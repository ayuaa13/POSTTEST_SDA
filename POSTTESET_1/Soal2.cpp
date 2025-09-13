#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N];

    // Isi matriks 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriks[i][j] = i * N + j + 1;
        }
    }

    // Cetak matriks
    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    // Hitung jumlah elemen baris genap 
    int jumlah = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) { // baris genap
            for (int j = 0; j < N; j++) {
                jumlah += matriks[i][j];
            }
        }
    }

    cout << "\nJumlah elemen baris genap = " << jumlah << endl;

    return 0;
}
