#include<string>
using namespace std;
struct DocGia
{
    string ma;
    string hoten;
    string cmnd;
    string ngaysinh;
    int gioitinh; // 0 nu , 1 nam
    string email;
    string diachi;
    string ngaylapthe;
    string ngayhethan;

};

struct NodeDocGia
{
    DocGia data;
    NodeDocGia *next;
};


