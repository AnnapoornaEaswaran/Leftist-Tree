#include<iostream>
using namespace std;
struct node
{
    int data;
    node *leftChild,*rightChild;
}*root,*temp;
int sValue(node *r)
{
    int ls,rs;
    if(r==NULL)
    {
        return -1;
    }
    else
    {
        ls=sValue(r->leftChild);
        rs=sValue(r->rightChild);
        if(ls<rs)         //min of both needs to be taken as svalue of the node.
            return ls+1;
        else
            return rs+1;
    }
}
void balanceTree(node *r)
{
    if(sValue(r->leftChild)<sValue(r->rightChild))
    {
        node *temp=r->rightChild;
        r->rightChild=r->leftChild;
        r->leftChild=temp;
    }
}
void insertVal(node *root1,node *r) //  need to check the maximum value in intermediate levels.
{
    if(root1->data>=r->data){
        if(root1->rightChild==NULL)
            root1->rightChild=r;
        else
            insertVal(root1->rightChild,r);
        balanceTree(root1);
    }
    else{
        if(root1==root){
                root=r;
                r->rightChild=root1;
        }
        else{
            temp= new node;
            temp->data=root1->data;
            temp->leftChild=root1->leftChild;
            temp->rightChild=root1->rightChild;
            root1->data=r->data;
            root1->leftChild=NULL;
            root1->rightChild=temp;
        }


        balanceTree(r);
    }
}
void displayInorder(node *r)
{
    if(r!=NULL){
    displayInorder(r->leftChild);
    if(r==root)
        cout<<"Root!! :";
    cout<<"  "<<r->data;
    displayInorder(r->rightChild);
    }
}
int main()
{
    cout<<"Hello world!!!!";
    int ch=1;
    node *temp,*r;
    while(ch==1){
        cout<<"Please enter the number:";
        temp=new node;
        cin>>temp->data;
        temp->leftChild=NULL;
        temp->rightChild=NULL;
        if(root==NULL)
            root=temp;
        else{
            r=root;
            insertVal(r,temp);
        }
        cout<<"do you want to continue? (1/2)?";
        cin>>ch;
    }
    r=root;
    displayInorder(r);

    return 0;
}
