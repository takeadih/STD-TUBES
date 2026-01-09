#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/*
    Tree Hirarki APBD
    Struktur:
    Provinsi (x)
      └─ Kabupaten/Kota (10x)
          └─ Program APBD (20x)
              └─ Anggaran (30x)
*/

struct Node {
    int id;                 // UNIQUE ID sesuai level
    string nama;            // Nama entitas
    double anggaran;        // Hanya terisi di level anggaran (30x)
    Node* firstChild;
    Node* nextSibling;
};

typedef Node* adrNode;

// Inisialisasi
void createTree(adrNode &root);
adrNode createNode(int id, string nama, double anggaran = 0);

// Operasi tree
void addChild(adrNode parent, adrNode child);

// Traversal & visualisasi
void tampilTree(adrNode root, int level = 0);
void preorder(adrNode root);
void postorder(adrNode root);

// Fitur anggaran
double getMinAnggaran(adrNode root);
double getMaxAnggaran(adrNode root);

// Data awal
void loadSampleAPBD(adrNode &root);

#endif
