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
	cout <<"\n���������෬�ѣ�"<< count; 

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
		std::cout << "\n��һ�쿪ʼ�ˣ�ҪԪ��������" << std::endl;

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
	std::cout << "**********����ʱ��**********" << std::endl;
	std::cout << "***************************"<<std::endl;
	
	checkDay();
	
	std::cout << "\n��Enter���Կ�ʼ��������..." << std::endl;
	flag = getchar();

	while(true)
	{
		system("cls");
		std::cout << "\n\n����������..." << std::endl;

		Sleep(period);

		system("cls");
		MessageBox(NULL, "����ʱ�� ���!", "��Ϣ", MB_ICONASTERISK);
		addTomato();
		std::cout << "\n\n��Enter���������µķ���..." << std::endl;
		
		flag = getchar();
	}

	return 0;
}