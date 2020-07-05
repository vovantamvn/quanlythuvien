#pragma once
#include <string>
#include "ngay.h"
using namespace std;
typedef struct Muon_Tra
{
    /* data */
    string madocgia;
    string ngaymuon;
    Ngay ngaytradukien;
    Ngay ngaytrathucte;
} Muon_Tra;
struct NodeMuon_Tra
{
    /* data */
    Muon_Tra data;
    Muon_Tra * next;
} NodeMuon_Tra;

