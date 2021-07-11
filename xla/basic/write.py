import cv2
# read
img = cv2.imread('photos/example.jpg')
cv2.imshow('Original', img)

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray', gray)

img_cvt = cv2.cvtColor(gray, cv2.COLOR_GRAY2BGR)
cv2.imshow('Image converted', img_cvt)

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray2', gray)

sobelX = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=cv2.FILTER_SCHARR)
sobelY = cv2.Sobel(img, cv2.CV_64F, 0, 1, cv2.FILTER_SCHARR)
sobelXY = cv2.Sobel(img, cv2.CV_64F, 1, 1, cv2.FILTER_SCHARR)

cv2.imshow('SobelX', sobelX)
cv2.imshow('SobelY', sobelY)
cv2.imshow('SobelXY', sobelXY)

cv2.waitKey(0)
