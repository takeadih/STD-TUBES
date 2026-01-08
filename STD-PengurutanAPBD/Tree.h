#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/*
    Sistem ini mengurutkan data APBD
    berdasarkan UNIQUE ID (Kode Program/Kegiatan APBD)
    menggunakan Binary Search Tree dan rekursi.
*/

typedef int infotype;

struct Node {
    infotype idAPBD;        // UNIQUE ID (key pengurutan)
    string namaProgram;
    string jenisBelanja;
    double anggaran;
    Node* left;
    Node* right;
};

typedef Node* adrNode;

void createTree_APBD(adrNode &root);

adrNode createNode_APBD(infotype id, string nama, string jenis, double anggaran);
bool isUniqueID_APBD(adrNode root, infotype id);

void insertNode_APBD(adrNode &root, adrNode p);
adrNode searchNode_APBD(adrNode root, infotype id);

// Hasil pengurutan APBD berdasarkan UNIQUE ID
void tampilUrutAPBD_Inorder(adrNode root);

int countProgram_APBD(adrNode root);
double totalAnggaran_APBD(adrNode root);
infotype getMinID_APBD(adrNode root);
infotype getMaxID_APBD(adrNode root);

void loadSampleAPBD(adrNode &root);

#endif
