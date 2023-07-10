'''
    Developer: Michail Tamvakeras, BSc in Computer Science and MSc in Intelligent Information Systems
    Info: This file contains plotting functions to display images and graphs easier.
'''
import cv2
import numpy as np
import matplotlib.pyplot as plt


def plot(image1, image2=None, image1_title=None, image2_title=None, figsize=(8,4), display_axis=False):
    ''' Displays one or two images side-by-side without resizing them by default '''
    font = {'fontname':'Times New Roman'} # Set the font face for the text
    font_size=13
    
    if image2 is None: 
        fig, ax = plt.subplots(1, 1)

        if len(image1.shape) > 2: ax.imshow(image1[:,:,::-1]) # BGR-image
        elif len(image1.shape) < 3: ax.imshow(image1, cmap='gray') # Gray-image
        ax.set_title(image1_title, **font, fontsize=font_size) if image1_title else ax.set_title('Image 1', **font, fontsize=font_size)
        if not display_axis: ax.axis('off')

    # Displays two images side-by-side
    elif image2 is not None:
        fig, ax = plt.subplots(1, 2)
        
        if len(image1.shape) > 2: ax[0].imshow(image1[:,:,::-1]) # BGR-image
        elif len(image1.shape) < 3: ax[0].imshow(image1, cmap='gray') # Gray-image
        ax[0].set_title(image1_title, **font, fontsize=font_size) if image1_title else ax[0].set_title('Image 1', **font, fontsize=font_size)
        if not display_axis: ax[0].axis('off')

        if len(image2.shape) > 2: ax[1].imshow(image2[:,:,::-1])
        elif len(image2.shape) < 3: ax[1].imshow(image2, cmap='gray')
        ax[1].set_title(image2_title, **font, fontsize=font_size) if image2_title else ax[1].set_title('Image 2', **font, fontsize=font_size)
        if not display_axis: ax[1].axis('off')
    
    plt.show()