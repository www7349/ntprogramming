#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define BUFLEN 512
#define PORT 9930

int main(int argc,char*argv[]){
	int s;
	int len;
	char* servName;
	int servPort;
	char* string;
	char buffer[256+1];
	struct sockaddr_in servAddr;
	if(argc!=3){
	printf("Error:three arguments are needed!");
	exit(1);
	}
	servNameargv[1];
	servPort=atoi(argv[2]);
	string=argv[3];
	memset(&servAddr,0,sizeof(sercAddr));
	servAddr.sin_family=AF_INET;
	inet_pton(AF_INETR,servName,&servAddr.sin_addr);
	servAddr.sin_port=htons(servPort);
	if((s=socket(PF_INET,SOCK_DGRAM,0)<0){
	perror("Error:Socket failed!");
	exit(1);
	}
	len=sendto(s,string,strlen(string,0,(struct sockaddr)&servAddr,
	sizeof(servAddr));

	len = sendto(s,string,strlen(string),0,(struct sockaddr)&servAddr,
	sizeof(servAddr));
	recvfrom(s,buffer,len,0,NULL,NULL);

	buffer[len]="\0";
	printf("Echo string received:");
	fputs(buffer,stdout);

	close(s);

	exit(0);
}


