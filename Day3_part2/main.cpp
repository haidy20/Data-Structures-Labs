#include <iostream>
using namespace std;
struct node{
int id;
node* Left;
node* Right;
};
class BST{
node* root;

//Find parent Fun
node* findParent(int id){
node* temp=root;
while(temp){
if (id <= temp->id && temp ->Left==NULL)
return temp;

else if(id>=temp->id && temp->Right==NULL)
return temp;

 else if(id <temp->id)
    temp=temp->Left;
else if(id >temp->id)
    temp=temp->Right;
}

}

// in order fun(private)
void inorder(node* r){
    if(r==NULL)
        return;
inorder(r->Left);
cout<< r->id <<",";
inorder(r->Right);
}

public:
    BST(){
    root=NULL;
    }
// Add fun
void add(int id){
node* temp= new node();
temp->id=id;
temp->Left=NULL;
temp->Right=NULL;
if(root==NULL)
    root=temp;
else{
    node* p =findParent(id);
if(id< p->id)
    p->Left=temp;
else
    p->Right=temp;
}

}

//(public) in order
void inorder(){
inorder(root);
}


};


int main()
{
  BST t1;
  t1.add(100);
  t1.add(50);
  t1.add(45);
  t1.add(120);
  t1.inorder();
    return 0;
}
