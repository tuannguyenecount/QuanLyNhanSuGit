#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "NghiPhep.h"
using namespace std;
#pragma once 

class QuanLyNghiPhep
{
	private:
		vector<NghiPhep> danhSachNghiPhep;
	public:
		QuanLyNghiPhep()
		{
			ifstream f;
			f.open("NghiPhep.txt", ios::in);
			if (f.is_open())
			{
				
				while (f.eof() == false)
				{
					NghiPhep nghiPhep;
					getline(f, nghiPhep.maNghiPhep, '|');
					if(nghiPhep.maNghiPhep == "\n" || nghiPhep.maNghiPhep == "")
						break;
					getline(f, nghiPhep.maNhanVien, '|');
					getline(f, nghiPhep.nghiTuNgay, '|');
					getline(f, nghiPhep.nghiDenNgay, '|');
					getline(f, nghiPhep.loaiNghiPhep, '|');
					getline(f, nghiPhep.trangThai, '|');
					char c = f.get();
					danhSachNghiPhep.push_back(nghiPhep);
				}
				f.close();
			}
		}
		~QuanLyNghiPhep()
		{
			if(danhSachNghiPhep.size() > 0)
			{
				ofstream f;
				f.open("NghiPhep.txt", ios::out);
				for (int i = 0; i < danhSachNghiPhep.size(); i++)
				{
					danhSachNghiPhep[i].XuatFile(f);
				}
				if (f.is_open())
					f.close();
			}
		}
		void ThemNghiPhep(NghiPhep nghiPhep)
		{
			danhSachNghiPhep.push_back(nghiPhep);
		}
		void XemDanhSach()
		{
			cout<<"Danh Sach Yeu Cau Nghi Phep\n\n";
			for (int i = 0; i < danhSachNghiPhep.size(); i++)
			{
				danhSachNghiPhep[i].Xuat();				
				cout<<endl;
			}
		}
		void PheDuyet()
		{
			string maNghiPhep;
			cout<<"Nhap ma nghi phep can phe duyet:\n";
			getline(cin, maNghiPhep);
			for (int i = 0; i < danhSachNghiPhep.size(); i++)
			{
				if(danhSachNghiPhep[i].maNghiPhep == maNghiPhep)
				{
					danhSachNghiPhep[i].PheDuyet();
					return;
				}
			}
		}
		void TuChoi()
		{
			string maNghiPhep;
			cout<<"Nhap ma nghi phep can tu choi:\n";
			getline(cin, maNghiPhep);
			for (int i = 0; i < danhSachNghiPhep.size(); i++)
			{
				if(danhSachNghiPhep[i].maNghiPhep == maNghiPhep)
				{
					danhSachNghiPhep[i].TuChoi();
					return;
				}
			}
		}
};
