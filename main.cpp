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
bool validImage()/*checks if actually a bmp. if not, print an error and make them
                   do it again*/

bool sizeCheck()// checks size of image

void getFileNames(vector<string> get_fileNames);// asks user for file name1



void printMatrix( vector <vector <char> > );

void combine(vector<Bitmap> pics)
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
return 0;
}

void combine(vector<Bitmap> pics)/////333333
{
  vector<vector<Pixel> > result;
  vector<vector<Pixel> > current_pic;
  int size = pics.size();
  current_pic = image.toPixelMatrix();
  result[][] = current_pic/ pics.size()
}





vector<string> get_filenames()//1111111111
{
  cout << "yo"
  string s;
  vector<string> v;
  while(cin >> s)
    v.push_back(s);
  return v;
}


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



Bitmap image;
image.open(fileName);
vector<Bitmap> images
if( image.isImage() )
{
  images.push_back(image)
}
vector<vector<Pixel>> bmp;
bmp = image.toPixelMatrix();
