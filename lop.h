#ifndef      __lop_H__
#define      __lop_H__

#include<stdio.h>
#include<string>
#include"hocVien.h"
/*    
Lớp: danh sách liên kết đơn (Mã lớp, trạng thái, Phòng học, contrỏ). Mỗi lớp
có 1 mã duy nhất; trạng thái của lớp bao gồm: 0: lớp chuẩn bị mở, 1: lớp đang 
học, 2: lớp đã hoàn tất. Thuộc tính contrỏ là con trỏ chỉ đến danh sách học 
viên của lớp (con trỏ chỉ đến cây nhị phân tìm kiếm HọcViên).
*/
	  
struct _LOP{
	string Ma;
	int Status;
	string Phong;
	DS_HOCVIEN ds_HocVien;
};      
typedef struct _LOP LOP;

struct _DS_LOP{
	int count = 0;
	LOP* ds_Lop;
};
typedef struct _DS_LOP DS_LOP;

#endif    // __lop_H__ 