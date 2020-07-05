#include<string>
using namespace std;
struct Sach
{
    string masach;
    string tensach;
    string tacgia;
    string nhasanxuat;
    string namsuatban;
    string theloai;
    double giasach;
    int soluong;
};

struct NodeSach
{
    Sach data;
    NodeSach *next;
};