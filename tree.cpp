#include "include/queue.h"
#include "include/tree.h"
#include "iostream"
using namespace std;

extern int Arr[100];

Tree* Twotree::getRoot()
{
    return this->root;
}

void Twotree::createNode(int data){
    if (root == nullptr){
        root = new Tree;
        if (root == nullptr)
        {
            printf("Fail to create node!\n");
            return;
        }
        queue->EnQueue(data);
        size++;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }
}

void Twotree::add(Tree * T, int data){
    //如果左子树为空，则添加左子树
    if (T->left == nullptr){
        Tree *temp = new Tree;
        if (temp == nullptr){
            printf("Fail to create node!\n");
        }
        queue->EnQueue(data);
        T->left = temp;
        T->left->data = data;
        size++;
        T->left->left = nullptr;
        T->left->right = nullptr;
        return;
    }
    else if (T->right == nullptr){
        Tree *temp = new Tree;
        if (temp == nullptr){
            printf("Fail to create node!\n");
        }
        queue->EnQueue(data);
        T->right = temp;
        T->right->data = data;
        T->right->left = nullptr;
        T->right->right = nullptr;
        size++;
        return;
    }
    //如果右子树不为空，并且下个节点的左子树或者右子树为空，则需要建立下个节点左子树或者右子树。
    //如果左右子树的下个结点都完成了分配，那么就需要从左子树开始
    else if ((T->right != nullptr && (T->left->left == nullptr || T->left->right == nullptr)) || (T->right != nullptr&&T->right->left!= nullptr&&T->right->right != nullptr)){
        add(T->left, data);
        return;
    }
    else {
        add(T->right, data);
        return;
    }
}

void Twotree::PreOrder(Tree *t){
    if (t == nullptr){
        return;
    }
    //从根结点开始：根->左->右
    printf("%d ", t->data);
    PreOrder(t->left);
    PreOrder(t->right);
    return;
}
void Twotree::InOrder(Tree *t){
    if (t != nullptr){
        InOrder(t->left);
        //从左结点开始：左->根->右
        printf("%d ", t->data);
        InOrder(t->right);
    }
}
void Twotree::PostOrder(Tree *t){
    if (t != nullptr){
        PostOrder(t->left);
        PostOrder(t->right);
        //从左结点开始：左->右->根
        printf("%d ", t->data);
    }
}

int Twotree::getSize(){
    return this->size;
}

void Twotree::floorOrder(){
    printf("----------- Floor Traversal(Tree) -------------\n");
    for (int i = 0; i < this->size;i++)
    {
        int data = queue->DeQueue();
        printf("%d ", data);
    }
    printf("\n");
}

Twotree::Twotree()
{
    queue = new Queue();
    size = 0;
    root = nullptr;
}

Twotree::~Twotree()
{
}