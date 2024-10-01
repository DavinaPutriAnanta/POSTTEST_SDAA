#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Workout {
    string namaWorkout;
    int durasiMenit; 
    int kaloriTerbakar;
    string hari; 
    string minggu; 
    Workout* next; 
};

Workout* head = nullptr;
void tambahWorkout() {
    Workout* newWorkout = new Workout(); 
    cin.ignore();
    cout << "Masukkan Nama Workout: ";
    getline(cin, newWorkout->namaWorkout);

    cout << "Masukkan Durasi (menit): ";
    while (true) {
        cin >> newWorkout->durasiMenit;
        if (cin.fail() || newWorkout->durasiMenit <= 0) {
            cout << "Input tidak valid! Masukkan durasi yang positif: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    cout << "Masukkan Kalori yang Terbakar: ";
    while (true) {
        cin >> newWorkout->kaloriTerbakar;
        if (cin.fail() || newWorkout->kaloriTerbakar < 0) {
            cout << "Input tidak valid! Masukkan kalori yang tidak negatif: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    cin.ignore();
    cout << "Masukkan Hari (contoh: Senin): ";
    getline(cin, newWorkout->hari);

    cout << "Masukkan Minggu (contoh: Minggu 1): ";
    getline(cin, newWorkout->minggu);

    newWorkout->next = head;
    head = newWorkout; 

    cout << "Workout berhasil ditambahkan!" << endl;
}
void tampilkanWorkout() {
    if (head == nullptr) {
        cout << "Belum ada program workout." << endl;
    } else {
        Workout* current = head;
        int count = 1;
        cout << "\nDaftar Workout:\n";
        while (current != nullptr) {
            cout << "Workout " << count << ": " << endl;
            cout << "Nama: " << current->namaWorkout << endl;
            cout << "Durasi: " << current->durasiMenit << " menit" << endl;
            cout << "Kalori Terbakar: " << current->kaloriTerbakar << endl;
            cout << "Hari: " << current->hari << endl;
            cout << "Minggu: " << current->minggu << endl;
            cout << "------------------------" << endl;
            current = current->next; 
            count++;
        }
    }
}
void hapusWorkout(int index) {
    if (head == nullptr) {
        cout << "Tidak ada workout untuk dihapus." << endl;
        return;
    }

    Workout* temp = head;
    if (index == 0) {
        head = head->next; 
        delete temp;
        cout << "Workout berhasil dihapus!" << endl;
        return;
    }
    Workout* prev = nullptr;
    for (int i = 0; temp != nullptr && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Indeks tidak valid!" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Workout berhasil dihapus!" << endl;
}
void updateWorkout(int index) {
    Workout* current = head;
    for (int i = 0; current != nullptr && i < index; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Indeks tidak valid!" << endl;
        return;
    }

    cin.ignore();
    cout << "Update Nama Workout: ";
    getline(cin, current->namaWorkout);

    cout << "Update Durasi (menit): ";
    while (true) {
        cin >> current->durasiMenit;
        if (cin.fail() || current->durasiMenit <= 0) {
            cout << "Input tidak valid! Masukkan durasi yang positif: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    cout << "Update Kalori yang Terbakar: ";
    while (true) {
        cin >> current->kaloriTerbakar;
        if (cin.fail() || current->kaloriTerbakar < 0) {
            cout << "Input tidak valid! Masukkan kalori yang tidak negatif: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    cin.ignore();
    cout << "Update Hari (contoh: Senin): ";
    getline(cin, current->hari);

    cout << "Update Minggu (contoh: Minggu 1): ";
    getline(cin, current->minggu);

    cout << "Workout berhasil diupdate!" << endl;
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
                    if (cin.fail() || indexUpdate < 1) {
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
                    if (cin.fail() || indexHapus < 1) {
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
