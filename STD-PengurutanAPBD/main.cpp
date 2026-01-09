#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    adrNode root;
    createTree(root);
    loadSampleAPBD(root);

    int pilih;
    do {
        cout << "\n=== SISTEM HIRARKI APBD ===\n";
        cout << "1. Tampilkan Struktur Tree\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Anggaran Terkecil\n";
        cout << "5. Anggaran Terbesar\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
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
            case 4:
                cout << "Anggaran terkecil: Rp "
                     << getMinAnggaran(root) << " M\n";
                break;
            case 5:
                cout << "Anggaran terbesar: Rp "
                     << getMaxAnggaran(root) << " M\n";
                break;
        }
    } while (pilih != 0);

    return 0;
}
