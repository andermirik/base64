#include <iostream>
#include "base64.h"

int main() {

	std::string word = "Hello world!";
	auto b64word = base64::base64_encode(word);
	auto db64word = base64::base64_decode(b64word);

	std::cout << word << std::endl;
	std::cout << b64word << std::endl;
	std::cout << db64word << std::endl;

	return(0);
}