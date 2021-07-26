#include <iostream>
#include"capLop.h"
#include"lop.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

DS_CAPLOP ds_CapLop;



int main() {
	int choice;
	load_CapLopFile(ds_CapLop);

		bool kt_choice = true;
		system("cls");

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
			cout << "| 5: Them     lop                        |" << endl;
			//-----------------------------------
			cout<<endl;
			cout << "| Nhap lua chon:                       ";
			
			while(!(cin >> choice)){
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
			case 0:{
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
					xuatCapLop(ds_CapLop);
					break;
				}
			case 3:
				{
					xoaCapLop(ds_CapLop);
					break;
				}
			case 4:
				{
					hieuChinhCapLop(ds_CapLop);
					break;
				}
			
			case 5:
				{
					themLop(ds_CapLop);
					save_CapLopFile(ds_CapLop);
					break;
				}		
			case 6:
				{
					xuatThongTinLop(ds_CapLop);
					break;
				}
						case 7:
				{
//					xuatThongTinLop(ds_CapLop);
					break;
				}
						case 8:
				{
//					xuatThongTinLop(ds_CapLop);
					break;
				}	
		}
	}
		
	return 0;
}