typedef struct sData
{
    int data;
    sData *next;
}StackData;

class Stack
{
public:
    Stack();
    ~Stack();
    void Push(int data); //入栈
    int Pop(); //出栈
    void CreateNode(int data);
    void Clear(); //清空栈
    int getSize();//获取栈内元素个数

private:
    StackData * pop;
    int size;
};
