#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    adrNode root;
    createTree_APBD(root);

    int pilihan;

    do {
        cout << "\n=== SISTEM PENGURUTAN APBD BERDASARKAN UNIQUE ID ===\n";
        cout << "1. Tambah Program APBD\n";
        cout << "2. Cari Program APBD\n";
        cout << "3. Tampilkan APBD Terurut (Inorder)\n";
        cout << "4. Tampilkan Preorder\n";
        cout << "5. Tampilkan Postorder\n";
        cout << "6. Jumlah Program APBD\n";
        cout << "7. Total Anggaran APBD\n";
        cout << "8. Unique ID Terkecil\n";
        cout << "9. Unique ID Terbesar\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1: {
            int id;
            string prov, kab, nama, jenis;
            double anggaran;

            cout << "Unique ID: ";
            cin >> id;

            if (!isUniqueID_APBD(root, id)) {
                cout << "ID sudah digunakan.\n";
                break;
            }

            cin.ignore();
            cout << "Provinsi: ";
            getline(cin, prov);
            cout << "Kabupaten/Kota: ";
            getline(cin, kab);
            cout << "Nama Program: ";
            getline(cin, nama);
            cout << "Jenis Belanja: ";
            getline(cin, jenis);
            cout << "Anggaran (juta): ";
            cin >> anggaran;

            insertNode_APBD(root,
                createNode_APBD(id, prov, kab, nama, jenis, anggaran));

            cout << "Data APBD berhasil ditambahkan.\n";
            break;
        }

        case 2: {
            int id;
            cout << "Masukkan Unique ID: ";
            cin >> id;

            adrNode p = searchNode_APBD(root, id);
            if (p != nullptr) {
                cout << p->provinsi << " - " << p->kabKota << endl;
                cout << p->namaProgram << endl;
                cout << p->jenisBelanja << endl;
                cout << "Rp " << p->anggaran << " M\n";
            } else {
                cout << "Data tidak ditemukan.\n";
            }
            break;
        }

        case 3:
            tampilUrutAPBD_Inorder(root);
            break;

        case 4:
            tampilAPBD_Preorder(root);
            break;

        case 5:
            tampilAPBD_Postorder(root);
            break;

        case 6:
            cout << "Jumlah program: "
                 << countProgram_APBD(root) << endl;
            break;

        case 7:
            cout << "Total anggaran: Rp "
                 << totalAnggaran_APBD(root) << " M\n";
            break;

        case 8:
            if (root != nullptr)
                cout << "ID terkecil: "
                     << getMinID_APBD(root) << endl;
            break;

        case 9:
            if (root != nullptr)
                cout << "ID terbesar: "
                     << getMaxID_APBD(root) << endl;
            break;
        }

    } while (pilihan != 0);

    return 0;
}
