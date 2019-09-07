#ifndef _sach_h_
#define _sach_h_
#include "DauSach.h"
#include "Common.h"
#define SACH_START_X 28		//Vi tri x bat dau ve bang danh sach cac sach
#define SACH_START_Y 18		//Vi tri y bat dau ve bang danh sach cac sach
#define SACH_END_X 92		//Vi tri x ket thuc ve bang danh sach cac sach
#define SACH_END_Y 25		//Vi tri y ket thuc ve bang danh sach cac sach
#define SACH_TOADO_X_1 47
#define SACH_TOADO_X_2 60

// Tra ve vi tri trong LISTDAUSACH co mtensach
int SearchTenSach(LISTDAUSACH ds, char *mtensach){
	DAUSACH dausach;
	for ( int i = 0 ; i < ds.n ; i++)
  		{
  			dausach = *(ds.nodes[i]);
  			if (strcmp(dausach.tensach, mtensach) == 0)
  			{
  				return i;
  				break;
			}
		}
	return -1;
}

// Tra ve vi tri trong LISTDAUSACH co mmasach
int SearchMaSach(LISTDAUSACH ds, int mmasach){
	DAUSACH dausach;
	for (int i = 0 ; i < ds.n ; i++)
  	{
  		dausach = *(ds.nodes[i]);
		for (LISTSACH* p = dausach.FirstSach; p!=NULL; p=p->Next)
  		{
  			if (p->sach.masach == mmasach)
  			{
  				return i;
  				break;
			}
		}
  		
	}
	return -1;
}

// Kiem tra ma sach, return 0 ma sach da co trong LISTSACH
int CheckMaSach(LISTDAUSACH ds, int vtdausach, int masach){	
	DAUSACH dausach = *(ds.nodes[vtdausach]);
	for (LISTSACH* p = dausach.FirstSach; p!=NULL; p=p->Next)
    	{ 	
			 if (p->sach.masach ==  masach) 
			 {
			 	return 0;
			 	break;
			 } 	
      	
		}	
	return 1;
}

//Tra ve 0 neu trong LISTDAUSACH co "tensach" co trang thai cua "masach" bang 0 (cho muon duoc)
int CheckTrangThaiSach(LISTDAUSACH ds, char tensach[51], int masach){         //Check du lieu nhap vao nhung ma sach ma co trang thai == 0
	int i = SearchTenSach (ds, tensach);
	if (i != -1)
	{
		for(LISTSACH* p =  (*ds.nodes[i]).FirstSach; p!=NULL; p=p->Next)
		{
			if(strcmp(p->sach.trangthai , "0") == 0) 
			{
				if(p->sach.masach == masach )
				{
					return 0;
				}
			}
		}
	}
	return 1;	
}

// Tra ve ma sach sau khi da ramdom va kiem tra
int RamdomMaSach(LISTDAUSACH ds, int vtdausach){
	int r;
	srand (time(0));
	do {
		r = rand() % 1000 + 1;
		for(int vtdausach = 0; vtdausach < ds.n; vtdausach++)
		{
			if(CheckMaSach(ds, vtdausach, r) == 0)
			{
				r = -1;
				break;
			}
		}
		if (r != -1)
		{
			return r;
			break;
		}
	}
	while (1);
}

//Set trang thai sach
void SetTrangThaiSach(char *trangthaisach){
	int n;
	int wx = wherex();
	int wy = wherey();
	BackForce_Color_Info();
	VeBang(31, 10, 88, 12);
	gotoxy(32, 11); cout<<" 0. Cho muon duoc || 1. Da co DG muon || 2. Da thanh ly ";
	BackForce_Color_Default();
	gotoxy(wx, wy);
	do
	{
		n = getch ();
		if (n == 48)
		{
			strcpy(trangthaisach, "0");
			cout<<"0";
			break;
		}
		else if (n == 49)
		{
			strcpy(trangthaisach, "1");
			cout<<"1";
			break;
		}
		else if (n == 50)
		{
			strcpy(trangthaisach, "2");
			cout<<"2";
			break;
		}
	}
	while (1);

	HideMessage(31, 10);
}

// Chen sach vao cuoi LISTSACH (Chen vao cuoi danh sach lien ket don)
void InsertLastIntoListSach(LISTSACH* &First, SACH s){
	LISTSACH* p = new LISTSACH;
	p->sach = s; 
	p->Next = NULL;
	if (First == NULL) First = p;
	else 
	{
		LISTSACH* Last ;
		for (Last = First; Last->Next!= NULL; Last = Last->Next );
		Last->Next = p;
	}
}

//Tra ve so luong masach cua dau sach "tensach" co trang thai == 0 trong LISTSACH
int CountTrangThaiSach0(LISTDAUSACH ds, char tensach[51]){
	int i = SearchTenSach (ds, tensach), dem = 0;
	if (i != -1)
	{
		for(LISTSACH* p = (*ds.nodes[i]).FirstSach; p!=NULL; p=p->Next)
		{
			if(strcmp(p->sach.trangthai , "0") == 0) 
			{
				dem = dem + 1;
			}
		}
	}
	return dem;	
}

//In ra masach con lai, ISBN, tensach, tacgia, NXB, sotrang, theloai cua dau sach " mtensach"
void TimThongTinSach(LISTDAUSACH ds){
	char mtensach[51];
	do
	{
		gotoxy(56, 15); cout<<"                              ";
		gotoxy(56, 15); SetTenSach(mtensach); gotoxy(56, 15); cout<<mtensach; ShowEscEnter();
		if(getch() == 27) 
		{
			gotoxy(0, 18);
			break;
		}
		int i = SearchTenSach(ds, mtensach);
		if(i == -1)
		{
			ShowMessage(40, 10, 80, 12, "        Ten sach khong ton tai         ");
		}
		else if(i != -1)
		{
			HideMessage(40, 10);
			int height = CountTrangThaiSach0(ds, mtensach);
			if(height != 0)
			{
				VeBang(1, 17, 118, 20 + height);
				VeDuongDoc (11, 17, 11, 20 + height);
				VeDuongDoc (25, 17, 25, 20 + height);
				VeDuongDoc (61, 17, 61, 20 + height);
				VeDuongDoc (82, 17, 82, 20 + height);
				VeDuongDoc (93, 17, 93, 20 + height);
				VeDuongDoc (104, 17, 104, 20 + height);
				VeDuongNgang (1, 11, 25, 61, 82, 93, 104, 118, 19);
				BackForce_Color_Header2();
				gotoxy(3, 18); cout<<"MA SACH"; gotoxy(17, 18); cout<<"ISBN"; gotoxy(40, 18); cout<<"TEN SACH"; gotoxy(69, 18); cout<<"TAC GIA"; gotoxy(87, 18); cout<<"NXB";  gotoxy(96, 18);cout<<"S.TRANG"; gotoxy(107,18); cout<<"THE LOAI";
				BackForce_Color_Default();
				gotoxy(5, 20);
			
				DAUSACH sach = *(ds.nodes[i]);
				for(LISTSACH* p = sach.FirstSach; p!=NULL; p=p->Next)
				{
					if(strcmp(p->sach.trangthai, "0") == 0)
					{
						gotoxy(5, wherey()); cout<<p->sach.masach<<endl;
					}
				}
			
				gotoxy(12, 20 + height/2); cout<<sach.ISBN; gotoxy(27, 20 + height/2); cout<<sach.tensach; gotoxy(64, 20 + height/2); cout<<sach.tacgia; gotoxy(86, 20 + height/2); cout<<sach.namxuatban; gotoxy(97, 20 + height/2); cout<<sach.sotrang; gotoxy(106, 20 + height/2); cout<<sach.theloai<<endl;
				gotoxy(0, height + 22);
				break;
			}
			else
			{
				VeBang(1, 17, 118, 21);
				VeDuongDoc (11, 17, 11, 21);
				VeDuongDoc (25, 17, 25, 21);
				VeDuongDoc (61, 17, 61, 21);
				VeDuongDoc (82, 17, 82, 21);
				VeDuongDoc (93, 17, 93, 21);
				VeDuongDoc (104, 17, 104, 21);
				VeDuongNgang (1, 19, 9, 13, 35, 20, 10, 10, 13);
				BackForce_Color_Header2();
				gotoxy(3, 18); cout<<"MA SACH"; gotoxy(17, 18); cout<<"ISBN"; gotoxy(40, 18); cout<<"TEN SACH"; gotoxy(69, 18); cout<<"TAC GIA"; gotoxy(87, 18); cout<<"NXB";  gotoxy(96, 18);cout<<"S.TRANG"; gotoxy(107,18); cout<<"THE LOAI";
				BackForce_Color_Default();
				
				gotoxy(5, 20);cout<<"Het";
			
				DAUSACH sach = *(ds.nodes[i]);
				gotoxy(12, 20 ); cout<<sach.ISBN; gotoxy(27, 20); cout<<sach.tensach; gotoxy(64, 20); cout<<sach.tacgia; gotoxy(86, 20 + height/2); cout<<sach.namxuatban; gotoxy(97, 20 + height/2); cout<<sach.sotrang; gotoxy(106, 20); cout<<sach.theloai<<endl;
				gotoxy(0, 22);
				system("pause");
				break;
			}
		
		}
	}
	while(1);
	
}

void NhapSach (LISTDAUSACH &ds){
	int toaDoKetThucY = SACH_END_Y;	//Toa do ket thuc bang
	int viTriY;
	char k;
	SACH s;
	char *mtensach= new char[35];
	int vtdausach;
	do{
		gotoxy(57, 15); cout<<"                                   ";
		gotoxy(57, 15); fflush(stdin); SetTenSach(mtensach); gotoxy(57, 15); cout<<mtensach;
		vtdausach = SearchTenSach (ds, mtensach); gotoxy(57, 15);
		 
		ShowEscEnter();
		if(getch() == 27)
		{
			k = 27;
			gotoxy(0, toaDoKetThucY + 6);
			break;
		}
		
		if (vtdausach == -1) 
		{
			ShowMessage(40, 10, 80, 12, "        Dau sach khong ton tai         ");
			gotoxy(57, 15); cout<<"                                   "; gotoxy(57, 15);
		}
		else
		{
			HideMessage(40, 10);
			break;
		}
	}
	while (1);
	
	if(k != 27){
		gotoxy(35, 21);
		while (vtdausach != -1)
		{
			viTriY = wherey();
			if (toaDoKetThucY - viTriY == 1 || toaDoKetThucY - viTriY == 2)
			{
				NoiBang(SACH_START_X, toaDoKetThucY, SACH_END_X, toaDoKetThucY + 2);
				VeDuongDoc(SACH_TOADO_X_1, toaDoKetThucY, SACH_TOADO_X_1, toaDoKetThucY +2); gotoxy(SACH_TOADO_X_1, toaDoKetThucY); cout<<char(179);
				VeDuongDoc(SACH_TOADO_X_2, toaDoKetThucY, SACH_TOADO_X_2, toaDoKetThucY +2); gotoxy(SACH_TOADO_X_2, toaDoKetThucY); cout<<char(179);
				toaDoKetThucY = toaDoKetThucY + 2 ;
				gotoxy(SACH_START_X + 7, viTriY);
			}
			
			gotoxy(SACH_START_X + 7, viTriY); s.masach = RamdomMaSach(ds, vtdausach); cout<<s.masach; HideMessage(40, 10);
			gotoxy(SACH_TOADO_X_1 + 6 , viTriY); fflush(stdin); SetTrangThaiSach(s.trangthai);
			gotoxy(SACH_TOADO_X_2 + 15 , viTriY); fflush(stdin); gets(s.vitri); fflush(stdin);
			
			InsertLastIntoListSach((*ds.nodes[vtdausach]).FirstSach, s);
			
			VeDuongNgang(SACH_START_X, SACH_TOADO_X_1, SACH_TOADO_X_2, SACH_END_X, -1, -1, -1, -1, viTriY + 1);
			
			gotoxy(35, viTriY + 2); 
			
			ShowEscEnter();
			if (getch() == 27){
				gotoxy(0, toaDoKetThucY + 4);
				break;
			} 
			HideMessage(40, 10);
		}	
	}
}

void MenuNhapSach(LISTDAUSACH &ds){	
	BackForce_Color_Header();
	VeBang(40, 5, 80, 7);
	gotoxy(41, 6); cout<<"               THEM SACH               ";
	
	BackForce_Color_Header2();
	VeBang(28, 14, 51, 16); gotoxy(53, 15); cout<<":";
	gotoxy(29, 15); cout<<"Ten dau sach can them"; 
	VeBang(55, 14, 92, 16);
	BackForce_Color_Default();
	
	VeBang(SACH_START_X, SACH_START_Y, SACH_END_X, SACH_END_Y);
	VeDuongDoc(SACH_TOADO_X_1, SACH_START_Y, SACH_TOADO_X_1, SACH_END_Y);
	VeDuongDoc(SACH_TOADO_X_2, SACH_START_Y, SACH_TOADO_X_2, SACH_END_Y);
	VeDuongNgang(SACH_START_X, SACH_TOADO_X_1, SACH_TOADO_X_2, SACH_END_X, -1, -1, -1, -1, 20);
	BackForce_Color_Header2();
	gotoxy(SACH_START_X + 7, 19); cout<<"MA SACH"; gotoxy(SACH_TOADO_X_1 + 2, 19); cout<<"TRANG THAI"; gotoxy(SACH_TOADO_X_2 + 10, 19); cout<<"VI TRI SACH"; 
	BackForce_Color_Default();
	
	NhapSach(ds);
}

void MenuTimThongTinSach(LISTDAUSACH &ds){
	
	BackForce_Color_Header();
	VeBang(40, 5, 80, 7);
	gotoxy(41, 6); cout<<"           TIM THONG TIN SACH          ";

	BackForce_Color_Header2();
	VeBang(28, 14, 51, 16); gotoxy(53, 15); cout<<":";
	gotoxy(29, 15); cout<<"Ten dau sach can tim"; 
	VeBang(55, 14, 92, 16); gotoxy(56, 15);
	BackForce_Color_Default();
	
	TimThongTinSach(ds);
}
#endif
