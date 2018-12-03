#include "SimpleHash.h"
#include "PrefixHash.h"
#include "FullLengthHash.h"
#include <iostream>

#include <fstream>

SimpleHash<std::string> InsertIntoSimpleHash(std::vector<std::string> & data){

	std::cout << "---SimpleHash Insert---" << std::endl;

    SimpleHash<std::string> InsertTimerSimpleHashHT;
    int TimeTotal = 0;

    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < data.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            InsertTimerSimpleHashHT.insert(data[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::cout << "Collisions: " << InsertTimerSimpleHashHT.getCollisions() << std::endl;
    std::cout << "Total Time: " << TimeTotal << "ns" << std::endl;
    std::cout << "Average Time: "  << TimeTotal / data.size() << "ns\n\n" <<std::endl;

    return InsertTimerSimpleHashHT;
}

void SearchSimpleHash(std::vector<string> & query, SimpleHash<std::string> HT){
    int TimeTotal = 0;

    std::cout << "---SimpleHash Search---" << std::endl;
    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < query.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            HT.contains(query[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::cout << "Total Time: " << TimeTotal << "ns" << std::endl;
    std::cout << "Average Time: " << TimeTotal / query.size() << "ns\n\n" << std::endl;
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


	SimpleHash<std::string> ht = InsertIntoSimpleHash(DataArray);
	SearchSimpleHash(QueryArray, ht);
}
