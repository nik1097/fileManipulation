#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <vector>
using namespace std;

int main() {
  int row = 0, col = 0, numrows = 0, numcols = 0;
  ifstream infile("chips-1.pgm");
  stringstream ss;
  string inputLine = "";

  // First line : version
  getline(infile,inputLine);
  if(inputLine.compare("P2") != 0) cerr << "Version error" << endl;
  else cout << "Version : " << inputLine << endl;

  // Second line : comment
  getline(infile,inputLine);
  cout << "Comment : " << inputLine << endl;

  // Continue with a stringstream
  ss << infile.rdbuf();
  // Third line : size
  ss >> numcols >> numrows;
  cout << numcols << " columns and " << numrows << " rows" << endl;

  int array[numrows][numcols];
  //vector<vector<int>> array( numrows , vector<int> (numcols, 0));
  vector<vector<int>> vec(numcols , vector<int> (numrows, 0));

  // Following lines : data
  for(row = 0; row < numrows; ++row)
    for (col = 0; col < numcols; ++col) ss >> array[row][col];
  infile.close();
  
  for(row = 0; row < numrows; ++row) {
    for(col = 0; col < numcols; ++col) {
       cout<<array[row][col];
       vec[numcols-col-1][row] = array[row][col];
       //break;
    }
  }

  ofstream myfile ("example_2.pgm");
  if (myfile.is_open()){
    myfile << "P5\n";
    myfile << "# Rotated image\n";
    myfile << "1300 1129\n";
    myfile << "255\n";
    for(row = 0; row < numrows; ++row)
      for (col = 0; col < numcols; ++col) 
        myfile << vec[row][col] << "\n";
    myfile.close();
  }
}