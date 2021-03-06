/***
Разработайте утилиту командной строки, принимающую на вход имя хоста
и печатающую в стандартный поток вывода список IP-адресов, ассоциированных
с данным именем.
***/

#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Wrong argument count!\n");
        return 1;
    }
    struct hostent *h;
    h = gethostbyname(argv[1]);
    
    int i = 0;
    char buf[100];
    while (h->h_addr_list[i] != NULL)
    {   
        printf("%s\n", inet_ntop(h->h_addrtype, h->h_addr_list[i], buf, 100));
        i++;
    }
    
    return 0;
}