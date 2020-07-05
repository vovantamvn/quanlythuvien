#include "nhanvien.h"
#include "sach.h"
#include "docgia.h"
#include <iostream>
#include <string>
using namespace std;
//1.5 tao nguoi dung
NhanVien taonhanvien()
{
    NhanVien nv;
    cout << "nhap id nhan vien: ";
    cin >> nv.id;
    cout << "nhap ten dang nhap:";
    cin.ignore();
    getline(cin, nv.tendangnhap);
    cout << "nhap mat khau : ";
    getline(cin, nv.matkhau);
    cout << "nhap ngay sinh : ";
    cin >> nv.ngaysinh.ngay;
    cout << "Nhap thang sinh : ";
    cin >> nv.ngaysinh.thang;
    cout << "Nhap nam sinh : ";
    cin >> nv.ngaysinh.nam;
    cin.ignore();
    cout << "nhap chung minh nhan dan :  ";
    getline(cin, nv.cmnd);
    cout << "nhap dia chi : ";
    getline(cin, nv.diachi);
    cout << "nhap gioi tinh :  ";
    cin >> nv.gioitinh;
    nv.trangthai = 1;
    return nv;
}
//1.3 thay doi mat khau;
void thaydoimatkhau(NhanVien &nv)
{
    fflush(stdin);
    string mkmoi;
    string xtmkmoi;
    cout << "Nhap mat khau moi: ";
    getline(cin, mkmoi);
    cout << "Nhap lai mat khau moi: ";
    getline(cin, xtmkmoi);

    if (mkmoi.compare(xtmkmoi))
    {
        nv.matkhau = mkmoi;
    }
    else
    {
        cout << "Mat khau xac thuc khong giong!";
    }
}
// 1.4 cap  nhat nhan vien
void capnhatnhanvien(NhanVien &nv)
{
    cout << "Nhap lai thong tin nhan vien : ";
    
    cout << "nhap id nhan vien : ";
    cin >> nv.id;
    cout << "nhap ten dang nhap : ";
    cin.ignore();
    getline(cin, nv.tendangnhap);
    cout << "nhap mat khau : ";
    getline(cin, nv.matkhau);
    cout << "nhap ngay sinh : ";
    cin >> nv.ngaysinh.ngay;
    cout << "Nhap thang sinh : " ;
    cin >> nv.ngaysinh.thang;
    cout << "Nhap nam sinh : ";
    cin >> nv.ngaysinh.nam;
    cin.ignore();
    cout << "nhap chung minh nhan dan : ";
    getline(cin, nv.cmnd);
    cout << "nhap dia chi : ";
    getline(cin, nv.diachi);
    cout << "nhap gioi tinh :  ";
    cin >> nv.gioitinh;
    cout << "nhap tinh trang : ";
    cin >> nv.trangthai;
    
}

//2.2 them doc gia
DocGia themdocgia()
{
    DocGia d;
    cout << "nhap ma :";
    cin >> d.ma;
    cout << "nhap ten doc gia : ";
    cin.ignore();
    getline(cin, d.hoten);
    cout << "nhap chung minh nhan dan :";
    getline(cin, d.cmnd);
    cout << "nhap ngay sinh : " ;
    cin >> d.ngaysinh.ngay;
    cout << "nhap thang sinh : " ;
    cin >> d.ngaysinh.thang;
    cout << "nhap nam sinh : ";
    cin >> d.ngaysinh.nam;
    cout << "nhap gioi tinh : ";
    cin >> d.gioitinh;
    cout << "nhap email : ";
    cin.ignore();
    getline(cin, d.email);
    cout << "nhap dia chi : ";
    getline(cin, d.diachi);
    cout << "nhap ngay lap the  : ";
    cin >> d.ngaylapthe.ngay;
    cout << "nhap thang lap the : ";
    cin >> d.ngaylapthe.thang;
    cout << "nhap nam lap the : ";
    cin >> d.ngaylapthe.nam;
    cout << "nhap ngay het han : ";
    cin >> d.ngayhethan.ngay;
    cout << "nhap thang het han : ";
    cin >> d.ngayhethan.thang;
    cout << "nhap nam het han : ";
    cin >> d.ngayhethan.ngay;
    return d;
}
//2.3 sua thong tin doc gia
void suathongtindocgia(DocGia d)
{
    cout << "Nhap lai thong tin doc gia  : ";
    cout << "nhap ma  : ";
    cin >> d.ma;
    cout << "nhap ten doc gia : ";
    cin.ignore();
    getline(cin, d.hoten);
    cout << "nhap chung minh nhan dan  : ";
    getline(cin, d.cmnd);
    cout << "nhap ngay sinh  :  ";
    cin >>d.ngaysinh.ngay;
     cout << "nhap thang sinh  :  ";
    cin >>d.ngaysinh.thang;
     cout << "nhap nam sinh  :  ";
    cin >>d.ngaysinh.nam;
    cout << "nhap gioi tinh  : ";
    cin >> d.gioitinh;
    cin.ignore();
    cout << "nhap email  : " ;
    getline(cin, d.email);
    cout << "nhap dia chi  :  ";
    getline(cin, d.diachi);
    cout << "nhap ngay lap the  :  " ;
    cin >> d.ngaylapthe.ngay;
    cout << "nhap thang lap the  :  " ;
    cin >> d.ngaylapthe.thang;
    cout << "nhap nam lap the   : ";
    cin >> d.ngaylapthe.nam;
    cout << "nhap ngay het han  : ";
    cin >> d.ngayhethan.ngay;
    cout << "nhap thang het han  : ";
    cin >> d.ngayhethan.thang;
    cout << "nhap nam het han  :  ";
    cin >> d.ngayhethan.ngay;
}
//3.2 them sach
Sach themsach()
{
    Sach s;
    cout << "nhap ma sach  : ";
    
    cin >> s.masach;
    cin.ignore();
    cout << "nhap ten sach  : ";
    getline(cin, s.tensach);
    cout << "nhap tac gia  : ";
    getline(cin, s.tacgia);
    cout << "nhap nha san xuat :  ";
    getline(cin, s.nhasanxuat);
    cout << "nhap nam xuat ban  :  ";
    getline(cin, s.namsuatban);
    cout << "nhap the loai :  " ;
    getline(cin, s.theloai);
    cout << "nhap don gia  : ";
    cin >> s.giasach;
    cout << "nhap so luong : " ;
    cin >> s.soluong;
    return s;
}
//3.3 chinh sua thong tin sach
void chinhsuathongtinsach(Sach &s)
{
    cout << "NHap lai thong tin sach : " ;
    cout << "nhap ma sach  : ";
    
    cin >>s.masach;

    cout << "nhap ten sach  : ";
    cin.ignore();
    getline(cin, s.tensach);
    cout << "nhap tac gia  : ";
    getline(cin, s.tacgia);
    cout << "nhap nha san xuat :";
    getline(cin, s.nhasanxuat);
    cout << "nhap nam xuat ban  : ";
    getline(cin, s.namsuatban);
    cout << "nhap the loai : ";
    getline(cin, s.theloai);
    cout << "nhap don gia : ";
    cin >> s.giasach;
    cout << "nhap so luong : ";
    cin >> s.soluong;
}

int main()
{
    taonhanvien();
}