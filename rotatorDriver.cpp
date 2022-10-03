#include <iostream>
#include <fstream>
#include "pgm.h"
#include "ppm.h"
#include "rotator.h"
#include <vector>
#include "grayPixel.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
    string input_file = argv[2];
    string output_file = argv[3];
    string orient = argv[4];
    int degree = stoi(argv[5]);

    cout<<degree;

    if(orient == "-l")
        degree = 360 - degree;

    Rotator* rotator = rotator->getInstance();

    if (input_file.find("pgm") != std::string::npos){
        Pgm* pgm = new Pgm();
        
        ifstream infile("cats_chips.pgm");
        stringstream ss;
        string inputLine = "";

        int magicNum, width, height, maxVal;
        int count = 0;
        // First line : version
        getline(infile, inputLine);
        if(inputLine.compare("P2") == 0){
            pgm->setMagicNum(2);
            
            getline(infile, inputLine);
            if(inputLine[0] == '#')
                cout<<"Comment";

            ss << infile.rdbuf();
            ss >> width >> height >> maxVal;
            pgm->setWidth(width);
            pgm->setHeight(height);
            pgm->setMaxVal(maxVal);

            string temp;

            for(int row = 0; row < height; ++row){
                vector<GrayPixel*> pixels;
                for (int col = 0; col < width; ++col){
                    ss >> temp;
                    pixels.push_back(new GrayPixel(temp));
                }
                pgm->gp_array.push_back(pixels);
            }
            rotator->rotate(pgm, degree, output_file);
        }
    }
}