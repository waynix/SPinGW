#include <stdio.h>
#include "serialport.h"

int main(void)
{
	HANDLE h = openSerialPort("COM1",B9600,one,off);
	char sendbuffer[] = "test";
	char readbuffer[100];
	//write test
	int bytesWritten = writeToSerialPort(h,sendbuffer,strlen(sendbuffer));
	printf("%d Bytes were written\n",bytesWritten);
	//read something
	int bytesRead = readFromSerialPort(h,readbuffer,99);
	readbuffer[bytesRead]=0;
	printf("%d Bytes were read:%s\n",bytesRead,readbuffer);
	if(!closeSerialPort(h)){
		ErrorExit("Closing Port failed: ");
	}
	return 0;
}