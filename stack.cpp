#include "include/stack.h"
#include <iostream>
using namespace std;

extern int Arr[100];

void Stack::CreateNode(int data){
    StackData *p = new StackData;
    if (p == nullptr){
        printf("Node creation failure!\n");
        return;
    }
    pop = p;
    p->data = data;
    pop->next = nullptr;
    size++;
}


void Stack::Push(int data){
    StackData * p = pop;
    if (pop == nullptr)
        CreateNode(data);
    else{
        CreateNode(data);
        pop->next = p;
    }
}


int Stack::getSize()
{
    return size;
}


int Stack::Pop()
{
    StackData *p = pop;
    if (pop == nullptr){
        printf("There's no data in the stack.\n");
        return -10000;
    }

    else{
        pop = pop->next;
        int data = p->data;
        delete p;
        size--;     
        return data;
    }
}


void Stack::Clear()
{
    while(pop!= nullptr){
        StackData* p = pop;
        pop = pop->next;
        size--;
        delete p;
    }
}

Stack::Stack()
{
    pop = nullptr;
    size = 0;
}

Stack::~Stack()
{
}
