#ifdef SOLUTION_01
#include <iostream>
#include <iomanip>
#include <string_view>

int main()
{
	const std::string_view names[] = {
		"�̹���", "�輭��", "�ֵ���", "������"
	};
	const int ages[] = {
		31, 28, 25, 28
	};

	printf("printf() �� ����\n");
	printf("---------------------------\n");
	printf("|%-12s|%12s|\n", "Name", "Age");
	printf("---------------------------\n");
	for (int i = 0; i < 4; ++i)
	{
		printf("|%-12s|%12d|\n", names[i].data(), ages[i]);
	}
	printf("---------------------------\n");

	std::cout << "std::cout �� ����\n";
	std::cout << "---------------------------\n";
	std::cout << "|" << std::setw(12) << std::left << "Name" << "|" << std::setw(12) << std::right << "Age" << "|\n";
	std::cout << "---------------------------\n";
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "|" << std::setw(12) << std::left << names[i] << "|" << std::setw(12) << std::right << ages[i] << "|\n";
	}
	std::cout << "---------------------------\n";

	return 0;
}
#endif