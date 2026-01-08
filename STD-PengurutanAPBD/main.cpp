#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    adrNode root;
    createTree_APBD(root);

    int pilihan;

    do {
        cout << "\n=== SISTEM PENGURUTAN APBD BERDASARKAN UNIQUE ID ===\n";
        cout << "1. Tambah Program/Kegiatan APBD\n\n";
        cout << "2. Cari Program APBD \n";
        cout << "3. Tampilkan APBD Terurut \n";
        cout << "4. Jumlah Program APBD\n";
        cout << "5. Total Anggaran APBD\n";
        cout << "6. Unique ID Terkecil\n";
        cout << "7. Unique ID Terbesar\n";
        cout << "0. Keluar\n\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int id;
                string nama, jenis;
                double anggaran;

                cout << "Unique ID (Kode Program APBD): ";
                cin >> id;

                if (!isUniqueID_APBD(root, id)) {
                    cout << "ID sudah digunakan. Harus unik.\n";
                    break;
                }

                cin.ignore();
                cout << "Nama Program: ";
                getline(cin, nama);

                cout << "Jenis Belanja: ";
                getline(cin, jenis);

                cout << "Anggaran (juta): ";
                cin >> anggaran;

                insertNode_APBD(root,
                    createNode_APBD(id, nama, jenis, anggaran));

                cout << "Data APBD berhasil ditambahkan.\n";
                break;
            }

            case 2: {
                int id;
                cout << "Masukkan Unique ID: ";
                cin >> id;

                adrNode p = searchNode_APBD(root, id);
                if (p != nullptr) {
                    cout << "Program: " << p->namaProgram << endl;
                    cout << "Jenis: " << p->jenisBelanja << endl;
                    cout << "Anggaran: Rp " << p->anggaran << " M\n";
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }

            case 3:
                if (root == nullptr)
                    cout << "Data APBD masih kosong.\n";
                else
                    tampilUrutAPBD_Inorder(root);
                break;

            case 4:
                cout << "Jumlah program APBD: "
                     << countProgram_APBD(root) << endl;
                break;

            case 5:
                cout << "Total anggaran APBD: Rp "
                     << totalAnggaran_APBD(root) << " M\n";
                break;

            case 6:
                if (root != nullptr)
                    cout << "Unique ID terkecil: "
                         << getMinID_APBD(root) << endl;
                break;

            case 7:
                if (root != nullptr)
                    cout << "Unique ID terbesar: "
                         << getMaxID_APBD(root) << endl;
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
