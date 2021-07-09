import cv2

def convert2binary(src, thresh = 100):
    # thresh, img = cv2.threshold(src, thresh, 255, cv2.THRESH_BINARY)
    img_bin = cv2.adaptiveThreshold(src = src, maxValue= 255,
                                    adaptiveMethod = cv2.ADAPTIVE_THRESH_MEAN_C, 
                                    thresholdType = cv2.THRESH_BINARY,
                                    blockSize= 5,
                                    C = 5)
    return img_bin

img_grayscale = cv2.imread('photos/water_melon_rescale.jpg', cv2.IMREAD_GRAYSCALE)
cv2.imshow('Original', img_grayscale)

img_binary = convert2binary(img_grayscale, 80)
cv2.imshow('Binary', img_binary)

cv2.waitKey(0)