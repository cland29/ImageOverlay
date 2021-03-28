#include <stdio.h>
#include <string>
#include "lodepng.h"
#include <iostream>

using namespace std;



class Image{
    public:
        Image(){

        }
        Image(string fileName){
            
            unsigned width, height;

            //decode
            unsigned error = lodepng::decode(image, width, height, fileName.c_str());
            this->width = (int) width;
            this->height = (int) height;

            //if there's an error, display it
            if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

            //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
        }
    private:
        std::vector<unsigned char> image;
        int width, height;

};