#include <iostream>
#include "gt_client.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
// using namespace std;

using namespace std;

int main(int argc, char *argv[])
{
    env env1;


    if(argc != 2)
    {
        printf("Client ID not entered\n");
        return 1;
    }

    int client_id = atoi(argv[1]);
    printf("Client ID: %d\n", client_id);
    env1.client_id = client_id;
    init(&env1);
    char items[128] = "Pen Drive, Mouse";

    put(&env1, client_id, items);
    sleep(1);
    get(&env1, client_id);
    sleep(3);

    strcpy(items, "Toothpaste, Soap");
    put(&env1, client_id, items);
    sleep(1);
    get(&env1, client_id);
    sleep(3);

    strcpy(items, "Book, Pen");
    put(&env1, client_id, items);
    printf("********Crash servers now!\n");
    sleep(10);
    get(&env1, client_id);
    sleep(5);

    strcpy(items, "Echo Dot, Google Home");
    put(&env1, client_id, items);
    sleep(1);
    get(&env1, client_id);
    sleep(3);

    strcpy(items, "iPhone X, MacBook");
    put(&env1, client_id, items);
    sleep(1);
    get(&env1, client_id);

    finalize(&env1);

    return 0;
}
