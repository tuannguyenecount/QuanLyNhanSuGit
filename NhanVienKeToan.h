#include <iostream>
#include <string>
#include <fstream>
#include "NhanVien.h"
using namespace std;

class NhanVienKeToan : public NhanVien {
	friend class QuanLyNhanVien;
private:
	int soNgayTangCa;
	int luongCanBan;
public:
	void Input()
	{
		NhanVien::Input();
		cout << "Nhap so ngay tang ca: ";
		cin >> soNgayTangCa;
		cout << "Nhap luong can ban: ";
		cin >> luongCanBan;
	}
	void Output()
	{
		NhanVien::Output();
		cout << "So ngay tang ca: " << soNgayTangCa << endl;
		cout << "Luong can ban: " << this->TinhTienLuong() << endl;
	}
	void OutputFile(ofstream& f)
	{
		f << "Accountant|";
		f << hoTen << "|";
		f << maNhanVien << "|";
		f << queQuan << "|";
		f << namSinh << "|";
		f << soNgayTangCa << "|";
		f << luongCanBan << endl;
	}
	int TinhTienLuong()
	{
		if (soNgayTangCa >= 10)
			return (luongCanBan + (soNgayTangCa * 500));
		else
			return luongCanBan;
	}
};
