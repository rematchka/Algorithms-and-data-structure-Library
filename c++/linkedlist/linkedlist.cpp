//
//  main.cpp
//  LinkedLists
//
//  Created by MacBook Pro on 6/17/19.
//  Copyright © 2019 MacBook Pro. All rights reserved.
//

#include <iostream>
using namespace std;


struct node
{
    int x;
    node* next;
    node(int x){this->x = x; next=NULL;};
};


node* create_linked_list(int * arr,int len)
{
    node* h;node* list;
    list = new node(arr[0]);
    h = list;
    for(int i =1;i<len;i++)
    {
        h->next = new node(arr[i]);
        h = h->next;
    }
    return list;
}

void print_list(node* h)

{
    node* l = h;
    while(l!= NULL)
    {
        cout<<l->x<<" ";
        l = l->next;
    }
    cout<<endl;
}

node* reverse_list(node* h)
{
 
    if(h==NULL) return h;
    node* l = h;
    
    node* prev = NULL;
    node* temp = l->next;
    
    while(temp != NULL)
    {
        l->next = prev;
        prev = l;
        l = temp;
        temp = l->next;
    }
    l->next = prev;
    return l;
}

node* reverse_list(node * h , int b)
{
    node* c = h;
    int cnt =1;
    
    if(h==NULL||b==1) return h;
    
    node* prev = NULL;
    node* temp;
    
    while(cnt%b!=0)
    {
        temp= h->next;
        h->next = prev;
        prev = h;
        h= temp;
    
        cnt++;
    }
    temp = h->next;
    h->next = prev;
    
    c->next = reverse_list(temp,b);
    
    return h;
    
}

int main(int argc, const char * argv[]) {

    int arr[6]={1,2,3,4,5,6};
    node* k = create_linked_list(arr,6);
    print_list(k);
    
    k= reverse_list(k,2);
    print_list(k);
    
    
    return 0;
}
