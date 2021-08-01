#include"hocVien.h"
// main function
int themHocVien(DS_CAPLOP &ds_CapLop)   {
    cout << "... them HOC VIEN ..." << endl;
    // tim ma cap lop
    char maCapLop[10];
    cout << "Nhap ma CAP LOP: ";
    fflush(stdin);
    cin.getline(maCapLop, 10);
    // check ma lop can them
    //	cout<<"ma cl = "<<maCapLop;
    int posCL = timViTriXoaCapLop(ds_CapLop, maCapLop);
    //	cout<<"pos = "<<posCL;
    if (posCL < 0) {
        // false
        cout << "Ma CAP LOP khong ton tai" << endl;
        return 0;
    }
    // tim lop cua hoc vien
    cout <<" Nhap ma LOP cua hoc vien can them: ";
    char maLop[10];
    fflush(stdin);
    cin.getline(maLop, 10);
    // check valid maLop
    int posL = check_LapMaLop(ds_CapLop.dsCapLop[posCL]->ds_Lop, maLop);
    if(posL < 0)    {
        cout<<" Ma LOP khong ton tai"<<endl;
        return 0;
    }
    // Nhap thong tin hoc vien
        HOCVIEN* HocVien = new HOCVIEN;
    // char ho[10];
    // char ten[10];
    // char phai[10];
    cout<<"Nhap Ho HOC VIEN: ";
    fflush(stdin);
    cin.getline(HocVien->Ho, 10);
    cout<<"Nhap Ten HOC VIEN: ";
    fflush(stdin);
    cin.getline(HocVien->Ten, 10);
        bool check = true;
        char nam[] = "Nam";
        char nu[] = "Nu";
        char khac[] = "Khac";

    do  {
    cout<<"Nhap Phai HOC VIEN (Nam - Nu - Khac): ";
    fflush(stdin);
    cin.getline(HocVien->Phai, 10);
    
    if(strcmp(HocVien->Phai, nam)== 0) {
        check = false;
    }   else if(strcmp(HocVien->Phai, nu)== 0)   {
        check = false;
    }   else if(strcmp(HocVien->Phai,khac)== 0)   {
        check = false;
    }
    
    }   while(check);


    // tao node hoc vien

    int maHV    ;
    int checkMHV;
            LOP * lop ;
        lop = searchLop(ds_CapLop.dsCapLop[posCL]->ds_Lop, maLop);
    do  {

        // cout<<"lop tim thay la : "<<lop->Ma<<endl;
        maHV = rand() % (999 - 100 + 1) + 100;
        checkMHV = Check_lap_MHV(lop->ds_HocVien.root, maHV);
    }
    while( checkMHV == 1 )  ; 
    HocVien->Ma = maHV;
    addNodeHocVien(lop->ds_HocVien.root, HocVien);
    lop->ds_HocVien.count ++;
    cout<<"done"<<endl;


return 1;
}


int xuatDanhSach_HV(DS_CAPLOP & ds_CapLop)  {
    cout << "... them HOC VIEN ..." << endl;
    // tim ma cap lop
    char maCapLop[10];
    cout << "Nhap ma CAP LOP: ";
    fflush(stdin);
    cin.getline(maCapLop, 10);
    // check ma lop can them
    //	cout<<"ma cl = "<<maCapLop;
    int posCL = timViTriXoaCapLop(ds_CapLop, maCapLop);
    //	cout<<"pos = "<<posCL;
    if (posCL < 0) {
        // false
        cout << "Ma CAP LOP khong ton tai" << endl;
        return 0;
    }
    // tim lop cua hoc vien
    cout <<" Nhap ma LOP cua hoc vien can them: ";
    char maLop[10];
    fflush(stdin);
    cin.getline(maLop, 10);
    // check valid maLop
    int posL = check_LapMaLop(ds_CapLop.dsCapLop[posCL]->ds_Lop, maLop);
    if(posL < 0)    {
        cout<<" Ma LOP khong ton tai"<<endl;
        return 0;
    }
    LOP * lop ;
    lop = searchLop(ds_CapLop.dsCapLop[posCL]->ds_Lop, maLop);
    if(lop->ds_HocVien.count == 0)  {
        cout<<"Hoc vien trong ."<<endl;
        return 0;
    }
    else {
        InOrder(lop->ds_HocVien.root);
    }
}


//additional function



int addNodeHocVien(HOCVIEN *&root, HOCVIEN *HocVien){

    if( root == NULL)    {
        root = HocVien;
        return 0;
    }
    if(root->Ma > HocVien->Ma)    {
        addNodeHocVien(root->pLeft, HocVien );
    }   else if(root->Ma < HocVien->Ma) {
        addNodeHocVien(root->pRight, HocVien);
    } 
    return 0;
}

int Check_lap_MHV(HOCVIEN* root, int maHV) {
    if(root == NULL)    {
        return 0; // ko lap
    }
    if(root->Ma == maHV)    {
        return 1; // lap
    }else if(root->Ma > maHV)   {
        Check_lap_MHV(root->pLeft, maHV);
    }else {
        Check_lap_MHV(root->pRight, maHV);
    }
}

void InOrder(HOCVIEN* root){
    if(root != NULL)
    {
        InOrder(root->pLeft);
        cout<<"Hoc vien : "<<root->Ma<<endl;
        cout<<"Hoc vien : "<<root->Ho<<endl;
        InOrder(root->pRight);
    }
}