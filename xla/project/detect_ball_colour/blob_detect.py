import cv2
import numpy as np

img = cv2.imread('balls/ball_2.jpg', cv2.IMREAD_GRAYSCALE)
cv2.imshow('Original', img)
# Set up the detector with default parameter
def blob_detect(img,
                hsv_min,
                hsv_max,
                blur=0,
                blob_params=None,
                search_windows=None,
                imshow=False
                ):

    # Blur image if having noise
    if blur > 0:
        img = cv2.blur(img, (blur, blur))
        if imshow:
            cv2.imshow("Blur", img)
    if search_windows is None: search_windows = [0.0, 0.0, 1.0, 1.0]

    # convert BGR img to HSV img
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    # Apply HSV threshold
    mask = cv2.inRange(hsv, hsv_min, hsv_max)
    if imshow: cv2.imshow("HSV mask", mask)

    # Cut the image using search windows
    mask = apply_search_window(mask)

    if imshow:
        cv2.imshow("Searching Mask", mask)
        cv2.waitKey(0)

 #- build default blob detection parameters, if none have been provided
    if blob_params is None:
        params = cv2.SimpleBlobDetector_Params()

        params.minThreshold = 10
        params.maxThreshold = 10

        params.filterByArea = True
        params.minArea = 1500

        params.filterByCircularity = True
        params.minCircularity = 0.1

        params.filterByConvexity = True
        params.minConvexity = 0.87

        params.filterByInertia = True
        params.minInertiaRatio = 0.01   

    else: 
        params = blob_params

    # Apply blob detection
    detector = cv2.SimpleBlobDetector_create(params)

    # Reverse mask
    reversemask = 255-mask

    if imshow:
        cv2.imshow('Reverse Mask', reversemask)
        cv2.waitKey(0)

    # Detect blobs
    keypoints = detector.detect(reversemask, None)
    return keypoints, reversemask

#---------- Apply search window: returns the image
#-- return(image)
def apply_search_window(image, window_adim=[0.0, 0.0, 1.0, 1.0]):
    rows = image.shape[0]
    cols = image.shape[1]
    x_min_px    = int(cols*window_adim[0])
    y_min_px    = int(rows*window_adim[1])
    x_max_px    = int(cols*window_adim[2])
    y_max_px    = int(rows*window_adim[3])    
    
    #--- Initialize the mask as a black image
    mask = np.zeros(image.shape,np.uint8)
    
    #--- Copy the pixels from the original image corresponding to the window
    mask[y_min_px:y_max_px,x_min_px:x_max_px] = image[y_min_px:y_max_px,x_min_px:x_max_px]   
    
    #--- return the mask
    return(mask)
    
def draw_keypoints(img,
                   keypoints,
                   line_color = (0,0,255),    # default is red (b,g,r)
                   imshow = False
                ):
    #-- Draw detected blobs as red circles.
    #-- cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS ensures the size of the circle corresponds to the size of blob
    im_with_keypoints = cv2.drawKeypoints(img, keypoints, np.array([]), line_color, cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
 
    if imshow:
        # Show keypoints
        cv2.imshow("Keypoints", im_with_keypoints)
        
    return(im_with_keypoints)

if __name__ == "__main__":
    # detect blue balls in image.
    blue_min = (79, 0, 0)
    blue_max = (128, 236, 255)

    image_list = []
    image_list.append(cv2.imread('balls/ball_2.jpg'))

    for img in image_list:
        keypoints, _ = blob_detect(img, blue_min, blue_max, imshow=True)

        img = draw_keypoints(img, keypoints, imshow=True)
        cv2.waitKey(0)