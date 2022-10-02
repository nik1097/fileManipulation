#ifndef GRAYPIXEL_H
#define GRAYPIXEL_H

class GrayPixel{
   private:
    unsigned char gp;

   public:
    GrayPixel(){
        gp = 0;
    }
    GrayPixel(unsigned char gp){
        this->gp = gp;
    }
    unsigned char getGp(){ 
        return gp; 
    }

    void setGp(unsigned char gr){ 
        this->gp = gp; 
    }
};

#endif