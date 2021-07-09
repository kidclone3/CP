import cv2 
import numpy as np

img = cv2.imread('photos/cute.jpg')
cv2.imshow('Original', img)

def translate(img, x, y):
    transMat = np.float32([[1, 0, x], [0,1,y]])
    dimension = (img.shape[0], img.shape[1])
    return cv2.warpAffine(img, transMat, dimension)

translated = translate(img, 100, 100)
cv2.imshow('Translated', translated)

def rotate(img, angle, rotPoint = None):
    (height, width) = img.shape[:2]

    if rotPoint == None:
        rotPoint = (width//2, height//2)
        # Diem chinh giua anh.
    
    rotMat = cv2.getRotationMatrix2D(rotPoint, angle, 1.0)
    return cv2.warpAffine(img, rotMat, (width, height))

rotated = rotate(img, 30)
cv2.imshow('Rotated', rotated)

# flipcode: 
# 1 = horizontically
# 0 = vertically
# -1 = both 0 and 1
flip = cv2.flip(img, 1)
cv2.imshow('Flipped', flip)


cv2.waitKey(0)