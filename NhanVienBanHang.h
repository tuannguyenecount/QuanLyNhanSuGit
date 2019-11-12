#include <iostream>
#include <string>
#include <fstream>
#include "NhanVien.h"
using namespace std;

class NhanVienBanHang : public NhanVien {
	friend class QuanLyNhanVien;
private:
	int soSanPhamBanDuoc;
	int luongCanBan;
public:
	void Input()
	{
		NhanVien::Input();
		cout << "Nhap so san pham ban duoc: ";
		cin >> soSanPhamBanDuoc;
		cout << "Nhap luong can ban: ";
		cin >> luongCanBan;
	}
	void Output()
	{
		NhanVien::Output();
		cout << "So san pham ban duoc: " << soSanPhamBanDuoc << endl;
		cout << "Luong can ban: " << this->TinhTienLuong() << endl;
	}
	void OutputFile(ofstream& f)
	{
		f << "Salesclerk|";
		f << hoTen << "|";
		f << maNhanVien << "|";
		f << queQuan << "|";
		f << namSinh << "|";
		f << luongCanBan << "|";
		f << soSanPhamBanDuoc << endl;
	}
	int TinhTienLuong()
	{
		if (soSanPhamBanDuoc >= 30)
			return (luongCanBan + (soSanPhamBanDuoc * 500));
		else
			return luongCanBan;
	}
};
