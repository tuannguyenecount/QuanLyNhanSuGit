#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdlib>
//#include "QuanLyNhanVien.h"
//#include "QuanLyPhong.h"
//#include "QuanLyHopDongLaoDong.h"
//#include "QuanLyNghiPhep.h"
using namespace std;

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

class NhanVien : public Nguoi {
private:
	friend class QuanLyNhanVien;
protected:
	string maNhanVien;
	string maPhong;
	string maNguoiQuanly;
public:
	virtual void Nhap()
	{
		Nguoi::Nhap();
		cout << "Nhap ma nhan vien: ";
		getline(cin, maNhanVien);
		
		cout << "Nhap ma phong: ";
		getline(cin, maPhong);
		
		cout << "Nhap ma nguoi quan ly:";
		getline(cin, maNguoiQuanly);
	}
	virtual void Xuat()
	{
		Nguoi::Xuat();
		cout << "Ma nhan vien: " << maNhanVien << endl;
		cout << "Ma phong: " << maPhong << endl;
		cout << "Ma nguoi quan ly: " << maNguoiQuanly << endl;
	}
	virtual void XuatFile(ofstream& f) = 0;
};

class NhanVienBanHang : public NhanVien {
	friend class QuanLyNhanVien;
private:
	int soSanPhamBanDuoc;
public:
	virtual void Nhap()
	{
		NhanVien::Nhap();
		cout << "Nhap so san pham ban duoc: ";
		cin >> soSanPhamBanDuoc;
		cin.ignore(1);
	}
	virtual void Xuat()
	{
		NhanVien::Xuat();
		cout << "So san pham ban duoc: " << soSanPhamBanDuoc << endl;
	}
	virtual void XuatFile(ofstream& f)
	{
		f << ten << "|";
		f << ngaySinh << "|";
		f << queQuan << "|";
		f << maNhanVien << "|";
		f << maPhong << "|";
		//f << maNguoiQuanLy << "|";
		f << soSanPhamBanDuoc << "|"<<endl;
	}
};

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
		cin.ignore(1);
	}
	void Xuat()
	{
		NhanVien::Xuat();
		cout << "So ngay tang ca: " << soNgayTangCa << endl;
	}
	virtual void XuatFile(ofstream& f)
	{
		f << ten << "|";
		f << ngaySinh << "|";
		f << queQuan << "|";
		f << maNhanVien << "|";
		f << maPhong << "|";
		//f << maNguoiQuanLy << "|";
		f << soNgayTangCa << "|"<<endl;
	}
};

class QuanLyNhanVien {
private:
	vector<NhanVien*> danhSachNhanVien;
	void GhiNhanVienBanHangRaFile();
	void GhiNhanVienKeToanRaFile();
public:
	QuanLyNhanVien()
	{
		ifstream f;
		f.open("NhanVienBanHang.txt", ios::in);
		if (f.is_open())
		{
			
			while (f.eof() == false)
			{
				NhanVien* nv = new NhanVienBanHang();
				getline(f, nv->ten, '|');
				if(nv->ten == "\n" || nv->ten == "")
					break;
				getline(f, nv->ngaySinh, '|');
				getline(f, nv->queQuan, '|');
				getline(f, nv->maNhanVien, '|');
				getline(f, nv->maPhong, '|');
				string sSoSP;
				getline(f, sSoSP,'|');
				char c = f.get();
				//getline(f, sSoSP);
				((NhanVienBanHang*)nv)->soSanPhamBanDuoc = atoi(sSoSP.c_str());
				danhSachNhanVien.push_back(nv);
				//f.get();
			}
			f.close();
		}
		f.open("NhanVienKeToan.txt", ios::in);
		if (f.is_open())
		{	
			while (f.eof() == false)
			{
				NhanVien* nv = new NhanVienKeToan();
				getline(f, nv->ten, '|');
				if(nv->ten == "\n" || nv->ten == "")
					break;
				getline(f, nv->ngaySinh, '|');
				getline(f, nv->queQuan, '|');
				getline(f, nv->maNhanVien, '|');
				getline(f, nv->maPhong, '|');
				string sNtc;
				getline(f, sNtc, '|');
				char c = f.get();
				((NhanVienKeToan*)nv)->soNgayTangCa = atoi(sNtc.c_str());
				danhSachNhanVien.push_back(nv);			
			}
			f.close();
		}
		
	}
	~QuanLyNhanVien()
	{
		if(DemNhanVienBanHang() > 0)
			GhiNhanVienBanHangRaFile();
			
		if(DemNhanVienKeToan() > 0)
			GhiNhanVienKeToanRaFile();
	}
	void ThemNhanVien(NhanVien* nv);
	void HienDanhSachNhanVienBanHang();
	void HienDanhSachNhanVienKeToan();
	NhanVien* TimNhanVien(string maNhanVien);
	void XoaNhanVien(string maNhanVien);
	void XemNhanVienThuocPhong(string maPhong);
	int DemNhanVienBanHang();
	int DemNhanVienKeToan();
//	long GetSumSalary();
};

void QuanLyNhanVien::ThemNhanVien(NhanVien* nv)
{
	danhSachNhanVien.push_back(nv);
}

void QuanLyNhanVien::HienDanhSachNhanVienBanHang()
{
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienBanHang"))
		{
			danhSachNhanVien[i]->Xuat();
			cout<<endl;
		}
	}
}

void QuanLyNhanVien::HienDanhSachNhanVienKeToan()
{
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienKeToan"))
		{
			danhSachNhanVien[i]->Xuat();
			cout<<endl;
		}
	}
}

void QuanLyNhanVien::GhiNhanVienBanHangRaFile()
{
	ofstream f;
	f.open("NhanVienBanHang.txt", ios::out);
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienBanHang"))
		{
			danhSachNhanVien[i]->XuatFile(f);
		}
	}
	if (f.is_open())
		f.close();
}


void QuanLyNhanVien::GhiNhanVienKeToanRaFile()
{
	ofstream f;
	f.open("NhanVienKeToan.txt", ios::out);
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienKeToan"))
		{
			danhSachNhanVien[i]->XuatFile(f);
		}
	}
	if (f.is_open())
		f.close();
}

NhanVien* QuanLyNhanVien::TimNhanVien(string maNhanVien)
{
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (danhSachNhanVien[i]->maNhanVien == maNhanVien)
		{
			return danhSachNhanVien[i];
		}
	}
	return NULL;
}

void QuanLyNhanVien::XoaNhanVien(string maNhanVien)
{
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (danhSachNhanVien[i]->maNhanVien == maNhanVien)
		{
			danhSachNhanVien.erase(danhSachNhanVien.begin() + i);
			return;
		}
	}
}

void QuanLyNhanVien::XemNhanVienThuocPhong(string maPhong)
{
	cout<<"\nDanh sach nhan vien thuoc phong co ma "+maPhong+" \n\n";
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (danhSachNhanVien[i]->maPhong == maPhong)
		{
			danhSachNhanVien[i]->Xuat();
			cout<<endl;
		}
	}
}

int QuanLyNhanVien::DemNhanVienBanHang()
{
	int count = 0;
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienBanHang"))
		{
			count++;
		}
	}
	return count;
}

int QuanLyNhanVien::DemNhanVienKeToan()
{
	int count = 0;
	for (int i = 0; i < danhSachNhanVien.size(); i++)
	{
		if (strstr(typeid(*danhSachNhanVien[i]).name(),"NhanVienKeToan"))
		{
			count++;
		}
	}
	return count;
}

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

class HopDongLaoDong
{
	private:
		friend class QuanLyHopDongLaoDong;
		string maHD;
		string maNhanVien;
		string tuNgay;
		string denNgay;
		int luongCanBan;
		string loaiLuong;
		int phuCap;
		string chucVu;
		string ngayKy;
	public:
		void TaoHopDong()
		{
			cout<<"Nhap ma hop dong lao dong:\n";
			getline(cin, maHD);
			cout<<"Hieu luc tu ngay:\n";
			getline(cin, tuNgay);
			cout<<"Hieu luc den ngay:\n";
			getline(cin, denNgay);
			cout<<"Luong can ban (VND):\n";
			cin>>luongCanBan;
			cin.ignore(1);
			int chon;
			do 
			{
				cout<<"Chon loai luong\n";
				cout<<"1. Luong Net\n";
				cout<<"2. Luong Gross\n";
				cin>>chon;
				switch(chon)
				{
					case 1: loaiLuong = "Net"; break;
					case 2: loaiLuong = "Gross"; break;
					default:
					{
						cout<<"Ban vui long chon chinh xac loai luong!\n";	
					} 
				}
			}
			while(chon != 1 && chon != 2);
			cout<<"Nhap phu cap (VND)\n";
			cin>>phuCap;
			cin.ignore(1);
			cout<<"Nhap chuc vu:\n";
			getline(cin, chucVu);
			cout<<"Nhap ngay ky:\n";
			getline(cin, ngayKy);
		}
		void XemHopDong()
		{
			cout<<"Ma so hop dong: "<<maHD<<endl;
			cout<<"Hieu luc tu ngay "<<tuNgay<<" den ngay "<<denNgay<<endl;
			cout<<"Luong can ban: "<<luongCanBan<< " VND. Loai luong "<<loaiLuong<<endl;
			cout<<"Phu cap: "<<phuCap<<" VND"<<endl;
			cout<<"Chuc vu: "<<chucVu<<endl;
			cout<<"Ngay ky hop dong: "<<ngayKy<<endl;
		}
		virtual void XuatFile(ofstream& f)
		{
			f << maHD << "|";
			f << tuNgay << "|";
			f << denNgay << "|";
			f << luongCanBan << "|";
			f << loaiLuong << "|";
			f << phuCap << "|";
			f << chucVu << "|";
			f << ngayKy << "|"<<endl;
		}
};

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

int main()
{
	QuanLyNhanVien quanLyNhanVien;
	NhanVien* nv = NULL;
	QuanLyPhong quanLyPhong;
	QuanLyHopDongLaoDong quanLyHopDongLaoDong;
	QuanLyNghiPhep quanlyNghiPhep;
	int chon;
	do {
		system("cls");
		cout << "0. THOAT." << endl;
		cout << "1. THEM NHAN VIEN BAN HANG" << endl;
		cout << "2. THEM NHAN VIEN KE TOAN" << endl;
		cout << "3. XEM DANH SACH NHAN VIEN BAN HANG" << endl;
		cout << "4. XEM DANH SACH NHAN VIEN KE TOAN" << endl;
		cout << "5. TIM KIEM NHAN VIEN THEO ID" << endl;
		cout << "6. XEM NHAN VIEN THEO MA PHONG"<<endl;
		cout << "7. XOA NHAN VIEN THEO ID" << endl;
		cout << "8. THEM PHONG BAN "<<endl;
		cout << "9. XEM DANH SACH PHONG BAN"<<endl;
		cout << "10. SUA PHONG BAN"<<endl;
		cout << "11. TAO HOP DONG LAO DONG"<<endl;
		cout << "12. XEM DANH SACH HOP DONG LAO DONG HIEN CO"<<endl;
		cout << "13. XOA HOP DONG LAO DONG"<<endl;
		cout << "14. YEU CAU NGHI PHEP"<<endl;
		cout << "15. XEM DANH SACH YEU CAU NGHI PHEP"<<endl;
		cout << "16. TU CHOI YEU CAU NGHI PHEP"<<endl;
		cout << "17. PHE DUYET YEU CAU NGHI PHEP"<<endl;
		cout << "CHON MENU: ";
		cin >> chon;
		cin.ignore(1);
		switch (chon)
		{
			case 1: {
				cout << "------------NHAP THONG TIN NHAN VIEN BAN HANG------------" << endl;
				nv = new NhanVienBanHang();
				nv->Nhap();
				quanLyNhanVien.ThemNhanVien(nv);
				break;
			}
			case 2: {
				cout << "------------NHAP THONG TIN NHAN VIEN KE TOAN------------" << endl;
				nv = new NhanVienKeToan();
				nv->Nhap();
				quanLyNhanVien.ThemNhanVien(nv);
				break;
			}
			case 3: {
				quanLyNhanVien.HienDanhSachNhanVienBanHang();
				system("pause");
				break;
			}
			case 4: {
				quanLyNhanVien.HienDanhSachNhanVienKeToan();
				system("pause");
				break;
			}
			case 5: {
				string maNhanVien;
				cout << "Nhap ma nhan vien can tim:\n";
				cin >> maNhanVien;
				NhanVien* nv = quanLyNhanVien.TimNhanVien(maNhanVien);
				if (nv == NULL)
				{
					cout << "Khong tim thay nhan vien!";
				}
				else
				{
					cout << "\nKet qua tim kiem\n\n";
					nv->Xuat();
				}
				system("pause");
				break;
			}
			case 6:{
				string maPhong;
				cout<<"Nhap ma phong:\n";
				cin>>maPhong;
				quanLyNhanVien.XemNhanVienThuocPhong(maPhong);
				system("pause");
				break;
			}
			case 7:
			{
				string maNhanVien;
				cout << "Nhap ma nhan vien can xoa:\n";
				cin >> maNhanVien;
				NhanVien* nv = quanLyNhanVien.TimNhanVien(maNhanVien);
				if (nv == NULL)
				{
					cout << "Khong tim thay nhan vien!";
				}
				else
				{
					quanLyNhanVien.XoaNhanVien(maNhanVien);
				}
				break;
			}
			case 8:{
				Phong phong;
				phong.Nhap();
				quanLyPhong.ThemPhong(phong);
				cout<<"Them thanh cong\n\n";
				quanLyPhong.XemDanhSachPhong();
				system("pause");
				break;
			}
			case 9:{
				quanLyPhong.XemDanhSachPhong();
				system("pause");
				break;
			}
			case 10:{
				quanLyPhong.SuaPhong();
				system("pause");
				break;
			}
			case 11:{
				HopDongLaoDong hopDongMoi;
				hopDongMoi.TaoHopDong();
				quanLyHopDongLaoDong.ThemVaoDanhSach(hopDongMoi);
				cout<<"Them thanh cong.";
				system("pause");
				break;
			}
			case 12:{
				quanLyHopDongLaoDong.XemDanhSach();
				system("pause");
				break;
			}
			case 13:{
				quanLyHopDongLaoDong.XoaHopDong();
				break;
			}
			case 14:{
				NghiPhep nghiPhep;
				nghiPhep.YeuCauNghiPhep();
				quanlyNghiPhep.ThemNghiPhep(nghiPhep);
				break;
			}
			case 15:{
				quanlyNghiPhep.XemDanhSach();
				system("pause");
				break;
			}
			case 16:{
				quanlyNghiPhep.TuChoi();
				break;
			}
			case 17:{
				quanlyNghiPhep.PheDuyet();
				break;
			}
			case 0: {
				break;
			}
		}
	} while (chon != 0);
}

