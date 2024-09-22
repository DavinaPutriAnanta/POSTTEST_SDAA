#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Struct untuk mendefinisikan data workout
struct Workout {
    string namaWorkout;
    int durasiMenit; // Durasi dalam menit
    int kaloriTerbakar;
    string hari; // Menyimpan hari workout
    string minggu; // Menyimpan minggu workout
};

// Maksimum jumlah program workout yang bisa dimasukkan
const int MAX_WORKOUT = 100;

// Deklarasi array
Workout daftarWorkout[MAX_WORKOUT];
int jumlahWorkout = 0;

// Prosedur untuk menambahkan program workout
void tambahWorkout() {
    if (jumlahWorkout < MAX_WORKOUT) {
        cout << "Masukkan Nama Workout: ";
        cin.ignore();
        getline(cin, daftarWorkout[jumlahWorkout].namaWorkout);
        
        cout << "Masukkan Durasi (menit): ";
        while (true) {
            cin >> daftarWorkout[jumlahWorkout].durasiMenit;
            if (cin.fail() || daftarWorkout[jumlahWorkout].durasiMenit <= 0) {
                cout << "Input tidak valid! Masukkan durasi yang positif: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        cout << "Masukkan Kalori yang Terbakar: ";
        while (true) {
            cin >> daftarWorkout[jumlahWorkout].kaloriTerbakar;
            if (cin.fail() || daftarWorkout[jumlahWorkout].kaloriTerbakar < 0) {
                cout << "Input tidak valid! Masukkan kalori yang tidak negatif: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        cout << "Masukkan Hari (contoh: Senin): ";
        cin.ignore();
        getline(cin, daftarWorkout[jumlahWorkout].hari);
        
        cout << "Masukkan Minggu (contoh: Minggu 1): ";
        getline(cin, daftarWorkout[jumlahWorkout].minggu);

        jumlahWorkout++;
        cout << "Workout berhasil ditambahkan!" << endl;
    } else {
        cout << "Tidak bisa menambah lagi, daftar sudah penuh!" << endl;
    }
}

// Fungsi untuk menampilkan semua workout
void tampilkanWorkout() {
    if (jumlahWorkout == 0) {
        cout << "Belum ada program workout." << endl;
    } else {
        cout << "\nDaftar Workout:\n";
        for (int i = 0; i < jumlahWorkout; i++) {
            cout << "Workout " << i + 1 << ": " << endl;
            cout << "Nama: " << daftarWorkout[i].namaWorkout << endl;
            cout << "Durasi: " << daftarWorkout[i].durasiMenit << " menit" << endl;
            cout << "Kalori Terbakar: " << daftarWorkout[i].kaloriTerbakar << endl;
            cout << "Hari: " << daftarWorkout[i].hari << endl;
            cout << "Minggu: " << daftarWorkout[i].minggu << endl;
            cout << "------------------------" << endl;
        }
    }
}

// Prosedur untuk menghapus workout berdasarkan index
void hapusWorkout(int index) {
    if (index >= 0 && index < jumlahWorkout) {
        for (int i = index; i < jumlahWorkout - 1; i++) {
            daftarWorkout[i] = daftarWorkout[i + 1];
        }
        jumlahWorkout--;
        cout << "Workout berhasil dihapus!" << endl;
    } else {
        cout << "Indeks tidak valid!" << endl;
    }
}

// Fungsi untuk mengupdate workout berdasarkan index
void updateWorkout(int index) {
    if (index >= 0 && index < jumlahWorkout) {
        cout << "Update Nama Workout: ";
        cin.ignore();
        getline(cin, daftarWorkout[index].namaWorkout);
        
        cout << "Update Durasi (menit): ";
        while (true) {
            cin >> daftarWorkout[index].durasiMenit;
            if (cin.fail() || daftarWorkout[index].durasiMenit <= 0) {
                cout << "Input tidak valid! Masukkan durasi yang positif: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        cout << "Update Kalori yang Terbakar: ";
        while (true) {
            cin >> daftarWorkout[index].kaloriTerbakar;
            if (cin.fail() || daftarWorkout[index].kaloriTerbakar < 0) {
                cout << "Input tidak valid! Masukkan kalori yang tidak negatif: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        cout << "Update Hari (contoh: Senin): ";
        cin.ignore();
        getline(cin, daftarWorkout[index].hari);
        
        cout << "Update Minggu (contoh: Minggu 1): ";
        getline(cin, daftarWorkout[index].minggu);

        cout << "Workout berhasil diupdate!" << endl;
    } else {
        cout << "Indeks tidak valid!" << endl;
    }
}

int main() {
    int pilihan;
    do {
        cout << "\nProgram Manajemen Workout Wanita" << endl;
        cout << "1. Tambah Workout" << endl;
        cout << "2. Tampilkan Semua Workout" << endl;
        cout << "3. Update Workout" << endl;
        cout << "4. Hapus Workout" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";

        while (true) {
            cin >> pilihan;
            if (cin.fail() || pilihan < 1 || pilihan > 5) {
                cout << "Pilihan tidak valid! Masukkan pilihan antara 1 hingga 5: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        switch (pilihan) {
            case 1:
                tambahWorkout();
                break;
            case 2:
                tampilkanWorkout();
                break;
            case 3: {
                int indexUpdate;
                cout << "Masukkan indeks workout yang akan diupdate: ";
                while (true) {
                    cin >> indexUpdate;
                    if (cin.fail() || indexUpdate < 1 || indexUpdate > jumlahWorkout) {
                        cout << "Indeks tidak valid! Masukkan indeks yang benar: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        break;
                    }
                }
                updateWorkout(indexUpdate - 1);
                break;
            }
            case 4: {
                int indexHapus;
                cout << "Masukkan indeks workout yang akan dihapus: ";
                while (true) {
                    cin >> indexHapus;
                    if (cin.fail() || indexHapus < 1 || indexHapus > jumlahWorkout) {
                        cout << "Indeks tidak valid! Masukkan indeks yang benar: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        break;
                    }
                }
                hapusWorkout(indexHapus - 1);
                break;
            }
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
