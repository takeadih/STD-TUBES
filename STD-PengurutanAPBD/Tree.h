#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/*
    Tree Hirarki APBD (General Tree)
    Representasi: Left-Child Right-Sibling (LCRS)

    Level:
    - Provinsi        : x
    - Kabupaten/Kota  : 10x (kabupaten < kota)
    - Anggaran        : 30x
*/

struct Node {
    int id;                 // UNIQUE ID
    string nama;            // Nama provinsi / kabupaten / kota
    double anggaran;        // Hanya terisi di level anggaran
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
void inorder(adrNode root);     // berbasis LCRS
void postorder(adrNode root);

// Visualisasi
void tampilTree(adrNode root, int level = 0);

// Analisis anggaran
double getMinAnggaran(adrNode root);
double getMaxAnggaran(adrNode root);

// Data awal
void loadSampleAPBD(adrNode &root);

#endif
