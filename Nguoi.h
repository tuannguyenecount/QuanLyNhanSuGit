#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#pragma once 

class Nguoi  {
protected:
	string ten;
	string ngaySinh;
	string queQuan;
public:
	virtual void Nhap()
	{	
		cout << "Nhap ten: ";
		getline(cin,ten);
		
		cout << "Nhap ngay sinh: ";
	    getline(cin, ngaySinh);
	    
		cout << "Nhap que quan:";
		getline(cin, queQuan);
	}
	virtual void Xuat()
	{
		cout << "Ten: " << ten << endl;
		cout << "Ngay sinh: " << ngaySinh << endl;
		cout << "Que quan: " << queQuan << endl;
	}
	virtual void XuatFile(ofstream& f) = 0;
};
