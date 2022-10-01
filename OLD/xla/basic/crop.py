import cv2
import numpy

# IMG_PATH = 'example.jpg'

# img = cv2.imread(IMG_PATH)

# img_crop = img[50:240, 240:700, :]
# crop_name = 'example_crop.jpg'

# cv2.imwrite(crop_name, img_crop)

def arrays(arr):
    # complete this function
    # use numpy.array
    arr.reverse()
    return numpy.array(arr, float)

arr = [int(i) for i in input().split()]
print(arrays(arr))