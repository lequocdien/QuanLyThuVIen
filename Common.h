#ifndef _common_h_
#define _common_h_
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#define Enter 13
const int WHITE=15;
#define PASSWORD "abcdef"
#define FONTSIZE 20
#define BACK_COLOR_DEFAULT 7
#define FORCE_COLOR_DEFAULT 10
#define BACK_COLOR_HEADER 1
#define FORCE_COLOR_HEADER 14
#define BACK_COLOR_HEADER2 7
#define FORCE_COLOR_HEADER2 4
#define BACK_COLOR_MESSAGE 4
#define FORCE_COLOR_MESSAGE 14
#define BACK_COLOR_INFO 14
#define FORCE_COLOR_INFO 9
using namespace std;

void gotoxy(short x,short y){
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

int wherex( void ){
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void ){
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}

void clreol( ) {
	COORD coord;
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = info.dwCursorPosition.X;
	coord.Y = info.dwCursorPosition.Y;
	FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
	  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
	gotoxy (info.dwCursorPosition.X + 1, info.dwCursorPosition.Y + 1);
}

void SetColor(WORD color){
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void SetBGColor(WORD color){
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void SetFontSize(int fontSize){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                  			// Width of each character in the font
	cfi.dwFontSize.Y = fontSize;                	// Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

char* Pwd () {
     char S[40]; int i=0;
     while ((S[i]= getch()) != Enter ) 
     { 
	 	printf ("%c", '*') ; i++ ; 
     }
     S[i]='\0';
     return S;
}

int CheckPwd () {
    int dem =0; 
    for ( dem = 1 ; dem <=3 ; dem++)
    { 
		printf( "Password :"); 
     	if (strcmp(Pwd(),PASSWORD) == 0)   return 1;     /* Ham so sanh chuoi: strcmp(const char *str1, const char *str2) trong thu vien <string.h>  */
      	else printf ( "\nPassword sai. Hay nhap lai\n")  ; 
    }
    return 0;  
}

void VietDungChuan(char* s){
	
}


void Chaychu (int x, int y){
	char a[42] = "--QUAN LY THU VIEN-- --QUAN LY THU VIEN--", b[20];
	for(int i = 0; i<strlen(a); i++)
	{
		strncpy(b, a+i, 20);
		b[20]='\0';
		Sleep(300);
		gotoxy(x-9, 3); cout<<b; gotoxy(x, y);
		if(i == 20) i = 0;
		if(kbhit())
		{
			SetColor(12);
			gotoxy(x-9, 3); cout<<"--QUAN LY THU VIEN--"; gotoxy(x, y);
			break;
		}
	}
}

void BackForce_Color_Default(){
	SetFontSize(FONTSIZE);
	SetBGColor(BACK_COLOR_DEFAULT);
	SetColor(FORCE_COLOR_DEFAULT);
}

void BackForce_Color_Header(){
	SetFontSize(FONTSIZE);
	SetBGColor(BACK_COLOR_HEADER);
	SetColor(FORCE_COLOR_HEADER);
}

void BackForce_Color_Header2(){
	SetFontSize(FONTSIZE);
	SetBGColor(BACK_COLOR_HEADER2);
	SetColor(FORCE_COLOR_HEADER2);
}

void BackForce_Color_Message(){
	SetFontSize(FONTSIZE);
	SetBGColor(BACK_COLOR_MESSAGE);
	SetColor(FORCE_COLOR_MESSAGE);
}

void BackForce_Color_Info(){
	SetFontSize(FONTSIZE);
	SetBGColor(BACK_COLOR_INFO);
	SetColor(FORCE_COLOR_INFO);
}
// Ve hinh chu nhat rong bat dau tu (x1, y1) den (x2, y2)
void VeBang(int x1, int y1, int x2, int y2){
	//Ve canh tren
	gotoxy(x1, y1); cout<<(char)218;
	for(int i = x1 + 1; i < x2; i++){
		cout<<(char)196;
	}
	cout<<(char)191;
	//Ve canh duoi
	gotoxy(x1, y2); cout<<(char)192;
	for(int i = x1 + 1; i < x2; i++){
		cout<<(char)196;
	}
	cout<<(char)217;
	//Ve canh trai va phai
	for(int i = y1 + 1; i < y2; i++){
		gotoxy(x1, i); cout<<(char)179;		//Ve canh trai
		gotoxy(x2, i); cout<<(char)179;		//Ve canh phai
	}
	gotoxy(x2, y2);
}

void XoaBang(int x1, int y1, int x2, int y2){
	//Xoa canh tren
	gotoxy(x1, y1); cout<<" ";
	for(int i = x1 + 1; i < x2; i++){
		cout<<" ";
	}
	cout<<(char)191;
	//Xoa canh duoi
	gotoxy(x1, y2); cout<<" ";
	for(int i = x1 + 1; i < x2; i++){
		cout<<" ";
	}
	cout<<(char)217;
	//Xoa canh trai va phai
	for(int i = y1 + 1; i < y2; i++){
		gotoxy(x1, i); cout<<" ";		//Ve canh trai
		gotoxy(x2, i); cout<<" ";		//Ve canh phai
	}
	gotoxy(x2, y2);
}

void NoiBang(int x1, int y1, int x2, int y2){
	//Xoa canh duoi cua bang cu
	for(int i = x1; i<= x2; i++){
		gotoxy(i, y1); cout<<" ";
	}
	gotoxy(x1, y2); cout<<(char)192;
	gotoxy(x2, y2); cout<<(char)217;
	for(int i = y1 ; i < y2; i++){
		gotoxy(x1, i); cout<<(char)179;
		gotoxy(x2, i); cout<<(char)179;
	}
	for(int i = x1 + 1; i < x2; i++){
		gotoxy(i, y2); cout<<(char)196;
	}
	
}

void VeDuongDoc(int x1, int y1, int x2, int y2){
	gotoxy(x1, y1); cout<<(char)194;
	gotoxy(x2, y2); cout<<(char)193;
	for(int i = y1 + 1; i < y2; i++){
		gotoxy(x1, i); cout<<(char)179;	
	}
}

void VeDuongNgang(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int y){
	if (x8 == -1 && x1 != -1 && x2 != -1 && x3 != -1 && x4 != -1 && x5 != -1 && x6 != -1 && x7 != -1){
		gotoxy(x1, y); cout<<(char)195;
		gotoxy(x7, y); cout<<(char)180;
		for(int i = x1 + 1; i < x7; i++){
			if(i == x2 || i == x3 || i == x4 || i == x5 || i == x6){
				gotoxy(i, y); cout<<(char)197;
			}
			else{
				gotoxy(i, y); cout<<(char)196;
			}
		}
	}
	else if (x7 == -1 && x8 == -1 && x1 != -1 && x2 != -1 && x3 != -1 && x4 != -1 && x5 != -1 && x6 != -1){
		gotoxy(x1, y); cout<<(char)195;
		gotoxy(x6, y); cout<<(char)180;
		for(int i = x1 + 1; i < x6; i++){
			if(i == x2 || i == x3 || i == x4 || i == x5){
				gotoxy(i, y); cout<<(char)197;
			}
			else{
				gotoxy(i, y); cout<<(char)196;
			}
		}
	}
	else if (x6 == -1 && x7 == -1 && x8 == -1 && x1 != -1 && x2 != -1 && x3 != -1 && x4 != -1 && x5 != -1){
		gotoxy(x1, y); cout<<(char)195;
		gotoxy(x5, y); cout<<(char)180;
		for(int i = x1 + 1; i < x5; i++){
			if(i == x2 || i == x3 || i == x4){
				gotoxy(i, y); cout<<(char)197;
			}
			else{
				gotoxy(i, y); cout<<(char)196;
			}
		}
	}
	else if(x5 == -1 && x6 == -1 && x7 == -1 && x8 == -1 && x1 != -1 && x2 != -1 && x3 != -1 && x4 != -1){
		gotoxy(x1, y); cout<<(char)195;
		gotoxy(x4, y); cout<<(char)180;
		for(int i = x1 + 1; i < x4; i++){
			if(i == x2 || i == x3){
				gotoxy(i, y); cout<<(char)197;
			}
			else{
				gotoxy(i, y); cout<<(char)196;
			}
		}
	}
	else if(x3 == -1 && x4 == -1 && x5 == -1 && x6 == -1 && x7 == -1 && x8 == -1 && x1 != -1 && x2 != -1){
		gotoxy(x1, y); cout<<(char)195;
		gotoxy(x2, y); cout<<(char)180;
		for(int i = x1 + 1; i < x2; i++){
			gotoxy(i, y); cout<<(char)196;
		}
	}
	else if(x1 != -1 && x2 != -1 && x3 != -1 && x4 != -1 && x5 != -1 && x6 != -1 && x7 != -1 && x8 != -1){
		gotoxy(x1, y); cout<<(char)195;
		gotoxy(x8, y); cout<<(char)180;
		for(int i = x1 + 1; i < x8; i++){
			if(i == x2 || i == x3 || i == x4 || i == x5 || i == x6 || i == x7){
				gotoxy(i, y); cout<<(char)197;
			}
			else{
				gotoxy(i, y); cout<<(char)196;
			}
		}
	}
}

void ThemDuongDoc(int x1, int x2, int x3){
	
}

void ShowEscEnter(){
	int wx = wherex();
	int wy = wherey();
	BackForce_Color_Message();
	VeBang(40, 10, 80, 12);
	gotoxy(41, 11); cout<<"      ESC: THOAT || ENTER: TIEP TUC    ";
	BackForce_Color_Default();
	gotoxy(wx, wy);
}

void ShowMessage(int x1, int y1, int x2, int y2, string message){
	int wx = wherex();
	int wy = wherey();
	BackForce_Color_Message();
	VeBang(x1, y1, x2, y2);
	gotoxy(x1 + 1, (y2 + y1)/2); cout<<message;
	BackForce_Color_Default();
	gotoxy(wx, wy);
}

void HideMessage(int x, int y){
	int wx = wherex();
	int wy = wherey();
	BackForce_Color_Default();
	gotoxy(x, y); 	cout<<"                                                          ";
	gotoxy(x, y+1); cout<<"                                                          ";
	gotoxy(x, y+2); cout<<"                                                          ";
	gotoxy(wx, wy);
}

#endif


