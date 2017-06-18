typedef struct tree
{
    int data;
    tree * right;
    tree * left;
}Tree;

class Twotree
{
public:
    void createNode(int data);
    void add(Tree * T,int data); //添加节点

    void PreOrder(Tree *t); //前序遍历，从根结点开始：根->左->右
    void InOrder(Tree *t);  //中序遍历，从左结点开始：左->根->右
    void PostOrder(Tree *t);//后序遍历，从左结点开始：左->右->根
    void floorOrder(); //通过队列来逐层遍历
    Tree *getRoot();   //获得根结点
    int getSize();     //获得元素个数
    Twotree();
    ~Twotree();

private:
    Tree * root;
    int size;
    Queue *queue;
};