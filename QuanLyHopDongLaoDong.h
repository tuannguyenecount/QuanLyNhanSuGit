#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "HopDongLaoDong.h"
using namespace std;
#pragma once 

class QuanLyHopDongLaoDong
{
	private:
		vector<HopDongLaoDong> danhSachHopDongLaoDong;
	public:
		QuanLyHopDongLaoDong()
		{
			ifstream f;
			f.open("HopDongLaoDong.txt", ios::in);
			if (f.is_open())
			{
				
				while (f.eof() == false)
				{
					HopDongLaoDong hopDongLaoDong;
					getline(f, hopDongLaoDong.maHD, '|');
					if(hopDongLaoDong.maHD == "\n" || hopDongLaoDong.maHD == "")
						break;
					getline(f, hopDongLaoDong.tuNgay, '|');
					getline(f, hopDongLaoDong.denNgay, '|');
					string sLuongCanBan;
					getline(f, sLuongCanBan,'|');
					hopDongLaoDong.luongCanBan = atoi(sLuongCanBan.c_str());
					getline(f, hopDongLaoDong.loaiLuong, '|');
					string sPhuCap;
					getline(f, sPhuCap,'|');
					hopDongLaoDong.phuCap = atoi(sPhuCap.c_str());
					getline(f, hopDongLaoDong.chucVu, '|');
					getline(f, hopDongLaoDong.ngayKy, '|');
					danhSachHopDongLaoDong.push_back(hopDongLaoDong);
					char c  = f.get();
				}
				f.close();
			}
		}
		~QuanLyHopDongLaoDong()
		{
			if(danhSachHopDongLaoDong.size() > 0)
			{	
				ofstream f;
				f.open("HopDongLaoDong.txt", ios::out);
				for (int i = 0; i < danhSachHopDongLaoDong.size(); i++)
				{
					danhSachHopDongLaoDong[i].XuatFile(f);
				}
				if (f.is_open())
					f.close();
			}
		}
		void ThemVaoDanhSach(HopDongLaoDong hopDongMoi)
		{
			danhSachHopDongLaoDong.push_back(hopDongMoi);
		}
		void XemDanhSach()
		{
			cout<<"Danh Sach Hop Dong Lao Dong\n\n";
			for (int i = 0; i < danhSachHopDongLaoDong.size(); i++)
			{
				danhSachHopDongLaoDong[i].XemHopDong();
			}
		}
		void XoaHopDong()
		{
			string maHD;
			cout<<"Nhap ma hop dong can xoa:\n";
			getline(cin, maHD);
			for (int i = 0; i < danhSachHopDongLaoDong.size(); i++)
			{
				if (danhSachHopDongLaoDong[i].maHD == maHD)
				{
					danhSachHopDongLaoDong.erase(danhSachHopDongLaoDong.begin() + i);
					return;
				}
			}
		}
};


