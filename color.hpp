void defaultClr(unsigned char code = 19) {
	switch (code) {
	case 0:
		data::colors[0][0] = sf::Color::White;//screen
		data::colors[0][1] = sf::Color::Black;
		data::colors[0][2] = sf::Color(255, 255, 255, 128);
		data::colors[0][3] = sf::Color::Transparent;
		data::shadowing[0][0] = true;
		data::shadowing[0][1] = false;
		break;
	case 1:
		data::colors[1][0] = sf::Color::Black;//border
		data::colors[1][1] = sf::Color::Blue;
		data::colors[1][2] = sf::Color(0, 0, 0, 64);
		data::colors[1][3] = sf::Color::Transparent;
		data::shadowing[1][0] = true;
		data::shadowing[1][1] = false;
		break;
	case 2:
		data::colors[2][0] = sf::Color::Cyan;//title
		data::colors[2][1] = sf::Color::Blue;
		data::colors[2][2] = sf::Color(0, 144, 240, 192);
		data::colors[2][3] = sf::Color::Transparent;
		data::shadowing[2][0] = true;
		data::shadowing[2][1] = false;
		break;
	case 3:
		data::colors[3][0] = sf::Color::White;//unsel
		data::colors[3][1] = sf::Color::Black;
		data::colors[3][2] = sf::Color(255, 255, 255, 144);
		data::colors[3][3] = sf::Color::Transparent;
		data::shadowing[3][0] = true;
		data::shadowing[3][1] = false;
		break;
	case 4:
		data::colors[4][0] = sf::Color::White;//hotkey
		data::colors[4][1] = sf::Color::Blue;
		data::colors[4][2] = sf::Color::Black;
		data::colors[4][3] = sf::Color::Transparent;
		data::shadowing[4][0] = true;
		data::shadowing[4][1] = false;
		break;
	case 5:
		data::colors[5][0] = sf::Color::White;//sel
		data::colors[5][1] = sf::Color::Black;
		data::colors[5][2] = sf::Color(0, 0, 0, 224);
		data::colors[5][3] = sf::Color(255, 128, 0, 32);
		data::shadowing[5][0] = true;
		data::shadowing[5][1] = true;
		break;
	case 6:
		data::colors[6][0] = sf::Color::White;//hotsel
		data::colors[6][1] = sf::Color::Black;
		data::colors[6][2] = sf::Color(64, 0, 0, 224);
		data::colors[6][3] = sf::Color(255, 128, 0, 32);
		data::shadowing[6][0] = true;
		data::shadowing[6][1] = true;
		break;
	case 7:
		data::colors[7][0] = sf::Color::Black;//disabled
		data::colors[7][1] = sf::Color::Blue;
		data::colors[7][2] = sf::Color(204, 204, 204, 96);
		data::colors[7][3] = sf::Color::Transparent;
		data::shadowing[7][0] = true;
		data::shadowing[7][1] = false;
		break;
	case 8:
		data::colors[8][0] = sf::Color::Black;//scrollbar
		data::colors[8][1] = sf::Color::Blue;
		data::colors[8][2] = sf::Color(0, 0, 0, 64);
		data::colors[8][3] = sf::Color::Transparent;
		data::shadowing[8][0] = true;
		data::shadowing[8][1] = false;
		break;
	case 9:
		data::colors[9][0] = sf::Color::Red;//tabmsg
		data::colors[9][1] = sf::Color::Black;
		data::colors[9][2] = sf::Color(255, 255, 0, 144);
		data::colors[9][3] = sf::Color::Transparent;
		data::shadowing[9][0] = true;
		data::shadowing[9][1] = false;
		break;
	case 10:
		data::colors[10][0] = sf::Color::Cyan;//cmdmark
		data::colors[10][1] = sf::Color::Black;
		data::colors[10][2] = sf::Color(0, 255, 255, 64);
		data::colors[10][3] = sf::Color::Transparent;
		data::shadowing[10][0] = true;
		data::shadowing[10][1] = false;
		break;
	case 11:
		data::colors[11][0] = sf::Color::White;//cmdline
		data::colors[11][1] = sf::Color::Black;
		data::colors[11][2] = sf::Color(255, 255, 255, 64);
		data::colors[11][3] = sf::Color::Transparent;
		data::shadowing[11][0] = true;
		data::shadowing[11][1] = false;
		break;
	case 12:
		data::colors[12][0] = sf::Color::Black;//pwdborder
		data::colors[12][1] = sf::Color::White;
		data::colors[12][2] = sf::Color(255, 255, 255, 128);
		data::colors[12][3] = sf::Color(255, 255, 255, 32);
		data::shadowing[12][0] = true;
		data::shadowing[12][1] = false;
		break;
	case 13:
		data::colors[13][0] = sf::Color::Red;//pwdheader
		data::colors[13][1] = sf::Color::White;
		data::colors[13][2] = sf::Color(255, 128, 128, 128);
		data::colors[13][3] = sf::Color(255, 255, 255, 32);
		data::shadowing[13][0] = true;
		data::shadowing[13][1] = false;
		break;
	case 14:
		data::colors[14][0] = sf::Color::Black;//pwdentry
		data::colors[14][1] = sf::Color::White;
		data::colors[14][2] = sf::Color(255, 255, 255, 128);
		data::colors[14][3] = sf::Color(255, 255, 255, 32);
		data::shadowing[14][0] = true;
		data::shadowing[14][1] = false;
		break;
	case 15:
		data::colors[15][0] = sf::Color::White;//timeout_msg
		data::colors[15][1] = sf::Color::Black;
		data::colors[15][2] = sf::Color(255, 255, 255, 128);
		data::colors[15][3] = sf::Color::Transparent;
		data::shadowing[15][0] = true;
		data::shadowing[15][1] = false;
		break;
	case 16:
		data::colors[16][0] = sf::Color::White;//timeout
		data::colors[16][1] = sf::Color::Black;
		data::colors[16][2] = sf::Color(255, 255, 255, 192);
		data::colors[16][3] = sf::Color::Transparent;
		data::shadowing[16][0] = true;
		data::shadowing[16][1] = false;
		break;
	case 17:
		data::colors[17][0] = sf::Color::White;//help
		data::colors[17][1] = sf::Color::Black;
		data::colors[17][2] = sf::Color(255, 255, 255, 192);
		data::colors[17][3] = sf::Color::Transparent;
		data::shadowing[17][0] = true;
		data::shadowing[17][1] = false;
		break;
	case 18:
		data::colors[18][0] = sf::Color::White;//msg07
		data::colors[18][1] = sf::Color::Black;
		data::colors[18][2] = sf::Color(255, 255, 255, 144);
		data::colors[18][3] = sf::Color::Transparent;
		data::shadowing[18][0] = true;
		data::shadowing[18][1] = false;
		break;
	case 19:
	default:
		for (unsigned char clrCode = 0; clrCode < 18; clrCode++)
			defaultClr(clrCode);
		break;
	}
}

void menuColor(std::string object, std::string ansiSec, std::string foregroundARGB, std::string backgroundARGB, std::string shadowing = "*") {
	unsigned char objCode;
	if (object == "screen")
		objCode = 0;
	else if (object == "border")
		objCode = 1;
	else if (object == "title")
		objCode = 2;
	else if (object == "unsel")
		objCode = 3;
	else if (object == "hotkey")
		objCode = 4;
	else if (object == "sel")
		objCode = 5;
	else if (object == "hotsel")
		objCode = 6;
	else if (object == "disabled")
		objCode = 7;
	else if (object == "scrollbar")
		objCode = 8;
	else if (object == "tabmsg")
		objCode = 9;
	else if (object == "cmdmark")
		objCode = 10;
	else if (object == "cmdline")
		objCode = 11;
	else if (object == "pwdborder")
		objCode = 12;
	else if (object == "pwdheader")
		objCode = 13;
	else if (object == "pwdentry")
		objCode = 14;
	else if (object == "timeout_msg")
		objCode = 15;
	else if (object == "timeout")
		objCode = 16;
	else if (object == "help")
		objCode = 17;
	else if (object == "msg07")
		objCode = 18;
	else
		objCode = 19;

	if (objCode != 19) {
		std::stringstream ansiSecStr;
		unsigned char code;
		for (unsigned long long n = 0; n < ansiSec.size(); n++) {
			if (ansiSec[n] == ';') {
				ansiSecStr >> code;
				ansiSecStr.str(std::string());
				switch (code) {
				case 0:
				case 38:
				case 39:
				case 49:
					defaultClr(objCode);
					break;
				case 30:
					data::colors[objCode][0] = sf::Color::Black;
					break;
				case 31:
					data::colors[objCode][0] = sf::Color::Red;
					break;
				case 32:
					data::colors[objCode][0] = sf::Color::Green;
					break;
				case 33:
					data::colors[objCode][0] = sf::Color(64, 32, 0, 255);
					break;
				case 34:
					data::colors[objCode][0] = sf::Color::Blue;
					break;
				case 35:
					data::colors[objCode][0] = sf::Color::Magenta;
					break;
				case 36:
					data::colors[objCode][0] = sf::Color::Cyan;
					break;
				case 37:
					data::colors[objCode][0] = sf::Color::White;
					break;
				case 40:
					data::colors[objCode][1] = sf::Color::Black;
					break;
				case 41:
					data::colors[objCode][1] = sf::Color::Red;
					break;
				case 42:
					data::colors[objCode][1] = sf::Color::Green;
					break;
				case 43:
					data::colors[objCode][1] = sf::Color(64, 32, 0, 255);
					break;
				case 44:
					data::colors[objCode][1] = sf::Color::Blue;
					break;
				case 45:
					data::colors[objCode][1] = sf::Color::Magenta;
					break;
				case 46:
					data::colors[objCode][1] = sf::Color::Cyan;
					break;
				case 47:
					data::colors[objCode][1] = sf::Color::White;
					break;
				}
			}
			else
				ansiSecStr << ansiSec[n];
		}
		std::stringstream hexStream;
		unsigned char af;
		unsigned char rf;
		unsigned char gf;
		unsigned char bf;
		unsigned char ab;
		unsigned char rb;
		unsigned char gb;
		unsigned char bb;
		hexStream << foregroundARGB[1];
		hexStream << foregroundARGB[2];
		af = (unsigned char)hexToDec(hexStream.str());
		hexStream.str(std::string());
		hexStream << foregroundARGB[3];
		hexStream << foregroundARGB[4];
		rf = (unsigned char)hexToDec(hexStream.str());
		hexStream.str(std::string());
		hexStream << foregroundARGB[5];
		hexStream << foregroundARGB[6];
		gf = (unsigned char)hexToDec(hexStream.str());
		hexStream.str(std::string());
		hexStream << foregroundARGB[7];
		hexStream << foregroundARGB[8];
		bf = (unsigned char)hexToDec(hexStream.str());
		hexStream.str(std::string());
		hexStream << backgroundARGB[1];
		hexStream << backgroundARGB[2];
		ab = (unsigned char)hexToDec(hexStream.str());
		hexStream.str(std::string());
		hexStream << backgroundARGB[3];
		hexStream << backgroundARGB[4];
		rb = (unsigned char)hexToDec(hexStream.str());
		hexStream.str(std::string());
		hexStream << backgroundARGB[5];
		hexStream << backgroundARGB[6];
		gb = (unsigned char)hexToDec(hexStream.str());
		hexStream.str(std::string());
		hexStream << backgroundARGB[7];
		hexStream << backgroundARGB[8];
		bb = (unsigned char)hexToDec(hexStream.str());
		hexStream.str(std::string());
		//std::cout << object << '(' << (int)objCode << ')' << "[FG]:" << "R:" << (int)rf << ';' << "G:" << (int)gf << ';' << "B:" << (int)bf << ';' << "A:" << (int)af << ';' << std::endl << object << '(' << (int)objCode << ')' << "[BG]:" << "R:" << (int)rb << ';' << "G:" << (int)gb << ';' << "B:" << (int)bb << ';' << "A:" << (int)ab << ';' << std::endl << "Raw:" << foregroundARGB << "[FG]" << ' ' << backgroundARGB << "[BG]" << std::endl;
		data::colors[objCode][2] = sf::Color(rf, gf, bf, af);
		data::colors[objCode][3] = sf::Color(rb, gb, bb, ab);

		if (shadowing == "none") {
			data::shadowing[objCode][0] = false;
			data::shadowing[objCode][1] = false;
		}
		else if (shadowing == "all") {
			data::shadowing[objCode][0] = true;
			data::shadowing[objCode][1] = true;
		}
		else if ((shadowing == "std") | (shadowing == "standard")) {
			data::shadowing[objCode][0] = true;
			data::shadowing[objCode][1] = false;
		}
		else if ((shadowing == "rev") | (shadowing == "reverse")) {
			data::shadowing[objCode][0] = false;
			data::shadowing[objCode][1] = true;
		}
		else if (shadowing != "*")
			msg("Unknown shadowing mode \"" + shadowing + "\". No changes made to shadowing", 2);
	}
}