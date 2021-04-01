#This file currently serves as a place holder so naming of the Sketch Folder was Image Overlay.

#Hi future Carl! 4/1/2021

import Image
import Overlay

def setup():
    
    size(480, 120)
    
    
    bgTest = Image.myImage("bgTest.PNG")
    utilitiesObj = Overlay.utility()
    utilitiesObj.mult_overlay(["test"], ".PNG", bgTest, 4, "test/testOut")
    
    print("done")

def draw():
    
  updatePixels()
