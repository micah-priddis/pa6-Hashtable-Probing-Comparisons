#include <vector>
#include <iostream>
#include <fstream>

#include "SeparateChaining.cpp"
#include "QuadraticChaining.cpp"
#include ""
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

	HashTable ChainingHT;
	HashTable LinearProbignHT;
	HashTable QuadraticProbingHT;

	return 0;
}