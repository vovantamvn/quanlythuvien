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
void thaydoimatkhau()
{
 


}
//2.2 them doc gia
DocGia themdocgia()
{
    DocGia d;
    cout << "nhap ma "<<endl;
    getline(cin, d.ma);
    cout << "nhap ten doc gia"<<endl;
    getline(cin, d.hoten);
    cout << "nhap chung minh nhan dan "<<endl;
    getline(cin, d.cmnd);
    cout << "nhap ngay sinh  "<<endl;
    getline(cin, d.ngaysinh);
    cout << "nhap gioi tinh  "<<endl;
    cin >> d.gioitinh;
    cout << "nhap email "<<endl;
    getline(cin, d.email);
    cout << "nhap dia chi  "<<endl;
    getline(cin, d.diachi);
    cout << "nhap ngay lap the  "<<endl;
    getline(cin, d.ngaylapthe);
    cout << "nhap ngay het han "<<endl;
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
    cout << "nhap ma sach "<<endl;
    getline(cin, s.masach);
    cout << "nhap ten sach "<<endl;
    getline(cin, s.tensach);
    cout << "nhap tac gia "<<endl;
    getline(cin, s.tacgia);
    cout << "nhap nha san xuat "<<endl;
    getline(cin, s.nhasanxuat);
    cout << "nhap nam xuat ban  "<<endl;
    getline(cin, s.namsuatban);
    cout << "nhap the loai "<<endl;
    getline(cin, s.theloai);
    cout << "nhap don gia "<<endl;
    cin >> s.giasach;
    cout << "nhap so luong"<<endl;
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
