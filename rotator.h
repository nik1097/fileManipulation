#ifndef ROTATOR_H
#define ROTATOR_H

#include "pgm.h"
#include "ppm.h"

class Rotator{
   private:
    static Rotator* instance;
    Rotator(){};

   public:
    static Rotator* Instance(){
        if (!instance){ 
            instance = new Rotator();
        }
        return instance;
    }
    void rotate(Ppm* in_file, Ppm* out_file, int degrees);
    void rotate(Pgm* in_file, Pgm* out_file, int degrees);
};

#endif