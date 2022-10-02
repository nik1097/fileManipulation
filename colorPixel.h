#ifndef COLORPIXEL_H
#define COLORPIXEL_H

class ColorPixel{
   private:
    unsigned char red;
    unsigned green;
    unsigned blue;

   public:
    ColorPixel(){
        red = 0;
        green = 0;
        blue = 0;
    }
    ColorPixel(unsigned char red, unsigned char green, unsigned char blue){
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    // Getters
    unsigned char getRed(){ 
        return red; 
    }
    unsigned char getGreen(){ 
        return green; 
    }
    unsigned char getBlue(){ 
        return blue; 
    }

    // Setters
    void setRed(unsigned char red){ 
        this->red = red; 
    }
    void setGreen(unsigned char green){ 
        this->green = green; 
    }
    void setBlue(unsigned char blue){ 
        this->blue = blue; 
    }
};

#endif