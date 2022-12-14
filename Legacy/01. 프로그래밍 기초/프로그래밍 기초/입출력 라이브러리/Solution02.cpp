#ifdef SOLUTION_02
#include <iostream>
#include <fstream>
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

	FILE* fp = NULL;
	fopen_s(&fp, "temp.txt", "w");

	fprintf(fp, "printf() �� ����\n");
	fprintf(fp, "---------------------------\n");
	fprintf(fp, "|%-12s|%12s|\n", "Name", "Age");
	fprintf(fp, "---------------------------\n");
	for (int i = 0; i < 4; ++i)
	{
		fprintf(fp, "|%-12s|%12d|\n", names[i].data(), ages[i]);
	}
	fprintf(fp, "---------------------------\n");

	fclose(fp);

	std::ofstream ofs("temp.txt", std::ios::app); // �̾ ���� ���� append ��� ����. ���� ���� �̾ ����Ѵ�.
	ofs << "std::cout �� ����\n";
	ofs << "---------------------------\n";
	ofs << "|" << std::setw(12) << std::left << "Name" << "|" << std::setw(12) << std::right << "Age" << "|\n";
	ofs << "---------------------------\n";
	for (int i = 0; i < 4; ++i)
	{
		ofs << "|" << std::setw(12) << std::left << names[i] << "|" << std::setw(12) << std::right << ages[i] << "|\n";
	}
	ofs << "---------------------------\n";

	return 0;
}
#endif