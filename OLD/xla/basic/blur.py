import cv2

def rescale_frame(frame, scale = 0.75):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)

    return cv2.resize(frame, (width, height), interpolation= cv2.INTER_AREA)

img = cv2.imread('photos/dong.jpg')
img = rescale_frame(img, 0.3)
cv2.imshow('Original',img)

dim = (3,3)

average = cv2.blur(img, dim)
cv2.imshow('Averaging blur', average)

gauss = cv2.GaussianBlur(img, dim, 0)
cv2.imshow('Gaussian Blur', gauss)

median = cv2.medianBlur(img, 3)
cv2.imshow('Median blur', median)

cv2.waitKey(0)