
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cmath>

void getInput(std::string raceOutcome){
	std::cout << ("Enter the outcome of the race: \n");
        std::cin >> raceOutcome;
	if(raceOutcome == "done"){
		exit(); //end the program if the user enters "done"
	}
}

void checkInputValidity(std::string raceOutcome, bool validOutcome){
	int index;
	char currentChar;
	validOutcome = true;
	for(index = 0; index < raceOutcome.length(); index++){
		if(raceOutcome[index] == " "){
			validOutcome = false;
		}
		else if(isdigit(raceOutcome[index])){
			validOutcome = false;
		}
		else{
			if(!isupper(raceOutcome[index])){
				validOutcome = false;
			}
		}
	}
}

void updateNames(std::string raceOutcome, char namesArray[]){
	int sampleSize =raceOutcome.length();
	int index, 
	

}

void updateNumPlayers(std::string raceOutcome, int numPlayersArray[]){

}

void updateScores(std::string raceOutcome, int scoreArray[]){

}




void scoreTheRace(std::string raceOutcome){
	

}

int main(){
	std::string raceOutcome;
	bool validOutcome; //to check for input validity (string needs to be all uppercase with no numbers or spaces
	while(validOutcome != true){ //loop until we get the correct input type
		validOutcome = true; //initialize to true
		getInput(raceOutcome); //get the outcome of the race (string inputted by the user)
		checkInputValidity(raceOutcome, validOutcome); //check for initial validity (before we verify that the teams have an equal number of players on each team
	}	
	//initialize the various arrays that will be used to score the race
	int sampleSize = raceOutcome.length();
	char namesArray[sampleSize];
	updateNames(raceOutcome, namesArray); //check how many teams there are and fill the names array with each unique team name
	

	

return 0;
}

