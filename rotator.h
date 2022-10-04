// Nikhil Suresh & Devin Lilaramani 


#ifndef ROTATOR_H
#define ROTATOR_H

#include <iostream>
#include "pgm.h"
#include "ppm.h"

using namespace std;

class Rotator{
   private:
    static Rotator* instance;
    Rotator(){};

   public:
    static Rotator* getInstance() {
      if (!instance) instance = new Rotator;
        return instance;
    }
    void rotate(Pgm* in_file, int degrees, string output_file);
    void rotate(Ppm* in_file, int degrees, string output_file);
};

#endif