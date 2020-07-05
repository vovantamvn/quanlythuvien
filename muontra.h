#pragma once
#include <string>
#include "ngay.h"
using namespace std;


typedef struct MuonTra
{
    int madocgia;
    Ngay ngaymuon;
    Ngay ngaytradukien;
    Ngay ngaytrathucte;
} MuonTra;

typedef struct NodeMuonTra
{
    MuonTra data;
    NodeMuonTra * next;
} NodeMuonTra;

