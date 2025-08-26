#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <tchar.h>

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

	// create address structure
	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(12345);

	// convert ip address to binary 
	if (InetPton(AF_INET, _T("0.0.0.0"), &serveraddr.sin_addr) != 1) {
		cout << "setting address structure failed" << endl;
		closesocket(listensocket);
		WSACleanup();
		return 1;
	}

	WSACleanup();
	return 0;
}