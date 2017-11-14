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

bool sizeCheck( int, int, int, int);// checks size of image

vector<string> getFileNames(vector<string> get_fileNames); // asks user for file name1

vector<vector<vector<Pixel> > > createVector(vector<string> v);

void printMatrix( vector <vector <Pixel> > );

vector<vector<Pixel> > combine(vector < vector < vector< Pixel > > > & combineImages);


//Main program...
int main()
{
Pixel rgb;
Bitmap image;
vector<string> fileNames;
vector<vector<vector< Pixel > > > bmp;

bmp = createVector(getFileNames(fileNames));
printMatrix(combine(bmp));
return 0;
}

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
  int xCheck=0;
  int yCheck=0;


    while(checking)
    {
      cout<< "Please enter a file you wish to add. Type DONE when finished. "<<count<<"/10 Passed"<<endl;
      cin>> picture;
      if(picture=="DONE")//if more than 2 files and type done =returns.
      {
        if (count<2)//makes sure there is at least two images.
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
          x = bmp.size();
          y = bmp[0].size();
          sameSize=true;
        }
        if(count>=1)
        {
          bmp = image.toPixelMatrix();
          int xCheck = bmp.size() ;
          int yCheck = bmp[0].size();
          sameSize=sizeCheck(x, y, xCheck, yCheck);
        }

        if (sameSize == false)//checks if valid
        {
          cout<<"Please enter an image the same size."<<endl;
          continue;
        }
        if(sameSize==true)
        {
        images.push_back(picture);
        count++;
        }
      }
    }
}

bool validImage(string im)//checks if it's actually an image
{
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

bool sizeCheck(int x, int y, int xCheck, int yCheck)//checks size
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

vector<vector<vector<Pixel> > > createVector(vector<string> v)
{
  vector<vector<vector<Pixel> > > bmpVector;
  Bitmap image;
  Pixel rgb;
  for (int i = 0; i < v.size(); i++)
  {
    image.open(v[i]);
    bmpVector.resize(v.size());
    bmpVector[i]=image.toPixelMatrix();
  }
  return bmpVector;
}

vector<vector<Pixel> > combine(vector < vector < vector< Pixel > > > & combineImages)
{
  int maxValue=255;
  int minValue=0;
  Pixel rgb;
  Bitmap image;
  int size = combineImages.size();
  vector<vector<Pixel> > imageFinal;
  int r = 0;
  int g = 0;
  int b = 0;
  int bValue;
  int gValue;
  int rValue;

  imageFinal.resize(combineImages[0].size());//resizes
  for (int p = 0; p < imageFinal.size(); p++)
  {
    imageFinal[p].resize(combineImages[0][0].size());

  }



  for (int a = 0; a < combineImages[0].size(); a++)
  {
    for (int d = 0; d < combineImages[0][0].size(); d++)
    {
      for (int z = 0; z < combineImages.size(); z++)
      {
          r = combineImages[z][a][d].red;
          g = combineImages[z][a][d].green;
          b = combineImages[z][a][d].blue;

          rgb = combineImages[z][a][d];
          rValue = rValue + r;
          gValue = gValue + g;
          bValue = bValue + b;

      }
      r = rValue/size;
      g = gValue/size;
      b = bValue/size;
      rValue = 0;
      gValue = 0;
      bValue = 0;

      if (r > maxValue) //makes sure that it doent go above the max value and lower then min value.
      {
        r = maxValue;
      }
      if (r < minValue)
      {
        r = minValue;
      }
      if (g > maxValue)
      {
        g=maxValue;
      }
      if (g < minValue)
      {
        g = minValue;
      }
      if (b > maxValue)
      {
        b = maxValue;
      }
      if (b < minValue)
      {
        b = minValue;
      }

      rgb.red = r;
      rgb.green = g;
      rgb.blue = b;
      imageFinal[a][d] = rgb;
    }
    if (a == (combineImages[0].size()/2))
    {
      cout<<"50% Complete!!!"<<endl;
    }
    if (a == (combineImages[0].size()/4))
    {
      cout<<"25% Complete!!!"<<endl;
    }
    if (a == (combineImages[0].size()*3/4))
    {
      cout<<"75% Complete!!!"<<endl;
    }
  }
  cout<<"Complete!!!"<<endl;
  return imageFinal;
}


  void printMatrix(vector<vector<Pixel> >imageFinal)
  {
    Bitmap image;
    image.fromPixelMatrix(imageFinal);
    image.save("Composite-mastenl14.bmp");
  }
