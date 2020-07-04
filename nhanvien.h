#include <string>
using namespace std;

struct NhanVien
{
    int id;
    string name;
    string username;
    string password;
};

struct NodeNhanVien
{
    NhanVien data;
    NodeNhanVien *next;
};