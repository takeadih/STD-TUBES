#include "Tree.h"

void createTree_APBD(adrNode &root) {
    root = nullptr;
}

adrNode createNode_APBD(infotype id, string nama, string jenis, double anggaran) {
    adrNode p = new Node;
    p->idAPBD = id;
    p->namaProgram = nama;
    p->jenisBelanja = jenis;
    p->anggaran = anggaran;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

bool isUniqueID_APBD(adrNode root, infotype id) {
    return searchNode_APBD(root, id) == nullptr;
}

// Insert BST secara rekursif berdasarkan UNIQUE ID
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
    if (root == nullptr) {
        return nullptr;
    } else if (id < root->idAPBD) {
        return searchNode_APBD(root->left, id);
    } else if (id > root->idAPBD) {
        return searchNode_APBD(root->right, id);
    }
    return root;
}

// Inorder traversal = hasil pengurutan APBD berdasarkan UNIQUE ID
void tampilUrutAPBD_Inorder(adrNode root) {
    if (root != nullptr) {
        tampilUrutAPBD_Inorder(root->left);
        cout << "Kode: " << root->idAPBD
             << " | Program: " << root->namaProgram
             << " | Jenis: " << root->jenisBelanja
             << " | Anggaran: Rp " << root->anggaran << " M\n";
        tampilUrutAPBD_Inorder(root->right);
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

infotype getMinID_APBD(adrNode root) {
    adrNode p = root;
    while (p->left != nullptr) {
        p = p->left;
    }
    return p->idAPBD;
}

infotype getMaxID_APBD(adrNode root) {
    adrNode p = root;
    while (p->right != nullptr) {
        p = p->right;
    }
    return p->idAPBD;
}

void loadSampleAPBD(adrNode &root) {
    insertNode_APBD(root,
        createNode_APBD(412, "Bantuan Sosial Masyarakat Kurang Mampu",
        "Belanja Operasi", 9600));

    insertNode_APBD(root,
        createNode_APBD(101, "Pembangunan dan Pemeliharaan Jalan Kabupaten",
        "Belanja Modal", 12500));

    insertNode_APBD(root,
        createNode_APBD(735, "Digitalisasi Layanan Administrasi Pemerintah Daerah",
        "Belanja Modal", 3800));

    insertNode_APBD(root,
        createNode_APBD(205, "Peningkatan Sarana dan Prasarana Sekolah Negeri",
        "Belanja Modal", 8200));

    insertNode_APBD(root,
        createNode_APBD(624, "Penguatan Ketahanan Pangan Daerah",
        "Belanja Operasi", 7100));
}

