#ifndef      __hocVien_H__
#define      __hocVien_H__

#include<stdio.h>
#include<string>
#include"diem.h">

using namespace std;
/*
HọcViên: cây nhị phân tìm kiếm 
(Mã học viên, là số nguyên ngẫu nhiên, được 
phát sinh tự động và không trùng nhau), Ho, Ten, Phai, con trỏ): con trỏ sẽ 
trỏ đến danh sách các điểm (nghe, nói, đọc, viết) của học viên.
*/

struct _HOCVIEN{
	int Ma;	//random
	char Ho[10];
	char Ten[10];
	char Phai[5];
	struct _HOCVIEN* pLeft;
	struct _HOCVIEN* pRight;
	DS_DIEM ds_diem;

};      
typedef struct _HOCVIEN HOCVIEN;

struct _DS_HOCVIEN{
	int count = 0;
	HOCVIEN* dsHocVien=NULL;
};
typedef struct _DS_HOCVIEN DS_HOCVIEN;

#endif    // __hocVien_H__ 