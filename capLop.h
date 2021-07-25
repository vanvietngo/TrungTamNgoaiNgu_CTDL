#ifndef	_capLop_heder
#define	_capLop_heder

#include<iostream>
#include<stdio.h>
#include<string> 
#include"lop.h"
#include <iomanip>
#include <fstream> 

using namespace std;
/*
Cấp lớp: danh sách tuyến tính là 1 mảng con trỏ 
(Mã cấp lớp, Tên cấp lớp, 
Số tiết học, học phí, con trỏ): con trỏ sẽ trỏ đến các lớp thuộc cấp lớp tương 
ứng.
*/


// datatype
struct _CAPLOP{
	char	Ma[10];
	char Ten[10];
	int SoTiet;
	int HocPhi;
	DS_LOP ds_lop;
};
typedef struct _CAPLOP CAPLOP;

const int SL_CapLop = 100;
struct _DS_CAPLOP{
	int count=0;
	CAPLOP* dsCapLop[SL_CapLop];
};
typedef struct _DS_CAPLOP DS_CAPLOP;

// function

//Về cấp lớp: thêm / xóa / hiệu chỉnh thông tin cấp lớp.

int themCapLop(DS_CAPLOP &ds_CapLop);
int xoaCapLop(DS_CAPLOP &ds_CapLop);
void xuatCapLop(DS_CAPLOP ds_CapLop);
int hieuChinhCapLop(DS_CAPLOP &ds_CapLop);

// function bo sung
int check_lap_MCL(DS_CAPLOP ds_CapLop, CAPLOP* CapLop);
int timViTriXoaCapLop(DS_CAPLOP ds_CapLop, string CapLop);
int check_lapMaCapLopLapEdit(DS_CAPLOP ds_CapLop, int pos, string MaEdit);
int save_CapLopFile(DS_CAPLOP ds_CapLop);
int load_CapLopFile(DS_CAPLOP &ds_CapLop);

#endif
