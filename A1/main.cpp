/* CSCI 200: Assignment 1: A1 - Random Encounter RPG
 *
 * Author: XXXX (Alexander Antone)
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
  char movement = 'y';
  random_device rd;
  mt19937 mt( rd() );

  uniform_int_distribution<int> dist(1, 6);
  uniform_int_distribution<int> dist1(1, 8);

  while (movement != 'n'){

    
    int d6Value = dist(mt);
    
    if (d6Value ==3 or d6Value ==6) {
      cout <<"You slip through the room." <<endl;
    }
    else {
      cout <<"There's an enemy in the room!" <<endl;
      int d8Value = dist1(mt);
      if (d8Value %3 ==0){
        cout <<"You encounter an orc." <<endl;
      }
        else {if (d8Value %3 ==1){
          cout <<"You encounter a goblin." <<endl;
        }

          else {if (d8Value %3 ==2){
            cout <<"You encounter a dragon." <<endl;
          }}

        }
    }
    cout <<" Do you wish to move to the next room? (y/n) ";
    cin >> movement;
    movement = (char)tolower(movement);

  }
  cout << 'You finished.';

  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}