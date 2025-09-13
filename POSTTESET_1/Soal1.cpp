include <iostream>
using namespace std;

#include <iostream>
using namespace std;


// Fungsi membalik array dan mengembalikan pointer
int* balikArray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
    return arr; // kembalikan pointer ke array
}

int main() {
    int arr[N];

    // Isi array dengan kelipatan 3
    for (int i = 0; i < N; i++) {
        arr[i] = (i + 1) * 3;
    }

    // Tampilkan array sebelum dibalik
    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    // Panggil fungsi, kembalikan pointer
    int *hasil = balikArray(arr, N);

    // Tampilkan array sesudah dibalik
    cout << "\nArray sesudah dibalik: ";
    for (int i = 0; i < N; i++) {
        cout << hasil[i] << " ";
    }

    return 0;
}
