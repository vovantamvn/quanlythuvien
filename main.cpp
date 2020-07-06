#include "nhanvien.h"
#include "sach.h"
#include "docgia.h"
#include "muontra.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*-------------------------------------------------------*/
// Bien toan cuc
NhanVien *nhanVien = NULL;
NodeNhanVien *headNhanVien = NULL;
NodeMuonTra *headMuonTra = NULL;
NodeDocGia *headDocGia = NULL;
NodeSach *headSach = NULL;
const int ROLE_ADMIN = 1;
const int ROLE_QUANLY = 2;
const int ROLE_CHUYENVIEN = 3;
/*-------------------------------------------------------*/

/*-------------------------------------------------------*/
// Chuc nang phu
void themSachVaoDauNode(Sach sach);

void themDocGiaVaoDauNode(DocGia docgia)
{
    NodeDocGia *node = new NodeDocGia();
    node->data = docgia;
    node->next = NULL;

    if (headDocGia == NULL)
    {
        headDocGia = node;
    }
    else
    {
        node->next = headDocGia;
        headDocGia = node;
    }
}

void themNhanVienVaoDauNode(NhanVien nhanvien)
{
    NodeNhanVien *node = new NodeNhanVien();
    node->data = nhanvien;
    node->next = NULL;

    if (headNhanVien == NULL)
    {
        headNhanVien = node;
    }
    else
    {
        node->next = headNhanVien;
        headNhanVien = node;
    }
}

void xoaManHinh()
{
    //system("clear");
    system("cls");
}

void docSachTuFile()
{
    //mã sách, nam, giá sách, số quyển sách, tên sách, tác giả, nhà xuất bản, thể loại
    //1 1997 200000 205De meo phieu luu ki,Ngo Bao Trung,Nha xuat ban puong duong,Sach giai
    ifstream file("sach.txt");
    while (!file.eof())
    {
        Sach sach;
        file >> sach.masach;
        file >> sach.namxuatban;
        file >> sach.giasach;
        file >> sach.soluong;
        getline(file, sach.tensach, ',');
        getline(file, sach.tacgia, ',');
        getline(file, sach.nhasanxuat, ',');
        getline(file, sach.theloai);

        themSachVaoDauNode(sach);
    }
    file.close();
}

void docDocGiaTuFile()
{
    //4 1 25 06 1999 2 7 2020 2 7 2021Vo Van Tam,1922215448,vovantam@gmail.com,Hai Lang Quang Tri
    //ma,gioitinh,ngaysinh,ngaylapthe,ngayhethan,hoten,cmnd,email,diachi
    ifstream file("docgia.txt");
    while (!file.eof())
    {
        DocGia docgia;
        file >> docgia.ma;
        file >> docgia.gioitinh;
        file >> docgia.ngaysinh.ngay;
        file >> docgia.ngaysinh.thang;
        file >> docgia.ngaysinh.nam;
        file >> docgia.ngaylapthe.ngay;
        file >> docgia.ngaylapthe.thang;
        file >> docgia.ngaylapthe.nam;
        file >> docgia.ngayhethan.ngay;
        file >> docgia.ngayhethan.thang;
        file >> docgia.ngayhethan.nam;
        getline(file, docgia.hoten, ',');
        getline(file, docgia.cmnd, ',');
        getline(file, docgia.email, ',');
        getline(file, docgia.diachi);

        themDocGiaVaoDauNode(docgia);
    }
    file.close();
}

void xoaBoNhoDem()
{
    cout << "Enter de tiep tuc!" << endl;
    cin.clear();
    cin.ignore(INT32_MAX, '\n');
}

void docNhanVienTuFile()
{
    //1 1 1 1 25 6 1999vovantam,Vo Van,1921682211,Hue
    //id/role//trang thai/gioi tinh/ngay/thang/nam/ten dang nhap/ho ten/cmnd/dia chi
    ifstream file("nhanvien.txt");
    while (!file.eof())
    {
        NhanVien nv;
        file >> nv.id;
        file >> nv.loainguoidung;
        file >> nv.trangthai;
        file >> nv.gioitinh;
        file >> nv.ngaysinh.ngay;
        file >> nv.ngaysinh.thang;
        file >> nv.ngaysinh.nam;
        getline(file, nv.tendangnhap, ',');
        getline(file, nv.matkhau, ',');
        getline(file, nv.hoten, ',');
        getline(file, nv.cmnd, ',');
        getline(file, nv.diachi);

        themNhanVienVaoDauNode(nv);
    }
    file.close();
}

void themPhieuMuonTraVaoDauNode(MuonTra muontra)
{
    NodeMuonTra *node = new NodeMuonTra();
    node->data = muontra;
    node->next = NULL;

    if (headMuonTra == NULL)
    {
        headMuonTra = node;
    }
    else
    {
        node->next = headMuonTra;
        headMuonTra = node;
    }
}

void docPhieuMuonTraTuFile()
{
    //2 1 1 2 0 25 6 2020 25 7 2020 28 6 2020
    ifstream file("muontra.txt");
    while (!file.eof())
    {
        MuonTra muontra;
        file >> muontra.ma;
        file >> muontra.madocgia;
        file >> muontra.masach[0];
        file >> muontra.masach[1];
        file >> muontra.masach[2];
        file >> muontra.ngaymuon.ngay;
        file >> muontra.ngaymuon.thang;
        file >> muontra.ngaymuon.nam;
        file >> muontra.ngaytradukien.ngay;
        file >> muontra.ngaytradukien.thang;
        file >> muontra.ngaytradukien.nam;
        file >> muontra.ngaytrathucte.ngay;
        file >> muontra.ngaytrathucte.thang;
        file >> muontra.ngaytrathucte.nam;

        themPhieuMuonTraVaoDauNode(muontra);
    }
    file.close();
}

void inSachRaFile()
{
    ofstream file("sach.txt");

    NodeSach *point = headSach;
    while (point != NULL)
    {
        Sach sach = point->data;
        file << sach.masach << " ";
        file << sach.namxuatban << " ";
        file << sach.giasach << " ";
        file << sach.soluong;
        file << sach.tensach << ',';
        file << sach.tacgia << ',';
        file << sach.nhasanxuat << ',';
        file << sach.theloai;

        point = point->next;
        if (point != NULL)
        {
            file << endl;
        }
    }
    file.close();
}

void inDocGiaRaFile()
{
    ofstream file("docgia.txt");

    NodeDocGia *point = headDocGia;
    while (point != NULL)
    {
        DocGia docgia = point->data;
        file << docgia.ma << " ";
        file << docgia.gioitinh << " ";
        file << docgia.ngaysinh.ngay << " ";
        file << docgia.ngaysinh.thang << " ";
        file << docgia.ngaysinh.nam << " ";
        file << docgia.ngaylapthe.ngay << " ";
        file << docgia.ngaylapthe.thang << " ";
        file << docgia.ngaylapthe.nam << " ";
        file << docgia.ngayhethan.ngay << " ";
        file << docgia.ngayhethan.thang << " ";
        file << docgia.ngayhethan.nam;
        file << docgia.hoten << ',';
        file << docgia.cmnd << ',';
        file << docgia.email << ',';
        file << docgia.diachi;

        point = point->next;
        if (point != NULL)
        {
            file << endl;
        }
    }
    file.close();
}

void inNhanVienRaFile()
{
    ofstream file("nhanvien.txt");

    NodeNhanVien *point = headNhanVien;
    while (point != NULL)
    {
        NhanVien nv = point->data;
        file << nv.id << " ";
        file << nv.loainguoidung << " ";
        file << nv.trangthai << " ";
        file << nv.gioitinh << " ";
        file << nv.ngaysinh.ngay << " ";
        file << nv.ngaysinh.thang << " ";
        file << nv.ngaysinh.nam;
        file << nv.tendangnhap << ',';
        file << nv.matkhau << ',';
        file << nv.hoten << ',';
        file << nv.cmnd << ',';
        file << nv.diachi;

        point = point->next;
        if (point != NULL)
        {
            file << endl;
        }
    }

    file.close();
}

void inPhieuMuonTraRaFile()
{
    ofstream file("muontra.txt");

    NodeMuonTra *point = headMuonTra;
    while (point != NULL)
    {
        MuonTra muontra = point->data;

        file << muontra.ma << " ";
        file << muontra.madocgia << " ";
        file << muontra.masach[0] << " ";
        file << muontra.masach[1] << " ";
        file << muontra.masach[2] << " ";
        file << muontra.ngaymuon.ngay << " ";
        file << muontra.ngaymuon.thang << " ";
        file << muontra.ngaymuon.nam << " ";
        file << muontra.ngaytradukien.ngay << " ";
        file << muontra.ngaytradukien.thang << " ";
        file << muontra.ngaytradukien.nam << " ";
        file << muontra.ngaytrathucte.ngay << " ";
        file << muontra.ngaytrathucte.thang << " ";
        file << muontra.ngaytrathucte.nam;

        point = point->next;
        if (point != NULL)
        {
            file << endl;
        }
    }

    file.close();
}
/*-------------------------------------------------------*/

/*-------------------------------------------------------*/
// Chuc nang cua chuong trinh
// 1.1 dang nhap
bool dangNhap(string tendangnhap, string matkhau)
{
    NodeNhanVien *point = headNhanVien;
    while (point != NULL)
    {
        if (tendangnhap == point->data.tendangnhap && matkhau == point->data.matkhau)
        {
            nhanVien = &point->data;
            return true;
        }
        point = point->next;
    }

    return false;
}

// 1.2 dang xuat
void dangXuat()
{
    inSachRaFile();
    inDocGiaRaFile();
    inNhanVienRaFile();
    inPhieuMuonTraRaFile();
    nhanVien = NULL;
}

//1.3 thay doi mat khau;
void thaydoimatkhau(NhanVien &nv)
{
    string mkmoi;
    string xtmkmoi;
    cout << "Nhap mat khau moi: ";
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
void capnhatnhanvien(NhanVien &nv)
{
    cout << "nhap ten dang nhap: ";
    getline(cin, nv.tendangnhap);
    cout << "nhap mat khau: ";
    getline(cin, nv.matkhau);
    cout << "nhap chung minh nhan dan: ";
    getline(cin, nv.cmnd);
    cout << "nhap dia chi: ";
    getline(cin, nv.diachi);
    cout << "nhap ngay sinh: ";
    cin >> nv.ngaysinh.ngay;
    cout << "Nhap thang sinh: ";
    cin >> nv.ngaysinh.thang;
    cout << "Nhap nam sinh: ";
    cin >> nv.ngaysinh.nam;
    cout << "nhap gioi tinh:  ";
    cin >> nv.gioitinh;
    cout << "nhap tinh trang: ";
    cin >> nv.trangthai;
}

//1.5 tao nguoi dung
NhanVien taonhanvien()
{
    NhanVien nv;
    cout << "nhap ten dang nhap: ";
    getline(cin, nv.tendangnhap);
    cout << "nhap ho ten: ";
    getline(cin, nv.hoten);
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

void chucNangThemNhanVien()
{
    NhanVien nv = taonhanvien();
    themNhanVienVaoDauNode(nv);
}

void inThongTinDocGia(DocGia dg)
{
    printf(
        "%-10d %-30s %02d/%02d/%02d %-10s %02d/%02d/%02d\n",
        dg.ma,
        dg.hoten.c_str(),
        dg.ngaysinh.ngay, dg.ngaysinh.thang, dg.ngaysinh.nam,
        (dg.gioitinh == 1) ? "Nam" : "Nu",
        dg.ngaylapthe.ngay, dg.ngaylapthe.thang, dg.ngaylapthe.nam);
}

void inThongTinNgay(string thongtin, Ngay ngay)
{
    cout << thongtin << " : " << ngay.ngay << " / " << ngay.thang << " / " << ngay.nam << endl;
}

// Xem thong tin doc gia
void inDocGia(DocGia dg)
{
    cout << "Ma: " << dg.ma << endl;
    cout << "Ho ten: " << dg.hoten << endl;
    cout << "CMND: " << dg.cmnd << endl;
    cout << "Gioi tinh: ";
    if (dg.gioitinh == 1)
    {
        cout << "Nam " << endl;
    }
    else
    {
        cout << "Nu " << endl;
    }
    cout << "Email: " << dg.email << endl;
    cout << "Dia chi: " << dg.diachi << endl;

    inThongTinNgay("Ngay sinh", dg.ngaysinh);
    inThongTinNgay("Ngay lap the", dg.ngaylapthe);
    inThongTinNgay("Ngay het han", dg.ngayhethan);
}

// 2.1 In danh sach doc gia
void inDanhSachDocGia()
{
    NodeDocGia *point = headDocGia;
    // 4 1 25 06 1999 2 7 2020 2 7 2021Vo Van Tam,1922215448,vovantam@gmail.com,Hai Lang Quang Tri
    printf("%-10s %-30s %-10s %-10s %s\n", "Ma", "Ho ten", "Ngay sinh", "Gioi tinh", "Ngay lap the");

    while (point != NULL)
    {
        DocGia dg = point->data;
        inThongTinDocGia(dg);

        point = point->next;
    }
}

//2.2 them doc gia
DocGia themdocgia()
{
    DocGia d;
    cout << "nhap ten doc gia : ";
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

void chucNangThemDocGia()
{
    DocGia docgia = themdocgia();
    themDocGiaVaoDauNode(docgia);
}

//2.3 sua thong tin doc gia
void suathongtindocgia(DocGia &d)
{
    cout << "nhap ten doc gia : ";
    getline(cin, d.hoten);
    cout << "nhap chung minh nhan dan  : ";
    getline(cin, d.cmnd);
    cout << "nhap ngay sinh  : ";
    cin >> d.ngaysinh.ngay;
    cout << "nhap thang sinh  : ";
    cin >> d.ngaysinh.thang;
    cout << "nhap nam sinh  : ";
    cin >> d.ngaysinh.nam;
    cout << "nhap gioi tinh  : ";
    cin >> d.gioitinh;
    cin.ignore();
    cout << "nhap email  : ";
    getline(cin, d.email);
    cout << "nhap dia chi  : ";
    getline(cin, d.diachi);
    cout << "nhap ngay lap the : ";
    cin >> d.ngaylapthe.ngay;
    cout << "nhap thang lap the : ";
    cin >> d.ngaylapthe.thang;
    cout << "nhap nam lap the  : ";
    cin >> d.ngaylapthe.nam;
    cout << "nhap ngay het han : ";
    cin >> d.ngayhethan.ngay;
    cout << "nhap thang het han : ";
    cin >> d.ngayhethan.thang;
    cout << "nhap nam het han : ";
    cin >> d.ngayhethan.ngay;
}

// 2.3 Sua thong thong tin doc gia
DocGia *timDocGiaTheoMa(int ma);
void chucNangSuaThongTinCuaMotDocGia()
{
    inDanhSachDocGia();
    cout<<"Nhap ma doc gia can sua: ";
    int ma;
    cin>>ma;
    cin.ignore();
    DocGia *dg = timDocGiaTheoMa(ma);
    if (dg == NULL)
    {
        cout<<"Ma khong hop le!\n";
    }
    else
    {
        suathongtindocgia(*dg);
        cout<<"Sua thanh cong!\n";
    }
}

// 2.4 Xoa thong tin mot doc gia
bool xoaDocGiaTheoId(int id)
{
    NodeDocGia *point = headDocGia;

    if (point == NULL)
    {
        return false;
    }

    if (point->data.ma == id)
    {
        headDocGia = headDocGia->next;
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
        point = point->next;
    }

    return false;
}

// 2.4 Xoa thong tin doc gia
void xoaThongTinDocGia()
{
    inDanhSachDocGia();
    cout<<"Nhap ma doc gia can xoa: ";
    int ma;
    cin>>ma;
    bool ketqua = xoaDocGiaTheoId(ma);
    if (ketqua)
    {
        cout<<"Da xoa doc gia thanh cong!\n";
    }
    else
    {
        cout<<"Ma khong hop le\n";
    }
}

// 2.5 Tim kiem doc gia theo CMND
DocGia *timDocGiaTheoChungMinhNhanDan(string cmnd)
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

// 2.5 Tim doc gia theo chung minh
void chucNangTimDocGiaTheoCMND()
{
    inDanhSachDocGia();
    string cmnd;
    cout<<"Nhap CMND can tim: ";
    getline(cin, cmnd);
    DocGia *dg = timDocGiaTheoChungMinhNhanDan(cmnd);
    if (dg == NULL)
    {
        cout<<"Khong tim thay!\n";
    }
    else
    {
        inDocGia(*dg);
    }
    
}

// 2.6 Tim kiem doc gia theo ho ten
DocGia *timDocGiaTheoHoTen(string ten)
{
    NodeDocGia *point = headDocGia;
    while (point != NULL)
    {
        if (point->data.hoten == ten)
        {
            return &point->data;
        }

        point = point->next;
    }

    return NULL;
}

// 2.6 Tim kiem doc gia theo ho ten
void chucNangTimDocGiaTheoHoTen()
{
    inDanhSachDocGia();
    string hoten;
    cout<<"Nhap ho ten can tim: ";
    getline(cin, hoten);
    DocGia *dg = timDocGiaTheoHoTen(hoten);
    if (dg == NULL)
    {
        cout<<"Khong tim thay!\n";
    }
    else
    {
        inDocGia(*dg);
    }
    
}

// 3.1 Xem danh sach cac sach trong thu vien
void xemSachTrongThuVien()
{
    NodeSach *point = headSach;
    //1 1997 200000 205De meo phieu luu ki 3,Ngo Bao Trung,Nha xuat ban puong duong,Sach toan
    printf("%-10s %-30s %-20s %-20s %-10s\n", "Ma sach", "Ten sach", "Tac gia", "Nam xuat ban", "So luong");
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
    cout << "nhap the loai :  ";
    getline(cin, s.theloai);
    cout << "nhap don gia  : ";
    cin >> s.giasach;
    cout << "nhap nam xuat ban  :  ";
    cin >> s.namxuatban;
    cout << "nhap so luong : ";
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

void chucNangThemSach()
{
    Sach sach = themsach();
    themSachVaoDauNode(sach);
}

//3.3 chinh sua thong tin sach
void chinhsuathongtinsach(Sach &s)
{
    cout << "Nhap lai thong tin sach: " << endl;
    cout << "nhap ma sach: ";
    cin >> s.masach;
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

Sach *timSachTheoMa(int ma)
{
    NodeSach *point = headSach;
    while (point != NULL)
    {
        if (point->data.masach == ma)
        {
            return &point->data;
        }

        point = point->next;
    }

    return NULL;
}

void chucNangChinhSuaThongTinSach()
{
    xemSachTrongThuVien();
    cout<<"Nhap ma sach can sua: ";
    int ma;
    cin>>ma;
    cin.ignore();

    Sach *sach = timSachTheoMa(ma);
    if (sach == NULL)
    {
        cout<<"Ma khong hop le!\n";
    }
    else
    {
        chinhsuathongtinsach(*sach);
    }
}

// 3.5 Tìm kiếm sách theo ISBN
void chucNangTimKiemSachTheoMa()
{
    int ma;
    cout<<"Nhap ma sach can tim: ";
    cin>>ma;
    
    Sach *sach = timSachTheoMa(ma);
    if (sach == NULL)
    {
        cout<<"Ma sach khong tion tai\n";
    }
    else
    {
        printf("%-10d %-30s %-20s %-20d %-10d\n",
               sach->masach,
               sach->tensach.c_str(),
               sach->tacgia.c_str(),
               sach->namxuatban,
               sach->soluong);
    }
    
}

//3.4 Xóa thông tin sách
void xoaThongTinSach()
{
    xemSachTrongThuVien();
    int ma;
    cout << "Nhap ma sach: ";
    cin >> ma;

    Sach *sach = timSachTheoMa(ma);
    if (sach == NULL)
    {
        cout << "Ma khong ton tai!\n";
        return;
    }

    if (headSach != NULL && headSach->data.masach == ma)
    {
        headSach = headSach->next;
        return;
    }

    NodeSach *point = headSach;
    while (point != NULL)
    {
        if (point->next->data.masach == ma)
        {
            NodeSach *next = point->next->next;
            point->next = next;
            break;
        }
    }

    cout << "Da xoa sach thanh cong!\n";
}

//3.6 Tìm kiếm sách theo tên sách
Sach *timSachTheoTen(string ten)
{
    NodeSach *point = headSach;
    while (point != NULL)
    {
        if (point->data.tensach == ten)
        {
            return &point->data;
        }

        point = point->next;
    }

    return NULL;
}

// 3.6 Tìm kiếm sách theo tên sách
void chucNangTimKiemSachTheoTen()
{
    int ma;
    cout<<"Nhap ma sach can tim: ";
    cin>>ma;
    
    Sach *sach = timSachTheoMa(ma);
    if (sach == NULL)
    {
        cout<<"Ma sach khong tion tai\n";
    }
    else
    {
        printf("%-10d %-30s %-20s %-20d %-10d\n",
               sach->masach,
               sach->tensach.c_str(),
               sach->tacgia.c_str(),
               sach->namxuatban,
               sach->soluong);
    }
    
}

bool muonSach(int masach);
bool kiemTraDocGia(int ma)
{
    NodeDocGia *point = headDocGia;
    while (point != NULL)
    {
        if (point->data.ma == ma)
        {
            return true;
        }
        point = point->next;
    }
    return false;
}

// 4 Lap phieu muon sach
void lapPhieuMuonSach()
{
    /*
    Mỗi phiếu mượn/trả sách chứa thông tin về mã độc giả, ngày mượn, ngày trả dự kiến,
    ngày trả thực tế và danh sách ISBN của các sách được mượn.
    */

    inDanhSachDocGia();
    MuonTra muon;
    cout << "Nhap ma doc gia: ";
    cin >> muon.madocgia;

    if (!kiemTraDocGia(muon.madocgia))
    {
        cout << "Ma doc gia khong hop le!" << endl;
        return;
    }

    for (int i = 0; i < 3;)
    {
        xemSachTrongThuVien();
        cout << "Nhap ma sach thu " << i + 1 << " (Nhap 0 de ket thuc): ";
        int masach;
        cin >> masach;

        if (masach == 0)
        {
            break;
        }

        if (muonSach(masach))
        {
            muon.masach[i] = masach;
            i++;
        }
        else
        {
            cout << "Sach da het hoac khong ton tai!" << endl;
        }
    }

    cout << "Nhap ngay muon (dd mm yyyy): ";
    cin >> muon.ngaymuon.ngay >> muon.ngaymuon.thang >> muon.ngaymuon.nam;
    cout << "Ngay tra du kiem (dd mm yyyy): ";
    cin >> muon.ngaytradukien.ngay >> muon.ngaytradukien.thang >> muon.ngaytradukien.nam;

    themPhieuMuonTraVaoDauNode(muon);
}

DocGia *timDocGiaTheoMa(int ma)
{
    NodeDocGia *point = headDocGia;
    while (point != NULL)
    {
        if (point->data.ma == ma)
        {
            return &point->data;
        }

        point = point->next;
    }

    return NULL;
}

void inDanhSachPhieuMuonChuaTra()
{
    NodeMuonTra *point = headMuonTra;
    printf("%-10s %-10s %-30s %s\n", "Ma phieu", "Ma doc gia", "Ten doc gia", "Ngay muon");

    while (point != NULL)
    {
        MuonTra muontra = point->data;
        DocGia *dg = timDocGiaTheoMa(muontra.madocgia);
        string ten = "";
        if (dg != NULL)
        {
            ten = dg->hoten;
        }

        point = point->next;

        if (muontra.ngaytrathucte.ngay != 0 && muontra.ngaytrathucte.thang != 0 && muontra.ngaytrathucte.nam != 0)
        {
            continue;
        }

        printf(
            "%-10d %-10d %-30s %02d/%02d/%02d\n",
            muontra.ma,
            muontra.madocgia,
            ten.c_str(),
            muontra.ngaymuon.ngay, muontra.ngaymuon.thang, muontra.ngaymuon.nam);
    }
}

MuonTra *timPhieuMuonTraTheoMa(int ma)
{
    NodeMuonTra *point = headMuonTra;
    while (point != NULL)
    {
        if (point->data.ma == ma)
        {
            return &point->data;
        }

        point = point->next;
    }

    return NULL;
}

// 5.0 Lap phieu tra sach
void lapPhieuTraSach()
{
    inDanhSachPhieuMuonChuaTra();
    int ma;
    cout << "Nhap ma phieu muon: ";
    cin >> ma;

    MuonTra *muontra = timPhieuMuonTraTheoMa(ma);
    if (muontra == NULL)
    {
        cout << "Ban nhap ma khong dung!" << endl;
        return;
    }

    cout << "Nhap ngay tra (dd mm yyyy): ";
    cin >> muontra->ngaytrathucte.ngay >> muontra->ngaytrathucte.thang >> muontra->ngaytrathucte.nam;
}

// Kiem tra xem ma sach co hop le hoac so luong sach van con
bool muonSach(int masach)
{
    Sach *sach = timSachTheoMa(masach);
    if (sach == NULL)
    {
        return false;
    }

    if (sach->soluong <= 0)
    {
        return false;
    }

    sach->soluong--;

    return true;
}

void initData()
{
    docSachTuFile();
    docDocGiaTuFile();
    docNhanVienTuFile();
    docPhieuMuonTraTuFile();
}

void thoatChuongTrinh()
{
    inSachRaFile();
    inDocGiaRaFile();
    inNhanVienRaFile();
    inPhieuMuonTraRaFile();
    exit(0);
}

//6.1  thong ke so luong sach trong thu vien
int soluongsach()
{
    NodeSach *point = headSach;
    int coutd = 0;
    while (point != NULL)
    {
        coutd++;
        point = point->next;
    }
    return coutd;
}

void chucNangThongKeSoLuongSach()
{
    int soluong = soluongsach();
    cout<<"So luong loai sach trong thu vien: "<<soluong<<endl;
}

//6.2 Thong ke so luong sach theo the loai
void chucNangThongKeSoLuongSachTheoTheLoai()
{
    const int MAX = soluongsach();
    int value[MAX] = {0};
    string key[MAX] = {""};
    
    NodeSach *point = headSach;
    while (point != NULL)
    {
        Sach sach = point->data;
        
        int so = sach.soluong;
        string loai = sach.theloai;

        for (int i = 0; i < MAX; i++)
        {
            if (key[i] == loai)
            {
                value[i] += so;
                break;
            }

            if (key[i] == "")
            {
                key[i] = loai;
                value[i] += so;
                break;   
            }
        }
        
        point = point->next;
    }
    
    printf("%-20s %s\n", "Loai sach", "So luong");
    for (int i = 0; i < MAX; i++)
    {
        if (key[i] == "")
        {
            break;
        }
        
        printf("%-20s %d\n", key[i].c_str(), value[i]);
    }
    
}

//6.3 THong ke so luong doc gia
int soluongdocgia()
{
    NodeDocGia *point = headDocGia;
    int coutd = 0;
    while (point != NULL)
    {
        coutd++;
        point = point->next;
    }
    return coutd;
}

void chucNangThongkeSoLuongDocGia()
{
    int soluong = soluongdocgia();
    cout<<"So luong doc gia la: "<<soluong<<endl;
}

//6.4 Thong ke so luong doc gia theo gioi tinh nam ;
int thongkesoluongdocgianam()
{
    int coutd = 0;
    NodeDocGia *point = headDocGia;
    while (point != NULL)
    {
        if (point->data.gioitinh == 1)
        {
            coutd++;
        }

        point = point->next;
    }
    return coutd;
}

int thongkesoluongdocgianu()
{
    int coutd = soluongdocgia() - thongkesoluongdocgianam();

    return coutd;
}

void chucNangThongKeSoLuongDocGiaTheoGioiTinh()
{
    cout<<"So luong doc gia nam: "<<thongkesoluongdocgianam()<<endl;
    cout<<"So luong doc gia nu: "<<thongkesoluongdocgianu()<<endl;
}

// Lay so ngay cua thang
int laySoNgayCuaThang(int thang, int nam)
{
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;

    case 2:
        if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
        {
            return 29;
        }
        return 28;

    default:
        return -1;
    }
}

// Kiem tra doc gia co bi tre han
bool kiemTraTreHan(MuonTra phieumuon)
{
    Ngay ngaymuon = phieumuon.ngaymuon;
    Ngay ngaytra = phieumuon.ngaytrathucte;

    if (ngaytra.ngay == 0 && ngaytra.thang == 0 && ngaytra.nam == 0)
    {
        return false;
    }

    if (ngaytra.nam == ngaymuon.nam)
    {
        if (ngaytra.thang == ngaymuon.thang)
        {
            return (ngaytra.ngay - 7 > ngaymuon.ngay);
        }

        return (laySoNgayCuaThang(ngaymuon.thang, ngaymuon.nam) + ngaytra.ngay - 7 > ngaymuon.ngay);
    }

    return (laySoNgayCuaThang(ngaymuon.thang, ngaymuon.nam) + ngaytra.ngay - 7 > ngaymuon.ngay);
}

// 6.5 Thong ke so sach dang muon
void chucNangThongKeSoSachDangMuon()
{
    int soluong = 0;
    NodeMuonTra *point = headMuonTra;
    while (point != NULL)
    {
        if (point->data.ngaytrathucte.ngay == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                if (point->data.masach[i] != 0)
                {
                    soluong++;
                }
            }
        }

        point = point->next;
    }

    cout << "Tong so sach dang duoc muon la: " << soluong << endl;
}

// 6.6 Thong ke doc gia bi tre han
void chucNangThongKeDocGiaBiTreHan()
{
    NodeMuonTra *point = headMuonTra;
    printf("%-10s %-10s %-30s %s\n", "Ma phieu", "Ma doc gia", "Ten doc gia", "Ngay muon");

    while (point != NULL)
    {
        if (kiemTraTreHan(point->data))
        {
            MuonTra muontra = point->data;
            string ten = "";
            DocGia *dg = timDocGiaTheoMa(point->data.madocgia);
            if (dg != NULL)
            {
                ten = dg->hoten;
            }

            printf(
                "%-10d %-10d %-30s %02d/%02d/%02d\n",
                muontra.ma,
                muontra.madocgia,
                ten.c_str(),
                muontra.ngaymuon.ngay, muontra.ngaymuon.thang, muontra.ngaymuon.nam);
        }

        point = point->next;
    }
}

void menuAdmin()
{
    while (true)
    {
        xoaManHinh();
        cout << " 0.Thoat chuong trinh"<<endl;
        cout << "12.Dang xuat: " << endl;
        cout << "13.Thay doi mat khau : " << endl;
        cout << "14.Cap nhat thong tin ca nhan: " << endl;
        cout << "15.Tao nguoi dung" << endl;
    
        cout << "21.Xem danh sach doc gia : " << endl;
        cout << "22.Them doc gia: " << endl;
        cout << "23.Cap nhat thong tin doc gia : " << endl;
        cout << "24:Xoa doc gia:" << endl;
        cout << "25.Tim kiem theo CMND: " << endl;
        cout << "26.Tim kiem theo ho ten : " << endl;

        cout << "31.Xem danh sach cac sach trong thu vien  : " << endl;
        cout << "32.Them sach : " << endl;
        cout << "33.Cap nhat thong tin quyen sach : " << endl;
        cout << "34:Xoa quyen sach :" << endl;
        cout << "35.Tim kiem theo ISBN : " << endl;
        cout << "36.Tim kiem theo ten sach : " << endl;

        cout << "40.Lap phieu muon sach" << endl;
        cout << "50.Lap phieu tra sach" << endl;

        cout << "61.Thong ke cac sach co trong thu vien : " << endl;
        cout << "62.Thong ke so luong sach theo loai : " << endl;
        cout << "63.Thong ke so luong doc gia : " << endl;
        cout << "64:Thong ke so luong doc gia theo gioi tinh  :" << endl;
        cout << "65.Thong ke sach dang muon: " << endl;
        cout << "66.thong ke doc gia dang bi tre hen : " << endl;
        cout << "Moi chon chuc nang: " << endl;

        int chon;
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 0:
            thoatChuongTrinh();
        case 12:
            dangXuat();
            return;

        case 13:
            thaydoimatkhau(*nhanVien);
            break;

        case 14:
            capnhatnhanvien(*nhanVien);
            break;

        case 15:
            chucNangThemNhanVien();
            break;

        case 21:
            inDanhSachDocGia();
            break;

        case 22:
            chucNangThemDocGia();
            break;

        case 23:
            chucNangSuaThongTinCuaMotDocGia();
            break;

        case 24:
            xoaThongTinDocGia();
            break;

        case 25:
            chucNangTimDocGiaTheoCMND();
            break;

        case 26:
            chucNangTimDocGiaTheoHoTen();
            break;

        case 31:
            xemSachTrongThuVien();
            break;

        case 32:
            chucNangThemSach();
            break;

        case 33:
            chucNangChinhSuaThongTinSach();
            break;

        case 34:
            xoaThongTinSach();
            break;

        case 35:
            chucNangTimKiemSachTheoMa();
            break;
        case 36:
            chucNangTimKiemSachTheoTen();
            break;

        case 40:
            lapPhieuMuonSach();
            break;

        case 50:
            lapPhieuTraSach();
            break;
        case 61:
            xemSachTrongThuVien();
            break;

        case 62:
            chucNangThongKeSoLuongSachTheoTheLoai();
            break;

        case 63:
            chucNangThongkeSoLuongDocGia();
            break;

        case 64:
            chucNangThongKeSoLuongDocGiaTheoGioiTinh();
            break;

        case 65:
            chucNangThongKeSoSachDangMuon();
            break;

        case 66:
            chucNangThongKeDocGiaBiTreHan();
            break;

        default:
            cout << "Ban nhap khong hop le!\n";
        }

        cin.clear();
        cin.ignore(INT32_MAX, '\n');
    }
}

void menuQuanly()
{
    while (true)
    {
        xoaManHinh();
        cout << "12.Dang xuat: " << endl;
        cout << "13.Thay doi mat khau : " << endl;
        cout << "14.Cap nhat thong tin ca nhan: " << endl;

        cout << "21.Xem danh sach doc gia : " << endl;
        cout << "22.Them doc gia: " << endl;
        cout << "23.Cap nhat thong tin doc gia : " << endl;
        cout << "24:Xoa doc gia:" << endl;
        cout << "25.Tim kiem theo CMND: " << endl;
        cout << "26.Tim kiem theo ho ten : " << endl;

        cout << "31.Xem danh sach cac sach trong thu vien  : " << endl;
        cout << "32.Them sach : " << endl;
        cout << "33.Cap nhat thong tin quyen sach : " << endl;
        cout << "34:Xoa quyen sach :" << endl;
        cout << "35.Tim kiem theo ISBN : " << endl;
        cout << "36.Tim kiem theo ten sach : " << endl;

        cout << "40.Lap phieu muon sach" << endl;
        cout << "50.Lap phieu tra sach" << endl;

        cout << "61.Thong ke cac sach co trong thu vien : " << endl;
        cout << "62.Thong ke so luong sach theo loai : " << endl;
        cout << "63.Thong ke so luong doc gia : " << endl;
        cout << "64:Thong ke so luong doc gia theo gioi tinh  :" << endl;
        cout << "65.Thong ke sach dang muon: " << endl;
        cout << "66.Thong ke doc gia dang bi tre hen : " << endl;
        cout << "Moi chon chuc nang: " << endl;

        int chon;
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 0:
            thoatChuongTrinh();
        case 12:
            dangXuat();
            return;

        case 13:
            thaydoimatkhau(*nhanVien);
            break;

        case 14:
            capnhatnhanvien(*nhanVien);
            break;

        case 21:
            inDanhSachDocGia();
            break;

        case 22:
            chucNangThemDocGia();
            break;

        case 23:
            chucNangSuaThongTinCuaMotDocGia();
            break;

        case 24:
            xoaThongTinDocGia();
            break;

        case 25:
            chucNangTimDocGiaTheoCMND();
            break;

        case 26:
            chucNangTimDocGiaTheoHoTen();
            break;

        case 31:
            xemSachTrongThuVien();
            break;

        case 32:
            chucNangThemSach();
            break;

        case 33:
            chucNangChinhSuaThongTinSach();
            break;

        case 34:
            xoaThongTinSach();
            break;

        case 35:
            chucNangTimKiemSachTheoMa();
            break;
        case 36:
            chucNangTimKiemSachTheoTen();
            break;

        case 40:
            lapPhieuMuonSach();
            break;

        case 50:
            lapPhieuTraSach();
            break;
        case 61:
            xemSachTrongThuVien();
            break;

        case 62:
            chucNangThongKeSoLuongSachTheoTheLoai();
            break;

        case 63:
            chucNangThongkeSoLuongDocGia();
            break;

        case 64:
            chucNangThongKeSoLuongDocGiaTheoGioiTinh();
            break;

        case 65:
            chucNangThongKeSoSachDangMuon();
            break;

        case 66:
            chucNangThongKeDocGiaBiTreHan();
            break;
            
        default:
            cout << "Ban nhap khong hop le!\n";
        }

        cin.clear();
        cin.ignore(INT32_MAX, '\n');
    }
}

void menuChuyenvien()
{
    while (true)
    {
        xoaManHinh();
        cout << "12.Dang xuat: " << endl;
        cout << "13.Thay doi mat khau : " << endl;
        cout << "14.Cap nhat thong tin ca nhan: " << endl;

        cout << "21.Xem danh sach doc gia : " << endl;
        cout << "22.Them doc gia: " << endl;
        cout << "23.Cap nhat thong tin doc gia : " << endl;
        cout << "25.Tim kiem theo CMND: " << endl;
        cout << "26.Tim kiem theo ho ten : " << endl;

        cout << "35.Tim kiem theo ISBN : " << endl;
        cout << "36.Tim kiem theo ten sach : " << endl;

        cout << "40.Lap phieu muon sach" << endl;
        cout << "50.Lap phieu tra sach" << endl;
        cout << "Moi chon chuc nang: " << endl;

        int chon;
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 0:
            thoatChuongTrinh();
        case 12:
            dangXuat();
            return;

        case 13:
            thaydoimatkhau(*nhanVien);
            break;

        case 14:
            capnhatnhanvien(*nhanVien);
            break;

        case 21:
            inDanhSachDocGia();
            break;

        case 22:
            chucNangThemDocGia();
            break;

        case 23:
            chucNangSuaThongTinCuaMotDocGia();
            break;

        case 24:
            xoaThongTinDocGia();
            break;

        case 25:
            chucNangTimDocGiaTheoCMND();
            break;

        case 26:
            chucNangTimDocGiaTheoHoTen();
            break;

        case 35:
            chucNangTimKiemSachTheoMa();
            break;
        case 36:
            chucNangTimKiemSachTheoTen();
            break;

        case 40:
            lapPhieuMuonSach();
            break;

        case 50:
            lapPhieuTraSach();
            break;
            
        default:
            cout << "Ban nhap khong hop le!\n";
        }

        cin.clear();
        cin.ignore(INT32_MAX, '\n');
    }
}

// Ket thuc cac chuc nang
/*-------------------------------------------------------*/

/*-------------------------------------------------------*/
// Ham main

int main()
{
    initData();
    while (true)
    {
        string tendangnhap;
        string matkhau;
        cout << "Nhap ten dang nhap: ";
        getline(cin, tendangnhap);
        cout << "Nhap mat khau: ";
        getline(cin, matkhau);

        if (dangNhap(tendangnhap, matkhau) == 0)
        {
            cout << "Ten dang nhap hoac mat khau khong dung!\n";
            continue;
        }

        switch (nhanVien->loainguoidung)
        {
        case ROLE_ADMIN:
            menuAdmin();
            break;

        case ROLE_QUANLY:
            menuQuanly();
            break;

        case ROLE_CHUYENVIEN:
            menuQuanly();
            break;
        }
    }
}
/*-------------------------------------------------------*/
