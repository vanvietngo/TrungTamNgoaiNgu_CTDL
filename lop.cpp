#include"lop.h"

// main function
int themLop(DS_CAPLOP & ds_CapLop) {
    cout << "... them lop ..." << endl;
    // tim ma cap lop
    char maCapLop[10];
    cout << "Nhap ma CAP LOP cua lop can them: ";
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
    } else {
        //true
        //		cout<<"post = "<<posCL;
        //		if(ds_CapLop.dsCapLop[posCL]->ds_Lop.count==0){
        //			cout<<"ds lop null";
        // tao data cho node lop de them vao dslk
        LOP * lop = new LOP;
        lop -> pNext = NULL;
        cout << "nhap trang thai (0-1-2): ";
        // check input number
        while (!(cin >> lop -> Status)) {
            cout << "gia tri phai la so: ";
            cin.clear();
            cin.ignore(123, '\n');
            //       		return 0;
        }
        // check reange status 0-1-2
        if (2 < lop -> Status || lop -> Status < 0) {
            // false
            cout << "trang thai khong hop le !";
            return 0;
        } else {
            // true
            cout << "Nhap phong: ";
            fflush(stdin);
            cin.getline(lop -> Phong, 10);
            //add node dslk
            if (ds_CapLop.dsCapLop[posCL] -> ds_Lop.count == 0) {
                cout << "Nhap ma phong, lop trong: ";
                fflush(stdin);
                cin.getline(lop -> Ma, 10);
                addNodeDSLK(ds_CapLop.dsCapLop[posCL] -> ds_Lop, lop);
                ds_CapLop.dsCapLop[posCL] -> ds_Lop.count++;
                //
                // char b[20]="";
                // strcat(b, ds_CapLop.dsCapLop[posCL]->Ma);
                // strcat(b, ".txt");
                // saveFileLop(ds_CapLop.dsCapLop[posCL] -> ds_Lop, b);
                cout << "...complete..." << endl;
            } else {
                cout << "Nhap ma phong: ";
                fflush(stdin);
                cin.getline(lop -> Ma, 10);
                // check ma lop
                if (check_LapMaLop(ds_CapLop.dsCapLop[posCL] -> ds_Lop, lop -> Ma) > 0) {
                    //false
                    cout << "Ma lop da ton tai, khong the them" << endl;
                    return 0;
                } else {
                    //true
                    addNodeDSLK(ds_CapLop.dsCapLop[posCL] -> ds_Lop, lop);
                    ds_CapLop.dsCapLop[posCL] -> ds_Lop.count++;

                    // char b[20]="";
                    // strcat(b, ds_CapLop.dsCapLop[posCL]->Ma);
                    // strcat(b, ".txt");
                    // saveFileLop(ds_CapLop.dsCapLop[posCL] -> ds_Lop, b);
                    cout << "...complete..." << endl;
                    return 1;
                }
            }
        }
        // save file LOP voi name = ten ma CAP LOP
        // moi CAP LOP co 1 file LoOP rieng theo ma~
        return 0;
    }
}

int xuatThongTinLop(DS_CAPLOP & ds_CapLop) {
    char maCapLop[10];
    cout << "Nhap ma CAP LOP cua lop can show: ";
    fflush(stdin);
    cin.getline(maCapLop, 10);
    // check ma lop can them
    int posCL = timViTriXoaCapLop(ds_CapLop, maCapLop);
    // cout<<"Poscl = "<<posCL<<endl;
    if (posCL < 0) {
        // false
        cout << "Ma CAP LOP khong ton tai" << endl;
        return 0;
    } else {
        // cout<<"count ds lop = "<<ds_CapLop.dsCapLop[posCL] -> ds_Lop.count<<endl;
        if (ds_CapLop.dsCapLop[posCL] -> ds_Lop.count == 0) {
            cout << "ds lop null" << endl;
            return 0;
        } else {
            //			cout<<"ds lop not null"<<endl;
            // xuat thong tin cac lop la dslk
            LOP * p = ds_CapLop.dsCapLop[posCL] -> ds_Lop.pHead_Lop;
            cout<<endl;
            cout << "               Danh sach cap lop: " << endl<<endl;
            cout <<"     "<< setw(5) << left << "Stt";
            cout << setw(15) << left << "Ma";
            cout << setw(15) << left << "Phong";
            cout << setw(10) << left << "Status"<<endl;
            cout << setfill('.');
            cout << setw(50) << "" << endl;
            cout << setfill(' ');
            int k = 0;
            while (p != NULL) {
                cout <<"     " << setw(5) << left << k;

                cout << setw(15) << left << p -> Ma ;
                cout << setw(15) << left  << p -> Phong ;
                cout <<setw(10) << left  << p -> Status << endl;
                p = p -> pNext;
                k++;
            }
        }
    }

    return 0;
}

int xoaLop(DS_CAPLOP & ds_CapLop) {
    // nhap ma CAP LOP cua LOP can xoa
    char maCapLop[10];
    cout << "Nhap ma CAP LOP cua LOP can xoa: ";
    fflush(stdin);
    cin.getline(maCapLop, 10);

    // check ma cap lop va tim vi tri
    int PosCL = timViTriXoaCapLop(ds_CapLop,maCapLop);
    if(PosCL<0) {
        cout<<"Ma CAP LOP khong ton tai!"<<endl;
        return 0;
    }
    // nhap ma Lop can xoa
    char maLop[10];
    cout<<"Nhap MA LOP can xoa: ";
    fflush(stdin);
    cin.getline(maLop,10);

    // check ma lop  va tim vi tri trong dslk
    int posLop = check_LapMaLop(ds_CapLop.dsCapLop[PosCL]->ds_Lop, maLop);
    if(posLop < 0) {
        cout<<"ma LOP khong ton tai !"<<endl;
        return 0;
    }

    // xoa lop
    // cout<<"Ma lop co ton tai"<<endl;
    deleteNodeDSLK(ds_CapLop.dsCapLop[PosCL]->ds_Lop, posLop);
    // saveFileLop(ds_CapLop.dsCapLop[PosCL] -> ds_Lop, ds_CapLop.dsCapLop[PosCL]->Ma);
    cout<<" ... complete ..."<<endl;
    return 1;
}

// additional
int check_LapMaLop(DS_LOP ds_Lop, char * maLop) {
    if (ds_Lop.count == 0) {
        // cout << "count = 0 ko lap " << endl;
        // ds lop null
        return -2; // ko lap
    } else {
        LOP * p = ds_Lop.pHead_Lop;
        int pos = 0;
        while (p != NULL) {
            if (strcmp(p -> Ma, maLop) == 0) {
                return pos; // tim thay ma lop giong nhau,  position
            }
            p = p -> pNext;
            pos++;
        }
        // cout << "ko lap " << endl;
        return -1; // ko lap
    }
}

void addNodeDSLK(DS_LOP & ds_Lop, LOP * lop) {
    if (ds_Lop.count == 0) {
        // add head
        ds_Lop.pHead_Lop = lop;
    } else {
        LOP * p = ds_Lop.pHead_Lop;
        while (p -> pNext != NULL) {
            p = p -> pNext;
        }
        // tail
        p -> pNext = lop;
    }
}

int deleteNodeDSLK(DS_LOP & ds_Lop, int pos) {
    // check truong hop xoa
    LOP* p;
    // xoa dau
    if( pos == 0 ) {
        p = ds_Lop.pHead_Lop;
        ds_Lop.pHead_Lop = ds_Lop.pHead_Lop->pNext;
        p=NULL;
        delete p;
        ds_Lop.count--;
        return 1;
    }
    //
    // xoa cuoi
    if(pos == ds_Lop.count - 1) {
        p = ds_Lop.pHead_Lop;
        while(p->pNext->pNext != NULL) {
            p=p->pNext;
        }
        LOP* pdel = p->pNext;
        p->pNext = NULL;
        delete pdel;
        ds_Lop.count--;
        return 1;
    }
    // xoa node bat ki o giua
    int mid = 1;
    p = ds_Lop.pHead_Lop;
    while(p->pNext->pNext != NULL && mid != pos) {
        p = p->pNext;
        mid++;
    }
    // xoa
    LOP* pdel = p->pNext;
    p->pNext = p->pNext->pNext;
    delete pdel;
    ds_Lop.count --;
    return 1;
}




int hieuChinhLop(DS_CAPLOP &ds_CapLop)  {
    // nhap ma CAP LOP cua LOP can edit
    char maCapLop[10];
    cout << "Nhap ma CAP LOP cua LOP can Edit: ";
    fflush(stdin);
    cin.getline(maCapLop, 10);

    // check ma cap lop va tim vi tri
    int PosCL = timViTriXoaCapLop(ds_CapLop,maCapLop);
    if(PosCL<0) {
        cout<<"Ma CAP LOP khong ton tai!"<<endl;
        return 0;
    }
    // nhap ma Lop can edit
    char maLop[10];
    cout<<"Nhap MA LOP can edit: ";
    fflush(stdin);
    cin.getline(maLop,10);

    // check ma lop  va tim vi tri trong dslk
    int posLop = check_LapMaLop(ds_CapLop.dsCapLop[PosCL]->ds_Lop, maLop);

    if(posLop < 0) {
        cout<<"ma LOP khong ton tai !"<<endl;
        return 0;
    }

    // edit - ma lop co ton tai
    LOP* lopEdit ;
    lopEdit = ds_CapLop.dsCapLop[PosCL]->ds_Lop.pHead_Lop;
    // int z = 0;
    // while(z != posLop) {
    //     lopEdit = lopEdit->pNext;
    //     z++;
    // }

    //tim node edit

    while (lopEdit != NULL) {
        if (strcmp(lopEdit -> Ma, maLop) == 0 ) {
            // l la node moi de thay the cho node edit
            LOP* l = new LOP;
            l->pNext=NULL;
            cout<<"Nhap ma lop new: ";
            fflush(stdin);
            cin.getline(l -> Ma, 10);

            // check ma lop moi co trung vs ma lop cu ko
            int c = 0;
            LOP* lopEdit2 ;
            lopEdit2 = ds_CapLop.dsCapLop[PosCL]->ds_Lop.pHead_Lop;
            while (lopEdit2 != NULL) {
                if (strcmp(lopEdit2 -> Ma, l -> Ma) == 0 && c != posLop) {
                    cout<<"Ma lop moi: "<<l -> Ma<<" da ton tai ."<<endl;
                    return 0;
                }
                lopEdit2 = lopEdit2 -> pNext;
                c++;
            }
            // true , edit go on
            // ma lop moi ko trung voi cac ma lop cu khac
            cout<<"Nhap Status lop new: ";
            while (!(cin >> l -> Status)) {
                cout << "gia tri phai la so: ";
                cin.clear();
                cin.ignore(123, '\n');
                //       		return 0;
            }
            if (2 < l -> Status || l -> Status < 0) {
            // false
            cout << "trang thai khong hop le (0-1-2)!";
            return 0;
        }
            cout<<"Nhap phong lop new: ";
            fflush(stdin);
            cin.getline(l -> Phong, 10);

            // gan l vao vi tri can edit
            // ds_CapLop.dsCapLop[PosCL]->ds_Lop.pHead_Lop
            // them lai node da edit vao vi tri vua xoa
            // edit dau
            if(posLop == 0) {
                LOP* del;
                del = ds_CapLop.dsCapLop[PosCL]->ds_Lop.pHead_Lop;
                l->pNext = ds_CapLop.dsCapLop[PosCL]->ds_Lop.pHead_Lop->pNext;
                ds_CapLop.dsCapLop[PosCL]->ds_Lop.pHead_Lop = l;
                delete del;
                cout<<" ... complete ...";
                return 1;
            }

            // edit cuoi
            if(posLop == ds_CapLop.dsCapLop[PosCL]->ds_Lop.count-1) {
                // cout<<"edit cuoi"<<endl;
                LOP *p;
                p = ds_CapLop.dsCapLop[PosCL]->ds_Lop.pHead_Lop;
                while(p->pNext->pNext != NULL) {
                    p = p->pNext;
                }
                LOP* del ;
                del = p->pNext;
                p->pNext = l;
                cout<<" ... complete ...";
                return 1;
            }
            // edit vi tri o giua
                LOP *p;
                p = ds_CapLop.dsCapLop[PosCL]->ds_Lop.pHead_Lop;
                int k = 1;
                while(p->pNext->pNext != NULL && k != posLop) {

                    p = p->pNext;
                    k++;
                }
                LOP* del ;
                del = p->pNext;
                l->pNext = p->pNext -> pNext;
                p->pNext = l;
                cout<<" ... complete ...";
                return 1;





            // saveFileLop(ds_CapLop.dsCapLop[PosCL] -> ds_Lop, ds_CapLop.dsCapLop[PosCL]->Ma);
            cout<<" ... complete not done..."<<endl;
            return 1;

            // return pos; // tim thay ma lop giong nhau,  position
        }
        lopEdit = lopEdit -> pNext;

    }
    // ko tim thay
    cout<<"Khong tim thay ma LOP can edit"<<endl;
    return 0;
}
//
int saveFileLop(DS_LOP ds_Lop, char* fileLop) {
    FILE * f;
    f = fopen(fileLop, "wb");
    if (f == NULL) {
        cout << "";
    //        exit(1);
    } else {
        LOP* p = ds_Lop.pHead_Lop;
        while(p!= NULL) {
            fwrite(p, sizeof(LOP), 1, f);
            p= p->pNext;
        }
        fclose(f);
    }
}



//
int openFileLop(DS_LOP& ds_Lop, char* fileLop) {
    FILE * f;
    f = fopen(fileLop, "rb");
    if (f == NULL) {
        cout << "";
        //        exit(1);
    } else {
        LOP lop;
        ds_Lop.count = 0;
        while (fread( & lop, sizeof(LOP), 1, f)) {
            LOP* l = new LOP;
            *l = lop;
            l->pNext = NULL;

            if(ds_Lop.pHead_Lop == NULL) {
                ds_Lop.pHead_Lop = l;
                ds_Lop.count++;
            } else {
                LOP*  p;
                p = ds_Lop.pHead_Lop;
                while(p->pNext != NULL) {
                    p = p->pNext ;
                }
                p->pNext = l;
                ds_Lop.count++;
            }
        }
        fclose(f);
    }
    return 0;
}