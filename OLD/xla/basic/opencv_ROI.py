import os, sys
import cv2


def apply_roi(img, roi):
    roi = cv2.resize(src = roi, dsize = (img.shape[1], img.shape[0]))

    assert img.shape[:2] == roi.shape[:2]
    # scale ROI to [0, 1] => binary mask
    thresh, roi = cv2.threshold(roi, thresh=128, maxval=1, type=cv2.THRESH_BINARY)
    
    # apply ROI on the original image
    new_img = img * roi
    return new_img



if __name__ == "__main__":
    assert len(sys.argv) == 3, '[USAGE] $ python opencv_ROI.py input_image roi_image'
    input_img_path, roi_img_path = sys.argv[1], sys.argv[2]

    assert os.path.isfile(input_img_path), 'Image not found @ %s' % input_img_path
    assert os.path.isfile(roi_img_path), 'ROI not found @ %s' % roi_img_path

    img = cv2.imread(input_img_path)
    roi = cv2.imread(roi_img_path)
    new_img = apply_roi(img, roi)
    cv2.imwrite('new_%s' % os.path.basename(input_img_path), new_img)
