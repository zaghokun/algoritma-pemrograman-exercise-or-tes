#include <iostream>
#include <vector>
using namespace std;

struct Menu
{
    string nama_menu;
    float harga;
};

struct Item_pembelian
{
    string nama_menu;
    int qty;
};

struct Data_pembelian
{
    int id_customer;
    string nama_customer;
    vector<Item_pembelian> items;
};

int main(){
vector<Menu> menu_resto;
    vector<Data_pembelian> data_beli;

    Menu menu01,menu02,menu03;
    bool lanjut = true;
    int pilihan;
    Menu tmpmenu;
    Data_pembelian tmpbeli;
    Item_pembelian tmpitem;
    bool lanjut_tambah_beli;
    string is_lanjut_tambah_beli;
    float tmpharga;
    float total;
    int id_cari;

    menu01.nama_menu = "Nasi Goreng";
    menu01.harga = 10000;
    menu_resto.push_back(menu01);
    
    menu02.nama_menu = "Sate Ayam";
    menu02.harga = 15000;
    menu_resto.push_back(menu02);
    
    menu03.nama_menu = "Salad";
    menu03.harga = 13000;
    menu_resto.push_back(menu03);
    
    while(lanjut){
        cout << "Menu Aplikasi" << endl;
        cout << "1. Tambah Menu Baru" << endl;
        cout << "2. Tampilkan Menu" << endl;
        cout << "3. Tambah Pembelian" << endl;
        cout << "4. Tampilkan Pembelian" << endl;
        cout << "5. Edit Harga Menu" << endl;
        cout << "6. Tambah Item pada Pembelian" << endl;
        cout << "9. Exit" << endl;
        
        cout << "Pilih Menu: ";
        cin >> pilihan;
        
        if(pilihan == 9){
            lanjut = false;
        } else if(pilihan == 1){
          cout << "Nama menu: ";
          cin.ignore();
          getline(cin,tmpmenu.nama_menu);
          cout << "Harga: ";
          cin >> tmpmenu.harga;
          menu_resto.push_back(tmpmenu);
        } else if(pilihan == 2){
            cout << "---------------------------------" << endl;
            cout << "Daftar Menu Restoran" << endl;
            cout << "---------------------------------" << endl;
            for(Menu m : menu_resto){
                cout << "Menu: " << m.nama_menu << endl;
                cout << "Harga: " << m.harga << endl;
                cout << "---------------------------------" << endl;
            }
        } else if (pilihan == 3){
            cout << "ID Customer: ";
            cin >> tmpbeli.id_customer;
            cin.ignore();
            cout << "Nama Customer: ";
            getline(cin, tmpbeli.nama_customer);
            
            lanjut_tambah_beli = true;
            while(lanjut_tambah_beli){
                cout << "Menu yg dibeli: ";
                getline(cin, tmpitem.nama_menu);
                cout << "Qty: ";
                cin >> tmpitem.qty;
                cin.ignore();
                
                tmpbeli.items.push_back(tmpitem);
                
                cout << "Sudah? (y/n): ";
                getline(cin, is_lanjut_tambah_beli);
                if(is_lanjut_tambah_beli == "y"){
                    lanjut_tambah_beli = false;
                    data_beli.push_back(tmpbeli);
                }
            }
        } else if(pilihan == 4){
            for(Data_pembelian dp : data_beli){
                cout << "ID Customer: " << dp.id_customer << endl;
                cout << "Nama Customer: " << dp.nama_customer << endl;
                cout << "Item yang dibeli: " << endl;
                total = 0;
                for(Item_pembelian ip : dp.items){
                    cout << " - " << ip.nama_menu << ", qty: " << ip.qty;
                    tmpharga = 0;
                    for(Menu m : menu_resto){
                        if(m.nama_menu == ip.nama_menu){
                            tmpharga = m.harga;
                            break;
                        }
                    }
                    if(tmpharga > 0){
                        cout << ", harga: " << tmpharga;
                        total += ip.qty*tmpharga;
                    } else {
                        cout << "(menu tidak ditemukan)";
                    }
                    cout << endl;
                }
                cout << "Total Harga: " << total << endl;
                cout << "---------------------------------------" << endl;
            }
        } else if (pilihan == 5) {
            cout << "Nama menu yang ingin diubah harganya: ";
            string nama_cari;
            cin.ignore();
            getline(cin, nama_cari);
            bool ditemukan = false;
            for (Menu &m : menu_resto) {
                if (m.nama_menu == nama_cari) {
                    cout << "Masukan Harga baru: ";
                    cin >> m.harga;
                    cout << "Harga berhasil diubah!" << endl;
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) {
                cout << "Menu tidak ditemukan!" << endl;
            }
        } else if (pilihan == 6) {
            cout << "Masukkan ID Customer: ";
            cin >> id_cari;
            bool ditemukan = false;
            for (Data_pembelian &dp : data_beli) {
                if (dp.id_customer == id_cari) {
                    ditemukan = true;
                    cout << "Tambah item baru untuk customer " << dp.nama_customer << endl;
                    lanjut_tambah_beli = true;
                    while (lanjut_tambah_beli) {
                        cout << "Menu yang mau ditambahkan: ";
                        cin.ignore();
                        getline(cin, tmpitem.nama_menu);
                        cout << "Qty: ";
                        cin >> tmpitem.qty;
                        dp.items.push_back(tmpitem);
                        cout << "Tambah lagi? (y/n): ";
                        cin >> is_lanjut_tambah_beli;
                        if (is_lanjut_tambah_beli == "n") {
                            lanjut_tambah_beli = false;
                        }
                    }
                    break;
                }
            }
            if (!ditemukan) {
                cout << "Customer dengan ID tersebut tidak ditemukan!" << endl;
            }
        }
    }
    
    return 0;
}
