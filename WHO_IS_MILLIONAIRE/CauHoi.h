#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

#pragma once
class CauHoi
{
private:
	string cauhoi;
	string cauA;
	string cauB;
	string cauC;
	string cauD;
	int dapAn;
public:
	CauHoi() { }
	CauHoi(const string& c, const string& ca, const string& cb, const string& cc, const string& cd) {
		cauhoi = c;
		cauA = ca;
		cauB = cb;
		cauC = cc;
		cauD = cd;
	}
	CauHoi(const string& c, const string& ca, const string& cb, const string& cc, const string& cd, const int& da) {
		cauhoi = c;
		cauA = ca;
		cauB = cb;
		cauC = cc;
		cauD = cd;
		dapAn = da;
	}
	void Show() {
		cout << "\n\n\n";
		printf( " %s\n\n\n", cauhoi.c_str());
	
		cout << "|==============================================================|\n";
		printf ("| 1.%-27s|| 2.%-27s|\n", cauA.c_str(), cauB.c_str());
		cout << "|==============================================================|\n";
		cout << "|==============================================================|\n";
		printf ("| 3.%-27s|| 4.%-27s|\n", cauC.c_str(), cauD.c_str());
		cout << "|==============================================================|\n";
	}

	string getCauHoi() const { return cauhoi; }
	string getA() const { return cauA; }
	string getB() const { return cauB; }
	string getC() const { return cauC; }
	string getD() const { return cauD; }
	int getDA() const { return dapAn; }
};

