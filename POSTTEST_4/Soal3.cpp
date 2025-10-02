#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};
    if (front == nullptr) {
        front = rear = newNode;                // 1. Jika queue kosong (front == nullptr), set front dan rear ke newNode
    } else {
        rear->next = newNode;
        rear = newNode;                        // 2. Jika tidak kosong, sambungkan rear->next ke newNode, lalu update rear
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong
    Node* temp = front;                     // 1. Simpan data dari front node
    string doc = temp->document;
    front = front->next;                    // 2. Geser front ke front->next
    if (front == nullptr) rear = nullptr;   // 3. Jika front menjadi nullptr, set rear juga ke nullptr
    delete temp;                            // 4. Delete node lama dan return data
    return doc;
}

void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {                  // Loop hingga queue kosong, dequeue dan print setiap dokumen
        cout << "Memproses:  " << dequeue(front, rear) << endl; // Format: "Memproses: [nama_dokumen]"
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
