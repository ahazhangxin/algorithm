/*=============================================================== 
 *   Copyright (C) . All rights reserved.")
 *   文件名称： 
 *   创 建 者：zhang
 *   创建日期：
 *   描    述：这个demo演示select最简单的使用 
 *       使用select对标准输入进行监控
 ================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/select.h>

int main()
{
    while(1) {
        fd_set set;
        FD_ZERO(&set);//清空集合
        FD_SET(0, &set);//将描述符0添加到集合中
        //int select(int nfds, fd_set *readfds, fd_set *writefds,
        //  fd_set *exceptfds, struct timeval *timeout);
        struct timeval tv;
        tv.tv_sec = 3;
        tv.tv_usec = 0;
        int nfds = select(0 + 1, &set, NULL, NULL, &tv);
        if (nfds < 0) {
            perror("select error\n");
            continue;
        }else if (nfds == 0) {
            printf("select timeout\n");
            continue;
        }
        printf("File descriptors are ready\n");
        char buf[1024] = {0};
        int ret = read(0, buf, 1023);
        if (ret < 0) {
            perror("read error\n");
            FD_CLR(0, &set);
            return -1;
        }
        printf("buf:[%s]\n", buf);
    }
    return 0;
}
