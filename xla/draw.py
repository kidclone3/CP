import cv2 
import numpy as np

blank = np.zeros((500, 500, 3), dtype= 'uint8')

# blank[:] = 0, 255, 0
# blank[100:300,100:300,:] = 255, 255, 255

cv2.rectangle(blank, (0, 0), (300, 200), (0, 0, 255), 3)

cv2.imshow('blank', blank)

cv2.waitKey(0)