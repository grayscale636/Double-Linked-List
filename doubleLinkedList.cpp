#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};
    Node* head;
    Node* tail;
    Node* node = new Node();
    Node* hapus;
    Node* bantu;
    Node* bantu2;

//Node *head, *tail;
void initial();
int isEmpty();
void insertDepan(int d);
void insertBelakang(int d);
void insertTengah(int d, int s);
void print();
void hapusDepan();
void hapusBelakang();
void hapusTengah(int s);
void clearList();

void initial() {
    head = tail = NULL;
}

int isEmpty() {
    if(head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void insertDepan(int d) {
    Node *baru = new Node;
    baru -> data = d;
    baru -> next = NULL;
    baru -> prev = NULL;
    if(isEmpty() == 1) {
        head = tail = baru;
        head -> next = NULL;
        head -> prev = NULL;
        tail -> next = NULL;
        tail -> prev = NULL;
    }
    else {
        baru -> next = head;
        head -> prev = baru;
        head = baru;
    }
}

void insertBelakang(int d) {
    Node *baru = new Node;
    baru -> data = d;
    baru -> next = NULL;
    baru -> prev = NULL;
    if(isEmpty() == 1) {
        head = tail = baru;
        head -> next = NULL;
        head -> prev = NULL;
        tail -> next = NULL;
        tail -> prev = NULL;
    }
    else {
        tail -> next = baru;
        baru -> prev = tail;
        tail = baru;
        tail -> next = NULL;
    }
}

void insertTengah(int d, int s) {
    Node *baru, *bantu, *bantu2;
    baru = new Node;
    baru -> data = d;
    baru -> next = NULL;
    baru -> prev = NULL;
    bantu = head;

    while(bantu -> data != s) {
        bantu = bantu -> next;
    }

    bantu2 = bantu -> next;
    baru -> next = bantu2;
    bantu2 -> prev = baru;
    bantu -> next = baru;
    baru -> prev = bantu;
}

void print() {
    Node *bantu;
    bantu = head;
    cout << "Berikut adalah data anda: " << endl;
    if(isEmpty() == 0) {
       while(bantu != NULL) {
            cout << bantu -> data << " ";
            bantu = bantu -> next;
       }
       cout << endl;
    }
    else {
        cout << "Data pada Linked List masih kosong" << endl;
    }
}

void hapusDepan() {
    if(isEmpty() == 0) {
        if(head -> next != NULL) {
        Node *hapus = head;
        head = head -> next;
        head -> prev = NULL;
        cout << hapus -> data << " berhasil dihapus";
        delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "Data pada Linked List masih kosong" << endl;
    }
}

void hapusBelakang() {
    if(isEmpty() == 0) {
        if(head -> next != NULL) {
            Node *hapus = tail;
            tail = tail -> prev;
            tail -> next = NULL;
            cout << hapus -> data << " berhasil dihapus";
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "Data pada Linked List masih kosong" << endl;
    }
}

void hapusTengah(int s) {
    Node *hapus, *bantu, *bantu2;
    hapus =head;

    while(hapus -> data != s) {
        hapus = hapus -> next;
    }
    bantu2 = hapus -> next;
    bantu = hapus -> prev;
    bantu -> next = bantu2;
    bantu2 -> prev = bantu;

    printf("data terhapus\n");
    delete hapus;
}

void clearList() {
    Node *bantu, *hapus;
    bantu = head;
    while(bantu != NULL) {
        hapus = bantu;
        bantu = bantu -> next;
        delete hapus;
    }
    head = NULL;
}

int main() {
	int pilih, d, s;
	do {
		cout << "\n 1.tambah depan"
			 << "\n 2.tambah belakang"
		 	 << "\n 3.tambah tengah"
		 	 << "\n 4.hapus depan"
		 	 << "\n 5.hapus belakang"
		 	 << "\n 6.hapus tengah"
		 	 << "\n 7.print"
		 	 << "\n 8.clear List"
		 	 << "\n 9.exit"
		 	 << "\n\n Pilih: ";
        cin >> pilih;
		switch(pilih) {
			case 1:
				cout << "Masukkan Data: " << endl;
				cin >> d;
				insertDepan(d);
				print();
				getch();
				break;

			case 2:
				cout << "Masukkan Data: " << endl;
				cin >> d;
				insertBelakang(d);
				print();
				getch();
				break;

			case 3:
				cout << "Masukkan Data: " << endl;
				cin >> d;
				print();
				cout << "Masukkan data setelah: ";
				cin >> s;
				insertTengah(d,s);
				print();
				getch();
				break;

			case 4:
				hapusDepan();
				print();
				getch();
				break;

            case 5:
				hapusBelakang();
				print();
				getch();
				break;

            case 6:
				cout << "Masukkan Data: " << endl;
				cin >> d;
				hapusTengah(d);
				print();
				getch();
				break;

            case 7:
				cout << "Berikut data pada Linked List: " << endl;
				print();
				getch();
				break;

            case 8:
				cout << "Semua data telah berhasil dihapus" << endl;
				clearList();
				getch();
				break;
			case 9:
				cout << "Terimakasih telah menggunakan program :)" << endl;
				getch;
				break;
			default:
				cout << "Pilihan anda salah" << endl;
				getch();
				break;
		}
		system("cls");
	}
	while(pilih !=9);
}




















