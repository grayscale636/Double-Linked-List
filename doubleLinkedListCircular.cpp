#include <iostream>
#include <conio.h>
using namespace std;

// Prototype fungsi
void init();
int totalNode();
void addFirst(int);
void addMiddle(int, int);
void addLast(int);
void removeFirst();
void removeMiddle(int);
void removeLast();
void printList();
void clear();

// Deklarasi node
struct Node { // mendeklarasikan struct bernama node
    int data; // deklarasi data bertipe int
    Node *prev; // deklarasi pointer prev
    Node *next; // deklarasi pointer next
};

Node *head, *tail; // deklarasi pointer head dan tail

void init() { // membuat fungsi inisialisasi
    head = NULL; // membuat head bernilai null
    tail = NULL; // membuat tail bernilai null 
}

// DONE
int totalNode() { // membuat fungsi untuk menghitung banyak node
    Node *cur; // deklarasi pointer cur

    cur = head; //membuat nilai cur sama dengan head
    int total = 0; // membuat nilai total berisi 0
    do { // menggunakan do while
        cur = cur->next; // membuat nilai cur bernilai next dari cur
        total++; // melooping value total
    } while (cur != head); // ketika cur tidak sama dengan head
    return total; // kembalikan nilai total
}

// DONE
void addFirst(int value) { // membuat fungsi untuk menambahkan dari awal dengan parameter value
    Node *newNode; // deklarasi pointer newNode
    newNode = new Node(); // membuat newNode dengan menggunakan operator new

    newNode->data = value; // membuat data dari newnode berisi value
    newNode->prev = NULL; // membuat prev dari newnode bernilai NULL
    newNode->next = NULL; // mengNULL kan setelah newNode
    
    if (head == NULL) { // jika head tidak sama dengan null
        head = newNode; // membuat nilai head berisi newNode
        head->next = head; // membuat next dari head menjadi head
        head->prev = head; // membuat prev dari head menjadi head
        tail = head; // membuat tail bernilai head
    } else { // jika tidak
        newNode->prev = tail; // membuat sebelum dari newNode menjadi tail
        newNode->next = head; // membuat setelah dari newNode menjadi head
        head->prev = newNode; // membuat sebelum dari tail bernilai newNode
        tail->next = newNode; // membuat setelah dari tail bernilai newNode
        head = newNode; // membuat nilai head bernilai newNode
    }
}

// UNGUIDED
void addMiddle(int position, int value) { // membuat fungsi untuk menambah data dari tengah
    if (head != NULL) { // jika head tidak sama dengan null
        if (position == 1) { // jika position sama dengan satu
            addFirst(value); // panggil fungsi addfirst dengan parameter value 
        } else if (position == totalNode() - 1) { // jika posisi sama dengan jumlah totalNode
            addLast(value); // penggil fungsi addLast dengan parameter value
        } else if (position < 0 || position > totalNode()-1) { // jika posisi tidak masuk kedalam index
            cout << "Cannot add node. Unreachable index" << endl; // tampilkan statement
        } else { // jika tidak
            Node *newNode, *cur, *afterNode; // deklarasi pointer
            newNode = new Node(); // membuat newNode dengan menggunakan fungsi new

            newNode->data = value; // mengisi data dari newnode berisi value
            newNode->prev = NULL; // membuat prev dari newNode bernilai NULL
            newNode->next = NULL; // membuat next dari newNode bernilai NULL

            cur = head; // membuat nilai cur sama dengan head
            int index = 0; // deklarasi index bernilai 0
            while (index < position-1) { // melooping ketika index kurang dari postition-1
                cur = cur->next; // membuat cur bernilai next dari cur
                index++; // mengulang nilai index
            }

            afterNode = cur->next; // membuat nilai afterNode bernilai next dari cur
            newNode->prev = cur; // membuat prev dari newNode bernilai cur
            newNode->next = afterNode; // membuat dari newNode bernilai afterNode
            cur->next = newNode; // membuat next dari current bernilai newNode
            afterNode->prev = newNode; // membuat prev dari afterNode bernilai afterNode
        }
    } else { // jika tidak
        cout << "Cannot add any node. Empty list!" << endl; // tampilkan statement
    }
}

// DONE
void addLast(int value) { // membuat fungsi untuk menambah data dari belakang
    Node *newNode; // deklarasi newNode
    newNode = new Node(); // membuat nilai newNode menggunakan fungsi new

    newNode->data = value; // mengisi data dari newNode berisi value
    newNode->prev = NULL; // membuat NULL sebelum newNode
    newNode->next = NULL; // membuat next setelah newNode
    
    if (head == NULL) { // jika head sama dengan NULL
        head = newNode; // membuat head sama dengan newNode
        head->next = head; // membuat next dari head bernilai head
        head->prev = head; // membuat sebelum dari head bernilai head
        tail = head; // membuat tail menjadi head
    } else { // jika tidak
        newNode->prev = tail; // membuat prev dari newNode bernilai tail
        newNode->next = head; // membuat next dari newNode bernilai head
        head->prev = newNode; // membuat prev dari head menjadi newNode
		tail->next = newNode; // membuat next dari tail menjadi newNode
        tail = newNode; // membuat nilai tail sama dengan newNode
    }
}

// DONE
void removeFirst() { // membuat fungsi untuk menghapus data dari depan
    if (head != NULL) { // jika head tidak sama dengan NULL
        Node *delNode; // deklarasi delNode

        if (head->next != head) { // jika next dari head tidak sama dengan head
            delNode = head; // membuat delNode sama dengan head
            head = head->next; // membuat head sama dengan next dari head
            tail->next = head; // membuat next dari tail sama dengan head
            head->prev = tail; // membuat prev dari head sama dengan NULL
        } else { // jika tidak
            head = NULL; // membuat head sama dengan NULL
        }
    } else { // jika tidak
        cout << "Cannot remove any node. Empty list!" << endl; // tampilkan statement
    }
}

void removeLast() { // membuat fungsi untuk menghapus dari belakang
    if (head != NULL) { // jika head tidak sama dengan NULL
        Node *delNode; // deklarasi delNode

        if (tail->prev != tail) { // jika prev dari tail tidak sama dengan tail
            delNode = tail; // membuat delnode sama dengan tail
            tail = tail->prev; // membuat tail bernilai prev dari tail
            tail->next = head; // membuat next dari tail sama dengan head
            head->prev = tail; // membuat prev dari head sama dengan tail
            delete delNode; // menggunakan fungsi hapus untuk menghapus delNode
        } else { // jika tidak
            tail = NULL; // membuat tail bernilai NULL
        }
    } else { // jika tidak
        cout << "Cannot remove any node. Empty list!" << endl; // tampilkan statement
    }
}

// TODO
void removeMiddle(int position) { // membuat fungsi untuk menghapus dari tengah
    if (head != NULL) { // jika head tidak sama dengan NULL
        if (position == 0) { // jika posisi sama dengan 0
            removeFirst(); // panggil fungsi removeFirst
        } else if (position == totalNode() - 1) { // jika posisi sama dengan totalNode
            removeLast(); // panggil fungsi removeLast
        } else if (position < 0 || position > totalNode()-1) { // jika posisi tidak masuk kedalam index
            cout << "Cannot add node. Unreachable index" << endl; // tampilkan statement
        } else { // jika tidak
            Node *delNode, *cur, *afterNode; // deklarasi pointer

            cur = head; // membuat cur sama dengan head
            int index = 0; // deklarasi index bernilai 0
            while (index < position-1) { // ketika index kurang dari position -1
                cur = cur->next; // membuat cur sama dengan next dari cur
                index++; // mengulang index
            }

            delNode = cur->next; // membuat delNode bernilai next dari cur
            afterNode = delNode->next; // membuat afterNode sama dengan next dari delNode
            cur->next = afterNode; // membuat next dari cur sama dengan afterNode
            afterNode->prev = cur; // membuat prev dari afterNode bernilai cur
            delete delNode; // menghapus delNode
        }
    } else { // jika tidak
        cout << "Cannot add any node. Empty list!" << endl; // tampilkan statement
    }
}

// DONE
void printList() { // membuat fungsi untuk mencetak list
    Node *cur; // deklarasi pointer cur
    cur = head; // membuat cur sama dengan head
    do{ // menggunakan do while
        cout << "(" << cur->data << ")" << " "; // tampilkan statement
        cur = cur->next; // membuat nilai cur sama dengan next dari cur
    } while(cur != head); // ketika cur tidak sama dengan head
    cout << endl; // baris baru
}

// TODO
void clear(){ // membuat fungsi untuk membersihkan data
	Node *cur, *delNode; // deklarasi pointer
	cur = head; // membuat cur sama dengan head
	
	while(cur != head){ // ketika cur tidak sama dengan head
		delNode = cur; // membuat delNode sama dengan cur
		cur = cur-> next; // membuat cur sama dengan next dari cur
		delete delNode; // menghapus delNode
	}
	
	head = NULL; // membuat head bernilai NULL
}

int main() { // fungsi utama
	init(); // panggil fungsi init
	int pilih, value, position; // deklarasi vatiabel yang akan digunakan
	do {
		cout << "\n 1.tambah depan"
			 << "\n 2.tambah tengah"
		 	 << "\n 3.tambah belakang"
		 	 << "\n 4.hapus depan"
		 	 << "\n 5.hapus tengah"
		 	 << "\n 6.hapus belakang"
		 	 << "\n 7.cetak list"
		 	 << "\n 8.clear data"		 	 
		 	 << "\n 9.exit"
		 	 << "\n\n Pilih: ";
        cin >> pilih; // ambil inputan
		switch(pilih) { // menggunakan switch untuk menentukan pilihan
			case 1: // pilihan pertama
				cout << "Masukkan Data: " << endl;
				cin >> value; // ambil inputan user
				addFirst(value); // panggil fungsi addFirst dengan parameter value
				printList(); // panggil fungsi printList
				getch(); // untuk membaca data karakter, sehingga karakter yang dimasukkan tidak perlu dienter
				break; // hentikan perulangan

			case 2: // pilihan kedua
				cout << "Masukkan Data: " << endl;
				cin >> value; // ambil inputan user
				printList(); // panggil fungsi printList
				cout << "Data pada index ke: ";
				cin >> position; // ambil inputan dari user
				addMiddle(position ,value); // panggil fungsi addMiddle dengan parameter position dan value
				printList(); // panggil fungsi printList
				getch(); // untuk membaca data karakter, sehingga karakter yang dimasukkan tidak perlu dienter
				break; // hentikan perulangan

			case 3: // pilihan ketiga
				cout << "Masukkan Data: " << endl;
				cin >> value; // ambil inputan dari user
				addLast(value); // panggil fungsi addLast dengan parameter value
				printList(); // panggil fungsi printList
				getch(); // untuk membaca data karakter, sehingga karakter yang dimasukkan tidak perlu dienter
				break; // hentikan perulangan

			case 4:
				removeFirst(); // panggil fungsi removeFirst
				printList(); // panggil fungsi printList
				getch(); // untuk membaca data karakter, sehingga karakter yang dimasukkan tidak perlu dienter
				break; // hentikan perulangan
            
			case 5:
				cout << "Data anda adalah: "; 
				printList();
				cout << "Hapus index ke berapa: " << endl;
				cin >> position;
				removeMiddle(position); // panggil fungsi removeMiddle
				printList(); // panggil fungsi printList
				getch(); // untuk membaca data karakter, sehingga karakter yang dimasukkan tidak perlu dienter
				break; // hentikan perulangan
            
			case 6:
				removeLast(); // panggil fungsi removeList
				printList(); // panggil fungsi printList
				getch(); // untuk membaca data karakter, sehingga karakter yang dimasukkan tidak perlu dienter
				break; // hentikan perulangan

            case 7:
				printList(); // panggil fungsi printList
				getch(); // untuk membaca data karakter, sehingga karakter yang dimasukkan tidak perlu dienter
				break; // hentikan perulangan
            case 8:
				cout << "Semua data telah berhasil dihapus" << endl;
				clear(); // panggil fungsi clearList
				getch(); // untuk membaca data karakter, sehingga karakter yang dimasukkan tidak perlu dienter
				break; // hentikan perulangan
			case 9:
				cout << "Terimakasih telah menggunakan program :)" << endl;
				getch; // untuk membaca data karakter, sehingga karakter yang dimasukkan tidak perlu dienter
				break; // hentikan perulangan
			default:
				cout << "Pilihan anda salah" << endl;
				getch(); // untuk membaca data karakter, sehingga karakter yang dimasukkan tidak perlu dienter
				break; // hentukan perulangan
		}
		system("cls"); // menggunakan clearscreen dari conio.h untuk membersihkan layar setiap satu perintah
	}
	while(pilih !=9); // ketika pilih tidak sama dengan 9, dan masih ada didalam pilihan , maka program terus mengulang
}
