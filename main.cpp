#include <iostream>
#include"capLop.h"
#include"lop.h"
#include"hocVien.h"
#include"diem.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

DS_CAPLOP ds_CapLop;



int main() {
    int choice;
    char xxx[100]="";
    char urlCapLop[100] = "C:\\Users\\Node Js\\Documents\\Duy\\DB\\capLop.txt";
    char urlDB[100] = "C:\\Users\\Node Js\\Documents\\Duy\\DB\\";
    // char urlDBx[100]="";
    char fileLop[100]="";
    char fileHocVien[100]="";

    bool kt_choice = true;
//    system("cls");

    load_CapLopFile(ds_CapLop, urlCapLop);
    // system("cls");
    for(int count0 =0; count0 < ds_CapLop.count; count0++)	{
        strcpy(fileLop,xxx);
        strcat(fileLop,urlDB);
        strcat(fileLop, ds_CapLop.dsCapLop[count0]->Ma);
        strcat(fileLop, ".txt");
        openFileLop(ds_CapLop.dsCapLop[count0]->ds_Lop, fileLop);

        // open file Hoc Vien
        LOP* lop;
		lop = ds_CapLop.dsCapLop[count0]->ds_Lop.pHead_Lop;
        while(lop != NULL)  {
//            if(lop->ds_HocVien.root != NULL)    {
                // tao file HV
                strcpy(fileHocVien, xxx);
                strcat(fileHocVien,urlDB);
                strcat(fileHocVien, lop->Ma);
                strcat(fileHocVien, ".txt");  
                openFileHocVien(lop->ds_HocVien, fileHocVien);
//            }
            lop = lop->pNext;
        }
    }


    while (kt_choice) {
        cout << endl << endl << endl;
        cout << "------ ------ ------ ------ ------ -------" << endl;
        cout << "| Nhap lua chon xu li:                   |" << endl;
        //--------------------------------------
        cout << "| 0: exit                                |" << endl;
        cout << "| 1: Them cap lop                        |" << endl;
        cout << "| 2: Xuat thong tin cap lop              |" << endl;
        cout << "| 3: Xoa thong tin cap lop               |" << endl;
        cout << "| 4: Hieu chinh thong tin cap lop        |" << endl;
        cout << "| 5: Them lop                            |" << endl;
        cout << "| 6: Xuat thong tin lop                  |" << endl;
        cout << "| 7: Xoa lop                             |" << endl;
        cout << "| 8: Edit lop                            |" << endl;
        cout << "| 9: Them hoc vien                       |" << endl;
        cout << "| 10: Xuat thong tin hoc vien            |" << endl;
        cout << "| 11: Hieu chinh thong tin hoc vien      |" << endl;
        cout << "| 12: Xoa thong tin hoc vien             |" << endl;
        // cout << "| 13: Them cap lop                       |" << endl;
        cout << "| 13: Thong ke hoc vien theo cap lop     |" << endl;
        cout << "| 14: Top 10 lop HOC VIEN dong nhat      |" << endl;       
        cout << "| 20: SAVE                               |" << endl;

        //-----------------------------------
        cout<<endl;
        cout << "| Nhap lua chon:                       ";

        while(!(cin >> choice)) {
            cout<<"| gia tri phai la so !"<<endl;
            cin.clear();
            cin.ignore(123,'\n');
            cout << "| Nhap lua chon:                      ";
        }
        cout << endl;
        cout << "------ ------ ------ ------ ------ -------" << endl;
        cout << endl << endl << endl;
        switch (choice)
        {
        case 0: {
            kt_choice = false;
            break;
        }
        case 1:
        {
            themCapLop(ds_CapLop);
            break;
        }
        case 2:
        {
            // system("cls");
            xuatCapLop(ds_CapLop);
            break;
        }
        case 3:
        {
            // system("cls");
            xoaCapLop(ds_CapLop);
            break;
        }
        case 4:
        {
// system("cls");
            hieuChinhCapLop(ds_CapLop);
            break;
        }

        case 5:
        {
            themLop(ds_CapLop);
            break;
        }
        case 6:
        {
            xuatThongTinLop(ds_CapLop);
            break;
        }
        case 7:
        {
            xoaLop(ds_CapLop);
            break;
        }
        case 8:
        {
            hieuChinhLop(ds_CapLop);
            break;
        }
        case 9:
        {
            themHocVien(ds_CapLop);
            break;
        }
        case 10:
        {
            xuatDanhSach_HV(ds_CapLop);
            break;
        }
        case 11:
        {
            editHocVien(ds_CapLop);
            break;
        }
        case 12:
        {
            xoaHocVien(ds_CapLop);
            break;
        }
        // case 13:
        // {
        //     themDiem(ds_CapLop);
        //     break;
        // }
                case 13:
        {
            thongKeHV(ds_CapLop);
            break;
        }
        case 14:
        {
            _10LopHVdongNhat(ds_CapLop);
            break;
        }
        case 20:
        {
            save_CapLopFile(ds_CapLop, urlCapLop);

            // save file Lop
            for(int i =0; i< ds_CapLop.count; i++)	{
                if(ds_CapLop.dsCapLop[i]->ds_Lop.pHead_Lop != NULL)	{
                    strcpy(fileLop, xxx);
                    strcat(fileLop, urlDB);
                    strcat(fileLop, ds_CapLop.dsCapLop[i]->Ma);
                    strcat(fileLop, ".txt");
                    saveFileLop(ds_CapLop.dsCapLop[i]->ds_Lop, fileLop);

                    // save file Hoc Vien
                    LOP* lop = ds_CapLop.dsCapLop[i]->ds_Lop.pHead_Lop;
                    while(lop != NULL)  {
//                         if(lop->ds_HocVien.root != NULL)    {
                            // tao file HV
                            strcpy(fileHocVien, xxx);
                            strcat(fileHocVien,urlDB);
                            strcat(fileHocVien, lop->Ma);
                            strcat(fileHocVien, ".txt");  
                            saveFileHocVien(lop->ds_HocVien, fileHocVien);

                            // save file diem

                            //
//                         }
                        lop = lop->pNext;
                    }

                }
            }
            cout<<"   ... saved ..."<<endl;
            break;
        }
        }
    }

    return 0;
}