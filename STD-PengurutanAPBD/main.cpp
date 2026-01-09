#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    adrNode root;
    createTree_APBD(root);
    loadSampleAPBD(root);

    int pilihan;
    do {
        cout << "\n=== SISTEM PENGURUTAN APBD (BST) ===\n";
        cout << "1. Cari Program APBD\n";
        cout << "2. Tampilkan Inorder (Terurut)\n";
        cout << "3. Tampilkan Preorder\n";
        cout << "4. Tampilkan Postorder\n";
        cout << "5. Jumlah Program APBD\n";
        cout << "6. Total Anggaran APBD\n";
        cout << "7. Anggaran Terkecil\n";
        cout << "8. Anggaran Terbesar\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int id;
                cout << "Masukkan Unique ID: ";
                cin >> id;
                adrNode p = searchNode_APBD(root, id);
                if (p) {
                    cout << "Kab/Kota : " << p->kabupatenKota << endl;
                    cout << "Program  : " << p->namaProgram << endl;
                    cout << "Anggaran : Rp " << p->anggaran << " M\n";
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }
            case 2: tampilInorder_APBD(root); break;
            case 3: tampilPreorder_APBD(root); break;
            case 4: tampilPostorder_APBD(root); break;
            case 5:
                cout << "Jumlah program APBD: "
                     << countProgram_APBD(root) << endl;
                break;
            case 6:
                cout << "Total anggaran APBD: Rp "
                     << totalAnggaran_APBD(root) << " M\n";
                break;
            case 7:
                cout << "Anggaran terkecil: Rp "
                     << getMinAnggaran_APBD(root) << " M\n";
                break;
            case 8:
                cout << "Anggaran terbesar: Rp "
                     << getMaxAnggaran_APBD(root) << " M\n";
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
