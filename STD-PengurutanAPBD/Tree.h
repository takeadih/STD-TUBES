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
    string nama;            // Nama provinsi / kabupaten / program / anggaran
    double anggaran;        // Hanya di level anggaran
    Node* firstChild;
    Node* nextSibling;
};

typedef Node* adrNode;

// Inisialisasi
void createTree(adrNode &root);
adrNode createNode(int id, string nama, double anggaran = 0);

// Operasi Tree
void addChild(adrNode parent, adrNode child);

// Traversal & visualisasi
void tampilTree(adrNode root, int level = 0);
void preorder(adrNode root);
void postorder(adrNode root);

// Data awal
void loadSampleAPBD(adrNode &root);

#endif
