from scipy.ndimage.measurements import label
from skimage.feature import peak_local_max
from skimage.segmentation import watershed
from scipy import ndimage
import cv2
import numpy as np
import imutils

img = cv2.imread('balls/ball_2.jpg')
cv2.imshow('Original', img)

blue_min = (98, 72, 0)
blue_max = (120, 255, 255)

# red_min = (0, 42, 0)
# red_max = (13, 255, 255)

red_min = (0, 211, 136)
red_max = (10, 255, 255)
# red_min = (0, 178, 0)
# red_max = (10, 255, 255)

# yellow_min = (15, 199, 0)
# yellow_max = (32, 255, 255)

# shifted = cv2.pyrMeanShiftFiltering(img, 21, 40)
# cv2.imshow('Shifted', shifted)


# img = cv2.bilateralFilter(img, 7, 25, 25)
img = cv2.GaussianBlur(img, (3,3),sigmaX= 5, sigmaY= 5)
cv2.imshow("Blur", img)

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
# cv2.imshow('Gray', gray)

hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
thresh = cv2.inRange(hsv, red_min, red_max)

thresh = cv2.erode(thresh, (5,5), iterations=10)
thresh = cv2.dilate(thresh, (5,5), iterations=5)

# thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU) [1]
cv2.imshow('Thresh', thresh)

D = ndimage.distance_transform_edt(thresh)
localMax = peak_local_max(D, indices=False, min_distance=20, labels=thresh)

markers = ndimage.label(localMax, structure=np.ones((3,3)))[0]
labels =  watershed(-D, markers, mask=thresh)
print("[INFO] {} unique segments found".format(len(np.unique(labels)) - 1))


for label in np.unique(labels):
    if label == 0:
        continue
    
    mask = np.zeros(gray.shape, dtype="uint8")
    mask [labels == label] = 255

    cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnts = imutils.grab_contours(cnts)
    c = max(cnts, key=cv2.contourArea)

    # Draw a circle enclosing the object
    ((x, y), r) = cv2.minEnclosingCircle(c)
    if (r < 15):
        continue
    cv2.circle(img, (int(x), int(y)), int(r), (0, 255, 0), 2)
    
cv2.imshow("Output", img)
cv2.waitKey(0)

