// Add code everywhere you see this:
// Your code >>>

#include <iostream>

using namespace std;

int num_resize; // the number of resizes
int num_copy;  // the number of copied elements
int size = 0;

void resize_array(int*& array, int& capacity)
{
  // Your code >>> resize array by doubling its capacity
  // Your code >>> use tracker variables:
  //           >>> num_resize and num_copy

  // first insert
    if (capacity == 0) {
        capacity = 1;
        num_resize++;

        // create temp array
        int *temp_array = new int[capacity];
        
        // clean up
        delete[] array;
        array = temp_array;
        //delete[] temp_array;
        temp_array = nullptr;

    } else {
        
        capacity *= 2;
        num_resize++;

        // create temp array
        int *temp_array = new int[capacity];
        
        // clean up
        delete[] array;
        // assign array with temp array and clean up temp array
        array = temp_array;
        //delete[] temp_array;
        temp_array = nullptr;

    }
}

void add_elements(int start, int total_elem)
{
    // Clear tracker variables
    num_resize = num_copy = 0;

    // Initialize array
    int capacity = start;
    int size = 0;
    int* A = new int[capacity];

    // Add elements to array
    while (size < total_elem)
    {
        if (size == capacity) // Array is full; add more space
        {
          resize_array(A, capacity);
          
        }
        ++size;
        int index = size - 1;
        A[index] = index*index; // new values
    }
    num_copy = capacity - 1;

    // Print tracking info
    cout << "Total elements: " << total_elem << endl;
    cout << "Resize " << num_resize << " times." << endl;
    cout << "Copied " << num_copy << " elements in total." << endl;
}

int main()
{
  // test this program
  int total_elem[]= {1, 2, 4, 64, 1024};
  for (int i = 0; i < 5; i++)
    add_elements(1, total_elem[i]);
}
