import cv2
import numpy as np

img = cv2.imread('photos/pink_x0.4.jpg')
cv2.imshow('Original', img)

blank = np.zeros(img.shape[:2], dtype='uint8')

b, g, r = cv2.split(img)

blue = cv2.merge([b, blank, blank])
green = cv2.merge([blank, g, blank])
red = cv2.merge([blank, blank, r])

cv2.imshow('Blue', blue)
cv2.imshow('Green', green)
cv2.imshow('Red', red)

cv2.waitKey(0)