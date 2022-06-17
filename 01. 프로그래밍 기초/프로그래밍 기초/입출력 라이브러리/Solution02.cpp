#ifdef SOLUTION_02
#include <iostream>
#include <fstream>
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

	FILE* fp = NULL;
	fopen_s(&fp, "temp.txt", "w");

	fprintf(fp, "printf() 쓴 버전\n");
	fprintf(fp, "---------------------------\n");
	fprintf(fp, "|%-12s|%12s|\n", "Name", "Age");
	fprintf(fp, "---------------------------\n");
	for (int i = 0; i < 4; ++i)
	{
		fprintf(fp, "|%-12s|%12d|\n", names[i].data(), ages[i]);
	}
	fprintf(fp, "---------------------------\n");

	fclose(fp);

	std::ofstream ofs("temp.txt", std::ios::app); // 이어서 쓰기 위해 append 모드 전달. 파일 끝에 이어서 출력한다.
	ofs << "std::cout 쓴 버전\n";
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