#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/

void towerHanoi(int, string, string, string, int&);

/*******************************************************************************
 * Time Complexity Analysis: O(2^n)
 * * Description:
 * Implements the recursive solution to the Tower of Hanoi problem.
 * * Input:
 * numDisks - number of disks to move
 * source - name of the source rod
 * buffer - name of the buffer rod
 * target - name of the target rod
 * numMoves - reference to count total moves
*******************************************************************************/

void towerHanoi(int numDisks, string source, string buffer, string target, int& numMoves) {
    // Base Case: If there are no disks left to move, return.
    if (numDisks <= 0) {
        return;
    }

    // Step 1: Move n-1 disks from Source to Buffer, using Target as auxiliary.
    // The largest disk (numDisks) remains stationary on the source rod.
    towerHanoi(numDisks - 1, source, target, buffer, numMoves);

    // Step 2: Move the largest disk (n) from Source to Target.
    cout << "Moving disc " << numDisks << " from " << source << " to " << target << endl;
    numMoves++;

    // Step 3: Move the n-1 disks from Buffer to Target, using Source as auxiliary.
    towerHanoi(numDisks - 1, buffer, source, target, numMoves);
}

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
 * * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}