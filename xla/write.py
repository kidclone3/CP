import cv2
# read
img = cv2.imread('example.jpg')

new_width = 800
new_height = 400
img_resize = cv2.resize(src = img, dsize = (new_width, new_height))
resize_img_name = 'girl_xinh_%dx%d.jpg' % (new_width, new_height)
# print(resize_img_name)
# cv2.imshow(resize_img_name, img_resize)
cv2.imwrite(resize_img_name, img_resize)
