#pragma once
#include <string>
#include"ngay.h"
using namespace std;

typedef struct NhanVien
{
    int id;
    string tendangnhap;
    string hoten;
    string matkhau;
    Ngay ngaysinh;
    string cmnd;
    string diachi;
    int gioitinh;  // 0: nu, 1: nam
    int trangthai; // 0: block, 1: actived
    int loainguoidung; // 1: admin, 2: quanly, 3 chuyenvien
} NhanVien;

typedef struct NodeNhanVien
{
    NhanVien data;
    NodeNhanVien *next;
} NodeNhanVien;