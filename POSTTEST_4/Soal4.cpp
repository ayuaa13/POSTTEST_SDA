#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* current = head_ref; // 1. Gunakan pointer current mulai dari head_ref

    // Kasus 2: Data baru lebih kecil dari head (sisipkan di awal)
    if (data < head_ref->data) {            // 1. Jika data < head_ref->data, sisipkan sebelum head dan update head_ref
        Node* tail = head_ref->prev;
        newNode->next = head_ref;
        newNode->prev = tail;                   
        tail->next = newNode;
        head_ref->prev = newNode;
        head_ref = newNode;
        return;
    }                               

    // Kasus 3: Cari posisi yang tepat (tengah/akhir)
    while (current->next != head_ref && current->next->data < data) {  // 2. Loop: while (current->next != head_ref && current->next->data < data)                                    
        current = current->next;                            
    }

    newNode->next = current->next;      // 3. Setelah loop, sisipkan newNode setelah current
    newNode->prev = current;
    current->next->prev = newNode;      // 4. Pastikan update semua pointer next dan prev dengan benar
    current->next = newNode;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    // Expected output: 10 20 30 40
    printList(head); 
    return 0;
}
