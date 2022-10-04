// Nikhil Suresh & Devin Lilaramani 


#include "pgm.h"

Pgm::Pgm(){
    magicNum = 0;
    maxVal = 0;
    width = 0;
    height = 0;
}

Pgm::Pgm(int magicNum, int maxVal, int width, int height){
    this->magicNum = magicNum;
    this->maxVal = maxVal;
    this->width = width;
    this->height = height;
}