from skimage.feature import peak_local_max
from skimage.morphology import watershed
from scipy import ndimage
import cv2
import numpy as np
import imutils


# Set up the detector with default parameter
def blob_detect(img,
                hsv_min,
                hsv_max,
                blur=0,
                bright = 20,  #change brightness
                blob_params=None,
                search_windows=[0.0, 0.0, 1.0, 1.0],
                imshow=False
                ):
    img = change_brightness(img, bright)
    if imshow: 
        cv2.imshow('Original', img)

    # Blur image if having noise
    if blur > 0:
        # img = cv2.GaussianBlur(img, (blur, blur), sigmaX=5, sigmaY=5)
        img = cv2.bilateralFilter(img, blur, 75, 75)
        # img = cv2.medianBlur(img, blur)
        if imshow:
            cv2.imshow("Blur", img)
    # Shifting image (Make it more like painting???)
    # shifted = cv2.pyrMeanShiftFiltering(img, 21, 20)
    # cv2.imshow("Shifted", shifted)

    # # Convert to gray and apply watershed algorithm.
    # gray = cv2.cvtColor(shifted, cv2.COLOR_BGR2GRAY)
    # thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU) [1]

    # cv2.imshow('Thresh', thresh)

    # convert BGR img to HSV img
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    # Apply HSV threshold
    mask = cv2.inRange(hsv, hsv_min, hsv_max)
    # if imshow: cv2.imshow("HSV mask", mask)

    # Cut the image using search windows
    mask = apply_search_window(mask)

    # if imshow:
    #     cv2.imshow("Searching Mask", mask)
    #     cv2.waitKey(0)

 #- build default blob detection parameters, if none have been provided
    if blob_params is None:
        params = cv2.SimpleBlobDetector_Params()

# Default min, max Threshold value
        params.minThreshold = 10
        params.maxThreshold = 200

        params.filterByArea = True
        params.minArea = 400
        params.maxArea = 10000

        params.filterByCircularity = True
        params.minCircularity = 0.35

        params.filterByConvexity = True
        params.minConvexity = 0.2

        params.filterByInertia = True
        params.minInertiaRatio = 0.2   

    else: 
        params = blob_params

    # Apply blob detection
    detector = cv2.SimpleBlobDetector_create(params)

    # Apply morphology
    # Opening
    mask = cv2.erode(mask, (5,5), iterations=5, borderType=cv2.BORDER_REFLECT)
    # cv2.imshow('Erode', mask)
    # mask = cv2.dilate(mask, (5,5), iterations=5, borderType=cv2.BORDER_REFLECT)
    # cv2.imshow('Dialate', mask)

    # Reverse mask
    reversemask = 255-mask
    # reversemask = cv2.dilate(reversemask, (3,3), iterations=5)

    if imshow:
        cv2.imshow('Reverse Mask', reversemask)

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
                   line_color = (0,255,0),    # default is black (b,g,r)
                   imshow = False
                ):
    #-- Draw detected blobs as red circles.
    #-- cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS ensures the size of the circle corresponds to the size of blob
    im_with_keypoints = cv2.drawKeypoints(img, keypoints, np.array([]), line_color, cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
 
    if imshow:
        # Show keypoints
        cv2.imshow("Keypoints", im_with_keypoints)
    print(f'This image has {len(keypoints)} contours')
    return(im_with_keypoints)

def change_brightness(img, value = 20):
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    h,s,v = cv2.split(hsv)

    v = cv2.add(v, value)
    v[v>255] = 255
    v[v<0] = 0

    final = cv2.merge((h,s,v))
    img_new = cv2.cvtColor(final, cv2.COLOR_HSV2BGR)
    return img_new

    return img_new
if __name__ == "__main__":
    # detect blue balls in image.
    # blue_min = (79, 0, 0)
    # blue_max = (128, 236, 255)
    # blue_min = (98, 72, 0)
    # blue_max = (120, 255, 255)

    # Yellow range:
    # yellow_min = (9, 209, 0)
    # yellow_max = (31, 255, 255)

    # Red range
    # red_min = (0, 42, 0)
    # red_max = (13, 255, 255)
    red_min = (0, 211, 136)
    red_max = (12, 255, 255)

    image_list = []
    image_list.append(cv2.imread('balls/ball_2.jpg'))

    for img in image_list:
        # canny = cv2.Canny(img, 50, 150, cv2.BORDER_DEFAULT)
        # cv2.imshow('Canny', canny)
        keypoints, _ = blob_detect(img, red_min, red_max, 5, 10, imshow=True)

        img = draw_keypoints(img, keypoints, imshow=True)
        cv2.waitKey(0)