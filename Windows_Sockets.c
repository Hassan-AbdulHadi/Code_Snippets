#include <stdio.h>
#include <winsock2.h>
///gcc source.c -o main.exe -l Ws2_32 ---- for gcc
///#pragma comment(lib, "Ws2_32.lib") ---- for windows compiler
int main(int argc,char** argv)
{
    
    SOCKET mysocket =INVALID_SOCKET; // the file descriptor that refers to the socket
    int result; //for function call results
    WSADATA wsadata; //structure contains information about the Windows Sockets implementation,such as the version
    struct sockaddr_in AdrressEndPoint; //structure contains an adress endpoint(IP,port,famliy)
                                      //it contains sin_addr structure which contains union containing the IP in various forms
    unsigned char recvBuffer[1024]; //receive buffer 
    unsigned char *message ="hello server !";

    unsigned long ip = inet_addr(argv[1]); //the htons and inet_addr retrun ip and port in network byte order (big endian)
        if(ip==INADDR_NONE)
        {
            fprintf(stderr,"Invalid ip");
            return 1;
        }
    AdrressEndPoint.sin_addr.S_un.S_addr=ip;
    AdrressEndPoint.sin_port=htons(1000);
    AdrressEndPoint.sin_family=AF_INET;

    result = WSAStartup(MAKEWORD(2,2),&wsadata); //loads the Ws2_32.dll into memory, MAKEWORD(2,2) for the socket version
        if(result !=0)
        {
            fprintf(stderr,"Problems with loading Ws2_32.dll");
            WSACleanup(); //frees resources that allocated by Ws2_32.dll
            return 1;
        }
    mysocket =socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(mysocket==INVALID_SOCKET)
        {
            fprintf(stderr,"Error in socket function : %d",WSAGetLastError());
            WSACleanup();
            return 1;
        }
    result = connect(mysocket,(SOCKADDR*)&AdrressEndPoint,sizeof(AdrressEndPoint)); //the (sockaddr*)&AdrressEndPoint is type casting
        if(result == SOCKET_ERROR)
        {
            if(result == 10060)
                fprintf(stderr,"Connection timed out");
            if(result == 10061)
                fprintf(stderr,"Connection refused");
            else
                fprintf(stderr,"Error in connecting, error code : %d",WSAGetLastError());
                //https://docs.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2
                //full list of windows socket errors code
            WSACleanup();
            return 1;
        }
    result = send(mysocket,message,(int)strlen(message),0);//returns the number of bytes sent 
        if(result == SOCKET_ERROR)
        {
            fprintf(stderr,"Send faild with error: %d",WSAGetLastError());
            closesocket(mysocket);
            WSACleanup();
            return 1;
        }
    printf("Bytes sent: %d\n",result);
    
    do
    {
        result = recv(mysocket,recvBuffer,1024,0);//returns number of bytes received
        int i;
        for(i=0;i<result;i++)
            printf("%c",recvBuffer[i]);
    } while (result > 0);
    
    result = shutdown(mysocket,SD_BOTH);//disables sends or receives on a socket, Parameters:SD_SEND,SD_RECEIVE,SD_BOTH 
        if(result == SOCKET_ERROR)
        {
            fprintf(stderr,"error in shuting down oprations: %d",WSAGetLastError());
            closesocket(mysocket);
            WSACleanup();
            return 1;
        }
    closesocket(mysocket);
    WSACleanup();
return 0;
}

/*
struct   sin_addr {
union   {
        struct{
            unsigned  char   s_b1,
                            s_b2,
                            s_b3,
                            s_b4;
    }  S_un_b;
            struct  {
            unsigned  short  s_w1,
                            s_w2;
            }  S_un_w;
            unsigned long  S_addr;
    } S_un;
    */