#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/*
    Pengurutan APBD menggunakan Binary Search Tree
    berdasarkan UNIQUE ID Program/Kegiatan APBD
*/

typedef int infotype;
typedef struct Node* adrNode;

struct Node {
    infotype idAPBD;          // UNIQUE ID (key BST)
    string kabupatenKota;
    string namaProgram;
    double anggaran;          // juta rupiah
    adrNode left;
    adrNode right;
};

// Inisialisasi
void createTree_APBD(adrNode &root);
adrNode createNode_APBD(
    infotype id,
    string kab,
    string nama,
    double anggaran
);

// Operasi BST
void insertNode_APBD(adrNode &root, adrNode p);
adrNode searchNode_APBD(adrNode root, infotype id);

// Traversal
void tampilInorder_APBD(adrNode root);
void tampilPreorder_APBD(adrNode root);
void tampilPostorder_APBD(adrNode root);

// Informasi APBD
int countProgram_APBD(adrNode root);
double totalAnggaran_APBD(adrNode root);
double getMinAnggaran_APBD(adrNode root);
double getMaxAnggaran_APBD(adrNode root);

// Data awal
void loadSampleAPBD(adrNode &root);

#endif
