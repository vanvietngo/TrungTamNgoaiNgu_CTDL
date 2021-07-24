#ifndef      __diem_H__
#define      __diem_H__

#include<stdio.h>
#include<string>

//      Điểm: danh sách liên kết đơn (kỹ năng, điểm): kỹ năng =0 là nghe, =1 là nói, 
//			=2 là đọc, =3 là viết

struct _DIEM{
	int Skill;	
	struct _DIEM* next;
};      
typedef struct _DIEM DIEM;

struct _DS_DIEM{
	int count = 0;
	DIEM* ds_Diem;
};
typedef struct _DS_DIEM DS_DIEM;

#endif    // __diem_H__ 