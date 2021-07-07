import cv2

def rescale_frame(frame, scale = 0.75):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)

    return cv2.resize(frame, (width, height), interpolation= cv2.INTER_AREA)

img = cv2.imread('photos/example.jpg')

img_rescale = rescale_frame(img)

cv2.imshow('Photo', img)
cv2.imshow('Photo rescale', img_rescale)

# cv2.waitKey(0)

video = cv2.VideoCapture('videos/accident.mp4')

while True:
    isTrue, frame = video.read()
    frame_resize = rescale_frame(frame)

    cv2.imshow('frame', frame)
    cv2.imshow('frame rescale', frame_resize)

    if cv2.waitKey(20) & 0xFF == ord('d'):
        break
video.release()
cv2.destroyAllWindows()