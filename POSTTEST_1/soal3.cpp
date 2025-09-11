#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 4;
    Mahasiswa mhs[N];

    cout << "Input data mahasiswa:\n";
    for (int i = 0; i < N; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;

        cout << "Nama: ";
        getline(cin, mhs[i].nama);

        cout << "NIM: ";
        getline(cin, mhs[i].nim);

        cout << "IPK: ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (mhs[j].ipk > mhs[j+1].ipk) {
                swap(mhs[j], mhs[j+1]);
            }
        }
    }

    cout << "\nData mahasiswa setelah diurutkan berdasarkan IPK ascending:\n";
    for (int i = 0; i < N; i++) {
        cout << mhs[i].nama << " | " << mhs[i].nim << " | " << mhs[i].ipk << endl;
    }
}