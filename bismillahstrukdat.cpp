#include <iostream>
#include <malloc.h>
#include <iomanip>
#include <string.h>
#define true 1
#define false 0
using namespace std;
void buatlistbaru();
typedef struct node *typeptr;
struct data{
	char waktu[5], kelas[10], tujuan[10];
	int harga;
};
struct data1{
	char nik[10], nama[30], waktu[5], kelas[10], tujuan[10];
	int harga;
};
struct node{
	data info;
	data1 infoo;
	typeptr next;
};
typeptr awal, akhir, awal1, akhir1;
void buatlistbaru(){
	typeptr list;
	list=NULL;
	awal=list;
	akhir=list;
}
void buatlistbaru1()
{	typeptr listbaru;
	listbaru=NULL;
	awal1=listbaru;
	akhir1=listbaru;}
int listkosong1(){
		return(awal1==NULL);
}
int listkosong(){
	if(awal==NULL)
		return(true);
	else
		return(false);
}
void sisipnode(char nik1[10], char nama1[30], typeptr bantu){
	typeptr NB,bantu1;
	cout<<bantu->info.tujuan;
	NB = (node *) malloc (sizeof(node));
	strcpy(NB->infoo.nik,nik1);
	strcpy(NB->infoo.nama, nama1);
	strcpy(NB->infoo.tujuan, bantu->info.tujuan);
	strcpy(NB->infoo.waktu, bantu->info.waktu);
	strcpy(NB->infoo.kelas, bantu->info.kelas);
	NB->infoo.harga = bantu->info.harga;
	NB->next = NULL;
		if (listkosong1()){
			cout<<bantu->info.tujuan;
			awal1 = NB;
			akhir1 = NB;
		}
		else if (strcmp(bantu->info.waktu, NB->infoo.waktu) < 0){
			cout<<bantu->info.waktu;
			NB->next = awal1;
			awal1 = NB;
		}
		else{
			cout<<bantu->info.kelas;
			bantu1 = awal1;
			while (bantu1->next != NULL && (strcmp(bantu->info.waktu, bantu1->next->infoo.waktu) < 0))
			NB->next = bantu1->next;
			bantu1->next=NB;
				if(strcmp(bantu->info.waktu,akhir->infoo.waktu) > 0)
					akhir1 = NB;
		}
}
void sisip(char tujuan2[10], char kelas2[10], char waktu2[5], int harga2){
	typeptr NB, bantu;
	NB = (node *) malloc (sizeof(node));
	strcpy(NB->info.tujuan, tujuan2);
	strcpy(NB->info.kelas, kelas2);
	strcpy(NB->info.waktu, waktu2);
	NB->info.harga = harga2;
	NB->next = NULL;
		if (listkosong()){
			awal = NB;
			akhir = NB;
		}
		else if (strcmp(tujuan2, NB->info.tujuan) < 0){
			NB->next = awal;
			awal = NB;
		}
		else{
			bantu = awal;
			while (bantu->next != NULL && (strcmp(tujuan2, bantu->next->info.tujuan) < 0))
			NB->next = bantu->next;
			bantu->next=NB;
				if(strcmp(tujuan2,akhir->info.tujuan) > 0)
					akhir = NB;
		}
}
void cari(){
	bool found = false;
	char carii, tujuan1[10];
	typeptr bantu;
	do{
		cin.ignore();
		cout << "Tujuan\t\t\t : "; cin.getline(tujuan1,sizeof(tujuan1));
		bantu = awal;
		if(listkosong()){
			cout<<"\nMaaf Daftar Tiket Masih Kosong!\n";
		}
		else{
			while (bantu != NULL){
					if(strcmp(tujuan1, bantu->info.tujuan)==0){
						cout << "Kelas\t\t\t : " << bantu->info.kelas << endl;
						cout << "Waktu Keberangkatan\t : " << bantu->info.waktu << endl;
						cout << "Harga\t\t\t : " << bantu->info.harga << endl;
						//found = true;
						break;
					}
						bantu = bantu->next;
			}
					if(found)
					cout<<"\nData tidak ditemukan!";
		}
		cout << "Cari tiket lagi? (y/n)";
		cin >> carii;
		}while(carii == 'y' || carii == 'Y');
}	
void cari2(){
	typeptr bantu;
	bantu = awal;
	char nik1[10], nama1[30];
	bool found = false;
	char tujuan1[10];
		cout << "Tujuan\t\t\t : "; cin.getline(tujuan1,sizeof(tujuan1));
		if(listkosong()){
			cout<<"\nMaaf Daftar Tiket Masih Kosong!\n";
		}
		else{
			while (bantu != NULL){
				cout<<bantu->info.tujuan;
				if(strcmp(tujuan1, bantu->info.tujuan)==0){
						cout << "Kelas\t\t\t : " << bantu->info.kelas << endl;
						cout << "Waktu Keberangkatan : " << bantu->info.waktu << endl;
						cout << "Harga\t\t\t : " << bantu->info.harga << endl;
		
						//found = true;
						break;
					}
					bantu = bantu->next;
			}
				if(found)
				cout<<"\nData tidak ditemukan!";
	//cout<<bantu->infoo.tujuan;
		}
		cout<<bantu->info.tujuan;
		cout << "NIK\t\t : "; cin.getline(nik1,sizeof(nik1));
		cout << "Nama Lengkap\t : "; cin.getline(nama1,sizeof(nama1));
		sisipnode(nik1, nama1, bantu);
}
void daftar(){
	int harga2, tes;
	char daftarr, waktu2[5], kelas2[10], tujuan2[10];
	cout << "===== INPUT DATA TIKET=====\n";
	cout << "Semua tiket dengan keberangkatan awal Yogyakarta\n";
	tes = 1;
	if(listkosong()){
		buatlistbaru();
		}
	while(tes == 1){
		cout << "Tujuan\t\t : "; cin >> tujuan2;
		cout << "Kelas\t\t : "; cin >> kelas2;
		cout << "Waktu Keberangkatan : "; cin >> waktu2;
		cout << "Harga\t\t : "; cin >> harga2;
		sisip(tujuan2, kelas2, waktu2, harga2);
		cout << "Tambah daftar tiket? (y/n)";
		cin >> daftarr;
		if(daftarr == 'y' || daftarr == 'Y'){
			tes = 1;
		}else{
			tes = 2;
		}
	}
}
void tampil(){
	typeptr bantu;
	int i = 0;
 	bantu = awal1;
 	cout << "\nDAFTAR ANTRIAN" << endl;
 	cout << "=======================================================================================================\n";
	cout << setw(6) << "NIK" << setw(10) << "Nama" << setw(10) << "Tujuan" << setw(10) << "Kelas" << setw(15) << "Waktu Keberangkatan" << 
	setw(15) << "Harga" << endl;
		do {
			cout << setw(4) << bantu->infoo.nik << setw(10) << bantu->infoo.nama << setw(10) << bantu->infoo.tujuan 
			<< setw(6) << bantu->infoo.kelas << setw(15) << bantu->infoo.waktu << setw(15) << bantu->infoo.harga << endl;
			i++;
			
			bantu=bantu->next;
		}while(bantu != NULL);
  	cout << "\n#jumlah antrian : " << i;
}
int main(){
	int pil, pili;
	char pilih;
	do{
		if (!listkosong1())
		tampil();
		cout << endl << endl;
        cout << "=============================================" << endl;
        cout << "\t\tMENU\t\t\n";
        cout << "\t1. Karyawan\t\n";
        cout << "\t2. Customer\t\n";
        cout << "=============================================" << endl;
        cout << "\tMasuk sebagai : ";
        cin >> pil;
        	switch(pil){
				case 1 :
					char user[10], pass[5];
					cout << "LOKET TIKET PESAWAT DOMESTIK" << endl;
					cout << "===========================================" <<endl;
					cout << "Anda Masuk sebagai Karyawan\n";
						do{
							cout << "===============LOGIN===============\n";
							cout << "Username : "; cin >> user;
							cout << "Password : "; cin >> pass;
								if(strcmp(user,"project") == 0 && (strcmp(pass,"123") == 0)){
									cout << "Login Berhasil\n";
									cout << "===== MENU KARYAWAN =====\n";
										cout << "1. Input Data Tiket\n";
										cout << "2. Tampil booking\n";
										cout << "Pilih : ";
										cin >> pili;
											switch(pili){
												case 1 :
													daftar();
												break;
												case 2 :
													tampil();
												break;
												default :
													cout << "Menu tidak ada di pilihan" << endl;
												break;
											}
								}
								else
									cout << "Login Gagal\n";
						}
						while((strcmp(user,"project")) != 0 && (strcmp(pass,"123")) != 0);		
				break;
				case 2 :
					cout << "LOKET TIKET PESAWAT DOMESTIK" << endl;
					cout << "==============================" <<endl;
					cout << "Anda Masuk sebagai Customer\n";
					cout << "1. Cari Tiket\n";
					cout << "2. Pesan Tiket\n";
					cout << "3. Pembatalan Tiket\n";
					cout << "Pilih : ";
					cin >> pili;
						switch(pili){
							case 1 :
								cout << "===== PENCARIAN TIKET =====\n";
								cari();
							break;
							case 2 :
								cout << "===== PEMESANAN DATA =====\n";cin.ignore();
								cari2();			
							break;
							case 3 :
								//batal();
							break;
							default :
								cout << "Menu tidak ada di pilihan" << endl;
							break;
						}
				break;
				default:
					cout << "Angka yang Anda Inputkan Salah" << endl;
				break;
			}cout << "\nAnda ingin kembali kemenu ? ";
			cin >> pilih;
		}while(pilih=='y'||pilih=='Y');
}
