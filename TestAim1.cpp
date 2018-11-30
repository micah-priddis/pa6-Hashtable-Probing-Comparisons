#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>

#include "SeparateChaining.h"
#include "QuadraticProbing.h"
#include "LinearProbing.h"


// Prints total time to search for each query in list.
void SearchChainingHT(std::vector<std::string> query, HashTable<std::string> HT) {
    int TimeAverage = 0;
    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < query.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            HT.contains(query[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeAverage += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    std::cout << "SearchChainingHT: " << TimeAverage << std::endl;

}

// Reports time to insert entire vector into HT
HashTable<std::string> InsertIntoChainingHT(std::vector<std::string> data){
    HashTable<std::string> InsertTimerChainingHT;
    int TimeAverage = 0;

    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < data.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            InsertTimerChainingHT.insert(data[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeAverage += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    //std::cout << InsertTimerChainingHT.getCollisions() << std::endl;
    std::cout << "InsertIntoChainingHT: " << TimeAverage << std::endl;

    return InsertTimerChainingHT;
}

// Prints total time to search for each query in list.
void SearchLinearHT(std::vector<std::string> query, LinearHashTable<std::string> HT) {
    int TimeAverage = 0;
    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < query.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            HT.contains(query[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeAverage += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    std::cout << "SearchLinearHT: " << TimeAverage << std::endl;
}

// Reports time to insert entire vector into HT
LinearHashTable<std::string> InsertIntoLinearHT(std::vector<std::string> data){
    LinearHashTable<std::string> InsertTimerLinearHT;
    int TimeAverage = 0;

    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < data.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            InsertTimerLinearHT.insert(data[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeAverage += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    std::cout << "Linear Collisions: " << InsertTimerLinearHT.getCollisions() << std::endl;
    std::cout << "InsertIntoLinearHT: " << TimeAverage << std::endl;

    return InsertTimerLinearHT;
}


// Prints total time to search for each query in list.
void SearchQuadraticHT(std::vector<std::string> query, QuadraticHashTable<std::string> HT) {
    int TimeAverage = 0;
    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < query.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            HT.contains(query[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeAverage += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    std::cout << "SearchQuadraticHT: " << TimeAverage << std::endl;
}

// Reports time to insert entire vector into HT
QuadraticHashTable<std::string> InsertIntoQuadraticHT(std::vector<std::string> data){
    QuadraticHashTable<std::string> InsertTimerQuadraticHT;
    int TimeAverage = 0;

    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < data.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            InsertTimerQuadraticHT.insert(data[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeAverage += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    std::cout << "Quadratic Collisions: " << InsertTimerQuadraticHT.getCollisions() << std::endl;
    std::cout << "InsertIntoQuadraticHT: " << TimeAverage << std::endl;

    return InsertTimerQuadraticHT;
}
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

	HashTable<std::string> ChainingHT;
    LinearHashTable<std::string> LinearProbingHT;
	QuadraticHashTable<std::string> QuadraticProbingHT;

    SearchChainingHT(QueryArray, InsertIntoChainingHT(DataArray)); // Separate Chaining
    std::cout << "===============================" << std::endl;
    SearchLinearHT(QueryArray, InsertIntoLinearHT(DataArray)); // Linear Probing
    std::cout << "===============================" << std::endl;
    SearchQuadraticHT(QueryArray, InsertIntoQuadraticHT(DataArray)); // Quadratic Probing

	return 0;
}
