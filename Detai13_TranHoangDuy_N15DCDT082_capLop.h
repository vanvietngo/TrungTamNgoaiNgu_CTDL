#ifndef	_capLop_heder
#define	_capLop_heder


#include"Detai13_TranHoangDuy_N15DCDT082_dataType.h"

using namespace std;
/*
Cấp lớp: danh sách tuyến tính là 1 mảng con trỏ 
(Mã cấp lớp, Tên cấp lớp, 
Số tiết học, học phí, con trỏ): con trỏ sẽ trỏ đến các lớp thuộc cấp lớp tương 
ứng.
*/




// function

//Về cấp lớp: thêm / xóa / hiệu chỉnh thông tin cấp lớp.

int themCapLop(DS_CAPLOP &ds_CapLop);
 int xoaCapLop(DS_CAPLOP &ds_CapLop);
void xuatCapLop(DS_CAPLOP ds_CapLop);
int hieuChinhCapLop(DS_CAPLOP &ds_CapLop);

// function bo sung
int check_lap_MCL(DS_CAPLOP ds_CapLop, CAPLOP* CapLop);
int timViTriXoaCapLop(DS_CAPLOP ds_CapLop, char* maCapLop);
int check_lapMaCapLopLapEdit(DS_CAPLOP ds_CapLop, int pos, char* MaEdit);



int save_CapLopFile(DS_CAPLOP ds_CapLop, char* fileName);
int load_CapLopFile(DS_CAPLOP &ds_CapLop, char* fileName);


#endif
