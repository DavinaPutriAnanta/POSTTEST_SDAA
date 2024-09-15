#include <iostream>
#include <iomanip> 
using namespace std;
int Pascal(int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    }
    return Pascal(baris - 1, kolom - 1) + Pascal(baris - 1, kolom);
}
void SegitigaPascal(int tingkat) {
    int LKolom = 4;
    for (int i = 0; i < tingkat; i++) {
        cout << setw((tingkat - i) * LKolom / 2); 

        for (int j = 0; j <= i; j++) {
            cout << setw(LKolom) << Pascal(i, j);
        }
        cout << endl;
    }
}

int main() {
    int tingkat = 3;
    cout << "Segitiga Pascal dengan " << tingkat << " tingkat:" << endl;
    SegitigaPascal(tingkat);
    return 0;
}
