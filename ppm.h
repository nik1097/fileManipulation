#ifndef PPM_H
#define PPM_H

#include <string>
#include <vector>
#include "colorPixel.h"

class Ppm{
   private:
    int magicNum;
    int maxVal;
    int width; 
    int height;

   public:
    vector<vector<ColorPixel*>>cp_array;
    Ppm();
    Ppm(int magicNum, int maxVal, int width, int height);

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
    vector<vector<ColorPixel*>> getPixels(){ 
        return cp_array; 
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
    void setPixels(vector<vector<ColorPixel*>>cp_array){
         this->cp_array = cp_array; 
    }
};

#endif