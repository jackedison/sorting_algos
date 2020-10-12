// This source file is intended to demonstrate various sorting algorithm implementations in C++

// Note: header files for class implementations etc. (.h extension)
// http://www.math.uaa.alaska.edu/~afkjm/csce211/handouts/SeparateCompilation.pdf

#include <iostream>
using namespace std;
#include <vector>
#include "selection_sort.cpp"

int main(){
    SelectionSort selectionsort;  // don't actually need this since create object after class declaration
    selectionsort.set_values({3, 2, 1});
    selectionsort.sort();





    return 0;
}