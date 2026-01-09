#include "Tree.h"

// Inisialisasi tree
void createTree(adrNode &root) {
    root = nullptr;
}

// Membuat node
adrNode createNode(int id, string nama, double anggaran) {
    adrNode p = new Node;
    p->id = id;
    p->nama = nama;
    p->anggaran = anggaran;
    p->firstChild = nullptr;
    p->nextSibling = nullptr;
    return p;
}

// Menambahkan child ke parent
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

// Menampilkan struktur tree (visualisasi)
void tampilTree(adrNode root, int level) {
    if (root != nullptr) {
        for (int i = 0; i < level; i++) cout << "  ";
        cout << "- [" << root->id << "] " << root->nama;

        if (root->anggaran > 0)
            cout << " | Rp " << root->anggaran << " M";

        cout << endl;

        tampilTree(root->firstChild, level + 1);
        tampilTree(root->nextSibling, level);
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
        cout << root->id << " ";
        postorder(root->nextSibling);
    }
}

// Data APBD diinisialisasi
void loadSampleAPBD(adrNode &root) {
    // Provinsi
    root = createNode(1, "Provinsi Jawa Barat");

    // Kabupaten/Kota
    adrNode kabBandung = createNode(101, "Kabupaten Bandung");
    adrNode kabBekasi  = createNode(102, "Kabupaten Bekasi");

    addChild(root, kabBandung);
    addChild(root, kabBekasi);

    // Program APBD (20x)
    adrNode progJalan = createNode(201, "Pembangunan Jalan Kabupaten");
    adrNode progBansos = createNode(202, "Bantuan Sosial Masyarakat");
    adrNode progSekolah = createNode(203, "Peningkatan Sarana Pendidikan");

    addChild(kabBandung, progJalan);
    addChild(kabBandung, progBansos);
    addChild(kabBekasi, progSekolah);

    // Anggaran (30x)
    adrNode anggaran1 = createNode(301, "Anggaran Tahun 2025", 12500);
    adrNode anggaran2 = createNode(302, "Anggaran Tahun 2025", 9600);
    adrNode anggaran3 = createNode(303, "Anggaran Tahun 2025", 8200);

    addChild(progJalan, anggaran1);
    addChild(progBansos, anggaran2);
    addChild(progSekolah, anggaran3);
}
