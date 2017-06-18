#include <iostream>
#include "include/stack.h"
#include "include/queue.h"
#include "include/tree.h"
using namespace std;

#define N 100
int Arr[N];

void StackTest(int count){
    Stack *stack = new Stack();
    int data;
    int i;

    printf("-----------Push(stack)-----------\n");
    for(i = 0; i < count; i++){
    	stack->Push(Arr[i]);
    	printf("%d ", Arr[i]);
    }
    printf("\n");
    
    printf("-----------Pop(stack)-----------\n");
    for(i = 0; i < count; i++){
	    data = stack->Pop();
	    printf("%d ", data);
    }
    printf("\n");

    stack->Clear();
    //printf("%d\n", stack->getSize());
    data = stack->Pop();
    //printf("%d,%d\n\n", stack->getSize(), data);
}

void QueueTest(int count){
    Queue *queue = new Queue();
    int data2;
    int i;
    
    printf("----------- Enter(queue) -----------\n");
    for(i = 0; i < count; i++){
    	queue->EnQueue(Arr[i]);
    	printf("%d ", Arr[i]);
    }
    printf("\n");

    printf("----------- Leave(queue) -----------\n");
    for(i = 0; i < count; i++){
	    int data2 =queue->DeQueue();
	    printf("%d ", data2);
    }
    printf("\n");
    queue->Clear();
    data2 = queue->DeQueue();
}


void TreeTest(int count){
    Twotree *twotree = new Twotree();
    int i;
    twotree->createNode(Arr[0]);

    for(i = 1; i < count; i++)
    	twotree->add(twotree->getRoot(),Arr[i]);
    //printf("%d\n",twotree->getSize());
    twotree->floorOrder();

    printf("----------- Preorder traversal(Tree) -----------\n");
    twotree->PreOrder(twotree->getRoot());
    printf("\n");
    printf("----------- Inorder traversal(Tree) ------------\n");
    twotree->InOrder(twotree->getRoot());
    printf("\n");
    printf("----------- Postorder traversal(Tree) ----------\n");
    twotree->PostOrder(twotree->getRoot());
    printf("\n");
}


int main()
{
	int testNum;
	int count, i;
	printf("Please input the count of data to operate: ");
	scanf("%d", &count);
	printf("Please input %d data(separated with a newline):\n", count);
	for(i = 0; i < count; i++){
		scanf("%d", &Arr[i]);
	}

	printf("Please choose data structure(1-Stack; 2-Queue; 3-Tree):\n");
	scanf("%d", &testNum);	
	while(testNum != 1 and testNum != 2 and testNum != 3){
		printf("testNumber is wrong! Please input again!\n");
		scanf("%d", &testNum);
	}

	switch(testNum){
		case 1: StackTest(count);break;
		case 2: QueueTest(count);break;
		case 3: TreeTest(count);break;
	}

	return 0;
}