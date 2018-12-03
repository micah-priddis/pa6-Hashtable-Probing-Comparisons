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


PrefixHash<std::string> InsertIntoPrefixHash(std::vector<std::string> & data){

    std::cout << "---PrefixHash Insert---" << std::endl;

    PrefixHash<std::string> InsertTimerPrefixHashHT;
    int TimeTotal = 0;

    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < data.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            InsertTimerPrefixHashHT.insert(data[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::cout << "Collisions: " << InsertTimerPrefixHashHT.getCollisions() << std::endl;
    std::cout << "Total Time: " << TimeTotal << "ns" << std::endl;
    std::cout << "Average Time: "  << TimeTotal / data.size() << "ns\n\n" <<std::endl;

    return InsertTimerPrefixHashHT;
}

void SearchPrefixHash(std::vector<string> & query, PrefixHash<std::string> HT){
    int TimeTotal = 0;

    std::cout << "---PrefixHash Search---" << std::endl;
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

FullLengthHash<std::string> InsertIntoFullLengthHash(std::vector<std::string> & data){

    std::cout << "---FullLengthHash Insert---" << std::endl;

    FullLengthHash<std::string> InsertTimerFullLengthHashHT;
    int TimeTotal = 0;

    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < data.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            InsertTimerFullLengthHashHT.insert(data[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::cout << "Collisions: " << InsertTimerFullLengthHashHT.getCollisions() << std::endl;
    std::cout << "Total Time: " << TimeTotal << "ns" << std::endl;
    std::cout << "Average Time: "  << TimeTotal / data.size() << "ns\n\n" <<std::endl;

    return InsertTimerFullLengthHashHT;
}

void SearchFullLengthHash(std::vector<string> & query, FullLengthHash<std::string> HT){
    int TimeTotal = 0;

    std::cout << "---FullLengthHash Search---" << std::endl;
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


	SimpleHash<std::string> SimpleHT = InsertIntoSimpleHash(DataArray);
	SearchSimpleHash(QueryArray, SimpleHT);

	PrefixHash<std::string> PrefixHT = InsertIntoPrefixHash(DataArray);
	SearchPrefixHash(QueryArray, PrefixHT);

	FullLengthHash<std::string> FullHT = InsertIntoFullLengthHash(DataArray);
	SearchFullLengthHash(QueryArray, FullHT);
}
