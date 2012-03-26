#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <inttypes.h>
#include <windows.h>

HANDLE openSerialPort(LPCSTR portname)
{
	DWORD  accessdirection =GENERIC_READ | GENERIC_WRITE;
	HANDLE hSerial = CreateFile(portname,
		accessdirection,
		0,
		0,
		OPEN_EXISTING,
		0,
		0);
	if (hSerial == INVALID_HANDLE_VALUE) {
		//call GetLastError(); to gain more information
	}
	DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams)) {
		 //could not get the state of the comport
	}
	dcbSerialParams.BaudRate=460800;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=ONESTOPBIT;
	dcbSerialParams.Parity=NOPARITY;
	if(!SetCommState(hSerial, &dcbSerialParams)){
		 //analyse error
	}
	COMMTIMEOUTS timeouts={0};
	timeouts.ReadIntervalTimeout=50;
	timeouts.ReadTotalTimeoutConstant=50;
	timeouts.ReadTotalTimeoutMultiplier=10;
	timeouts.WriteTotalTimeoutConstant=50;
	timeouts.WriteTotalTimeoutMultiplier=10;
	if(!SetCommTimeouts(hSerial, &timeouts)){
		//handle error
	}
	return hSerial;
}


DWORD readFromSerialPort(HANDLE hSerial, uint8_t * buffer, int buffersize)
{
    DWORD dwBytesRead = 0;
    if(!ReadFile(hSerial, buffer, buffersize, &dwBytesRead, NULL)){
        //handle error
    }
    return dwBytesRead;
}

DWORD writeToSerialPort(HANDLE hSerial, uint8_t * data, int length)
{

	DWORD dwBytesRead = 0;
	if(!WriteFile(hSerial, data, length, &dwBytesRead, NULL)){
		//handle error
	}
	return dwBytesRead;

}

void closeSerialPort(HANDLE hSerial)
{
	CloseHandle(hSerial);
}
#endif