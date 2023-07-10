import os
import sys
import cv2

# IMPORTANT: Sets the working directory by code to access the custom libraries in the following
curr_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)))
os.chdir(curr_dir); os.chdir('..')
workdir = os.getcwd()
sys.path.append(workdir)
print(workdir)

from help.plotting import plot

img_orig = cv2.imread(os.path.join(workdir, 'test_py', 'street1.jpg'))
img_gray = cv2.cvtColor(img_orig, cv2.COLOR_BGR2GRAY)

plot(img_orig, img_gray, image1_title='Original Image', image2_title='Grayscale Image')
