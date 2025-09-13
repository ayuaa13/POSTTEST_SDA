#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 4;
    Mahasiswa mhs[N];

    // Input data mahasiswa
    for (int i = 0; i < N; i++) {
        cout << "Input data mahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "IPK: ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    // Sorting berdasarkan IPK (ascending)
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (mhs[i].ipk > mhs[j].ipk) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }

    // Tampilkan data setelah diurutkan
    cout << "\nData Mahasiswa setelah diurutkan berdasarkan IPK (ascending):\n";
    for (int i = 0; i < N; i++) {
        cout << i+1 << ". " << mhs[i].nama 
             << " | NIM: " << mhs[i].nim 
             << " | IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}