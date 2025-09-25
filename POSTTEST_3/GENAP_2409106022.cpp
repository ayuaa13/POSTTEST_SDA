#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Penerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    Penerbangan* next;
    Penerbangan* prev;
};

Penerbangan* head = nullptr;
Penerbangan* tail = nullptr;

// Variabel global
string nama = "AYU";
string nim = "022";
int counter = 1; // untuk generate kode penerbangan

// Membuat kode penerbangan otomatis berdasarkan NIM
string generateKode() {
    string kode = "JT-" + nim;
    if (counter > 1) kode += "-" + to_string(counter - 1);
    return kode;
}

// Tambah di akhir
void tambahPenerbangan(string tujuan, string status) {
    Penerbangan* baru = new Penerbangan;
    baru->kodePenerbangan = generateKode();
    baru->tujuan = tujuan;
    baru->status = status;
    baru->next = nullptr;
    baru->prev = nullptr;

    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    counter++;
    cout << "Jadwal penerbangan berhasil ditambahkan.\n";
}

// Sisip di posisi ke-3 (khusus NIM 022)
void sisipPenerbangan(string tujuan, string status) {
    int posisi = 3;
    Penerbangan* baru = new Penerbangan;
    baru->kodePenerbangan = generateKode();
    baru->tujuan = tujuan;
    baru->status = status;
    baru->next = nullptr;
    baru->prev = nullptr;

    if (head == nullptr || posisi == 1) {
        baru->next = head;
        if (head != nullptr) head->prev = baru;
        head = baru;
        if (tail == nullptr) tail = baru;
    } else {
        Penerbangan* temp = head;
        int pos = 1;
        while (temp->next != nullptr && pos < posisi - 1) {
            temp = temp->next;
            pos++;
        }
        baru->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = baru;
        temp->next = baru;
        baru->prev = temp;
        if (baru->next == nullptr) tail = baru;
    }
    counter++;
    cout << "Jadwal penerbangan berhasil disisipkan di posisi " << posisi << ".\n";
}

// Hapus jadwal paling awal
void hapusAwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal.\n";
        return;
    }
    Penerbangan* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    cout << "Jadwal penerbangan paling awal berhasil dihapus.\n";
}

// Update status penerbangan
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

// Tampilkan semua jadwal dalam bentuk tabel (dari depan)
void tampilkanJadwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal.\n";
        return;
    }

    cout << "\n=============================================================\n";
    cout << "                     DAFTAR JADWAL PENERBANGAN              \n";
    cout << "=============================================================\n";
    cout << left << setw(5) << "| No"
         << setw(15) << "| Kode"
         << setw(25) << "| Tujuan"
         << setw(20) << "| Status"
         << "|\n";
    cout << "-------------------------------------------------------------\n";

    Penerbangan* temp = head;
    int no = 1;
    while (temp != nullptr) {
        cout << left << setw(5) << ("| " + to_string(no))
             << setw(15) << ("| " + temp->kodePenerbangan)
             << setw(25) << ("| " + temp->tujuan)
             << setw(20) << ("| " + temp->status)
             << "|\n";
        temp = temp->next;
        no++;
    }
    cout << "=============================================================\n";
}

// Tampilkan semua jadwal dari belakang
void tampilkanJadwalBelakang() {
    if (tail == nullptr) {
        cout << "Tidak ada jadwal.\n";
        return;
    }

    cout << "\n=============================================================\n";
    cout << "              DAFTAR JADWAL (TRAVERSAL DARI BELAKANG)       \n";
    cout << "=============================================================\n";
    cout << left << setw(5) << "| No"
         << setw(15) << "| Kode"
         << setw(25) << "| Tujuan"
         << setw(20) << "| Status"
         << "|\n";
    cout << "-------------------------------------------------------------\n";

    Penerbangan* temp = tail;
    int no = 1;
    while (temp != nullptr) {
        cout << left << setw(5) << ("| " + to_string(no))
             << setw(15) << ("| " + temp->kodePenerbangan)
             << setw(25) << ("| " + temp->tujuan)
             << setw(20) << ("| " + temp->status)
             << "|\n";
        temp = temp->prev;
        no++;
    }
    cout << "=============================================================\n";
}

// Cari detail data berdasarkan kode atau tujuan
void cariDetail(string keyword) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal.\n";
        return;
    }
    Penerbangan* temp = head;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == keyword || temp->tujuan == keyword) {
            cout << "\n===== DETAIL DATA PENERBANGAN =====\n";
            cout << "Kode   : " << temp->kodePenerbangan << endl;
            cout << "Tujuan : " << temp->tujuan << endl;
            cout << "Status : " << temp->status << endl;
            cout << "==================================\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Data dengan kata kunci '" << keyword << "' tidak ditemukan.\n";
}

// Menu utama
void menu() {
    int pilihan;
    do {
        cout << "=================================================\n";
        cout << "|        FLIGHT SCHEDULE SYSTEM                 |\n";
        cout << "|         [" << nama << " - " << nim << "]      |\n";
        cout << "=================================================\n";
        cout << "|1. Tambah Jadwal Penerbangan                   |\n";
        cout << "|2. Sisipkan Jadwal Penerbangan                 |\n";
        cout << "|3. Hapus Jadwal Paling Awal                    |\n";
        cout << "|4. Update Status Penerbangan                   |\n";
        cout << "|5. Tampilkan Semua Jadwal (dari depan)         |\n";
        cout << "|6. Tampilkan Semua Jadwal (dari belakang)      |\n";
        cout << "|7. Cari Detail Jadwal (berdasarkan Kode/Tujuan)|\n";
        cout << "|0. Keluar                                      |\n";
        cout << "=================================================\n";
        cout << "Pilih menu:";
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
        } else if (pilihan == 6) {
            tampilkanJadwalBelakang();
        } else if (pilihan == 7) {
            string keyword;
            cout << "Masukkan Kode atau Tujuan: ";
            getline(cin, keyword);
            cariDetail(keyword);
        }
    } while (pilihan != 0);
}

int main() {
    menu();
    return 0;
}
