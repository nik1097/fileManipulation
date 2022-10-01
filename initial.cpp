#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <sstream> // stringstream
using namespace std;

int main() {
  int row = 0, col = 0, numrows = 0, numcols = 0;
  ifstream infile("cats_chips.pgm");
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
  ss >> numcols >> numrows;
  cout << numcols << " columns and " << numrows << " rows" << endl;

  int array[numrows][numcols];
  int rev_array[numrows][numcols];
  
  for(row = 0; row < numrows; ++row)
    for (col = 0; col < numcols; ++col)  
      ss >> array[row][col];

  infile.close();
  
  for(row = 0; row < numrows; ++row)
    for (col = 0; col < numcols; ++col)
      //rev_array[col][numrows-row-1] = array[row][col]; // 90 rotation
      //rev_array[numrows-row-1][numcols-col-1] = array[row][col]; // 180 rotation
      rev_array[numcols-col-1][row] = array[row][col]; // 270 rotation
  
  ofstream myfile ("example.pgm");
  if (myfile.is_open())
  {
    myfile << "P2\n";
    myfile << "# Rotated image\n";
    myfile << "704 704\n";
    for(row = 0; row < numrows; ++row)
      for (col = 0; col < numcols; ++col) 
        myfile << rev_array[row][col] << "\n";
    myfile.close();
  }
  return 0;
}
