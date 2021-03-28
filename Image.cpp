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