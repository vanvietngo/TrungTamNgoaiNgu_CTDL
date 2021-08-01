#ifndef      __hocVien_H__
#define      __hocVien_H__

#include<stdio.h>
#include<string>
#include"dataType.h"
#include"lop.h"
#include<cstdlib> // rand(); srand();   rand()% (b -a + 1) + a => [a;b]
#include<ctime> // xoa data random cu khi khoi dong
/*
HọcViên: cây nhị phân tìm kiếm 
(Mã học viên, là số nguyên ngẫu nhiên, được 
phát sinh tự động và không trùng nhau), Ho, Ten, Phai, con trỏ): con trỏ sẽ 
trỏ đến danh sách các điểm (nghe, nói, đọc, viết) của học viên.
*/

// MAIN fnction
// Về học viên: thêm / xóa / hiệu chỉnh thông tin học viên.

int themHocVien(DS_CAPLOP & ds_CapLop);
int xuatDanhSach_HV(DS_CAPLOP & ds_CapLop);
int editHocVien(DS_CAPLOP &ds_CapLop);


// additional function

int Check_lap_MHV(HOCVIEN* root, int maHV);
int addNodeHocVien(HOCVIEN* &root, HOCVIEN *HocVien);
void InOrder(HOCVIEN* root);
HOCVIEN* searchHocVien(HOCVIEN* root, int maHV);
int Check_lap_MHV(HOCVIEN * root, int maHV);

void writeFile(HOCVIEN * root, FILE* f);
int saveFileHocVien(DS_HOCVIEN ds_HocVien, char* fileHocVien);

// int openFileHocVien(DS_LOP& ds_Lop, char* fileLop);

#endif    // __hocVien_H__ 