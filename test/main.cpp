#include <iostream>
#include <string.h>
using namespace std;

struct node {
    int id;
    char name[10];
    node* next;
    node* prev;
};

class Linked {
    node* head;
    node* tail;

    node* SearchNode(int id) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->id == id)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

public:
    Linked() { head = tail = NULL; }

    void append(int id, char* name) {
        node* temp = new node();
        temp->id = id;
        strcpy(temp->name, name);
        temp->prev = NULL;
        temp->next = NULL;
        if (head == NULL) {
            head = tail = temp;
        } else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->id << " " << temp->name << endl;
            temp = temp->next;
        }
    }

    int Count() {
        int n = 0;
        node* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        return n;
    }

    node SearchById(int id) {
        node n;
        node* temp = SearchNode(id);
        if (temp != NULL) {
            n.id = temp->id;
            strcpy(n.name, temp->name);
        } else {
            n.id = -1;
        }
        return n;
    }

    void deleteById(int id) {
        node* t = SearchNode(id);
        if (t == NULL) {
            return;
        } else if (head == tail) {
            head = tail = NULL;
        } else if (t == head) {
            head = head->next;
            head->prev = NULL;
        } else if (t == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            t->prev->next = t->next;
            t->next->prev = t->prev;
        }
        delete t;
    }

    void Insert(int id, char* name) {
        node* temp = new node();
        temp->id = id;
        strcpy(temp->name, name);
        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL) {
            head = tail = temp;
        } else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }
};

int main() {
    Linked c1;
    c1.append(3, "haidy");
    c1.append(4, "soso");
    c1.display();
    cout << "Count: " << c1.Count() << endl;

    cout << "Deleting node with id 3" << endl;
    c1.deleteById(3);
    c1.display();
    cout << "Count: " << c1.Count() << endl;

    cout << "Inserting node with id 5" << endl;
    c1.Insert(5, "john");
    c1.display();
    cout << "Count: " << c1.Count() << endl;

    cout << "Searching for node with id 4" << endl;
    node result = c1.SearchById(4);
    if (result.id != -1) {
        cout << "Found: " << result.name << " " << result.id << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
