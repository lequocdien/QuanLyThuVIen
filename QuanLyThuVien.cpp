#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <math.h>
#include "ClassObject.h"
#include "DauSach.h"
#include "Sach.h"
#include "DocGia.h"
#include "MuonTraSach.h"
#include "Common.h"
#define TOADO_MESSAGE_X 31
#define TOADO_MESSAGE_Y 10
using namespace std;


int Menu (LISTDAUSACH &ds, TREE* &root)
{
	int luachon;
	while (1)
	{
		system("cls");
		BackForce_Color_Header2();
		VeBang(40, 2, 79, 4);
		BackForce_Color_Default();
		gotoxy(40, 5);  cout<<(" ______________________________________ ");
		gotoxy(40, 6);  cout<<("|                                      |");
		gotoxy(40, 7);  cout<<("|                MENU                  |");
		gotoxy(40, 8);  cout<<("|______________________________________|");
		gotoxy(40, 9);  cout<<("|                                      |");
		gotoxy(40, 10); cout<<("|   1. Them dau sach                   |");
		gotoxy(40, 11); cout<<("|                                      |");
		gotoxy(40, 12); cout<<("|   2. Them sach                       |");
		gotoxy(40, 13); cout<<("|                                      |");
		gotoxy(40, 14); cout<<("|   3. Tim thong tin sach              |");
		gotoxy(40, 15); cout<<("|                                      |");
		gotoxy(40, 16); cout<<("|   4. In danh sach nhung dau sach     |");
		gotoxy(40, 17); cout<<("|                                      |");
		gotoxy(40, 18); cout<<("|   5. Quan ly doc gia                 |");
		gotoxy(40, 19); cout<<("|                                      |");
		gotoxy(40, 20); cout<<("|   6. Muon tra sach                   |");
		gotoxy(40, 21); cout<<("|                                      |");
		gotoxy(40, 22); cout<<("|   0. Thoat                           |");
		gotoxy(40, 23); cout<<("|                                      |");
		gotoxy(40, 24); cout<<("|            Chon |   |                |");
		gotoxy(40, 25); cout<<("|______________________________________|");
		gotoxy(60, 24);
		Chaychu(wherex(), wherey());
		BackForce_Color_Default();
		char *lc = new char[2];
		do
		{
			*lc = getch();
			if(48 <= *lc && *lc <= 57)
			{
				*(lc+1) = '\0';
				luachon = atoi(lc);
				break;
			}
		}
		while(1);
		
		delete []lc;
		gotoxy(60, 24); cout<<luachon;
		Sleep(100);
		if ( 0 > luachon || luachon > 6)
		{
//			SetColor(0); SetBGColor(13);
//			gotoxy(40, 27); cout<<"    Ban nhap sai. Vui long nhap lai!!   ";
//			BackForce_Color_Default();
//			cout<<endl;
//			system ("pause");
		}
		if (luachon == 0)
		{
//			for(int i = ds.n - 1; i >= 0; i--)
//			{
//				DeleteAll ((*ds.nodes[i]).FirstSach, root);
//				delete [] ds.nodes[i];
//				
//			}
			gotoxy(45, 45); cout<<"    !!!!!!GOODBYE!!!!!!   ";
			gotoxy(40, 60);
			break;
		}
		
		else if (luachon == 1)
		{
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
			BackForce_Color_Default();
			gotoxy(0, 7);
			
			MenuNhapDauSach(ds);
			system("pause");
		}
		else if (luachon == 2)
		{
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
			BackForce_Color_Default();
			gotoxy(0, 7);
	
			MenuNhapSach(ds);
			system("pause");
			
		}
		else if (luachon == 3)																		/*Sai o phan tim kiem roi in ra lai??*/
		{
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
			BackForce_Color_Default();
			gotoxy(0, 7);
	
			MenuTimThongTinSach(ds);
			system("pause");
		}
		else if (luachon == 4)
		{
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
			BackForce_Color_Default();
			gotoxy(0, 7);
			
			MenuInDauSach(ds);
			system("pause");
		}
		else if (luachon == 5)
		{
			MenuDocGia(ds, root);
		}
		else if (luachon == 6)
		{
			MenuMuonTra(ds, root);
		}
	}
}

int main ()
{
//	resizeConsole(1200, 680);
//	SetColor(10);
	BackForce_Color_Default();
	LISTDAUSACH dausach;
	TREE* root;
	KhoiTaoTree (root);
	Menu(dausach, root);
	return 0;
}



