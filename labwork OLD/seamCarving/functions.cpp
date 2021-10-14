#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

#define INFO(X) cout << "[INFO] (" << __FUNCTION__ << ":" << __LINE__ << ") " << #X << " = " << X << endl;

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::ofstream;

Pixel **createImage(int width, int height)
{
  //cout << "Start createImage... " << endl;

  // Create a one dimensional array on the heap of pointers to Pixels
  //    that has width elements (i.e. the number of columns)
  Pixel **image = new Pixel *[width];

  bool fail = false;

  for (int i = 0; i < width; ++i)
  { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];

    if (image[i] == nullptr)
    { // failed to allocate
      fail = true;
    }
  }

  if (fail)
  { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i = 0; i < width; ++i)
    {
      delete[] image[i]; // deleting nullptr is not a problem
    }
    delete[] image; // dlete array of pointers
    return nullptr;
  }

  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = {0, 0, 0};
    }
  }
  //cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel **image, int width)
{
  //cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i = 0; i < width; ++i)
  {
    delete[] image[i]; // delete each individual array placed on the heap
  }
  delete[] image;
  image = nullptr;
}

int *createSeam(int length)
{
  // TODO(student): create a seam
  int *array = new int[length];
  for (int i = 0; i < length; i++) {
    array[i] = 0;
  }

  return array;
}

void deleteSeam(int *seam)
{
  delete[] seam;
}

bool loadImage(string filename, Pixel **image, int width, int height)
{
  // TODO(student): load an image
  //INFO(filename);
  //INFO(image);
  //INFO(width);
  //INFO(height);

  //filename = "/seamCarving/" + filename;

  ifstream ifs(filename);

  // check if input stream opened successfully
  if (!ifs.is_open())
  {
    cout << "Error: failed to open input file - " << filename << endl;
    return false;
  }

  float counter = 0.0;
  string counterString = "";

  string tempValueS = "";
  int tempValue = 0;
  Pixel temp = {0, 0, 0};
  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";










  // get type from preamble
  char type[3];
  ifs >> type; // should be P3
  if ((toupper(type[0]) != 'P') || (type[1] != '3'))
  { // check that type is correct
    cout << "Error: type is " << type << " instead of P3" << endl;
    return false;
  }

  // get width (w) and height (h) from preamble
  int w = 0, h = 0;
  ifs >> w >> h;

  if (w != width) { 
    // check that width matches what was passed into the function
    cout << "Error: input width (" << width << ") does not match value in file (" << w << ")" << endl;
    return false;
  }
  if (h != height) {
     // check that height matches what was passed into the function
    cout << "Error: input height (" << height << ") does not match value in file (" << h << ")" << endl;
    return false;
  }




  // get maximum value from preamble
  int colorMax = 0;
  ifs >> colorMax;
  if (colorMax != 255)
  {
    cout << "Error: file is not using RGB color values." << endl;
    return false;
  }

  
  
  // check number of pixels  
  while (ifs >> counterString) {counter++;}
  //cout << "Counter RGB: " << counter << endl;
  counter = (float) (counter / 3.0);
  //cout << "Counter PreRound: " << counter << endl << endl;
  //counter = round(counter);
  //cout << "Counter Rounded: " << counter << endl << endl;

  if (counter < (width * height)) {cout << "Error: not enough color values" << endl;}
  if (counter > (width * height)) {cout << "Error: too many color values " << endl;}

  ifs.clear();
  ifs.seekg(0, std::ios::beg);

  // reset position of file stream to where pixels start
  ifs >> type;
  ifs >> w >> h;
  ifs >> colorMax;




  // check errors and fill image with pixel data from file
  for (int row = 0; row < height; row++)
  {
    for (int column = 0; column < width; column++)
    {
      for (int element = 0; element < 3; element++)
      {
        ifs >> tempValueS;

        if (alpha.find(tempValueS[0]) < 1000)
        {
          cout << "Error: read non-integer value" << endl;
          exit(1);
        }
        else
        {
          tempValue = std::stoi(tempValueS);
        }

        if (tempValue < 0 || tempValue > 255)
        {
          cout << "Error: invalid color value " << tempValue << endl;
          exit(1);
        }

        switch (element)
        {
        case 0:
          temp.r = tempValue;
          continue;

        case 1:
          temp.g = tempValue;
          continue;

        case 2:
          temp.b = tempValue;
          continue;

        default:
          continue;
        }
      }

      image[column][row] = temp;
    }
  }

  return true;
}

bool outputImage(string filename, Pixel **image, int width, int height)
{
  //cout << "Outputting image..." << endl;
  // TODO(student): declare/define and open output file stream
  ofstream ofs (filename);
  

  // TODO(student): check if output stream opened successfully
  if (!ofs.is_open()) {
    cout << "Error: failed to open output file " << filename << endl;
  }
  // TODO(student): output preamble
  ofs << "P3" << endl;
  ofs << width << " " << height << endl;
  ofs << "255" << endl;
  
  // TODO(student): output pixels
  Pixel temp = {0,0,0};

  int column = 0;
  for (int row = 0; row < height; row++)
  {
    for (column = 0; column < width - 1; column++)
    {

      temp = image[column][row];
      ofs << temp.r << " " << temp.g << " " << temp.b << " ";
      //cout << temp.r << " " << temp.g << " " << temp.b << " ";
    }

    if (row == height - 1) {
      temp = image[column][row];
      ofs << temp.r << " " << temp.g << " " << temp.b;
      //cout << temp.r << " " << temp.g << " " << temp.b << " | ";
    } else {
      //cout << "height: " << height << endl;
      //cout << "row: " << row << endl << endl;
      //cout << "width: " << width << endl;
      //cout << "column: " << column << endl << endl;
      //temp = image[column][row];
      ofs << temp.r << " " << temp.g << " " << temp.b << endl;
      //cout << temp.r << " " << temp.g << " " << temp.b << endl;
    }
  }
  ofs.close();
  return true;
}

int energy(Pixel **image, int column, int row, int width, int height)
{
  // TODO(student): compute the energy of a pixel


  //Pixel** image = createImage(1,1);
  //image[0]0] = {1,0,0};

  int rGradientX = 0;
  int gGradientX = 0;
  int bGradientX = 0;
  int rGradientY = 0;
  int gGradientY = 0;
  int bGradientY = 0;

  int xGradient = 0;
  int yGradient = 0;

  int colPosLeft = 0;
  int colPosRight = 0;
  int rowPosUp = 0;
  int rowPosDown = 0;

  bool width1 = false;
  bool height1 = false;


  if (height == 1) {height1 = true;}
  if (width == 1) {width1 = true;}
  if (height1 && width1) {return 0;}

  //if (width == 1) {return 0;}
  // handle width and height = 0
  
  // handle border pixels
  if (column == width - 1) {
    colPosLeft = width - 2;
    colPosRight = 0;
  }
  else if (column == 0) {
    colPosLeft = width - 1;
    colPosRight = 1;
  } 
  else {
    colPosLeft = column - 1;
    colPosRight = column  + 1;
  }

  if (row == height - 1) {
    rowPosUp = height - 2;
    rowPosDown = 0;
  }
  else if (row == 0) {
    rowPosUp = height - 1;
    rowPosDown = 1;
  }
  else {
    rowPosUp = row - 1;
    rowPosDown = row + 1;
  }




  if (!width1) {
    //set X gradients
    rGradientX = abs(image[colPosRight][row].r - image[colPosLeft][row].r);
    gGradientX = abs(image[colPosRight][row].g - image[colPosLeft][row].g);
    bGradientX = abs(image[colPosRight][row].b - image[colPosLeft][row].b);
  } else {
    rGradientX = image[column][row].r;
    gGradientX = image[column][row].g;
    bGradientX = image[column][row].b;
  }
  

  if (!height1) {
    //set Y gradients
    rGradientY = abs(image[column][rowPosDown].r - image[column][rowPosUp].r);
    gGradientY = abs(image[column][rowPosDown].g - image[column][rowPosUp].g);
    bGradientY = abs(image[column][rowPosDown].b - image[column][rowPosUp].b);
  } else {
    rGradientY = image[column][row].r;
    gGradientY = image[column][row].g;
    bGradientY = image[column][row].b;
  }

  
  
  //set the main X and Y gradients
  xGradient = pow(rGradientX, 2) + pow(gGradientX, 2) + pow(bGradientX, 2);
  yGradient = pow(rGradientY, 2) + pow(gGradientY, 2) + pow(bGradientY, 2);

  //output energy
  return xGradient + yGradient;
}

int loadVerticalSeam(Pixel **image, int start_col, int width, int height, int *seam)
{
  // TODO(student): load a vertical seam
  int curColumn = start_col;
  int nextColumn = 0;

  int left = 0;
  int right = 0;
  
  long minEnergy = 100000000;
  //cout << minEnergy << endl << endl;
  int leftEnergy = 0;
  int downEnergy = 0;
  int rightEnergy = 0;
  int totalEnergy = 0;

  /*
  cout << "Image: " << endl;

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      cout << image[j][i].r << " ";
      cout << image[j][i].g << " ";
      cout << image[j][i].b << "   ";
    }
    cout << endl;
    
  }
  cout << endl;

  */
  
  totalEnergy += energy(image, curColumn, 0, width, height);

  //bool debug = false;
  int row = 0;

  for (row = 0; row < height - 1; row++) {
    if (curColumn == 0) {left = 0;} else {left = curColumn - 1;}
    if (curColumn == width - 1) {right = width - 1;} else {right = curColumn + 1;}


    //grab left energy
    downEnergy = energy(image, curColumn, row + 1, width, height);
    rightEnergy = energy(image, right, row + 1, width, height);
    leftEnergy = energy(image, left, row + 1, width, height);

    //pick next column based on maxEnergy
    if (downEnergy < minEnergy) {minEnergy = downEnergy; nextColumn = curColumn;} //cout << "Down" << endl;}
    if (rightEnergy < minEnergy) {minEnergy = rightEnergy; nextColumn = right;} //cout << "Right" << endl;}
    if (leftEnergy < minEnergy) {minEnergy = leftEnergy; nextColumn = left;} //cout << "Left" << endl;}
    
    
    //cout << "minEnergy: " << minEnergy << endl;
    
    //cout << "Next Col: " << nextColumn << endl << endl;

    totalEnergy += minEnergy;
    seam[row] = curColumn;
    curColumn = nextColumn;
    minEnergy = 10000000;
  }
  //cout << "ROW: " << row << endl;
  seam[row] = nextColumn;
  //cout << "Value: " << seam[row] << endl;
  //cout << "row: " << row << endl;
  //cout << "curCol: " << curColumn << endl;
    
  cout << "Seam: " << endl;
  for (int i = 0; i < height; i++)
  {
    cout << seam[i] << endl;
  }
  cout << "Total Energy: " << totalEnergy << endl;

  return totalEnergy;
}

int loadHorizontalSeam(Pixel **image, int start_row, int width, int height, int *seam)
{
  // TODO(student): load a horizontal seam
  INFO(image);
  INFO(start_row);
  INFO(width);
  INFO(height);
  INFO(seam);
  return 0;
}

int *findMinVerticalSeam(Pixel **image, int width, int height)
{
  // TODO(student): find min vertical seam
  long minimum = 1000000;
  int* seam = createSeam(height);
  long currentEnergy = 0;
  int index = 0;

  for (int col = 0; col < width; col++)
  {
    currentEnergy = loadVerticalSeam(image, col, width, height, seam);
    if (currentEnergy < minimum) {
      minimum = currentEnergy;
      index = col;
    }
  }

  loadVerticalSeam(image, index, width, height, seam);
  
  /*
  int seam2[height];
  for (int i = 0; i < height; i++) {
    seam2[i] = seam[i];
  }
  */

  //delete seam;

  return seam;
}

int *findMinHorizontalSeam(Pixel **image, int width, int height)
{
  // TODO(student): find min horizontal seam
  INFO(image);
  INFO(width);
  INFO(height);
  return nullptr;
}

void removeVerticalSeam(Pixel **image, int width, int height, int *verticalSeam)
{
  // TODO(student): remove a vertical seam

  int start = 0;


  for (int row = 0; row < height; row++)
  {
    
    start = verticalSeam[row];

    for(int col = start; col < width - 1; col++) 
    {
      image[col][row] = image[col + 1][row];
    } 
  }
  
}

void removeHorizontalSeam(Pixel **image, int width, int height, int *horizontalSeam)
{
  // TODO(student): remove a horizontal seam
  INFO(image);
  INFO(width);
  INFO(height);
  INFO(horizontalSeam);
}
