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
typedef struct Node* adrNode;

struct Node {
    infotype idAPBD;            // UNIQUE ID (key BST)
    string provinsi;
    string kabKota;
    string namaProgram;
    string jenisBelanja;
    double anggaran;

    adrNode left;
    adrNode right;
};

/* Operasi dasar BST */
void createTree_APBD(adrNode &root);
adrNode createNode_APBD(
    infotype id,
    string prov,
    string kabkota,
    string nama,
    string jenis,
    double anggaran
);

bool isUniqueID_APBD(adrNode root, infotype id);
void insertNode_APBD(adrNode &root, adrNode p);
adrNode searchNode_APBD(adrNode root, infotype id);

/* Traversal */
void tampilUrutAPBD_Inorder(adrNode root);   // hasil pengurutan
void tampilAPBD_Preorder(adrNode root);
void tampilAPBD_Postorder(adrNode root);

/* Fitur tambahan */
int countProgram_APBD(adrNode root);
double totalAnggaran_APBD(adrNode root);
infotype getMinID_APBD(adrNode root);
infotype getMaxID_APBD(adrNode root);

#endif
