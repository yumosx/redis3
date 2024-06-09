#include "dict.h"

//表示hash表是否可以扩容
int dict_can_resize;

void _dictExpandIfNeeded(dict* d) {
    //表示hash表为空直接扩容
    if (d->ht[0].size == 0) {
        return 0;
    }

}

void dictEnableResize(void) {
    dict_can_resize = 1;
}

void dictDisableResize(void) {
    dict_can_resize = 0;
}

//然后这两个函数又被封装在update_dict_resize_policy函数中
void updateDictResizePolicy(void) {
    if (server.rdb_child_pid == -1 && server.aof_child_pid == -1) {
        dictEnableResize();
    } else {
        dictDisableResize();
    }
}


/*
首先是向redis中写入新的键值对或者修改新的键值对时候, redis都会判断下一步时候需要进行rehash
- 添加一个键值对
- 添加一个键值对
- 直接调用dictaddraw
*/


//扩容的时候一般会扩容两倍
//dictExpand(d, d->ht[0].used*2);
int dictExpand(dict* d, unsigned long size) {

}

//扩容函数的底层实现
static unsigned long _dictNextPower(unsigned long size) {
    //hash表的初始化大小
    unsigned long i = DICT_HI_INITAL_SIZE;
    if (size >= LONG_MAX)
        return LONG_MAX + 1LU;

    while (1) {
        if (i >= size)
            return i;
        i *= 2;
    }
}


/*
渐进式rehash如何实现，hash表在执行rehash的时候, 由于hash表空间增大
简单的说rehash的意思是redis并不会一次性的把当前的hash表中的所有的键，都拷贝到新的位置
而是会分批拷贝，因为一次性拷贝很可能会导致线程的阻塞
*/

int dictRehash(dict* d, int n) {
    int empty_visits = n * 10;

    //主要的循环
    while(n-- && d->ht[0].used != 0) {

    }
    



    return 0;
}