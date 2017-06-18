#include "include/queue.h"
#include "iostream"
using namespace std;

extern int Arr[100];

void Queue::EnQueue(int data)
{
    if (pop == nullptr){
        QueueData* p = new QueueData;
        if (p == nullptr){
            printf("Node creation failure!\n");
            return;
        }
        pop = p;
        pop->data = data;
        size++;
        pop->next = nullptr;
    }
    else{
        //需要先判断是否它的下个结点是为空
        QueueData* temp = pop;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new QueueData;
        if (temp == nullptr){
            printf("Node creation failure!\n");
            return;
        }       
        temp->next->data = data;
        size++;
        temp->next->next = nullptr;
    }
}

void Queue::Clear()
{
    while (pop != nullptr)
    {
        size--;
        QueueData * p = pop;
        pop = pop->next;
        delete p;
    }
}

int Queue::DeQueue()
{
    if (pop != nullptr){
        size--;
        QueueData * p = pop;
        int data = pop->data;
        pop = pop->next;
        delete p;
        return data;
    }
    else{
        printf("There's no data in the queue.\n");
        return -10000000;
    }

}

int Queue::getSize(){
    return size;
}

bool Queue::IsQueueEmpty(){
    if (size == 0)
        return true;
    else
        return false;
}

Queue::Queue()
{
    pop = nullptr;
    size = 0;
}

Queue::~Queue()
{
}