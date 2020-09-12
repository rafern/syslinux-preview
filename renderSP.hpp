void update() {
	unsigned char bgNum;
	unsigned char fgNum;
	bool hasScroll = false;
	if ((data::menuRows != 0) & (data::menuLabels.size() != 0)) {
		if (data::menuLabels.size() - 1 > data::menuRows) {
			hasScroll = true;
			data::scrollLength = 1 + ((long double)((long double)(data::menuRows * 100) / (long double)data::menuLabels.size()) / 100.0f) * (long double)data::menuRows;
			while (data::selectedMenu > data::menuRows - 1 + data::menuPageFocus) {
				data::menuPageFocus += data::menuRows;
				data::scrollPos += data::scrollLength - 1;
				if (data::menuPageFocus + data::menuRows > data::menuLabels.size() - 1) {
					data::menuPageFocus = (short)data::menuLabels.size() - data::menuRows;
					data::scrollPos = data::menuRows - data::scrollLength + 1;
				}
			}
			while (data::selectedMenu < data::menuPageFocus) {
				data::menuPageFocus -= data::menuRows;
				data::scrollPos -= data::scrollLength - 1;
				if (data::menuPageFocus < 0)
					data::menuPageFocus = 0;
				if (data::scrollPos < 0)
					data::scrollPos = 0;
			}
		}
	}

	if (data::vesamenu == true) {
		bgNum = 3;
		fgNum = 2;
	}
	else {
		bgNum = 1;
		fgNum = 0;
	}

	
	for (unsigned short nR = 0; nR < data::menuRows + 4; nR++) {
		unsignedString sstream,
					   fsstream;
		if (nR == 0) {
			for (short nC1 = 0; nC1 < data::menuWidth; nC1++) {
				sstream += 219;
				if (nC1 == 0)
					fsstream += 218;
				else if (nC1 == data::menuWidth - 1)
					fsstream += 191;
				else
					fsstream += 196;
			}
			write(sstream, (float)(data::menuMargin * font::width) + (font::width * 0.5f), (float)(0 * font::height) + (font::height * 0.5f), data::shadowing[1][1], data::colors[1][bgNum]);
			write(fsstream, (float)(data::menuMargin * font::width) + (font::width * 0.5f), (float)(0 * font::height) + (font::height * 0.5f), data::shadowing[1][0], data::colors[1][fgNum]);
			sstream.clear();
			fsstream.clear();
		}
		else if (nR == 1) {
			unsigned short numToTitle = (unsigned short)((data::menuWidth - data::title.size()) * 0.5f);
			unsigned short numAfterTitle = (unsigned short)(data::menuWidth - (numToTitle + data::title.size()));
			for (short nC1 = 0; nC1 < numToTitle; nC1++) {
				sstream += 219;
				if (nC1 == 0)
					fsstream += 179;
				else
					fsstream += ' ';
			}
			write(sstream, (float)(data::menuMargin * font::width) + (font::width * 0.5f), (float)(1 * font::height) + (font::height * 0.5f), data::shadowing[1][1], data::colors[1][bgNum]);
			write(fsstream, (float)(data::menuMargin * font::width) + (font::width * 0.5f), (float)(1 * font::height) + (font::height * 0.5f), data::shadowing[1][0], data::colors[1][fgNum]);
			sstream.clear();
			fsstream.clear();
			fsstream += data::title;
			if (data::title.size() != 0) {
				for (short nC2 = 0; nC2 < data::title.size(); nC2++) {
					sstream += 219;
				}
			}
			write(sstream, (float)((data::menuMargin + numToTitle) * font::width) + (font::width * 0.5f), (float)(1 * font::height) + (font::height * 0.5f), data::shadowing[2][1], data::colors[2][bgNum]);
			write(fsstream, (float)((data::menuMargin + numToTitle) * font::width) + (font::width * 0.5f), (float)(1 * font::height) + (font::height * 0.5f), data::shadowing[2][0], data::colors[2][fgNum]);
			sstream.clear();
			fsstream.clear();
			for (short nC3 = 0; nC3 < numAfterTitle; nC3++) {
				sstream += 219;
				if (nC3 == numAfterTitle - 1)
					fsstream += 179;
				else
					fsstream += ' ';
			}
			write(sstream, (float)((data::menuMargin + numToTitle + data::title.size()) * font::width) + (font::width * 0.5f), (float)(1 * font::height) + (font::height * 0.5f), data::shadowing[1][1], data::colors[1][bgNum]);
			write(fsstream, (float)((data::menuMargin + numToTitle + data::title.size()) * font::width) + (font::width * 0.5f), (float)(1 * font::height) + (font::height * 0.5f), data::shadowing[1][0], data::colors[1][fgNum]);
			sstream.clear();
			fsstream.clear();
		}
		else if (nR == 2) {
			for (short nC1 = 0; nC1 < data::menuWidth; nC1++) {
				sstream += 219;
				if (nC1 == 0)
					fsstream += 195;
				else if (nC1 == data::menuWidth - 1)
					fsstream += 180;
				else
					fsstream += 196;
			}
			write(sstream, (float)(data::menuMargin * font::width) + (font::width * 0.5f), (float)(2 * font::height) + (font::height * 0.5f), data::shadowing[1][1], data::colors[1][bgNum]);
			write(fsstream, (float)(data::menuMargin * font::width) + (font::width * 0.5f), (float)(2 * font::height) + (font::height * 0.5f), data::shadowing[1][0], data::colors[1][fgNum]);
			sstream.clear();
			fsstream.clear();
		}
		else if (nR == data::menuRows + 3) {
			for (short nC1 = 0; nC1 < data::menuWidth; nC1++) {
				sstream += 219;
				if (nC1 == 0)
					fsstream += 192;
				else if (nC1 == data::menuWidth - 1)
					fsstream += 217;
				else
					fsstream += 196;
			}
			write(sstream, (float)(data::menuMargin * font::width) + (font::width * 0.5f), (float)((data::menuRows + 3) * font::height) + (font::height * 0.5f), data::shadowing[1][1], data::colors[1][bgNum]);
			write(fsstream, (float)(data::menuMargin * font::width) + (font::width * 0.5f), (float)((data::menuRows + 3) * font::height) + (font::height * 0.5f), data::shadowing[1][0], data::colors[1][fgNum]);
			sstream.clear();
			fsstream.clear();
		}
		else {
			for (short nC1 = 0; nC1 < data::menuWidth; nC1++) {
				if (nC1 == 0) {
					fsstream += 179;
					sstream += 219;
				}
				else if (nC1 != data::menuWidth - 1) {
					fsstream += ' ';
					sstream += ' ';
				}
			}
			write(sstream, (float)(data::menuMargin * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[1][1], data::colors[1][bgNum]);
			write(fsstream, (float)(data::menuMargin * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[1][0], data::colors[1][fgNum]);
			sstream.clear();
			fsstream.clear();
			if ((hasScroll == true) & (nR < 2 + data::scrollPos + data::scrollLength) & (nR > 2 + data::scrollPos)) {
				fsstream += 178;
				sstream += 219;
				write(sstream, (float)((data::menuMargin + data::menuWidth - 1) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[8][1], data::colors[8][bgNum]);
				write(fsstream, (float)((data::menuMargin + data::menuWidth - 1) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[8][0], data::colors[8][fgNum]);
			}
			else {
				fsstream += 179;
				sstream += 219;
				write(sstream, (float)((data::menuMargin + data::menuWidth - 1) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[1][1], data::colors[1][bgNum]);
				write(fsstream, (float)((data::menuMargin + data::menuWidth - 1) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[1][0], data::colors[1][fgNum]);
			}
			sstream.clear();
			fsstream.clear();
			unsigned short menuFocus = nR - 3 + data::menuPageFocus;
			if ((menuFocus > data::menuLabels.size() - 1) | (data::menuLabels.size() == 0)) {
				for (short nC1 = 0; nC1 < data::menuWidth - 2; nC1++)
					sstream += 219;
				write(sstream, (float)((data::menuMargin + 1) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[1][1], data::colors[1][bgNum]);
				sstream.clear();
			}
			else {
				if ((data::menuSeparators[menuFocus] == true) | (data::menuHiddens[menuFocus] == true)) {
					for (short nC1 = 0; nC1 < data::menuWidth - 2; nC1++)
						sstream += 219;
					write(sstream, (float)((data::menuMargin + 1) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[1][1], data::colors[1][bgNum]);
					sstream.clear();
				}
				else if (data::menuDisables[menuFocus] == true) {
					unsigned short charLeft = data::menuWidth - 2 - (unsigned short)data::menuNames[menuFocus].size();
					fsstream += data::menuNames[menuFocus];
					for (unsigned short n = 0; n < fsstream.size(); n++) {
						sstream += 219;
					}
					write(unsignedString(219), (float)((data::menuMargin + 1) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[7][1], data::colors[7][bgNum]);
					write(sstream, (float)((data::menuMargin + 2) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[7][1], data::colors[7][bgNum]);
					write(fsstream, (float)((data::menuMargin + 2) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[7][0], data::colors[7][fgNum]);
					sstream.clear();
					fsstream.clear();
					for (unsigned short n = 0; n < charLeft - 1; n++) {
						sstream += 219;
					}
					if (fsstream.size() < data::menuWidth - 2)
						write(sstream, (float)((data::menuMargin + 2 + data::menuNames[menuFocus].size()) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[1][1], data::colors[1][bgNum]);
					sstream.clear();
				}
				else {
					unsigned short charLeft = data::menuWidth - 2 - (unsigned short)data::menuNames[menuFocus].size();
					fsstream += data::menuNames[menuFocus];
					sstream += 219;
					if (menuFocus == data::selectedMenu)
						write(unsignedString(219), (float)((data::menuMargin + 1) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[5][1], data::colors[5][bgNum]);
					else
						write(unsignedString(219), (float)((data::menuMargin + 1) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[3][1], data::colors[3][bgNum]);
					for (unsigned short n = 0; n < fsstream.size(); n++) {
						if ((data::menuHasHotkey[menuFocus] == true) & (n == data::menuHotkey[menuFocus])) {
							if (menuFocus == data::selectedMenu) {
								write(sstream, (float)((data::menuMargin + 2 + n) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[6][1], data::colors[6][bgNum]);
								write(unsignedString(fsstream[n]), (float)((data::menuMargin + 2 + n) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[6][0], data::colors[6][fgNum]);
							}
							else {
								write(sstream, (float)((data::menuMargin + 2 + n) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[4][1], data::colors[4][bgNum]);
								write(unsignedString(fsstream[n]), (float)((data::menuMargin + 2 + n) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[4][0], data::colors[4][fgNum]);
							}
						}
						else {
							if (menuFocus == data::selectedMenu) {
								write(sstream, (float)((data::menuMargin + 2 + n) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[5][1], data::colors[5][bgNum]);
								write(unsignedString(fsstream[n]), (float)((data::menuMargin + 2 + n) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[5][0], data::colors[5][fgNum]);
							}
							else {
								write(sstream, (float)((data::menuMargin + 2 + n) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[3][1], data::colors[3][bgNum]);
								write(unsignedString(fsstream[n]), (float)((data::menuMargin + 2 + n) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[3][0], data::colors[3][fgNum]);
							}
						}
					}
					unsigned int tempSize = (unsigned int)fsstream.size();
					sstream.clear();
					fsstream.clear();
					for (unsigned short n = 0; n < charLeft - 1; n++)
						sstream += 219;
					if ((menuFocus == data::selectedMenu) & ((tempSize < (unsigned int)data::menuWidth - 2)))
						write(sstream, (float)((data::menuMargin + data::menuNames[menuFocus].size() + 2) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[5][1], data::colors[5][bgNum]);
					else if (tempSize < (unsigned int)data::menuWidth - 2)
						write(sstream, (float)((data::menuMargin + data::menuNames[menuFocus].size() + 2) * font::width) + (font::width * 0.5f), (float)(nR * font::height) + (font::height * 0.5f), data::shadowing[3][1], data::colors[3][bgNum]);
					sstream.clear();
				}
			}
		}
	}
	if (data::moved == false) {
		std::string initial = data::menuAutoboot,
					before;
		bool done = false;
		for (unsigned int n = 0; (n < initial.size()) & (done == false); n++) {
			if (initial[n] == '#')
				done = true;
			else
				before += initial[n];
		}
		std::string after;
		for (unsigned int n = (unsigned int)before.size() + 1; n < initial.size(); n++) {
			after += toString(std::wstring(1, initial[n]))[0];
		}

		if ((int)floor(data::timeoutTime.asSeconds()) == 1) {
			after = replaceSubstring(after, "{s}", data::autobootSingular);
			after = replaceSubstring(after, "{d}", "");
			after = replaceSubstring(after, "{p}", "");
		}
		else if ((int)floor(data::timeoutTime.asSeconds()) == 2) {
			after = replaceSubstring(after, "{s}", "");
			if (data::autobootDual.empty() == false) {
				after = replaceSubstring(after, "{d}", data::autobootDual);
				after = replaceSubstring(after, "{p}", "");
			}
			else {
				after = replaceSubstring(after, "{d}", "");
				after = replaceSubstring(after, "{p}", data::autobootPlural);
			}
		}
		else {
			after = replaceSubstring(after, "{s}", "");
			after = replaceSubstring(after, "{d}", "");
			after = replaceSubstring(after, "{p}", data::autobootPlural);
		}

		unsigned short spaceBefore = (unsigned short)((78 - before.size() - std::to_string((int)floor(data::timeoutTime.asSeconds())).size() - after.size()) * 0.5);
		write(before, (float)(spaceBefore * font::width) + (font::width * 0.5f), (float)((data::menuTimeoutRow - 1) * font::height) + (font::height * 0.5f), data::shadowing[15][0], data::colors[15][fgNum]);
		write(std::to_string((int)floor(data::timeoutTime.asSeconds())), (float)((spaceBefore + before.size()) * font::width) + (font::width * 0.5f), (float)((data::menuTimeoutRow - 1) * font::height) + (font::height * 0.5f), data::shadowing[16][0], data::colors[16][fgNum]);
		write(after, (float)((spaceBefore + before.size() + std::to_string((int)floor(data::timeoutTime.asSeconds())).size()) * font::width) + (font::width * 0.5f), (float)((data::menuTimeoutRow - 1) * font::height) + (font::height * 0.5f), data::shadowing[15][0], data::colors[15][fgNum]);
	}
	if (data::allowOptions == true) {
		unsigned short spaceBefore = (unsigned short)((78 - data::menuTabMsg.size()) * 0.5);
		write(data::menuTabMsg, (float)(spaceBefore * font::width) + (font::width * 0.5f), (float)((data::menuTabMsgRow - 1) * font::height) + (font::height * 0.5f), data::shadowing[9][0], data::colors[9][fgNum]);

	}
	else {
		unsigned short spaceBefore = (unsigned short)((78 - data::menuNoTabMsg.size()) * 0.5);
		write(data::menuNoTabMsg, (float)(spaceBefore * font::width) + (font::width * 0.5f), (float)((data::menuTabMsgRow - 1) * font::height) + (font::height * 0.5f), data::shadowing[9][0], data::colors[9][fgNum]);
	}
	if(data::selectedMenu != 65535)
		write(data::menuHelps[data::selectedMenu], (float)(font::width) + (font::width * 0.5f), (float)((data::menuHelpMsgRow - 1) * font::height) + (font::height * 0.5f), data::shadowing[17][0], data::colors[17][fgNum]);
}

void renderSP() {
	sf::Event event;
	
	if (data::imgName.empty() == false) {
		std::ifstream testFStream(data::workingDir + data::imgName);
		if (testFStream) {
			png::image< png::rgba_pixel > pngppBgImg(data::workingDir + data::imgName);
			if (pngppBgImg.get_width() == 0)
				msg("Background image failed to load! Background won't be rendered! Please check background file name in syslinux configuration.", 2);
			else {
				data::bgTex.loadFromImage(pngppToSfml(pngppBgImg));
				if ((data::bgTex.getSize().x == 640) & (data::bgTex.getSize().y == 480)) {
					msg("Background loaded successfully and is valid to draw!", 4);
					data::renderBg = true;
				}
				else
					msg("Background image size isn't equal to window resolution! No background will be rendered.", 2);
			}
		}
		else
			msg("Background image failed to read! Background won't be rendered! Please check background file name in syslinux configuration.", 2);
	}
	data::bgSprite.setTexture(data::bgTex);
	if (!font::fontTex.loadFromFile("font.png"))
		msg("Font failed to load from resources, so text won't be rendered!", 3);

	if (data::menuNames.size() > 0) {
		for (unsigned short n = 0; (n < data::menuNames.size() - 1) & (data::selectedMenu == 65535); n++) {
			if (data::menuDefaults[n] == true)
				data::selectedMenu = n;
		}
		if (data::selectedMenu == 65535) {
			for (unsigned short n2 = 0; (n2 < data::menuNames.size() - 1) & (data::selectedMenu == 65535); n2++) {
				if ((data::menuDisables[n2] == false) & (data::menuSeparators[n2] == false))
					data::selectedMenu = n2;
			}
		}
	}
	
	data::timeoutTime = sf::seconds((float)(data::timeout * 0.1));
	data::window.create(sf::VideoMode(640, 480), "Syslinux Preview " + info::version, sf::Style::Close);
	data::timeoutClock.restart();
	while (data::window.isOpen() == true) {
		if((data::vesamenu == true) && (data::imgName.empty() == false) && (data::bgTex.getSize().x == 640) && (data::bgTex.getSize().y == 480))
			data::window.draw(data::bgSprite);
		else if(data::vesamenu == true)
			data::window.clear(data::colors[0][3]);
		else
			data::window.clear(data::colors[0][1]);

		while (data::window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				data::window.close();
				msg("Syslinux emulation aborted by user.", 0); 
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					if (data::selectedMenu != 65535) {
						for (unsigned short n = (unsigned short)data::selectedMenu - 1; (n > 0) & (data::isDone == false); n--) {
							if ((data::menuDisables[n] == false) & (data::menuSeparators[n] == false)) {
								data::selectedMenu = n;
								data::isDone = true;
							}
						}
						data::isDone = false;
						data::moved = true;
					}
					break;
				case sf::Keyboard::Down:
					if (data::selectedMenu != 65535) {
						for (unsigned short n = (unsigned short)data::selectedMenu + 1; (n < data::menuNames.size()) & (data::isDone == false); n++) {
							if ((data::menuDisables[n] == false) & (data::menuSeparators[n] == false)) {
								data::selectedMenu = n;
								data::isDone = true;
							}
						}
						data::isDone = false;
						data::moved = true;
					}
					break;
				case sf::Keyboard::Left:
					if (data::selectedMenu != 65535) {
						data::selectedMenu -= data::menuRows;
						if (data::selectedMenu < 0) {
							data::selectedMenu = 65535;
							for (unsigned short n = 0; (n < data::menuNames.size() - 1) & (data::selectedMenu == 65535); n++) {
								if ((data::menuDisables[n] == false) & (data::menuSeparators[n] == false))
									data::selectedMenu = n;
							}
						}
						if ((data::menuDisables[data::selectedMenu] == true) | (data::menuSeparators[data::selectedMenu] == true)) {
							for (unsigned short n = (unsigned short)data::selectedMenu - 1; (n > 0) & (data::isDone == false); n--) {
								if ((data::menuDisables[n] == false) & (data::menuSeparators[n] == false)) {
									data::selectedMenu = n;
									data::isDone = true;
								}
							}
						}
						data::isDone = false;
						data::moved = true;
					}
					break;
				case sf::Keyboard::Right:
					if (data::selectedMenu != 65535) {
						data::selectedMenu += data::menuRows;
						if (data::selectedMenu > data::menuLabels.size() - 1) {
							data::selectedMenu = 65535;
							for (unsigned short n = (unsigned short)data::menuNames.size() - 1; (n > 0) & (data::selectedMenu == 65535); n--) {
								if ((data::menuDisables[n] == false) & (data::menuSeparators[n] == false))
									data::selectedMenu = n;
							}
						}
						if ((data::menuDisables[data::selectedMenu] == true) | (data::menuSeparators[data::selectedMenu] == true)) {
							for (unsigned short n = (unsigned short)data::selectedMenu + 1; (n < data::menuNames.size()) & (data::isDone == false); n++) {
								if ((data::menuDisables[n] == false) & (data::menuSeparators[n] == false)) {
									data::selectedMenu = n;
									data::isDone = true;
								}
							}
						}
						data::isDone = false;
						data::moved = true;
					}
					break;
				case sf::Keyboard::Return:
					boot();
					break;
				default:
					if (canToChar(event.key.code) == true) {
						bool done = false;
						for (unsigned short n = 0; (n < data::hotkeyMenus.size()) & (done == false); n++) {
							if (data::hotkeyChar[n] == keyToChar(event.key.code)) {
								data::selectedMenu = data::hotkeyMenus[n];
								if(data::immediate == true)
									boot();
								data::moved = true;
								done = true;
							}
						}
					}
				}
				break;
			}
		}

		update();
		if ((data::moved == false) & (data::window.isOpen() == true)) {
			if(data::showFPS)
				write(std::to_string(1 / data::timeoutClock.getElapsedTime().asSeconds()) + " FPS", 0, 0, true, sf::Color::Red);
			data::timeoutTime -= data::timeoutClock.restart();
			if ((int)floor(data::timeoutTime.asSeconds()) < 0)
				boot(true);
		}
		else if(data::showFPS)
			write(std::to_string(1 / data::timeoutClock.restart().asSeconds()) + " FPS", 0, 0, true, sf::Color::Red);
		data::window.display();
	}
	//std::cout << std::endl << "*** END OF RENDER() ***" << std::endl;
}