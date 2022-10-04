// Nikhil Suresh & Devin Lilaramani

#ifndef COLORPIXEL_H
#define COLORPIXEL_H

#include<string>
using namespace std;

class ColorPixel{
   private:
    string red;
    string green;
    string blue;

   public:
    ColorPixel(){}

    ColorPixel(string red, string green, string blue){
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    // Getters
    string getRed(){ 
        return red; 
    }
    string getGreen(){ 
        return green; 
    }
    string getBlue(){ 
        return blue; 
    }

    // Setters
    void setRed(string red){ 
        this->red = red; 
    }
    void setGreen(string green){ 
        this->green = green; 
    }
    void setBlue(string blue){ 
        this->blue = blue; 
    }
};

#endif