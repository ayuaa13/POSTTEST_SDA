#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Penerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    Penerbangan* next;
};

Penerbangan* head = nullptr;

string nama = "AYU A.A"; 
string nim = "022"; 
int counter = 1; 

// Membuat kode penerbangan 
string generateKode() {
    string kode = "JT-" + nim;
    if (counter > 1) kode += "-" + to_string(counter - 1);
    return kode;
}

// 1. tambah penerbangan
void tambahPenerbangan(string tujuan, string status) {
    Penerbangan* baru = new Penerbangan;
    baru->kodePenerbangan = generateKode();
    baru->tujuan = tujuan;
    baru->status = status;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Penerbangan* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    counter++;
    cout << "Jadwal penerbangan berhasil ditambahkan.\n";
}

// 2. Sisip di posisi ke-3
void sisipPenerbangan(string tujuan, string status) {
    int posisi = 3;

    Penerbangan* baru = new Penerbangan;
    baru->kodePenerbangan = generateKode();
    baru->tujuan = tujuan;
    baru->status = status;
    baru->next = nullptr;

    if (head == nullptr || posisi == 1) {
        baru->next = head;
        head = baru;
    } else {
        Penerbangan* temp = head;
        int pos = 1;
        while (temp->next != nullptr && pos < posisi - 1) {
            temp = temp->next;
            pos++;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    counter++;
    cout << "Jadwal penerbangan berhasil disisipkan di posisi " << posisi << ".\n";
}

// 3. Hapus jadwal
void hapusAwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal.\n";
        return;
    }
    Penerbangan* temp = head;
    head = head->next;
    delete temp;
    cout << "Jadwal penerbangan paling awal berhasil dihapus.\n";
}

// 4. Update status penerbangan
void updateStatus(string kode, string statusBaru) {
    Penerbangan* temp = head;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            temp->status = statusBaru;
            cout << "Status penerbangan " << kode << " berhasil diperbarui.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan.\n";
}

// 5. Tampilkan semua jadwal dalam bentuk tabel
void tampilkanJadwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal.\n";
        return;
    }

    cout << "\n=============================================================\n";
    cout << "                     DAFTAR JADWAL PENERBANGAN              \n";
    cout << "=============================================================\n";
    cout << left << setw(15) << "| Kode"
         << setw(25) << "| Tujuan"
         << setw(20) << "| Status"
         << "|\n";
    cout << "-------------------------------------------------------------\n";

    Penerbangan* temp = head;
    while (temp != nullptr) {
        cout << left << setw(15) << ("| " + temp->kodePenerbangan)
             << setw(25) << ("| " + temp->tujuan)
             << setw(20) << ("| " + temp->status)
             << "|\n";
        temp = temp->next;
    }
    cout << "=============================================================\n";
}

// Menu utama
void menu() {
    int pilihan;
    do {
        cout << "\n============================================\n";
        cout << "|           FLIGHT SCHEDULE SYSTEM           |\n";
        cout << "|     [" << nama << " - " << nim << "]       |\n";
        cout << "==============================================\n";
        cout << "|1. Tambah Jadwal Penerbangan                |\n";
        cout << "|2. Sisipkan Jadwal Penerbangan              |\n";
        cout << "|3. Hapus Jadwal Paling Awal                 |\n";
        cout << "|4. Update Status Penerbangan                |\n";
        cout << "|5. Tampilkan Semua Jadwal                   |\n";
        cout << "|0. Keluar                                   |\n";
        cout << "==============================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string tujuan, status;
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status (Tepat Waktu/Terlambat/Naik Pesawat): ";
            getline(cin, status);
            tambahPenerbangan(tujuan, status);
        } else if (pilihan == 2) {
            string tujuan, status;
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status (Tepat Waktu/Terlambat/Naik Pesawat): ";
            getline(cin, status);
            sisipPenerbangan(tujuan, status);
        } else if (pilihan == 3) {
            hapusAwal();
        } else if (pilihan == 4) {
            string kode, statusBaru;
            cout << "Masukkan kode penerbangan: ";
            getline(cin, kode);
            cout << "Masukkan status baru: ";
            getline(cin, statusBaru);
            updateStatus(kode, statusBaru);
        } else if (pilihan == 5) {
            tampilkanJadwal();
        }
    } while (pilihan != 0);
}

int main() {
    menu();
    return 0;
}
