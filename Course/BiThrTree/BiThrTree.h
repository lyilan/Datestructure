/*
 * @Author: lyilan
 * @Date: 2021-04-10 19:29:08
 * @Description: for my ying~
 */

// - - - - - 二叉树的二叉线索存储表示 - - - - -

//Link == 0:指针，Thread == 1:线索
typedef enum PointerTag
{
    Link,
    Thread
};
typedef char TElemType;
typedef struct BiThrNode
{
    TElemType data;
};