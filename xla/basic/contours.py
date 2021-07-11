import cv2
import numpy as np

img = cv2.imread('photos/snow_forest.png')
cv2.imshow('Original', img)

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray', gray)

# blur = cv2.GaussianBlur(gray, (5, 5), cv2.BORDER_DEFAULT)
# cv2.imshow('Blur', blur)

canny = cv2.Canny(gray, 175,255)
cv2.imshow('Canny', canny)

ret, thresh = cv2.threshold(gray, 125, 255, cv2.THRESH_BINARY)
cv2.imshow('Thresh', thresh)

blank = np.zeros(img.shape, dtype= 'uint8')

contours, hierarchies = cv2.findContours(thresh, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)

cv2.drawContours(blank, contours, -1, (0, 255, 0), thickness = 1)
cv2.imshow('Blank contours', blank)

print(f'{len(contours)} contour(s) found!')

cv2.waitKey(0)