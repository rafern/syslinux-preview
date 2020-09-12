void msg(std::string message, unsigned char type = 0) { // 0=Info; 1=Warning; 2=Error; 3=Fatal; 4=Success
	switch (type) {
	default:
	case 0:
		std::cout << "[INFO] " << message << std::endl;
		break;
	case 1:
		if (winFuncs::enableWarnings == true) {
			if (winFuncs::firstWarn == true) {
				winFuncs::firstWarn = false;
				msg("To disable warnings add the '-W' argument.", 0);
			}
			std::cout << "[WARNING] " << message << std::endl;
		}
		break;
	case 2:
			std::cout << "[ERROR] " << message << std::endl;
		break;
	case 3:
			std::cout << "[FATAL] " << message << std::endl;
		break;
	case 4:
			std::cout << "[SUCCESS] " << message << std::endl;
		break;
	}
}