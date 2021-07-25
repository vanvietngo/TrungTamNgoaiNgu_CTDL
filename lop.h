#ifndef      __lop_H__
#define      __lop_H__


#include"dataType.h"
#include"capLop.h"
/*    
Lớp: danh sách liên kết đơn (Mã lớp, trạng thái, Phòng học, contrỏ). Mỗi lớp
có 1 mã duy nhất; trạng thái của lớp bao gồm: 0: lớp chuẩn bị mở, 1: lớp đang 
học, 2: lớp đã hoàn tất. Thuộc tính contrỏ là con trỏ chỉ đến danh sách học 
viên của lớp (con trỏ chỉ đến cây nhị phân tìm kiếm HọcViên).
*/
	  
// dataType	  


// function 

//Về lớp: thêm / xóa / hiệu chỉnh thông tin lớp.
int themLop(DS_CAPLOP &ds_CapLop);
//int xoaLop();
//int hieuChinhLop();
//void xuatThongTinLop();

// additional



#endif    // __lop_H__ 