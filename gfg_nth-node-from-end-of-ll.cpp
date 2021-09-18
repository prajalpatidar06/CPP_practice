#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* root;
Node* last;

void push(int val){
    Node* t = new Node(val);
    if(!root){
        root = last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

int getNthFromLast(struct Node *head, int &n){
    static int size = 0;
    static int found = 0;
    
    if(head == NULL){
        return n-1;
    }
    int c = getNthFromLast(head->next , n);
    if(c > 0 && !found){
        return c-1;
    }
    if(c <= 0 && !found){
        found = 1;
        return head->data;
    }
    return c;
}

int main(){

    int n,k;
    cin>>n>>k;

    int val;
    for(int i = 0 ; i < n ; i++){
        cin>>val;
        push(val);
    }

    cout<<getNthFromLast(root,k);
    
    return 0;
}