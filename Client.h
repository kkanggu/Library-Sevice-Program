#ifndef CLIENT_H
#define CLIENT_H



#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*
 * Client struct.
 * StudentNumber is 8 digit, other is string.
 */
typedef struct Client
{
	int m_iStudentNum ;
	char * m_cPassword ;
	char * m_cName ;
	char * m_cAddress ;
	char * m_cNumber ;
	/*char m_cPassword [ 15 ] ;
	char m_cName [ 15 ] ;
	char m_cAddress [ 20 ] ;
	char m_cNumber [ 15 ] ;*/

	struct Client * m_pPrev ;
	struct Client * m_pNext ;
}  Client ;



#endif