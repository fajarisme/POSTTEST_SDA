#include <iostream>
#include <string>
using namespace std;

struct Flight {
    string kodePenerbangan;
    string tujuan;
    string status;
    Flight* next;
};

Flight* head = nullptr;

string nama, nim;

int counterKode = 0;

string generateKode() {
    string base = "JT-030";
    if (counterKode == 0) {
        counterKode++;
        return base;
    } else {
        return base + "-" + to_string(counterKode++);
    }
}

void tambahJadwal() {
    Flight* baru = new Flight;
    baru->kodePenerbangan = generateKode();
    cout << "Masukkan tujuan penerbangan : ";
    cin.ignore();
    getline(cin, baru->tujuan);
    baru->status = "Tepat Waktu";
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Flight* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Jadwal berhasil ditambahkan dengan kode: " << baru->kodePenerbangan << endl;
}

void sisipJadwal() {
    int posisi = (nim.back() - '0') + 1;
    Flight* baru = new Flight;
    baru->kodePenerbangan = generateKode();
    cout << "Masukkan tujuan penerbangan : ";
    cin.ignore();
    getline(cin, baru->tujuan);
    baru->status = "Tepat Waktu";
    baru->next = nullptr;

    if (posisi <= 1 || head == nullptr) {
        baru->next = head;
        head = baru;
    } else {
        Flight* temp = head;
        for (int i = 1; i < posisi - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    cout << "Jadwal berhasil disisipkan di posisi " << posisi << " dengan kode: " << baru->kodePenerbangan << endl;
}

void hapusAwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal untuk dihapus." << endl;
        return;
    }
    Flight* temp = head;
    head = head->next;
    cout << "Jadwal dengan kode " << temp->kodePenerbangan << " berhasil dihapus." << endl;
    delete temp;
}

void updateStatus() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal." << endl;
        return;
    }
    string kode;
    cout << "Masukkan kode penerbangan yang ingin diupdate: ";
    cin >> kode;

    Flight* temp = head;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "Status saat ini: " << temp->status << endl;
            cout << "Masukkan status baru: ";
            cin.ignore();
            getline(cin, temp->status);
            cout << "Status berhasil diperbarui." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan." << endl;
}

void tampilkanJadwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan." << endl;
        return;
    }
    Flight* temp = head;
    cout << "\n--- DAFTAR JADWAL PENERBANGAN ---" << endl;
    while (temp != nullptr) {
        cout << "Kode: " << temp->kodePenerbangan 
             << " | Tujuan: " << temp->tujuan 
             << " | Status: " << temp->status << endl;
        temp = temp->next;
    }
}

int main() {
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    int pilihan;
    do {
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|              FLIGHT SCHEDULE SYSTEM                        |\n";
        cout << "|          [ " << nama << " - " << nim << " ]                         |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                               |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                             |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                                |\n";
        cout << "| 4. Update Status Penerbangan                               |\n";
        cout << "| 5. Tampilkan Semua Jadwal                                  |\n";
        cout << "| 0. Keluar                                                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: sisipJadwal(); break;
            case 3: hapusAwal(); break;
            case 4: updateStatus(); break;
            case 5: tampilkanJadwal(); break;
            case 0: cout << "Keluar dari program..." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}