#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    adrNode root;
    createTree(root);
    loadSampleAPBD(root);

    int pilihan;
    do {
        cout << "\n=== SISTEM TREE HIRARKI APBD ===\n";
        cout << "1. Tampilkan Struktur Tree\n";
        cout << "2. Traversal Preorder\n";
        cout << "3. Traversal Inorder\n";
        cout << "4. Traversal Postorder\n";
        cout << "5. Anggaran Terkecil\n";
        cout << "6. Anggaran Terbesar\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilTree(root);
                break;
            case 2:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Anggaran terkecil: Rp "
                     << getMinAnggaran(root) << " M\n";
                break;
            case 6:
                cout << "Anggaran terbesar: Rp "
                     << getMaxAnggaran(root) << " M\n";
                break;
            case 0:
                cout << "Keluar dari sistem.\n";
                break;
            default:
                cout << "Menu tidak tersedia.\n";
        }

    } while (pilihan != 0);

    return 0;
}
