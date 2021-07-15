import cv2 
import numpy as np

red_min = (0, 205, 136)
red_max = (10, 255, 255)

img = cv2.imread('balls/ball_2.jpg')
img = cv2.pyrMeanShiftFiltering(img, 7,20)

cv2.imshow("Shifted", img)

hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
thresh = cv2.inRange(hsv, red_min, red_max)

cv2.imshow('Thresh', thresh)


kernel = np.ones((3,3), np.uint8)
opening = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernel, iterations=2)

sure_bg = cv2.dilate(opening, kernel, iterations=3)

cv2.imshow('Opening', opening)
cv2.imshow('BG', sure_bg)

dist_transform = cv2.distanceTransform(opening, cv2.DIST_L2, 5)
ret, sure_fg = cv2.threshold(dist_transform, 0.7*dist_transform.max(), 255, 0)

cv2.imshow('FG', sure_fg)

sure_fg = np.uint8(sure_fg)
unknown = cv2.subtract(sure_bg, sure_fg)

cv2.imshow('Unknown', unknown)

ret, markers = cv2.connectedComponents(sure_fg)

markers = markers + 1
markers[unknown==255] = 0

markers = cv2.watershed(img, markers)
img[markers == -1] = [0, 255, 0]

cv2.imshow('Contour', img)

cv2.waitKey(0)