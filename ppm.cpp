#include "ppm.h"

Ppm::Ppm(){
    magicNum = 0;
    maxVal = 0;
    width = 0;
    height = 0;
}

Ppm::Ppm(int magicNum, int maxVal, int width, int height){
    this->magicNum = magicNum;
    this->maxVal = maxVal;
    this->width = width;
    this->height = height;
}