#pragma once
#include <string>
#include "ngay.h"
using namespace std;


typedef struct MuonTra
{
    int ma = 0;
    int madocgia;
    int masach[3] = {0}; // toi da cho muon 3 quyen
    Ngay ngaymuon;
    Ngay ngaytradukien;
    Ngay ngaytrathucte;
} MuonTra;

typedef struct NodeMuonTra
{
    MuonTra data;
    NodeMuonTra * next;
} NodeMuonTra;

