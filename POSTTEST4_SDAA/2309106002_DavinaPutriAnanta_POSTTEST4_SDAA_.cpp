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

Workout* stackTop = nullptr;

void pushWorkout() {
    Workout* newWorkout = new Workout();
    cin.ignore();
    cout << "Masukkan Nama Workout (Stack): ";
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
    cout << "Masukkan Hari: ";
    getline(cin, newWorkout->hari);

    cout << "Masukkan Minggu: ";
    getline(cin, newWorkout->minggu);

    newWorkout->next = stackTop;
    stackTop = newWorkout;

    cout << "Workout berhasil ditambahkan ke Stack!" << endl;
}

void popWorkout() {
    if (stackTop == nullptr) {
        cout << "Stack kosong!" << endl;
    } else {
        Workout* temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
        cout << "Workout berhasil dihapus dari Stack!" << endl;
    }
}

void lihatStack() {
    if (stackTop == nullptr) {
        cout << "Stack kosong!" << endl;
    } else {
        Workout* current = stackTop;
        int count = 1;
        cout << "\nDaftar Workout di Stack:\n";
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

void editStack(int index) {
    Workout* current = stackTop;
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
    cout << "Update Hari: ";
    getline(cin, current->hari);

    cout << "Update Minggu: ";
    getline(cin, current->minggu);

    cout << "Workout berhasil diupdate di Stack!" << endl;
}
Workout* queueFront = nullptr;
Workout* queueRear = nullptr;

void enqueueWorkout() {
    Workout* newWorkout = new Workout();
    cin.ignore();
    cout << "Masukkan Nama Workout (Queue): ";
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
    cout << "Masukkan Hari: ";
    getline(cin, newWorkout->hari);

    cout << "Masukkan Minggu: ";
    getline(cin, newWorkout->minggu);

    newWorkout->next = nullptr;
    if (queueRear == nullptr) {
        queueFront = queueRear = newWorkout;
    } else {
        queueRear->next = newWorkout;
        queueRear = newWorkout;
    }

    cout << "Workout berhasil ditambahkan ke Queue!" << endl;
}

void dequeueWorkout() {
    if (queueFront == nullptr) {
        cout << "Queue kosong!" << endl;
    } else {
        Workout* temp = queueFront;
        queueFront = queueFront->next;
        if (queueFront == nullptr) {
            queueRear = nullptr;
        }
        delete temp;
        cout << "Workout berhasil dihapus dari Queue!" << endl;
    }
}

void lihatQueue() {
    if (queueFront == nullptr) {
        cout << "Queue kosong!" << endl;
    } else {
        Workout* current = queueFront;
        int count = 1;
        cout << "\nDaftar Workout di Queue:\n";
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

void editQueue(int index) {
    Workout* current = queueFront;
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
    cout << "Update Hari: ";
    getline(cin, current->hari);

    cout << "Update Minggu: ";
    getline(cin, current->minggu);

    cout << "Workout berhasil diupdate di Queue!" << endl;
}

void menuStack() {
    int pilihanStack;
    do {
        cout << "\nSubmenu Stack\n";
        cout << "1. Tambah Workout ke Stack" << endl;
        cout << "2. Hapus Workout dari Stack" << endl;
        cout << "3. Lihat Stack" << endl;
        cout << "4. Edit Workout di Stack" << endl;
        cout << "5. Kembali ke Menu Utama" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihanStack;

        switch (pilihanStack) {
            case 1:
                pushWorkout();
                break;
            case 2:
                popWorkout();
                break;
            case 3:
                lihatStack();
                break;
            case 4: {
                int indexStack;
                cout << "Masukkan indeks workout yang ingin diedit (mulai dari 0): ";
                cin >> indexStack;
                editStack(indexStack);
                break;
            }
            case 5:
                cout << "Kembali ke Menu Utama." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihanStack != 5);
}

void menuQueue() {
    int pilihanQueue;
    do {
        cout << "\nSubmenu Queue\n";
        cout << "1. Tambah Workout ke Queue" << endl;
        cout << "2. Hapus Workout dari Queue" << endl;
        cout << "3. Lihat Queue" << endl;
        cout << "4. Edit Workout di Queue" << endl;
        cout << "5. Kembali ke Menu Utama" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihanQueue;

        switch (pilihanQueue) {
            case 1:
                enqueueWorkout();
                break;
            case 2:
                dequeueWorkout();
                break;
            case 3:
                lihatQueue();
                break;
            case 4: {
                int indexQueue;
                cout << "Masukkan indeks workout yang ingin diedit (mulai dari 0): ";
                cin >> indexQueue;
                editQueue(indexQueue);
                break;
            }
            case 5:
                cout << "Kembali ke Menu Utama." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihanQueue != 5);
}

int main() {
    int pilihan;
    do {
        cout << "\nProgram Manajemen Workout Wanita" << endl;
        cout << "1. Kelola Stack" << endl;
        cout << "2. Kelola Queue" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuStack();
                break;
            case 2:
                menuQueue();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 3);

    return 0;
}
