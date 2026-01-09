#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/*
 Tree Hirarki APBD (3 Level)
 Provinsi
 ├─ Kabupaten
 │   ├─ Nama Kabupaten
 │   │   └─ Anggaran
 └─ Kota
     ├─ Nama Kota
     │   └─ Anggaran
*/

struct Node {
    int id;                 // UNIQUE ID
    string nama;            // Nama wilayah / anggaran
    double anggaran;        // Khusus node anggaran

    Node* firstChild;       // Anak pertama
    Node* nextSibling;      // Saudara berikutnya
};

typedef Node* adrNode;

// Dasar
void createTree(adrNode &root);
adrNode createNode(int id, string nama, double anggaran = 0);

// Operasi tree
void addChild(adrNode parent, adrNode child);

// Traversal
void preorder(adrNode root);
void postorder(adrNode root);

// Visualisasi
void tampilTree(adrNode root, int level = 0);

// Anggaran
double getMinAnggaran(adrNode root);
double getMaxAnggaran(adrNode root);

// Data awal
void loadSampleAPBD(adrNode &root);

#endif
