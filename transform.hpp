bool hasChar(std::string string, char character) {
	bool found = false;
	if (string.size() > 0) {
		for (unsigned int n = 0; (n < string.size() - 1) & (found == false); n++) {
			if (string[n] == character)
				found = true;
		}
	}
	return found;
}

std::string toLowercase(std::string initial) {
	std::string finalStr;
	for (unsigned int n = 0; n < initial.size(); n++) {
		finalStr += (char)tolower((int)initial[n]);
	}
	return finalStr;
}

std::string lastWord(std::string initial, char separatorChar) {
	std::string finalStr;
	for (unsigned int n = 0; n < initial.size(); n++) {
		if (initial[n] == separatorChar)
			finalStr.clear();
		else
			finalStr += initial[n];
	}
	return finalStr;
}

std::string removeLast(std::string initial, char separatorChar) {
	bool found = false;
	for (unsigned int n = (unsigned int)initial.size() - 1; (n > 0) & (found == false); n--) {
		if (initial[n] == separatorChar)
			found = true;
		else
			initial.erase(initial.end() - 1);
	}
	return initial;
}

std::string replaceChar(std::string initial, char toReplace, char replacer) {
	for (unsigned int n = 0; n < initial.size() - 1; n++) {
		if (initial[n] == toReplace) {
			initial[n] = replacer;
		}
	}
	return initial;
}

std::string replaceSubstring(std::string initial, std::string toReplace, std::string replacer) {
	if (toReplace.empty())
		return initial;
	size_t start_pos = 0;
	while ((start_pos = initial.find(toReplace, start_pos)) != std::string::npos) {
		initial.replace(start_pos, toReplace.length(), replacer);
		start_pos += replacer.length();
	}
	return initial;
}

std::string getSubstringFromChars(std::string initial, char fromChar, char toChar, bool getBorders = false) {
	std::string sub;
	bool foundFirst = false;
	bool done = false;
	for (unsigned int n = 0; (n < initial.size()) & (done == false); n++) {
		if ((foundFirst == false) & (initial[n] == fromChar)) {
			foundFirst = true;
			if (getBorders == true)
				sub += fromChar;
		}
		else if ((foundFirst == true) & (initial[n] == toChar)) {
			done = true;
			if (getBorders == true)
				sub += toChar;
		}
		else if (foundFirst == true)
			sub += initial[n];
	}
	return sub;
}

std::string join(std::vector <std::string> *pointerToVec, unsigned int startingElement = 1) {
	std::string finalStr;
	for (unsigned int n = startingElement; n < pointerToVec->size(); n++) {
		if (n != startingElement)
			finalStr += ' ';
		finalStr += (*pointerToVec)[n];
	}
	return finalStr;
}

std::string pushCharBack(std::string initial, unsigned int charLoc) {
	for (unsigned int n = charLoc; n < initial.size(); n++)
		initial[n] = initial[n + 1];
	return initial;
}

std::wstring toWString(const std::string& str)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.from_bytes(str);
}

std::string toString(const std::wstring& wstr)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}

long long hexToDec(std::string hexString) {
	bool convert = true;
	for (unsigned int n = 0; n < hexString.size(); n++) {
		if ((hexString[n] != '0') && (hexString[n] != '1') && (hexString[n] != '2') && (hexString[n] != '3') && (hexString[n] != '4') && (hexString[n] != '5') && (hexString[n] != '6') && (hexString[n] != '7') && (hexString[n] != '8') && (hexString[n] != '9') && (hexString[n] != 'A') && (hexString[n] != 'B') && (hexString[n] != 'C') && (hexString[n] != 'D') && (hexString[n] != 'E') && (hexString[n] != 'F') && (hexString[n] != 'a') && (hexString[n] != 'b') && (hexString[n] != 'c') && (hexString[n] != 'd') && (hexString[n] != 'e') && (hexString[n] != 'f'))
			convert = false;
	}
	if (convert == false) {
		msg("\"" + hexString + "\"" + " is not a valid hexadecimal string", 2);
		return 0;
	}
	else {
		long long finalLongLong = 0;
		unsigned char equivalent;
		for (unsigned int n = 0; n < hexString.size(); n++) {
			switch (hexString[hexString.size() - 1 - n]) {
			case '0':
				equivalent = 0;
				break;
			case '1':
				equivalent = 1;
				break;
			case '2':
				equivalent = 2;
				break;
			case '3':
				equivalent = 3;
				break;
			case '4':
				equivalent = 4;
				break;
			case '5':
				equivalent = 5;
				break;
			case '6':
				equivalent = 6;
				break;
			case '7':
				equivalent = 7;
				break;
			case '8':
				equivalent = 8;
				break;
			case '9':
				equivalent = 9;
				break;
			case 'A':
			case 'a':
				equivalent = 10;
				break;
			case 'B':
			case 'b':
				equivalent = 11;
				break;
			case 'C':
			case 'c':
				equivalent = 12;
				break;
			case 'D':
			case 'd':
				equivalent = 13;
				break;
			case 'E':
			case 'e':
				equivalent = 14;
				break;
			case 'F':
			case 'f':
				equivalent = 15;
				break;
			}
			finalLongLong += equivalent * (unsigned long long)pow(16.0, n);
		}
		return finalLongLong;
	}
}

sf::Image pngppToSfml(png::image< png::rgba_pixel > pngppImg) {
	msg("Converting png++ image to SFML image...", 0);
	sf::Image sfmlImg;
	sf::Uint8 *pixArray = new sf::Uint8[pngppImg.get_width() * pngppImg.get_height() * 4];
	for (unsigned int x = 0; x < pngppImg.get_width(); x++) {
		for (unsigned int y = 0; y < pngppImg.get_height(); y++) {
			pixArray[(x + y * pngppImg.get_width()) * 4] = pngppImg.get_pixel(x, y).red;
			pixArray[(x + y * pngppImg.get_width()) * 4 + 1] = pngppImg.get_pixel(x, y).green;
			pixArray[(x + y * pngppImg.get_width()) * 4 + 2] = pngppImg.get_pixel(x, y).blue;
			pixArray[(x + y * pngppImg.get_width()) * 4 + 3] = pngppImg.get_pixel(x, y).alpha;
		}
	}
	sfmlImg.create((unsigned int)pngppImg.get_width(), (unsigned int)pngppImg.get_height(), pixArray);
	msg("Done!", 4);
	return sfmlImg;
}