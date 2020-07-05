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
NodeNhanVien  *headNhanVien = NULL;
NhanVien *nhanVien = NULL;
// Doc gia
NodeDocGia *headDocGia = NULL;
NodeSach *headSach = NULL;
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
    file.close();
}

void docDocGiaTuFile()
{

}

void xoaBoNhoDem()
{
    cout<<"Enter de tiep tuc!"<<endl;
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
        file>>nv.id;
        file>>nv.loainguoidung;
        file>>nv.trangthai;
        file>>nv.gioitinh;
        file>>nv.ngaysinh.ngay;
        file>>nv.ngaysinh.thang;
        file>>nv.ngaysinh.nam;
        getline(file, nv.tendangnhap, ',');
        getline(file, nv.matkhau, ',');
        getline(file, nv.hoten, ',');
        getline(file, nv.cmnd, ',');
        getline(file, nv.diachi);

        themNhanVienVaoDauNode(nv);
    }
    file.close();
}
/*-------------------------------------------------------*/


/*-------------------------------------------------------*/
// Chuc nang cua chuong trinh
// 1.1 dang nhap
//oke
bool dangNhap(string tendangnhap, string matkhau) {
    NodeNhanVien *point = headNhanVien;
    while (point != NULL)
    {
        if (tendangnhap == point->data.tendangnhap && matkhau == point->data.matkhau)
        {
            return true;
        }
        point = point->next;
    }

    return false;
}

// 1.1 chuc nang dang nhap
//oke
void chucNangDangNhap() {
    string tendangnhap;
    string matkhau;
    
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
//oke
void dangXuat() {
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
    cout << "Nhap thang sinh: " ;
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

// sap bo
// 1.5 tao nguoi dung
// them nguoi dung vao danh sach
// void themNguoiDungVaoDau (NodeNhanVien *head, NhanVien &nv) {
//     NodeNhanVien *node = new NodeNhanVien();
//     node->data = nv;
//     node->next = NULL;

//     // check head
//     if (head == NULL)
//     {
//         head = node;
//     }
//     else
//     {
//         node->next = head;
//         head = node;
//     }
// }

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
//oke
void inDanhSachDocGia() 
{
    NodeDocGia *point = headDocGia;
    
    while (point != NULL)
    {
        if(point->data.gioitinh == 1){
            inDocGia(point->data);
        }
        
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

// 2.6 Tim kiem doc gia theo ho ten

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

//3.4 Xóa thông tin sách


//3.5 Tìm kiếm sách theo ISBN
Sach* timSachTheoMa(int ma)
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

//3.6 Tìm kiếm sách theo tên sách
Sach* timSachTheoTen(string ten)
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

// 4 Lap phieu muon sach
bool muonSach(int masach);
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
    
    for(int i=0; i<10;)
    {
        xemSachTrongThuVien();
        cout<<"Nhap ma sach thu " << i + 1 << " (Nhap 0 de ket thuc): ";
        int masach;
        cin>>masach;
        
        if (masach == 0)
        {
            break;
        }

        if(muonSach(masach))
        {
            muon.masach[i] = masach;
            i++;
        }
        else
        {
            cout<<"Sach da het hoac khong ton tai!"<<endl;
        }
        
    }
    
    cout<<"Nhap ngay muon (dd mm yyyy): ";
    cin>>muon.ngaymuon.ngay>>muon.ngaymuon.thang>>muon.ngaymuon.nam;
    cout<<"Ngay tra du kiem (dd mm yyyy): ";
    cin>>muon.ngaytradukien.ngay>>muon.ngaytradukien.thang>>muon.ngaytradukien.nam;
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
}

//6.1
int  soluongsach(NodeDocGia *head) 
{
    NodeDocGia *point = head;
    int coutd = 0;
    while (point != NULL)
    {
        inDocGia(point->data);
        point = point->next;
    }    
}

void menuAdmin(){


  int chon;
    cin >> chon;
    cout << "1.quan ly tai khoan : "<<endl;
    cout << "2.quan ly doc gia  : "<<endl;
    cout << "3.quan ly sach : "<<endl;
    cout << "4.Lap phieu muon sach : "<<endl;
    cout << "5.Lap phieu tra sach : "<<endl;
    cout << "6.Cac thong ke co ban : "<<endl;
    cout << "Chon chuc nang 1-6 : "<<endl;

   switch (chon)
   {
       //quan ly tai khoan
   case 1 :{
       cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Dang xuat: "<<endl;
        cout << "2.Thay doi mat khau : "<<endl;
        cout << "3.Cap nhat thong tin ca nhan: "<<endl;
        cout << "4:Tao nguoi dung :"<<endl;
        cout << "5.Phan quyen nguoi dung: "<<endl;
       int c; 
       cin>>c;
       switch (c)
       {
       case 1:{
           //dang xuat
            break;
       }
       case 2:{
           //thay doi mat khau
            break;
       }
       case 3:{
           //Cap nhat thong tin 
            break;
       }
       case 4:{
           //Tao nguoi dung 
            break;
       }
       case 5:{
           //Phan quyen nguoi dung
            break;
       }
          
       
       default:
           break;
       }
        
       break;
   }



    // quan ly doc gia
   case 2 :{
        cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Xem danh sach doc gia : "<<endl;
        cout << "2.Them doc gia: "<<endl;
        cout << "3.Cap nhat thong tin doc gia : "<<endl;
        cout << "4:Xoa doc gia:"<<endl;
        cout << "5.Tim kiem theo CMND: "<<endl;
        cout << "6.Tim kiem theo ho ten : "<<endl;
       int d; 
       cin>>d;
       switch (d)
       {
       case 1:{
            //xem dach dach doc gia
           break;
       }
        case 2:{
            //them doc gia 
           break;
       }
        case 3:{
            //Cap nhat thong tin doc gia
           break;
       }
        case 4:{
            //xoadoc gia
           break;
       }
        case 5:{
            //Tim kiem theo cmnd
           break;
       }
        case 6:{
            //tim kiem theo ho ten
           break;
       }
       default:
           break;
       }
       break;

   }


   //quan ly sach
   case 3 :{
        cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Xem danh sach cac sach trong thu vien  : "<<endl;
        cout << "2.Them sach : "<<endl;
        cout << "3.Cap nhat thong tin quyen sach : "<<endl;
        cout << "4:Xoa quyen sach :"<<endl;
        cout << "5.Tim kiem theo ISBN : "<<endl;
        cout << "6.Tim kiem theo ten sach : "<<endl;
       int e; 
       cin>>e;
        switch (e)
        {
        case 1 :{

            break;
        }
        case 2 :{
            
            break;
        }
        case 3 :{
            
            break;
        }
        case 4 :{
            
            break;
        }
        case 5 :{
            
            break;
        }
        case 6 :{
            
            break;
        }
            
        
        default:
            break;
        }


       break;
   }


   //Lap phieu muon sach
   case 4 :{
       //phieu muon sach 
       break;
   }


   //lap phieu tra sach
   case 5 :{
       //phieu tra sach
       break;
   }

   //cac thong ke co ban
   case 6 :{
       cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Thong ke cac sach co trong thu vien : "<<endl;
        cout << "2.Thong ke so luong sach theo loai : "<<endl;
        cout << "3.Thong ke so luong doc gia : "<<endl;
        cout << "4:Thong ke so luong doc gia theo gioi tinh  :"<<endl;
        cout << "5.Thong ke sach dang muon: "<<endl;
        cout << "6.thong ke doc gia dang bi tre hen : "<<endl;
       int e; 
       cin>>e;
       switch (e)
       {
       case 1:{

             break;
       }
       case 2:{
           
             break;
       }
       case 3:{
           
             break;
       }
       case 4:{
           
             break;
       }
       case 5:{
           
             break;
       }
       case 6:{
           
             break;
       }
         
       
       default:
           break;
       }

       break;
   }
   
   
   default:
       break;
   }
    
}
void menuQuanly(){

  int chon;
    cin >> chon;
    cout << "1.quan ly tai khoan : "<<endl;
    cout << "2.quan ly doc gia  : "<<endl;
    cout << "3.quan ly sach : "<<endl;
    cout << "4.Lap phieu muon sach : "<<endl;
    cout << "5.Lap phieu tra sach : "<<endl;
    cout << "6.Cac thong ke co ban : "<<endl;
    cout << "Chon chuc nang 1-6 : "<<endl;

   switch (chon)
   {
       //quan ly tai khoan
   case 1 :{
       cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Dang xuat: "<<endl;
        cout << "2.Thay doi mat khau : "<<endl;
        cout << "3.Cap nhat thong tin ca nhan: "<<endl;
    
       int c; 
       cin>>c;
       switch (c)
       {
       case 1:{
           //dang xuat
            break;
       }
       case 2:{
           //thay doi mat khau
            break;
       }
       case 3:{
           //Cap nhat thong tin 
            break;
       }
       default:
           break;
       }
        
       break;
   }



    // quan ly doc gia
   case 2 :{
        cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Xem danh sach doc gia : "<<endl;
        cout << "2.Them doc gia: "<<endl;
        cout << "3.Cap nhat thong tin doc gia : "<<endl;
        cout << "4:Xoa doc gia:"<<endl;
        cout << "5.Tim kiem theo CMND: "<<endl;
        cout << "6.Tim kiem theo ho ten : "<<endl;
       int d; 
       cin>>d;
       switch (d)
       {
       case 1:{
            //xem dach dach doc gia
           break;
       }
        case 2:{
            //them doc gia 
           break;
       }
        case 3:{
            //Cap nhat thong tin doc gia
           break;
       }
        case 4:{
            //xoadoc gia
           break;
       }
        case 5:{
            //Tim kiem theo cmnd
           break;
       }
        case 6:{
            //tim kiem theo ho ten
           break;
       }
       default:
           break;
       }
       break;




   }


   //quan ly sach
   case 3 :{
        cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Xem danh sach cac sach trong thu vien  : "<<endl;
        cout << "2.Them sach : "<<endl;
        cout << "3.Cap nhat thong tin quyen sach : "<<endl;
        cout << "4:Xoa quyen sach :"<<endl;
        cout << "5.Tim kiem theo ISBN : "<<endl;
        cout << "6.Tim kiem theo ten sach : "<<endl;
       int e; 
       cin>>e;
        switch (e)
        {
        case 1 :{

            break;
        }
        case 2 :{
            
            break;
        }
        case 3 :{
            
            break;
        }
        case 4 :{
            
            break;
        }
        case 5 :{
            
            break;
        }
        case 6 :{
            
            break;
        }
            
        
        default:
            break;
        }


       break;
   }


   //Lap phieu muon sach
   case 4 :{
       //phieu muon sach 
       break;
   }


   //lap phieu tra sach
   case 5 :{
       //phieu tra sach
       break;
   }

   //cac thong ke co ban
   case 6 :{
       cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Thong ke cac sach co trong thu vien : "<<endl;
        cout << "2.Thong ke so luong sach theo loai : "<<endl;
        cout << "3.Thong ke so luong doc gia : "<<endl;
        cout << "4:Thong ke so luong doc gia theo gioi tinh  :"<<endl;
        cout << "5.Thong ke sach dang muon: "<<endl;
        cout << "6.thong ke doc gia dang bi tre hen : "<<endl;
       int e; 
       cin>>e;
       switch (e)
       {
       case 1:{

             break;
       }
       case 2:{
           
             break;
       }
       case 3:{
           
             break;
       }
       case 4:{
           
             break;
       }
       case 5:{
           
             break;
       }
       case 6:{
           
             break;
       }
         
       
       default:
           break;
       }

       break;
   }
   
   
   default:
       break;
   }
}
void menuChuyenvien(){

  int chon;
    cin >> chon;
    cout << "1.quan ly tai khoan : "<<endl;
    cout << "2.quan ly doc gia  : "<<endl;
    cout << "3.quan ly sach : "<<endl;
    cout << "4.Lap phieu muon sach : "<<endl;
    cout << "5.Lap phieu tra sach : "<<endl;
    cout << "6.Cac thong ke co ban : "<<endl;
    cout << "Chon chuc nang 1-6 : "<<endl;

   switch (chon)
   {
       //quan ly tai khoan
   case 1 :{
       cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Dang xuat: "<<endl;
        cout << "2.Thay doi mat khau : "<<endl;
        cout << "3.Cap nhat thong tin ca nhan: "<<endl;
        
       int c; 
       cin>>c;
       switch (c)
       {
       case 1:{
           //dang xuat
            break;
       }
       case 2:{
           //thay doi mat khau
            break;
       }
       case 3:{
           //Cap nhat thong tin 
            break;
       }
       default:
           break;
       }
        
       break;
   }



    // quan ly doc gia
   case 2 :{
        cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Xem danh sach doc gia : "<<endl;
        cout << "2.Them doc gia: "<<endl;
        cout << "3.Cap nhat thong tin doc gia : "<<endl;
        cout << "4.Tim kiem theo CMND: "<<endl;
        cout << "5.Tim kiem theo ho ten : "<<endl;
       int d; 
       cin>>d;
       switch (d)
       {
       case 1:{
            //xem dach dach doc gia
           break;
       }
        case 2:{
            //them doc gia 
           break;
       }
        case 3:{
            //Cap nhat thong tin doc gia
           break;
       }
        case 4:{
            //Tim kiem theo cmnd
           break;
       }
        case 5:{
            //tim kiem theo ho ten
           break;
       }
       default:
           break;
       }
       break;




   }


   //quan ly sach
   case 3 :{
        cout << "Moi chon chuc nang: "<<endl;
        cout << "1.Tim kiem theo ISBN : "<<endl;
        cout << "2.Tim kiem theo ten sach : "<<endl;
       int e; 
       cin>>e;
        switch (e)
        {
        case 1 :{

            break;
        }
        case 2 :{
            
            break;
        }
        default:
            break;
        }


       break;
   }


   //Lap phieu muon sach
   case 4 :{
       //phieu muon sach 
       break;
   }


   //lap phieu tra sach
   case 5 :{
       //phieu tra sach
       break;
   }
   
   
   default:
       break;
   }
}


// Ket thuc cac chuc nang
/*-------------------------------------------------------*/


/*-------------------------------------------------------*/
// Ham main

int main()
{
    initData();
    lapPhieuMuonSach();
}
/*-------------------------------------------------------*/