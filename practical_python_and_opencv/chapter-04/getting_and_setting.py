#### Original Codes ########

# import argparse, cv2

# ap = argparse.ArgumentParser()
# ap.add_argument("-i", "--image", required = True, help = "Path to the image")
# args = vars(ap.parse_args())

# image = cv2.imread(args["image"])

# #getting and setting pixel color
# (b, g, r) = image[219,90]
# print("Pixel at (0, 0) - Red: {}, Green: {}, Blue: {}".format(r, g, b))

# image [0, 0] = (0, 0, 255)
# (b, g, r) = image[0,0]
# print("Pixel at (0, 0) - Red: {}, Green: {}, Blue: {}".format(r, g, b))

# cv2.imshow("Image", image)
# cv2.waitKey(0)

# #cropping a slice of the image
# corner = image[0:100, 0:100]
# cv2.imshow("Corner", corner)
# cv2.waitKey(0)

# #setting the pixel color of a slice
# image[0:200, 0:50] = (0, 255, 0)
# cv2.imshow("Updated", image)
# cv2.waitKey(0)


#### My Codes ########
import argparse, cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True, help = "Path to the image")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])

#channels stored in OpenCV is in reverse order;
(b, g, r) = image[0,0]  #each pixel data is stored as a tuple representing the value in RGB channels 
print "Pixel at (0, 0) - Red: %d, Green; %d, Blue %d" % (r, g, b)	#unpack and access each element in the tuple

image[0,0] = (0, 0, 255)
(b, g, r) = image[0,0]
print "Pixel at (0, 0) - Red: %d, Green; %d, Blue %d" % (r, g, b)

corner = image[0:100, 0:100]
cv2.imshow("Corner", corner)
cv2.waitKey(0)

image[0:100, 0:100] = (0, 255, 0)
cv2.imshow("Updated", image)
cv2.waitKey(0)