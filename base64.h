#pragma once
#include <string>
namespace base64 {
	std::string base64_decode(const std::string& bytes);
	std::string base64_encode(const std::string& bytes);
}