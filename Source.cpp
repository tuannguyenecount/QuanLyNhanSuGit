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
using namespace std;


int main()
{
	QuanLyNhanVien quanLyNhanVien;
	NhanVien* nv = NULL;
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
		cout << "CHON MENU: ";
		cin >> chon;
		switch (chon)
		{
			case 1: {
				cout << "------------NHAP THONG TIN NHAN VIEN BAN HANG------------" << endl;
				nv = new NhanVienBanHang();
				nv->Input();
				quanLyNhanVien.AddToList(nv);
				break;
			}
			case 2: {
				cout << "------------NHAP THONG TIN NHAN VIEN KE TOAN------------" << endl;
				nv = new NhanVienKeToan();
				nv->Input();
				quanLyNhanVien.AddToList(nv);
				break;
			}
			case 3: {
				quanLyNhanVien.ShowSalesClerk();
				system("pause");
				break;
			}
			case 4: {
				quanLyNhanVien.ShowAccountant();
				system("pause");
				break;
			}
			case 5: {
				string id;
				cout << "Nhap ma nhan vien can tim:\n";
				cin >> id;
				NhanVien* nv = quanLyNhanVien.SearchEmployee(id);
				if (nv == NULL)
				{
					cout << "Khong tim thay nhan vien!";
				}
				else
				{
					cout << "Ket qua tim kiem\n";
					nv->Output();
				}
				system("pause");
				break;
			}
			case 6:
			{
				string maNhanVien;
				cout << "Nhap ma nhan vien can xoa:\n";
				cin >> maNhanVien;
				NhanVien* nv = quanLyNhanVien.SearchEmployee(maNhanVien);
				if (nv == NULL)
				{
					cout << "Khong tim thay nhan vien!";
				}
				else
				{
					quanLyNhanVien.DeleteEmployee(maNhanVien);
				}
				break;
			}
			case 7:
			{
				cout << "Tong tien phai tra cho toan bo nhan vien la " << quanLyNhanVien.GetSumSalary();
				system("pause");
				break;
			}
			case 0: {
				break;
			}
		}
	} while (chon != 0);
	quanLyNhanVien.WriteSalesClerkToFile();
	quanLyNhanVien.WriteAccountantToFile();
}

