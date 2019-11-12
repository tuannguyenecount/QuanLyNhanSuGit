#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "NhanVienBanHang.h"
#include "NhanVienKeToan.h"
using namespace std;

class QuanLyNhanVien {
	vector<NhanVien*> danhSachNhanVien;
public:
	QuanLyNhanVien()
	{
		ifstream f;
		f.open("Salesclerks.txt", ios::in);
		if (f.is_open())
		{
			string type;
			while (getline(f, type, '|'))
			{
				NhanVien* nv = new NhanVienBanHang();
				getline(f, nv->hoTen, '|');
				getline(f, nv->maNhanVien, '|');
				getline(f, nv->queQuan, '|');
				getline(f, nv->namSinh, '|');
				string sLuong;
				getline(f, sLuong, '|');
				((NhanVienBanHang*)nv)->luongCanBan = atoi(sLuong.c_str());
				string sSoSP;
				getline(f, sSoSP);
				((NhanVienBanHang*)nv)->soSanPhamBanDuoc = atoi(sSoSP.c_str());
				danhSachNhanVien.push_back(nv);
			}
			f.close();
		}
		f.open("Accountants.txt", ios::in);
		if (f.is_open())
		{
			string type;
			while (getline(f, type, '|'))
			{
				NhanVien* nv = new NhanVienKeToan();
				getline(f, nv->hoTen, '|');
				getline(f, nv->maNhanVien, '|');
				getline(f, nv->queQuan, '|');
				getline(f, nv->namSinh, '|');
				string sNtc;
				getline(f, sNtc, '|');
				((NhanVienKeToan*)nv)->soNgayTangCa = atoi(sNtc.c_str());
				string sLuong;
				getline(f, sLuong);
				((NhanVienKeToan*)nv)->luongCanBan = atoi(sLuong.c_str());
				danhSachNhanVien.push_back(nv);
				f.close();
			}
		}
	}
	void AddToList(NhanVien* nv);
	void ShowSalesClerk();
	void WriteSalesClerkToFile();
	void ShowAccountant();
	void WriteAccountantToFile();
	NhanVien* SearchEmployee(string id);
	void DeleteEmployee(string id);
	long GetSumSalary();
};

void QuanLyNhanVien::AddToList(NhanVien* nv)
{
	danhSachNhanVien.push_back(nv);
}

void QuanLyNhanVien::ShowSalesClerk()
{
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienBanHang"))
		{
			danhSachNhanVien[i]->Output();
			cout<<endl;
		}
	}
}

void QuanLyNhanVien::WriteSalesClerkToFile()
{
	ofstream f;
	f.open("Salesclerks.txt", ios::out);
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienBanHang"))
		{
			danhSachNhanVien[i]->OutputFile(f);
		}
	}
	if (f.is_open())
		f.close();
}

void QuanLyNhanVien::ShowAccountant()
{
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienKeToan"))
		{
			danhSachNhanVien[i]->Output();
			cout<<endl;
		}
	}
}

void QuanLyNhanVien::WriteAccountantToFile()
{
	ofstream f;
	f.open("Accountants.txt", ios::out);
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienKeToan"))
		{
			danhSachNhanVien[i]->OutputFile(f);
		}
	}
	if (f.is_open())
		f.close();
}

NhanVien* QuanLyNhanVien::SearchEmployee(string maNhanVien)
{
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (danhSachNhanVien[i]->maNhanVien == maNhanVien)
		{
			return danhSachNhanVien[i];
		}
	}
	return NULL;
}

void QuanLyNhanVien::DeleteEmployee(string maNhanVien)
{
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (danhSachNhanVien[i]->maNhanVien == maNhanVien)
		{
			danhSachNhanVien.erase(danhSachNhanVien.begin() + i);
			return;
		}
	}
}

long QuanLyNhanVien::GetSumSalary()
{
	long sum = 0;
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		sum += danhSachNhanVien[i]->TinhTienLuong();
	}
	return sum;
}

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

