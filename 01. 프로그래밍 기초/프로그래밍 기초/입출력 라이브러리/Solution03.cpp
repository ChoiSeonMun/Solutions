#ifdef SOLUTION_03
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string_view>

int main()
{
	const std::string_view names[] = {
		"이민준", "김서준", "최도윤", "갈예준"
	};
	const int ages[] = {
		31, 28, 25, 28
	};
	
	int strSize = 1000;
	char* str = new char[strSize];
	memset(str, 0, strSize);
	
	int writtenByte = std::sprintf(str, "printf() 쓴 버전\n");
	writtenByte += std::sprintf(str + writtenByte, "---------------------------\n");
	writtenByte += std::sprintf(str + writtenByte, "|%-12s|%12s|\n", "Name", "Age");
	writtenByte += std::sprintf(str + writtenByte, "---------------------------\n");
	for (int i = 0; i < 4; ++i)
	{
		writtenByte += std::sprintf(str + writtenByte, "|%-12s|%12d|\n", names[i].data(), ages[i]);
	}
	std::sprintf(str + writtenByte, "---------------------------\n");
	std::printf("%s", str);
	delete[] str;

	std::stringstream ss;
	ss << "std::cout 쓴 버전\n";
	ss << "---------------------------\n";
	ss << "|" << std::setw(12) << std::left << "Name" << "|" << std::setw(12) << std::right << "Age" << "|\n";
	ss << "---------------------------\n";
	for (int i = 0; i < 4; ++i)
	{
		ss << "|" << std::setw(12) << std::left << names[i] << "|" << std::setw(12) << std::right << ages[i] << "|\n";
	}
	ss << "---------------------------\n";
	std::cout << ss.str() << "\n";

	return 0;
}
#endif