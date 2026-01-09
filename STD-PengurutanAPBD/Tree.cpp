#include "Tree.h"

// Membuat tree kosong
void createTree(adrNode &root) {
    root = nullptr;
}

// Membuat node baru
adrNode createNode(int id, string nama, double anggaran) {
    adrNode p = new Node;
    p->id = id;
    p->nama = nama;
    p->anggaran = anggaran;
    p->firstChild = nullptr;
    p->nextSibling = nullptr;
    return p;
}

// Menambahkan child ke parent (hirarki)
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

// Inorder traversal (LCRS)
void inorder(adrNode root) {
    if (root != nullptr) {
        inorder(root->firstChild);
        cout << root->id << " ";
        inorder(root->nextSibling);
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

// Visualisasi struktur tree
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

// Mencari anggaran terkecil
double getMinAnggaran(adrNode root) {
    if (root == nullptr) return -1;

    double minVal = (root->anggaran > 0) ? root->anggaran : -1;

    double childMin = getMinAnggaran(root->firstChild);
    double siblingMin = getMinAnggaran(root->nextSibling);

    if (childMin > 0 && (minVal < 0 || childMin < minVal))
        minVal = childMin;
    if (siblingMin > 0 && (minVal < 0 || siblingMin < minVal))
        minVal = siblingMin;

    return minVal;
}

// Mencari anggaran terbesar
double getMaxAnggaran(adrNode root) {
    if (root == nullptr) return 0;

    double maxVal = root->anggaran;

    double childMax = getMaxAnggaran(root->firstChild);
    double siblingMax = getMaxAnggaran(root->nextSibling);

    if (childMax > maxVal) maxVal = childMax;
    if (siblingMax > maxVal) maxVal = siblingMax;

    return maxVal;
}

// Inisialisasi data APBD
void loadSampleAPBD(adrNode &root) {
    root = createNode(1, "Provinsi Jawa Barat");

    // Kabupaten (ID lebih kecil)
    adrNode kabBandung = createNode(101, "Kabupaten Bandung");
    adrNode anggaranKab = createNode(301, "Anggaran Kabupaten Bandung", 12500);

    // Kota (ID lebih besar)
    adrNode kotaBekasi = createNode(102, "Kota Bekasi");
    adrNode anggaranKota = createNode(302, "Anggaran Kota Bekasi", 9800);

    addChild(root, kabBandung);
    addChild(kabBandung, anggaranKab);

    addChild(root, kotaBekasi);
    addChild(kotaBekasi, anggaranKota);
}
