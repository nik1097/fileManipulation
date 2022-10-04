// Nikhil Suresh & Devin Lilaramani 

#ifndef PGM_H
#define PGM_H

#include <string>
#include <vector>
#include "grayPixel.h"

using namespace std;

class Pgm{
   private:
    int magicNum;
    int maxVal;
    int width; 
    int height;

   public:
    vector<vector<GrayPixel*>>gp_array;
    Pgm();
    Pgm(int magicNum, int maxVal, int width, int height);

    int getMagicNum(){ 
        return magicNum; 
    };
    int getMaxVal(){ 
        return maxVal; 
    }
    int getWidth(){ 
        return width; 
    }
    int getHeight(){ 
        return height; 
    }
    vector<vector<GrayPixel*>> getPixels(){ 
        return gp_array; 
    }

    void setMagicNum(int magicNum){ 
        this->magicNum = magicNum; 
    }
    void setMaxVal(int maxVal){ 
        this->maxVal = maxVal; 
    }
    void setWidth(int width){ 
        this->width = width; 
    }
    void setHeight(int height){ 
        this->height = height; 
    }
    void setPixels(vector<vector<GrayPixel*>>gp_array){
         this->gp_array = gp_array; 
    }
};

#endif