import cv2
import numpy as np

# PATH = '/home/delus/Documents/mycodes/xla/photos/pink_x0.4.jpg'
PATH = 'balls/ball_2.jpg'
img = cv2.imread(PATH)
cv2.imshow("Original Picture", img)

img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)


# Red color 
low_red = np.array([0, 100, 84])
high_red = np.array([13, 255, 255])
red_mask = cv2.inRange(img_hsv,low_red, high_red)
red = cv2.bitwise_and(img, img, mask=red_mask)

# Blue color
low_blue = np.array([94, 80, 2])
high_blue = np.array([126, 255, 255])
blue_mask = cv2.inRange(img_hsv, low_blue, high_blue)
blue = cv2.bitwise_and(img, img, mask = blue_mask)


# Green color
low_green = np.array([35, 0, 72])
high_green = np.array([80, 255, 255])
green_mask = cv2.inRange(img_hsv, low_green, high_green)
green = cv2.bitwise_and(img, img, mask = green_mask)


# Show to screen
cv2.imshow("Red", red)
cv2.imshow("Blue", blue)
cv2.imshow("Green", green)

# Contour detect
canny = cv2.Canny(img, 175, 255)
cv2.imshow("Canny", canny)

cv2.waitKey(0)