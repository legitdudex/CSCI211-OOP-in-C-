/*
 * Kang-hee Cho
 * CS211- Waxman 1:40-3:30
 * Due Date: 11/15/17
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;
int main(){
	int numberRings; //initialize the variable to store the user input for the number of rings
	cout << "Enter the number of rings: \n"; //prompt for user input
	cin >> numberRings;
	
	vector <int> towers[3]; //initialize the three vectors that are going to represent the towers
	for(int i = (numberRings + 1); i > 0; i--){
		towers[0].push_back(i); //add the rings to the first tower
	}
	towers[1].push_back(numberRings + 1); //push a ring with the value of numberRings + 1 to the second tower
	towers[2].push_back(numberRings + 1); //push a ring with the value of numberRings + 1 to the third tower
	// now all our vectors are initialized. Time to start our alogithm.
	int from, to;
	from = 0; //initially need to take a ring off tower 0
	if((numberRings % 2) == 1){ //if the total number of rings is odd
		to = 1; //set the to variable initally to tower 1
	}
	else{ //if the total number of rings is even
		to = 2; //set the to variable initially to tower 2
	}
	
	int move = 1, candidate = towers[0].back();
	while( towers[1].size() < (numberRings + 1) ){ //program is done when we have successfully moved all the rings to the second tower
		cout << "Move #" << move << ": Transfer ring " << candidate << " from tower " << from << " to tower " << to << "\n";
		candidate = towers[from].back(); //save the candidate ring
		towers[to].push_back(candidate); //push the candidate ring onto the tower it is going to
		towers[from].pop_back(); //pop the top of the stack where we just moved the ring from
		
		//now we need to update the next tower we are going to move the ring from
		int comparingtoRing1 = (to + 1) % 3; //the tower to the right of the tower we just moved a ring to
		int comparingtoRing2 = (to + 2) % 3; //the tower to the left of the tower we just moved a ring to
		if(towers[comparingtoRing1].back() < towers[comparingtoRing2].back()){ //find the tower with the smaller ring on the top of the stack
			from = (to + 1) % 3; //the next ring we are going to move resides in the tower to the right of the tower we just moved a ring to 
		} 
		else{ //if the next smallest ring resides in the tower to the left of the tower we just moved a ring to
			from = (to + 2) % 3; //the next ring we are going to move resides in the tower to the left of the tower we just moved a ring to
		}
		
		//now we need to update the next tower we are going to move the ring to
		if((numberRings % 2) == 1){ //if the number of total rings is odd
			int comparingRing = (from + 1) % 3; //we compare with the tower to the right of the tower we just moved a ring from
			if(towers[from].back() < towers[comparingRing].back()){ //if the ring on top of the tower we just moved a ring from is smaller than the comparing ring
				to = (from + 1) % 3; //the next tower we are going to move to cannot be the comparing tower. Hence, 
			}
			else{
				to = (from + 2) % 3; //if the ring on top of the tower we just moved a ring from is bigger than the comparing ring, we can indeed move the next ring to that tower
			}
		}
		else{ //if the number of total rings is even
			int comparingRing = (from + 2) % 3; //we compare with the tower to the left of the tower we just moved a ring from
			if(towers[from].back() < towers[comparingRing].back()){ //if the ring on top of the tower we just moved a ring from is smaller than the comparing ring
				to = (from + 2) % 3; //the next tower we are going to move a ring to is where the comparing tower resides
			}
			else{ //if the ring on top of the tower we just moved a ring from is larger than the comparing ring
				to = (from + 1) % 3; //the next tower we are going to move a ring to is where the comparing tower or the from tower does not reside
			}
		}

		candidate = towers[from].back(); //we must now update our candidate ring
		move++; //increment the number of moves

	}
	return 0;
}
