#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

struct node {
    int id;
    char name[10];
    node* prev;
};

class Stack {
private:
    node* tos;

public:
    Stack() {
        tos = NULL;
    }

    // Push Function
    void push(int id, char* name) {
        node* temp = new node();
        temp->id = id;
        strcpy(temp->name, name);
        temp->prev = tos;
        tos = temp;
    }

    // Pop Function
    node pop() {
        node res;
        res.id = -1;
        if (tos != NULL) {
            res.id = tos->id;
            strcpy(res.name, tos->name);
            node* temp = tos;
            tos = tos->prev;
            delete temp;
        }
        return res;
    }

    // Is Empty
    int isEmpty() {
        if (tos == NULL)
            return 1;
        else
            return 0;
    }

    // Is Full
    int isFull() {
        node* temp = new node();
        if (temp == NULL) {

            return 1;
        } else {
            delete temp;
            return 0;
        }
    }

     ~Stack() {
        cout << "Destructor is here" << endl;
    }

};

int main() {
    Stack c1;
    c1.push(1, "Haidy");
    c1.push(2, "Essam");

    node poppedNode = c1.pop();
    cout << "Popped Node: " << poppedNode.id << "," << poppedNode.name << endl;
    node popped = c1.pop();
    cout << "Popped: " << popped.id << "," << popped.name << endl;

    return 0;
}
