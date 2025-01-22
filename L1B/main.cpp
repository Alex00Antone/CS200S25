/* CSCI 200: Assignment 1: Lab 1B - Random Classification
 *
 * Author: XXXX (INSERT_NAME)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <random>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/
  bool condition = true;
  while (condition) {
    random_device rd;
    mt19937 mt( rd() );

    int minValue;
    cout << "Enter the minimum value: ";
    cin >> minValue; 

    int maxValue;
    cout << "Enter the maximum value: " ;
    cin >> maxValue; 

    uniform_real_distribution<double> floatDist(minValue, maxValue);

    float randomValue = floatDist(mt);

    cout <<"A random value is ";
    cout <<randomValue <<endl;

    float quartileRange = (maxValue-minValue)/4;

    if (randomValue< (minValue+quartileRange)){
        cout <<" Your value is in the first quartile!" << endl;
    }
        else {if (randomValue< (minValue+(2*quartileRange))){
            cout <<" Your value is in the second quartile!" << endl;
        }
            else {if (randomValue< (minValue+(3*quartileRange))) {
                cout <<" Your value is in the third quartile!" << endl;
            }
                else {
                    cout <<" Your value is in the forth quartile!" << endl;
                }
            }
        }
    char yesNo;
    cout <<" Do you want another random value? (Y/N): ";
    cin >> yesNo;
    if (yesNo == 'N'){
        condition = false;
    } 
  }


  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}