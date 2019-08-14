/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：zhang
*   创建日期：
*   描    述：封装一个Select类，向外提供接口实现select的简单操作 
*       对大量描述符进行监控，向用户返回就绪的描述符
*       1. 添加指定描述符的事件监控接口
*           bool Add(TcpSocket &sock);
*       2. 开始监控，向用户返回就绪的描述符
*           bool Wait(std::vector<TcpSocket> &list);
*       3. 从监控中移除指定的描述符
*           bool Del(TcpSocket &sock);
================================================================*/
#ifndef __M_SL_H__
#define __M_SL_H__
#include <iostream>
#include <vector>
#include <sys/select.h>
#include "tcpsocket.hpp"
class Select
{
    public:
        Select ():_max_fd(-1) {
            FD_ZERO(&_rfds);
        }
        bool Add(TcpSocket &sock) {
            int fd = sock.GetFd();
            if (FD_ISSET(fd, &_rfds)) {
                std::cerr << "The file descriptor is already";
                std::cerr << " in the collection\n";
                return true;
            }
            FD_SET(fd, &_rfds);
            _max_fd = _max_fd > fd ? _max_fd : fd;
            return true;
        }
        bool Wait(std::vector<TcpSocket> &list, int time_sec = 3) {
            struct timeval tv;
            tv.tv_sec = time_sec;
            tv.tv_usec = 0;
            fd_set fds = _rfds;
            int nfds = select(_max_fd + 1, &fds, NULL, NULL, &tv);
            if (nfds < 0) {
                std::cerr << "select error\n";
                return false;
            }else if (nfds == 0) {
                std::cerr << "select timeout\n";
                return false;
            }
            for (int i = 0; i <= _max_fd; i++) {
                if (FD_ISSET(i, &fds)) {
                    TcpSocket sock;
                    sock.SetFd(i);
                    list.push_back(sock);
                }
            }
            return true;
        }
        bool Del(TcpSocket &sock) {
            int fd = sock.GetFd();
            FD_CLR(fd, &_rfds);
            for (int i = _max_fd; i >= 0; i--) {
                if (FD_ISSET(i, &_rfds)) {
                    _max_fd = i;
                    break;
                }
            }
            return true;
        }
    private:
        fd_set _rfds;
        int _max_fd;
};
#endif
