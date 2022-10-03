#include <iostream>
#include "rotator.h"
#include "grayPixel.h"
#include <fstream>

using namespace std;

Rotator *Rotator::instance = 0;

// should implement functions here, unless they are inlined

void Rotator::rotate(Pgm* input, int degrees, string output_file){
    int magicNum = input->getMagicNum();
    int maxVal = input->getMaxVal();
    int width = input->getWidth(); // numofcols
    int height = input->getHeight(); //numofrows

    vector<vector<GrayPixel*>> rev_array(height, vector<GrayPixel*>(width));

    for(int row = 0; row < height; ++row){
        for (int col = 0; col < width; ++col){
            if (degrees == 90)
               rev_array[col][height-row-1] = input->gp_array[row][col]; 
            else if (degrees == 180)
                rev_array[height-row-1][width-col-1] = input->gp_array[row][col];
            else if (degrees == 270)
                rev_array[width-col-1][row] = input->gp_array[row][col];
        }
    } 
    ofstream myfile(output_file);
    if (myfile.is_open()){
        myfile << "P" << magicNum << endl;
        myfile << "# Rotated image\n";
        myfile << width<<" "<<height<<endl; 
        myfile << maxVal<<endl;
        for(int row = 0; row < height; ++row){
            for (int col = 0; col < width; ++col){ 
                GrayPixel* gp = rev_array[row][col];
                myfile << gp->getGp() << "\n";
            }
        }
        myfile.close();
    }
}