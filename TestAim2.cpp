#include "SimpleHash.h"
#include <iostream>

#include <fstream>

SimpleHash<std::string> InsertIntoSimpleHash(std::vector<std::string> & data){

    SimpleHash<std::string> InsertTimerSimpleHashHT;
    int TimeTotal = 0;

    std::chrono::steady_clock::time_point start, end;

    for(int i = 0; i < data.size();i++) {
            start = std::chrono::steady_clock::now(); // get time before insert
            InsertTimerSimpleHashHT.insert(data[i]);
            end = std::chrono::steady_clock::now(); // time after insert

            TimeTotal += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    std::cout << "SimpleHash Collisions: " << InsertTimerSimpleHashHT.getCollisions() << std::endl;
    std::cout << "InsertIntoSimpleHash: " << TimeTotal << std::endl;

    return InsertTimerSimpleHashHT;
}


int main(){

	SimpleHash<std::string> sh;

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


	InsertIntoSimpleHash(DataArray);
}
