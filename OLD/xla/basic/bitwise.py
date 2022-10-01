import cv2
import numpy as np
from numpy.lib.type_check import real

blank = np.zeros((400, 400), dtype= 'uint8')

rectangle = cv2.rectangle(blank.copy(), (30, 30), (370, 370), 255, -1)
circle = cv2.circle(blank.copy(), (200, 200), 200, 255, -1)

cv2.imshow('Rectangle', rectangle)
cv2.imshow('Circle', circle)

bw_and = cv2.bitwise_and(rectangle, circle)
cv2.imshow('Bitwise AND', bw_and)

bw_or = cv2.bitwise_or(rectangle, circle)
cv2.imshow('Bitwise OR', bw_or)

bw_xor = cv2.bitwise_xor(rectangle, circle)
cv2.imshow('Bitwise XOR', bw_xor)

cv2.waitKey(0)