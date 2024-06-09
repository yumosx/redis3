sds sdsnewlen(const void* init, size_t* initlen) {
    void* sh; //指向sds结体的指针
    sds s; //sds类型变量

    //创建一个sds结构体
    sh = s_malloc(hdrlen + initlen+1);

    //sds类型变量指向sds结构体中的buf数组
    //sh指向sds结构体的初始位置
    //hdrlen是元变量的长度
    s = (char*)sh + hdrlen;

    if (initlen && init) {
        //将要传入的字符串拷贝给sds变量s
        memcpy(s, init, initlen);
    }

    s[initlen] = '\0';
    return s;
}

sds sdscatlen(sds s, const void* t, size_t len) {
    //获得目标字符串s的当前长度
    size_t curlen = sdslen(s);
    //根据要追加len和目标字符串s的现有长度, 判断要增加新的空间
    s = sdsMakeRoomFor(s, len);
    if (s == NULL) return NULL;
    memcpy(s+curlen, t, len);
    //设置目标字符串的最新长度, 拷贝前面长度curlen加上拷贝长度
    sdssetlen(s, curle); 
    //拷贝之后, 在目标字符串之后加上\0
    s[curlen+len] = '\0';
    return s;    
}