#include <iostream>
#include <windows.h>
#include <cstdio>
#include<Windows.h>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
#pragma warning(disable:4996)

int period = 25;

void addTomato() {
	int count;
	ifstream infile;
	ofstream outfile;

	infile.open("f:/cppfiles/clock/project1/num_tomato.txt", ios::in);
	infile >> count;
	infile.close();

	count += 1;
	cout <<"\n本日已栽培番茄："<< count; 

	outfile.open("f:/cppfiles/clock/project1/num_tomato.txt", ios::out);
	outfile << count;
	outfile.close();
}

void checkDay() {
	time_t now = time(NULL);
	struct tm* ltm = localtime(&now);
	int day;
	day = ltm->tm_wday;

	ifstream infile;
	ofstream outfile;

	int last_day;
	infile.open("f:/cppfiles/clock/project1/num_weekday.txt", ios::in);
	infile >> last_day;
	infile.close();

	if (last_day != day) {
		std::cout << "\n新一天开始了，要元气满满！" << std::endl;

		outfile.open("f:/cppfiles/clock/project1/num_weekday.txt", ios::out);
		outfile << day;
		outfile.close();

		outfile.open("f:/cppfiles/clock/project1/num_tomato.txt", ios::out);
		outfile << 0;
		outfile.close();
	}
	
}

int main()
{
	char flag;
	std::cout << "***************************" << std::endl;
	std::cout << "**********番茄时间**********" << std::endl;
	std::cout << "***************************"<<std::endl;
	
	checkDay();
	
	std::cout << "\n按Enter键以开始培育番茄..." << std::endl;
	flag = getchar();

	while(true)
	{
		system("cls");
		std::cout << "\n\n番茄栽培中..." << std::endl;

		Sleep(period);

		system("cls");
		MessageBox(NULL, "番茄时间 完成!", "消息", MB_ICONASTERISK);
		addTomato();
		std::cout << "\n\n按Enter继续播种新的番茄..." << std::endl;
		
		flag = getchar();
	}

	return 0;
}