#ifndef BOOK_H
#define BOOK_H



#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*
 * Book struct.
 * BookNumber is 7 digit, ISBN is 13 digit, Borrow is character.
 */
typedef struct Book
{
	int m_iBookNum ;
	char * m_cName ;
	char * m_cPublisher ;
	char * m_cAuthor ;
	/*char m_cName [ 25 ] ;
	char m_cPublisher [ 25 ] ;
	char m_cAuthor [ 15 ] ;*/
	char * m_cISBN ;
	//long m_lISBN ;
	char * m_cHoldingInstitution ;
	//char m_cHoldingInstitution [ 20 ] ;
	char m_cBorrow ;

	struct Book * m_pPrev ;
	struct Book * m_pNext ;
}  Book ;



#endif