import cv2
import numpy as np

INPUT_PATH = '../videos/girl.mp4'

def print_image(img, frame_diff):
    new_img = np.zeros((img.shape[0], 2*img.shape[1], img.shape[2]), np.uint8)

    new_img[:,:img.shape[1], :] = img
    new_img[:, img.shape[1]:, 0] = frame_diff
    new_img[:, img.shape[1]:, 1] = frame_diff
    new_img[:, img.shape[1]:, 2] = frame_diff

    return new_img

def main(video_path):
    cap = cv2.VideoCapture(video_path)
    last_gray = None
    idx = -1
    while True:
        ret, frame = cap.read()
        idx += 1
        if not ret:
            print(f'Stopped reading video {video_path}')
            break
        # if cv2.waitKey(20) & 0xFF == ord('q'):
        #     break
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        cv2.imshow('Original', frame)
        if last_gray is None:
            last_gray = gray
            continue
        diff = cv2.absdiff(gray, last_gray)
        cv2.imshow('Movement', print_image(frame, diff))
        cv2.waitKey(20)
        last_gray = gray
        # print(f'Done image {idx}')
    
    cv2.destroyAllWindows()
    cap.release()

if __name__ == "__main__":
    main(INPUT_PATH)
            