#ifndef _docgia_h_
#define _docgia_h_
#define DOCGIA_START_X 25
#define DOCGIA_START_Y 14
#define DOCGIA_END_X 90
#define DOCGIA_END_Y 21
#define DOCGIA_TOADO_X_1 31
#define DOCGIA_TOADO_X_2 38
#define DOCGIA_TOADO_X_3 52
#define DOCGIA_TOADO_X_4 66
#define DOCGIA_TOADO_X_5 76

int viTriKetThucY = 0;	//Vi tri ket thuc cua bang in danh sach doc gia

void Time (time_t &ngaymuon, time_t &ngaytra){
	time_t nm = time(0);
	ngaymuon = nm;
	tm *tg1 = localtime(&nm);
	gotoxy(67,27);cout<<tg1->tm_mday<<"/"<<1+ tg1->tm_mon<<"/"<<1900 + tg1->tm_year<<endl;
	
	time_t nt = nm + 1296000; 
	ngaytra = nt;
	tm *tg2 = localtime(&nt);
	gotoxy(81,27); cout<<tg2->tm_mday<<"/"<<1+ tg2->tm_mon<<"/"<<1900 + tg2->tm_year<<endl;
}

void ChangeTime(time_t a){
	tm* a1 = localtime(&a); 
	cout<<a1->tm_mday<<"/"<<1+ a1->tm_mon<<"/"<<1900 + a1->tm_year;
}

void KhoiTaoTree (TREE* &root){
	root = NULL;
}

// Ham tra ve du lieu DocGia (kieu TREE)
TREE* SearchDocGia(TREE* root,  int x){
	TREE* p;
	p = root;
	while (p != NULL && p->MDG != x)
	{
		if (x< p->MDG)
		{
			p = p->left;
		}
		else
		{
			p= p->right;
		}
	}
	return p;
}

// Ham tra ve MaDocGia kieu int
int RandomMDG(TREE* root){
	srand (time(0));
    TREE *p;
   	while (1)
   	{
   		int r = rand() % 1000 + 1;
   		p = SearchDocGia(root, r);
   		if(p == NULL)
   		{
   			return r;
   			break;
		}
    	else if (p->MDG != r)
    	{
    		return r;
    		break;
		}
   	}
} 

// Ham dung de set ma doc gia va ma sach
void SetMa(TREE* root, char *mdg){
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
				mdg[i] = '\0';
				if (i == 0)
				{
//					SetColor(0); SetBGColor(13);
//					VeBang(40, 10, 80, 12);
//					gotoxy(41, 11); cout<<"       O nay khong duoc de trong       ";
//					gotoxy(x, y);
					ShowMessage(40, 10, 80, 12, "       O nay khong duoc de trong       ");
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
						mdg[j] = mdg[j+1];
					}
					mdg[--i] = '\0';
					for(j = 0; j<i; j++)
					{
						gotoxy(x+j, y); cout<<mdg[j];
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
					mdg[wherex()-x] = (char)k;
					cout<<(char)k;
				}
				else if (wherex() < 91)
				{
					mdg[i++] = (char)k;
					cout<<(char)k;
				}
			
			}
			else if (wherex() < 102)
			{
//				int wx = wherex();
//				SetColor(0); SetBGColor(13);
//				VeBang(40, 10, 80, 12);
//				gotoxy(41, 11); cout<<"        O nay chi nhan ky tu so        ";
//				gotoxy(wx, y);

				ShowMessage(40, 10, 80, 12, "        O nay chi nhan ky tu so        ");
			}
			
		}
		
	}
	while(true);
	gotoxy(x, y);
}

// Ham SetTrangThaiTheForDocGia() chi nhan 0 va 1 tu ban phim
void SetTrangThaiTheDocGia (int &trangthaithe){
	int wx = wherex();
	int wy = wherey();
	BackForce_Color_Info();
	VeBang(40, 10, 80, 12);
	gotoxy(41, 11); cout<<"0. The bi khoa || 1. The dang hoat dong";
	BackForce_Color_Default();
	gotoxy(wx, wy);
		
	int n;
	do
	{
		
		n = getch ();
		if (n == 48)
		{
			trangthaithe = 0;
			cout<<"0";
			break;
		}
		else if (n == 49)
		{
			trangthaithe = 1;
			cout<<"1";
			break;
		}
	}
	while (1);
	HideMessage(40, 10);
}

// Ham SetPhaiForDocGia() chi nhan 0 va 1 tu ban phim
void SetPhaiDocGia(char p[5]){
	int wx = wherex();
	int wy = wherey();
	BackForce_Color_Info();
	VeBang(40, 10, 80, 12);
	gotoxy(41, 11); cout<<"            0. Nam || 1. Nu            ";
	BackForce_Color_Default();
	gotoxy(wx, wy);
	
	int n;
	do
	{
		n = getch ();
		if (n == 48)
		{
			strcpy(p ,"Nam");
			cout<<"Nam";
			break;
		}
		else if (n == 49)
		{
			strcpy(p ,"Nu");
			cout<<"Nu";
			break;
			
		}
	}
	while (1);
	HideMessage(40, 10);
}

// Chen node DocGia vao TREE
void InsertDGIntoTree(TREE* &p, int x, DOCGIA a){
	if (p == NULL)
	{
		p = new TREE;
		p->MDG = x;
		p->DG = a;
		p->left= NULL;
		p->right= NULL;
	}
	else
	{
		if(x<p->MDG)
		{
			InsertDGIntoTree(p->left, x, a);
		}
		else if(x>p->MDG)
		{
			InsertDGIntoTree(p->right, x, a);
		}
	}
}

void TimNodeCucTrai(TREE* tmp, TREE* NodeCucTrai){
	if(NodeCucTrai != NULL)
	{
		TimNodeCucTrai(tmp, NodeCucTrai->left);
	}
	else
	{
		tmp->MDG = NodeCucTrai->MDG;
		tmp->DG = NodeCucTrai->DG;
		tmp = NodeCucTrai;
		NodeCucTrai = tmp->right;
	}
}

// Xoa node co khoa ka "key" trong cay nhi phan tim kiem
void XoaNodeInTree(TREE* &root, int key){
	if(root == NULL)
	{
//		SetColor(0); SetBGColor(13);
//		VeBang(40, 10, 80, 12);
//		gotoxy(41, 11); cout<<"        Xoa that bai!      ";
//		gotoxy(0, 20);
//		SetColor(10); SetBGColor(3);
		ShowMessage(40, 10, 80, 12, "        Xoa that bai!      ");
	}
	else
	{
		if (key < root->MDG)
		{
			XoaNodeInTree(root->left, key);
		}
		else if (key > root->MDG)
		{
			XoaNodeInTree(root->right, key);
		}
		else
		{
			TREE* tmp = root;
			if(tmp->left == NULL)
			{
				root = tmp->right;
			}
			else if(tmp->right == NULL)
			{
				root = tmp->left;
			}
			else
			{
				TREE* NodeCucTrai = root->right;
				TimNodeCucTrai(tmp, NodeCucTrai);
			}
			delete tmp;
			
//			SetColor(0); SetBGColor(13);
//			VeBang(40, 10, 80, 12);
//			gotoxy(41, 11); cout<<"            Xoa thanh cong!            ";
//			gotoxy(0, 20);
//			SetColor(10); SetBGColor(3);
			ShowMessage(40, 10, 80, 12, "            Xoa thanh cong!            ");
		}
	}
	
}

// Dem so luong doc gia co trong cay nhi phan
int CountDocGiaInTree(TREE* T){
   if( T == NULL)
      return 0;
   else
      return 1 + CountDocGiaInTree(T->left) + CountDocGiaInTree(T->right);
}

void NhapDocGia(TREE* &root){
	int maDocGia = 1;    //khoa chinh la MDG
	int soThuTu = 1;
	int viTriKetThucY = DOCGIA_END_Y;
	int viTriY;
	
	do{
		viTriY = wherey();
		if (viTriKetThucY - viTriY == 1 || viTriKetThucY - viTriY == 2)
		{
			NoiBang(DOCGIA_START_X, viTriKetThucY, DOCGIA_END_X, viTriKetThucY + 2);
			VeDuongDoc(DOCGIA_TOADO_X_1, viTriKetThucY, DOCGIA_TOADO_X_1, viTriKetThucY +2);
			gotoxy(DOCGIA_TOADO_X_1, viTriKetThucY); cout<<char(179);
			VeDuongDoc(DOCGIA_TOADO_X_2, viTriKetThucY, DOCGIA_TOADO_X_2, viTriKetThucY +2);
			gotoxy(DOCGIA_TOADO_X_2, viTriKetThucY); cout<<char(179);
			VeDuongDoc(DOCGIA_TOADO_X_3, viTriKetThucY, DOCGIA_TOADO_X_3, viTriKetThucY +2);
			gotoxy(DOCGIA_TOADO_X_3, viTriKetThucY); cout<<char(179);
			VeDuongDoc(DOCGIA_TOADO_X_4, viTriKetThucY, DOCGIA_TOADO_X_4, viTriKetThucY +2);
			gotoxy(DOCGIA_TOADO_X_4, viTriKetThucY); cout<<char(179);
			VeDuongDoc(DOCGIA_TOADO_X_5, viTriKetThucY, DOCGIA_TOADO_X_5, viTriKetThucY +2);
			gotoxy(DOCGIA_TOADO_X_5, viTriKetThucY); cout<<char(179);
			
			viTriKetThucY = viTriKetThucY + 2 ;
			gotoxy(35, viTriY);
		}
		
		DOCGIA DG;
		gotoxy(DOCGIA_START_X + 2, viTriY); cout<<soThuTu; soThuTu = soThuTu + 1; 
		gotoxy(DOCGIA_TOADO_X_1 + 2, viTriY); maDocGia = RandomMDG(root); cout<<maDocGia;
		gotoxy(DOCGIA_TOADO_X_2 + 2, viTriY); SetHoTen(DG.ho); gotoxy(40, viTriY); cout<<DG.ho;
		gotoxy(DOCGIA_TOADO_X_3 + 2, viTriY); SetHoTen(DG.ten); gotoxy(54, viTriY); cout<<DG.ten;;
		gotoxy(DOCGIA_TOADO_X_4 + 5, viTriY); fflush(stdin); SetTrangThaiTheDocGia(DG.trangthaithe); 	/*(Bi khoa: 0 | Dang hoat dong: 1 )*/
		gotoxy(DOCGIA_TOADO_X_5 + 6, viTriY); fflush(stdin); SetPhaiDocGia(DG.phai);
		DG.NumberBookBorrow = 0;
		DG.PTR = NULL;
		InsertDGIntoTree(root, maDocGia, DG);
		
		VeDuongNgang(DOCGIA_START_X, DOCGIA_TOADO_X_1, DOCGIA_TOADO_X_2, DOCGIA_TOADO_X_3, DOCGIA_TOADO_X_4, DOCGIA_TOADO_X_5, DOCGIA_END_X, -1, viTriY + 1); 
		
		gotoxy(DOCGIA_START_X + 2, viTriY + 2); 	//Dua con tro den vi tri hang ke tiep
		
		ShowEscEnter();
		if(getch() == 27){
			gotoxy(0, viTriKetThucY + 6);
			break;
		} 
		HideMessage(40, 10);
	}
	while(true);
}

void HieuChinhDocGia(TREE*& root){
	int wx = wherex();
	int wy = wherey();
	TREE* docgia;
	char *mdg = new char[5];
	do
	{
		gotoxy(wx, wy); cout<<"                             ";
		gotoxy(wx, wy); SetMa(root, mdg); gotoxy(wx, wy); ShowEscEnter(); gotoxy(wx, wy); cout<<atoi(mdg);
		docgia = SearchDocGia(root, atoi(mdg));
		if(getch() == 27)
		{
			gotoxy(0, 25);
			break;
		}
		else if (docgia == NULL) 
		{
			ShowMessage(40, 10, 80, 12, "          Doc gia khong ton tai        ");
		}
		else
		{
			HideMessage(40, 10);
			
			gotoxy(DOCGIA_START_X + 6, DOCGIA_START_Y + 7); cout<<docgia->MDG;
			gotoxy(DOCGIA_TOADO_X_2 + 2, DOCGIA_START_Y + 7); SetHoTen(docgia->DG.ho); gotoxy(DOCGIA_TOADO_X_2 + 2, wherey()); cout<<docgia->DG.ho;
			gotoxy(DOCGIA_TOADO_X_3 + 2, DOCGIA_START_Y + 7); SetHoTen(docgia->DG.ten); gotoxy(DOCGIA_TOADO_X_3 + 2, wherey()); cout<<docgia->DG.ten;;
			gotoxy(DOCGIA_TOADO_X_4 + 4, DOCGIA_START_Y + 7); fflush(stdin); SetTrangThaiTheDocGia(docgia->DG.trangthaithe);	/*(Bi khoa: 0 | Dang hoat dong: 1 )*/
			gotoxy(DOCGIA_TOADO_X_5 + 6, DOCGIA_START_Y + 7); fflush(stdin); SetPhaiDocGia(docgia->DG.phai);
			
			//Thong bao cap nhat thanh cong
			ShowMessage(40, 10, 80, 12, "      Cap nhat doc gia thanh cong!     ");
			break;
		}
	}
	while (1);
	
}

void XoaDocGia(TREE* &root){
	int wx = wherex();
	int wy = wherey();
	TREE* p;
	char *mdg = new char[5];
	do
	{
		gotoxy(wx, wy); cout<<"                             ";
		gotoxy(wx, wy); SetMa(root, mdg); ShowEscEnter(); gotoxy(wx, wy); cout<<atoi(mdg);
		p = SearchDocGia(root, atoi(mdg));
		if(getch() == 27)
		{
			break;
		}
		else if (p == NULL) 
		{
			ShowMessage(40, 10, 80, 12, "          Doc gia khong ton tai        ");
		}
		else
		{
			HideMessage(40, 10);
			XoaNodeInTree(root, p->MDG);
			break;
		}
	}
	while (1);
}

void InDanhSachDocGiaTheoMDG(TREE* root){
	int y = wherey(), i = 1;
   	const int STACKSIZE = 500;
   	TREE* Stack[STACKSIZE];
  	TREE* p = root;
  	int sp=-1;	// Khoi tao Stack rong
   	do
   	{ 
   		while (p != NULL)
      	{	
		  	Stack[++sp]= p;
			p= p->left;
     	}
     	if (sp != -1)
     	{	
	  		p = Stack[sp--];
		 	gotoxy(DOCGIA_START_X + 3, y); cout<<i; gotoxy(DOCGIA_TOADO_X_1 + 4, y); cout<<p->MDG; gotoxy(DOCGIA_TOADO_X_2 + 4, y); cout<<p->DG.ho; gotoxy(DOCGIA_TOADO_X_3 + 4, y); cout<<p->DG.ten; gotoxy(DOCGIA_TOADO_X_4 + 7, y); cout<<p->DG.trangthaithe; gotoxy(DOCGIA_TOADO_X_5 + 7, y); cout<<p->DG.phai<<endl;
		 	if (y + 1 != viTriKetThucY){
		 		VeDuongNgang (DOCGIA_START_X, DOCGIA_TOADO_X_1 + 2, DOCGIA_TOADO_X_2 + 2, DOCGIA_TOADO_X_3 + 2, DOCGIA_TOADO_X_4 + 2, DOCGIA_TOADO_X_5 + 2, DOCGIA_END_X, -1, y + 1);
			} 
			y = y + 2; i = i + 1;
			p=p->right;
		 
      	}
      	else break;
   } while (1);
}

void InDanhSachDocGiaTheoTenHo(TREE* root){
	TREE* MangDocGia[CountDocGiaInTree(root)];
	int y = wherey();
   	const int STACKSIZE = 500;
   	TREE* Stack[STACKSIZE];
  	TREE* p = root;
  	int sp = -1;	// Khoi tao Stack rong
  	int i = 0;
   	do
   	{ 
   		while (p != NULL)
      	{	
		  	Stack[++sp]= p;
			p= p->left;
     	}
     	if (sp != -1)
     	{	
	  		p = Stack[sp--];
	  		MangDocGia[i++] = p;
		 	p = p->right;
      	}
      	else break;
   } while (1);
   
   TREE* Swap;
   for(int i = 1; i<CountDocGiaInTree(root); i++)
   {
   		for(int j = CountDocGiaInTree(root) - 1; j >= i; j--)
   		{
   			if(strcmp(MangDocGia[j - 1]->DG.ten, MangDocGia[j]->DG.ten) > 0)
   			{
   				Swap = MangDocGia[j-1];
   				MangDocGia[j-1] = MangDocGia[j];
   				MangDocGia[j] = Swap;
			}
			else if(strcmp(MangDocGia[j - 1]->DG.ten, MangDocGia[j]->DG.ten) == 0)
			{
				if(strcmp(MangDocGia[j - 1]->DG.ho, MangDocGia[j]->DG.ho) > 0)
				{
					Swap = MangDocGia[j-1];
   					MangDocGia[j-1] = MangDocGia[j];
   					MangDocGia[j] = Swap;
				}
			}
		}
   }
   
   for(int i = 0; i<CountDocGiaInTree(root); i++)
   {
   		gotoxy(DOCGIA_START_X + 3, y); cout<<i; gotoxy(DOCGIA_TOADO_X_1 + 4, y); cout<<MangDocGia[i]->MDG; gotoxy(DOCGIA_TOADO_X_2 + 4, y); cout<<MangDocGia[i]->DG.ho; gotoxy(DOCGIA_TOADO_X_3 + 4, y); cout<<MangDocGia[i]->DG.ten; gotoxy(DOCGIA_TOADO_X_4 + 7, y); cout<<MangDocGia[i]->DG.trangthaithe; gotoxy(DOCGIA_TOADO_X_5 + 7, y); cout<<MangDocGia[i]->DG.phai<<endl;
//   		gotoxy(30, y); cout<<i+1; gotoxy(35,y); cout<<MangDocGia[i]->MDG; gotoxy(42, y); cout<<MangDocGia[i]->DG.ho; gotoxy(56, y); cout<<MangDocGia[i]->DG.ten; gotoxy(73, y); cout<<MangDocGia[i]->DG.trangthaithe; gotoxy(85, y); cout<<MangDocGia[i]->DG.phai<<endl;
		if ( y + 1 != viTriKetThucY){
			VeDuongNgang (DOCGIA_START_X, DOCGIA_TOADO_X_1 + 2, DOCGIA_TOADO_X_2 + 2, DOCGIA_TOADO_X_3 + 2, DOCGIA_TOADO_X_4 + 2, DOCGIA_TOADO_X_5 + 2, DOCGIA_END_X, -1, y + 1);
		} 
		y = y + 2;
   }
}

void InDanhSachDocGiaMuonQuaHan(TREE* root, LISTDAUSACH ds,  time_t now){
	int height = 12;
	int stt = 1, justone = 1;
	TREE* stack[500];
	int sp = -1;
	int thoigian;
	do
	{
		while(root != NULL)
		{
			stack[++sp] = root;
			root =  root->left;
		}
		if(sp != -1)
		{
			root = stack[sp--];
			for(LISTMUONSACH* p = root->DG.PTR; p!=NULL; p= p->Next)
			{
				thoigian = p->data.ngaytra - now;
				if(thoigian < 0)
				{
					if (height == wherey() )
					{
//						NoiBang(2, wherey(), 117, wherey() + 2);
//						ThemDuongDoc(8, height, height + 2);
//						ThemDuongDoc(23, height, height + 2);
//						ThemDuongDoc(38, height, height + 2);
//						ThemDuongDoc(74, height, height + 2);
//						ThemDuongDoc(89, height, height + 2);
//						ThemDuongDoc(104, height, height + 2);
//						VeDuongNgang(2, wherey()-2, 5, 14, 14, 35, 14, 14, 12);
						NoiBang(2, wherey(), 117, wherey() + 2);
						VeDuongDoc(8, height, 8, height + 2); gotoxy(8, height); cout<<char(179);
						VeDuongDoc(23, height, 23, height + 2); gotoxy(23, height); cout<<char(179);
						VeDuongDoc(38, height, 38, height + 2); gotoxy(38, height); cout<<char(179);
						VeDuongDoc(74, height, 74, height + 2); gotoxy(74, height); cout<<char(179);
						VeDuongDoc(89, height, 89, height + 2); gotoxy(89, height); cout<<char(179);
						VeDuongNgang (2, 8, 23, 38, 74, 89, 104, 117, wherey()-2);
						height = height + 2;
						gotoxy(30, wherey() + 1);
					}
					if (justone == 1)
					{
						gotoxy(4, wherey()); cout<<stt; gotoxy(13, wherey()); cout<<root->MDG; 
						justone ++;
						stt = stt + 1;
					}
					else
					{
						int y = wherey() - 1;
						for(int i = 2; i<= 23; i++)
						{
							if(i == 2 || i == 8)
							{
								gotoxy(i, y); cout<<char(179);
							}
							else if (i == 23)
							{
								gotoxy(i, y); cout<<char(195);
							}
							else
							{
								gotoxy(i, y); cout<<" ";
							}
						}
						gotoxy(30, y + 1);
						
					}
					int vitri = SearchMaSach (ds, p->data.masach);
					DAUSACH dausach = *(ds.nodes[vitri]);
					gotoxy(30, wherey()); cout<<p->data.masach; gotoxy(40, wherey()); cout<<dausach.tensach; gotoxy(77, wherey()); ChangeTime(p->data.ngaymuon); gotoxy(93, wherey()); ChangeTime(p->data.ngaytra); gotoxy(108, wherey()); cout<<(abs(thoigian/86400))<<endl;
				}
			}
			root = root->right;
			justone = 1;
		}
		else break;
	}
	while(1);
	if (wherey() == 11)
	{
		system("cls");
		
		BackForce_Color_Header();
		VeBang(20, 1, 100, 3);
		gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
		gotoxy(0, 7);
		
		VeBang(40, 5, 80, 7);
		gotoxy(41, 6); cout<<"  DANH SACH DOC GIA MUON QUA HAN   ";
		BackForce_Color_Default();
	
		VeBang(2, 8, 117, 14);
		gotoxy(42, 11); cout<<"Hien tai chua co doc gia muon qua han!";
		gotoxy(0, 16);
	}
} 

void InCacSachMotDGDangMuon(TREE* docgia, LISTDAUSACH ds, int soluongsach){
	int stt = 1, j;
	for(LISTMUONSACH* i = docgia->DG.PTR; i!=NULL; i=i->Next)
	{
		j = SearchTenSach (ds, i->data.tensach);
		DAUSACH sach = *(ds.nodes[j]);
		gotoxy(4, wherey()); cout<<stt; gotoxy(9, wherey()); cout<<i->data.masach; gotoxy(25, wherey()); cout<<i->data.tensach; gotoxy(61, wherey()); cout<<sach.tacgia; gotoxy(84, wherey()); cout<<sach.namxuatban; gotoxy(93, wherey()); cout<<sach.sotrang; gotoxy(104, wherey()); cout<<sach.theloai;
		if (stt != soluongsach)
		{
//			VeDuongNgang (2, wherey() + 1, 5, 14, 35, 20, 10, 10, 14 );
			VeDuongNgang(2, 8, 23, 59, 80, 91, 102, 117, wherey() + 1);
		}
		gotoxy(4, wherey() + 1);
		stt = stt + 1;

	}
	
}

void DeleteAll(LISTSACH* &ListSach, TREE* &docgia){
	//Xoa List sach
	LISTSACH* p;
	while (ListSach != NULL)
	{
		p = ListSach;
		ListSach = p->Next;
		delete p;
	}
	//Xoa List Muon Tra
	LISTMUONSACH* q;
	while(docgia->DG.PTR != NULL)
	{
		q = docgia->DG.PTR;
		docgia->DG.PTR = q->Next;
		delete q;
	}
	
}

int MenuInDocGia(TREE* root){
	int luachon;
	while (1)
	{
		system("cls");
		BackForce_Color_Header2();
		VeBang(40, 2, 87, 4);
		BackForce_Color_Default();
		gotoxy(40, 5);  cout<<(" ______________________________________________");
		gotoxy(40, 6);  cout<<("|                                              |");
		gotoxy(40, 7);  cout<<("|          MENU IN DANH SACH DOC GIA           |");
		gotoxy(40, 8);  cout<<("|______________________________________________|");
		gotoxy(40, 9);  cout<<("|                                              |");
		gotoxy(40, 10); cout<<("|   1. In danh sach doc gia theo MDG           |");
		gotoxy(40, 11); cout<<("|                                              |");
		gotoxy(40, 12); cout<<("|   2. In danh sach doc gia theo ho ten        |");
		gotoxy(40, 13); cout<<("|                                              |");
		gotoxy(40, 14); cout<<("|   0. Thoat                                   |");
		gotoxy(40, 15); cout<<("|                                              |");
		gotoxy(40, 16); cout<<("|               Chon |   |                     |");
		gotoxy(40, 17); cout<<("|______________________________________________|");
		gotoxy(63, 16);
		Chaychu(wherex(), wherey());
		
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
		gotoxy(63, 16); cout<<luachon;
		Sleep(100);
		if ( 0 > luachon || luachon > 3)
		{
//			SetColor(0); SetBGColor(13);
//			gotoxy(40, 19); cout<<"         Ban nhap sai. Vui long nhap lai!!      ";
//			SetColor(10); SetBGColor(3);
//			cout<<endl;
//			system ("pause");
		}
		if (luachon == 0)
			return 0;
		else if (luachon == 1)
		{
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
//			BackForce_Color_Default();
			gotoxy(0, 7);
			
			VeBang(40, 5, 80, 7);
			gotoxy(41, 6); cout<<"       DANH SACH DOC GIA THEO MDG      ";
			BackForce_Color_Default();
			
			if(root == NULL)
			{
				VeBang(2, 11, 117, 17);
				gotoxy(45, 14); cout<<"Hien tai chua co doc gia nao!";
				gotoxy(0, 18);
			}
			else
			{
				viTriKetThucY = 10 + 2*CountDocGiaInTree(root) + 2; 
				
				VeBang(DOCGIA_START_X, 10, DOCGIA_END_X, viTriKetThucY);
				VeDuongDoc (DOCGIA_TOADO_X_1 + 2, 10, 33, viTriKetThucY);
				VeDuongDoc (DOCGIA_TOADO_X_2 + 2, 10, 40, viTriKetThucY);
				VeDuongDoc (DOCGIA_TOADO_X_3 + 2, 10, 54, viTriKetThucY);
				VeDuongDoc (DOCGIA_TOADO_X_4 + 2, 10, 68, viTriKetThucY);
				VeDuongDoc (DOCGIA_TOADO_X_5 + 2, 10, 78, viTriKetThucY);
				VeDuongNgang (DOCGIA_START_X, DOCGIA_TOADO_X_1 + 2, DOCGIA_TOADO_X_2 + 2, DOCGIA_TOADO_X_3 + 2, DOCGIA_TOADO_X_4 + 2, DOCGIA_TOADO_X_5 + 2, DOCGIA_END_X, -1, 12);
				
				BackForce_Color_Header2();
				gotoxy(28, 11); cout<<"STT"; gotoxy(35, 11); cout<<"MDG"; gotoxy(46, 11); cout<<"HO"; gotoxy(60, 11); cout<<"TEN"; gotoxy(70, 11); cout<<"TR.THAI"; gotoxy(82, 11); cout<<"PHAI";
				BackForce_Color_Default();
				
				gotoxy(29, 13); InDanhSachDocGiaTheoMDG(root);
			}
			gotoxy(0, wherey() + 2);
			system("pause");
		}
		else if (luachon == 2)
		{
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
//			BackForce_Color_Default();
			gotoxy(0, 7);
			
			VeBang(40, 5, 80, 7);
			gotoxy(41, 6); cout<<"     DANH SACH DOC GIA THEO TEN HO     ";
			BackForce_Color_Default();
			
			if(root == NULL)
			{
				VeBang(2, 11, 117, 17);
				gotoxy(45, 14); cout<<"Hien tai chua co doc gia nao!";
				gotoxy(0, 18);
			}
			else
			{
				viTriKetThucY = 10 + 2*CountDocGiaInTree(root) + 2; 
				
				VeBang(DOCGIA_START_X, 10, DOCGIA_END_X, viTriKetThucY);
				VeDuongDoc (DOCGIA_TOADO_X_1 + 2, 10, 33, viTriKetThucY);
				VeDuongDoc (DOCGIA_TOADO_X_2 + 2, 10, 40, viTriKetThucY);
				VeDuongDoc (DOCGIA_TOADO_X_3 + 2, 10, 54, viTriKetThucY);
				VeDuongDoc (DOCGIA_TOADO_X_4 + 2, 10, 68, viTriKetThucY);
				VeDuongDoc (DOCGIA_TOADO_X_5 + 2, 10, 78, viTriKetThucY);
				VeDuongNgang (DOCGIA_START_X, DOCGIA_TOADO_X_1 + 2, DOCGIA_TOADO_X_2 + 2, DOCGIA_TOADO_X_3 + 2, DOCGIA_TOADO_X_4 + 2, DOCGIA_TOADO_X_5 + 2, DOCGIA_END_X, -1, 12);
				
				BackForce_Color_Header2();
				gotoxy(28, 11); cout<<"STT"; gotoxy(35, 11); cout<<"MDG"; gotoxy(46, 11); cout<<"HO"; gotoxy(60, 11); cout<<"TEN"; gotoxy(70, 11); cout<<"TR.THAI"; gotoxy(82, 11); cout<<"PHAI";
				BackForce_Color_Default();
				
				gotoxy(29, 13); InDanhSachDocGiaTheoTenHo(root);
			}
			gotoxy(0, wherey() + 2);
			system("pause");
		}
	}
}

int MenuDocGia(LISTDAUSACH &ds, TREE* &root){
	int luachon;
	while (1)
	{
		system("cls");
		BackForce_Color_Header2();
		VeBang(40, 2, 79, 4);
		BackForce_Color_Default();
		gotoxy(40, 5);  cout<<(" ______________________________________");
		gotoxy(40, 6);  cout<<("|                                      |");
		gotoxy(40, 7);  cout<<("|         MENU QUAN LY DOC GIA         |");
		gotoxy(40, 8);  cout<<("|______________________________________|");
		gotoxy(40, 9);  cout<<("|                                      |");
		gotoxy(40, 10); cout<<("|   1. Them doc gia                    |");
		gotoxy(40, 11); cout<<("|                                      |");
		gotoxy(40, 12); cout<<("|   2. Hieu chinh doc gia              |");
		gotoxy(40, 13); cout<<("|                                      |");
		gotoxy(40, 14); cout<<("|   3. Xoa doc gia                     |");
		gotoxy(40, 15); cout<<("|                                      |");
		gotoxy(40, 16); cout<<("|   4. In danh sach doc gia            |");
		gotoxy(40, 17); cout<<("|                                      |");
		gotoxy(40, 18); cout<<("|   0. Thoat                           |");
		gotoxy(40, 19); cout<<("|                                      |");
		gotoxy(40, 20); cout<<("|            Chon |   |                |");
		gotoxy(40, 21); cout<<("|______________________________________|");
		gotoxy(60, 20);
		Chaychu (wherex(), wherey());
		
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
		gotoxy(60, 20); cout<<luachon;
		Sleep(100);
		
		if ( 0 > luachon || luachon > 5)
		{
			gotoxy(40, 23); cout<<"    Ban nhap sai. Vui long nhap lai!!   ";
			cout<<endl;
			system ("pause");
		}
		
		if (luachon == 0){
			return 0;
		}
		else if (luachon == 1)
		{			
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
//			BackForce_Color_Default();
			gotoxy(0, 7);
			
			VeBang(40, 5, 80, 7);
			gotoxy(41, 6); cout<<"              THEM DOC GIA             ";
			BackForce_Color_Default();
			
			VeBang(DOCGIA_START_X, DOCGIA_START_Y, DOCGIA_END_X, DOCGIA_END_Y);
			VeDuongDoc (DOCGIA_TOADO_X_1, DOCGIA_START_Y, DOCGIA_TOADO_X_1, DOCGIA_END_Y);
			VeDuongDoc (DOCGIA_TOADO_X_2, DOCGIA_START_Y, DOCGIA_TOADO_X_2, DOCGIA_END_Y);
			VeDuongDoc (DOCGIA_TOADO_X_3, DOCGIA_START_Y, DOCGIA_TOADO_X_3, DOCGIA_END_Y);
			VeDuongDoc (DOCGIA_TOADO_X_4, DOCGIA_START_Y, DOCGIA_TOADO_X_4, DOCGIA_END_Y);
			VeDuongDoc (DOCGIA_TOADO_X_5, DOCGIA_START_Y, DOCGIA_TOADO_X_5, DOCGIA_END_Y);
			VeDuongNgang (DOCGIA_START_X, DOCGIA_TOADO_X_1, DOCGIA_TOADO_X_2, DOCGIA_TOADO_X_3, DOCGIA_TOADO_X_4, DOCGIA_TOADO_X_5, DOCGIA_END_X, -1, 16 );
			
			BackForce_Color_Header2();
			gotoxy(DOCGIA_START_X + 2, 15); cout<<"STT"; gotoxy(DOCGIA_TOADO_X_1 + 2, 15); cout<<"MDG"; gotoxy(DOCGIA_TOADO_X_2 + 6, 15); cout<<"HO"; gotoxy(DOCGIA_TOADO_X_3 + 6, 15); cout<<"TEN"; gotoxy(DOCGIA_TOADO_X_4 + 2, 15); cout<<"TR.THAI"; gotoxy(DOCGIA_TOADO_X_5 + 6, 15); cout<<"PHAI";
			BackForce_Color_Default();
			gotoxy(DOCGIA_START_X + 2, 17);
			
			NhapDocGia(root);
		}
		else if (luachon == 2)
		{
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
//			BackForce_Color_Default();
			gotoxy(0, 7);
			
			VeBang(40, 5, 80, 7);
			gotoxy(41, 6); cout<<"           HIEU CHINH DOC GIA          ";
//			BackForce_Color_Default();
			
			BackForce_Color_Header2();
			VeBang(DOCGIA_START_X, 14, 56, 16); gotoxy(58, 15); cout<<":";
			gotoxy(29, 15); cout<<"MA DOC GIA CAN HIEU CHINH"; 
			VeBang(60, 14, 92, 16);
			BackForce_Color_Default();

			VeBang(DOCGIA_START_X, DOCGIA_START_Y + 4, DOCGIA_END_X + 2, DOCGIA_END_Y + 1);
			VeDuongDoc(DOCGIA_TOADO_X_2, DOCGIA_START_Y + 4, DOCGIA_TOADO_X_2, DOCGIA_END_Y + 1);
			VeDuongDoc(DOCGIA_TOADO_X_3, DOCGIA_START_Y + 4, DOCGIA_TOADO_X_3, DOCGIA_END_Y + 1);
			VeDuongDoc(DOCGIA_TOADO_X_4, DOCGIA_START_Y + 4, DOCGIA_TOADO_X_4, DOCGIA_END_Y + 1);
			VeDuongDoc(DOCGIA_TOADO_X_5, DOCGIA_START_Y + 4, DOCGIA_TOADO_X_5, DOCGIA_END_Y + 1);
			VeDuongNgang(DOCGIA_START_X, DOCGIA_TOADO_X_2, DOCGIA_TOADO_X_3, DOCGIA_TOADO_X_4, DOCGIA_TOADO_X_5, DOCGIA_END_X + 2, -1, -1, DOCGIA_START_Y + 6);
			BackForce_Color_Header2();
			gotoxy(30, DOCGIA_START_Y + 5); cout<<"MDG"; gotoxy(44,  DOCGIA_START_Y + 5); cout<<"HO"; gotoxy(58,  DOCGIA_START_Y + 5); cout<<"TEN"; gotoxy(68,  DOCGIA_START_Y + 5); cout<<"TR.THAI"; gotoxy(81,  DOCGIA_START_Y + 5); cout<<"PHAI";
			BackForce_Color_Default();
			
			gotoxy(62, 15);	//Dua co tro ve vi tri nhap Ma Doc Gia
			HieuChinhDocGia(root);
			gotoxy(0, 25); system("pause");
		}
		else if (luachon == 3)
		{
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
//			BackForce_Color_Default();
			gotoxy(0, 7);
			
			BackForce_Color_Header();
			VeBang(40, 5, 80, 7);
			gotoxy(41, 6); cout<<"              XOA DOC GIA              ";
//			BackForce_Color_Default();
			
			BackForce_Color_Header2();
			VeBang(28, 14, 56, 16); gotoxy(58, 15); cout<<":";
			gotoxy(30, 15); cout<<"MA DOC GIA CAN XOA"; 
			VeBang(60, 14, 92, 16);
			BackForce_Color_Default();
			
			gotoxy(62, 15);	//Dua co tro ve vi tri nhap Ma Doc Gia
			XoaDocGia(root);
			gotoxy(0, 25); system("pause");
		}
		else if (luachon == 4)
		{
			MenuInDocGia(root);
		}
	}
}

#endif
