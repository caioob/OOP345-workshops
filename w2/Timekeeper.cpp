#include <iostream>
#include <chrono>
#include <cstring>
#include "Timekeeper.h"

namespace sict{
    Timekeeper::Timekeeper(){
        noOfRecord = 0;
    }

    void Timekeeper::start(){
		startWatch  = std::chrono::steady_clock::now();
    }

        void Timekeeper::stop(){
		startWatch  = std::chrono::steady_clock::now();
    }

    void Timekeeper::recordEvent(char* description){
		if (noOfRecord < MAX_RECS){
			strcpy(rec[noOfRecord].eventDescription, description);
			rec[noOfRecord].durationWatch = std::chrono::duration_cast<std::chrono::milliseconds>(stopWatch - startWatch);
			strcpy(rec[noOfRecord].unit, "seconds");
			noOfRecord++;
		}
    }

    void Timekeeper::report(std::ostream& ostr){
		ostr << "Execution Times: "  << std::endl;
		int temp[noOfRecord];
		for (int i = 0;  i < noOfRecord; i++){
			temp[i] = std::chrono::duration::duration_cast<std::chrono::milliseconds>(rec[i].durationWatch)  ;
			ostr << rec[i].eventDescription << " " << temp[i]  << " " << rec[i].unit << std::endl;
		}
    }
}
