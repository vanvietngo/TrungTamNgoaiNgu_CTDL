#include"lop.h"
int themLop(DS_CAPLOP &ds_CapLop){
	cout<<"... them lop ..."<<endl;
	// tim ma cap lop 
	char maCapLop[10];
	cout<<"Nhap ma CAP LOP cua lop can them: ";
	fflush(stdin);
	cin.getline(maCapLop,10);
	// check ma lop can them
	int posCL = timViTriXoaCapLop(ds_CapLop, maCapLop);
	if(posCL<0){
		// false
		cout<<"Ma CAP LOP khong ton tai"<<endl;
		return 0;
	}else{
		//true
		cout<<"post = "<<posCL;
		if(ds_CapLop.dsCapLop[posCL]->ds_Lop.count==0){
			cout<<"ds lop null";
			// tao data cho node lop de them vao dslk
			LOP* lop = new LOP;
			lop->pNext=NULL;
			cout<<"nhap trang thai (0-1-2): ";
				// check input number
			    while (!(cin >> lop -> Status)) {
			      cout << "gia tri phai la so: ";
			      cin.clear();
			      cin.ignore(123, '\n');
			      //       		return 0;
    			}
    			// check reange status 0-1-2
    			if(2<lop->Status || lop->Status<0){
    				// false
    				cout<<"trang thai khong hop le !";
					return 0;
				}else{
					// true
					cout<<"Nhap phong: ";
					fflush(stdin);
					cin.getline(lop->Phong,10);
					//add node dslk
					addNodeDSLK(ds_CapLop.dsCapLop[posCL]->ds_Lop, lop);
				}
		}else{
			cout<<"ds lop not null";
			cout<<ds_CapLop.dsCapLop[posCL]->ds_Lop.pHead_Lop;
		}
	}
	// them lop cho cap lop -- dslk don	
	
	return 0;
}

void addNodeDSLK(DS_LOP &ds_Lop, LOP* lop){
	if(ds_Lop.count == 0){
		// add head
		ds_Lop.pHead_Lop = lop;
		ds_Lop.count++;
	}else{
		LOP* p =  ds_Lop.pHead_Lop;
		while(p->pNext != NULL){
			p=p->pNext;
		}
		// tail
		p->pNext = lop;
//		lop->pNext=NULL;
	}
}

int xuatThongTinLop(DS_CAPLOP &ds_CapLop){
	char maCapLop[10];
	cout<<"Nhap ma CAP LOP cua lop can them: ";
	fflush(stdin);
	cin.getline(maCapLop,10);
	// check ma lop can them
	int posCL = timViTriXoaCapLop(ds_CapLop, maCapLop);
			if(ds_CapLop.dsCapLop[posCL]->ds_Lop.count==0){
			cout<<"ds lop null"<<endl;
		}else{
			cout<<"ds lop not null"<<endl;
//			cout<<ds_CapLop.dsCapLop[posCL]->ds_Lop.pHead_Lop;
			// xuat thong tin cac lop la dslk
			LOP* p = ds_CapLop.dsCapLop[posCL]->ds_Lop.pHead_Lop;
			while(p!=NULL){
				cout<<"inform: "<<p->Phong<<endl;
				p=p->pNext;
			}
		}
}


