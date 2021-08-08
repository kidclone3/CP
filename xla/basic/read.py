import cv2

# img = cv2.imread('photos/example.jpg')

# cv2.imshow('read img', img)

# cv2.waitKey(0)
# print(img.shape)

capture = cv2.VideoCapture('../videos/wtf.mp4')

while True:
    isTrue, frame = capture.read()
    cv2.imshow('frame', frame)

    if cv2.waitKey(20) & 0xFF == ord('d'):
        break

capture.release()
cv2.destroyAllWindows() 
