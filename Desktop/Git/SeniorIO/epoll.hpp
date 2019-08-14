/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：封装一个Epoll类，向外提供简单的多路转接接口
*       1. 添加监控
*       bool Add(TcpSocket &sock);
*       2. 进行监控，返回就绪的TcpSocket列表
*       bool Wait(std::vector<TcpSocket> &list, int time_sec);
*       3. 移除监控 
*       bool Del(TcpSocket &sock);
================================================================*/

#include <iostream>
#include <vector>
#include <sys/epoll.h>
#include "tcpsocket.hpp"

class Epoll
{
    public:
        Epoll():_epfd(-1){}
        bool Init() {
            _epfd = epoll_create(1);
            if (_epfd < 0) {
                std::cerr << "epoll create error\n";
                return false;
            }
            return true;
        }
        bool Add(TcpSocket &sock) {
            int fd = sock.GetFd();
            struct epoll_event ev;
            ev.data.fd = fd;
            ev.events = EPOLLIN | EPOLLET;//EPOLLOUT
            int ret = epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &ev);
            if (ret < 0) {
                std::cerr << "Add descriptor monitoring failed\n";
                return false;
            }
            return true;
        }
        bool Wait(std::vector<TcpSocket> &list, int time_sec = 3) {
            struct epoll_event evs[100];
            int nfds = epoll_wait(_epfd, evs, 100, time_sec * 1000);
            if (nfds < 0) {
                std::cerr << "epoll wait error\n";
                return false;
            }else if (nfds == 0) {
                std::cerr << "Wait for a timeout\n";
                return false;
            }
            for (int i = 0; i < nfds; i++) {
                TcpSocket sock;
                sock.SetFd(evs[i].data.fd);
                list.push_back(sock);
            }
            return true;
        }
        bool Del(TcpSocket &sock) {
            int fd = sock.GetFd();
            int ret = epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, NULL);
            if (ret < 0) {
                std::cerr << "Failed to remove descriptor monitor\n";
                return false;
            }
            return true;
        }
    private:
        int _epfd;
};
