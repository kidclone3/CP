import cv2
from threading import Thread

class WebcamVideoStream:
    def __init__(self, src = 0):
        # initialize the video camera stream and read the first frame
		# from the stream
        self.stream = cv2.VideoCapture(src)
        (self.grabbed, self.frame) = self.stream.read()
        # initialize the variable used to indicate if the thread should
		# be stopped
        self.stopped = False

    def start(self):
        # Start the thread to read frames from video stream
        Thread(target=self.update, args=()).start()
        return self
    
    def update(self):
        # keep looping until the thread is stopped.
        while 1:
            # if the thread indicator variable is set, stop the thread
            if self.stopped:
                return
            
            # Otherwise, read the next frame from the stream
            (self.grabbed, self.frame) = self.stream.read()

    def read(self):
        # Return the frame most recently read
        return self.frame
            
    def stop(self):
        # Indicate that the thread should be stopped
        self.stopped = True