// Nikhil Suresh & Devin Lilaramani 

#ifndef GRAYPIXEL_H
#define GRAYPIXEL_H

#include<string>

using namespace std;

class GrayPixel{
   private:
    string gp;

   public:
    GrayPixel(){}
    GrayPixel(string gp){
        this->gp = gp;
    }
    string getGp(){ 
        return gp;
    }
    void setGp(string gp){
        this->gp = gp;
    }
};

#endif