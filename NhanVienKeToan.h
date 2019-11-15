#include <iostream>
#include <string>
#include <fstream>
#include "NhanVien.h"
using namespace std;
#pragma once 

class NhanVienKeToan : public NhanVien {
	friend class QuanLyNhanVien;
private:
	int soNgayTangCa;
public:
	void Nhap()
	{
		NhanVien::Nhap();
		cout << "Nhap so ngay tang ca: ";
		cin >> soNgayTangCa;
		cin.ignore(1);
	}
	void Xuat()
	{
		NhanVien::Xuat();
		cout << "So ngay tang ca: " << soNgayTangCa << endl;
	}
	virtual void XuatFile(ofstream& f)
	{
		f << ten << "|";
		f << ngaySinh << "|";
		f << queQuan << "|";
		f << maNhanVien << "|";
		f << maPhong << "|";
		//f << maNguoiQuanLy << "|";
		f << soNgayTangCa << "|"<<endl;
	}
};
