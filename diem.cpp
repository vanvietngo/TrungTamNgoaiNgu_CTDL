#include"diem.h"

//  main funcrion
int themDiem(DS_CAPLOP &ds_CapLop)  {
    cout << "... them DIEM ..." << endl;
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
    cout << " Nhap ma LOP cua hoc vien can edit: ";
    char maLop[10];
    fflush(stdin);
    cin.getline(maLop, 10);
    // check valid maLop
    int posL = check_LapMaLop(ds_CapLop.dsCapLop[posCL] -> ds_Lop, maLop);
    if (posL < 0) {
        cout << " Ma LOP khong ton tai" << endl;
        return 0;
    }
    LOP * lop;
    lop = searchLop(ds_CapLop.dsCapLop[posCL] -> ds_Lop, maLop);
    // check ma hoc vien
    int maHV;
    cout << "Nhap ma HOC VIEN can edit: ";
    cin >> maHV;
    if (Check_lap_MHV(lop -> ds_HocVien.root, maHV) == 0) {
        cout << "Ma hoc vien khong ton tai" << endl;
        return 0;
    }
    // them diem
    HOCVIEN * HocVien;
    HocVien = searchHocVien(lop -> ds_HocVien.root, maHV);
        //
    int checkExit;
    do{
        DIEM* diem = new DIEM;
        cout<<"Nhap skill (0:nghe ; 1:noi ; 2:doc ; 3:viet): ";
        cout<<"Nhap 0: exit , so bat ki de tiep tuc them: ";
            while (!(cin >> checkExit)) {
            cout << "gia tri phai la so";
            cin.clear();
            cin.ignore(123, '\n');
//            return 0;
        }
        
    }while(!checkExit);


}