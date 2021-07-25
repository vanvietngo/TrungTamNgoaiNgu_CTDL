#include"lop.h"

// main function
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
//		cout<<"post = "<<posCL;
//		if(ds_CapLop.dsCapLop[posCL]->ds_Lop.count==0){
//			cout<<"ds lop null";
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
					if(ds_CapLop.dsCapLop[posCL]->ds_Lop.count==0){
						cout<<"Nhap ma phong, lop trong: ";
						fflush(stdin);
						cin.getline(lop->Ma,10);
						addNodeDSLK(ds_CapLop.dsCapLop[posCL]->ds_Lop,lop);
						ds_CapLop.dsCapLop[posCL]->ds_Lop.count++;
//						cout<<ds_CapLop.dsCapLop[posCL]->ds_Lop.count<<"...............";
					}else{
						cout<<"Nhap ma phong: ";
						fflush(stdin);
						cin.getline(lop->Ma,10);
						// check ma lop
						if(check_LapMaLop(ds_CapLop.dsCapLop[posCL]->ds_Lop,lop->Ma) >0){
							//false
							cout<<"Ma lop da ton tai, khong the them"<<endl;
							return 0;
						}else{
							//true
						addNodeDSLK(ds_CapLop.dsCapLop[posCL]->ds_Lop,lop);
						ds_CapLop.dsCapLop[posCL]->ds_Lop.count++;
//						cout<<ds_CapLop.dsCapLop[posCL]->ds_Lop.count<<"...";
						return 1;
						}
					}
	}
	// them lop cho cap lop -- dslk don	
	
	return 0;
}
}


int xuatThongTinLop(DS_CAPLOP &ds_CapLop){
	char maCapLop[10];
	cout<<"Nhap ma  LOP cua lop can show: ";
	fflush(stdin);
	cin.getline(maCapLop,10);
	// check ma lop can them
	int posCL = timViTriXoaCapLop(ds_CapLop, maCapLop);
			if(ds_CapLop.dsCapLop[posCL]->ds_Lop.count==0){
			cout<<"ds lop null"<<endl;
		}else{
//			cout<<"ds lop not null"<<endl;
			// xuat thong tin cac lop la dslk
			LOP* p = ds_CapLop.dsCapLop[posCL]->ds_Lop.pHead_Lop;
			while(p!=NULL){
				cout<<"Ma: "<<p->Ma<<endl;
				cout<<"Phong: "<<p->Phong<<endl;
				cout<<"Status: "<<p->Status<<endl;
				p=p->pNext;
			}
		}
}


// additional
int check_LapMaLop(DS_LOP ds_Lop,char *maLop){
	if(ds_Lop.count==0){
		cout<<"count = 0 ko lap "<<endl;
		return -1;// ko lap
	}else{
		LOP*p = ds_Lop.pHead_Lop;
		int pos = 0;
		while(p!=NULL){
			if(strcmp(p->Ma, maLop)==0){
				return pos; // tim thay ma lop giong nhau,  position
			}
			p=p->pNext;
			pos++;
		}
		cout<<"ko lap "<<endl;
		return -1; // ko lap
	}
}

void addNodeDSLK(DS_LOP &ds_Lop, LOP* lop){
	if(ds_Lop.count == 0){
		// add head
		ds_Lop.pHead_Lop = lop;
	}else{
		LOP* p =  ds_Lop.pHead_Lop;
		while(p->pNext != NULL){
			p=p->pNext;
		}
		// tail
		p->pNext = lop;
	}
}





int deleteNodeDSLK(DS_LOP &ds_Lop, int pos){
	if(ds_Lop.count == 0){
		cout<<"danh sach LOP trong."<<endl;
		return 0;
	}
	// ds not null
	
	LOP* p = ds_Lop.pHead_Lop;
	// xoa dau
	if(pos==0){
		ds_Lop.pHead_Lop = ds_Lop.pHead_Lop->pNext;
		delete p;
		ds_Lop.count--;
		return 1;//done
	}
		// xoa vi tri bat ki
	
	int k = 1;
		
//	while(p->Pnext->Pnext != NULL && k != pos){
//		if(strcmp(p->Ma, maLop)==0){//bang nhau
//		    p = p->Pnext;
//            ++k;
//	}
//		
//}
}


