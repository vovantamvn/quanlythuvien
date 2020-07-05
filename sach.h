#pragma once
#include<string>
using namespace std;


typedef struct Sach
{
    int masach;
    string tensach;
    string tacgia;
    string nhasanxuat;
    string theloai;
    int namxuatban;
    double giasach;
    int soluong;
} Sach;

typedef struct NodeSach
{
    Sach data;
    NodeSach *next;
} NodeSach;