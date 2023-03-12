# SpinGW

This Repository contains a wrapper to access the SerialPort in MinGW.

## Dependencies

* Windows (tested under XP, 7 and 10)
* MinGW (untested with Visual Studio and Cygwin)

## Usage

1. Copy or fork SPinGW
2. Include serialport.h and serialport.c to your program.
3. Call openSerialPort from your program.
4. Use writeToSerialPort and readFromSerialPort to transfer data
5. Close the port with closeSerialPort after the communication is finished

## Example

``` c
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
```

Compile gcc example.c serialport.c -o example.exe

## FAQ

* Comports with a bigger number (I believe bigger than 9) can be used by with their UNC Paths \\\\.\\COM11 (thanks to jaui)
