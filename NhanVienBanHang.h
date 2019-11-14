#include <iostream>
#include <string>
#include <fstream>
#include "NhanVien.h"
using namespace std;
#pragma once 

class NhanVienBanHang : public NhanVien {
	friend class QuanLyNhanVien;
private:
	int soSanPhamBanDuoc;
public:
	virtual void Nhap()
	{
		NhanVien::Nhap();
		cout << "Nhap so san pham ban duoc: ";
		cin >> soSanPhamBanDuoc;
		cin.ignore(1);
	}
	virtual void Xuat()
	{
		NhanVien::Xuat();
		cout << "So san pham ban duoc: " << soSanPhamBanDuoc << endl;
	}
	virtual void XuatFile(ofstream& f)
	{
		f << ten << "|";
		f << ngaySinh << "|";
		f << queQuan << "|";
		f << maNhanVien << "|";
		f << maPhong << "|";
		//f << maNguoiQuanLy << "|";
		f << soSanPhamBanDuoc << "|"<<endl;
	}
};
