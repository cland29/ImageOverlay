class myImage(object):
    def __init__(self, filename):
        self.img = loadImage(filename)
        self.width = self.img.width
        self.height = self.img.height
        self.filename = filename
    
    def getPixel(self, x, y):
        return self.img.pixels[y * self.width + x]
    
    def getPixelCol(self, x, y):
        red = red(self.img.pixels[y * self.width + x])
        green = green(self.img.pixels[y * self.width + x])
        blue = blue(self.img.pixels[y * self.width + x])
        return (red, green, blue)
    
    def setPixel(self, x, y, col):
        self.img.pixels[y * self.width + x] = col
        
    
    
    
    def saveImg(self, filename):
        self.img.save(filename)
