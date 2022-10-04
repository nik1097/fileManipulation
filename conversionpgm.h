// Nikhil Suresh & Devin Lilaramani 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#ifndef CONVERSIONPGM_H
#define CONVERSIONPGM_H


#define SIZE 256

class Conversionpgm{
//void writeP5 (FILE *inFile, FILE *outFile);

//represents a single pixel object
typedef struct Pixel {
  unsigned char g;
}GreyPix;

//this struct is used to store the entire image data, along with the width and height
typedef struct Image {
  int width, height;
  GreyPix *data;
}PGMImage;

//write a p2 file
public:
 void writeP2 (FILE *inFile, FILE *outFile)
{

  //buffer used for the comments mainly
  char buff[SIZE], *fh;

  PGMImage image;

  int read, i, j, counter = 1;
  unsigned int maxColors;


  fh = (char *)malloc(sizeof(char) * SIZE);
  fh = fgets(buff, SIZE, inFile);             //Make sure we are reading the right type of file
  if ( (fh == NULL) || ( strncmp(buff, "P5\n", 2) != 0 ) ) perror("Please provide a P5 .pgm file for conversion\n");
  (void) fprintf(outFile, "P2\n");

  //get rid of comments
  do
        {
           fh = fgets(buff, SIZE, inFile);      //write the comments into the out file
           if( strncmp(buff, "#", 1) == 0) fprintf(outFile, "%s", buff);
           if ( fh == NULL ) return;
        } while ( strncmp(buff, "#", 1) == 0 );

  //read in the width and height
  read = sscanf(buff, "%u %u", &image.width, &image.height);


  //throw error if the width and height aren't in the file
  if(read < 2) {
    perror("File Unreadable. Please check the file format\n");
    return;
  }
  image.data = (GreyPix *)malloc(sizeof(GreyPix) * image.width * image.height);

  read = fscanf(inFile, "%u", &maxColors);
  //check that the right color format is used
  if(maxColors != 255 || read != 1) {
    perror("Please provide an 24-bit color file");
    return;
  }


  //put all that good stuff into the outFile
  fprintf(outFile, "%u %u\n%u\n",image.width, image.height, maxColors);

  //read the image into the buffer
  fread(image.data, sizeof(GreyPix), image.width * image.height, inFile);

  //write out to the ascii file
  for (i = 0; i < image.width * image.height; i++)
  {
      fprintf(outFile, " %d ", image.data[i].g);

      //format handling
      if(counter == image.width) {
        fprintf(outFile, "\n");
        counter = 1;
      }
      else counter += 1;
    }

}
};