#include "nhanvien.h"
#include "sach.h"
#include "docgia.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


/*-------------------------------------------------------*/
// Bien toan cuc
NodeNhanVien  *headNhanVien = NULL;
NhanVien *nhanVien = NULL;
// Doc gia
NodeDocGia *headDocGia = NULL;
NodeSach *headSach = NULL;
/*-------------------------------------------------------*/


/*-------------------------------------------------------*/
// Chuc nang phu
void themSachVaoDauNode(Sach sach);
void docSachTuFile()
{
    //mã sách, nam, giá sách, số quyển sách, tên sách, tác giả, nhà xuất bản, thể loại
    //1 1997 200000 205De meo phieu luu ki,Ngo Bao Trung,Nha xuat ban puong duong,Sach giai
    ifstream file("sach.txt");
    while (!file.eof())
    {
        Sach sach;
        file>>sach.masach;
        file>>sach.namxuatban;
        file>>sach.giasach;
        file>>sach.soluong;
        getline(file, sach.tensach, ',');
        getline(file, sach.tacgia, ',');
        getline(file, sach.nhasanxuat, ',');
        getline(file, sach.theloai);

        themSachVaoDauNode(sach);
    }
}

void docDocGiaTuFile()
{

}

void docNguoiDungTuFile()
{

}
/*-------------------------------------------------------*/


/*-------------------------------------------------------*/
// Chuc nang cua chuong trinh
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

//1.3 thay doi mat khau;
//oke 
void thaydoimatkhau(NhanVien &nv)
{
    fflush(stdin);
    string mkmoi;
    string xtmkmoi;
    cout << "Nhap mat khau moi: ";
    cin.ignore();
    getline(cin, mkmoi);
    cout << "Nhap lai mat khau moi: ";
    getline(cin, xtmkmoi);

    if (mkmoi == xtmkmoi)
    {
        nv.matkhau = mkmoi;
         cout << "Mat khau da doi thanh cong ! ";
    }
    else
    {
        cout << "Mat khau xac thuc khong giong!";
    }
}

// 1.4 cap  nhat nhan vien
//oke 
void capnhatnhanvien(NhanVien &nv)
{
    cout << "Nhap lai thong tin nhan vien : ";
    cout << "nhap ten dang nhap: ";
    cin.ignore();
    getline(cin, nv.tendangnhap);
    cout << "nhap mat khau: ";
    getline(cin, nv.matkhau);
    cout << "nhap ngay sinh: ";
    cin >> nv.ngaysinh.ngay;
    cout << "Nhap thang sinh: " ;
    cin >> nv.ngaysinh.thang;
    cout << "Nhap nam sinh: ";
    cin >> nv.ngaysinh.nam;
    cin.ignore();
    cout << "nhap chung minh nhan dan: ";
    getline(cin, nv.cmnd);
    cout << "nhap dia chi: ";
    getline(cin, nv.diachi);
    cout << "nhap gioi tinh:  ";
    cin >> nv.gioitinh;
    cout << "nhap tinh trang: ";
    cin >> nv.trangthai;   
}

//1.5 tao nguoi dung
//oke
NhanVien taonhanvien()
{
    NhanVien nv;
    cout << "nhap id nhan vien: ";
    cin >> nv.id;
    cout << "nhap ten dang nhap: ";
    getline(cin, nv.tendangnhap);
    cout << "nhap mat khau: ";
    getline(cin, nv.matkhau);
    cout << "nhap chung minh nhan dan: ";
    getline(cin, nv.cmnd);
    cout << "nhap dia chi: ";
    getline(cin, nv.diachi);
    cout << "nhap gioi tinh (0: nu, 1: nam): ";
    cin >> nv.gioitinh;
    cout << "nhap ngay sinh: ";
    cin >> nv.ngaysinh.ngay;
    cout << "nhap thang sinh: ";
    cin >> nv.ngaysinh.thang;
    cout << "nhap nam sinh: ";
    cin >> nv.ngaysinh.nam;
    cout << "nhap tinh trang (0: block, 1: actived): ";
    cin >> nv.trangthai;
    return nv;
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
//oke
void inThongTinNgay(string thongtin, Ngay ngay) {
    cout<<thongtin<<": "<<ngay.ngay<<"/"<<ngay.thang<<"/"<<ngay.nam<<endl;
}

// Xem thong tin doc gia
//oke
void inDocGia(DocGia dg) {
   cout << "Ma: " << dg.ma <<endl;
   cout << "Ho ten: "<<dg.hoten<<endl;
   cout<<"CMND: "<<dg.cmnd<<endl;
    cout<< "Gioi tinh: ";
    if(dg.gioitinh==1){
         cout<< "Nam " <<endl;
    }
    else{
         cout<< "Nu " <<endl;
    }
   cout<<"Email: "<<dg.email<<endl;
   cout<<"Dia chi: "<<dg.diachi<<endl;

   inThongTinNgay("Ngay sinh", dg.ngaysinh);
   inThongTinNgay("Ngay lap the", dg.ngaylapthe);
   inThongTinNgay("Ngay het han", dg.ngayhethan);
}

// 2.1 In danh sach doc gia
void inDanhSachDocGia(NodeDocGia *head) 
{
    NodeDocGia *point = head;

    while (point != NULL)
    {
        inDocGia(point->data);
        point = point->next;
    }    
}

//2.2 them doc gia
//oke
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
    cout << "nhap ngay sinh : ";
    cin >> d.ngaysinh.ngay;
    cout << "nhap thang sinh : ";
    cin >> d.ngaysinh.thang;
    cout << "nhap nam sinh : ";
    cin >> d.ngaysinh.nam;
    cout << "nhap gioi tinh (0: nu, 1: nam): ";
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
    cin >> d.ngayhethan.nam;
   
    return d;
}

//2.3 sua thong tin doc gia
//oke
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

// 2.5 Tim kiem doc gia theo CMND
DocGia* timDocGiaTheoChungMinhNhanDan(string cmnd)
{
    NodeDocGia *point = headDocGia;
    while (point != NULL)
    {
        if (point->data.cmnd == cmnd)
        {
            return &point->data;
        }
        
        point = point->next;
    }
    
    return NULL;
}

// 2.6 Tim kiem sach theo ho ten

// 3.1 Xem danh sach cac sach trong thu vien
// Oke
void xemSachTrongThuVien()
{
    NodeSach *point = headSach;
    //1 1997 200000 205De meo phieu luu ki 3,Ngo Bao Trung,Nha xuat ban puong duong,Sach toan
    printf("%-10s %-30s %-20s %-20s %-10s\n", "Ma sach", "Ten sach", "Tac gia", "Nam xuat ban" , "So luong");
    while (point != NULL)
    {
        Sach sach = point->data;
        printf("%-10d %-30s %-20s %-20d %-10d\n", 
            sach.masach, 
            sach.tensach.c_str(),
            sach.tacgia.c_str(),
            sach.namxuatban,
            sach.soluong);

        point = point->next;
    }
}

// 3.2 them sach
// Oke
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
    cout << "nhap the loai :  " ;
    getline(cin, s.theloai);
    cout << "nhap don gia  : ";
    cin >> s.giasach;
    cout << "nhap nam xuat ban  :  ";
    cin >> s.namxuatban;
    cout << "nhap so luong : " ;
    cin >> s.soluong;
    return s;
}

// 3.2 Them sach vao dau node
void themSachVaoDauNode(Sach sach)
{
    NodeSach *node = new NodeSach();
    node->data = sach;
    node->next = NULL;

    if (headSach == NULL)
    {
        headSach = node;
    }
    else
    {
        node->next = headSach;
        headSach = node;   
    }
}

//3.3 chinh sua thong tin sach
//oke
void chinhsuathongtinsach(Sach &s)
{
    cout << "Nhap lai thong tin sach: "<<endl;
    cout << "nhap ma sach: ";
    cin >>s.masach;
    cin.ignore();
    cout << "nhap ten sach: ";
    cin.ignore();
    getline(cin, s.tensach);
    cout << "nhap tac gia: ";
    getline(cin, s.tacgia);
    cout << "nhap nha san xuat: ";
    getline(cin, s.nhasanxuat);
    cout << "nhap the loai: ";
    getline(cin, s.theloai);
    cout << "nhap don gia: ";
    cin >> s.giasach;
    cout << "nhap nam xuat ban : ";
    cin >> s.namxuatban;
    cout << "nhap so luong: ";
    cin >> s.soluong;
}

// 4 Lap phieu muon sach
void lapPhieuMuonSach()
{

}


// Ket thuc cac chuc nang
/*-------------------------------------------------------*/


/*-------------------------------------------------------*/
// Ham main

int main()
{
  DocGia dg= themdocgia();
  inDocGia(dg);
}
/*-------------------------------------------------------*/