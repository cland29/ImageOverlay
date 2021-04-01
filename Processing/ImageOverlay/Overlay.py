import Image

class utility(object):
    def __init__(self):
        self.i = 0

    def overlay(self, img_list, bg_img):
        overlay_img = Image.myImage(bg_img.filename)
        
        for y in range(bg_img.height):
            for x in range(bg_img.width):
                good_pixel_count = 0
                bg_pixel_RGB = bg_img.getPixelCol(x, y)
                
                new_pixel = [0, 0, 0]
                for img in img_list:
                    pixel_RGB = img.getPixelCol(x, y)
    
                    #Algorithm for detemining if a pixel is a background or dancer pixel
                    threshold = 80
                    diff = ((bg_pixel_RGB[0] - pixel_RGB[0])**2 + (bg_pixel_RGB[1] - pixel_RGB[1])**2 + (bg_pixel_RGB[2] - pixel_RGB[2])**2)**0.5
                    
                    
                    
                    #Saves the pixel as good
                    if (diff > threshold):
                        
                        good_pixel_count += 1
                        new_pixel[0] += pixel_RGB[0]
                        new_pixel[1] += pixel_RGB[1]
                        new_pixel[2] += pixel_RGB[2]
                        
                if (good_pixel_count > 0):
                    overlay_img.setPixel(x, y, color(int(new_pixel[0] / good_pixel_count), int(new_pixel[1] / good_pixel_count), int(new_pixel[2] / good_pixel_count))) 
                    
        return overlay_img
                    
        

        
