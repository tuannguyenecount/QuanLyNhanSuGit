#include <iostream>
#include <string>
#include <fstream>
#include "NhanVien.h"
using namespace std;

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
	}
	void Xuat()
	{
		NhanVien::Xuat();
		cout << "So ngay tang ca: " << soNgayTangCa << endl;
	}
	virtual void XuatFile(ofstream& f)
	{
		f << ten << "|";
		f << queQuan << "|";
		f << ngaySinh << "|";
		f << maNhanVien << "|";
		f << maPhong << "|";
	//	f << maNguoiQuanLy << "|";
		f << soNgayTangCa << endl;
	}
};
