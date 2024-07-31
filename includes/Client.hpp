#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <map>

#define MAX_EVENTS 10

class Client {
public:
    Client(int socket);
    Client();
    int getSocket() const;
    void setNick(const std::string& nick);
    void setUser(const std::string& user);
    std::string getNick() const;
    std::string getUser() const;

private:
    int socket;
    std::string nick;
    std::string user;
};

class ClientArray {
    private:
        std::map<int, Client> clients;
    public:
        ClientArray();
        ~ClientArray();
        void add_client(int client_socket);
        void remove_client(int client_socket);
        Client &get_client(int client_socket);

};