#include <stdlib.h>

/*
hash实体
*/
typedef struct dictEntry {
    void* key;
    union
    {
        void* val;
        uint64_t u64;
        uint64_t s64;
        double d;
    };
    struct dictEntry* next; 
};

/*
hash表被定义为一个二维数组, 这个数组的每个元素是一个哈希项的指针
*/
typedef struct dictht {
    struct dictEntry** table;
    unsigned long size;
    unsigned long sizemask;
    unsigned long used;
} dictht;

/*
1. 正常服务请求阶段, 所有的键都写入hash表[0]
2. 接着进行rehash, 键值对被迁移到哈希表[1]中
3. 最后迁移完成之后, ht[0]的空间被释放，并将ht[1]的地址给ht[0], ht[1]的表被设置成0
*/
typedef struct dict {
    dictht ht[2];   //两个hash表
    long rehashidx; //表示是否正在进行rehash
} dict;

/*
在_dictExpandifNeed函数中给出这三者的定义
什么时候触发rehash
1.条件1: ht[0]的大小为0
2.条件2: ht[0]承受的元素个数已经超过了ht[0]的大小
3.条件3: ht[0]承载的元素个数，是ht[0]的大小dict_force_resize_ratio倍，
    其中dict_force_resize_ratio 的默认值是5
*/
