#ifndef __hocVien_H__
#define __hocVien_H__

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
int editHocVien(DS_CAPLOP & ds_CapLop);
int xoaHocVien(DS_CAPLOP & ds_CapLop);
int thongKeHV(DS_CAPLOP  ds_CapLop);
// In ra 10 lớp có số lượng học viên là đông nhất
int _10LopHVdongNhat(DS_CAPLOP  ds_CapLop);

// additional function

int Check_lap_MHV(HOCVIEN * root, int maHV);
int addNodeHocVien(HOCVIEN * & root, HOCVIEN * HocVien);
void InOrder(HOCVIEN * root);
HOCVIEN * searchHocVien(HOCVIEN * root, int maHV);
int Check_lap_MHV(HOCVIEN * root, int maHV);
int xoaNodeCNP(HOCVIEN * & root, int maHV);
int showHVtheoCL(CAPLOP *capLop);

void writeFile(HOCVIEN * root, FILE * f);
int saveFileHocVien(DS_HOCVIEN ds_HocVien, char * fileHocVien);
int openFileHocVien(DS_HOCVIEN & ds_HocVien, char * fileHocVien);

int addNode_10HV_MAX(DS_countMaxLop &ds, countMaxLop* lop);
int showNode_10Max(DS_countMaxLop ds);

#endif // __hocVien_H__ 