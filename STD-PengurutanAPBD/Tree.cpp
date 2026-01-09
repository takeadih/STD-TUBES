#include "Tree.h"

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

void addChild(adrNode parent, adrNode child) {
    if (parent->firstChild == nullptr) {
        parent->firstChild = child;
    } else {
        adrNode temp = parent->firstChild;
        while (temp->nextSibling != nullptr)
            temp = temp->nextSibling;
        temp->nextSibling = child;
    }
}

// Traversal
void preorder(adrNode root) {
    if (root != nullptr) {
        cout << root->id << " ";
        preorder(root->firstChild);
        preorder(root->nextSibling);
    }
}

void inorder(adrNode root) {
    if (root != nullptr) {
        inorder(root->firstChild);
        cout << root->id << " ";
        inorder(root->nextSibling);
    }
}

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
        cout << "- [" << root->id << "] " << root->nama;
        if (root->anggaran > 0)
            cout << " | Rp " << root->anggaran << " M";
        cout << endl;

        tampilTree(root->firstChild, level + 1);
        tampilTree(root->nextSibling, level);
    }
}

// Anggaran minimum
double getMinAnggaran(adrNode root) {
    if (root == nullptr) return -1;

    double minVal = (root->anggaran > 0) ? root->anggaran : -1;
    double c = getMinAnggaran(root->firstChild);
    double s = getMinAnggaran(root->nextSibling);

    if (c > 0 && (minVal < 0 || c < minVal)) minVal = c;
    if (s > 0 && (minVal < 0 || s < minVal)) minVal = s;

    return minVal;
}

// Anggaran maksimum
double getMaxAnggaran(adrNode root) {
    if (root == nullptr) return 0;

    double maxVal = root->anggaran;
    double c = getMaxAnggaran(root->firstChild);
    double s = getMaxAnggaran(root->nextSibling);

    if (c > maxVal) maxVal = c;
    if (s > maxVal) maxVal = s;

    return maxVal;
}

// Inisialisasi data
void loadSampleAPBD(adrNode &root) {
    root = createNode(1, "Provinsi Jawa Barat");

    adrNode kab = createNode(101, "Kabupaten");
    adrNode kota = createNode(102, "Kota");

    addChild(root, kab);
    addChild(root, kota);

    adrNode kabBandung = createNode(201, "Kabupaten Bandung");
    adrNode kabGarut   = createNode(202, "Kabupaten Garut");
    addChild(kab, kabBandung);
    addChild(kab, kabGarut);

    addChild(kabBandung, createNode(301, "Anggaran Kab. Bandung", 12500));
    addChild(kabGarut,   createNode(302, "Anggaran Kab. Garut", 9100));

    adrNode kotaBekasi = createNode(203, "Kota Bekasi");
    adrNode kotaDepok  = createNode(204, "Kota Depok");
    addChild(kota, kotaBekasi);
    addChild(kota, kotaDepok);

    addChild(kotaBekasi, createNode(303, "Anggaran Kota Bekasi", 9800));
    addChild(kotaDepok,  createNode(304, "Anggaran Kota Depok", 8400));
}
