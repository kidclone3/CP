import cv2
import numpy as np

IMG_PATH = 'example.jpg'
img = cv2.imread(IMG_PATH)
print(img.shape)



img_pad = np.zeros([1920, 1080, 3])
img_pad += 100
img_pad[300:1650,:,:] = img
cv2.imwrite('example_padding.jpg', img_pad)
print(img_pad.shape)