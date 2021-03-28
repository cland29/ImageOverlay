#include <stdio.h>
#include <string>
#include "lodepng.h"
#include <iostream>

using namespace std;

class Image{

    public:
        Image();
        Image(string fileName);
    private:
        std::vector<unsigned char> image;
        int width, height;
};