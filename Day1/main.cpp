#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    int id;
    char name[10];
    node *next;
    node *prev;
};

class Linked
{
    node *head;
    node *tail;

    node *searchbyId(int id)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->id == id)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

public:
    Linked()
    {
        head = tail = NULL;
    }

    void append(int id, char *name)
    {
        node *temp = new node();
        temp->id = id;
        strcpy(temp->name, name);
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->id << " ";
            cout<<temp->name;
            temp = temp->next;
        }
        cout << endl;
    }

    int Count()
    {
        node *temp = head;
        int n = 0;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        return n;
    }

    node searchNode(int id)
    {
        node n;
        node *temp = searchbyId(id);
        if (temp != NULL)
        {
            n.id = temp->id;
            strcpy(n.name, temp->name);
        }
        else
        {
            n.id = -1;
        }
        return n;
    }

    void deletebyId(int id)
    {
        node *t = searchbyId(id);
        if (t == NULL)
        {
            return;
        }
        else if (head == tail)
        {
            head = tail = NULL;
        }
        else if (t == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else if (t == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            t->prev->next = t->next;
            t->next->prev = t->prev;
        }
        delete t;
    }

    void insertNode(int id, char *name, int prevId)
    {
        node *t = searchbyId(prevId);
        if (t == NULL)
        {
            return;
        }
        else
        {
            node *temp = new node();
            temp->id = id;
            strcpy(temp->name, name);
            temp->prev = t;
            temp->next = t->next;
            t->next = temp;
        }
    }
};

int main()
{
    Linked linkedList;
    linkedList.append(1, "Haidy");
    linkedList.append(2, "Essam");
    linkedList.display();
    linkedList.insertNode(3, "Ahmed", 1);
    linkedList.display();
    linkedList.deletebyId(2);
    linkedList.display();

    return 0;
}
