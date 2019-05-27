#pragma once
#include "ListCauHoi.h"
#include <Windows.h>
#include <thread>
#include <random>
#include <conio.h>
#include <algorithm>
#include "csl.h"
#include <vector>
using namespace std;
//enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER, BACK };
//TRANGTHAI key(int z)
//{
//	if (z == 224)
//	{
//		char c;
//		c = _getch();
//		if (c == 72) { return UP; }
//		if (c == 80) return DOWN;
//		if (c == 77) return RIGHT;
//		if (c == 75) return LEFT;
//	}
//	else if (z == 13) return ENTER;
//}


class Menu {
private:
	ListCauHoi list;
	bool canUsed1 = true, canUsed2=true, canUsed3=true; //biến cho biết sự trợ giúp có khả dụng
public:
	Menu() {
		list.Input();
	}
	void Menu_Chinh() {
		
		resizeConsole(675, 650);
		SetConsoleTitle("AI LA TRIEU PHU 2019 - DEVELOPED BY </ZIP> AND PORNHUB");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		system("color 70");
		int chon ;
		
		bool running = true;
		while (running) {
			canUsed1 = true, canUsed2 = true, canUsed3 = true;

MenuChinh:
			system("cls");
			cout << "\n\n\n";
			cout << "|========================@====================@=================@==============|\n";
			cout << "|\\        /|    |/===\\   | |---  |\\  /| | |   | /===\\|\\  |  /\\  |/===/=== /==\\ |\n";
			cout << "| \\  /\\  / |====||   |   | |--|  | \\/ | | |   | |   || \\ | /==\\ ||   |===    / |\n";
			cout << "|  \\/  \\/  |    |\\===/   | ___|  |    | | |__ | \\===/|  \\|/    \\||   |___   0  |\n";
			cout << "|==============================================================================|\n\n\n";
			cout << "|==============================================================================|\n";
			cout << "|                               1. START                                       |\n";
			cout << "|==============================================================================|\n";
			cout << "|==============================================================================|\n";
			cout << "|                               2. HIGH SCORE                                  |\n";
			cout << "|==============================================================================|\n";
			cout << "|==============================================================================|\n";
			cout << "|                               3. ABOUT US                                    |\n";
			cout << "|==============================================================================|\n";
			cout << "|==============================================================================|\n";
			cout << "|                               4. EXIT                                        |\n";
			cout << "|==============================================================================|\n";

			// dieu khien
			/*int tt = 0;
			int *mau = new int[2];
			while (1) {		
				for (int i = 0; i < 3; i++) {
					gotoxy(9 + 3 * i);
					textcolor(12);
				}
				textcolor(14);
				
				int z = _getch();
				TRANGTHAI trangthai = key(z);
				switch (trangthai) {
				case UP: {
					tt--;
					if (tt < 0) tt = 2;
					break;
				}
				case DOWN: {
					tt++;
					if (tt > 2) tt = 0;
					break;
				}
				case ENTER: {
					system("cls");
					if (tt = 0) {
						cout << "\n\nNhập tên Người chơi  ";
						cin >> playerName; cin.ignore();

						system("cls");
						tienThuong();

						Run();
						break;
					}
					if (tt = 1) {
						while (!_kbhit) {
							cout << "DEVELOPED BY </ZIP> AND PORNHUB 2019";
							cout << "\n\n Nhan phim bat ki de quay lai";
						}
						Menu_Chinh();
					}
				}

				}
				for (int i = 0; i < 3; i++) {
					mau[i] = 12;
					mau[tt] = 14;
				}
			}	*/
			cout << "\nLựa chọn: "; cin >> chon;
			switch (chon) {
			case 1: {
				system("cls");
				cout << "\n\nNhập tên Người chơi:  ";
				cin.ignore(); getline(cin, g_playerName);

				cout << endl;
				char str1[100]= "NẾU BẠN TRẢ LỜI ĐÚNG BẠN SẼ NGHE THẤY 2 TIẾNG: ";
				char str2[100]= "NẾU BẠN TRẢ LỜI SAI  BẠN SẼ NGHE THẤY 2 TIẾNG: ";
				for (int i = 0; i < strlen(str1); i++)
				{
					printf("%c", str1[i]);
					Sleep(50);
				}
				BeepTrue();
				cout << "\n\n";
				for (int i = 0; i < strlen(str2); i++)
				{
					printf("%c", str2[i]);
					Sleep(50);
				}
				BeepFalse();

				system("cls");
				TienThuong();

				Run();
				break;
			}
			case 2: {
				//to do
				cin.get();
				break;
			}
			case 3: {
				system("cls");
				cout << "\n\n\t AI LA TRIEU PHU 2019 - DEVELOPED BY </ZIP> AND PORNHUB";
				cout << "\n\n\t Copyright © 2018 all rights reserved";
				_getch();
				break;
			}
			case 4: {
				running = false;
				system("cls");
				cout << "\n\tNhan Enter de thoat chuong trinh.";
				break;
			}
			}
		}
	}
private:
	void resizeConsole(int width, int height)
	{
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, width, height, TRUE);
	}
	void Run() {
		system("color 70");
		bool running = true;
		int count = 1;
		
		while (running) {
			int ans = 0;
			system("cls");
			if (count ==1){
				printf("\nCHÀO MỪNG \033[1;31m%s\033[0m ĐẾN VỚI CHƯƠNG TRÌNH AI LÀ TRIỆU PHÚ!!!^^", g_playerName.c_str());
			}
			else {
				printf("\nSố tiền hiện tại của \033[1;31m%s\033[0m khi bạn vượt qua câu số %d là %s,000 đồng", g_playerName.c_str(), count - 1, g_tienThuong[count - 2].c_str());
			}
			
			cout << "\n\n\nCâu " << count<< ":";
			list.Get_Cau_Hoi();
TraLoi:
			do {
				
				cout << "\nChọn 1->4 để đưa ra đáp án(Nhấn 0 để chuyển sang quyền trợ giúp):   ";
				cin >> ans;
			} while (!(ans >= 0 && ans <= 4));

			cout << endl;
			if (ans == 0) {
				Beep(3000, 200);
				Beep(00, 1100);
				TroGiup();
				goto TraLoi;
			}
			if (ans == list.Get_CauHoi().getDA()) {
				cout << "Well done!!! <3" << endl;
				BeepTrue();
				
				Sleep(1000);
				list.Delete(list.Get_Pos());
				cin.get();
			}
			else {
				BeepFalse();
				cout << "\n Bạn đã trả lời sai. Đáp án đúng là " << list.Get_CauHoi().getDA();
				cout << "\n\n Cảm ơn bạn đã tham gia chương trình.\n Bạn sẽ ra về với số tiền thưởng là " << g_tienThuong[count - 2] <<",000 đồng";
				cout << "\n Chúc bạn luôn luôn nỗ lực đạt được thành công trong cuộc sống";

				running = false;
				int control = 0;
				while (control != 13)
					control = _getch();
			}
			
			if (count == 3) {
				system("cls");
				cout << "\n\n Chúc mừng bạn đã vượt qua 15 câu hỏi của chương trình \033[1;31mAI LÀ TRIỆU PHÚ 2019\033[0m.";
				cout << "\n\n Bạn sẽ ra về với số tiền thưởng là \033[1;31m 150,000,000 \033[0m đồng.\n\n Chúc bạn luôn luôn nỗ lực đạt được thành công trong cuộc sống.";
				cin.get();
				running = false;
			}

			count++;
		}
	}
	void TroGiup()
	{
		//Beep(3000, 200);
		int troGiup;
MenuTroGiup:
		cout << "\n";
		cout << "\t\t|=====================================|\n";
		cout << "\t\t| 1.  GỌI ĐIỆN THOẠI CHO NGƯỜI THÂN   |\n";
		cout << "\t\t|=====================================|\n";
		cout << "\t\t|=====================================|\n";
		cout << "\t\t| 2.  50/50                           |\n";
		cout << "\t\t|=====================================|\n";
		cout << "\t\t|=====================================|\n";
		cout << "\t\t| 3.  HỎI Ý KIẾN KHÁN GIẢ             |\n";
		cout << "\t\t|=====================================|\n";
		cout << "\t\t|=====================================|\n";
		cout << "\t\t| 4.  QUAY LẠI                        |\n";
		cout << "\t\t|=====================================|\n";

		std::vector<int> tempList{ 1,2,3,4 }; // list luu STT cua dap an (chi su dung trong phan tro giup)
		
		int value = list.Get_CauHoi().getDA();
		cout << "\nChọn quyền trợ giúp: "; cin >> troGiup;
		switch (troGiup) {
		case 1: {
			if (canUsed1 == false) { 
				cout << "Quyền trợ giúp thứ nhất đã được sử dụng.\n"; 
				goto MenuTroGiup; 
			}
			cout << "\nNguời thân gợi ý cho bạn đáp án câu hỏi là " << list.Get_CauHoi().getDA() << endl;
			canUsed1 = false;
			break;
		}
		case 2: {
			if (canUsed2 == false) {
				cout << "Quyền trợ giúp thứ hai đã được sử dụng.\n";
				goto MenuTroGiup;
			}

			cout << "\nMáy tính đang bỏ đi 2 phương án sai...\n"; Sleep(1000);

			// LOẠI BỎ ĐÁP ÁN ĐÚNG VÀ MỘT ĐÁP ÁN BẤT KÌ CÒN LẠI
			for (int i = 0; i < 2; i++) {
				tempList.erase(std::remove(tempList.begin(), tempList.end(), value), tempList.end());
				int index = rand() % tempList.size();
				value = tempList[index];
			}
			cout << tempList[0] << " và " << tempList[1] << " là hai phương án sai.\n";
			canUsed2 = false;
			break;
		}
		case 3: {
			if (canUsed3 == false) {
				cout << "Quyền trợ giúp thứ ba đã được sử dụng.\n";
				goto MenuTroGiup;
			}

			cout << "\nĐáp án " << value << ": 55%";
			tempList.erase(std::remove(tempList.begin(), tempList.end(), value), tempList.end());
			int percent = 20;
			for (auto phantu : tempList) {
				cout << "\nĐáp án " << phantu << ": " << percent << "%";
				percent -= 5;
			}
			cout << endl;
			canUsed3 = false;
		}
		case 4: {
			break;
		}
		}
	}
	void TienThuong()
	{
		cout << endl;
		cout << "\t\t\t|===============================|\n"; textcolor(12);
		cout << "\t\t\t|     SỐ TIỀN QUA MỖI CÂU HỎI   |\n"; textcolor(0);
		cout << "\t\t\t|===============================|\n\n";
		cout << "\t\t\t|===============================|\n"; textcolor(12);
		cout << "\t\t\t|   Cau 15: 150,000,000 đồng    |\n"; textcolor(0);
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 14: 85,000,000  đồng    |\n";
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 13: 60,000,000  đồng    |\n";
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 12: 40,000,000  đồng    |\n";
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 11: 30,000,000  đồng    |\n";
		cout << "\t\t\t|===============================|\n"; textcolor(12);
		cout << "\t\t\t|   Cau 10: 22,000,000  đồng    |\n"; textcolor(0);
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 9:  14,000,000  đồng    |\n";
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 8:  10,000,000  đồng    |\n";
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 7:  6,000,000   đồng    |\n";
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 6:  3,000,000   đồng    |\n";
		cout << "\t\t\t|===============================|\n"; textcolor(12);
		cout << "\t\t\t|   Cau 5:  2,000,000   đồng    |\n"; textcolor(0);
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 4:  1,000,000   đồng    |\n";
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 3:  600,000     đồng    |\n";
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 2:  400,000     đồng    |\n";
		cout << "\t\t\t|===============================|\n";
		cout << "\t\t\t|   Cau 1:  200,000     đồng    |\n";
		cout << "\t\t\t|===============================|\n";

		cout << "Nhan Enter de bat dau.";
		cin.get();
	}
};

