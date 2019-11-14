#include <iostream>
#include <string>
#include <fstream>
using namespace std;

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
