// Nikhil Suresh & Devin Lilaramani 


#include <iostream>
#include <fstream>
#include "pgm.h"
#include "ppm.h"
#include "rotator.h"
#include <vector>
#include "grayPixel.h"
#include <sstream>
#include "conversionppm.h"
#include "conversionpgm.h"

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
        
        ifstream infile(input_file);
        stringstream ss;
        string inputLine = "";

        int magicNum, width, height, maxVal;
        int count = 0;
        // First line : version
        getline(infile, inputLine);
        if(inputLine.compare("P5") == 0){
            const char *input = input_file.c_str();
            const char* p2Converted = "P2File.pgm";
            FILE *inputFile = fopen(input, "rb");
            FILE *outFile = fopen(p2Converted, "wb");
            Conversionpgm *convert;

            convert->writeP2(inputFile, outFile);

            ifstream infile_1(p2Converted);
            string inputLine_1 = "";
            
            getline(infile_1, inputLine_1);

            pgm->setMagicNum(2);
            
            getline(infile_1, inputLine_1);
            if(inputLine_1[0] == '#')
                cout<<"Comment";

            ss << infile_1.rdbuf();
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
        else if(inputLine.compare("P2") == 0){
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
    else if (input_file.find("ppm") != std::string::npos){
        Ppm* ppm = new Ppm();
        
        ifstream infile(input_file);
        if (infile.fail()) {
            cout << "Could not open file: ";
        }
        stringstream ss;
        string inputLine = "";

        int magicNum, width, height, maxVal;
        int count = 0;
        // First line : version
        getline(infile, inputLine); 

        if(inputLine.compare("P6") == 0){
            const char *input = input_file.c_str();
            const char* p6Converted = "P6File.ppm";
            FILE *inputFile = fopen(input, "rb");
            FILE *outFile = fopen(p6Converted, "wb");
            Conversionppm *convert;

            convert->writeP3(inputFile, outFile);

            ifstream infile_1(p6Converted);
            string inputLine_1 = "";
            
            getline(infile_1, inputLine_1);

            ppm->setMagicNum(3);
            
            getline(infile_1, inputLine_1);
            if(inputLine_1[0] == '#')
                cout<<"Comment";

            ss << infile_1.rdbuf();
            ss >> width >> height >> maxVal;
            ppm->setWidth(width);
            ppm->setHeight(height);
            ppm->setMaxVal(maxVal);

            string red;
            string blue;
            string green;

            for(int row = 0; row < height; ++row){
                vector<ColorPixel*> pixels;
                for (int col = 0; col < width; ++col){
                    ss >> red >> blue >> green;
                    pixels.push_back(new ColorPixel({red, blue, green}));
                }
                ppm->cp_array.push_back(pixels);
            }
            rotator->rotate(ppm, degree, output_file);
        }
        else if(inputLine.compare("P3") == 0){
            ppm->setMagicNum(3);
            
            getline(infile, inputLine);
            if(inputLine[0] == '#')
                cout<<"Comment";

            ss << infile.rdbuf();
            ss >> width >> height >> maxVal;
            ppm->setWidth(width);
            ppm->setHeight(height);
            ppm->setMaxVal(maxVal);

            string red;
            string blue;
            string green;

            for(int row = 0; row < height; ++row){
                vector<ColorPixel*> pixels;
                for (int col = 0; col < width; ++col){
                    ss >> red >> blue >> green;
                    pixels.push_back(new ColorPixel({red, blue, green}));
                }
                ppm->cp_array.push_back(pixels);
            }
            rotator->rotate(ppm, degree, output_file);
        }
    }
}