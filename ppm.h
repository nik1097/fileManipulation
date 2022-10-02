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
    std::vector<ColorPixel> cp;

   public:
    Ppm();
    Ppm(int magicNum, int maxVal, int width, int height, std::vector<ColorPixel> cp);

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
    std::vector<ColorPixel> getPixels(){ 
        return cp; 
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
    void setPixels(std::vector<ColorPixel> cp){
         this->cp = cp; 
    }
};

#endif