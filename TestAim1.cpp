#include <vector>
#include <iostream>
#include <fstream>

#include "SeparateChaining.h"
#include "QuadraticProbing.h"
#include "LinearProbing.h"
int main(){


	std::ifstream file;
	file.open("OHenry.txt");

	std::vector<std::string> DataArray;

	//file processing
	if(file.is_open()){
		std::string line;

		while(getline(file,line, '\n')){
			DataArray.push_back(line);
		}
	}
	file.close();

		file.open("queries.txt");

	std::vector<std::string> QueryArray;

	//file processing
	if(file.is_open()){
		std::string line;

		while(getline(file,line, '\n')){
			QueryArray.push_back(line);
		}
	}
	file.close();

	std::cout << QueryArray[0];

	HashTable<std::string> ChainingHT;

	LinearHashTable<std::string> LinearProbingHT;
	QuadraticHashTable<std::string> QuadraticProbingHT;

	return 0;
}


void InsertIntoChainingHT(){

	for(int i = 0; i< DataArray.size();i++){
		LinearProbingHT.insert(DataArray[i]);
	}


}