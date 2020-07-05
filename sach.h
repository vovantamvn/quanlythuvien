#include<string>
using namespace std;
struct Sach
{
    int masach;
    string tensach;
    string tacgia;
    string nhasanxuat;
    string theloai;
    int namxuatban;
    double giasach;
    int soluong;
};

struct NodeSach
{
    Sach data;
    NodeSach *next;
};