#include <iostream>
#include <WinSock2.h>

using namespace std;


#pragma comment(lib,"ws2_32.lib")


/*

1. init winsock
2. create socket
3. get ip and port
4. bind the ip/port with the socket
5. listen on socket
6. accept
7. recall and send
8. close the socket
9. clean up winsok


*/

bool initialize() {
	WSADATA data;
	return WSAStartup(MAKEWORD(2, 2),&data) == 0;
}

int main() {

	if (!initialize()) {
		cout << "winsokcet not initialize" << endl;
		return 1;
	}

	SOCKET listensocket = socket(AF_INET,SOCK_STREAM,0);

	if (listensocket == INVALID_SOCKET) {
		cout << "socket creaion failed" << endl;
		return 1;
	}
	WSACleanup();
	return 0;
}