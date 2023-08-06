import cv2
import numpy as NUMpy

image = cv2.imread("img/GOAT.jpg")
# just to justify if the image is in the right format
print(image.shape)

# just to justify
cv2.imshow('img',image)
cv2.waitKey(0)


def detect_red_and_white_regions(image):
    hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    # determining lower limit and upper limit of BGR value
    lower_val_red = NUMpy.array([0, 20, 0], dtype="uint8")  # Adjust the lower_val_red values to detect red
    upper_val_red = NUMpy.array([0, 255, 255], dtype="uint8")  # Adjust the upper_val_red values to detect red
    # using cv2.inRange to detect the red color
    red_mask = cv2.inRange(hsv_image, lower_val_red, upper_val_red)

    # determining lower limit and upper limit of BGR vals of white
    lower_val_white = NUMpy.array([0, 0, 200], dtype="uint8")
    upper_val_white = NUMpy.array([180, 30, 255], dtype="uint8")
    # using cv2.inRange to detect the white color
    white_mask = cv2.inRange(hsv_image, lower_val_white, upper_val_white)

    # Combine the masks for red and white regions using bitwise or
    final_mask = cv2.bitwise_or(red_mask, white_mask)

    # we are using bitwise and to highlight the red and white regions in the NUMpy image
    red_and_white_regions = cv2.bitwise_and(image, image, mask=final_mask)

    # Displaying the red and white regions image
    cv2.imshow('Red and White Regions', red_and_white_regions)
    cv2.waitKey(0)


# Call the function after displaying the original image
detect_red_and_white_regions(image)


def analyze_goat(img):
    # Calculate the minimum and maximum pixel values in the image
    smallest = NUMpy.min(img)
    largest = NUMpy.max(img)

    # Calculate the average pixel value in the image
    average = NUMpy.mean(img)
    
    # Calculate the total number of non-zero (foreground) and zero (background) pixels in the image
    num_foreground_pixels = NUMpy.count_nonzero(img)
    num_background_pixels = img.size - num_foreground_pixels

    # so the the information got displayed
    font = cv2.FONT_HERSHEY_SIMPLEX
    #print(num_foreground_pixels)
    cv2.putText(img,"dsf",(10, 30),font, 1, (200,200,200), cv2.LINE_AA)


    # Display the processed image with information
    cv2.imshow('Analyzed Goat', img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

