#### Original Codes ################################################################################################

# import argparse, cv2, os

# ap = argparse.ArgumentParser()
# ap.add_argument("-i", "--image", required=True, help="Path to the image")
# ap.add_argument("-ni", "--new-image", required=False, help="Path to the image to be saved")
# args = vars(ap.parse_args())

# image = cv2.imread(args["image"])
# print("width: {} pixels".format(image.shape[1]))
# print("height: {} pixels".format(image.shape[0]))
# print("channels: {}".format(image.shape[2]))

# cv2.imshow("Image", image)
# cv2.waitKey(0)

# if args["new_image"]:
# 	try:
# 		cv2.imwrite(args["new_image"], image)
# 	except IOError as e:
# 		print("couldn't save new image {}: {}".format(args["new_image"], e.strerror))
# 	except:
# 		print("couldn't save new image")

#### My Codes #########################################################################################################

import argparse
import cv2	#implicitly use numpy representations

ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True, help="Path to the image")	#only argument required is "--image"

#when executing, it could be either 
#$python filename -i IMAGEPATH 
# or 
#$python filename --image IMAGEPATH

args = vars(ap.parse_args())	#parse the arguments and store tham in a dictionary

image = cv2.imread(args["image"])	#imread() returns a NumPy array representing the image

print "width: %d pixels" % (image.shape[1])	#shape attribute, since the image is represented NumPy arrays
print "height: %d pixels" % (image.shape[0])
print "channels: %d" % (image.shape[2])

#image.shape is the np.array (350, 228, 3) #columns, rows 
# width 350p
# height 228p
# channels 3	#RGB components of the image

cv2.imshow("Image", image)	
cv2.waitKey(0)	#pauses the execution until there is a key input, parameter 0 means that any key will-unpause the execution 
#the camel waitKey(), not waitkey()

cv2.imwrite("newimage.jpg", image)