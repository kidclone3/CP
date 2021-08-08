from skimage.feature import peak_local_max
from skimage.segmentation import watershed
from scipy import ndimage
import cv2
import numpy as np
import imutils
from threading import Thread
from imutils.video import VideoStream
import time


blue_min = (98, 72, 0)
blue_max = (120, 255, 255)

# red_min = (0, 42, 0)
# red_max = (13, 255, 255)

# red_min = (0, 211, 136)
# red_max = (10, 255, 255)
red_min = (0, 202, 0)
red_max = (14, 255, 255)
# red_min = (0, 178, 0)
# red_max = (10, 255, 255)

# yellow_min = (15, 199, 0)
# yellow_max = (32, 255, 255)

green_min = (32, 109, 0)
green_max = (72, 255, 255)

def blob_detect(img, minArea = 800, minHSV = None, maxHSV= None, imshow = False, webcam = False):
    # img = cv2.bilateralFilter(img, 7, 25, 25)
    # img = cv2.GaussianBlur(img, (3,3),sigmaX= 7, sigmaY= 7)

    # img = cv2.pyrMeanShiftFiltering(img, 15, 15)
    # cv2.imshow('Shifted', shifted)

    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    thresh = cv2.inRange(hsv, minHSV, maxHSV)
    # Apply filled object algorithm.
    im_flood = thresh.copy()
    h, w = img.shape[:2]
    mask = np.zeros((h+2, w+2), np.uint8)
    cv2.floodFill(im_flood, mask, (0,0), 255)
    im_flood_inv = cv2.bitwise_not(im_flood)

    # Combine => Got a filled object.
    thresh = cv2.bitwise_or(thresh, im_flood_inv)
    cv2.imwrite("mask.jpg", thresh)
    # cv2.imshow("Flooded", im_out)
    # Apply morphology for preprocessing.
    # kernel = np.ones((5), np.uint8)
    # thresh = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernel, iterations = 3)

    if imshow: cv2.imshow('Thresh', thresh)
    # Apply watershed algorithm (core).
    # Distance_transform take at most time ( > 0.03s)
    # D = distance_transform_edt(thresh)
    D = cv2.distanceTransform(thresh, cv2.DIST_L2, 0)
    
    localMax = peak_local_max(D, indices=False, min_distance=20, labels=thresh)
    markers, nums = ndimage.label(localMax) #, structure=np.ones((3,3)))
    # labels = cv2.watershed(img, markers)
    labels =  watershed(-D, markers, mask=thresh)
    # print(nums)
    # print(len(np.unique(labels)))
    # start = time.time()
    for label in np.unique(labels):
        if label == 0:
            continue
        # print(label)
        mask = np.zeros(img.shape[:2], dtype="uint8")
        mask [labels == label] = 255
        pixel_thresh = np.count_nonzero(labels == label)

        if (pixel_thresh < minArea):
            nums -= 1
            continue
        cnts = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        cnts = imutils.grab_contours(cnts)
        c = max(cnts, key=cv2.contourArea)

        # Draw a circle enclosing the object
        ((x, y), r) = cv2.minEnclosingCircle(c)
        cv2.circle(img, (int(x), int(y)), int(r), (0, 255, 0), 2)
    # print(f'{nums} objects found')
    # print(time.time() - start)
    if imshow or webcam: 
        cv2.imshow("Output", img)
        # cv2.waitKey(0)

# img = cv2.imread('balls/ball_2.jpg')
# cv2.imshow('Original', img)

# blob_detect(img, 800, green_min, green_max, imshow=False)

def detect_using_webcam():
    vs = VideoStream(src = 0).start()
    # vs = cv2.VideoCapture(0)
    # vs = WebcamVideoStream(src=0).start()

    while 1:
        start = time.time()
        img = vs.read()
        # img = cv2.imread('balls/ball_2.jpg')
        # cv2.imshow('Original', img)
        blob_detect(img, 800, green_min, green_max, webcam=True)
        stop = time.time()
        print(stop - start)

        key = cv2.waitKey(1) & 0xFF
        if key == ord('q'):
            break
    # vs.stop()
    cv2.destroyAllWindows()
    # vs.stop()
detect_using_webcam()

