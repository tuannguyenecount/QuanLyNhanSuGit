#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "QuanLyNhanVien.h"
#include "QuanLyPhong.h"
#include "QuanLyHopDongLaoDong.h"
#include "QuanLyNghiPhep.h"
using namespace std;


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
					cout << "Ket qua tim kiem\n";
					nv->Xuat();
				}
				system("pause");
				break;
			}
			case 6:{
				string maPhong;
				cout<<"Nhap ma phong:\n";
				cin>>maPhong;
				cout<<"Danh sach nhan vien thuoc phong nay\n";
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

