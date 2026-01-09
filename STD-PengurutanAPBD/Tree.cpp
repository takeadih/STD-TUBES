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

// Preorder
void preorder(adrNode root) {
    if (root != nullptr) {
        cout << root->id << " ";
        preorder(root->firstChild);
        preorder(root->nextSibling);
    }
}

// Postorder
void postorder(adrNode root) {
    if (root != nullptr) {
        postorder(root->firstChild);
        cout << root->id << " ";
        postorder(root->nextSibling);
    }
}

// Cari anggaran terkecil (hanya node 30x)
double getMinAnggaran(adrNode root) {
    if (root == nullptr) return DBL_MAX;

    double minChild = getMinAnggaran(root->firstChild);
    double minSibling = getMinAnggaran(root->nextSibling);

    double minValue = (minChild < minSibling) ? minChild : minSibling;

    if (root->id >= 300 && root->id < 400) {
        return (root->anggaran < minValue) ? root->anggaran : minValue;
    }
    return minValue;
}

// Cari anggaran terbesar
double getMaxAnggaran(adrNode root) {
    if (root == nullptr) return 0;

    double maxChild = getMaxAnggaran(root->firstChild);
    double maxSibling = getMaxAnggaran(root->nextSibling);

    double maxValue = (maxChild > maxSibling) ? maxChild : maxSibling;

    if (root->id >= 300 && root->id < 400) {
        return (root->anggaran > maxValue) ? root->anggaran : maxValue;
    }
    return maxValue;
}

// Inisialisasi data APBD
void loadSampleAPBD(adrNode &root) {

    // ===== PROVINSI 1 =====
    root = createNode(1, "Provinsi Jawa Barat");

    adrNode kabBandung = createNode(101, "Kabupaten Bandung");
    adrNode kabBekasi  = createNode(102, "Kabupaten Bekasi");

    addChild(root, kabBandung);
    addChild(root, kabBekasi);

    adrNode progJalan = createNode(201, "Pembangunan Jalan Kabupaten");
    adrNode progBansos = createNode(202, "Bantuan Sosial Masyarakat");
    adrNode progSekolah = createNode(203, "Peningkatan Sarana Pendidikan");

    addChild(kabBandung, progJalan);
    addChild(kabBandung, progBansos);
    addChild(kabBekasi, progSekolah);

    addChild(progJalan, createNode(301, "Anggaran 2025", 12500));
    addChild(progBansos, createNode(302, "Anggaran 2025", 9600));
    addChild(progSekolah, createNode(303, "Anggaran 2025", 8200));

    // ===== PROVINSI 2 =====
    adrNode provJateng = createNode(2, "Provinsi Jawa Tengah");
    addChild(root, provJateng);

    adrNode kabSemarang = createNode(103, "Kota Semarang");
    addChild(provJateng, kabSemarang);

    adrNode progKesehatan = createNode(204, "Peningkatan Layanan Kesehatan");
    addChild(kabSemarang, progKesehatan);

    addChild(progKesehatan, createNode(304, "Anggaran 2025", 14500));
}
