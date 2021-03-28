#include <stdio.h>
#include <string>
#include "lodepng.h"
#include <iostream>

//glm
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/half_float.hpp>

using namespace std;

class Image{

    public:
        Image();
        Image(string fileName);
        void saveImage(string fileName);
    private:
        std::vector<unsigned char> image;
        int width, height;
};