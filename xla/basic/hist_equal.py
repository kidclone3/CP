import cv2

img = cv2.imread('photos/water_melon_rescale.jpg', flags= cv2.IMREAD_GRAYSCALE)
cv2.imshow('Original', img)

img_eq = cv2.equalizeHist(img)
cv2.imshow('Equalized', img_eq)

cv2.waitKey(0)