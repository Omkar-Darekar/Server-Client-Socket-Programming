#include<stdio.h>
#include <netdb.h> 
#include <stdio.h> 
#include <arpa/inet.h>
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>

#define MAX 100
#define SockAdd struct sockaddr
#define PORT 8088

//using namespace std;


void func(int mainSock){
	char msg[MAX];
	char str[]="Exit";
	
	for(;;){
		//cout<<"Enter String"<<endl;
		printf("\n Enter Message ---->>> ");
		int n=0;
		bzero(msg,sizeof(msg));
		while((msg[n++]=getchar())!='\n')
		;
		
		/*
		int i=0;	
		cout<<"msg[0]"<<msg[0]<<endl;	
		while((msg[i]!='\n')){
			cout<<"I am here"<<endl;
			cout<<msg[i];
			i++;		
			//n--;
		}
		*/

		if(strcmp(msg,str)==0){
			printf("You Entered Exit");
			break;
		}


		write(mainSock,msg,sizeof(msg));
		
				
		bzero(msg,sizeof(msg));		
		
		read(mainSock,msg,sizeof(msg));

		int i=0;	
		//cout<<"msg[0]"<<msg[0]<<endl;	
		/*while((msg[i]!='\n')){
			//cout<<"I am here"<<endl;
			cout<<msg[i];
			i++;		
			//n--;
		}*/
		printf("\n Server Message -->> %s",msg);
		
		
	}


}


int main(){
	int mainSock;
	struct sockaddr_in servInfo;
	
	mainSock= socket(AF_INET,SOCK_STREAM,0);
	if(mainSock ==-1){
		//cout<<"Main Socket Failed"<<endl;
		printf("\n Main Socket Failed \n");
	}else{
		//cout<<"Main Socket Success"<<endl;
		printf("\n Main Socket Success \n");
	}

	bzero(&servInfo, sizeof(servInfo));
	
	servInfo.sin_family = AF_INET; 
	servInfo.sin_addr.s_addr = inet_addr("192.168.0.125"); 
	//servInfo.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servInfo.sin_port = htons(PORT); 

	//int len=sizeof(servInfo);
		

	if(connect(mainSock,(SockAdd*)&servInfo,sizeof(servInfo))!=0){
		//cout<<"Connection Failed"<<endl;
		puts("\n Inside Clinet Connection Failed \n");
		//printf("\n Connection Failed \n");
		exit(0);	
	}else{
		//cout<<"Connection Success"<<endl;
		//print("\n Connection Success \n");
		puts("\n Inside Client Coonect \n");
	}


	func(mainSock);

	close(mainSock);

return 0;
}
