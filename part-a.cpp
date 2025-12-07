#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept> // Added for std::runtime_error
using namespace std;

// Time Complexity Analysis: O(n)
/*******************************************************************************
 * Function implementation (Helper Function)
*******************************************************************************/
template <typename T>
T findMaxRecTailHelper(const T arr[], const int SIZE, int i, T currentMax) {
    // Base Case: If the head pointer (i) has passed the array end, return the accumulated maximum.
    if (i >= SIZE) {
        return currentMax;
    }
    
    // Recursive Step: Compare the current element with the current maximum.
    T nextMax = (arr[i] > currentMax) ? arr[i] : currentMax;

    // Recurse on the rest of the array with the new maximum.
    return findMaxRecTailHelper(arr, SIZE, i + 1, nextMax);
}


/*******************************************************************************
 * Function implementation (Public Wrapper)
*******************************************************************************/
// FIX: Added default parameter i = 0 to match main() calls.
template <typename T>
T findMaxRecTail(const T arr[], const int SIZE, int i = 0) { 
    // Edge Case: Empty array
    if (SIZE <= 0) {
        throw std::runtime_error("Array size must be greater than 0.");
    }
    
    // Start recursion by using the first element as the initial maximum.
    return findMaxRecTailHelper(arr, SIZE, i, arr[i]);
}


int main() {
    // create the array
    const int SIZE = 10;
    int myArray[SIZE] = {
        5, 23, 0, -2, 4,
        9, 11, 21, 130, 6
    };

    // display the maximum
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: "
         << findMaxRecTail(myArray, SIZE) << endl // Calls fixed function with i=0 default
         << "Should be 130 for the fixed array\n";
    cout << setfill('-') << setw(40) << "" << endl << endl;

    // create a random array
    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int randArray[SIZE_2];
    // Note: srand(time(0)) should be placed here if you want new random numbers each run
    srand(time(0)); 
    for (int& elem : randArray) {
        elem = rand() % MAX_VAL;
    }

    // find the maximum using C++ standard's algorithm
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: "
         << *max_element(randArray, randArray + SIZE_2) << endl;

    // find the maximum using the recursive implementation
    cout << "Maximum using Recursion: "
         << findMaxRecTail(randArray, SIZE_2) << endl; // Calls fixed function with i=0 default
    cout << setfill('-') << setw(40) << "" << endl;

    // terminate
    return 0;
}