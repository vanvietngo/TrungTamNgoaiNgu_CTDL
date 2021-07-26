



//main  function 
//Về lớp: thêm / xóa / hiệu chỉnh thông tin lớp.
int themLop(DS_CAPLOP &ds_CapLop);
//int hieuChinhLop();
int xuatThongTinLop(DS_CAPLOP &ds_CapLop);
int xoaLop(DS_CAPLOP & ds_CapLop);

// additional
void addNodeDSLK(DS_LOP &ds_Lop, LOP* lop);
int check_LapMaLop(DS_LOP ds_Lop,char *maLop);
int deleteNodeDSLK(DS_LOP & ds_Lop, int pos);


#endif    // __lop_H__ 
