#ifndef _classobject_h_
#define _classobject_h_
#define MAX_DAU_SACH 500

////////////////////////Sach//////////////////////////
struct Sach {
	int masach;
	char trangthai[2];
	char vitri[10];
};
typedef struct Sach SACH;

struct ListSach {
	SACH sach;
	struct ListSach *Next;
};
typedef struct ListSach LISTSACH;

////////////////////////Dau Sach//////////////////////////
struct DauSach {
	char ISBN[14];
	char tensach[51];
	char tacgia[21];
	char sotrang[5];
	char namxuatban[5];
	char theloai[21];
	int soluotmuon = 0;
	LISTSACH *FirstSach = NULL;
};
typedef struct DauSach DAUSACH;

struct ListDauSach {
	int n = 0;
	DAUSACH *nodes[MAX_DAU_SACH];
};
typedef struct ListDauSach LISTDAUSACH;

////////////////////////Muon Sach//////////////////////////
struct MuonSach {
	int masach;
	char tensach[51];
	time_t ngaymuon;
	time_t ngaytra;
};
typedef struct MuonSach MUONSACH;

struct ListMuonSach {
	MUONSACH data;
	struct ListMuonSach *Next;
};
typedef struct ListMuonSach LISTMUONSACH;

////////////////////////Doc gia//////////////////////////
struct DocGia {
	char ho[10];
	char ten[10];
	char phai[5];
	int trangthaithe;
	int NumberBookBorrow;
	LISTMUONSACH *PTR;
};
typedef struct DocGia DOCGIA;

struct Tree {
	int MDG;
	DOCGIA DG;
	struct Tree *left;
	struct Tree *right;
};
typedef struct Tree TREE;
#endif
