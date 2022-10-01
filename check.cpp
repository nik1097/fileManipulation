#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

//CUSTOM SPLIT FUNCTION TO SEPARATE WORDS INTO VECTOR
vector<string> split(const string& input, char delim)
{
    vector<string> result;
    stringstream stream;
    stream.str(input);
    string token;
    while (getline(stream, token, delim)) {
        result.push_back(token);
    }
    return result;
}

//PGM CLASS
class pgmFile {
public:
    pgmFile(istream& in)
    { //CONSTRUCTOR THAT READS FROM A STREAM

        string buffer;
        int counter = 0;
        vector<int> row;
        while (getline(in, buffer)) { //WHILE WE HAVE LINES...
            if (counter == 0) { //IF IT'S THE FIRST LINE, SET HEADERS
                vector<string> firstLine = split(buffer, ' '); //SPLIT HEADER INTO ITS ELEMENTS
                this->type = firstLine[0];
                this->width = stoi(firstLine[1]);
                this->height = stoi(firstLine[2]);
                this->maxPixelValue = stoi(firstLine[3]);
            }
            else { //IF IT'S NOT THE FIRST LINE...
                if (counter == this->width) { //IF WE'VE READ A NUMBER OF PIXELS EQUIVALENT TO THE IMAGES WIDTH, WE'VE FINISHED THE FIRST ROW
                    row.push_back(stoi(buffer)); //PUSH LAST PIXEL FROM ROW IN
                    this->pixels.push_back(row); //PUSH ROW INTO PIXELS MEMBER
                    row.clear(); //CLEAR ROW TO PREPARE FOR NEXT
                    counter = 0; //RESET COUNTER
                }
                else { //IF COUTNER HASN'T REACHED WIDTH, WE STILL HAVE PIXELS TO READ IN
                    row.push_back(stoi(buffer)); //READ PIXEL INTO ROW
                }
            }
            counter++; //MOVE TO NEXT PIXEL
        }
    }
    void rRotate(string filename)
    { //ROTATE CLOCK-WISE
        int newWidth = this->height; //OLD HEIGHT BECOMES NEW WIDTH AND VICE-VERSA
        int newHeight = this->width;
        ofstream file(filename.c_str());
        if (!file.is_open())
            throw "Error creating file!";
        file << this->type << " " << newWidth << " " << newHeight << " " << this->maxPixelValue << endl; //WRITE HEADERS TO THE FILE
        int i = 0;
        while (i < newHeight) { //WRITING ROWS
            for (vector<vector<int> >::reverse_iterator j = this->pixels.rbegin(); j != this->pixels.rend(); j++) //ITERATE BACKWARDS
                file << (*j)[i] << endl; //WRITE FIRST PIXEL OF EVERY ROW TO FILE
            i++; //MOVE ON TO NEXT ROW
        }
    }
    void lRotate(string filename)
    { //ROTATE COUNTERCLOCKWISE (THAT'S A HORRIBLE WORD)
        int newWidth = this->height; //OLD HEIGHT BECOMES NEW WIDTH AND VICE-VERSA
        int newHeight = this->width;
        ofstream file(filename.c_str());
        if (!file.is_open())
            throw "Error creating file!";
        file << this->type << " " << newWidth << " " << newHeight << " " << this->maxPixelValue << endl; //WRITE HEADERS TO THE FILE
        int i = newHeight;
        while (i > 0) { //START ITERATING FROM THE LAST PIXEL OF EACH ROW
            for (auto it : this->pixels) // FOR EVERY ROW
                file << it[i] << endl; //PRINT TO FILE
            i--; //MOVE ON TO PREVIOUS PIXEL
        }
    }
    void vflip(string filename)
    { //FLIP VERTICAL
        ofstream file(filename.c_str());
        if (!file.is_open())
            throw "Error creating file!";
        file << this->type << " " << this->width << " " << this->height << " " << this->maxPixelValue << endl; //WRITE HEADERS TO THE FILE
        for (vector<vector<int> >::reverse_iterator i = this->pixels.rbegin(); i != this->pixels.rend(); i++) //START FROM LAST ROW
            for (vector<int>::reverse_iterator j = i->rbegin(); j != i->rend(); j++) //START FROM LAST PIXEL OF EACH ROW
                file << *j << endl;
    }
    void hFlip(string filename)
    { //FLIP HORIZONTAL
        ofstream file(filename.c_str());
        if (!file.is_open())
            throw "Error creating file!";
        file << this->type << " " << this->width << " " << this->height << " " << this->maxPixelValue << endl; //WRITE HEADERS TO THE FILE
        for (auto i : this->pixels) //FOR EVERY ROW
            for (vector<int>::reverse_iterator j = i.rbegin(); j != i.rend(); j++) //WRITE LAST PIXEL OF EACH ROW
                file << *j << endl;
    }

private:
    string type;
    int width;
    int height;
    int maxPixelValue;
    vector<vector<int> > pixels;
};

int main()
{
    ifstream input("cats_chips.pgm");
    if (!input.is_open())
        throw "Error opening file!";
    pgmFile file(input);
    //file.lRotate("leftRotate");
    //file.rRotate("rightRotate");
    //file.vflip("vFlip");
    //file.hFlip("hFlip");
}