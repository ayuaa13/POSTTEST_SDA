#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0'; 
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    for (char c : s) {
        push(stackTop, c);   // 1. Push setiap karakter dari string s ke dalam stack.
    }

    while (stackTop != nullptr) {
        reversed += pop(stackTop);  // 2. Pop setiap karakter dari stack dan tambahkan ke string `reversed`.
    }
    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; 
    // Output: ataD rutkurtS
    return 0;
}
