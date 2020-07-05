#include "nhanvien.h"
#include "sach.h"
#include "docgia.h"
#include <iostream>
#include <string>
using namespace std;

NhanVien taonhanvien()
{
    NhanVien nv;
    cout << "nhap id nhan vien";
    cin >> nv.id;
    cout << "nhap ten dang nhap";
    getline(cin, nv.hoten);
    cout << "nhap mat khau";
    getline(cin, nv.matkhau);
    cout << "nhap ngay sinh";
    getline(cin, nv.ngaysinh);
    cout << "nhap chung minh nhan dan ";
    getline(cin, nv.cmnd);
    cout << "nhap dia chi";
    getline(cin, nv.diachi);
    cout << "nhap gioi tinh ";
    cin >> nv.gioitinh;
    cout << "nhap tinh trang ";
    cin >> nv.trangthai;
    cout << "nhap ten nhan vien";

    return nv;
}
// 1.4 cap  nhat nhan vien
void capnhatnhanvien()
{
}
//1.3 thay doi mat khau;
void thaydoimatkhau(NhanVien &nv)
{
    fflush(stdin);
    string mkmoi;
    string xtmkmoi;
    cout<<"Nhap mat khau moi: ";
    getline(cin, mkmoi);
    cout<<"Nhap lai mat khau moi: ";
    getline(cin, xtmkmoi);

    if (mkmoi.compare(xtmkmoi))
    {
        nv.matkhau = mkmoi;
    }
    else
    {
        cout<<"Mat khau xac thuc khong giong!" << endl;
    }
}


//2.2 them doc gia
DocGia themdocgia()
{
    DocGia d;
    cout << "nhap ma ";
    getline(cin, d.ma);
    cout << "nhap ten doc gia";
    getline(cin, d.hoten);
    cout << "nhap chung minh nhan dan ";
    getline(cin, d.cmnd);
    cout << "nhap ngay sinh  ";
    getline(cin, d.ngaysinh);
    cout << "nhap gioi tinh  ";
    cin >> d.gioitinh;
    cout << "nhap email ";
    getline(cin, d.email);
    cout << "nhap dia chi  ";
    getline(cin, d.diachi);
    cout << "nhap ngay lap the  ";
    getline(cin, d.ngaylapthe);
    cout << "nhap ngay het han ";
    getline(cin, d.ngayhethan);
    return d;
}
//2.3 sua thong tin doc gia
void suathongtindocgia()
{
}
//3.2 them sach
Sach themsach()
{
    Sach s;
    cout << "nhap ma sach ";
    getline(cin, s.masach);
    cout << "nhap ten sach ";
    getline(cin, s.tensach);
    cout << "nhap tac gia ";
    getline(cin, s.tacgia);
    cout << "nhap nha san xuat ";
    getline(cin, s.nhasanxuat);
    cout << "nhap nam xuat ban  ";
    getline(cin, s.namsuatban);
    cout << "nhap the loai ";
    getline(cin, s.theloai);
    cout << "nhap don gia ";
    cin >> s.giasach;
    cout << "nhap so luong";
    cin >> s.soluong;
    return s;
}
//3.3 chinh sua thong tin sach
void chinhsuathongtinsach()
{
}

int main() 
{

}