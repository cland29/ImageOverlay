#This file currently serves as a place holder so naming of the Sketch Folder was Image Overlay.

#Hi future Carl! 4/1/2021

import Image

def setup():
    
    size(480, 120)
    test = Image.myImage("test.PNG")
    for i in range(test.width):
        test.setPixel(i, 10, color(0, 0, 255))
    test.saveImg("test1.PNG")
    
    print("done")

def draw():
    
  updatePixels()
