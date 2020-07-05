#pragma once
#include <string>
#include "ngay.h"
using namespace std;


typedef struct DocGia
{
    int ma;
    string hoten;
    string cmnd;
    Ngay ngaysinh;
    int gioitinh; // 0 nu , 1 nam
    string email;
    string diachi;
    Ngay ngaylapthe;
    Ngay ngayhethan;
} DocGia;


typedef struct NodeDocGia
{
    DocGia data;
    NodeDocGia *next;
} NodeDocGia;


