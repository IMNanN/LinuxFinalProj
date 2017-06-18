typedef struct qData
{
    int data;
    qData *next;
}QueueData;

class Queue
{
public:
    Queue();
    ~Queue();  
    void EnQueue(int data);  //入队
    int  DeQueue();  //出队
    bool IsQueueEmpty();  //判断是否为空
    int getSize();  //获取队内元素个数
    void Clear();  //清空队列

private:
    int size;
    QueueData *pop;
};
