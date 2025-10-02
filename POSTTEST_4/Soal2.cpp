#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// fungsi push dan pop dari soal sebelumnya.
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

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char c : expr) {                              // 1. Loop setiap karakter dalam `expr`.
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);                         // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack.
        } else if (c == ')' || c == '}' || c == ']') { // 3. Jika karakter adalah kurung tutup ')', '}', ']', cek:
            if (stackTop == nullptr) return false;      // a. Apakah stack kosong? Jika ya, return false.
            char topChar = pop(stackTop);

            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;                           // b. Pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka. Jika tidak, return false.
            }
        }
    }

    return (stackTop == nullptr);         // 4. Setelah loop selesai, jika stack kosong, return true. Jika tidak, return false.
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    return 0;
}
