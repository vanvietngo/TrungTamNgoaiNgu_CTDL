#include"capLop.h"

// main function

int themCapLop(DS_CAPLOP &ds_CapLop){
	// check dk them cap lop
	//false
	if(ds_CapLop.count >= SL_CapLop){
		cout<<"so luong cap lop da toi da khong the them !"<<endl;
		return 0;
	}
	//true
	else{
		CAPLOP* CapLop = new CAPLOP;
		cout<<"  -------- Them cap lop --------"<<endl;
		cout<<"Nhap ma: ";cin.ignore(); getline(cin,CapLop->Ma); 
		cout<<"Nhap ten: "; getline(cin, CapLop->Ten); 
       	cout<<"Nhap so tiet: ";
       	while(!(cin>>CapLop->SoTiet)){
       		cout<<"gia tri phai la so";
       		cin.clear();
       		cin.ignore(123,'\n');
       		return 0;
		   }
       	cout<<"Nhap hoc phi: ";
       	while(!(cin>>CapLop->HocPhi)){
       		cout<<"gia tri phai la so";
       		cin.clear();
       		cin.ignore(123,'\n');
       		return 0;
		   }
		// check lap Ma cap lop
		//True
		if(check_lap_MCL(ds_CapLop, CapLop)==0){
			ds_CapLop.dsCapLop[ds_CapLop.count]=CapLop;
			ds_CapLop.count++;
			cout<<"complete !"<<endl;
			save_CapLopFile(ds_CapLop);
		}
	}
	return 0;
}

int xoaCapLop(DS_CAPLOP &ds_CapLop){
	
	cout<<"  -------- Xoa cap lop --------"<<endl;
	string MaCapLop = "";
	cout<<"Nhap ma: ";cin.ignore(); getline(cin,MaCapLop); cout<<endl;
	// search pos delete
	int pos = timViTriXoaCapLop( ds_CapLop,  MaCapLop);
	// check ma cap lop
	
	if(pos >= 0){
		if(pos==ds_CapLop.count-1){
			delete ds_CapLop.dsCapLop[pos];
			ds_CapLop.dsCapLop[pos] = NULL;
			ds_CapLop.count--;
			cout<<"complete !"<<endl;
			save_CapLopFile(ds_CapLop);
			return 1;
		}else{
				CAPLOP* CapLopDel = ds_CapLop.dsCapLop[pos];
				for(int i = pos; i<ds_CapLop.count-1;++i){
					ds_CapLop.dsCapLop[i] = ds_CapLop.dsCapLop[i+1];
				}
				ds_CapLop.dsCapLop[ds_CapLop.count-1] = NULL;
				ds_CapLop.count--;
				cout<<"complete !"<<endl;
				save_CapLopFile(ds_CapLop);
				CapLopDel = NULL;
				delete CapLopDel;
				return 1;
		}
}else{
	cout<<"Khong tim thay ma cap lop "<<endl;
	return 0;
}
}

int hieuChinhCapLop(DS_CAPLOP &ds_CapLop){
	string maCapLop="";
	CAPLOP* CapLop = new CAPLOP;
	
	cout<<"Nhap ma cap lop: ";
	cin.ignore();
	getline(cin,maCapLop);
	int pos = timViTriXoaCapLop(ds_CapLop, maCapLop);

	if(pos>=0){
		cout<<"Nhap ma new: "; getline(cin,CapLop->Ma); cout<<endl;
		cout<<"Nhap ten new: "; getline(cin, CapLop->Ten); cout<<endl;
		cout<<"Nhap so tiet new: ";
       	while(!(cin>>CapLop->SoTiet)){
       		cout<<"gia tri phai la so";
       		cin.clear();
       		cin.ignore(123,'\n');
//       		return 0;
		   }
       	cout<<"Nhap hoc phi new: ";
       	while(!(cin>>CapLop->HocPhi)){
       		cout<<"gia tri phai la so";
       		cin.clear();
       		cin.ignore(123,'\n');
//       		return 0;
		   }
		// check lap Ma cap lop
		//True
		if(check_lapMaCapLopLapEdit(ds_CapLop, pos, CapLop->Ma)==-1){
			CAPLOP* CapLopDel = ds_CapLop.dsCapLop[pos];
			ds_CapLop.dsCapLop[pos]=CapLop;
			CapLopDel = NULL;
			delete CapLopDel;
			cout<<"complete !"<<endl;
			save_CapLopFile(ds_CapLop);
		}
		else{
			if(check_lapMaCapLopLapEdit(ds_CapLop, pos, CapLop->Ma)==-2){
				cout<<"Ma cap lop da ton tai !"<<endl;
					return 0;
			}
		}
	}else{
		cout<<"Khong tim thay ma cap lop !";
		return 0;
	}
}

void xuatCapLop(DS_CAPLOP ds_CapLop){
//	cout << setw(5) << left << 1;
	cout<<"Danh sach cap lop: "<<endl;
	cout << setw(5)  << left << "Stt";
	cout << setw(10) << left << "Ma";
	cout << setw(25) << left << "Ten";
	cout << setw(10)  << left << "So tiet";
	cout << setw(25) << left << "Hoc Phi"<<endl;
	cout << setfill('.');		
	cout << setw(70) << "" << endl;	
	cout << setfill(' ');
	
	for(int i=0;i<ds_CapLop.count;i++){
		cout<< setw(5) << left<<i;
		cout<< setw(10) << left<<ds_CapLop.dsCapLop[i]->Ma;
		cout<< setw(25) << left<<ds_CapLop.dsCapLop[i]->Ten;
		cout<< setw(10) << left<<ds_CapLop.dsCapLop[i]->SoTiet;
		cout<< setw(25) << left<<ds_CapLop.dsCapLop[i]->HocPhi<<endl;
	}
}


// additional function


int check_lap_MCL(DS_CAPLOP ds_CapLop, CAPLOP* CapLop){
	if(ds_CapLop.count==0)return 0;
	for(int i=0;i<ds_CapLop.count;i++){
		if(CapLop->Ma == ds_CapLop.dsCapLop[i]->Ma){
			cout<<"trung ma cap lop ! khong the them !";
			return 1;
		}
	}
	return 0;
}

int timViTriXoaCapLop(DS_CAPLOP ds_CapLop, string CapLop){
	if(ds_CapLop.count==0)return -2; // danh sach trong
	for(int i=0;i<ds_CapLop.count;i++){
		if(CapLop == ds_CapLop.dsCapLop[i]->Ma){
			return i; // tim thay ma cap lop theo input string
		}
	}
	return -1;
}

int check_lapMaCapLopLapEdit(DS_CAPLOP ds_CapLop, int pos, string MaEdit){
	
	if(ds_CapLop.count==0){
		return -2; // false for edit
	}
	for(int i=0;i<ds_CapLop.count;i++){
		if(MaEdit == ds_CapLop.dsCapLop[i]->Ma && i != pos) {
			return i; // false for edit
		}
	}
	return -1; // true for edit
}

void load_CapLopFile(DS_CAPLOP& ds_CapLop){
	ifstream  f;
	f.open("capLop.txt", ios_base::in);
	if(f.fail()){
		cout << "file not exis" << endl;
	}
	else{
			while (!f.eof())          
	{
		CAPLOP* CapLop = new CAPLOP;
		getline(f, CapLop->Ma,','); 
		getline(f, CapLop->Ten,','); 
		
		f>>(CapLop->SoTiet); 
		f.ignore(256, ',');
		
		f>>(CapLop->HocPhi); 
		f.ignore(256, '\n');
		
		ds_CapLop.dsCapLop[ds_CapLop.count] = CapLop;
		ds_CapLop.count++;
	}
	}


	f.close();
}

void save_CapLopFile(DS_CAPLOP ds_CapLop){
	fstream f;
	f.open("capLop.txt", ios::out);
	if (f.fail())
	{
		cout << "file not exis" << endl;
	}
	else
	{
		for(int i=0;i<ds_CapLop.count;i++){
			f<<ds_CapLop.dsCapLop[i]->Ma;
			f<<",";
			f<<ds_CapLop.dsCapLop[i]->Ten;
			f<<",";
			f<<ds_CapLop.dsCapLop[i]->SoTiet;
			f<<",";
			f<<ds_CapLop.dsCapLop[i]->HocPhi;
			f<<",";
			if(i != ds_CapLop.count-1){
				f<<endl;
			}
			
		}
		f.close();
	}
}






