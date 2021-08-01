#include"hocVien.h"

 // main function

int themHocVien(DS_CAPLOP & ds_CapLop) {
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
    cout << " Nhap ma LOP cua hoc vien: ";
    char maLop[10];
    fflush(stdin);
    cin.getline(maLop, 10);
    // check valid maLop
    int posL = check_LapMaLop(ds_CapLop.dsCapLop[posCL] -> ds_Lop, maLop);
    if (posL < 0) {
        cout << " Ma LOP khong ton tai" << endl;
        return 0;
    }
    // Nhap thong tin hoc vien
    HOCVIEN * HocVien = new HOCVIEN;
    // char ho[10];
    // char ten[10];
    // char phai[10];
    cout << "Nhap Ho HOC VIEN: ";
    fflush(stdin);
    cin.getline(HocVien -> Ho, 20);
    cout << "Nhap Ten HOC VIEN: ";
    fflush(stdin);
    cin.getline(HocVien -> Ten, 20);
    bool check = true;
    char nam[] = "Nam";
    char nu[] = "Nu";
    char khac[] = "Khac";

    do {
        cout << "Nhap Phai HOC VIEN (Nam - Nu - Khac): ";
        fflush(stdin);
        cin.getline(HocVien -> Phai, 10);

        if (strcmp(HocVien -> Phai, nam) == 0) {
            check = false;
        } else if (strcmp(HocVien -> Phai, nu) == 0) {
            check = false;
        } else if (strcmp(HocVien -> Phai, khac) == 0) {
            check = false;
        }

    } while (check);

    // tao node hoc vien

    int maHV;
    int checkMHV;
    LOP * lop;
    lop = searchLop(ds_CapLop.dsCapLop[posCL] -> ds_Lop, maLop);
    do {

        // cout<<"lop tim thay la : "<<lop->Ma<<endl;
        maHV = rand() % (999 - 100 + 1) + 100;
        checkMHV = Check_lap_MHV(lop -> ds_HocVien.root, maHV);
    }
    while (checkMHV == 1);
    HocVien -> Ma = maHV;
    addNodeHocVien(lop -> ds_HocVien.root, HocVien);
    lop -> ds_HocVien.count++;
    cout << "done" << endl;

    return 1;
}

int xuatDanhSach_HV(DS_CAPLOP & ds_CapLop) {
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
    cout << " Nhap ma LOP cua hoc vien: ";
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
    if (lop -> ds_HocVien.count == 0) {
        cout << "Hoc vien trong ." << endl;
        return 0;
    } else {
        cout << "                           Danh sach cap lop: " << endl << endl;
        cout << "     " << setw(15) << left << "Ma";
        cout << setw(25) << left << "Ho";
        cout << setw(25) << left << "Ten";
        cout << setw(15) << left << "Phai" << endl;
        cout << setfill('.');
        cout << setw(85) << "" << endl;
        cout << setfill(' ');
        InOrder(lop -> ds_HocVien.root);
    }
}

int editHocVien(DS_CAPLOP &ds_CapLop)   {
    cout << "... edit HOC VIEN ..." << endl;
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
    cout<<"Nhap ma HOC VIEN can edit: ";
    cin >> maHV;
    if(Check_lap_MHV(lop->ds_HocVien.root, maHV) == 0)  {
        cout<<"Ma hoc vien khong ton tai"<<endl;
        return 0;
    }
    HOCVIEN* HocVien;
    HocVien = searchHocVien(lop->ds_HocVien.root, maHV);
    // cout<<"maHV = "<<HocVien->Ma<<endl;
    // cout<<"Ho = "<<HocVien->Ho<<endl;
    cout<<"nhap ho new: ";
            fflush(stdin);

    cin.getline(HocVien->Ho, 20);
    cout <<"nhap ten new: ";
            fflush(stdin);

    cin.getline(HocVien->Ten, 20);
    bool check = true;
    char nam[] = "Nam";
    char nu[] = "Nu";
    char khac[] = "Khac";

    do {
        cout << "Nhap Phai HOC VIEN new (Nam - Nu - Khac): ";
        fflush(stdin);
        cin.getline(HocVien -> Phai, 10);

        if (strcmp(HocVien -> Phai, nam) == 0) {
            check = false;
        } else if (strcmp(HocVien -> Phai, nu) == 0) {
            check = false;
        } else if (strcmp(HocVien -> Phai, khac) == 0) {
            check = false;
        }

    } while (check);
cout<<"done"<<endl;
return 0;



}

//additional function

int addNodeHocVien(HOCVIEN * & root, HOCVIEN * HocVien) {

    if (root == NULL) {
        root = HocVien;
        return 0;
    }
    if (root -> Ma > HocVien -> Ma) {
        addNodeHocVien(root -> pLeft, HocVien);
    } else if (root -> Ma < HocVien -> Ma) {
        addNodeHocVien(root -> pRight, HocVien);
    }
    return 0;
}

int Check_lap_MHV(HOCVIEN * root, int maHV) {
    if (root == NULL) {
        return 0; // ko lap
    }
    if (root -> Ma == maHV) {
        return 1; // lap
    } else if (root -> Ma > maHV) {
        Check_lap_MHV(root -> pLeft, maHV);
    } else if (root -> Ma < maHV){
        Check_lap_MHV(root -> pRight, maHV);
    }
}

void InOrder(HOCVIEN * root) {
    if (root != NULL) {
        InOrder(root -> pLeft);
        cout << "     " << setw(15) << left << root -> Ma;
        cout << setw(25) << left << root -> Ho;
        cout << setw(25) << left << root -> Ten;
        cout << setw(15) << left << root -> Phai << endl;
        InOrder(root -> pRight);
    }
}

HOCVIEN* searchHocVien(HOCVIEN * root, int maHV) {

    if (root -> Ma == maHV) {
        return root; // lap
    } else if (root -> Ma > maHV) {
        searchHocVien(root -> pLeft, maHV);
    } else {
        searchHocVien(root -> pRight, maHV);
    }
    // return 0;
}