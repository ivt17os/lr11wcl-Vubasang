#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>


using namespace std;

int main(int argc, char** argv ) {
    long long t1, t2, freq, nlines =0,nread, k=0;
	char str[4096];
	
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	
	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
	
	FILE* f = fopen("a.txt", "rb"); 
	
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// ����������� ����� ����� � 1 ���


	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// ������� ����� ����� ��������� �����
	while (!feof(f)){
		nread = fread(str, 1, 4096, f);
		for ( int i = 0; i < nread; i++){
			if(str[i] == '\n') k++;	
		}
	}
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// ������� ����� ����� ��������� �����

	fclose(f);
	cout.precision(3);
	cout << fixed;
	cout << "Time: " << (t2-t1)/(1.*freq) << endl;
	cout << "File a.txt has " << k <<" lines." ;
	return 0;
}