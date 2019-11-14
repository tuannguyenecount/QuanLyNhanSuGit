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
#pragma once 

class QuanLyNhanVien {
private:
	vector<NhanVien*> danhSachNhanVien;
	void GhiNhanVienBanHangRaFile();
	void GhiNhanVienKeToanRaFile();
public:
	QuanLyNhanVien()
	{
		ifstream f;
		f.open("NhanVienBanHang.txt", ios::in);
		if (f.is_open())
		{
			
			while (f.eof() == false)
			{
				NhanVien* nv = new NhanVienBanHang();
				getline(f, nv->ten, '|');
				if(nv->ten == "\n" || nv->ten == "")
					break;
				getline(f, nv->ngaySinh, '|');
				getline(f, nv->queQuan, '|');
				getline(f, nv->maNhanVien, '|');
				getline(f, nv->maPhong, '|');
				string sSoSP;
				getline(f, sSoSP,'|');
				char c = f.get();
				//getline(f, sSoSP);
				((NhanVienBanHang*)nv)->soSanPhamBanDuoc = atoi(sSoSP.c_str());
				danhSachNhanVien.push_back(nv);
				//f.get();
			}
			f.close();
		}
		f.open("NhanVienKeToan.txt", ios::in);
		if (f.is_open())
		{	
			while (f.eof() == false)
			{
				NhanVien* nv = new NhanVienKeToan();
				getline(f, nv->ten, '|');
				if(nv->ten == "\n" || nv->ten == "")
					break;
				getline(f, nv->ngaySinh, '|');
				getline(f, nv->queQuan, '|');
				getline(f, nv->maNhanVien, '|');
				getline(f, nv->maPhong, '|');
				string sNtc;
				getline(f, sNtc, '|');
				char c = f.get();
				((NhanVienKeToan*)nv)->soNgayTangCa = atoi(sNtc.c_str());
				danhSachNhanVien.push_back(nv);			
			}
			f.close();
		}
		
	}
	~QuanLyNhanVien()
	{
		if(DemNhanVienBanHang() > 0)
			GhiNhanVienBanHangRaFile();
			
		if(DemNhanVienKeToan() > 0)
			GhiNhanVienKeToanRaFile();
	}
	void ThemNhanVien(NhanVien* nv);
	void HienDanhSachNhanVienBanHang();
	void HienDanhSachNhanVienKeToan();
	NhanVien* TimNhanVien(string maNhanVien);
	void XoaNhanVien(string maNhanVien);
	void XemNhanVienThuocPhong(string maPhong);
	int DemNhanVienBanHang();
	int DemNhanVienKeToan();
//	long GetSumSalary();
};

void QuanLyNhanVien::ThemNhanVien(NhanVien* nv)
{
	danhSachNhanVien.push_back(nv);
}

void QuanLyNhanVien::HienDanhSachNhanVienBanHang()
{
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienBanHang"))
		{
			danhSachNhanVien[i]->Xuat();
			cout<<endl;
		}
	}
}

void QuanLyNhanVien::HienDanhSachNhanVienKeToan()
{
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienKeToan"))
		{
			danhSachNhanVien[i]->Xuat();
			cout<<endl;
		}
	}
}

void QuanLyNhanVien::GhiNhanVienBanHangRaFile()
{
	ofstream f;
	f.open("NhanVienBanHang.txt", ios::out);
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienBanHang"))
		{
			danhSachNhanVien[i]->XuatFile(f);
		}
	}
	if (f.is_open())
		f.close();
}


void QuanLyNhanVien::GhiNhanVienKeToanRaFile()
{
	ofstream f;
	f.open("NhanVienKeToan.txt", ios::out);
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienKeToan"))
		{
			danhSachNhanVien[i]->XuatFile(f);
		}
	}
	if (f.is_open())
		f.close();
}

NhanVien* QuanLyNhanVien::TimNhanVien(string maNhanVien)
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

void QuanLyNhanVien::XoaNhanVien(string maNhanVien)
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

void QuanLyNhanVien::XemNhanVienThuocPhong(string maPhong)
{
	cout<<"\nDanh sach nhan vien thuoc phong co ma "+maPhong+" \n\n";
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (danhSachNhanVien[i]->maPhong == maPhong)
		{
			danhSachNhanVien[i]->Xuat();
			cout<<endl;
		}
	}
}

int QuanLyNhanVien::DemNhanVienBanHang()
{
	int count = 0;
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienBanHang"))
		{
			count++;
		}
	}
	return count;
}

int QuanLyNhanVien::DemNhanVienKeToan()
{
	int count = 0;
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienKeToan"))
		{
			count++;
		}
	}
	return count;
}

//long QuanLyNhanVien::GetSumSalary()
//{
//	long sum = 0;
//	for (int i = 0; i < danhSachNhanVien.size(); i++)
//	{
//		sum += danhSachNhanVien[i]->TinhTienLuong();
//	}
//	return sum;
//}

