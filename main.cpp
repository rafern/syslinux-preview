#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <math.h>
#include <locale>
#include <codecvt>
#include <png++/png.hpp>
#include <SFML/Graphics.hpp>
#include "resources.hpp"
#include "winFuncs.h"
#include "ansi850.hpp"
#include "transform.hpp"
#include "color.hpp"
#include "keyfuncs.hpp"
#include "command.hpp"
#include "renderSP.hpp"

int main(int argc, char* argv[]) {
	std::vector < std::string > arguments;
	if (argc == 1)
		msg("No file has been specified!", 2);
	else {
		for (unsigned int n = 1; n < (unsigned int)(argc); n++) { //Pre-parse
			if (argv[n][0] == '-')
				if (argv[n][1] != '\0') {
					if (argv[n][1] == 'W')
						winFuncs::enableWarnings = false;
					else if (argv[n][1] == 'F')
						data::showFPS = true;
				}
				else
					arguments.push_back(argv[n]);
			else
				arguments.push_back(argv[n]);
		} //End of Pre-parse

		if(arguments.size() == 0)
			msg("No file has been specified!", 2);
		else {
			if (arguments.size() > 1)
				msg("Multiple files selected, all configurations will be joined. Order of load:", 0);
			for (unsigned int n = 0; n < (unsigned int)(arguments.size()); n++) { //Parse
				if (arguments.size() > 1)
					std::cout << arguments[n] << std::endl;
				read(arguments[n]);
				genComs(n);
			} //End of Parse
			if ((hasChar(arguments[0], '\\') == true) | (hasChar(arguments[0], '/') == true))
				data::workingDir = removeLast(replaceChar(arguments[0], '\\', '/'), '/');
			if (arguments.size() > 1) {
				if (data::workingDir == "")
					msg("Later UI commands will replace older UI commands and the first file's directory will set the working directory.\nWorking directory is console's working directory", 0);
				else
					msg("Later UI commands will replace older UI commands and the first file's directory will set the working directory.\nWorking directory:\"" + data::workingDir + '\"', 0);
			}
			prep();
			optimise();
			renderSP();
		}
	}
	return 0;
}