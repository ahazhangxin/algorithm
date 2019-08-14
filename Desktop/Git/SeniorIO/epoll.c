/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：通过这个简单的demo体会epoll的一个使用方法 
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/epoll.h>

int main()
{
    int epfd = epoll_create(1);
    if (epfd < 0) {
        perror("epoll create error\n");
        return -1;
    }

    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = 0;

    //int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)
    epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &ev);

    while(1) {
        //int epoll_wait(int epfd, struct epoll_event *events,
        //  int maxevents, int timeout);
        struct epoll_event evs[10];
        int nfds = epoll_wait(epfd, evs, 10, 3000);
        if (nfds < 0) {
            perror("epoll wait error\n");
            continue;
        }else if (nfds == 0) {
            printf("epoll timeout\n");
            continue;
        }
        int i;
        for (i = 0; i < nfds; i++) {
            char buf[1024] = {0};
            read(evs[i].data.fd, buf, 1023);
            printf("buf:[%s]\n", buf);
        }
    }
    return 0;
}
