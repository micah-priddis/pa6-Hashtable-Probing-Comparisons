#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>

#include "SeparateChaining.h"
#include "QuadraticProbing.h"
#include "LinearProbing.h"


// Prints total time to search for each query in list.
void SearchChainingHT(std::vector<std::string> query, HashTable<std::string> HT) {
    int TimeTotal = 0;
    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < query.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            HT.contains(query[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::cout << "==========CHAINING SEARCH==========" << std::endl;
    std::cout << "Chaining Total Search Time: " << TimeTotal << " ns" << std::endl;
    std::cout << "Chaining Average Search Time: " << TimeTotal / query.size() << " ns" << std::endl;
}

// Reports time to insert entire vector into HT
HashTable<std::string> InsertIntoChainingHT(std::vector<std::string> data){
    HashTable<std::string> InsertTimerChainingHT;
    int TimeTotal = 0;

    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < data.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            InsertTimerChainingHT.insert(data[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::cout << "==========CHAINING INSERT==========" << std::endl;
    std::cout << "Chaining Collisions: " << InsertTimerChainingHT.getCollisions() << " collisions" << std::endl;
    std::cout << "Chaining Total Insertion Time: " << TimeTotal << " ns" << std::endl;
    std::cout << "Chaining Average Insertion Time: " << TimeTotal / data.size() << " ns" << std::endl;

    return InsertTimerChainingHT;
}

// Prints total time to search for each query in list.
void SearchLinearHT(std::vector<std::string> query, LinearHashTable<std::string> HT) {
    int TimeTotal = 0;
    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < query.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            HT.contains(query[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::cout << "==========LINEAR SEARCH==========" << std::endl;
    std::cout << "Linear Total Search Time: " << TimeTotal <<  " ns" << std::endl;
    std::cout << "Linear Average Search Time: " << TimeTotal / query.size() << " ns" << std::endl;

}

// Reports time to insert entire vector into HT
LinearHashTable<std::string> InsertIntoLinearHT(std::vector<std::string> data){
    LinearHashTable<std::string> InsertTimerLinearHT;
    int TimeTotal = 0;

    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < data.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            InsertTimerLinearHT.insert(data[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::cout << "==========LINEAR INSERT==========" << std::endl;
    std::cout << "Linear Collisions: " << InsertTimerLinearHT.getCollisions() << " collisions" << std::endl;
    std::cout << "Linear Total Insertion Time: " << TimeTotal << " ns" << std::endl;
    std::cout << "Linear Average Insertion Time: " << TimeTotal / data.size() << " ns" << std::endl;

    return InsertTimerLinearHT;
}


// Prints total time to search for each query in list.
void SearchQuadraticHT(std::vector<std::string> query, QuadraticHashTable<std::string> HT) {
    int TimeTotal = 0;
    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < query.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            HT.contains(query[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::cout << "==========QUADRATIC SEARCH==========" << std::endl;
    std::cout << "Quadratic Total Search Time: " << TimeTotal << " ns" << std::endl;
    std::cout << "Quadratic Average Search Time: " << TimeTotal / query.size() << " ns" << std::endl;
}

// Reports time to insert entire vector into HT
QuadraticHashTable<std::string> InsertIntoQuadraticHT(std::vector<std::string> data){
    QuadraticHashTable<std::string> InsertTimerQuadraticHT;
    int TimeTotal = 0;

    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < data.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            InsertTimerQuadraticHT.insert(data[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::cout << "==========QUADRATIC INSERT==========" << std::endl;
    std::cout << "Quadratic Collisions: " << InsertTimerQuadraticHT.getCollisions() << " collisions" << std::endl;
    std::cout << "Quadratic Total Search Time: " << TimeTotal << " ns" << std::endl;
    std::cout << "Quadratic Average Search Time: " << TimeTotal / data.size() << " ns" << std::endl;

    return InsertTimerQuadraticHT;
}

int main(){

    // file processing for OHenry
    std::ifstream file;
    file.open("OHenry.txt");

    std::vector<std::string> DataArray; // vector used to hold OHenry data

	if(file.is_open()){
		std::string line;

		while(getline(file,line, '\n')){
			DataArray.push_back(line);
		}
	}
	file.close();


    // file processing for query
    file.open("queries.txt");

    std::vector<std::string> QueryArray; // vector used to hold search queries

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
    SearchLinearHT(QueryArray, InsertIntoLinearHT(DataArray)); // Linear Probing
    SearchQuadraticHT(QueryArray, InsertIntoQuadraticHT(DataArray)); // Quadratic Probing

	return 0;
}
