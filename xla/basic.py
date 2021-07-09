import cv2 

def rescale_frame(frame, scale = 0.75):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)

    return cv2.resize(frame, (width, height), interpolation= cv2.INTER_AREA)

# Source
img = rescale_frame(cv2.imread('photos/pink.jpg'), 0.4)
cv2.imshow('Pink', img)
cv2.imwrite('photos/pink_x0.4.jpg', img)
# Make gray image
# gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
# cv2.imshow('gray', gray)

# # Add blur
# blur = cv2.GaussianBlur(img, (7, 7), cv2.BORDER_DEFAULT)
# cv2.imshow('blur', blur)

# # IDK what this is
# canny = cv2.Canny(blur, 125, 175)
# cv2.imshow('canny', canny)

cv2.waitKey(0)