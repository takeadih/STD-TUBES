#include "Tree.h"
#include <cfloat>

void createTree_APBD(adrNode &root) {
    root = nullptr;
}

adrNode createNode_APBD(
    infotype id,
    string kab,
    string nama,
    double anggaran
) {
    adrNode p = new Node;
    p->idAPBD = id;
    p->kabupatenKota = kab;
    p->namaProgram = nama;
    p->anggaran = anggaran;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertNode_APBD(adrNode &root, adrNode p) {
    if (root == nullptr) {
        root = p;
    } else if (p->idAPBD < root->idAPBD) {
        insertNode_APBD(root->left, p);
    } else if (p->idAPBD > root->idAPBD) {
        insertNode_APBD(root->right, p);
    }
}

adrNode searchNode_APBD(adrNode root, infotype id) {
    if (root == nullptr) return nullptr;
    if (id < root->idAPBD) return searchNode_APBD(root->left, id);
    if (id > root->idAPBD) return searchNode_APBD(root->right, id);
    return root;
}

// INORDER = hasil pengurutan UNIQUE ID
void tampilInorder_APBD(adrNode root) {
    if (root != nullptr) {
        tampilInorder_APBD(root->left);
        cout << root->idAPBD << " | "
             << root->kabupatenKota << " | "
             << root->namaProgram << " | Rp "
             << root->anggaran << " M\n";
        tampilInorder_APBD(root->right);
    }
}

void tampilPreorder_APBD(adrNode root) {
    if (root != nullptr) {
        cout << root->idAPBD << " | "
             << root->namaProgram << endl;
        tampilPreorder_APBD(root->left);
        tampilPreorder_APBD(root->right);
    }
}

void tampilPostorder_APBD(adrNode root) {
    if (root != nullptr) {
        tampilPostorder_APBD(root->left);
        tampilPostorder_APBD(root->right);
        cout << root->idAPBD << " | "
             << root->namaProgram << endl;
    }
}

int countProgram_APBD(adrNode root) {
    if (root == nullptr) return 0;
    return 1 + countProgram_APBD(root->left)
             + countProgram_APBD(root->right);
}

double totalAnggaran_APBD(adrNode root) {
    if (root == nullptr) return 0;
    return root->anggaran
         + totalAnggaran_APBD(root->left)
         + totalAnggaran_APBD(root->right);
}

// Cari anggaran minimum (traversal seluruh tree)
double getMinAnggaran_APBD(adrNode root) {
    if (root == nullptr) return DBL_MAX;

    double kiri = getMinAnggaran_APBD(root->left);
    double kanan = getMinAnggaran_APBD(root->right);

    double minChild = (kiri < kanan) ? kiri : kanan;
    return (root->anggaran < minChild) ? root->anggaran : minChild;
}

// Cari anggaran maksimum
double getMaxAnggaran_APBD(adrNode root) {
    if (root == nullptr) return 0;

    double kiri = getMaxAnggaran_APBD(root->left);
    double kanan = getMaxAnggaran_APBD(root->right);

    double maxChild = (kiri > kanan) ? kiri : kanan;
    return (root->anggaran > maxChild) ? root->anggaran : maxChild;
}

void loadSampleAPBD(adrNode &root) {
    insertNode_APBD(root,
        createNode_APBD(412, "Kab. Bandung",
        "Bantuan Sosial Masyarakat", 9600));

    insertNode_APBD(root,
        createNode_APBD(101, "Kab. Bandung",
        "Pembangunan Jalan Kabupaten", 12500));

    insertNode_APBD(root,
        createNode_APBD(735, "Kota Jakarta Pusat",
        "Digitalisasi Layanan Pemerintah", 3800));

    insertNode_APBD(root,
        createNode_APBD(205, "Kota Semarang",
        "Peningkatan Sarana Pendidikan", 8200));

    insertNode_APBD(root,
        createNode_APBD(624, "Kota Makassar",
        "Ketahanan Pangan Daerah", 7100));
}
