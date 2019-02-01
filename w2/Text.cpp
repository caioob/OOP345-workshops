#include <iostream>
#include <fstream>
#include "Text.h"

namespace sict{
	Text::Text(){
		textLines = nullptr;
		noOfLines = 0;
	}

	Text::Text(const char* nameFile){
		noOfLines  = 0;
		textLines = nullptr;
		const char* a;
		std::fstream file(nameFile);
		while(!file.eof()){  //I got the logic for this loop in this website https://www.sanfoundry.com/cpp-program-count-lines-in-file/
			std::getline(file, a);
			noOfLines++;
		}

	}
}
