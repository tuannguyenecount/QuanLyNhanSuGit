#include <iostream>
#include <string>
#include <fstream>
#include "NhanVien.h"
using namespace std;

class NhanVienBanHang : public NhanVien {
	friend class QuanLyNhanVien;
private:
	int soSanPhamBanDuoc;
public:
	void Nhap()
	{
		NhanVien::Nhap();
		cout << "Nhap so san pham ban duoc: ";
		cin >> soSanPhamBanDuoc;
	}
	void Xuat()
	{
		NhanVien::Xuat();
		cout << "So san pham ban duoc: " << soSanPhamBanDuoc << endl;
	}
	void XuatFile(ofstream& f)
	{
		f << ten << "|";
		f << queQuan << "|";
		f << ngaySinh << "|";
		f << maNhanVien << "|";
		f << soSanPhamBanDuoc << endl;
	}
};
