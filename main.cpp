#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"
#include <cmath>
#include <ctime>
using namespace std;


//Global constants
const int HOW_MANY_INPUT = 10;

//Prototypes...
/*bool validImage() checks if actually a bmp. if not, print an error and make them
                   do it again*/

//bool sizeCheck()// checks size of image

vector<string> getFileNames(vector<string> get_fileNames); // asks user for file name1



//void printMatrix( vector <vector <char> > );

void combine(vector < vector < vector< Pixel > > >);


//Main program...
int main()
{
  /*

     1.Input image and make sure it is valid bmp
     2.
     3.put each image into pixel matrix
     4.
     5.
  */

  Bitmap image;
  vector <string> fileNames;
  vector<vector<vector< Pixel > > > bmp;
  Pixel rgb;

  fileNames = getFileNames(fileNames);


return 0;
}

/*
void combine(vector<Bitmap> pics)/////333333
{
  vector<vector<Pixel> > result;
  vector<vector<Pixel> > current_pic;
  int size = pics.size();
  current_pic = image.toPixelMatrix();
  result[][] = current_pic/ pics.size()
}
*/




vector<string> getFileNames(vector<string> get_fileNames)//1111111111
{
  vector<string> imgv;
  int count=0;

  string fileName;
  cout<< "Please enter a file you wish to add."<< endl;

  cin>> fileName;

    imgv.push_back(fileName);
    return imgv;

}

/*
validImage()//2222222222222222
{
bool validBmp;
do
{

  image.open(fileName);
  validBmp = image.isImage();
  if (validBmp == false)
  {
    cout <<'\v'<<"This file can not be read."<<endl;
    cout << "The file must be an accesible 24 bit depth Windows BMP file." << endl;
  }
}
while(validBmp == false );


if( validBmp == true )
 {
   return true;
 }
}


/*
validImage()//2222222222222222
{
Bitmap image;
image.open(fileName);
vector<Bitmap> images


if( image.isImage() )
{
  images.push_back(image)
}
vector<vector<Pixel>> bmp;
bmp = image.toPixelMatrix();
}
*/
