#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact { //class untuk menyimpan informasi kontak (maksimal 8 kontak)
private:
    string name; //variabel untuk nama kontak
    string address; //variabel untuk alamat kontak
    string power; //variabel untuk kekuatan kontak
    string phoneNumber; //variabel untuk nomor telepon kontak

public:
    Contact(string name, string address, string power, string phoneNumber) //constructor untuk pengisian kontak
        : name(name), address(address), power(power), phoneNumber(phoneNumber) {} //penamaan disesuaikan supaya mempermudah pembacaan code

    string getName() const { //getter untuk mengambil informasi nama kontak
        return name;
    }

    void display() const {
        cout << "Name: " << name << endl; //menampilkan nama
        cout << "Address: " << address << endl; //menampilkan alamat
        cout << "Power: " << power << endl; //menampilkan kekuatan
        cout << "Phone Number: " << phoneNumber << endl; //menampilkan nomor telepon
    }
};

class PhoneBook { //class untuk menyimpan informasi yang sudah diinput melalui class contact
private:
    vector<Contact> contacts; //tempat penyimpanan utama informasi kontak yang diinput
    const size_t maxContacts = 8; //maksimal jumlah kontak yang dapat ditampung adalah 8 buah

public:
    void addContact(const Contact& contact) {
        if (contacts.size() == maxContacts) { //mengecek kapasitas kontak
            contacts.erase(contacts.begin()); //apabila sudah lebih dari 8, maka kontak paling awal akan dihapus
        }
        contacts.push_back(contact); //menambahkan kontak baru ke akhir daftar kontak
    }

    void searchContactInteractive() const {
        if (contacts.empty()) { //memeriksa apabila kontak kosong
            cout << "No contacts available." << endl; //maka tampilkan pesan ini
            return;
        }

        cout << "Available contacts:" << endl; //menampilkan daftar kontak yang tersedia
        for (const auto& contact : contacts) {
            cout << "- " << contact.getName() << endl; //mengambil sekaligus menampilkan list nama kontak yang tersedia
        }

        string name;
        cout << "\nEnter the name to view details: "; //user dapat memilih nama yang tersedia untuk ditampilkan informasi lengkapnya
        cin.ignore();
        getline(cin, name); //supaya input nama bisa mengandung spasi

        for (const auto& contact : contacts) {
            if (contact.getName() == name) {
                contact.display(); //menampilkan informasi kontak sesuai nama yang dipilih user
                return;
            }
        }
        cout << "Contact not found." << endl; //jika nama yang diinput tidak tertera dalam list, tampilkan pesan ini
    }

    void clearContacts() {
        contacts.clear(); //fungsi untuk membersihkan informasi kontak
    }
};

int main() {
    PhoneBook phoneBook; //deklarasi objek
    int choice; //deklrasi variabel yang digunakan untuk menampung angka menu pilihan

    do {
        cout << "\nPhoneBook Menu:" << endl;
        cout << "1. ADD Contact" << endl;
        cout << "2. SEARCH Contact" << endl;
        cout << "3. EXIT" << endl;
        cout << "Enter your choice: "; //menerima masukan angka dari pilihan menu
        cin >> choice;

        switch (choice) {
        case 1: { //apabila memilih menu 1. ADD
            string name, address, power, phoneNumber;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name); //menerima input nama
            cout << "Enter Address: ";
            getline(cin, address); //menerima input alamat
            cout << "Enter Power: ";
            getline(cin, power); //menerima input kekuatan
            cout << "Enter Phone Number: ";
            getline(cin, phoneNumber); //menerima input nomor telepon

            Contact newContact(name, address, power, phoneNumber); //constructor untuk pengisian kontak baru
            phoneBook.addContact(newContact); //memasukkan kontak yang baru diinput ke class
            cout << "Contact added successfully!" << endl;
            break;
        }
        case 2: { //apabila memilih menu 2. SEARCH
            phoneBook.searchContactInteractive(); //digunakan untuk mencari informasi kontak berdasarkan nama yang sudah terdaftar
            break;
        }
        case 3: //apabila memilih menu 3. EXIT 
            phoneBook.clearContacts(); //menghapus semua informasi kontak yang telah terdaftar
            cout << "Exiting program and clearing all contacts." << endl;
            break;
        default: //apabila input angka menu pilihan tidak sesuai (bukan angka 1-3)
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3); //selama user tidak memilih angka 3, maka program akan terus berjalan

    return 0;
}