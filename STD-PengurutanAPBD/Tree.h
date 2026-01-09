#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/*
    Tree Hirarki APBD
    Representasi: Left-Child Right-Sibling (LCRS)

    Level:
    Provinsi (x)
    └─ Kategori Wilayah (10x)
       └─ Nama Wilayah (20x)
          └─ Anggaran (30x)
*/

struct Node {
    int id;
    string nama;
    double anggaran;
    Node* firstChild;
    Node* nextSibling;
};

typedef Node* adrNode;

// Inisialisasi
void createTree(adrNode &root);
adrNode createNode(int id, string nama, double anggaran = 0);

// Operasi tree
void addChild(adrNode parent, adrNode child);

// Traversal
void preorder(adrNode root);
void inorder(adrNode root);     // LCRS inorder
void postorder(adrNode root);

// Visualisasi
void tampilTree(adrNode root, int level = 0);

// Analisis anggaran
double getMinAnggaran(adrNode root);
double getMaxAnggaran(adrNode root);

// Data awal
void loadSampleAPBD(adrNode &root);

#endif
