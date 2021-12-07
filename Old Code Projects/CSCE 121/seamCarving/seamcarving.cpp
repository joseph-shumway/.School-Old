#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout;
using std::cin;
using std::string;
using std::ostringstream;
using std::endl;

int main() { 

  //energy(Pixel ** image[1][1], 0,0 , 1, 1);
  cout << "Input filename: ";
  string filename;
  cin >> filename;
  


  //get width and height, then check for validity
  cout << "Input width and height: ";
  int width = 0;
  int height = 0;
  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  string tempWidth = "";
  string tempHeight = "";
  cin >> tempWidth  >> tempHeight;

  
    
  if (alpha.find(tempWidth[0]) < 1000) {
    cout << "Error: width is a non-integer value" << endl;
    exit(1);
  } else {
      width = std::stoi(tempWidth);
  }

  if (alpha.find(tempHeight[0]) < 1000) {
    cout << "Error: height is a non-integer value" << endl;
    exit(1);
  } else {
      height = std::stoi(tempHeight);
  }



  if (width <= 0) {
      cout << "Error: width must be greater than 0. You entered " << width << endl;
      exit(1);
  }

  if (height <= 0) {
      cout << "Error: height must be greater than 0. You entered " << height << endl;
      exit(1);
  }

  //Get target width and height, then check for validity
  
  cout << "Input target width and height: " << endl;
  int targetWidth = 0;
  int targetHeight = 0;
  string tempTargetWidth = "";
  string tempTargetHeight = "";
  cin >> tempTargetWidth >> tempTargetHeight;
  
  if (alpha.find(tempTargetWidth[0]) < 1000) {
    cout << "Error: target width is a non-integer value" << endl;
    exit(1);
  } else {
      targetWidth = std::stoi(tempTargetWidth);
  }

  if (alpha.find(tempTargetHeight[0]) < 1000) {
    cout << "Error: target height is a non-integer value" << endl;
    exit(1);
  } else {
      targetHeight = std::stoi(tempTargetHeight);
  }

  if (targetWidth <= 0) {
      cout << "Error: target width must be greater than 0. You entered " << targetWidth << endl;
      exit(1);
  }

  if (targetHeight <= 0) {
      cout << "Error: target height must be greater than 0. You entered " << targetHeight << endl;
      exit(1);
  }

  // check if targetHeight or targetWidth are less than height and width
  if (targetHeight > height) {
      cout << "Error: target height must be less than height, " << targetHeight << " is greater than " << height << endl;
      exit(1);
  }

  if (targetWidth > width) {
      cout << "Error: target width must be less than width, " << targetWidth << " is greater than " << width << endl;
      exit(1);
  }
  
  
  
  // save originalWidth since width will change with carving
  int originalWidth = width; 
  
  Pixel** image = createImage(width, height);
  //int testimage[3][4];
  if (image != nullptr) { // new returns nullptr if it fails to allocate array

    if (loadImage(filename, image, width, height)) {
      cout << endl;

      //findMinVerticalSeam(image, width, height);

      int testEnergy = 0;
      testEnergy += energy(image, 0, 0, width, height);
      cout << "Energy: " << testEnergy << endl << endl;
      testEnergy += energy(image, 0, 1, width, height);
      cout << "Energy: " << testEnergy << endl << endl;
      testEnergy += energy(image, 0, 2, width, height);
      cout << "Energy: " << testEnergy << endl << endl;

      

      //int* seam1 = new int[height];
      //seam1 = createSeam(height);
      
      //int energy1 = energy(image, 0,0, width, height);
      //loadVerticalSeam(image, 1, width, height, seam1);
      //cout << "Energy: " << energy1 << endl;
      
      // uncomment for part 2

      /*
      
      for (int i = 0; i < height; i++)
      {
        for (int j = 0; j < width; j++)
        {
          testimage[j][i] = energy(image, j, i, width, height);
          cout << testimage[j][i] << " ";
        }
        cout << endl;
      }
      cout << endl << endl;
      
      */
      
      while (width - targetWidth > 0) {
        if (width - targetWidth > 0) {
          int* verticalSeam = findMinVerticalSeam(image, width, height);
          removeVerticalSeam(image, width, height, verticalSeam);
          deleteSeam(verticalSeam);
          width--;
          cout << "SHRINK!" << endl;
        }
        
        /*
        // this is for the extra credit
        if (height - targetHeight > 0) {
          int* horizontalSeam = findMinHorizontalSeam(image, width, height);
          removeHorizontalSeam(image, width, height, horizontalSeam);
          deleteSeam(horizontalSeam);
          height--;
        }
        */
      }
      
     
      
      
      ostringstream oss;
      oss << "carved" << width << "X" << height << "." << filename;
      outputImage(oss.str().c_str(), image, width, height);
    }
  }
  
  // call last to remove the memory from the heap
  deleteImage(image, originalWidth);
}