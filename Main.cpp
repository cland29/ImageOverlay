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

int main(int argc, char **argv)
{
    string fileName;
    if (argc > 1){
        string arg1(argv[0]);
        fileName = arg1;
    }else{
        fileName = "testInput.png";
    }
    Image test = Image(fileName);


    printf("Hello world!");


}
