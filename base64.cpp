#include "base64.h"

namespace base64 {
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	std::string base64_encode(const std::string& bytes) {
		std::string result;
		result.reserve(bytes.size() * 4 / 3);
		char bytes_4[4];
		char bytes_3[3];

		int count_zeros = 0;
		if (bytes.size() % 3) {
			count_zeros = 3 - (bytes.size() % 3);
		}

		int cp = 0;
		while (cp < bytes.size()) {
			bytes_3[0] = bytes[cp];

			if (cp + 1 >= bytes.size())
				bytes_3[1] = 0;
			else
				bytes_3[1] = bytes[cp + 1];

			if (cp + 2 >= bytes.size())
				bytes_3[2] = 0;
			else
				bytes_3[2] = bytes[cp + 2];

			bytes_4[0] = (bytes_3[0] & 0xfc) >> 2;
			bytes_4[1] = ((bytes_3[0] & 0x03) << 4) + ((bytes_3[1] & 0xf0) >> 4);
			bytes_4[2] = ((bytes_3[1] & 0x0f) << 2) + ((bytes_3[2] & 0xc0) >> 6);
			bytes_4[3] = bytes_3[2] & 0x3f;

			cp += 3;

			for (int i = 0; i < 4; i++) {
				result.push_back(alphabet[bytes_4[i]]);
			}
		}

		while (count_zeros) {
			result[result.size() - count_zeros--] = '=';
		}

		return result;
	}

	std::string base64_decode(const std::string& bytes) {
		std::string result;
		result.reserve(bytes.size() * 3 / 4);

		char bytes_4[4];
		char bytes_3[3];

		int cp = 0;
		while (cp < bytes.size() && bytes[cp] != '=') {
			bytes_4[0] = bytes[cp];
			bytes_4[1] = bytes[cp + 1];
			bytes_4[2] = bytes[cp + 2];
			bytes_4[3] = bytes[cp + 3];

			for (int i = 0; i < 4; i++)
				bytes_4[i] = alphabet.find(bytes_4[i]) & 0xff;

			bytes_3[0] = (bytes_4[0] << 2) + ((bytes_4[1] & 0x30) >> 4);
			bytes_3[1] = ((bytes_4[1] & 0x0f) << 4) + ((bytes_4[2] & 0x3c) >> 2);
			bytes_3[2] = ((bytes_4[2] & 0x03) << 6) + bytes_4[3];

			cp += 4;

			for (int i = 0; i < 3; i++) {
				result.push_back(bytes_3[i]);
			}
		}

		return result;
	}
}
