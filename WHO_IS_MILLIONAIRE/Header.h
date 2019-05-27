#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

static string g_playerName;
static string g_tienThuong[15] = { "200" ,"400" ,"600" ,"1,000","2,000","3,000" ,"6,000",  "10,000" , "14,000",
		"22,000", "30,000","40,000"," 60,000", "85,000" , "150,000" };

void BeepTrue() {
	Beep(3000, 200);
	Beep(3000, 200);
	Beep(00, 1100);
}
void BeepFalse() {
	Beep(708, 300);
	Beep(708, 300);
	Beep(00, 1000);
}