#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "Phong.h"
using namespace std;
#pragma once 

class QuanLyPhong {
	vector<Phong> danhSachPhong;
public:
	QuanLyPhong()
	{
		ifstream f;
		f.open("Phong.txt", ios::in);
		if (f.is_open())
		{
			while (f.eof() == false)
			{
				Phong phong;
				getline(f, phong.maPhong, '|');
				if(phong.maPhong == "" || phong.maPhong == "\n")
					break;
				getline(f, phong.tenPhong, '|');
				char c = f.get();
				danhSachPhong.push_back(phong);
			}
			f.close();
		}	
	}
	~QuanLyPhong()
	{
		if(danhSachPhong.size() > 0)
		{	
			ofstream f;
			f.open("Phong.txt", ios::out);
			for (int i = 0; i < danhSachPhong.size(); i++)
			{
				danhSachPhong[i].XuatFile(f);
			}
			if (f.is_open())
				f.close();
		}
	}
	void ThemPhong(Phong phong)
	{
		danhSachPhong.push_back(phong);
	}
	void XemDanhSachPhong()
	{
		for(int i = 0; i < danhSachPhong.size(); i++)
		{
			danhSachPhong[i].Xuat();
			cout<<endl;
		}
	}
	Phong* TimKiem(string maPhong)
	{
		for(int i = 0; i < danhSachPhong.size(); i++)
		{
			if(danhSachPhong[i].maPhong == maPhong)
				return &danhSachPhong[i];
		}
		return NULL;
	}
	void SuaPhong()
	{
		string maPhong;
		cout<<"Nhap ma phong can sua:\n";
		cin>>maPhong;
		Phong* phong = TimKiem(maPhong);
		if(phong == NULL)
		{
			cout<<"Phong khong ton tai!";
		}
		else 
		{
			cout<<"Nhap ten phong moi:\n";
			cin.ignore(1);
			getline(cin, phong->tenPhong);
			cout<<"Sua thanh cong";
		}
	}
	bool KiemTraPhongTonTai(string maPhong)
	{
		Phong* phong = TimKiem(maPhong);
		return phong != NULL;
	}
	
};


