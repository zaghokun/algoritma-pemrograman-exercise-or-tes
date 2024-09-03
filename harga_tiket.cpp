#include <iostream>
using namespace std;

int main(){

    int A = 5;
    int B = 60;
    double a = 30000;
    double b = 40000;
    double c = 50000;

    double diskon_5_persen = 0.05;
    double G;
    double U;
    double harga;
    double total = 0;
    cout << "Jumlah pengunjung yang datang: ";
    cin >> G;

    for(int i = 1; i <= G; i++){
        cout << "Masukkan umur pengunjung: ";
        cin >> U;
        if(U < A){
            harga = a;
        }else if(U > B){
            harga = b;
        }else{
            harga = c;
        }
        total += harga;
    }

    if(G > 5){
        double harga_diskon = total * diskon_5_persen;
        double setelah_diskon = total - harga_diskon;
        cout << "Total harga tiket = " << setelah_diskon << endl;
    }else{
        cout << "Total harga tiket = " << total << endl;
    }
}
