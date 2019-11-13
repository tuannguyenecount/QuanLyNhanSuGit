#include <iostream>
#include <string>
#include <fstream>
#include "Nguoi.h"
#include "QuanLyNhanVien.h"
using namespace std;
#pragma once 

class NhanVien : public Nguoi {
	friend class QuanLyNhanVien;
protected:
	string maNhanVien;
	string maPhong;
	string maNguoiQuanly;
public:
	virtual void Nhap()
	{
		Nguoi::Nhap();
		cout << "Nhap ma nhan vien: ";
		cin >> maNhanVien;
		cout << "Nhap ma phong: ";
		cin >> maPhong;
		cout << "Nhap ma nguoi quan ly:";
		cin >> maNguoiQuanly;
	}
	virtual void Xuat()
	{
		Nguoi::Xuat();
		cout << "Ma nhan vien: " << maNhanVien << endl;
		cout << "Ma phong: " << maPhong << endl;
		cout << "Ma nguoi quan ly: " << maNguoiQuanly << endl;
	}
	virtual void XuatFile(ofstream& f) = 0;
};
