#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(){
    // create socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an addres for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(5555);
    server_address.sin_addr.s_addr = inet_addr("10.8.0.10");
    
    int connection_status =
    connect(network_socket, (struct sockaddr *) &server_address, 
                                sizeof(server_address));
    
    if( connection_status == -1 ) {
        printf("Somethink went wrong!");
    }

    // sending data to the servr
    char *data_to_send;
    data_to_send = "Kebab";
    // strcpy(data_to_send,"Wiadomosc\n");
    send(network_socket, data_to_send, strlen(data_to_send),0);

    // reciving data from the server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    // print server response
    printf("Otrzymalem : %s\n", server_response);

    close(network_socket);

    return 0;
}
