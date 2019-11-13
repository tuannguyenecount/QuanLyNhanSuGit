#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "QuanLyNhanVien.h"
#include "QuanLyPhong.h"
using namespace std;


int main()
{
	QuanLyNhanVien quanLyNhanVien;
	NhanVien* nv = NULL;
	QuanLyPhong quanLyPhong;
	int chon;
	do {
		system("cls");
		cout << "0. THOAT." << endl;
		cout << "1. THEM NHAN VIEN BAN HANG" << endl;
		cout << "2. THEM NHAN VIEN KE TOAN" << endl;
		cout << "3. XEM DANH SACH NHAN VIEN BAN HANG" << endl;
		cout << "4. XEM DANH SACH NHAN VIEN KE TOAN" << endl;
		cout << "5. TIM KIEM NHAN VIEN THEO ID" << endl;
		cout << "6. XOA NHAN VIEN THEO ID" << endl;
		cout << "7. XEM TONG LUONG NHAN VIEN" << endl;
		cout << "8. THEM PHONG BAN "<<endl;
		cout << "9. XEM DANH SACH PHONG BAN"<<endl;
		cout << "CHON MENU: ";
		cin >> chon;
		switch (chon)
		{
			case 1: {
				cout << "------------NHAP THONG TIN NHAN VIEN BAN HANG------------" << endl;
				nv = new NhanVienBanHang();
				nv->Nhap();
				quanLyNhanVien.ThemNhanVien(nv);
				break;
			}
			case 2: {
				cout << "------------NHAP THONG TIN NHAN VIEN KE TOAN------------" << endl;
				nv = new NhanVienKeToan();
				nv->Nhap();
				quanLyNhanVien.ThemNhanVien(nv);
				break;
			}
			case 3: {
				quanLyNhanVien.XemDanhSachNhanVienBanHang();
				system("pause");
				break;
			}
			case 4: {
				quanLyNhanVien.XemDanhSachNhanVienKeToan();
				system("pause");
				break;
			}
			case 5: {
				string maNhanVien;
				cout << "Nhap ma nhan vien can tim:\n";
				cin >> maNhanVien;
				NhanVien* nv = quanLyNhanVien.TimNhanVien(maNhanVien);
				if (nv == NULL)
				{
					cout << "Khong tim thay nhan vien!";
				}
				else
				{
					cout << "Ket qua tim kiem\n";
					nv->Xuat();
				}
				system("pause");
				break;
			}
			case 6:
			{
				string maNhanVien;
				cout << "Nhap ma nhan vien can xoa:\n";
				cin >> maNhanVien;
				NhanVien* nv = quanLyNhanVien.TimNhanVien(maNhanVien);
				if (nv == NULL)
				{
					cout << "Khong tim thay nhan vien!";
				}
				else
				{
					quanLyNhanVien.XoaNhanVien(maNhanVien);
				}
				break;
			}
//			case 7:
//			{
//				cout << "Tong tien phai tra cho toan bo nhan vien la " << quanLyNhanVien.GetSumSalary();
//				system("pause");
//				break;
//			}
			case 8:{
				Phong phong;
				phong.Nhap();
				quanLyPhong.ThemPhong(phong);
				cout<<"Them thanh cong\n\n";
				quanLyPhong.XemDanhSachPhong();
				system("pause");
				break;
			}
			case 9:{
				quanLyPhong.XemDanhSachPhong();
				system("pause");
				break;
			}
			case 0: {
				break;
			}
		}
	} while (chon != 0);
}

