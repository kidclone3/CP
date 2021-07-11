import cv2
import numpy as np


img = cv2.imread('photos/cute.jpg')
cv2.imshow('Original', img)

print(img.shape[:2])
blank = np.zeros(img.shape[:2], dtype='uint8')

rec = cv2.rectangle(blank.copy(), (260, 130), (500, 395), 255, -1)
cv2.imshow('Rectangle', rec)

circle = cv2.circle(blank.copy(), (380,265), 130, 255, -1)
cv2.imshow('Circle', circle)

masking_rec = cv2.bitwise_and(img, img, mask=rec)
cv2.imshow('Masking Rectangle', masking_rec)

masking_cir = cv2.bitwise_and(img, img, mask= circle)
cv2.imshow('Masking Circle', masking_cir)

cv2.waitKey(0)