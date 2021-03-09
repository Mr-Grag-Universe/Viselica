#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "h1.h"

int game(std::string word) {
	std::cout << word;

	// error counter
	short i{ 0 };
	short mist_type{ 0 };
	bool letters[33]; for (int j = 0; j < 33; ++j) { letters[j] = false; }

	// temporary unsolved word
	std::string word_new = "";	for (auto now : word) { word_new += "_"; }

	while (i < 10) {
		
		// drawing everything
		drawing(i, word_new, word, mist_type); mist_type = 0;

		std::string enter;// the entered string
		std::cin >> enter;

		//input processing
		//if you made a mistake
		/*
		if (word.find(enter) == word.npos) {
			std::cout << "Worth.";
			i++;
		}
		*/
		// if you entered not 1 letter and not a word
		if ((enter.size() > 1) && (enter.size() != word.size())) {
			mist_type = 5;
			continue;
		}
		// if you entered a letter or word of the desired size
		else {
			if (word.size() == enter.size()) { // if you entered the word
				//if you guessed the word
				if (word == enter) { drawing(i, word_new, word, mist_type); return i; }

				//if you didn't guessed the word
				else { i++; mist_type = 4; }
			}
			// if the letter is not in the hidden word
			if (word.find(enter) == word.npos) { i++; mist_type = 1; }
			else { // if you entered a letter
				if (letters[enter.at(0) - 'а']) { mist_type = 2; continue; }
				if ('а' >= enter[0] || enter[0] <= 'ю') { letters[enter[0] - 'а'] = true; }
				for (int j = 0; j < word.size(); ++j) {
					//if the entered letter is found in the hidden word
					if (enter.at(0) == word.at(j)) {
						//if such a letter is already open
						if (word_new[j] == enter[0]) { mist_type = 2; continue; }
						
						//если закрытая буква угадана
						else {
							word_new[j] = enter[0];
							//std::string :: iterator iter = word_new.begin();
							//word_new.erase(iter+j+1, 1);
							//word_new.insert(j+1, enter[0]);
						}
					}

				}
				mist_type = 3;
			}

			//word_new.insert(word.find(enter), enter);
		}
		if (word == word_new) { drawing(i, word_new, word, mist_type);  return i; }
	}
	drawing(i, word_new, word, mist_type);
	return i;
}