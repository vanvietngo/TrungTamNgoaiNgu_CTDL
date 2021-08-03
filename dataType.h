#ifndef _dataType_heder
#define _dataType_heder

#include<stdint.h>

#include<iostream>

#include<stdio.h>

#include<string>

#include <iomanip>

#include <fstream>

using namespace std;

struct _DIEM {
    int Skill;
    struct _DIEM * next = NULL;
};
typedef struct _DIEM DIEM;

struct _DS_DIEM {
    int count = 0;
    DIEM * ds_Diem = NULL;
};
typedef struct _DS_DIEM DS_DIEM;

// dataType	  - HocVien - cnp

struct _HOCVIEN {
    int Ma; //random
    char Ho[20];
    char Ten[20];
    char Phai[5];
    struct _HOCVIEN * pLeft = NULL;
    struct _HOCVIEN * pRight = NULL;
    DS_DIEM ds_diem;

};
typedef struct _HOCVIEN HOCVIEN;

struct _DS_HOCVIEN {
    int count = 0;
    HOCVIEN * root = NULL;
};
typedef struct _DS_HOCVIEN DS_HOCVIEN;

//dataType	  - lop - dslk 
struct _LOP {
    char Ma[10];
    int Status;
    char Phong[10];
    DS_HOCVIEN ds_HocVien;
    _LOP * pNext = NULL;
};
typedef struct _LOP LOP;

struct _DS_LOP {
    int count = 0;
    LOP * pHead_Lop;
};
typedef struct _DS_LOP DS_LOP;

// datatype - cap lop
struct _CAPLOP {
    char Ma[10];
    char Ten[10];
    int SoTiet;
    int HocPhi;
    DS_LOP ds_Lop;
};
typedef struct _CAPLOP CAPLOP;

const int SL_CapLop = 100;
struct _DS_CAPLOP {
    int count = 0;
    CAPLOP * dsCapLop[SL_CapLop];
};
typedef struct _DS_CAPLOP DS_CAPLOP;

#endif