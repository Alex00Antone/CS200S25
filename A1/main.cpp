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
  char fightRun = 'f';
  int enemiesKilled = 0;
  int goldCollected = 0;
  int roomGold = 0;

  random_device rd;
  mt19937 mt( rd() );
  
  uniform_int_distribution<int> dist(1, 6);
  uniform_int_distribution<int> dist1(1, 8);
  uniform_int_distribution<int> dist2(1, 12);
  uniform_int_distribution<int> dist3(1, 20);

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
        cout <<"Roll a D8 greater than 1 to win." <<endl;
        cout << "Roll a D8 less than 8 to escape." <<endl;
        cout << "Do you wish to (f)ight or (r)un? ";
        cin >> fightRun;
        fightRun = (char)tolower(fightRun);
        d8Value = dist1(mt);
        cout <<"your D8 rolls a " <<d8Value <<endl;
        if (fightRun == 'f'){
          if (d8Value == 8){
            cout <<"The Orc slays you with your sword. Game over." <<endl;
            movement = 'n';
            break;
          }
          else  {
            cout <<"You killed the orc!" <<endl;
            ++enemiesKilled;
            d8Value = dist1(mt);
            roomGold += d8Value;
            d8Value = dist1(mt);
            roomGold += d8Value;
            cout <<"You take "<<roomGold <<" gold coins from the orc's treasure chest." <<endl;
            goldCollected += roomGold;
            roomGold = 0;

          }
        }
        else {
          if (d8Value == 8){
            cout <<"The orc hits you in the back with an arrow. Game Over." <<endl;
            movement = 'n';
            break;
          }
          else  {
            cout << "you sneak past the orc unaware."<<endl;
          }
        }
      }
        else {if (d8Value %3 ==1){
          cout <<"You encounter a goblin." <<endl;
          cout <<"Roll a D12 greater than 3 to win." <<endl;
          cout << "Roll a D12 less than 10 to escape." <<endl;
          cout << "Do you wish to (f)ight or (r)un? ";
          cin >> fightRun;
          fightRun = (char)tolower(fightRun);
          int d12Value = dist2(mt);
          cout <<"your D12 rolls a " <<d12Value <<endl;

          if (fightRun == 'f'){
            if (d12Value == 1 or d12Value == 2 or d12Value ==3){
              cout <<"The Goblin slays you with your sword. Game over." <<endl;
              movement = 'n';
              break;
            }
            else  {
              cout <<"You killed the goblin!" <<endl;
              ++enemiesKilled;
              d12Value = dist2(mt);
              roomGold += d12Value;
              d12Value = dist2(mt);
              roomGold += d12Value;
              cout <<"You take "<<roomGold <<" gold coins from the goblin's purse." <<endl;
              goldCollected += roomGold;
              roomGold = 0;
            }
          }
          else {
            if (d12Value == 10 or d12Value == 11 or d12Value ==12){
              cout <<"You fall into a trap dug by the goblin. Game Over." <<endl;
              movement = 'n';
              break;
            }
            else  {
              cout << "You slip from the goblin's sight."<<endl;
            }
        }
        }

          else {if (d8Value %3 ==2){
            cout <<"You encounter a dragon." <<endl;
            cout <<"Roll a D20 greater than 16 to win." <<endl;
            cout << "Roll a D20 less than 17 to escape." <<endl;
            cout << "Do you wish to (f)ight or (r)un? ";
            cin >> fightRun;
            fightRun = (char)tolower(fightRun);
            int d20Value = dist3(mt);
            cout <<"your D20 rolls a " <<d20Value <<endl;
            if (fightRun == 'f'){
              if (d20Value == 17 or d20Value == 18 or d20Value ==19 or d20Value ==20){
                cout <<"You slayed the dragon!" <<endl;
                ++enemiesKilled;
                d20Value = dist3(mt);
                goldCollected += d20Value;
                d20Value = dist3(mt);
                goldCollected += d20Value;
                cout <<"You take "<<roomGold <<" gold coins from the dragon's treasure hoard." <<endl;
                goldCollected += roomGold;
                roomGold = 0;
              }
              else  {
                cout <<"The dragon gobbled you up. Game Over." <<endl;
                movement = 'n';
                break;
              }
            }
            else {
              if (d20Value == 17 or d20Value == 18 or d20Value ==19 or d20Value ==20){
                cout <<"The dragon's flame burns you to a crisp. Game Over." <<endl;
                movement = 'n';
                break;
              }
              else  {
                cout <<"You escaped the dragon's lair." <<endl;
                
              }
          }
          }

        }
        }
    }
    if (goldCollected >= 100){
      movement = 'n';
    }
    cout <<" Do you wish to move to the next room? (y/n) ";
    cin >> movement;
    movement = (char)tolower(movement);

  }
  cout << "You finished with " << goldCollected <<" gold coins and killed " <<enemiesKilled << " enemies.";

  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}