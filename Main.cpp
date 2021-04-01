#include <stdio.h>
#include <string>
#include "lodepng.h"
#include <iostream>
#include "Image.h"
#include <omp.h>

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
    for(int i = 0; i < 10; i++){
        //test.saveImage("testOutput" + to_string(i) +".png");
    }


    double a[256], b[256], sum;
    int n = 256;

    for (int i = 0; i < n; i++){
        a[i] = i * 0.5;
        b[i] = i * 2.0;
    }

    sum = 0.0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++){
        sum += a[i]*b[i];
        printf("%d: d\n", omp_get_thread_num(), i);
    }
    printf("sum = %f\n", sum);


    //.saveImage("testOutput.png");


    printf("Hello world!");


}
