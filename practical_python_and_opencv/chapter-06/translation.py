# import argparse, cv2, numpy as np, imutils

# ap = argparse.ArgumentParser()
# ap.add_argument("-i", "--image", required = True, help = "Path to the image")
# args = vars(ap.parse_args())

# image = cv2.imread(args["image"])
# cv2.imshow("Original", image)

# # translation
# # translation via matrices
# M = np.float32([[1, 0, 25], [0, 1, 50]])
# shifted = cv2.warpAffine(image, M, (image.shape[1], image.shape[0]))
# cv2.imshow("Shifted Down and Right", shifted)

# M = np.float32([[1, 0, -50], [0, 1, -90]])
# shifted = cv2.warpAffine(image, M, (image.shape[1], image.shape[0]))
# cv2.imshow("Shifted Up and Left", shifted)

# # translation via helper function
# shifted = imutils.translate(image, 10, -100)
# cv2.imshow("Shifted with utility function", shifted)

# cv2.waitKey(0)



import argparse
import cv2
import numpy as np
import imutils

ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True, help = "Path to the image")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])
cv2.imshow("Original", image)

# translation
# translation via matrices
M = np.float32([[1, 0, 25], [0, 1, 50]])
#for the third argument, the size of image, we have to supply them manually
shifted = cv2.warpAffine(image, M, (image.shape[1], image.shape[0])) 
cv2.imshow("Shifted Down and Right", shifted)
cv2.waitKey(0)

M = np.float32([[1, 0, -50], [0, 1, -90]])
shifted = cv2.warpAffine(image, M, (image.shape[1], image.shape[0]))
cv2.imshow("Shifted Up and Left", shifted)

# translation via helper function
shifted = imutils.translate(image, 10, -100)
cv2.imshow("Shifted with utility function", shifted)

cv2.waitKey(0)

## imutils.py ##
# def translate(image, x, y):
# 	M = np.float32([[1,0,x],[0,1,y]])
# 	shifted = cv2.warpAffine(image, M, image.shape[1], image.shape[0])
# 	return shifted

# 	