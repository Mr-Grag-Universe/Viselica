#include <iostream>
#include <string>
#include <fstream>
#include "h1.h"

void drawing(int mistakes, std::string word_new, std::string word, int mist_type) {

	system("cls"); // clearing the screen

	//drawing the rules of the game in a frame
	rules();

	//drawing a hidden word
	std::cout << "The hidden word: ";
	for (int i = 0; i < word_new.size(); ++i) {
		std::cout << word_new.at(i) << " ";
	}
	std::cout << std::endl;

	std::ifstream f;
	if (mistakes == 0) { std::cout << "There isn't mistakes.\n"; }
	else {//если ошибки есть то нарисовать соответствующий их числу кадр
		std::cout << "You've made  " << mistakes << " mistakes.\n";
		f.open("picture.txt", std::ios::in);
		for (int i = 1; i < mistakes; ++i) {
			for (int j = 0; j < 16; ++j) {
				std::string temp;
				getline(f, temp);
			}
		}
		for (int j = 0; j < 16; ++j) {
			std::string temp;
			getline(f, temp);
			std::cout << temp << std::endl;
		}
		f.close();
	}

	std::cout << "";
	switch (mist_type)
	{
	case 1:
		std::cout << "There isn't this letter in our word.\n";
		break;
	case 2:
		std::cout << "You have already checked this letter. Try another one.\n";
		break;
	case 3:
		std::cout << "Right. Such a letter is in our word.\n";
		break;
	case 4:
		std::cout << "We didn't think of that word.\n";
		break;
	case 5:
		std::cout << "You can enter only 1 letter or a whole word (of the desired size). Repeat.\n";
		break;
	}
	if (mistakes < 10) { std::cout << "Enter your entire letter or word: "; }
	
}