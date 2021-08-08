import cv2
import numpy as np
from numpy.lib.function_base import diff

BACKGROUND_IMG = '../photos/background.jpg'
FOREGROUND_IMG = '../photos/foreground.jpg'

# First, we need blur each image. We use Gassian blur to reduce noise.

def blur_color_img(img, kernel_width = 5, kernel_height = 5, sigmaX = 2, sigmaY = 2):
    img = np.copy(img) # Do not modify the original image.
    img[:,:,0] = cv2.GaussianBlur(img[:, :, 0], (kernel_width, kernel_height), sigmaX= sigmaX, sigmaY = sigmaY)
    img[:,:,1] = cv2.GaussianBlur(img[:, :, 1], (kernel_width, kernel_height), sigmaX= sigmaX, sigmaY = sigmaY)
    img[:,:,2] = cv2.GaussianBlur(img[:, :, 2], (kernel_width, kernel_height), sigmaX= sigmaX, sigmaY = sigmaY)

    return img

def background_subtraction(fg_img, bg_img, diff_threshold = 30):
    fg_img = blur_color_img(fg_img, 7, 7, 4, 4)
    bg_img = blur_color_img(bg_img, 7, 7, 2, 2)

    mask = fg_img - bg_img
    mask = np.abs(mask)
    # Combine 3 dimensions into binary.
    mask = np.mean(mask, axis = 2, keepdims=False)

    mask[mask<diff_threshold] = 0
    mask[mask>diff_threshold] = 255
    mask = mask.astype(np.uint8)

    # mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, (5, 5), iterations=5)
    mask = cv2.medianBlur(mask, 7)
    return mask

def main(foreground_img, background_img):
    fg_img = cv2.imread(foreground_img)
    bg_img = cv2.imread(background_img)

    mask = background_subtraction(fg_img, bg_img, 25)
    print(mask.shape[:])
    new_img = np.zeros((fg_img.shape[0], fg_img.shape[1], 4), np.uint8) # create a PNG image with 4 dimension

    new_img[:, :, :3] = fg_img
    new_img[:, :, 3] = mask
    cv2.imwrite("mask.jpg", mask)
    cv2.imwrite("New_image.png", new_img)
    cv2.waitKey(0)

if __name__ == "__main__":
    main(FOREGROUND_IMG, BACKGROUND_IMG)

