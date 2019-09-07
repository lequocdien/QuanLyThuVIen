#ifndef _dausach_h_
#define _dausach_h_
//#include "ClassObject.h"
//#include "Sach.h"
#include "Common.h"
#define DAUSACH_START_X 2		//Vi tri x bat dau ve bang danh sach cac dau sach
#define DAUSACH_START_Y 14		//Vi tri y bat dau ve bang danh sach cac dau sach
#define DAUSACH_END_X 117		//Vi tri x ket thuc ve bang danh sach cac dau sach
#define DAUSACH_END_Y 21		//Vi tri y ket thuc ve bang danh sach cac dau sach
#define DAUSACH_TOADO_X_1 8
#define DAUSACH_TOADO_X_2 23
#define DAUSACH_TOADO_X_3 59
#define DAUSACH_TOADO_X_4 80
#define DAUSACH_TOADO_X_5 91
#define DAUSACH_TOADO_X_6 102

//Dung thuat toan sap xep BubbleSort
void SapXepDauSachTheoTen (LISTDAUSACH &ds){
	char ts[51], tg[21], tl[21], isbn[14], st[5],  nxb[5];
 	for (int i = 1; i<ds.n; i++)
 	{
 		for (int j = ds.n-1; j >= i; j--)
 		{
 			if (strcmp((*ds.nodes[j-1]).tensach, (*ds.nodes[j]).tensach) > 0)
 			{
 				strcpy(ts, (*ds.nodes[j-1]).tensach);
    			strcpy(isbn , (*ds.nodes[j-1]).ISBN);
   				strcpy(tg, (*ds.nodes[j-1]).tacgia);
   				strcpy(st, (*ds.nodes[j-1]).sotrang);
  				strcpy(nxb , (*ds.nodes[j-1]).namxuatban);
    			strcpy(tl, (*ds.nodes[j-1]).theloai);
    			
    			strcpy((*ds.nodes[j-1]).tensach, (*ds.nodes[j]).tensach);
    			strcpy((*ds.nodes[j-1]).ISBN , (*ds.nodes[j]).ISBN);
   				strcpy((*ds.nodes[j-1]).tacgia, (*ds.nodes[j]).tacgia);
   				strcpy((*ds.nodes[j-1]).sotrang, (*ds.nodes[j]).sotrang);
  				strcpy((*ds.nodes[j-1]).namxuatban , (*ds.nodes[j]).namxuatban);
    			strcpy((*ds.nodes[j-1]).theloai, (*ds.nodes[j]).theloai);
    			
    			strcpy((*ds.nodes[j]).tensach, ts);
    			strcpy((*ds.nodes[j]).ISBN , isbn);
   				strcpy((*ds.nodes[j]).tacgia, tg);
   				strcpy((*ds.nodes[j]).sotrang , st);
  				strcpy((*ds.nodes[j]).namxuatban , nxb);
    			strcpy((*ds.nodes[j]).theloai, tl);
    			
			 }
		 }
	}
//  	InDauSach(ds);
}

//Kiem tra ISBN co bi trung hay khong, return 0 neu trung va return 1 neu khong trung
int CheckISBN (LISTDAUSACH ds, char* isbn){
	int i = 0;
	DAUSACH dausach;
	for (i; i< ds.n; i++)
	{
		dausach = *(ds.nodes[i]);
		if(strcmp(dausach.ISBN, isbn) == 0)
		{
			return 0;
			break;
		}
		
	}
	return 1;	
}

void SetISBN(char *isbn, LISTDAUSACH ds){
	int x = wherex(), y = wherey();
	int k, i = 0;
	do
	{
		k = getch();
		HideMessage(40, 10);
		if(k == 13 || k == 8 || k == 224 || 32 <= k && k <= 126)
		{
			if(k == 13) 
			{
				isbn[i] = '\0';
			
				if (i > 13)
				{
					ShowMessage(40, 10, 80, 12, "    ISBN qua dai! ISBN 13 ky tu so     ");
					gotoxy(x, y); cout<<"              "; gotoxy(x, y);
					i = 0;
				}
				else if (i < 10 || i == 11 || i == 12)
				{
					ShowMessage(40, 10, 80, 12, "  ISBN khong hop le! ISBN 13 ky tu so  ");
					gotoxy(x, y); cout<<"              "; gotoxy(x, y);
					i = 0;
				}
				else if (CheckISBN (ds, isbn) == 0)
				{
					ShowMessage(40, 10, 80, 12, "   ISBN bi trung. Vui long nhap lai    ");
					gotoxy(x, y); cout<<"              "; gotoxy(x, y);
					i = 0;
				}
				else 
				{
					break;
				}
			}
			else if(k == 8)
			{
				int x8 = wherex();
				if(wherex() > x && wherex() <= x+i)
				{
					int j;
					for(j = wherex()-x-1; j < i-1; j++)
					{
						isbn[j] = isbn[j+1];
					}
					isbn[--i] = '\0';
					for(j = 0; j<i; j++)
					{
						gotoxy(x+j, y); cout<<isbn[j];
					}
					gotoxy(x+i, y); cout<<" "; gotoxy(x8-1, y);
				}
			}
			else if(k == 224)
			{
				k = getch();
				if(k == 75)
				{
					if(wherex() != x)
					{
						gotoxy(wherex()-1, y);
					}
				}
				else if (k == 77)
				{
					if(wherex() != x+i)
					{
						gotoxy(wherex()+1, y);
					}
				}
			}
			else if (48 <= k && k <= 57)
			{
				if(wherex() >= x && wherex() < x+i)
				{
					isbn[wherex()-x] = (char)k;
				}
				else if(wherex() < 23)
				{
					isbn[i++] = (char)k;
					cout<<(char)k;
				}
			
			}
			else
			{
				ShowMessage(40, 10, 80, 12, "        ISBN chi nhan ky tu so         ");
			}
			
		}
		
	}
	while(1);
}

void SetTenSach(char *tensach){
	int x = wherex(), y = wherey();
	int k, i = 0;
	do
	{
		k = getch();
		HideMessage(40, 10);
		if(k == 27 || k == 13 || k == 8 || k == 224 || 32 <= k && k <= 126)
		{
			if(k == 13) 
			{
				tensach[i] = '\0';
				if(i == 0)
				{
//					BackForce_Color_Message();
//					VeBang(40, 10, 80, 12);
//					gotoxy(41, 11); cout<<"     Ten sach khong duoc de trong      ";
//					gotoxy(x, y);
					
					ShowMessage(40, 10, 80, 12, "     Ten sach khong duoc de trong      ");
				}
				else
				{
					break;
				}
			}
			else if(k == 8)
			{
				int x8 = wherex();
				if(wherex() > x && wherex() <= x+i)
				{
					int j;
					for(j = wherex()-x-1; j < i-1; j++)
					{
						tensach[j] = tensach[j+1];
					}
					tensach[--i] = '\0';
					for(j = 0; j<i; j++)
					{
						gotoxy(x+j, y); cout<<tensach[j];
					}
					gotoxy(x+i, y); cout<<" "; gotoxy(x8-1, y);
				}
			}
			else if(k == 224)
			{
				k = getch();
				if(k == 75)
				{
					if(wherex() != x)
					{
						gotoxy(wherex()-1, y);
					}
				}
				else if (k == 77)
				{
					if(wherex() != x+i)
					{
						gotoxy(wherex()+1, y);
					}
				}
			}
			
			else
			{
				if(wherex() >= x && wherex() < x+i)
				{
					tensach[wherex()-x] = (char)k;
					cout<<(char)k;
				}
				else if (i != 34)
				{
					tensach[i++] = (char)k;
					cout<<(char)k;
				}
			
			}
			
		}
		
	}
	while(1);
	*tensach = toupper(*tensach);
}

//Ham nay duoc su dung de kiem tra du kieu vao cho TacGia; Ho, Ten doc gia
void SetHoTen(char *tacgia){
	int x = wherex(), y = wherey();
	int k, i = 0;
	do
	{
		k = getch();
		HideMessage(40, 10);
		if(k == 13 || k == 8 || k == 224 || 32 <= k && k <= 126)
		{
			
			if(k == 13) 
			{
				if(i == 0)
				{
					ShowMessage(40, 10, 80, 12, "           Khong duoc de trong         ");
				}
				else
				{
					tacgia[i] = '\0';
					break;
				}
			}
			else if(k == 8)
			{
				int x8 = wherex();
				if(wherex() > x && wherex() <= x+i)
				{
					int j;
					for(j = wherex()-x-1; j < i-1; j++)
					{
						tacgia[j] = tacgia[j+1];
					}
					tacgia[--i] = '\0';
					for(j = 0; j<i; j++)
					{
						gotoxy(x+j, y); cout<<tacgia[j];
					}
					gotoxy(x+i, y); cout<<" "; gotoxy(x8-1, y);
				}
			}
			else if(k == 224)
			{
				k = getch();
				if(k == 75)
				{
					if(wherex() != x)
					{
						gotoxy(wherex()-1, y);
					}
				}
				else if (k == 77)
				{
					if(wherex() != x+i)
					{
						gotoxy(wherex()+1, y);
					}
				}
			}
			else if (!( 65 <= k && k <= 90 || 97 <= k && k <= 122 || k == 32))
			{
				ShowMessage(40, 10, 80, 12, "         Ky tu nay khong hop le        ");
			}
			else
			{
				if(wherex() >= x && wherex() < x+i)
				{
					tacgia[wherex()-x] = (char)k;
					cout<<(char)k;
				}
				else if (wherex() < 80)
				{
					tacgia[i++] = (char)k;
					cout<<(char)k;
				}
			
			}
			
		}
		
	}
	while(1);
	VietDungChuan(tacgia);
}

void SetNXB(char *nxb){
	int x = wherex(), y = wherey();
	int k, i = 0;
	do
	{
		k = getch();
		HideMessage(40, 10);
		if(k == 13 || k == 8 || k == 224 || 32 <= k && k <= 126)
		{
			if(k == 13) 
			{
				if (i > 4)
				{
					ShowMessage(40, 10, 80, 12, "    Nam qua dai. Vui long nhap lai!    ");
					gotoxy(DAUSACH_TOADO_X_4 + 4, y); cout<<"       "; gotoxy(DAUSACH_TOADO_X_4 + 4, y);
					i = 0; 
				}
				else if (i < 4 ||(strcmp(nxb, "2018")) > 0)
				{
					ShowMessage(40, 10, 80, 12, " Nam khong hop le. Vui long nhap lai!  ");
					gotoxy(DAUSACH_TOADO_X_4 + 4, y); cout<<"       "; gotoxy(DAUSACH_TOADO_X_4 + 4, y);
					i = 0;
				}
				else 
				{
					nxb[i] = '\0';
					break;
				}
			}
			else if(k == 8)
			{
				int x8 = wherex();
				if(wherex() > x && wherex() <= x+i)
				{
					int j;
					for(j = wherex()-x-1; j < i-1; j++)
					{
						nxb[j] = nxb[j+1];
					}
					nxb[--i] = '\0';
					for(j = 0; j<i; j++)
					{
						gotoxy(x+j, y); cout<<nxb[j];
					}
					gotoxy(x+i, y); cout<<" "; gotoxy(x8-1, y);
				}
			}
			else if(k == 224)
			{
				k = getch();
				if(k == 75)
				{
					if(wherex() != x)
					{
						gotoxy(wherex()-1, y);
					}
				}
				else if (k == 77)
				{
					if(wherex() != x+i)
					{
						gotoxy(wherex()+1, y);
					}
				}
			}
			else if (48 <= k && k <= 57)
			{
				if(wherex() >= x && wherex() < x+i)
				{
					nxb[wherex()-x] = (char)k;
					cout<<(char)k;
				}
				else if (wherex() < 91)
				{
					nxb[i++] = (char)k;
					cout<<(char)k;
				}
			
			}
			else if (wherex() < 102)
			{
				ShowMessage(40, 10, 80, 12, "    Nam xuat ban chi nhan ky tu so     ");
			}
			
		}
		
	}
	while(1);
}

void SetSoTrang(char *st){
	int x = wherex(), y = wherey();
	int k, i = 0;
	do
	{
		k = getch();
		HideMessage(40, 10);
		if(k == 13 || k == 8 || k == 224 || 32 <= k && k <= 127)
		{
			if(k == 13) 
			{
				st[i] = '\0';
				break;
			}
			else if(k == 8)
			{
				int x8 = wherex();
				if(wherex() > x && wherex() <= x+i)
				{
					int j;
					for(j = wherex()-x-1; j < i-1; j++)
					{
						st[j] = st[j+1];
					}
					st[--i] = '\0';
					for(j = 0; j<i; j++)
					{
						gotoxy(x+j, y); cout<<st[j];
					}
					gotoxy(x+i, y); cout<<" "; gotoxy(x8-1, y);
				}
			}
			else if(k == 224)
			{
				k = getch();
				if(k == 75)
				{
					if(wherex() != x)
					{
						gotoxy(wherex()-1, y);
					}
				}
				else if (k == 77)
				{
					if(wherex() != x+i)
					{
						gotoxy(wherex()+1, y);
					}
				}
			}
			else if (48 <= k && k <= 57)
			{
				if(wherex() >= x && wherex() < x+i)
				{
					st[wherex()-x] = (char)k;
					cout<<(char)k;
				}
				else if (wherex() < 102)
				{
					st[i++] = (char)k;
					cout<<(char)k;
				}
			
			}
			else
			{
				ShowMessage(40, 10, 80, 12, "      So trang chi nhan ky tu so       ");
			}
			
		}
		
	}
	while(1);
}

void SetTheLoai (char *theloai){
	int x = wherex(), y = wherey();
	int k, i = 0;
	do
	{
		k = getch();
		HideMessage(40, 10);
		if(k == 13 || k == 8 || k == 224 || 32 <= k && k <= 126)
		{
			if(k == 13) 
			{
				theloai[i] = '\0';
				break;
			}
			else if(k == 8)
			{
				int x8 = wherex();
				if(wherex() > x && wherex() <= x+i)
				{
					int j;
					for(j = wherex()-x-1; j < i-1; j++)
					{
						theloai[j] = theloai[j+1];
					}
					theloai[--i] = '\0';
					for(j = 0; j<i; j++)
					{
						gotoxy(x+j, y); cout<<theloai[j];
					}
					gotoxy(x+i, y); cout<<" "; gotoxy(x8-1, y);
				}
			}
			else if(k == 224)
			{
				k = getch();
				if(k == 75)
				{
					if(wherex() != x)
					{
						gotoxy(wherex()-1, y);
					}
				}
				else if (k == 77)
				{
					if(wherex() != x+i)
					{
						gotoxy(wherex()+1, y);
					}
				}
			}
			
			else
			{
				if(wherex() >= x && wherex() < x+i)
				{
					theloai[wherex()-x] = (char)k;
					cout<<(char)k;
				}
				else if ( wherex() < 117)
				{
					theloai[i++] = (char)k;
					cout<<(char)k;
				}
			
			}
			
		}
		
	}
	while(1);
	*theloai = toupper(*theloai);
}

void NhapDauSach (LISTDAUSACH &ds){
	int toaDoKetThucY = DAUSACH_END_Y;	//Toa do ket thuc bang
	int viTriY;
	char *a;
	int soThuTu = 0;
	do{
		viTriY = wherey();
		DAUSACH *dausach = new DAUSACH;
		if (toaDoKetThucY - viTriY == 1 || toaDoKetThucY - viTriY == 2)     //Noi them bang
		{
			NoiBang(DAUSACH_START_X, toaDoKetThucY, DAUSACH_END_X, toaDoKetThucY + 2);
			VeDuongDoc(DAUSACH_TOADO_X_1, toaDoKetThucY, DAUSACH_TOADO_X_1, toaDoKetThucY + 2); gotoxy(DAUSACH_TOADO_X_1, toaDoKetThucY); cout<<char(179);
			VeDuongDoc(DAUSACH_TOADO_X_2, toaDoKetThucY, DAUSACH_TOADO_X_2, toaDoKetThucY + 2); gotoxy(DAUSACH_TOADO_X_2, toaDoKetThucY); cout<<char(179);
			VeDuongDoc(DAUSACH_TOADO_X_3, toaDoKetThucY, DAUSACH_TOADO_X_3, toaDoKetThucY + 2); gotoxy(DAUSACH_TOADO_X_3, toaDoKetThucY); cout<<char(179);
			VeDuongDoc(DAUSACH_TOADO_X_4, toaDoKetThucY, DAUSACH_TOADO_X_4, toaDoKetThucY + 2); gotoxy(DAUSACH_TOADO_X_4, toaDoKetThucY); cout<<char(179);
			VeDuongDoc(DAUSACH_TOADO_X_5, toaDoKetThucY, DAUSACH_TOADO_X_5, toaDoKetThucY + 2); gotoxy(DAUSACH_TOADO_X_5, toaDoKetThucY); cout<<char(179);
			VeDuongDoc(DAUSACH_TOADO_X_6, toaDoKetThucY, DAUSACH_TOADO_X_6, toaDoKetThucY + 2); gotoxy(DAUSACH_TOADO_X_6, toaDoKetThucY); cout<<char(179);
			toaDoKetThucY = toaDoKetThucY + 2 ;
		}
		
		soThuTu = soThuTu + 1;
		gotoxy(DAUSACH_START_X + 2, viTriY); cout<<soThuTu;           								//So thu tu
		gotoxy(DAUSACH_TOADO_X_1 + 1, viTriY); SetISBN((*dausach).ISBN, ds); gotoxy(DAUSACH_TOADO_X_1 + 1, viTriY); cout<<(*dausach).ISBN;   	//ISBN
		gotoxy(DAUSACH_TOADO_X_2 + 2, viTriY); SetTenSach((*dausach).tensach); gotoxy(DAUSACH_TOADO_X_2 + 2, viTriY); cout<<(*dausach).tensach; //Ten sach
		gotoxy(DAUSACH_TOADO_X_3 + 2, viTriY); SetHoTen((*dausach).tacgia); gotoxy(DAUSACH_TOADO_X_3 + 2, viTriY); cout<<(*dausach).tacgia;				//Tac gia
		gotoxy(DAUSACH_TOADO_X_4 + 4, viTriY); SetNXB((*dausach).namxuatban); gotoxy(DAUSACH_TOADO_X_4 + 4, viTriY); cout<<(*dausach).namxuatban;    //Nam xuat ban
		gotoxy(DAUSACH_TOADO_X_5 + 2, viTriY); SetSoTrang((*dausach).sotrang); gotoxy(DAUSACH_TOADO_X_5 + 2, viTriY); cout<<(*dausach).sotrang;							//So trang
		gotoxy(DAUSACH_TOADO_X_6 + 2, viTriY); SetTheLoai((*dausach).theloai); gotoxy(DAUSACH_TOADO_X_6 + 2, viTriY); cout<<(*dausach).theloai<<endl;				//The loai
		(*dausach).FirstSach = NULL;
		ds.nodes[ds.n++] = dausach;
		
		VeDuongNgang (DAUSACH_START_X, DAUSACH_TOADO_X_1, DAUSACH_TOADO_X_2, DAUSACH_TOADO_X_3, DAUSACH_TOADO_X_4, DAUSACH_TOADO_X_5, DAUSACH_TOADO_X_6, DAUSACH_END_X, viTriY + 1);		//Ve duong ngang ket thuc 1 dau sach
		
		gotoxy(4, viTriY + 2);		//Dua con tro den vi tri hang ke tiep
		
		ShowEscEnter();
		if (getch() == 27)
		{
			gotoxy(0, toaDoKetThucY + 6);
			break;
		}
		HideMessage(40, 10);
		
	} while(ds.n < MAX_DAU_SACH);
	if (ds.n == MAX_DAU_SACH)
	{
		ShowMessage(40, 10, 80, 12, "        Danh sach da day!         ");
		getch();
	}

}

void InDauSach(LISTDAUSACH ds){
	DAUSACH dausach;
	int i, viTriY;
	for( i = 0; i<ds.n; i++)
	{
		viTriY = wherey();
		dausach = *ds.nodes[i];
		gotoxy(DAUSACH_START_X + 2, viTriY); cout<<i+ 1; gotoxy(DAUSACH_TOADO_X_1 + 1, viTriY); cout<<dausach.ISBN; gotoxy(DAUSACH_TOADO_X_2 + 2, viTriY); cout<<dausach.tensach; gotoxy(DAUSACH_TOADO_X_3 + 2, viTriY); cout<<dausach.tacgia; gotoxy(DAUSACH_TOADO_X_4 + 4, viTriY); cout<<dausach.namxuatban; gotoxy(DAUSACH_TOADO_X_5 + 2, viTriY); cout<<dausach.sotrang; gotoxy(DAUSACH_TOADO_X_6 + 2, viTriY); cout<<dausach.theloai;
		if (i != ds.n - 1)
		{
			VeDuongNgang (DAUSACH_START_X, DAUSACH_TOADO_X_1, DAUSACH_TOADO_X_2, DAUSACH_TOADO_X_3, DAUSACH_TOADO_X_4, DAUSACH_TOADO_X_5, DAUSACH_TOADO_X_6, DAUSACH_END_X, viTriY + 1);
			gotoxy(4, viTriY + 2);
		}
	}
	
}

void InDauSachMuonNhieuNhat(LISTDAUSACH ds){
	int height;
	DAUSACH tmp;
	DAUSACH *luotmuon = new DAUSACH[ds.n];
	if(ds.n > 10)
	{
		height = 10;
	}
	else
	{
		height = ds.n;
	}
	//Dua dau sach vao mang luotmuon
	for(int i = 0; i<ds.n; i++)
	{
		luotmuon[i] = (*ds.nodes[i]);
	}
	//Sap xep trong mang luotmuon giam dan
	for(int i = 1; i<ds.n; i++)
	{
		for(int j = ds.n -1; j>=i; j--)
		{
			if(luotmuon[j].soluotmuon >  luotmuon[j-1].soluotmuon)
			{
				tmp = luotmuon[j-1];
				luotmuon[j-1] = luotmuon[j];
				luotmuon[j] = tmp;
			}
		}
	}
	//Xaut mang luotmuon
	for(int i = 0; i<height; i++)
	{
		gotoxy(4, wherey()); cout<<i+ 1; gotoxy(9, wherey()); cout<<luotmuon[i].ISBN; gotoxy(25, wherey()); cout<<luotmuon[i].tensach; gotoxy(61, wherey()); cout<<luotmuon[i].tacgia; gotoxy(84, wherey()); cout<<luotmuon[i].namxuatban; gotoxy(93, wherey()); cout<<luotmuon[i].sotrang; gotoxy(104, wherey()); cout<<luotmuon[i].soluotmuon;
		if (i != ds.n - 1)
		{
			VeDuongNgang (2, wherey() + 1, 5, 14, 35, 20, 10, 10, 14 );
			gotoxy(4, wherey() + 1);
		}
	}
	delete [] luotmuon;
}

void MenuNhapDauSach(LISTDAUSACH &ds){
	BackForce_Color_Header();
	VeBang(40, 5, 80, 7);
	gotoxy(41, 6); cout<<"             NHAP DAU SACH             ";
	BackForce_Color_Default();
	
	VeBang(DAUSACH_START_X, DAUSACH_START_Y, DAUSACH_END_X, DAUSACH_END_Y);
	VeDuongDoc (DAUSACH_TOADO_X_1, DAUSACH_START_Y, DAUSACH_TOADO_X_1, DAUSACH_END_Y);
	VeDuongDoc (DAUSACH_TOADO_X_2, DAUSACH_START_Y, DAUSACH_TOADO_X_2, DAUSACH_END_Y);
	VeDuongDoc (DAUSACH_TOADO_X_3, DAUSACH_START_Y, DAUSACH_TOADO_X_3, DAUSACH_END_Y);
	VeDuongDoc (DAUSACH_TOADO_X_4, DAUSACH_START_Y, DAUSACH_TOADO_X_4, DAUSACH_END_Y);
	VeDuongDoc (DAUSACH_TOADO_X_5, DAUSACH_START_Y, DAUSACH_TOADO_X_5, DAUSACH_END_Y);
	VeDuongDoc (DAUSACH_TOADO_X_6, DAUSACH_START_Y, DAUSACH_TOADO_X_6, DAUSACH_END_Y);
	VeDuongNgang (DAUSACH_START_X, DAUSACH_TOADO_X_1, DAUSACH_TOADO_X_2, DAUSACH_TOADO_X_3, DAUSACH_TOADO_X_4, DAUSACH_TOADO_X_5, DAUSACH_TOADO_X_6, DAUSACH_END_X, 16);
	BackForce_Color_Header2();
	gotoxy(DAUSACH_START_X + 2, 15); cout<<"STT"; gotoxy(DAUSACH_TOADO_X_1 + 6, 15); cout<<"ISBN"; gotoxy(DAUSACH_TOADO_X_2 + 13, 15); cout<<"TEN SACH"; gotoxy(DAUSACH_TOADO_X_3 + 7, 15); cout<<"TAC GIA"; gotoxy(DAUSACH_TOADO_X_4 + 5, 15); cout<<"NXB"; gotoxy(DAUSACH_TOADO_X_5 + 2, 15); cout<<"S.TRANG";gotoxy(DAUSACH_TOADO_X_6 + 4, 15); cout<<"THE LOAI";
	BackForce_Color_Default();
	gotoxy(DAUSACH_START_X + 2, 17);
	
	NhapDauSach(ds);
}

//In dau sach theo ten sach tang dan
void MenuInDauSach(LISTDAUSACH ds){
	
	BackForce_Color_Header();
	VeBang(40, 5, 80, 7);
	gotoxy(41, 6); cout<<"        DANH SACH NHUNG DAU SACH       ";
	BackForce_Color_Default();
			
	if (ds.n == 0)
	{
		VeBang(DAUSACH_START_X, DAUSACH_START_Y, DAUSACH_END_X, DAUSACH_END_Y);
		gotoxy(45, (DAUSACH_START_Y + DAUSACH_END_Y)/2); cout<<"Ban chua them dau sach nao!";
		gotoxy(0, DAUSACH_END_Y + 6);
	}
	else
	{
		int toaDoKetThucY = DAUSACH_START_Y + 2*ds.n + 2;
		
		VeBang(DAUSACH_START_X, DAUSACH_START_Y, DAUSACH_END_X, toaDoKetThucY);
		VeDuongDoc (DAUSACH_TOADO_X_1, DAUSACH_START_Y, DAUSACH_TOADO_X_1, toaDoKetThucY);
		VeDuongDoc (DAUSACH_TOADO_X_2, DAUSACH_START_Y, DAUSACH_TOADO_X_2, toaDoKetThucY);
		VeDuongDoc (DAUSACH_TOADO_X_3, DAUSACH_START_Y, DAUSACH_TOADO_X_3, toaDoKetThucY);
		VeDuongDoc (DAUSACH_TOADO_X_4, DAUSACH_START_Y, DAUSACH_TOADO_X_4, toaDoKetThucY);
		VeDuongDoc (DAUSACH_TOADO_X_5, DAUSACH_START_Y, DAUSACH_TOADO_X_5, toaDoKetThucY);
		VeDuongDoc (DAUSACH_TOADO_X_6, DAUSACH_START_Y, DAUSACH_TOADO_X_6, toaDoKetThucY);
		VeDuongNgang (DAUSACH_START_X, DAUSACH_TOADO_X_1, DAUSACH_TOADO_X_2, DAUSACH_TOADO_X_3, DAUSACH_TOADO_X_4, DAUSACH_TOADO_X_5, DAUSACH_TOADO_X_6, DAUSACH_END_X, 16);
		BackForce_Color_Header2();
		gotoxy(DAUSACH_START_X + 2, 15); cout<<"STT"; gotoxy(DAUSACH_TOADO_X_1 + 6, 15); cout<<"ISBN"; gotoxy(DAUSACH_TOADO_X_2 + 13, 15); cout<<"TEN SACH"; gotoxy(DAUSACH_TOADO_X_3 + 7, 15); cout<<"TAC GIA"; gotoxy(DAUSACH_TOADO_X_4 + 5, 15); cout<<"NXB"; gotoxy(DAUSACH_TOADO_X_5 + 2, 15); cout<<"S.TRANG";gotoxy(DAUSACH_TOADO_X_6 + 4, 15); cout<<"THE LOAI";
		BackForce_Color_Default();
		gotoxy(DAUSACH_START_X + 2, 17);
	
		SapXepDauSachTheoTen(ds);
		InDauSach(ds);
		
		gotoxy(0, toaDoKetThucY + 6);
	}
}

#endif
