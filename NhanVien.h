#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#pragma once 

class NhanVien {
	friend class QuanLyNhanVien;
protected:
	string maNhanVien;
	string namSinh;
	string hoTen, queQuan;
public:
	virtual void Input()
	{
		cout << "Nhap ma nhan vien: ";
		cin >> maNhanVien;
		cout << "Nhap ho ten: ";
		cin.ignore();
		getline(cin, hoTen);
		cout << "Nhap que quan:";
		cin.ignore();
		getline(cin, queQuan);
		cout << "nhap nam sinh:";
		cin >> namSinh;
	}
	virtual void Output()
	{
		cout << "Ma nhan vien: " << maNhanVien << endl;
		cout << "Ho ten: " << hoTen << endl;
		cout << "Que quan: " << queQuan << endl;
		cout << "Nam sinh: " << namSinh << endl;
	}
	virtual void OutputFile(ofstream& f) = 0;
	virtual int TinhTienLuong() = 0;
};
