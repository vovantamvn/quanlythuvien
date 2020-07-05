#include "nhanvien.h"
#include "sach.h"
#include "docgia.h"

#include <iostream>
#include <string>
using namespace std;

// Bien toan cuc
NodeNhanVien  *headNhanVien = NULL;
NhanVien *nhanVien = NULL;
// Doc gia
NodeDocGia *headDocGia = NULL;

// 1.1 dang nhap
bool dangNhap(string tendangnhap, string matkhau) {
    NodeNhanVien *point = headNhanVien;
    while (point != NULL)
    {
        if (tendangnhap == point->data.tendangnhap && matkhau == point->data.matkhau)
        {
            return true;
        }
        
    }

    return false;
}

// 1.1 chuc nang dang nhap
void chucNangDangNhap() {
    string tendangnhap;
    string matkhau;
    // xoa bo nho dem
    fflush(stdin);
    cout<<"Nhap ten dang nhap: ";
    getline(cin, tendangnhap);

    cout<<"Nhap mat khau: ";
    getline(cin, matkhau);

    if (dangNhap(tendangnhap, matkhau))
    {
        // Chuc nang dang nhap dung
    }
    else
    {
        cout<<"Ten dang nhap hoac mat khau bi sai!"<<endl;
    }
}

// 1.2 dang xuat
void dangXuat() {
    nhanVien = NULL;
}

// 1.5 tao nhan vien
NhanVien& taoNhanvien()
{
    NhanVien nv;
    cout << "nhap id nhan vien: ";
    cin >> nv.id;
    cout << "nhap ten dang nhap: ";
    getline(cin, nv.hoten);
    cout << "nhap mat khau: ";
    getline(cin, nv.matkhau);
    cout << "nhap ngay sinh: ";
    getline(cin, nv.ngaysinh);
    cout << "nhap chung minh nhan dan: ";
    getline(cin, nv.cmnd);
    cout << "nhap dia chi: ";
    getline(cin, nv.diachi);
    cout << "nhap gioi tinh (0: nu, 1: nam): ";
    cin >> nv.gioitinh;
    cout << "nhap tinh trang (0: block, 1: actived): ";
    cin >> nv.trangthai;
    cout << "nhap ten nhan vien: ";
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

// 1.5 tao nguoi dung
// them nguoi dung vao danh sach
void themNguoiDungVaoDau (NodeNhanVien *head, NhanVien &nv) {
    NodeNhanVien *node = new NodeNhanVien();
    node->data = nv;
    node->next = NULL;

    // check head
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
}

// in thng tin ngay
void inThongTinNgay(string thongtin, Ngay ngay) {
    cout<<thongtin<<": "<<ngay.ngay<<"/"<<ngay.thang<<"/"<<ngay.nam<<endl;
}

// Xem thong tin doc gia
void inDocGia(DocGia dg) {
   cout << "Ma: " << dg.ma <<endl;
   cout << "Ho ten: "<<dg.hoten<<endl;
   cout<<"CMND: "<<dg.cmnd<<endl;
   cout<< "Gioi tinh: " << (dg.gioitinh == 1)? "Nam\n" : "Nu\n";
   cout<<"Email: "<<dg.email<<endl;
   cout<<"Dia chi: "<<dg.diachi<<endl;

   inThongTinNgay("Ngay sinh", dg.ngaysinh);
   inThongTinNgay("Ngay lap the", dg.ngaylapthe);
   inThongTinNgay("Ngay het han", dg.ngayhethan);
}

// 2.1 In danh sach doc gia
void inDanhSachDocGia(NodeDocGia *head) {
    NodeDocGia *point = head;

    while (point != NULL)
    {
        inDocGia(point->data);
        point = point->next;
    }    
}

//2.2 them doc gia
DocGia& themdocgia()
{
    DocGia d;
    cout << "nhap ma: ";
    getline(cin, d.ma);
    cout << "nhap ten doc gia: ";
    getline(cin, d.hoten);
    cout << "nhap chung minh nhan dan: ";
    getline(cin, d.cmnd);
    cout << "nhap ngay sinh:  ";
    getline(cin, d.ngaysinh);
    cout << "nhap gioi tinh: ";
    cin >> d.gioitinh;
    cout << "nhap email: ";
    getline(cin, d.email);
    cout << "nhap dia chi:  ";
    getline(cin, d.diachi);
    cout << "nhap ngay het han: ";
    getline(cin, d.ngayhethan);
    return d;
}

//2.3 sua thong tin doc gia
void suathongtindocgia()
{
}

// 2.4 Xoa thong tin mot doc gia
bool xoaDocGiaTheoId(NodeDocGia *head, int id) {
    NodeDocGia *point = headDocGia;

    if (point == NULL)
    {
        return false;
    }
    

    if(point->data.ma == id) {
        head = head->next;
        return true;
    }
    
    while (point->next != NULL)
    {
        if (point->next->data.ma == id)
        {
            NodeDocGia *tmp = point->next->next;
            point->next = tmp;
            return true;   
        }
    }
    
    return false;
}

// Chuc nang xoa thong tin doc gia
void xoaThongTinDocGia() {

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