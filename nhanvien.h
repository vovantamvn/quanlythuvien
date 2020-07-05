#include <string>
using namespace std;

struct NhanVien
{
    int id;
    string tendangnhap;
    string matkhau;
    string hoten;
    string ngaysinh;
    string cmnd;
    string diachi;
    int gioitinh;  // 0: nu, 1: nam
    int trangthai; // 0: block, 1: actived
};

struct NodeNhanVien
{
    NhanVien data;
    NodeNhanVien *next;
};