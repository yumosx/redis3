#ifndef sds_h
#define sds_h

#include <stdlib.h>

//用来存放对应的指针
typedef char* sds;

struct __attribute__((__packed__)) sdshdr8 {
    uint8_t len; //字符串现在已经有的长度
    uint8_t alloc; //给字符串分配的长度
    char buf[]; //字符数组
};



#endif