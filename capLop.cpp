#include"capLop.h"

// main function

int themCapLop(DS_CAPLOP & ds_CapLop) {
    // check dk them cap lop
    //false
    if (ds_CapLop.count >= SL_CapLop) {
        cout << "so luong cap lop da toi da khong the them !" << endl;
        return 0;
    }
    //true
    else {
        CAPLOP * CapLop = new CAPLOP;
        cout << "  -------- Them cap lop --------" << endl;
        cout << "Nhap ma: ";
        //    cin.ignore();
        fflush(stdin);
        cin.getline(CapLop -> Ma, 10);
        cout << "Nhap ten: ";
        fflush(stdin);
        cin.getline(CapLop -> Ten, 10);
        cout << "Nhap so tiet: ";
        while (!(cin >> CapLop -> SoTiet)) {
            cout << "gia tri phai la so";
            cin.clear();
            cin.ignore(123, '\n');
            return 0;
        }
        cout << "Nhap hoc phi: ";
        while (!(cin >> CapLop -> HocPhi)) {
            cout << "gia tri phai la so";
            cin.clear();
            cin.ignore(123, '\n');
            return 0;
        }
        // check lap Ma cap lop
        //True
        if (check_lap_MCL(ds_CapLop, CapLop) == 0) {
            ds_CapLop.dsCapLop[ds_CapLop.count] = CapLop;
            ds_CapLop.count++;
            cout << "complete !" << endl;
            save_CapLopFile(ds_CapLop);
        } else {
            cout << "loi nhap data" << endl;
        }
    }
    return 0;
}

int xoaCapLop(DS_CAPLOP & ds_CapLop) {

    cout << "  -------- Xoa cap lop --------" << endl;
    //  string MaCapLop = "";
    char MaCapLop[10];
    cout << "Nhap ma: ";
    //  cin.ignore();
    //  getline(cin, MaCapLop);
    fflush(stdin);
    cin.getline(MaCapLop, 10);
    cout << endl;
    // search pos delete
    int pos = timViTriXoaCapLop(ds_CapLop, MaCapLop);
    // check ma cap lop
    //	cout<<"pos = "<<pos;
    if (pos >= 0) {
        if (pos == ds_CapLop.count - 1) {
            delete ds_CapLop.dsCapLop[pos];
            ds_CapLop.dsCapLop[pos] = NULL;
            ds_CapLop.count--;
            cout << "complete !" << endl;
            save_CapLopFile(ds_CapLop);
            return 1;
        } else {
            CAPLOP * CapLopDel = ds_CapLop.dsCapLop[pos];
            for (int i = pos; i < ds_CapLop.count - 1; ++i) {
                ds_CapLop.dsCapLop[i] = ds_CapLop.dsCapLop[i + 1];
            }
            ds_CapLop.dsCapLop[ds_CapLop.count - 1] = NULL;
            ds_CapLop.count--;
            cout << "complete !" << endl;
            save_CapLopFile(ds_CapLop);
            CapLopDel = NULL;
            delete CapLopDel;
            return 1;
        }
    } else {
        cout << "Khong tim thay ma cap lop " << endl;
        return 0;
    }
}

int hieuChinhCapLop(DS_CAPLOP & ds_CapLop) {
    //  string maCapLop = "";
    char maCapLop[10];
    CAPLOP * CapLop = new CAPLOP;

    cout << "Nhap ma cap lop: ";
    //  cin.ignore();
    //  getline(cin, maCapLop);
    fflush(stdin);
    cin.getline(maCapLop, 10);
    int pos = timViTriXoaCapLop(ds_CapLop, maCapLop);
    //int pos = -1;
    //cout<<"pos = "<<pos;
    if (pos >= 0) {
        cout << "Nhap ma new: ";
        cin.getline(CapLop -> Ma, 10);
        cout << endl;
        cout << "Nhap ten new: ";
        cin.getline(CapLop -> Ten, 10);
        cout << endl;
        cout << "Nhap so tiet new: ";
        while (!(cin >> CapLop -> SoTiet)) {
            cout << "gia tri phai la so: ";
            cin.clear();
            cin.ignore(123, '\n');
            //       		return 0;
        }
        cout << "Nhap hoc phi new: ";
        while (!(cin >> CapLop -> HocPhi)) {
            cout << "gia tri phai la so: ";
            cin.clear();
            cin.ignore(123, '\n');
            //       		return 0;
        }
        // check lap Ma cap lop
        //True
        //    cout<<"check lap = "<<check_lapMaCapLopLapEdit(ds_CapLop, pos, CapLop -> Ma);
        if (check_lapMaCapLopLapEdit(ds_CapLop, pos, CapLop -> Ma) == -1) {
            CAPLOP * CapLopDel = ds_CapLop.dsCapLop[pos];
            ds_CapLop.dsCapLop[pos] = CapLop;
            CapLopDel = NULL;
            delete CapLopDel;
            cout << "complete !" << endl;
            save_CapLopFile(ds_CapLop);
        } else {
            if (check_lapMaCapLopLapEdit(ds_CapLop, pos, CapLop -> Ma) == -2) {
                cout << "Danh sach trong !" << endl;
                return 0;
            } else {
                cout << "Ma CAP LOP da ton tai" << endl;
                return 0;
            }
        }
    } else {
        cout << "Khong tim thay ma cap lop !";
        return 0;
    }
}

void xuatCapLop(DS_CAPLOP ds_CapLop) {
    //	cout << setw(5) << left << 1;
    cout << "Danh sach cap lop: " << endl;
    cout << setw(5) << left << "Stt";
    cout << setw(10) << left << "Ma";
    cout << setw(25) << left << "Ten";
    cout << setw(10) << left << "So tiet";
    cout << setw(25) << left << "Hoc Phi" << endl;
    cout << setfill('.');
    cout << setw(70) << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < ds_CapLop.count; i++) {
        cout << setw(5) << left << i;
        cout << setw(10) << left << ds_CapLop.dsCapLop[i] -> Ma;
        cout << setw(25) << left << ds_CapLop.dsCapLop[i] -> Ten;
        cout << setw(10) << left << ds_CapLop.dsCapLop[i] -> SoTiet;
        cout << setw(25) << left << ds_CapLop.dsCapLop[i] -> HocPhi << endl;
    }
}

// additional function

int check_lap_MCL(DS_CAPLOP ds_CapLop, CAPLOP * CapLop) {
    if (ds_CapLop.count == 0) return 0;
    for (int i = 0; i < ds_CapLop.count; i++) {

        //    if (CapLop -> Ma == ds_CapLop.dsCapLop[i] -> Ma) {
        if (strcmp(CapLop -> Ma, ds_CapLop.dsCapLop[i] -> Ma) == 0) {
            cout << "trung ma cap lop ! khong the them !";
            return 1;
        }
    }
    return 0;
}

int timViTriXoaCapLop(DS_CAPLOP ds_CapLop, char * maCapLop) {
    if (ds_CapLop.count == 0) 
        return -2; // danh sach trong
        
    for (int i = 0; i < ds_CapLop.count; i++) {
        // if (CapLop == ds_CapLop.dsCapLop[i] -> Ma) {
        if (strcmp(maCapLop, ds_CapLop.dsCapLop[i] -> Ma) == 0) {
            return i; // tim thay ma cap lop theo input string
        }
    }
    return -1; // ko tim thay ma cap lop
}

int check_lapMaCapLopLapEdit(DS_CAPLOP ds_CapLop, int pos, char * MaEdit) {

    if (ds_CapLop.count == 0) {
        return -2; // false for edit
    }
    for (int i = 0; i < ds_CapLop.count; i++) {
        if (strcmp(MaEdit, ds_CapLop.dsCapLop[i] -> Ma) == 0 && i != pos) {
            return i; // false for edit
        }
    }
    return -1; // true for edit
}

int load_CapLopFile(DS_CAPLOP & ds_CapLop) {
    CAPLOP num[100];
    FILE * fptr;
    if ((fptr = fopen(pathCapLop, "rb")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    int z = 0;
    while (fread( & num[z], sizeof(CAPLOP), 1, fptr)) {
        z++;
    }
    for (int i = 0; i < z; i++) {
        ds_CapLop.dsCapLop[i] = & num[i];
        ds_CapLop.count++;
    }
    fclose(fptr);

    return 0;
}

int save_CapLopFile(DS_CAPLOP ds_CapLop) {
    FILE * f;
    f = fopen(pathCapLop, "wb");
    if (f == NULL) {
        cout << "error open file";
        exit(1);
    } else {
        for (int i = 0; i < ds_CapLop.count; i++) {
            fwrite(ds_CapLop.dsCapLop[i], sizeof(CAPLOP), 1, f);
        }
        fclose(f);
    }
}
