namespace info {
	std::string version = "1.0 WIP";
}

namespace winFuncs {
	bool enableWarnings = true;
	bool firstWarn = true;
}

namespace data {
	bool textMode = false;
	std::string workingDir = "";
	std::vector <std::string> files;
	std::vector <std::string> filenames;
	std::vector <std::string> commands;
	std::vector <std::string> menuLabels;
	std::vector <std::string> menuNames;
	std::vector <std::string> menuBoots;
	std::vector <std::string> menuHelps;
	std::vector <std::string> menuPasswords;
	std::vector <std::string> menuOriginalNames;
	std::vector <bool> menuDefaults;
	std::vector <bool> menuSeparators;
	std::vector <bool> menuDisables;
	std::vector <bool> menuHiddens;
	std::vector <unsigned int> menuHotkey;
	std::vector <bool> menuHasHotkey;
	std::string title = "";
	std::string menuTabMsg = "Press [Tab] to edit options";
	std::string menuNoTabMsg = "";
	std::string menuAutoboot = "Automatic boot in # second{p}...";
	std::string autobootSingular = "";
	std::string autobootDual = "";
	std::string autobootPlural = "s";
	unsigned int timeout = 100;
	sf::Clock timeoutClock;
	sf::Time timeoutTime;
	bool prompt = true;
	bool noescape = false;
	bool vesamenu = false;
	sf::Color colors[19][4];
	bool shadowing[19][2];
	short menuWidth = 80;
	short menuMargin = 10;
	short menuPasswordMargin = 3;
	short menuRows= 12;
	short menuTabMsgRow = 18;
	short menuCmdLineRow = 18;
	short menuEndRow = -1;
	short menuPasswordRow = 11;
	short menuTimeoutRow = 20;
	short menuHelpMsgRow = 22;
	short menuHelpMsgEndRow = -1;
	short menuHiddenRow = -2;
	short menuHShift = 0;
	short menuVShift = 0;
	sf::Texture bgTex;
	sf::Sprite bgSprite;
	std::string imgName;
	sf::RenderWindow window;
	long selectedMenu = 65535;
	bool isDone = false;
	bool moved = false;
	bool allowOptions = true;
	bool immediate = false;
	std::vector <unsigned short> hotkeyMenus;
	std::vector <char> hotkeyChar;
	long double scrollLength = 0;
	short menuPageFocus = 0;
	long double scrollPos = 0;
	bool renderBg = false;
	bool showFPS = false;
}