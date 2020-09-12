char keyToChar(sf::Keyboard::Key key) {
	switch (key) {
	default: //Just really to avoid crashes
	case sf::Keyboard::A:
		return 'a';
		break;
	case sf::Keyboard::B:
		return 'b';
		break;
	case sf::Keyboard::C:
		return 'c';
		break;
	case sf::Keyboard::D:
		return 'd';
		break;
	case sf::Keyboard::E:
		return 'e';
		break;
	case sf::Keyboard::F:
		return 'f';
		break;
	case sf::Keyboard::G:
		return 'g';
		break;
	case sf::Keyboard::H:
		return 'h';
		break;
	case sf::Keyboard::I:
		return 'i';
		break;
	case sf::Keyboard::J:
		return 'j';
		break;
	case sf::Keyboard::K:
		return 'k';
		break;
	case sf::Keyboard::L:
		return 'l';
		break;
	case sf::Keyboard::M:
		return 'm';
		break;
	case sf::Keyboard::N:
		return 'n';
		break;
	case sf::Keyboard::O:
		return 'o';
		break;
	case sf::Keyboard::P:
		return 'p';
		break;
	case sf::Keyboard::Q:
		return 'q';
		break;
	case sf::Keyboard::R:
		return 'r';
		break;
	case sf::Keyboard::S:
		return 's';
		break;
	case sf::Keyboard::T:
		return 't';
		break;
	case sf::Keyboard::U:
		return 'u';
		break;
	case sf::Keyboard::V:
		return 'v';
		break;
	case sf::Keyboard::W:
		return 'w';
		break;
	case sf::Keyboard::X:
		return 'x';
		break;
	case sf::Keyboard::Y:
		return 'y';
		break;
	case sf::Keyboard::Z:
		return 'z';
		break;
	case sf::Keyboard::Num0:
		return '0';
		break;
	case sf::Keyboard::Num1:
		return '1';
		break;
	case sf::Keyboard::Num2:
		return '2';
		break;
	case sf::Keyboard::Num3:
		return '3';
		break;
	case sf::Keyboard::Num4:
		return '4';
		break;
	case sf::Keyboard::Num5:
		return '5';
		break;
	case sf::Keyboard::Num6:
		return '6';
		break;
	case sf::Keyboard::Num7:
		return '7';
		break;
	case sf::Keyboard::Num8:
		return '8';
		break;
	case sf::Keyboard::Num9:
		return '9';
		break;
	case sf::Keyboard::Space:
		return ' ';
		break;
	}
}

bool canToChar(sf::Keyboard::Key key) {
	switch (key) {
	case sf::Keyboard::A:
	case sf::Keyboard::B:
	case sf::Keyboard::C:
	case sf::Keyboard::D:
	case sf::Keyboard::E:
	case sf::Keyboard::F:
	case sf::Keyboard::G:
	case sf::Keyboard::H:
	case sf::Keyboard::I:
	case sf::Keyboard::J:
	case sf::Keyboard::K:
	case sf::Keyboard::L:
	case sf::Keyboard::M:
	case sf::Keyboard::N:
	case sf::Keyboard::O:
	case sf::Keyboard::P:
	case sf::Keyboard::Q:
	case sf::Keyboard::R:
	case sf::Keyboard::S:
	case sf::Keyboard::T:
	case sf::Keyboard::U:
	case sf::Keyboard::V:
	case sf::Keyboard::W:
	case sf::Keyboard::X:
	case sf::Keyboard::Y:
	case sf::Keyboard::Z:
	case sf::Keyboard::Num0:
	case sf::Keyboard::Num1:
	case sf::Keyboard::Num2:
	case sf::Keyboard::Num3:
	case sf::Keyboard::Num4:
	case sf::Keyboard::Num5:
	case sf::Keyboard::Num6:
	case sf::Keyboard::Num7:
	case sf::Keyboard::Num8:
	case sf::Keyboard::Num9:
	case sf::Keyboard::Space:
		return true;
	default:
		return false;
	}
}