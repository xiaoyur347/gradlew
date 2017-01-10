#include <string>
#include <stdio.h>
#include "uint128.h"
#include "md5.h"

std::string to_base36(uint128_t val)
{
	static std::string base36 = "0123456789abcdefghijklmnopqrstuvwxyz";
	std::string result;
	result.reserve(100);
	do {
		uint128_t t(val);
		t %= 36;
		result = base36[t.to_integer()] + result;
		val /= 36;
	} while (val.to_integer());
	return result;
}

int main(int argc, char* argv[])
{
	std::string strUrl = argv[1];
	MD5 md5(strUrl);
	std::string str = md5.hexdigest();
	str.insert(0, "0x");
	uint128_t val(str);
	printf("%s\n", to_base36(val).c_str());
	return 0;
}
