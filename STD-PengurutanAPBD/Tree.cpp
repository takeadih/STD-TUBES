#include "Tree.h"
#include <cfloat>

void createTree(adrNode &root) {
    root = nullptr;
}

adrNode createNode(int id, string nama, double anggaran) {
    adrNode p = new Node;
    p->id = id;
    p->nama = nama;
    p->anggaran = anggaran;
    p->firstChild = nullptr;
    p->nextSibling = nullptr;
    return p;
}

// Tambah child sebagai sibling terakhir
void addChild(adrNode parent, adrNode child) {
    if (parent->firstChild == nullptr) {
        parent->firstChild = child;
    } else {
        adrNode temp = parent->firstChild;
        while (temp->nextSibling != nullptr) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

// Preorder traversal
void preorder(adrNode root) {
    if (root != nullptr) {
        cout << root->id << " ";
        preorder(root->firstChild);
        preorder(root->nextSibling);
    }
}

// Postorder traversal
void postorder(adrNode root) {
    if (root != nullptr) {
        postorder(root->firstChild);
        postorder(root->nextSibling);
        cout << root->id << " ";
    }
}

// Visualisasi tree
void tampilTree(adrNode root, int level) {
    if (root != nullptr) {
        for (int i = 0; i < level; i++) cout << "  ";
        cout << "[" << root->id << "] " << root->nama;
        if (root->anggaran > 0)
            cout << " | Rp " << root->anggaran << " M";
        cout << endl;

        tampilTree(root->firstChild, level + 1);
        tampilTree(root->nextSibling, level);
    }
}

// Anggaran minimum
double getMinAnggaran(adrNode root) {
    if (root == nullptr) return DBL_MAX;

    double minVal = (root->anggaran > 0) ? root->anggaran : DBL_MAX;
    minVal = min(minVal, getMinAnggaran(root->firstChild));
    minVal = min(minVal, getMinAnggaran(root->nextSibling));

    return minVal;
}

// Anggaran maksimum
double getMaxAnggaran(adrNode root) {
    if (root == nullptr) return 0;

    double maxVal = root->anggaran;
    maxVal = max(maxVal, getMaxAnggaran(root->firstChild));
    maxVal = max(maxVal, getMaxAnggaran(root->nextSibling));

    return maxVal;
}

// Inisialisasi data APBD
void loadSampleAPBD(adrNode &root) {
    root = createNode(1, "Provinsi Jawa Barat");

    adrNode kab = createNode(101, "Kategori Kabupaten");
    adrNode kota = createNode(102, "Kategori Kota");

    addChild(root, kab);
    addChild(root, kota);

    adrNode kabBandung = createNode(201, "Kabupaten Bandung");
    adrNode kabBekasi  = createNode(202, "Kabupaten Bekasi");

    addChild(kab, kabBandung);
    addChild(kab, kabBekasi);

    addChild(kabBandung, createNode(301, "Anggaran APBD", 12500));
    addChild(kabBekasi,  createNode(302, "Anggaran APBD", 9800));

    adrNode kotaBandung = createNode(203, "Kota Bandung");
    adrNode kotaDepok   = createNode(204, "Kota Depok");

    addChild(kota, kotaBandung);
    addChild(kota, kotaDepok);

    addChild(kotaBandung, createNode(303, "Anggaran APBD", 11000));
    addChild(kotaDepok,   createNode(304, "Anggaran APBD", 8700));
}
