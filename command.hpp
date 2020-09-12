void read(std::string file) {
	std::string fileCont;
	std::ifstream fstrm(file, std::ifstream::binary | std::ifstream::in);
	if (fstrm) {
		char letter;
		for (int i = 0; !fstrm.eof(); i++) {
			fstrm.get(letter);
			fileCont += letter;
		}
		fileCont[fileCont.size() - 1] = '\n';
	}
	else
		std::cout << "Error opening file \"" << file << "\". Please check your configuration file" << std::endl;
	fstrm.close();
	data::files.push_back(fileCont);
	data::filenames.push_back(file);

	//std::cout << std::endl << "*** END OF READ() ***" << std::endl;
}

void genComs(int fn) {
	std::string command;
	for (unsigned long long n = 0; n < data::files[fn].size(); n++) {
		if(data::files[fn][n] == '\n') {
			data::commands.push_back(command);
			command.clear();
		}
		else if(data::files[fn][n] > 31)
			command += data::files[fn][n];
	}
	//std::cout << std::endl << "*** END OF GENCOMS() ***" << std::endl;
}

void makeHotkey() {
	for (unsigned int n = 0; n < data::menuNames[data::menuNames.size() - 1].size(); n++) {
		if (data::menuNames[data::menuNames.size() - 1][n] == '^') {
			bool doneOne = false;
			if ((data::menuHasHotkey[data::menuHasHotkey.size() - 1] == false) & (data::menuDisables[data::menuDisables.size() - 1] == false) & (data::menuSeparators[data::menuSeparators.size() - 1] == false)) {
				bool exist = false;
				if (data::hotkeyChar.size() != 0) {
					for (unsigned short n2 = 0; (n2 < data::hotkeyChar.size()) & (exist == false); n2++) {
						if (data::hotkeyChar[n2] == toLowercase(std::string(1, data::menuNames[data::menuNames.size() - 1][n + 1]))[0])
							exist = true;
					}
				}
				if (exist == false) {
					data::menuHasHotkey[data::menuHasHotkey.size() - 1] = true;
					data::menuHotkey[data::menuHotkey.size() - 1] = n;
					doneOne = true;
				}
			}
			data::menuNames[data::menuNames.size() - 1] = pushCharBack(data::menuNames[data::menuNames.size() - 1], n);
			data::menuNames[data::menuNames.size() - 1].erase(data::menuNames[data::menuNames.size() - 1].end() - 1);
			if (doneOne == true) {
				data::hotkeyMenus.push_back((unsigned short)data::menuNames.size() - 1);
				data::hotkeyChar.push_back(toLowercase(std::string(1, data::menuNames[data::menuNames.size() - 1][n]))[0]);
			}
		}
	}
}

std::string prepAutoboot(std::string expression) {
	std::string returnVal;
	std::string sub = "";
	bool done = false;
	unsigned short num = 0;
	unsigned short focus = 0;
	for (unsigned int n = 0; n < expression.size(); n++) {
		if (expression[n] == ',')
			num++;
	}
	if (num > 2)
		num = 2;
	for (unsigned int n = 0; (n < expression.size() + 1) & (done == false); n++) {
		if ((expression[n] == ',') | (n == expression.size())) {
			if (focus == 0)
				data::autobootSingular = sub;
			else if (focus == 1) {
				if (num == 1)
					data::autobootPlural = sub;
				else if (num == 2)
					data::autobootDual = sub;
			}
			else if (focus == 2) {
				if (num == 2)
					data::autobootPlural = sub;
			}
			sub = "";
			focus++;
		}
		else
			sub += expression[n];
	}
	if (num == 1)
		returnVal = "{s}{p}";
	else if (num == 2)
		returnVal = "{s}{d}{p}";
	return returnVal;
}

void prep() {
	defaultClr();
	for (unsigned int n = 0; n < data::commands.size(); n++) {
		if (data::commands[n].empty() == false) {
			std::string subcom;
			std::vector <std::string> subcoms;
			for (unsigned long long n2 = 0; n2 < data::commands[n].size(); n2++) {
				if (data::commands[n][n2] == ' ') {
					subcoms.push_back(subcom);
					subcom.clear();
				}
				else if (n2 == data::commands[n].size() - 1) {
					subcom += data::commands[n][n2];
					subcoms.push_back(subcom);
					subcom.clear();
				}
				else
					subcom += data::commands[n][n2];
			}
			//std::cout << n << ':' << data::commands[n] << std::endl;
			if (data::textMode == false) {
				if (toLowercase(subcoms[0]) == "ui") {
					if (toLowercase(lastWord(join(&subcoms, 1), '/')) == "vesamenu.c32")
						data::vesamenu = true;
					else if (toLowercase(lastWord(join(&subcoms, 1), '/')) == "menu.c32")
						data::vesamenu = false;
				}
				else if (toLowercase(subcoms[0]) == "include") {
					read(data::workingDir + lastWord(join(&subcoms, 1), '/'));
					genComs((int)data::files.size() - 1);
				}
				else if (toLowercase(subcoms[0]) == "label") {
					data::menuLabels.push_back(subcoms[1]);
					data::menuNames.push_back("");
					data::menuBoots.push_back("");
					data::menuHelps.push_back("");
					data::menuPasswords.push_back("");
					data::menuDefaults.push_back(false);
					data::menuSeparators.push_back(false);
					data::menuDisables.push_back(false);
					data::menuHiddens.push_back(false);
					data::menuHotkey.push_back(0);
					data::menuHasHotkey.push_back(false);
				}
				else if (toLowercase(subcoms[0]) == "menu") {
					if (toLowercase(subcoms[1]) == "label") {
						data::menuNames[data::menuNames.size() - 1] = join(&subcoms, 2);
						makeHotkey();
					}
					else if (toLowercase(subcoms[1]) == "title")
						data::title = join(&subcoms, 2);
					else if (toLowercase(subcoms[1]) == "default")
						data::menuDefaults[data::menuDefaults.size() - 1] = true;
					else if (toLowercase(subcoms[1]) == "separator") {
						data::menuLabels.push_back("");
						data::menuNames.push_back("");
						data::menuBoots.push_back("");
						data::menuHelps.push_back("");
						data::menuPasswords.push_back("");
						data::menuDefaults.push_back(false);
						data::menuSeparators.push_back(true);
						data::menuDisables.push_back(false);
						data::menuHiddens.push_back(false);
						data::menuHotkey.push_back(0);
						data::menuHasHotkey.push_back(false);
					}
					else if (toLowercase(subcoms[1]) == "disabled")
						data::menuDisables[data::menuDisables.size() - 1] = true;
					else if (toLowercase(subcoms[1]) == "hidden")
						data::menuHiddens[data::menuHiddens.size() - 1] = true;
					else if (toLowercase(subcoms[1]) == "color") {
						if (subcoms.size() == 4)
							menuColor(subcoms[2], subcoms[3], subcoms[4], subcoms[5]);
						else if (subcoms.size() > 4)
							menuColor(subcoms[2], subcoms[3], subcoms[4], subcoms[5], subcoms[6]);
						else
							msg("Missing arguments in MENU COLOR. No changes will be made.", 2);
					}
					else if (toLowercase(subcoms[1]) == "background")
						data::imgName = lastWord(join(&subcoms, 1), '/');
					else if (toLowercase(subcoms[1]) == "width")
						data::menuWidth = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "margin")
						data::menuMargin = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "passwordmargin")
						data::menuPasswordMargin = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "rows")
						data::menuRows = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "tabmsgrow")
						data::menuTabMsgRow = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "cmdlinerow")
						data::menuCmdLineRow = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "endrow")
						data::menuEndRow = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "passwordrow")
						data::menuPasswordRow = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "timeoutrow")
						data::menuTimeoutRow = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "helpmsgrow")
						data::menuHelpMsgRow = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "helpmsgendrow")
						data::menuHelpMsgEndRow = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "hiddenrow")
						data::menuHiddenRow = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "hshift")
						data::menuHShift = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "vshift")
						data::menuVShift = std::stoi(subcoms[2]);
					else if (toLowercase(subcoms[1]) == "autoboot") {
						data::menuAutoboot = join(&subcoms, 2);
						std::string sub;
						sub = getSubstringFromChars(data::menuAutoboot, '{', '}', true);
						//std::cout << sub << std::endl;
						data::menuAutoboot = replaceSubstring(data::menuAutoboot, sub, prepAutoboot(getSubstringFromChars(data::menuAutoboot, '{', '}')));
						//std::cout << data::menuAutoboot << std::endl << data::autobootSingular << ',' << data::autobootDual << ',' << data::autobootPlural << std::endl;
					}
					else if (toLowercase(subcoms[1]) == "tabmsg")
						data::menuTabMsg = join(&subcoms, 2);
					else if (toLowercase(subcoms[1]) == "notabmsg")
						data::menuNoTabMsg = join(&subcoms, 2);
					else if (toLowercase(subcoms[1]) == "immediate")
						data::immediate = true;
					else
						msg("Unknown or unsupported command:'" + join(&subcoms, 0) + "'.", 1);
				}
				else if ((toLowercase(subcoms[0]) == "kernel") || (toLowercase(subcoms[0]) == "append") || (toLowercase(subcoms[0]) == "sysappend") || (toLowercase(subcoms[0]) == "localboot") || (toLowercase(subcoms[0]) == "initrd") || (toLowercase(subcoms[0]) == "config") || (toLowercase(subcoms[0]) == "com32") || (toLowercase(subcoms[0]) == "comboot") || (toLowercase(subcoms[0]) == "fdimage") || (toLowercase(subcoms[0]) == "pxe") || (toLowercase(subcoms[0]) == "bss") || (toLowercase(subcoms[0]) == "boot") || (toLowercase(subcoms[0]) == "linux")) {
					if(!data::menuBoots[data::menuBoots.size() - 1].empty())
						data::menuBoots[data::menuBoots.size() - 1] += '\n';
					data::menuBoots[data::menuBoots.size() - 1] += join(&subcoms, 0);
				}
				else if (toLowercase(join(&subcoms, 0)) == "text help")
					data::textMode = true;
				else if (toLowercase(subcoms[0]) == "timeout")
					data::timeout = std::stol(subcoms[1]);
				else if (toLowercase(subcoms[0]) == "allowoptions") {
					if (subcoms[1] == "0")
						data::allowOptions = false;
					else if (subcoms[1] == "1")
						data::allowOptions = true;
				}
				else if (toLowercase(subcoms[0]) == "prompt") {
					if (subcoms[1] == "0")
						data::prompt = false;
					else if (subcoms[1] == "1")
						data::prompt = true;
				}
				else if (toLowercase(subcoms[0]) == "noescape") {
					if (subcoms[1] == "0")
						data::noescape = false;
					else if (subcoms[1] == "1")
						data::noescape = true;
				}
				else
					msg("Unknown or unsupported command:'" + join(&subcoms, 0) + "'.", 1);
			}
			else if (toLowercase(subcoms[0]) == "endtext")
				data::textMode = false;
			else
				data::menuHelps[data::menuHelps.size() - 1] += join(&subcoms, 0) + '\n';
			subcoms.clear();
		}
	}
	if (data::menuWidth + (data::menuMargin * 2) > 78)
		data::menuWidth = 78 - (data::menuMargin * 2);
	if (data::title.size() > data::menuWidth)
		data::menuWidth = (short)data::title.size() + 2;
}

void optimise() {
	if (data::menuNames.size() > 0) {
		for (unsigned int n = 0; n < data::menuNames.size(); n++) {
			data::menuOriginalNames.push_back(data::menuNames[n]);
			if (data::menuNames[n].size() > data::menuWidth - 3) {
				data::menuNames[n].clear();
				for (unsigned int n2 = 0; n2 < (unsigned int)data::menuWidth - 3; n2++)
					data::menuNames[n] += data::menuOriginalNames[n][n2];
			}
				
		}
	}
}

void boot(bool autoboot = false) {
	data::window.close();
	msg("Syslinux emulation completed.", 0);
	if (data::selectedMenu == 65535)
		msg("The syslinux configuration had no menu entries", 0);
	else {
		if (autoboot == true)
			msg("Autobooted the \"" + data::menuOriginalNames[data::selectedMenu] + "\" menu entry (Label:" + data::menuLabels[data::selectedMenu] + "):\n" + data::menuBoots[data::selectedMenu], 0);
		else
			msg("Boot invoked by the \"" + data::menuOriginalNames[data::selectedMenu] + "\" menu entry (Label:" + data::menuLabels[data::selectedMenu] + "):\n" + data::menuBoots[data::selectedMenu], 0);
	}
}