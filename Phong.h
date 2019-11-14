#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#pragma once 

class Phong {
private:
	friend class QuanLyPhong;
protected:
	string maPhong;
	string tenPhong;
public:
	void Nhap()
	{
		cout << "Nhap ma phong: ";
		getline(cin, maPhong);
		cout << "Nhap ten phong: ";
		getline(cin, tenPhong);
	}
	void Xuat()
	{
		cout << "Ma phong: " << maPhong << endl;
		cout << "Ten phong: " << tenPhong << endl;
	}
 	void XuatFile(ofstream& f)
 	{
 		f << maPhong << "|";
		f << tenPhong <<"|"<<endl;
	}
};
