#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <windows.h>

/**
 * \brief A list of standard baudrates
 * \note there may be additional conigurations available for your hardware
 */
enum Baudrate
{
	B50	    = 50,      // not listed in https://learn.microsoft.com/en-us/windows/win32/api/winbase/ns-winbase-dcb
	B110	= 110,
	B150	= 150,
	B300	= 300,
	B1200	= 1200,
	B2400	= 2400,
	B4800	= 4800,
	B9600   = 9600,
	B19200	= 19200,
	B38400	= 38400,
	B57600	= 57600,
	B115200 = 115200,
	B230400	= 230400,
	B460800	= 460800,
	B500000 = 500000,
	B1000000= 1000000  // not listed in https://learn.microsoft.com/en-us/windows/win32/api/winbase/ns-winbase-dcb
};

/**
 * \brief Possible values for the nuber of stop bits
 */
enum Stopbits
{
	one = ONESTOPBIT,
	onePointFive = ONE5STOPBITS,
	two = TWOSTOPBITS
};

/**
 * \brief Available parity operation modes modes
 */
enum Paritycheck
{
	off  = NOPARITY,     // disable parity checking
	even = EVENPARITY,   // enable even parity
	odd  = ODDPARITY,    // enable odd parity
	mark = MARKPARITY,   // enable mark parity
	space = SPACEPARITY  // enable space parity
};

/**
 * \brief Display the error information from the operation system and exit the program.
 * \param lpszFunction Additional input for the user printed before the error message.
 */
void ErrorExit(LPTSTR lpszFunction); 


/**
	\brief Opens a new connection to a serial port
	\param portname		name of the serial port(COM1 - COM9 or \\\\.\\COM1-COM256)
	\param baudrate		the baudrate of this port (for example 9600)
	\param stopbits		th nuber of stoppbits (one, onePointFive or two)
	\param parity		the parity (even, odd, off or mark)
	\return			HANDLE to the serial port
	*/
HANDLE openSerialPort(LPCSTR portname,enum Baudrate baudrate, enum Stopbits stopbits, enum Paritycheck parity);

/**
	\brief Read data from the serial port
	\param hSerial		File HANDLE to the serial port
	\param buffer		pointer to the area where the read data will be written
	\param buffersize	maximal size of the buffer area
	\return				amount of data that was read
	*/
DWORD readFromSerialPort(HANDLE hSerial, char * buffer, int buffersize);
/**
	\brief write data to the serial port
	\param hSerial	File HANDLE to the serial port
	\param buffer	pointer to the area where the read data will be read
	\param length	amount of data to be read
	\return			amount of data that was written
	*/
DWORD writeToSerialPort(HANDLE hSerial, char * data, int length);

/**
 * Close the port
 * \param hSerial File HANDLE to the serial port that need to be closed
 * Will return false on success
 */
BOOL closeSerialPort(HANDLE hSerial);

#endif
