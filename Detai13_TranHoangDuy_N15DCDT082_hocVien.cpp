#include"Detai13_TranHoangDuy_N15DCDT082_hocVien.h"

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
    // HocVien
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
    cout << "... Hien thi thong tin HOC VIEN ..." << endl;
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
        cout << "                           Danh sach hoc vien: " << endl << endl;
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

int editHocVien(DS_CAPLOP & ds_CapLop) {
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
    cout << "Nhap ma HOC VIEN can edit: ";
    cin >> maHV;
    if (Check_lap_MHV(lop -> ds_HocVien.root, maHV) == 0) {
        cout << "Ma hoc vien khong ton tai" << endl;
        return 0;
    }
    // ma HV  hop le
    HOCVIEN * HocVien;
    HocVien = searchHocVien(lop -> ds_HocVien.root, maHV);
    // cout<<"maHV = "<<HocVien->Ma<<endl;
    // cout<<"Ho = "<<HocVien->Ho<<endl;
    cout << "nhap ho new: ";
    fflush(stdin);

    cin.getline(HocVien -> Ho, 20);
    cout << "nhap ten new: ";
    fflush(stdin);

    cin.getline(HocVien -> Ten, 20);
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
    cout << "done" << endl;
    return 0;
}

int xoaHocVien(DS_CAPLOP & ds_CapLop) {
    cout << "... Xoa HOC VIEN ..." << endl;
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
    cout << " Nhap ma LOP cua hoc vien can xoa: ";
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
    cout << "Nhap ma HOC VIEN can xoa: ";
    cin >> maHV;
    if (Check_lap_MHV(lop -> ds_HocVien.root, maHV) == 0) {
        cout << "Ma hoc vien khong ton tai" << endl;
        return 0;
    }
    // xoa - node cnp
    xoaNodeCNP(lop -> ds_HocVien.root, maHV);
    lop -> ds_HocVien.count--;
    cout << "... complete ..." << endl;

}

int thongKeHV(DS_CAPLOP ds_CapLop) {
    cout << "... HOC VIEN theo CAP LOP..." << endl;
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
    // show
    showHVtheoCL(ds_CapLop.dsCapLop[posCL]);
    return 0;
}

int _10LopHVdongNhat(DS_CAPLOP ds_CapLop) {
    DS_countMaxLop ds;

    for (int i = 0; i < ds_CapLop.count; i++) {
        if (ds_CapLop.dsCapLop[i] -> ds_Lop.pHead_Lop != NULL) {
            // cout<<"ma CAP LOP: "<<ds_CapLop.dsCapLop[i]->Ma<<endl;

            LOP * lop = ds_CapLop.dsCapLop[i] -> ds_Lop.pHead_Lop;
            while (lop != NULL) {
                // cout<<"ma Lop = "<<lop->Ma<<endl;
                countMaxLop * p = new countMaxLop;
                p -> maCapLop = ds_CapLop.dsCapLop[i] -> Ma;
                p -> maLop = lop -> Ma;
                p -> countHV = lop -> ds_HocVien.count;
                addNode_10HV_MAX(ds, p);
                ds.count++;
                lop = lop -> pNext;
            }

        }

    }
    // showNode_10Max(ds);
    // chuyen dslk -> array
    countMaxLop array[ds.count];
    countMaxLop * p3 = ds.pHead;
    int z = 0;
    while (p3 != NULL) {
        array[z] = * p3;
        p3 = p3 -> pNext;
        z++;
    }
    // sort array
    for (int j = 0; j < ds.count - 1; j++) {
        // cout<<"ma lop =- "<<array[j].maLop<<endl;
        for (int l = j + 1; l < ds.count; l++) {
            if (array[j].countHV < array[l].countHV) {
                countMaxLop temp = array[j];
                array[j] = array[l];
                array[l] = temp;
            }
        }
    }

    // show 10st array
    cout << "                Top 10 lop co HOC VIEN dong nhat: " << endl << endl;
    cout <<"     "<< setw(5) << left << "Stt";
    cout << setw(15) << left << "Ma cap lop";
    cout << setw(15) << left << "Ma lop";
    cout << setw(20) << left << "So luong hoc vien"<<endl;
    cout << setfill('.');
    cout << setw(70) << "" << endl;
    cout << setfill(' ');
    if (ds.count > 10) {
        for (int u = 0; u < 10; u++) {
            cout <<"     "<< setw(5) << left << u;
            cout << setw(15)<< array[u].maCapLop ;
            cout << setw(15) << array[u].maLop ;
            cout << setw(20)<< array[u].countHV << endl;
        }
    } else if (ds.count > 0) {
        for (int u = 0; u < ds.count; u++) {
            cout <<"     "<< setw(5) << left << u;
            cout << setw(15) << array[u].maCapLop ;
            cout << setw(15) << array[u].maLop ;
            cout << setw(15) << array[u].countHV <<  endl;
        }
    } else {
        cout << "Khong co lop ton tai !";
    }

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
    // return 0;
}

int Check_lap_MHV(HOCVIEN * root, int maHV) {
    if (root == NULL) {
        return 0; // ko lap
    }
    if (root -> Ma == maHV) {
        return 1; // lap
    } else if (root -> Ma > maHV) {
        Check_lap_MHV(root -> pLeft, maHV);
    } else if (root -> Ma < maHV) {
        Check_lap_MHV(root -> pRight, maHV);
    }
}

void InOrder(HOCVIEN * root) {
    if (root != NULL) {
        cout << "     " << setw(15) << left << root -> Ma;
        cout << setw(25) << left << root -> Ho;
        cout << setw(25) << left << root -> Ten;
        cout << setw(15) << left << root -> Phai << endl;
        InOrder(root -> pLeft);
        InOrder(root -> pRight);
    }
}

HOCVIEN * searchHocVien(HOCVIEN * root, int maHV) {

    if (root -> Ma == maHV) {
        return root; // lap
    } else if (root -> Ma > maHV) {
        searchHocVien(root -> pLeft, maHV);
    } else {
        searchHocVien(root -> pRight, maHV);
    }
    // return 0;
}

int xoaNodeCNP(HOCVIEN * & root, int maHV) {
    if (root -> Ma == maHV) {
        cout << "mahv xoa = " << maHV << endl;
        if (root -> pRight == NULL) {
            cout << "1 l child" << endl;
            HOCVIEN * del;
            del = root;
            root = root -> pLeft;
            delete del;
            return 1;
        } else if (root -> pLeft == NULL) {
            cout << "1 r child" << endl;
            HOCVIEN * del;
            del = root;
            root = root -> pRight;
            delete del;
            return 1;
        } else {
            cout << "2 child" << endl;
            // node have 2 child
            HOCVIEN * x = leftMost(root -> pRight);
            root = x;
            delete x;
            return 1;
        }
        return 1; // lap
    } else if (root -> Ma > maHV) {
        xoaNodeCNP(root -> pLeft, maHV);
    } else if (root -> Ma < maHV) {
        xoaNodeCNP(root -> pRight, maHV);
    }
}

// node trai nhat cua node con ben phai cua node can xoa;
HOCVIEN * leftMost(HOCVIEN * root) {
    if (root -> pLeft == NULL) {
        return root;
    } else {
        leftMost(root -> pLeft);
    }
}

void writeFile(HOCVIEN * root, FILE * f) {
    if (root != NULL) {
        fwrite(root, sizeof(HOCVIEN), 1, f);
        writeFile(root -> pLeft, f);
        writeFile(root -> pRight, f);
    }
}

int saveFileHocVien(DS_HOCVIEN ds_HocVien, char * fileHocVien) {
    FILE * f;
    f = fopen(fileHocVien, "wb");
    if (f == NULL) {
        cout << "";
        //        exit(1);
    } else {
        HOCVIEN * p = ds_HocVien.root;
        writeFile(p, f);
        fclose(f);
    }
}

// open file

int openFileHocVien(DS_HOCVIEN & ds_HocVien, char * fileHocVien) {
    //    cout<<"file = "<<fileHocVien<<endl;
    FILE * fileHV;
    fileHV = fopen(fileHocVien, "rb");
    if (fileHV == NULL) {
        cout << "";
        //        exit(1);
    } else {
        HOCVIEN hocvien;
        ds_HocVien.count = 0;
        while (fread( & hocvien, sizeof(HOCVIEN), 1, fileHV)) {
            HOCVIEN * hv = new HOCVIEN;
            * hv = hocvien;
            hv -> pLeft = NULL;
            hv -> pRight = NULL;
            addNodeHocVien(ds_HocVien.root, hv);
            ds_HocVien.count++;
        }
    }
    fclose(fileHV);
    return 0;
}

// show hv theo cl

int showHVtheoCL(CAPLOP * capLop) {
    cout << endl << endl << "Ma CAP LOP: " << capLop -> Ma << endl;
    LOP * lop;
    lop = capLop -> ds_Lop.pHead_Lop;
    while (lop != NULL) {
        cout << "Ma lop: " << lop -> Ma << endl;
        cout << "Danh sach hoc vien: " << endl << endl;
        cout << "     " << setw(15) << left << "Ma";
        cout << setw(25) << left << "Ho";
        cout << setw(25) << left << "Ten";
        cout << setw(15) << left << "Phai" << endl;
        cout << setfill('.');
        cout << setw(85) << "" << endl;
        cout << setfill(' ');
        InOrder(lop -> ds_HocVien.root);
        cout << endl << endl;
        lop = lop -> pNext;
    }
}

// 10 lop hv dong nhat 
int addNode_10HV_MAX(DS_countMaxLop & ds, countMaxLop * lop) {
    if (ds.count == 0) {
        // add head
        ds.pHead = lop;
    } else {
        countMaxLop * p = ds.pHead;
        while (p -> pNext != NULL) {
            p = p -> pNext;
        }
        // tail
        p -> pNext = lop;
    }
}

int showNode_10Max(DS_countMaxLop ds) {
    countMaxLop * p = ds.pHead;
    cout << "cout all lop = " << ds.count << endl;
    while (p != NULL) {
        cout << "ma CL: " << p -> maCapLop << endl;
        cout << "malop: " << p -> maLop << endl;
        cout << "cout HV: " << p -> countHV << endl << endl << endl << endl;
        p = p -> pNext;
    }
}