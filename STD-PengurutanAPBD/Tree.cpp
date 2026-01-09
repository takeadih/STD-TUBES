#include "Tree.h"

void createTree_APBD(adrNode &root) {
    root = nullptr;
}

adrNode createNode_APBD(
    infotype id,
    string prov,
    string kabkota,
    string nama,
    string jenis,
    double anggaran
) {
    adrNode p = new Node;
    p->idAPBD = id;
    p->provinsi = prov;
    p->kabKota = kabkota;
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

/* Insert BST berdasarkan UNIQUE ID */
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
    if (id < root->idAPBD)
        return searchNode_APBD(root->left, id);
    else if (id > root->idAPBD)
        return searchNode_APBD(root->right, id);
    return root;
}

/* Inorder = hasil pengurutan */
void tampilUrutAPBD_Inorder(adrNode root) {
    if (root != nullptr) {
        tampilUrutAPBD_Inorder(root->left);
        cout << "ID: " << root->idAPBD
             << " | " << root->provinsi
             << " - " << root->kabKota
             << " | " << root->namaProgram
             << " | " << root->jenisBelanja
             << " | Rp " << root->anggaran << " M\n";
        tampilUrutAPBD_Inorder(root->right);
    }
}

void tampilAPBD_Preorder(adrNode root) {
    if (root != nullptr) {
        cout << root->idAPBD << " - " << root->namaProgram << endl;
        tampilAPBD_Preorder(root->left);
        tampilAPBD_Preorder(root->right);
    }
}

void tampilAPBD_Postorder(adrNode root) {
    if (root != nullptr) {
        tampilAPBD_Postorder(root->left);
        tampilAPBD_Postorder(root->right);
        cout << root->idAPBD << " - " << root->namaProgram << endl;
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
