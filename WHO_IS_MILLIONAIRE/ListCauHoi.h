#pragma once
#include "CauHoi.h"
#include <fstream>
#include <time.h>
#include <random>
#include <string>
using namespace std;

class ListCauHoi
{
private:
	int num;
	int count = 0;
	CauHoi *arr;
public:
	ListCauHoi() { arr = new CauHoi[100]; }
	~ListCauHoi() { if (arr) delete[] arr; }
	void Add(const CauHoi& obj) {
		if (count >= 100) {
			return;
		}
		arr[count++] = obj;
	}
	void Delete(const int& ele) {
		if (ele < 0 || ele >= count) {
			return;
		}
		for (int i = ele; i < count; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
	}
	void Show() {
		for (int i = 0; i < count; i++) {
			arr[i].Show();
		}
	}
	void Get_Cau_Hoi() {
		if (count != 0) {
			srand(time(NULL));
			num = rand() % count + 0;
			arr[num].Show();
		}
	}
	CauHoi Get_CauHoi() {
		return arr[num];
	}
	int Get_Pos() {
		return num;
	}
	void Input() {
		string cauhoi, a, b, c, d; int da;
		try {
			ifstream ifs("Data.txt", ios::in);
			if (ifs.good()) {
				while (!ifs.eof()) {
					string str;
					getline(ifs, cauhoi);
					getline(ifs, a);
					getline(ifs, b);
					getline(ifs, c);
					getline(ifs, d);
					getline(ifs, str);
					da = stoi(str);
					ifs >> ws;
					Add({ cauhoi, a, b, c, d, da });
				}
			}
			else {
				cout << "File does not exist!";
				return;
			}
			
		}
		catch (exception e) {
			cout << "Error";
			return;
		}
	}
};

