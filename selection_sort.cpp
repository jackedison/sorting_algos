#include <iostream>
using namespace std;
#include <vector>

// Selection sort works by repeatedly finding the minimum element and putting it at the front

class SelectionSort{
    int size;  // These variables are private since not declared public/protected.

    public:
      vector <int> array;  // Use vector instead of raw array. Much easier to copy and manipulate.
      void set_values(vector <int>) ;
      vector<int> sort(void);

} selectionsort;  // can create an object called 'selectionsort' here too

// Declare the functions in the class outside of it if needed?
void SelectionSort::set_values(vector <int> x){
    array = x;
    size = x.size();
}

vector<int> SelectionSort::sort(){
    vector<int> new_array = {};
    int* lowest_val;
    int max_val = ((((1<<30)-1)*2)+1);

    while (true){
        int* lowest_val = array.data();  // .data() gives pointer to start of vector. Can offset as stored in continuous memory
        // cout << lowest_val << endl;  // this has a pointer (reference) saved to it. & would give pointer to this pointer variable
        // cout << *lowest_val << endl;  // * gives the value the pointer points to

        for (auto it = array.begin(); it != array.end(); ++it){  // Using auto automatically detects the data type used in the template and lets you use it
            if (*lowest_val > *it){
                lowest_val = &(*it);
            }
        }

        if (*lowest_val == max_val){break;}  // break condition, all done

        new_array.push_back(*lowest_val);
        *lowest_val = max_val;

    }

    // cout the vector
    for (auto it = new_array.begin(); it != new_array.end(); ++it){
        cout << *it << ", ";
    }
    return new_array;
}

// Probably a linked list would be more efficient then could drop the element and not check over it when its donee
// But eh stop thinking about efficiency and just implement the inefficient sorts