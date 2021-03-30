#include <stdio.h>
#include <string>
#include "lodepng.h"
#include <iostream>
#include "Image.h"

//glm
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/half_float.hpp"

using namespace std;

Image::Image(){
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

Image::Image(string fileName){
    //decode
    unsigned error = lodepng::decode(image, width, height, fileName.c_str());


    //if there's an error, display it
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}

void Image::saveImage(string fileName){
    unsigned error = lodepng::encode(fileName.c_str(), image, (unsigned) width, (unsigned) height);
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

void Image::setRGBPixel(unsigned x, unsigned y, glm::vec3 pixelCol){
    image[4 * width * y + 4 * x + 0] = pixelCol[0];
    image[4 * width * y + 4 * x + 1] = pixelCol[1];
    image[4 * width * y + 4 * x + 2] = pixelCol[2];
    image[4 * width * y + 4 * x + 3] = 255;
}

void Image::setRGBPixel(unsigned x, unsigned y, glm::vec4 pixelCol){
    image[4 * width * y + 4 * x + 0] = pixelCol[0];
    image[4 * width * y + 4 * x + 1] = pixelCol[1];
    image[4 * width * y + 4 * x + 2] = pixelCol[2];
    image[4 * width * y + 4 * x + 3] = pixelCol[3];
}
