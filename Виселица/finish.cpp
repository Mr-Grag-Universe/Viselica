#pragma once
#include <iostream>
#include <string>

void finish(int result, std::string word) {
	if (result == 10) { std::cout << "You've lost!\n"; std::cout << "We made a wish for the word " << word; }
	else { std::cout << "You've won! Errors committed " << result; }
}