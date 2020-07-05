#include<string>
using namespace std;
struct Muon_Tra
{
    /* data */
    string madocgia;
    string ngaymuon;
    string ngaytradukien;
    string ngaytrathucte;
};
struct NodeMuon_Tra
{
    /* data */
    Muon_Tra data;
    Muon_Tra * next;
};

