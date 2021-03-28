#include <stdio.h>
#include <string>
#include "lodepng.h"
#include <iostream>

using namespace std;



class Image{
    public:
        Image(){
            width = 512, height = 512;
            image.resize(width * height * 4);
            for(unsigned y = 0; y < height; y++){
                for(unsigned x = 0; x < width; x++) {
                    image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
                    image[4 * width * y + 4 * x + 1] = x ^ y;
                    image[4 * width * y + 4 * x + 2] = x | y;
                    image[4 * width * y + 4 * x + 3] = 255;
                }
            }
        }

        Image(string fileName){
            //decode
            unsigned error = lodepng::decode(image, width, height, fileName.c_str());
            

            //if there's an error, display it
            if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

            //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
        }

        void saveImage(string fileName){
            unsigned error = lodepng::encode(fileName.c_str(), image, (unsigned) width, (unsigned) height);
            if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
        }

        

    private:
        std::vector<unsigned char> image;
        unsigned width, height;

};