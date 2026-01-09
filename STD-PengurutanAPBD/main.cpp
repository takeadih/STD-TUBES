#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    adrNode root;
    createTree(root);
    loadSampleAPBD(root);

    int pilihan;
    do {
        cout << "\n=== SISTEM HIRARKI APBD ===\n";
        cout << "1. Tampilkan Struktur APBD\n";
        cout << "2. Traversal Preorder\n";
        cout << "3. Traversal Postorder\n";
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
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
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
