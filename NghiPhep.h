#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#pragma once 

class NghiPhep
{
	private:
		friend class QuanLyNghiPhep;
		string maNghiPhep;
		string maNhanVien;
		string nghiTuNgay;
		string nghiDenNgay;
		string loaiNghiPhep;
		string trangThai;
	public:
		NghiPhep()
		{
			trangThai = "Chua phe duyet";
		}
		void YeuCauNghiPhep()
		{
			cout<<"Nhap ma nghi phep:\n";
			getline(cin, maNghiPhep);
			cout<<"Nhap ma nhan vien nghi\n";
			getline(cin, maNhanVien);
			cout<<"Nghi tu ngay\n";
			getline(cin, nghiTuNgay);
			cout<<"Nghi den ngay\n";
			getline(cin, nghiDenNgay);
			cout<<"Loai nghi phep\n";
			getline(cin, loaiNghiPhep);
		}
		void PheDuyet()
		{
			trangThai = "Da phe duyet";	
		}
		void TuChoi()
		{
			trangThai = "Chua phe duyet";	
		}
		void Xuat()
		{
			cout<<"Ma nghi phep: "<<maNghiPhep<<endl;
			cout<<"Ma nhan vien nghi: " <<maNhanVien<<endl;
			cout<<"Thoi gian nghi: "<<nghiTuNgay<<" - "<<nghiDenNgay<<endl;
			cout<<"Loai nghi phep: "<<loaiNghiPhep<<endl;
			cout<<"Trang thai: "<<trangThai<<endl;
		}
		void XuatFile(ofstream& f)
	 	{
	 		f << maNghiPhep << "|";
			f << maNhanVien <<"|";
			f << nghiTuNgay <<"|";
			f << nghiDenNgay <<"|";
			f << loaiNghiPhep <<"|";
			f << trangThai <<"|"<<endl;
		}
};
