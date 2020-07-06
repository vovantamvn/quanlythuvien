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
NodeNhanVien  *headNhanVien = NULL;
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
// oke
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
//oke
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
//oke
void xoaManHinh()
{
    system("clear");
    //system("cls");
}
//oke
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

//oke
void docDocGiaTuFile()
{
    //4 1 25 06 1999 2 7 2020 2 7 2021Vo Van Tam,1922215448,vovantam@gmail.com,Hai Lang Quang Tri
    //ma,gioitinh,ngaysinh,ngaylapthe,ngayhethan,hoten,cmnd,email,diachi
    ifstream file("docgia.txt");
    while (!file.eof())
    {
       DocGia docgia;
       file>>docgia.ma;
       file>>docgia.gioitinh;
       file>>docgia.ngaysinh.ngay;
       file>>docgia.ngaysinh.thang;
       file>>docgia.ngaysinh.nam;
       file>>docgia.ngaylapthe.ngay;
       file>>docgia.ngaylapthe.thang;
       file>>docgia.ngaylapthe.nam;
       file>>docgia.ngayhethan.ngay;
       file>>docgia.ngayhethan.thang;
       file>>docgia.ngayhethan.nam;
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
//oke
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

//oke
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

//oke
void docPhieuMuonTraTuFile()
{
    //2 1 1 2 0 25 6 2020 25 7 2020 28 6 2020
    ifstream file("muontra.txt");
    while (!file.eof())
    {
        MuonTra muontra;
        file>>muontra.ma;
        file>>muontra.madocgia;
        file>>muontra.masach[0];
        file>>muontra.masach[1];
        file>>muontra.masach[2];
        file>>muontra.ngaymuon.ngay;
        file>>muontra.ngaymuon.thang;
        file>>muontra.ngaymuon.nam;
        file>>muontra.ngaytradukien.ngay;
        file>>muontra.ngaytradukien.thang;
        file>>muontra.ngaytradukien.nam;
        file>>muontra.ngaytrathucte.ngay;
        file>>muontra.ngaytrathucte.thang;
        file>>muontra.ngaytrathucte.nam;

        themPhieuMuonTraVaoDauNode(muontra);
    }
    file.close();
}

// in sach ra file
//oke
void inSachRaFile()
{
    ofstream file("sach.txt");

    NodeSach *point = headSach;
    while (point != NULL)
    {
        Sach sach = point->data;
        file<<sach.masach<<" ";
        file<<sach.namxuatban<<" ";
        file<<sach.giasach<<" ";
        file<<sach.soluong;
        file<<sach.tensach<<',';
        file<<sach.tacgia<<',';
        file<<sach.nhasanxuat<<',';
        file<<sach.theloai;   

        point = point->next;
        if (point != NULL)
        {
            file<<endl;
        }
        
    }
    file.close();
}

// in doc gia ra file
//oke
void inDocGiaRaFile()
{
    ofstream file("docgia.txt");

    NodeDocGia *point = headDocGia;
    while (point != NULL)
    {
        DocGia docgia = point->data;
        file<<docgia.ma<<" ";
        file<<docgia.gioitinh<<" ";
        file<<docgia.ngaysinh.ngay<<" ";
        file<<docgia.ngaysinh.thang<<" ";
        file<<docgia.ngaysinh.nam<<" ";
        file<<docgia.ngaylapthe.ngay<<" ";
        file<<docgia.ngaylapthe.thang<<" ";
        file<<docgia.ngaylapthe.nam<<" ";
        file<<docgia.ngayhethan.ngay<<" ";
        file<<docgia.ngayhethan.thang<<" ";
        file<<docgia.ngayhethan.nam;
        file<<docgia.hoten<<',';
        file<<docgia.cmnd<<',';
        file<<docgia.email<<',';
        file<<docgia.diachi;

        point = point->next;
        if (point != NULL)
        {
            file<<endl;
        }
    }
    file.close();
}

// in nhan vien ra file
//oke
void inNhanVienRaFile()
{
    ofstream file("nhanvien.txt");
    
    NodeNhanVien *point = headNhanVien;
    while (point != NULL)
    {
        NhanVien nv = point->data;
        file<<nv.id<<" ";
        file<<nv.loainguoidung<<" ";
        file<<nv.trangthai<<" ";
        file<<nv.gioitinh<<" ";
        file<<nv.ngaysinh.ngay<<" ";
        file<<nv.ngaysinh.thang<<" ";
        file<<nv.ngaysinh.nam;
        file<<nv.tendangnhap<<',';
        file<<nv.matkhau<<',';
        file<<nv.hoten<<',';
        file<<nv.cmnd<<',';
        file<<nv.diachi;

        point = point->next;
        if (point != NULL)
        {
            file<<endl;
        }
    }
    
    file.close();
}

// in phieu muon tra ra file
//oke
void inPhieuMuonTraRaFile()
{
    ofstream file("muontra.txt");

    NodeMuonTra *point = headMuonTra;
    while (point != NULL)
    {
        MuonTra muontra = point->data;

        file<<muontra.ma<<" ";
        file<<muontra.madocgia<<" ";
        file<<muontra.masach[0]<<" ";
        file<<muontra.masach[1]<<" ";
        file<<muontra.masach[2]<<" ";
        file<<muontra.ngaymuon.ngay<<" ";
        file<<muontra.ngaymuon.thang<<" ";
        file<<muontra.ngaymuon.nam<<" ";
        file<<muontra.ngaytradukien.ngay<<" ";
        file<<muontra.ngaytradukien.thang<<" ";
        file<<muontra.ngaytradukien.nam<<" ";
        file<<muontra.ngaytrathucte.ngay<<" ";
        file<<muontra.ngaytrathucte.thang<<" ";
        file<<muontra.ngaytrathucte.nam;

        point = point->next;
        if (point != NULL)
        {
            file<<endl;
        }
    }
    

    file.close();
}
/*-------------------------------------------------------*/

/*-------------------------------------------------------*/
// Chuc nang cua chuong trinh
// 1.1 dang nhap
//oke
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
//oke
void dangXuat()
{
    nhanVien = NULL;
}

//1.3 thay doi mat khau;
//oke
//update
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
//oke
//update
void capnhatnhanvien(NhanVien &nv)
{
    cout << "Nhap lai thong tin nhan vien : ";
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

    xoaBoNhoDem();
}

//1.5 tao nguoi dung
//update
NhanVien taonhanvien()
{
    NhanVien nv;
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

    xoaBoNhoDem();
    return nv;
}

void inThongTinDocGia(DocGia dg)
{
    printf(
        "%-10d %-30s %02d/%02d/%02d %-10s %02d/%02d/%02d\n",
        dg.ma,
        dg.hoten.c_str(),
        dg.ngaysinh.ngay, dg.ngaysinh.thang, dg.ngaysinh.nam,
        (dg.gioitinh == 1)? "Nam" : "Nu",
        dg.ngaylapthe.ngay, dg.ngaylapthe.thang, dg.ngaylapthe.nam);
}
// in thong tin ngay
//oke
void inThongTinNgay(string thongtin, Ngay ngay)
{
    cout << thongtin << ": " << ngay.ngay << "/" << ngay.thang << "/" << ngay.nam << endl;
}

// Xem thong tin doc gia
//oke
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
//oke
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
//oke
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

    xoaBoNhoDem();
    return d;
}

//2.3 sua thong tin doc gia
//oke
void suathongtindocgia(DocGia &d)
{
    cout << "Nhap lai thong tin doc gia  : ";
    cout << "nhap ten doc gia : ";
    getline(cin, d.hoten);
    cout << "nhap chung minh nhan dan  : ";
    getline(cin, d.cmnd);
    cout << "nhap ngay sinh  :  ";
    cin >> d.ngaysinh.ngay;
    cout << "nhap thang sinh  :  ";
    cin >> d.ngaysinh.thang;
    cout << "nhap nam sinh  :  ";
    cin >> d.ngaysinh.nam;
    cout << "nhap gioi tinh  : ";
    cin >> d.gioitinh;
    cin.ignore();
    cout << "nhap email  : ";
    getline(cin, d.email);
    cout << "nhap dia chi  :  ";
    getline(cin, d.diachi);
    cout << "nhap ngay lap the  :  ";
    cin >> d.ngaylapthe.ngay;
    cout << "nhap thang lap the  :  ";
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
bool xoaDocGiaTheoId(int id) 
{
    NodeDocGia *point = headDocGia;
    NodeDocGia *head = headDocGia;

    if (point == NULL)
    {
        return false;
    }

    if (point->data.ma == id)
    {
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

// 3.1 Xem danh sach cac sach trong thu vien
// Oke
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

//3.3 chinh sua thong tin sach
//oke
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

//3.5 Tìm kiếm sách theo ISBN
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

//3.4 Xóa thông tin sách
void xoaThongTinSach()
{
    xemSachTrongThuVien();
    int ma;
    cout<<"Nhap ma sach: ";
    cin>>ma;

    Sach *sach = timSachTheoMa(ma);
    if (sach == NULL)
    {
        cout<<"Ma khong ton tai!\n";
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
    
    cout<<"Da xoa sach thanh cong!\n";
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
    cout<<"Nhap ma doc gia: ";
    cin>>muon.madocgia;

    if (!kiemTraDocGia(muon.madocgia))
    {
        cout<<"Ma doc gia khong hop le!"<<endl;
        return;
    }
    
    for(int i=0; i<3;)
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

    
    cout<<"Nhap ngay muon (dd mm yyyy): ";
    cin>>muon.ngaymuon.ngay>>muon.ngaymuon.thang>>muon.ngaymuon.nam;
    cout<<"Ngay tra du kiem (dd mm yyyy): ";
    cin>>muon.ngaytradukien.ngay>>muon.ngaytradukien.thang>>muon.ngaytradukien.nam;

    themPhieuMuonTraVaoDauNode(muon);
}

DocGia* timDocGiaTheoMa(int ma)
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

MuonTra* timPhieuMuonTraTheoMa(int ma)
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
    cout<<"Nhap ma phieu muon: ";
    cin>>ma;

    MuonTra* muontra = timPhieuMuonTraTheoMa(ma);
    if (muontra == NULL)
    {
        cout<<"Ban nhap ma khong dung!"<<endl;
        return;
    }
    
    cout<<"Nhap ngay tra (dd mm yyyy): ";
    cin>>muontra->ngaytrathucte.ngay>>muontra->ngaytrathucte.thang>>muontra->ngaytrathucte.nam;

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

//6.2 Thong ke so luong sach theo the loai


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

void menuQuanly()
{
    
}
/*
void menuAdmin()
{
    while (true)
    {
        xoaManHinh();
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
        switch (chon)
        {
            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            case 1:
                break;

            default:
                cout<<"Ban nhap khong hop le!\n";
        }
    }
}
*/
void menuChuyenvien()
{
    
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
        cout<<"Nhap ten dang nhap: ";
        getline(cin, tendangnhap);
        cout<<"Nhap mat khau: ";
        getline(cin, matkhau);

        if (dangNhap(tendangnhap, matkhau) == 0)
        {
            cout<<"Ten dang nhap hoac mat khau khong dung!\n";
            continue;
        }
        
        switch (nhanVien->loainguoidung)
        {
        case ROLE_ADMIN:
            cout<<"admin";
            break;

        case ROLE_QUANLY:
            cout<<"quan ly";
            break;

        case ROLE_CHUYENVIEN:
            cout<<"chuyen vien";
            break;
        }
    }
}
/*-------------------------------------------------------*/
