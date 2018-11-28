#include <Windows.h>;
#include <string>
typedef DWORD Any;

class Convert
{
public:
	static char* StringToChar(std::string str)
	{
		char *cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		return cstr;
	}
	static char* ToString(Any value)
	{
		std::string str = std::to_string(value);
		return StringToChar(str);
	}
	static int ToInt32(char* str)
	{
		return std::stoi(str);
	}
};