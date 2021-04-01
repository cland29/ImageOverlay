class myImage(object):
    def __init__(self, filename):
        self.img = loadImage(filename)
        self.width = self.img.width
        self.height = self.img.height
        self.filename = filename
    
    def getPixel(self, x, y):
        return self.img.pixels[y * self.width + x]
    
    def getPixelCol(self, x, y):
        redP = red(self.img.pixels[y * self.width + x])
        greenP = green(self.img.pixels[y * self.width + x])
        blueP = blue(self.img.pixels[y * self.width + x])
        return (redP, greenP, blueP)
    
    def setPixel(self, x, y, col):
        self.img.pixels[y * self.width + x] = col
        
    
    
    
    def saveImg(self, filename):
        self.img.save(filename)
