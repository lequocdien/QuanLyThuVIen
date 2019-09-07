#include "DocGia.h"


// Chen sach vao cuoi danh sach cua LISTMUONSACH
void InsertLastIntoListMuonSach(LISTMUONSACH* &PTR, MUONSACH data){
	LISTMUONSACH * p = new LISTMUONSACH;
	p-> data = data; 
	p->Next = NULL;
	if (PTR == NULL) PTR = p;
	else 
	{
		LISTMUONSACH* Last ;
		for (Last = PTR; Last->Next!= NULL; Last = Last->Next );
		Last->Next = p;
	}
}

// Tra ve so luong sach ma doc gia "p" dang muon
int CountSachMuon(TREE* root, int mdg){
	int dem = 0;
	TREE* p;
	p = SearchDocGia(root, mdg);
	for(LISTMUONSACH* q = p->DG.PTR; q != NULL; q = q->Next)
	{
		dem = dem + 1;
	}
	return dem;
}

int CheckDGMuonQuaHan(TREE* docgia){
	time_t now = time(0);
	int thoigian;
	for(LISTMUONSACH* p = docgia->DG.PTR; p!=NULL; p=p->Next)
	{
		thoigian = p->data.ngaytra - now;
		if( thoigian < 0)
		{
			return 0;
			break;
		}
	}
	return 1;
}

void MuonSach(TREE* &root, LISTDAUSACH ds){
	TREE *docgia;
	char *mdg = new char[5];
	char tensach[51];
	do
	{
		gotoxy(62, 15); cout<<"                              ";
		gotoxy(62, 15); SetMa(root, mdg); ShowEscEnter(); gotoxy(62, 15);
		docgia = SearchDocGia(root, atoi(mdg));
		if(getch() == 27) break;
		if(docgia == NULL)
		{
			ShowMessage(40, 10, 80, 12, "     Ma doc gia nay khong ton tai!     ");
		}
		else if(docgia->DG.trangthaithe == 0)
		{
			ShowMessage(40, 10, 80, 12, "            The da bi khoa!            ");
		}
		else if(CheckDGMuonQuaHan(docgia) == 0)
		{
			ShowMessage(40, 10, 80, 12, "  Doc gia nay giu mot sach qua han!    ");
		}
		else if (docgia->DG.NumberBookBorrow >= 3)
		{
			ShowMessage(40, 10, 80, 12, "      Doc gia muon qua 3 cuon sach     ");
		}
		else
		{
			HideMessage(40, 10);
			do 
			{
				gotoxy(62,19); cout<<"                              ";
				fflush(stdin); gotoxy(62,19); SetTenSach(tensach); ShowEscEnter(); gotoxy(62,19); gotoxy(62,19); cout<<tensach;
				int vtdausach = SearchTenSach (ds, tensach);
				if(getch() == 27) break;
				if(vtdausach == -1)
				{
					ShowMessage(40, 10, 80, 12, "         Dau sach khong ton tai!       ");
				}
				else 
				{
					(*ds.nodes[vtdausach]).soluotmuon += 1;
					HideMessage(40, 10);
					VeBang(28, 22, 51, 24 + 2*CountTrangThaiSach0(ds, tensach));
					gotoxy(30, 23); cout<<"Cac ma sach kha dung";
					VeDuongNgang (28, 51, -1, -1, -1, -1, -1, -1, 24);
					gotoxy(38, 24);
					DAUSACH dausach = *(ds.nodes[vtdausach]);
					if(dausach.FirstSach == NULL)
					{
						system("cls");
						SetColor(12);
						SetBGColor(3);
						VeBang(40, 1, 80, 3);
						gotoxy(56, 2); cout<<"MUON SACH";
						SetColor(10);
						SetBGColor(3);
						gotoxy(40, 3); cout<<"\n\n";
	
						VeBang(2, 11, 117, 17);
						gotoxy(42, 14); cout<<"    Hien tai dau sach nay da het!    ";
						gotoxy(0, 25);
						system("pause");
						break;
//						gotoxy(28, wherey()+1); cout<<char(179);
//						gotoxy(51, wherey()); cout<<char(179);
//						gotoxy(38, wherey()); cout<<"NULL"<<endl;
//						gotoxy(28, wherey()); cout<<char(192);
//						gotoxy(51, wherey()); cout<<char(217);
//						gotoxy(29, wherey()); 
//						for(int i = 29; i<= 50; i++)
//						{
//							gotoxy(i, wherey()); cout<<char(196);
//						}
					}
					else
					{
						for (LISTSACH *p = dausach.FirstSach; p != NULL; p = p->Next)
    					{ 	
			 				if(strcmp(p->sach.trangthai, "0") == 0 )
			 				{
		 						gotoxy(38, wherey() + 1); cout<<p->sach.masach;
			 					if(wherey() + 1 != 24 + 2*CountTrangThaiSach0(ds, tensach)) 
									VeDuongNgang (28, 51, -1, -1, -1, -1, -1, -1, wherey() + 1);
							}
						} 
					}
					
					
					MUONSACH data; 
					char *ms = new char[5];
					VeBang(53, 22, 93 , 28);
					gotoxy(61, 23); cout<<"Moi ban chon mot ma sach";
					VeDuongNgang (53, 65, 79, 93, -1, -1, -1, -1, 24); gotoxy(65, 24); cout<<(char)194; gotoxy(79, 24); cout<<(char)194;
					VeDuongDoc (65, 24, 65, 28);
					VeDuongDoc(79, 24, 79, 28);
					VeDuongNgang (53, 65, 79, 93, -1, -1, -1, -1, 26);
					gotoxy(55,25); cout<<"MA SACH"; gotoxy(67,25); cout<<"NGAY MUON"; gotoxy(81,25); cout<<"NGAY TRA";
					do
					{
						gotoxy(58, 27); cout<<"      "; gotoxy(58, 27); SetMa(root, ms); ShowEscEnter(); gotoxy(58, 27); cout<<atoi(ms);
						if(getch() == 27) break;
						if (CheckMaSach(ds, vtdausach, atoi(ms)) == 1 || CheckTrangThaiSach (ds, tensach, atoi(ms)) == 1)
						{
							ShowMessage(40, 10, 80, 12, "           Ma sach khong dung!         ");
						}
						else
						{
							HideMessage(40, 10);
							data.masach = atoi(ms);
							strcpy(data.tensach, tensach);
							for (LISTSACH *p = dausach.FirstSach; p != NULL; p = p->Next)
    						{ 	
			 					if(p->sach.masach == atoi(ms))
			 					{
			 						strcpy(p->sach.trangthai , "1");
								}
							} 	
							Time (data.ngaymuon, data.ngaytra);
							strcmp(data.tensach, tensach);
							docgia->DG.NumberBookBorrow = docgia->DG.NumberBookBorrow + 1;
							InsertLastIntoListMuonSach(docgia->DG.PTR, data);
							
							//Thong bao muon thanh cong!
							ShowMessage(40, 10, 80, 12, "           Muon sach thanh cong        ");
							gotoxy(0, 28 + 2*CountTrangThaiSach0(ds, tensach));
							system("pause");
							break;
						}
					}
					while(1);
					break;
				}
			}
			while(1);
			break;	
		}
	}
	while(1);
	
	gotoxy(0, 27 + 2*CountTrangThaiSach0(ds, tensach));
}

// Ham tra ve 0 neu ma sach "ms" trong LISTMUONSACH cua doc gia "root" can tra co trong LISTMUONSACH
int CheckMaSachInLISTMUONSACH(TREE *root, int ms){
	for (LISTMUONSACH *p = root->DG.PTR; p != NULL; p=p->Next)
	{
		if(p->data.masach == ms)
		{
			return 0;
		}
	}
	return -1;
}

// Ham tra ve 0 neu trong LISTMUONSACH cua doc gia "root" co ten sach "mtensach"
int CheckTenSachInLISTMUONSACH(TREE* root, char *mtensach){
	for(LISTMUONSACH* p = root->DG.PTR; p!=NULL; p=p->Next)
	{
		if(strcmp(p->data.tensach, mtensach) == 0)
		{
			return 0;
		}
	}
	return 1;
}

void TraSach (TREE* &root, LISTDAUSACH ds){
	TREE *docgia;
	char *mdg = new char[5];
	char mtensach[51];
	do
	{
		gotoxy(62, 15); cout<<"                             ";
		gotoxy(62, 15); SetMa(root, mdg); ShowEscEnter(); gotoxy(62, 15); cout<<atoi(mdg);
		docgia = SearchDocGia(root, atoi(mdg));
		if(getch() == 27) break;
		if(docgia == NULL)
		{	
			ShowMessage(40, 10, 80, 12, "     Ma doc gia nay khong ton tai!     ");
		}
		else if(docgia->DG.trangthaithe == 0)
		{
			ShowMessage(40, 10, 80, 12, "            The da bi khoa!            ");
		}
		else if (docgia->DG.PTR == NULL)
		{
//			system("cls");
//			SetColor(12);
//			SetBGColor(3);
//			VeBang(40, 1, 80, 3);
//			gotoxy(56, 2); cout<<"TRA SACH";
//			SetColor(10);
//			SetBGColor(3);
//			gotoxy(40, 3); cout<<"\n\n";
	
			VeBang(2, 11, 117, 17);
			gotoxy(42, 14); cout<<"Hien tai doc gia nay chua muon sach nao!";
			gotoxy(0, 25);
			system("pause");
			break;
		}
		else
		{
			HideMessage(40, 10);
			do 
			{
				gotoxy(62,19); cout<<"                              ";
				fflush(stdin); gotoxy(62,19); SetTenSach(mtensach); ShowEscEnter(); gotoxy(62,19);
				int vtdausach = SearchTenSach (ds, mtensach);
				if(getch() == 27) break;
				if(vtdausach == -1)
				{
//					SetColor(0); SetBGColor(13);
//					VeBang(40, 10, 80, 12);
//					gotoxy(41, 11); cout<<"         Dau sach khong ton tai!       ";
//					SetColor(10); SetBGColor(3);
//					gotoxy(58, 7);
					ShowMessage(40, 10, 80, 12, "         Dau sach khong ton tai!       ");
				}
				else 
				{
				//In nhung ma sach ma docgia dang muon
					HideMessage(40, 10);
					if(docgia->DG.PTR == NULL ||  CheckTenSachInLISTMUONSACH(docgia, mtensach) == 1)
					{
						VeBang(28, 22, 51 , 26);
						gotoxy(29, 23); cout<<"Cac ma sach dang muon";
						VeDuongNgang (28, 51, -1, -1, -1, -1, -1, -1, 24);
						gotoxy(38, 25); cout<<"NULL";
					}
					else
					{
						VeBang(28, 22, 51 , 30);
						gotoxy(29, 23); cout<<"Cac ma sach dang muon";
						VeDuongNgang (28, 51, -1, -1, -1, -1, -1, -1, 24);
						for(LISTMUONSACH* p = docgia->DG.PTR; p!=NULL; p = p->Next)
						{
							if(strcmp(p->data.tensach, mtensach) == 0)
							{
								gotoxy(38, wherey()+1); cout<<p->data.masach<<endl;
								VeDuongNgang (28, 51 , -1, -1, -1, -1, -1, -1, wherey());
							}
						
						}
						int y = wherey();
						XoaBang(28, y, 51, 30);
						gotoxy(28,y); cout<<char(192);
						gotoxy(51, y); cout<<char(217);
						gotoxy(29, y); 
						for(int i = 29; i<= 50; i++)
						{
							gotoxy(i, y); cout<<char(196);
						}
					}
				
				//Chon ma sach can tra
					char *ms = new char[5];
					VeBang(53, 22, 93 , 28);
					gotoxy(61, 23); cout<<"Moi ban chon ma sach";
					VeDuongNgang (53, 65, 79, 93, -1, -1, -1, -1, 24);
					VeDuongDoc (65, 24, 65, 28);
					VeDuongDoc(79, 24, 79, 28);
					VeDuongNgang (53, 65, 79, 93, -1, -1, -1, -1, 26);
					gotoxy(55,25); cout<<"MA SACH"; gotoxy(67,25); cout<<"NGAY MUON"; gotoxy(81,25); cout<<"NGAY TRA";
					do
					{
						gotoxy(58, 27); cout<<"      "; gotoxy(58, 27); SetMa(root, ms); ShowEscEnter(); gotoxy(58, 27); cout<<atoi(ms);
						if(getch() == 27) break;
						if (CheckMaSach(ds, vtdausach, atoi(ms)) == 1 || CheckMaSachInLISTMUONSACH(docgia, atoi(ms)) == -1)
						{
							ShowMessage(40, 10, 80, 12, "           Ma sach khong dung!         ");
						}
						else
						{
							HideMessage(40, 10);
							for (LISTSACH *p = (*ds.nodes[vtdausach]).FirstSach; p!= NULL; p = p->Next)
    						{ 	
			 					if(p->sach.masach == atoi(ms))
			 					{
			 						strcpy(p->sach.trangthai , "0");
								}
							} 
							for (LISTMUONSACH *p = docgia->DG.PTR; p!=NULL; p=p->Next)
							{
								if(p->data.masach == atoi(ms))
								{
									tm *tg1 = localtime(&p->data.ngaymuon);
									gotoxy(67,27);cout<<tg1->tm_mday<<"/"<<1+ tg1->tm_mon<<"/"<<1900 + tg1->tm_year<<endl;
									time_t now = time(0);
									tm *tg2 = localtime(&now);
									gotoxy(81,27); cout<<tg2->tm_mday<<"/"<<1+ tg2->tm_mon<<"/"<<1900 + tg2->tm_year<<endl;
									
									//Xoa sach da tra ra khoi lien ket don
									if (p == docgia->DG.PTR)
									{
										docgia->DG.PTR = p->Next;
										delete p;
									}
									else
									{
										LISTMUONSACH *q;
										for (q = docgia->DG.PTR; q->Next != p; q=q->Next);
										q->Next = p->Next;
										delete p;
									}
									ShowMessage(40, 10, 80, 12, "          Tra sach thanh cong!         ");
									gotoxy(0, 31);
									system("pause");
									break;
								}
							}
							docgia->DG.NumberBookBorrow = docgia->DG.NumberBookBorrow - 1;
							break;
							
						}
						
					}
					while(1);
					break;
				}
				
			}
			while(1);
			break;	
		}
	}
	while(1);
}

int MenuMuonTra (LISTDAUSACH &ds, TREE* &root){
	int luachon;
		while (1)
	{
		system("cls");
		BackForce_Color_Header2();
		VeBang(40, 2, 79, 4);
		BackForce_Color_Default();
		gotoxy(40, 5);  cout<<(" ______________________________________");
		gotoxy(40, 6);  cout<<("|                                      |");
		gotoxy(40, 7);  cout<<("|         MENU MUON TRA SACH           |");
		gotoxy(40, 8);  cout<<("|______________________________________|");
		gotoxy(40, 9);  cout<<("|                                      |");
		gotoxy(40, 10); cout<<("|   1. Muon sach                       |");
		gotoxy(40, 11); cout<<("|                                      |");
		gotoxy(40, 12); cout<<("|   2. Tra sach                        |");
		gotoxy(40, 13); cout<<("|                                      |");
		gotoxy(40, 14); cout<<("|   3. In cac sach mot doc gia muon    |");
		gotoxy(40, 15); cout<<("|                                      |");
		gotoxy(40, 16); cout<<("|   4. Danh sach DG muon sach qua han  |");
		gotoxy(40, 17); cout<<("|                                      |");
		gotoxy(40, 18); cout<<("|   5. 10 sach co luot muon nhieu nhat |");
		gotoxy(40, 19); cout<<("|                                      |");
		gotoxy(40, 20); cout<<("|   0. Thoat                           |");
		gotoxy(40, 21); cout<<("|                                      |");
		gotoxy(40, 22); cout<<("|            Chon |   |                |");
		gotoxy(40, 23); cout<<("|______________________________________|");
		gotoxy(60, 22);
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
		gotoxy(60, 22); cout<<luachon;
		Sleep(100);
		if ( 0 > luachon || luachon > 5)
		{
//			SetColor(0); SetBGColor(13);
//			gotoxy(40, 254); cout<<"    Ban nhap sai. Vui long nhap lai!!   ";
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
			
//			BackForce_Color_Header();
			VeBang(40, 5, 80, 7);
			gotoxy(41, 6); cout<<"               MUON SACH               ";
//			BackForce_Color_Default();
			
			BackForce_Color_Header2();
			VeBang(28, 14, 56, 16); gotoxy(58, 15); cout<<":";
			gotoxy(30, 15); cout<<"MA DOC GIA CAN MUON SACH"; 
			VeBang(60, 14, 92, 16);
			
			VeBang(28, 18, 56, 20); gotoxy(58, 19); cout<<":";
			gotoxy(30, 19); cout<<"TEN SACH CAN MUON SACH"; 
			VeBang(60, 18, 92, 20);
			BackForce_Color_Default();
		
			MuonSach(root, ds);
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
			gotoxy(56, 6); cout<<"TRA SACH";
			
			BackForce_Color_Header2();
			VeBang(28, 14, 56, 16); gotoxy(58, 15); cout<<":";
			gotoxy(30, 15); cout<<"MA DOC GIA CAN TRA SACH"; 
			VeBang(60, 14, 92, 16);
			
			VeBang(28, 18, 56, 20); gotoxy(58, 19); cout<<":";
			gotoxy(30, 19); cout<<"TEN SACH CAN TRA SACH"; 
			VeBang(60, 18, 92, 20);
			BackForce_Color_Default();
			TraSach(root, ds);
		}
		else if (luachon == 3)
		{
			char *mdg = new char[5];
			TREE* docgia;

			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
//			BackForce_Color_Default();
			gotoxy(0, 7);
			
			VeBang(40, 5, 80, 7);
			gotoxy(41, 6); cout<<" DANH SACH NHUNG SACH MOT DOC GIA MUON ";
			
			BackForce_Color_Header2();
			VeBang(28, 14, 56, 16); gotoxy(58, 15); cout<<":";
			gotoxy(30, 15); cout<<"MA DOC GIA CAN XEM"; 
			VeBang(60, 14, 92, 16);
			BackForce_Color_Default();
			
			do
			{
				gotoxy(62, 15); cout<<"                              ";
				gotoxy(62, 15); SetMa(root, mdg); ShowEscEnter(); gotoxy(62, 15); cout<<atoi(mdg);
				docgia = SearchDocGia(root, atoi(mdg));
				if(getch() == 27) 
				{
					gotoxy(0, 18);
					break;
				}
				if (docgia == NULL)
				{
					ShowMessage(40, 10, 80, 12, "     Ma doc gia nay khong ton tai!     ");
					
				}
				else
				{
					if (docgia->DG.PTR == NULL)
					{
						VeBang(2, 17, 117, 23);
						gotoxy(45, 20); cout<<"Doc gia nay chua muon sach!";
						gotoxy(0, 25);
						system("pause");
						break;
					}
					else
					{
						int soluongsach1docgiamuon = CountSachMuon(root, atoi(mdg));
						int height = 19 + 2*soluongsach1docgiamuon; 
						VeBang(2, 17, 117, height);
						VeDuongDoc(8, 17, 8, height);
						VeDuongDoc(23, 17, 23, height);
						VeDuongDoc(59, 17, 59, height);
						VeDuongDoc(80, 17, 80, height);
						VeDuongDoc(91, 17, 91, height);
						VeDuongDoc(102, 17, 102, height);
						BackForce_Color_Header2();
						gotoxy(4, 18); cout<<"STT"; gotoxy(12, 18); cout<<"MA SACH"; gotoxy(36, 18); cout<<"TEN SACH"; gotoxy(66, 18); cout<<"TAC GIA"; gotoxy(85, 18); cout<<"NXB"; gotoxy(93, 18); cout<<"S.TRANG";gotoxy(106,18); cout<<"THE LOAI";
						BackForce_Color_Default();
						VeDuongNgang(2, 8, 23, 59, 80, 91, 102, 117, 19);
						gotoxy(4, 20);
						InCacSachMotDGDangMuon(docgia, ds, soluongsach1docgiamuon);
						gotoxy(0, 17 + 2*soluongsach1docgiamuon + 4 );
						system("pause");
						break;
					}
				}
			}
			while(1);
		}
		else if (luachon == 4)
		{
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
//			BackForce_Color_Default();
			gotoxy(0, 7);
	
			VeBang(40, 5, 80, 7);
			gotoxy(41, 6); cout<<"    DANH SACH DOC GIA MUON QUA HAN     ";
			BackForce_Color_Default();
			
			int height = 12;			
			VeBang(2, 8, 117, height);
			VeDuongDoc(8, 8, 8, height);
			VeDuongDoc(23, 8, 23, height);
			VeDuongDoc(38, 8, 38, height);
			VeDuongDoc(74, 8, 74, height);
			VeDuongDoc(89, 8, 89, height);
			VeDuongDoc(104, 8, 104, height);
			BackForce_Color_Header2();
			gotoxy(4, 9); cout<<"STT"; gotoxy(11, 9); cout<<"MA DOC GIA"; gotoxy(28, 9); cout<<"MA SACH"; gotoxy(54, 9); cout<<"TEN SACH"; gotoxy(77, 9); cout<<"NGAY MUON"; gotoxy(91, 9); cout<<"NGAY PHAI TRA";gotoxy(108, 9); cout<<"QUA HAN";
			BackForce_Color_Default();
			VeDuongNgang(2, 8, 23, 38, 74, 89, 104, 117, 10);
			gotoxy(4, 11);
			
			time_t now = time(0);
			InDanhSachDocGiaMuonQuaHan(root, ds, now);
			gotoxy(0, wherey() + 3);
			system("pause");
		}
		else if (luachon == 5)
		{
			system("cls");
			BackForce_Color_Header();
			VeBang(20, 1, 100, 3);
			gotoxy(21, 2); cout<<"                                QUAN LY THU VIEN                               ";
//			BackForce_Color_Default();
			gotoxy(0, 7);
	
			VeBang(40, 5, 80, 7);
			gotoxy(41, 6); cout<<"  10 DAU SACH CO LUOT MUON NHIEU NHAT  ";
			BackForce_Color_Default();
			
			if (ds.n == 0)
			{
				VeBang(2, 8, 117, 14);
				gotoxy(45, 11); cout<<"Ban chua them dau sach nao!";
				gotoxy(0, 16);
				system("pause");
			}
			else
			{
				int height;
				if(ds.n > 10)
				{
					height = 10;
				}
				else
				{
					height = ds.n;
				}
				
				VeBang(2, 8, 117, 8 + 2*height + 2);
				VeDuongDoc (8, 8, 8, 8 + 2*height + 2);
				VeDuongDoc (23, 8, 23, 8 + 2*height + 2);
				VeDuongDoc (59, 8, 59, 8 + 2*height + 2);
				VeDuongDoc (80, 8, 80, 8 + 2*height + 2);
				VeDuongDoc (91, 8, 91, 8 + 2*height + 2);
				VeDuongDoc (102, 8, 102, 8 + 2*height + 2);
				VeDuongNgang (2, 8, 23, 59, 80, 91, 102, 117, 10 );
				BackForce_Color_Header2();
				gotoxy(4, 9); cout<<"STT"; gotoxy(14, 9); cout<<"ISBN"; gotoxy(36, 9); cout<<"TEN SACH"; gotoxy(66, 9); cout<<"TAC GIA"; gotoxy(85, 9); cout<<"NXB"; gotoxy(93, 9); cout<<"S.TRANG";gotoxy(104, 9); cout<<"SO LUOT MUON";
				BackForce_Color_Default();
				gotoxy(4, 11);
			
				InDauSachMuonNhieuNhat(ds);
				gotoxy(0, 8 + 2*ds.n + 4);
				system("pause");
			}
		}
	}
}

