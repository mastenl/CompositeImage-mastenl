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
bool validImage(string);

bool sizeCheck(int, int, int, int, int);// checks size of image

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




vector<string> getFileNames(vector<string> get_fileNames)//1  Checks if valid and creates vector of file names.
{
  //star-test1.bmp
  Pixel rgb;
  vector<string> images;
  vector <vector <Pixel> > bmp;
  int count=0;
  string picture;
  Bitmap image;
  bool validBmp;
  bool checking=true;
  bool sameSize;
  int x;
  int y;
  int xCheck;
  int yCheck;


    while(checking)
    {
      cout<< "Please enter a file you wish to add. Or, type done when finished. "<<count<<"/10 Passed"<<endl;
      cin>> picture;
      if(picture=="DONE")//if more than 2 files and type done =returns.
      {
        if (count<=2)//makes sure there is at least two images.
        {
          cout << "Needs at least two images." << endl;
          continue;
        }
        cout<<"Successful!!!"<<endl;
        return images;
      }

      if(count<HOW_MANY_INPUT)//opens image and check if valid
      {
        validBmp=validImage(picture);
      }
      else//stops from pushing images if more than 10. Only way to exit is to type done.
      {
        cout<<"Can't have more than 10 images."<<'\n'<<"You have:"<<count<<endl;
        continue;
      }


      if (validBmp == false)//checks if valid
      {
        cout<<"Please enter a valid image."<<endl;
        continue;
      }

      if(validBmp == true )//checks if valid. Pushes into images if actually is a file. also counts.
      {
        if (count==0)
        {
          image.open(picture);
          bmp = image.toPixelMatrix();
          const int x = bmp.size() ;
          const int y = bmp[0].size();
          sameSize=true;
        }
        if(count>=1)
        {
          bmp = image.toPixelMatrix();
          int xCheck = bmp.size() ;
          int yCheck = bmp[0].size();
          sameSize=sizeCheck(count, x, y, xCheck, yCheck);
        }

        if (sameSize == false)//checks if valid
        {
          cout<<"Please enter an image the same size."<<endl;
          continue;
        }
        if(count==0 || sameSize==true)
        {
        images.push_back(picture);
        count++;
        }


      }
    }
}

bool validImage(string im)//2222222222222222
{
bool validBmp;
Bitmap image;

  image.open(im);
  if (image.isImage() == false)
  {
    return false;
  }

  else
  {
   return true;
  }
}

bool sizeCheck(int count, int x, int y, int xCheck, int yCheck)
{
  if(count==0)
  {
    return true;
  }
  if(count>0)
  {
    if(x==xCheck)
    {
      if(y==yCheck)
      {
      return true;
      }
    }
    else
    {
      return false;
    }
  }
}
/*
validImage()//2222222222222222
{
vector<vector<Pixel>> bmp;
Bitmap image;
image.open(fileName);
vector<Bitmap> images


if( image.isImage() )
{
  images.push_back(image)
}

bmp = image.toPixelMatrix();
}
*/
