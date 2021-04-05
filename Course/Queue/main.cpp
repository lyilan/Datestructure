#include "Queue.h"

int main()
{
    LinkQueue Q;
    QElemType e;

    if(InitQueue(Q))
        printf("队列Q初始化成功\n");
    else
    {
        printf("初始化失败！\n");
    }
    
    if(QueueEmpty(Q))
        printf("队列为空！\n");

    printf("请输入5个元素：");
    for(int i = 0; i < 5; i++)
    {
        scanf("%d",&e);
        EnQueue(Q, e);
    }

    printf("队列长度： %d\n",QueueLength(Q));
    
    GetHead(Q,e);
    printf("队列首个元素：%d\n",e);

    printf("开始遍历队列：\n");
    QueueTraverse(Q, visit);

    DeQueue(Q, e);
    printf("删除队头元素：%d\n",e);

    GetHead(Q,e);
    printf("队列首个元素：%d\n",e);

    printf("开始遍历队列：\n");
    QueueTraverse(Q, visit);

    if(ClearQueue(Q))
        printf("队列清空\n");
    else 
        printf("清空失败！\n");
    
    if(DestroyQueue(Q))
    {
        printf("队列销毁成功！\n");
    }
    else
    {
        printf("队列销毁失败！\n");
    }

    printf("再见！\n");
    return 0;

}