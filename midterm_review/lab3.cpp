
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>


using namespace std;

bool isValid(string results){
	int size = results.size();
	if(size <= 1){ //there has to be at least 2 teams. 
		return false;
	}
	for(int i = 0; i < results.size(); i++){ //checks if the racers are all alphabetic
		if(!(isalpha(results[i]))){
			return false;
		}
	}
	//Now we need to check if the teams have the same amount of members per team
	int n, teamCount, teamArrayIndex = 0;
	bool exists = false;
	char teamArray[size];
	for(int i = 0; i < size; i++){ //adding the distinct teams to the team array
		char racer = results[i];
		for(int j = 0; j < size; j++){
			if(racer == teamArray[j]);
			exists = true;
		}
		if(exists == false){
			teamArray[teamArrayIndex] = racer;
			teamArrayIndex++;
		}
		exists = false;
	}
	for(int i = 0; i < size; i++){
			cout << teamArray[i];
	}

	return true;
}

int main(){
	string raceResults;
	cout << "Enter the race results: ";
	cin >> raceResults;
	cout << "\n";
	isValid(raceResults);





}
