#include "Library_Service.h"
#define TIME_T_SECOND_30DAY		2592000		;

int iClientCount = 0 ;
int iBookCount = 0 ;
int iBorrowCount = 0 ;
int iBookNum = 0 ;


/*
 * Load File and add to LinkedList
 */
void File_Load ( FILE * fFile , int iFileCheck )
{
	int i = 0 ;
	int iStartIndex = 0 ;
	int iTemp = 0 ;
	char cTemp [ 150 ] ;
	char cInfo [ 50 ] ;


	if ( 1 == iFileCheck )
	{
		while ( ( NULL != fFile ) && ( fgets ( cTemp , 149 , fFile ) ) )
		{
			pClientTail -> m_pPrev -> m_pNext = ( Client * ) malloc ( sizeof ( Client ) ) ;							// pNode -> m_pNext = pNew


			pClientTail -> m_pPrev -> m_pNext -> m_pNext = pClientTail ;											// pNew -> m_pNext = pTail
			pClientTail -> m_pPrev -> m_pNext -> m_pPrev = pClientTail -> m_pPrev ;									// pNew -> m_pPrev = pNode
			pClientTail -> m_pPrev = pClientTail -> m_pPrev -> m_pNext ;											// pTail -> m_pPrev = pNew


			Copy_Nto0 ( cTemp , cInfo , 0 , 0 , 8 ) ;
			pClientTail -> m_pPrev -> m_iStudentNum = atoi ( cInfo ) ;

			i = 11 ;
			iStartIndex = 11 ;
			iTemp = 0 ;
			

			while ( '\n' != cTemp [ i ] )
			{
				++ i ;


				if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 0 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pClientTail -> m_pPrev -> m_cPassword = ( char * ) malloc ( sizeof ( char ) * strlen ( cInfo ) ) ;
					strcpy ( pClientTail -> m_pPrev -> m_cPassword , cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 1 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pClientTail -> m_pPrev -> m_cName = ( char * ) malloc ( sizeof ( char ) * strlen ( cInfo ) ) ;
					strcpy ( pClientTail -> m_pPrev -> m_cName , cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 2 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pClientTail -> m_pPrev -> m_cAddress = ( char * ) malloc ( sizeof ( char ) * strlen ( cInfo ) ) ;
					strcpy ( pClientTail -> m_pPrev -> m_cAddress , cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( '\n' == cTemp [ i ] ) && ( 3 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pClientTail -> m_pPrev -> m_cNumber = ( char * ) malloc ( sizeof ( char ) * strlen ( cInfo ) ) ;
					strcpy ( pClientTail -> m_pPrev -> m_cNumber , cInfo ) ;
//					iStartIndex = i + 1 ;
//					++ iTemp ;
//					++ i ;
				}
			}

			
			++ iClientCount ;
		}
	}
	else if ( 2 == iFileCheck )
	{
		while ( ( NULL != fFile ) && ( fgets ( cTemp , 149 , fFile ) ) )
		{
			pBookTail -> m_pPrev -> m_pNext = ( Client * ) malloc ( sizeof ( Client ) ) ;							// pNode -> m_pNext = pNew


			pBookTail -> m_pPrev -> m_pNext -> m_pNext = pBookTail ;											// pNew -> m_pNext = pTail
			pBookTail -> m_pPrev -> m_pNext -> m_pPrev = pBookTail -> m_pPrev ;									// pNew -> m_pPrev = pNode
			pBookTail -> m_pPrev = pBookTail -> m_pPrev -> m_pNext ;											// pTail -> m_pPrev = pNew


			Copy_Nto0 ( cTemp , cInfo , 0 , 0 , 7 ) ;
			pBookTail -> m_pPrev -> m_iBookNum = atoi ( cInfo ) ;


			if ( pBookTail -> m_pPrev -> m_iBookNum > iBookNum )
				iBookNum = pBookTail -> m_pPrev -> m_iBookNum ;

			i = 10 ;
			iStartIndex = 10 ;
			iTemp = 0 ;
			

			while ( '\n' != cTemp [ i ] )
			{
				++ i ;


				if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 0 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBookTail -> m_pPrev -> m_cName = ( char * ) malloc ( sizeof ( char ) * strlen ( cInfo ) ) ;
					strcpy ( pBookTail -> m_pPrev -> m_cName , cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 1 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBookTail -> m_pPrev -> m_cPublisher = ( char * ) malloc ( sizeof ( char ) * strlen ( cInfo ) ) ;
					strcpy ( pBookTail -> m_pPrev -> m_cPublisher , cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 2 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBookTail -> m_pPrev -> m_cAuthor = ( char * ) malloc ( sizeof ( char ) * strlen ( cInfo ) ) ;
					strcpy ( pBookTail -> m_pPrev -> m_cAuthor , cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 3 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBookTail -> m_pPrev -> m_lISBN = atol ( cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 4 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBookTail -> m_pPrev -> m_cHoldingInstitution = ( char * ) malloc ( sizeof ( char ) * strlen ( cInfo ) ) ;
					strcpy ( pBookTail -> m_pPrev -> m_cHoldingInstitution , cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( '\n' == cTemp [ i ] ) && ( 5 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					pBookTail -> m_pPrev -> m_cBorrow = cTemp [ i - 1 ] ;
//					Copy_Nto0 ( cTemp , pClientTail -> m_cNumber , iStartIndex , 0 , i - iStartIndex ) ;
//					iStartIndex = i + 1 ;
//					++ iTemp ;
//					++ i ;
				}
			}

			
			++ iBookCount ;
		}
	}
	else
	{
		while ( ( NULL != fFile ) && ( fgets ( cTemp , 149 , fFile ) ) )
		{
			pBorrowTail -> m_pPrev -> m_pNext = ( Client * ) malloc ( sizeof ( Client ) ) ;							// pNode -> m_pNext = pNew


			pBorrowTail -> m_pPrev -> m_pNext -> m_pNext = pBorrowTail ;											// pNew -> m_pNext = pTail
			pBorrowTail -> m_pPrev -> m_pNext -> m_pPrev = pBorrowTail -> m_pPrev ;									// pNew -> m_pPrev = pNode
			pBorrowTail -> m_pPrev = pBorrowTail -> m_pPrev -> m_pNext ;											// pTail -> m_pPrev = pNew


			Copy_Nto0 ( cTemp , cInfo , 0 , 0 , 8 ) ;
			pBorrowTail -> m_pPrev -> m_iStudentNum = atoi ( cInfo ) ;

			i = 11 ;
			iStartIndex = 11 ;
			iTemp = 0 ;
			

			while ( '\n' != cTemp [ i ] )
			{
				++ i ;


				if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 0 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBorrowTail -> m_pPrev -> m_iBookNum = atoi ( cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
					
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 1 == iTemp ) )
				{
				//																													type is time_t. Find it!!!!!!!!!!!!!!!!!!!!!
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBorrowTail -> m_tBorrowDate = atol ( cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 2 == iTemp ) )
				{
				//																													type is time_t. Find it!!!!!!!!!!!!!!!!!!!!!
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBorrowTail -> m_tReturnDate = atol ( cInfo ) ;
//					iStartIndex = i + 1 ;
//					++ iTemp ;
//					++ i ;
				}
			}

			
			++ iBorrowCount ;
		}
	}	
}


 /*
  * Save File.
  */
void File_Save ( FILE * fFile , int iFileCheck )
{
	Client * pClientNode = pClientHead -> m_pNext ;
	Book * pBookNode = pBookHead -> m_pNext ;
	Borrow * pBorrowNode = pBorrowHead -> m_pNext ;
	int i = 0 ;


	if ( 1 == iFileCheck )
	{
		if ( iClientCount )
		{
			for ( i = 0 ; i < iClientCount ; ++i )
			{
				fprintf ( fFile , "%d | %s | %s | %s | %s\n" , pClientNode -> m_iStudentNum , pClientNode -> m_cPassword , pClientNode -> m_cName ,
																pClientNode -> m_cAddress , pClientNode -> m_cNumber ) ;
				pClientNode = pClientNode -> m_pNext ;
			}
		}
	}
	else if ( 2 == iFileCheck )
	{
		if ( iBookCount )
		{
			for ( i = 0 ; i < iBookCount ; ++i )
			{
				fprintf ( fFile , "%d | %s | %s | %s | %ld | %s | %c\n" , pBookNode -> m_iBookNum , pBookNode -> m_cName , pBookNode -> m_cPublisher ,
																			pBookNode -> m_cAuthor , pBookNode -> m_lISBN , pBookNode -> m_cHoldingInstitution ,
																			pBookNode -> m_cBorrow ) ;
				pBookNode = pBookNode -> m_pNext ;
			}
		}
	}
	else if ( 3 == iFileCheck )
	{
		if ( iBorrowCount )
		{
			for ( i = 0 ; i < iBorrowCount ; ++i )
			{
				fprintf ( fFile , "%d | %d | %ld | %ld\n" , pBorrowNode -> m_iStudentNum , pBorrowNode -> m_iBookNum ,
															pBorrowNode -> m_tBorrowDate , pBorrowNode -> m_tReturnDate ) ;
				//fprintf ( fFile , "%d | %d | %s | %s\n" , pNode -> m_iStudentNum , pNode -> m_cPassword ,
				//											 pNode -> m_cName , pNode -> m_cAddress , pNode -> m_cNumber ) ;
				// time_t. Check it!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				pBorrowNode = pBorrowNode -> m_pNext ;
			}
		}
	}
	else if ( 4 == iFileCheck )
	{
		fprintf ( fFile , "\n%d | %s | %s | %s | %s\n" , pClientNode -> m_iStudentNum , pClientNode -> m_cPassword , pClientNode -> m_cName ,
															pClientNode -> m_cAddress , pClientNode -> m_cNumber ) ;
	}
	else if ( 5 == iFileCheck )
	{
		fprintf ( fFile , "%d | %s | %s | %s | %ld | %s | %c\n" , pBookNode -> m_iBookNum , pBookNode -> m_cName , pBookNode -> m_cPublisher ,
																	pBookNode -> m_cAuthor , pBookNode -> m_lISBN , pBookNode -> m_cHoldingInstitution ,
																	pBookNode -> m_cBorrow ) ;
	}
	else
	{
		fprintf ( fFile , "%d | %d | %ld | %ld\n" , pBorrowNode -> m_iStudentNum , pBorrowNode -> m_iBookNum ,
													pBorrowNode -> m_tBorrowDate , pBorrowNode -> m_tReturnDate ) ;
				//fprintf ( fFile , "%d | %d | %s | %s\n" , pNode -> m_iStudentNum , pNode -> m_cPassword ,
				//											 pNode -> m_cName , pNode -> m_cAddress , pNode -> m_cNumber ) ;
				// time_t. Check it!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			
	}
}


/*
 * Print Basic Menu.
 */
void ServiceMenu_Print ()
{
	system ( "cls" ) ;
	printf ( ">> 도서관 서비스 <<\n" ) ;
	printf ( "1. 회원 가입\n" ) ;
	printf ( "2. 로그인\n" ) ;
	printf ( "3. 프로그램 종료\n\n" ) ;
}


/*
 * Print Admin Menu.
 */
void ServiceAdmin_Print ()
{
	system ( "cls" ) ;
	printf ( ">> Admin Menu <<\n" ) ;
	printf ( "1. Register Book\t" ) ;
	printf ( "2. Eliminate Book\n" ) ;
	printf ( "3. Borrow Book\t" ) ;
	printf ( "4. Return Book\n" ) ;
	printf ( "5. Search Book\t" ) ;
	printf ( "6. User List\n" ) ;
	printf ( "7. Logout \t" ) ;
	printf ( "8. End Program\n\n" ) ;
}



/*
 * Print User Menu.
 */
void ServiceUser_Print ()
{
	system ( "cls" ) ;
	printf ( ">> User Menu <<\n" ) ;
	printf ( "1. Search Book\t" ) ;
	printf ( "2. My Borrow List\n" ) ;
	printf ( "3. Modify Information.\t" ) ;
	printf ( "4. Quit Member\n" ) ;
	printf ( "5. Logout\t" ) ;
	printf ( "6. End Program\n\n" ) ;
}


/*
 * strcpy, [ n ] to [ 0 ]
 */
void Copy_Nto0 ( char * cpOrigin , char * cpCopy , int iOrigin_Index , int iCopy_Index , int iLength )
{
	int i = 0 ;


	for ( i = 0 ; i < iLength ; ++i )
	{
		cpCopy [ iCopy_Index + i ] = cpOrigin [ iOrigin_Index + i ] ;
	}


	cpCopy [ i ] = '\0' ;
}


/*
 * Register Function.
 * Register new member.
 */
void Register_Member ()
{
	Client * pNode = ( Client * ) malloc ( sizeof ( Client ) ) ;
	Client * pSort = NULL ;
	FILE * fClient = NULL ;


	printf ( "학번, 비밀번호, 이름, 주소 , 전화번호를 입력.\n" ) ;
	printf ( "학번 : " ) ;
	scanf ( "%d" , & pNode -> m_iStudentNum ) ;
	printf ( "비밀번호 : " ) ;
	scanf ( "%s" , pNode -> m_cPassword ) ;
	printf ( "이름 : " ) ;
	scanf ( "%s" , pNode -> m_cName ) ;
	printf ( "주소 : " ) ;
	scanf ( "%s" , pNode -> m_cAddress ) ;
	printf ( "전화번호 : " ) ;
	scanf ( "%s" , pNode -> m_cNumber ) ;


	pSort = Sort_StudentNum_Find_Member ( pNode ) ;
	
	
	if ( NULL == pSort )
	{
		free ( pNode ) ;
		
		printf ( "Same Student Number. Register failed.\n" ) ;
	}
	else
	{
//		Remove_Line_Escape_Sequence ( pNode ) ;

		pSort -> m_pNext -> m_pPrev = pNode ;
		pNode -> m_pNext = pSort -> m_pNext ;
		pSort -> m_pNext = pNode ;
		pNode -> m_pPrev = pSort ;

		++ iClientCount ;
		

		fClient = fopen ( "Client.txt" , "a" ) ;
		File_Save ( fClient , 4 ) ;
		fclose ( fClient ) ;


		printf ( "Register end.\n" ) ;
	}
}


/*
 * Parameter Node need to be sorted.
 * Compare Node's Student Number, and find sequence.
 * return value is pSort.
 * pSort -> m_pNext = pNode
 */
Client * Sort_StudentNum_Find_Member ( Client * pNode )
{
	Client * pSort = pClientHead ;
	int iSortNumber = 0 ;
	int iNodeNumber = pNode -> m_iStudentNum ;


	while ( pSort -> m_pNext != pClientTail )
	{
		pSort = pSort -> m_pNext ;
		iSortNumber = pSort -> m_iStudentNum ;

		
		if ( iNodeNumber == iSortNumber )
		{
			pSort = NULL ;

			break ;
		}
		else if ( iSortNumber > iNodeNumber )			// SortNumber is 20161112 , NodeNumber is 20161111
		{
			pSort = pSort -> m_pPrev ;

			break ;
		}
	}
	
	
	return pSort ;
}


/*
 *
 */
/* void Login_Main ()
{
	Client * pNode = Login_Member ;


	if ( NULL == pNode )
	{
		
	}
	else if ( pClientHead == pNode )
	{

	}
	else
	{

	}
} */


/*
 * Login Function.
 */
void Login_Member ()
{
	Client * pNode = pClientHead ;
	char cUser [ 20 ] ;
	char cPassword [ 20 ] ;
	
	
	printf ( "Num : " ) ;
	scanf ( "%s" , cUser ) ;
	printf ( "Password : " ) ;
	scanf ( "%s" , cPassword ) ;


	while ( pNode -> m_pNext != pClientTail )
	{
		pNode = pNode -> m_pNext ;

		
		if ( ! strcmp ( "admin" , cUser ) )
		{
			pUser = pClientHead ;

			break ;
		}
		else if ( ( atoi ( cUser ) ) == ( pNode -> m_iStudentNum ) )			// SortNumber is 20161112 , NodeNumber is 20161111
		{
			if ( ! strcmp ( cPassword , pNode -> m_cPassword ) )
			{
				pUser = pNode ;

				break ;
			}
			else
			{
				pUser = NULL ;

				break ;
			}
		}
	}
}


/*
 * Register Function.
 * Register Book.
 */
void Register_Book ()
{
	Book * pNode = ( Book * ) malloc ( sizeof ( Book ) ) ;
	Book * pSort = NULL ;
	FILE * fBook = NULL ;

	printf ( "도서명, 출판사, 저자명, ISBN , 소장처 입력.\n" ) ;
	printf ( "도서명 : " ) ;
	scanf ( "%s" , pNode -> m_cName ) ;
	printf ( "출판사 : " ) ;
	scanf ( "%s" , pNode -> m_cPublisher ) ;
	printf ( "저자명 : " ) ;
	scanf ( "%s" , pNode -> m_cAuthor ) ;
	printf ( "ISBN : " ) ;
	scanf ( "%ld" , & pNode -> m_lISBN ) ;
	printf ( "소장처 : " ) ;
	scanf ( "%s" , pNode -> m_cHoldingInstitution ) ;


	pSort = Sort_ISBN_Find_Book ( pNode ) ;
	
	
/*	if ( NULL == pSort )
	{
		free ( pNode ) ;
		
		printf ( "Same Student Number. Register failed.\n" ) ;
	} */
	if ( NULL != pSort )									// Why?
	{
//		Remove_Line_Escape_Sequence ( pNode ) ;

		pSort -> m_cBorrow = 'Y' ;
		pSort -> m_iBookNum = iBookNum + 1 ;
		++ iBookNum ;
		pSort -> m_pNext -> m_pPrev = pNode ;
		pNode -> m_pNext = pSort -> m_pNext ;
		pSort -> m_pNext = pNode ;
		pNode -> m_pPrev = pSort ;

		++ iBookCount ;


		fBook = fopen ( "Book.txt" , "a" ) ;
		File_Save ( fBook , 5 ) ;
		fclose ( fBook ) ;


		printf ( "Register end.\n" ) ;
	}

	// ISBN
}


/*
 * Parameter Node need to be sorted.
 * Compare Node's ISBN, and find sequence.
 * return value is pSort.
 * pSort -> m_pNext = pNode
 */
Book * Sort_ISBN_Find_Book ( Book * pNode )
{
	Book * pSort = pClientHead ;
	long lSortISBN = 0 ;
	long lNodeISBN = pNode -> m_lISBN ;


	while ( pSort -> m_pNext != pBookTail )
	{
		pSort = pSort -> m_pNext ;
		lSortISBN = pSort -> m_lISBN ;

		
/*		if ( lNodeISBN == lSortISBN )
		{
			pSort = NULL ;

			break ;
		} */
		if ( lSortISBN > lNodeISBN )			// SortISBN is 20160805111 , NodeNumber is 20160805112
		{
			pSort = pSort -> m_pPrev ;

			break ;
		}
	}
	
	
	return pSort ;
}


/*
 * Eliminate Book.
 */
void Eliminate_Book ()
{
	int iMenu = 0 ;
	Book * pNode = NULL ;
	Book * pEliPrev = NULL ;
	Book * pEliNext = NULL ;
	FILE * fBook = NULL ;


	printf ( "1. Name\t" ) ;
	printf ( "2. ISBN\n" ) ;

	scanf ( "%d" , & iMenu ) ;


	pNode = Search_Book ( iMenu ) ;
	
	
	if ( NULL != pNode )
	{
		Print_Book_Information ( pNode ) ;
		pNode = Search_Book ( 5 ) ;
	}


	if ( ( NULL != pNode ) && ( 'Y' == pNode -> m_cBorrow ) )
	{
		pEliPrev = pNode -> m_pPrev ;
		pEliNext = pNode -> m_pNext ;
		pEliPrev -> m_pNext = pEliNext ;
		pEliNext -> m_pPrev = pEliPrev ;
		-- iBookCount ;


		if ( pNode -> m_iBookNum == iBookNum )
			BookNumber_ReSetting () ;


		free ( pNode ) ;


		fBook = fopen ( "Book.txt" , "w+" ) ;
		File_Save ( fBook , 2 ) ;
		fclose ( fBook ) ;
	}
	else if ( ( NULL != pNode ) && ( 'N' == pNode -> m_cBorrow ) )
	{
		printf ( "You can't eliminate it.\n" ) ;
	}
	else
		printf ( "도서가 존재하지 않습니다.\n" ) ;
}


/*
 * Eliminate Borrowed Book.
 */
void Eliminate_Borrow ( Borrow * pNode )
{
	Borrow * pEliPrev = pNode -> m_pPrev ;
	Borrow * pEliNext = pNode -> m_pNext ;
	FILE * fBorrow = NULL ;


	pEliPrev -> m_pNext = pEliNext ;
	pEliNext -> m_pPrev = pEliPrev ;
	-- iBorrowCount ;


	free ( pNode ) ;


	fBorrow = fopen ( "Borrow.txt" , "w+" ) ;
	File_Save ( fBorrow , 3 ) ;
	fclose ( fBorrow ) ;
}


/*
 * iBookNum is eliminated, so value has to be changed.
 */
void BookNumber_ReSetting ()
{
	Book * pNode = pBookHead ;


	iBookNum = 0 ;


	while ( pNode -> m_pNext != pBookTail )
	{
		pNode = pNode -> m_pNext ;

	
		if ( pNode -> m_iBookNum > iBookNum )
			iBookNum = pNode -> m_iBookNum ;
	}
}


/*
 * Borrow Book.
 */
void Borrow_Book ()
{
	int iMenu = 0 ;
	int iTempBookNum = 0 ;
	int iStudentNum = 0 ;
	time_t tTime = 0 ;
	Client * pClientNode = pClientHead ;
	Book * pBookNode = pBookHead ;
	Borrow * pBorrowNode = pBorrowHead ;
	FILE * fBorrow = NULL ;


	printf ( "1. Name\t" ) ;
	printf ( "2. ISBN\n" ) ;

	scanf ( "%d" , & iMenu ) ;


	pBookNode = Search_Book ( iMenu ) ;
	
	
	if ( NULL != pBookNode )
	{
		Print_Book_Information ( pBookNode ) ;

		printf ( "Student Number : " ) ;
		scanf ( "%d" , & iStudentNum ) ;
		printf ( "Book Number : " ) ;
		scanf ( "%d" , & iTempBookNum ) ;


		while ( pClientNode -> m_pNext != pClientTail )
		{
			pClientNode = pClientNode -> m_pNext ;

	
			if ( pClientNode -> m_iStudentNum == iStudentNum )
				break ;
		}
		while ( pBookNode -> m_pNext != pClientTail )
		{
			pBookNode = pBookNode -> m_pNext ;

	
			if ( pBookNode -> m_iBookNum == iTempBookNum )
				break ;
		}


		if ( pClientNode -> m_pNext == pClientTail )
		{
			printf ( "Client doesn't exist.\n" ) ;
		}
		else if ( pBookNode -> m_pNext == pBookTail )
		{
			printf ( "Book doesn't exist.\n" ) ;
		}
		else if ( 'N' == pBookNode -> m_cBorrow )
		{
			printf ( "Can't borrow that book.\n" ) ;
		}
		else
		{
			pBookNode -> m_cBorrow = 'N' ;
			
			pBorrowNode = ( Borrow * ) malloc ( sizeof ( Borrow * ) ) ;

			pBorrowNode -> m_iStudentNum = pClientNode -> m_iStudentNum ;
			pBorrowNode	-> m_iBookNum = pBookNode -> m_iBookNum ;
			time ( & tTime ) ;
			pBorrowNode -> m_tBorrowDate = tTime ;
			pBorrowNode -> m_tReturnDate = Set_Return_Date ( tTime ) ;

			pBorrowTail -> m_pPrev -> m_pNext = pBorrowNode ;
			pBorrowNode -> m_pPrev = pBorrowTail -> m_pPrev ;
			pBorrowTail -> m_pPrev = pBorrowNode ;
			pBorrowNode -> m_pNext = pBorrowTail ;

			++ iBorrowCount ;

			printf ( "Book has been borrowed.\n" ) ;


			fBorrow = fopen ( "Borrow.txt" , "a" ) ;
			File_Save ( fBorrow , 6 ) ;
			fclose ( fBorrow ) ;


			free ( pBorrowNode ) ;
		}
	}
}


/*
 * Set returning date.
 * If returning date is Sunday, set it Monday. + 1 day.
 */
time_t Set_Return_Date ( time_t tTime )
{
	char cTemp [ 26 ] ;


	tTime += TIME_T_SECOND_30DAY ;
	strncpy ( cTemp , ctime ( tTime ) , 26 ) ;
	
	
	if ( ( 'S' == cTemp [ 23 ] ) && ( 'U' == cTemp [ 24 ] ) && ( 'N' == cTemp [ 25 ] ) )
		tTime += 86400 ;


	return tTime ;
}


/*
 * Return the borrowed book.
 */
void Return_Book ()
{
	int iStudentNum = 0 ;
	int * irgBookNum = NULL ;
	int iTemp = 0 ;
	int i = 0 ;
	char cTemp ;
	Client * pClientNode = pClientHead ;
	Book * pBookNode = pBookHead ;
	Borrow * pBorrowNode = pBorrowHead ;
	int iStudentBorrow = 0 ;


	printf ( "Input student number : " ) ;
	scanf ( "%d" , & iStudentNum ) ;


	while ( pClientNode -> m_pNext != pClientTail )
	{
		pClientNode = pClientNode -> m_pNext ;

	
		if ( iStudentNum == pClientNode -> m_iStudentNum )
			break ;
	}
	while ( ( pClientTail != pClientNode -> m_pNext ) && ( pBorrowNode -> m_pNext != pBorrowTail ) )
	{
		pBorrowNode = pBorrowNode -> m_pNext ;


		if ( iStudentNum == pBorrowNode -> m_iStudentNum )
		{
			++ iStudentBorrow ;
		}
	}
	if ( iStudentBorrow )
	{
		pBorrowNode = pBorrowHead ;
		irgBookNum = ( int * ) malloc ( iStudentBorrow * sizeof ( int ) ) ;


		while ( i != iStudentNum )
		{
			if ( pBorrowTail == pBorrowNode -> m_pNext )
			{
				pBorrowNode = pBorrowHead ;
			}


			pBorrowNode = pBorrowNode -> m_pNext ;
			pBookNode = pBookHead ;


			if ( iStudentNum == pBorrowNode -> m_iStudentNum )
			{
				while ( pBookTail != pBookHead -> m_pNext )
				{
					if ( pBorrowNode -> m_iBookNum == pBookNode -> m_iBookNum )
						break ;
				}


				Print_Borrow_Information ( pBorrowNode , pBookNode ) ;
				irgBookNum [ i ] = pBorrowNode -> m_iStudentNum ;
				++i ;
			}
		}


		printf ( "Input returning book number : " ) ;
		scanf ( "%d" , & iTemp ) ;


		while ( iTemp != irgBookNum [ i ] )
		{
			++ i ;
		}
		if ( i == iStudentBorrow )
		{
			printf ( "BookNumber is Wrong.\n" ) ;
		}
		else
		{
			printf ( "Return the book? : " ) ;
			scanf ( "%c" , & cTemp ) ;


			if ( 'Y' == cTemp )
			{
				pBookNode = pBookHead ;


				while ( pBookTail != pBookNode -> m_pNext )
				{
					pBookNode = pBookNode -> m_pNext ;


					if ( irgBookNum [ i ] == pBookNode -> m_iBookNum )
						break ;
				}	


				pBookNode -> m_cBorrow = 'Y' ;
				Eliminate_Borrow ( pBorrowNode ) ;
			}
		}

		free ( irgBookNum ) ;
	}
}


/*
 * Search Client.
 * Name, Student Number, Every Student.
 */
Client * Search_Client ()
{
	int iMenu = 0 ;
	char * cName = NULL ;
	int iTempStudentNum ;
	Client * pNode = pClientHead ;


	while ( 4 != iMenu )
	{
		printf ( "1. Name Search\t" ) ;
		printf ( "2. Student Number Search\n" ) ;
		printf ( "3. All Search\t" ) ;
		printf ( "4. Previous Menu\n" ) ;
		
		scanf ( "%d" , & iMenu ) ;


		if ( 1 == iMenu )
		{
			printf ( "Input Name : " ) ;
			scanf ( "%s" , cName ) ;


			while ( pClientTail != pNode -> m_pNext)
			{
				pNode = pNode -> m_pNext ;


				if ( ! strcmp ( cName , pNode -> m_cName ) )
					break ;
			}


			Print_User ( pNode ) ;
		}
		else if ( 2 == iMenu )
		{
			printf ( "Input Student Number : " ) ;
			scanf ( "%d" , & iTempStudentNum ) ;


			while ( pClientTail != pNode -> m_pNext)
			{
				pNode = pNode -> m_pNext ;


				if ( iTempStudentNum == pNode -> m_iStudentNum )
					break ;
			}


			Print_User ( pNode ) ;
		}
		else if ( 3 == iMenu )
		{
			while ( pClientTail != pNode -> m_pNext )
			{
				pNode = pNode -> m_pNext ;

				Print_User ( pNode ) ;
			}
		}
		else if ( 5 != iMenu )
		{
			printf ( "Wrong menu. Try again.\n" ) ;
		}
	}
}


/*
 * Search Specific Book.
 * Name, ISBN, Publisher, Author, BookNumber
 */
Book * Search_Book ( int iMenu )
{
	char * cName = NULL ;
	long lISBN = 0 ;
	char * cPublisher = NULL ;
	char * cAuthor = NULL ;
	int iBookNum = 0 ;
	Book * pNode = pBookHead ;


	if ( ! iMenu )
	{
		printf ( "1. Name\t" ) ;
		printf ( "2. ISBN\n" ) ;
		printf ( "3. Publisher\t" ) ;
		printf ( "4. Author\n" ) ;

		scanf ( "%d" , & iMenu ) ;

		//도서명 ISBN 출판사 저자명 도서번호
	}


	if ( 1 == iMenu )	// Name
	{
		printf ( "Input Book Name : " ) ;
		scanf ( "%s" , cName ) ;


		while ( pNode -> m_pNext != pBookTail )
		{
			pNode = pNode -> m_pNext ;

		
/*			if ( lNodeISBN == lSortISBN )
			{
				pSort = NULL ;

				break ;
			} */
			if ( ! strcmp ( cName , pNode -> m_cName ) )			// SortISBN is 20160805111 , NodeNumber is 20160805112
			{
				break ;
			}
		}
	}
	else if ( 2 == iMenu ) // ISBN
	{
		printf ( "Input ISBN : " ) ;
		scanf ( "ld" , & lISBN ) ;


		while ( pNode -> m_pNext != pBookTail )
		{
			pNode = pNode -> m_pNext ;


			if ( lISBN == pNode -> m_lISBN )
			{
				break ;
			}
		}
	}
	else if ( 3 == iMenu ) // Publisher
	{
		printf ( "Input Publisher : " ) ;
		scanf ( "%s" , cPublisher ) ;


		while ( pNode -> m_pNext != pBookTail )
		{
			pNode = pNode -> m_pNext ;


			if ( ! strcmp ( cPublisher , pNode -> m_cPublisher ) )
			{
				break ;
			}
		}
	}
	else if ( 4 == iMenu ) // Author
	{
		printf ( "Input Author : " ) ;
		scanf ( "%s" , cAuthor ) ;


		while ( pNode -> m_pNext != pBookTail )
		{
			pNode = pNode -> m_pNext ;


			if ( ! strcmp ( cAuthor , pNode -> m_cAuthor ) )
			{
				break ;
			}
		}
	}
	else
	{
		printf ( "Input Book Num : " ) ;
		scanf ( "%d" , & iBookNum ) ;


		while ( pNode -> m_pNext != pBookTail )
		{
			pNode = pNode -> m_pNext ;


			if ( iBookNum == pNode -> m_iBookNum )
			{
				break ;
			}
		}
	}


	if ( pNode -> m_pNext == pBookTail )
		pNode = NULL ;


	return pNode ;
}


/*
 * Logout.
 */
void Logout_Member ()
{
	pUser = NULL ;
}


/*
 * End Program.
 */
void Program_End ()
{
	// Save.
	exit ( 1 ) ;
}


/*
 * Print User's Borrow List.\n
 */
void My_Borrow_List ()
{
	int iMyBorrow = 0 ;
//	int * irgBookNum = NULL ;
	Book * pBookNode = pBookHead ;
	Borrow * pBorrowNode = pBorrowHead ;


	while ( pBorrowNode -> m_pNext != pBorrowTail )
	{
		pBorrowNode = pBorrowNode -> m_pNext ;


		if ( pUser -> m_iStudentNum == pBorrowNode -> m_iStudentNum )
		{
			++ iMyBorrow ;
		}
	}
	if ( iMyBorrow )
	{
		pBorrowNode = pBorrowHead ;
//		irgBookNum = ( int * ) malloc ( iMyBorrow * sizeof ( int ) ) ;


		while ( iMyBorrow )
		{
			if ( pBorrowTail == pBorrowNode -> m_pNext )
			{
				pBorrowNode = pBorrowHead ;
			}


			pBorrowNode = pBorrowNode -> m_pNext ;
			pBookNode = pBookHead ;


			if ( pUser -> m_iStudentNum == pBorrowNode -> m_iStudentNum )
			{
/*				while ( pBookTail != pBookHead -> m_pNext )
				{
					if ( pBorrowNode -> m_iBookNum == pBookNode -> m_iBookNum )
						break ;
				} */


				Print_Borrow_Information ( pBorrowNode , pBookNode ) ;
//				irgBookNum [ i ] = pBorrowNode -> m_iStudentNum ;
//				++i ;
				-- iMyBorrow ;
			}
		}
	}
}


/*
 * Modify User's Information.
 */
void Modify_Member ()
{
	printf ( "Modify information except student number, and name.\n" ) ;
	printf ( "Password : " ) ;
	scanf ( "%s" , pUser -> m_cPassword ) ;
	printf ( "Address : " ) ;
	scanf ( "%s" , pUser -> m_cAddress ) ;
	printf ( "Phone Number : " ) ;
	scanf ( "%s" , pUser -> m_cNumber ) ;

	printf ( "Modify End.\n" ) ;
}


/*
 * Quit Member.
 * If user borrow the book, user can't quit.
 */
void Quit_Member ()
{
	Client * pEliPrev = pUser -> m_pPrev ;
	Client * pEliNext = pUser -> m_pNext ;
	Borrow * pBorrowNode = pBorrowHead ;
	FILE * fClient = NULL ;


	while ( pBorrowTail != pBorrowNode -> m_pNext )
	{
		pBorrowNode = pBorrowNode -> m_pNext ;


		if ( pUser -> m_iStudentNum == pBorrowNode -> m_iStudentNum )
			break ;
	}

	if ( pBorrowTail == pBorrowNode -> m_pNext )
	{
		pEliPrev -> m_pNext = pEliNext ;
		pEliNext -> m_pPrev = pEliPrev ;
		-- iClientCount ;


		free ( pUser ) ;


		fClient = fopen ( "Client.txt" , "w+" ) ;
		File_Save ( fClient , 1 ) ;
		fclose ( fClient ) ;


		pUser = NULL ;
	}
	else
	{
		printf ( "User borrowed the book. User can't quit.\n" ) ;
	}
}



void Print_UserList () ;
/*
 * Print One User's Information.
 */
void Print_User ( Client * pNode )
{
	if ( NULL != pNode )
	{
		printf ( "Student Number : %d\n" , pNode -> m_iStudentNum ) ;
		printf ( "Name : %s\n" , pNode -> m_cName ) ;
		printf ( "Address : %s\n" , pNode -> m_cAddress ) ;
		printf ( "Phone Number : %s\n" , pNode -> m_cNumber ) ;
	}
}



/*
 * Print Book Information.
 */
void Print_Book_Information ( Book * pNode )
{
	if ( NULL != pNode )
	{
		printf ( "Book Number : %d\n" , pNode -> m_iBookNum ) ;
		printf ( "Book Name : %s\n" , pNode -> m_cName ) ;
		printf ( "Publisher : %s\n" , pNode -> m_cPublisher ) ;
		printf ( "Author : %s\n" , pNode -> m_cAuthor ) ;
		printf ( "ISBN : %ld\n" , pNode -> m_lISBN ) ;
		printf ( "Holding Institution : %s\n" , pNode -> m_cHoldingInstitution ) ;
		printf ( "Eliminate or Borrow Possbile : %c\n" , pNode -> m_cBorrow ) ;	
	}
	else
	{
		printf ( "That book doesn't exist.\n" ) ;
	}
}


/*
 * Print Borrow Book's Information.
 */
void Print_Borrow_Information ( Borrow * pBorrowNode , Book * pBookNode )
{
	if ( ( NULL != pBorrowNode ) && ( NULL != pBookNode ) )
	{
		printf ( "Book Number : %d\n" , pBookNode -> m_iBookNum ) ;
		printf ( "Book Name : %s\n" , pBookNode -> m_cName ) ;
		printf ( "Borrow Date : %d\n" , 1 ) ;
		printf ( "Return Date : %d\n\n" , 1 ) ;
	}
}


/*
 * free or delete all malloc or new.
 */
void All_free ()
{
	Client * pClientNode = pClientHead ;
	Book * pBookNode = pBookHead ;
	Borrow * pBorrowNode = pBorrowHead ;


	while ( pClientTail != pClientNode )
	{
		free ( pClientNode -> m_cAddress ) ;
		free ( pClientNode -> m_cName ) ;
		free ( pClientNode -> m_cNumber ) ;
		free ( pClientNode -> m_cPassword ) ;

		pClientNode = pClientNode -> m_pNext ;

		free ( pClientNode -> m_pPrev ) ;
	}
	while ( pBookTail != pBookNode )
	{
		free ( pBookNode -> m_cAuthor ) ;
		free ( pBookNode -> m_cHoldingInstitution ) ;
		free ( pBookNode -> m_cName ) ;
		free ( pBookNode -> m_cPublisher ) ;

		pBookNode = pBookNode -> m_pNext ;

		free ( pBookNode -> m_pPrev ) ;
	}
	while ( pBorrowTail != pBorrowNode )
	{
		pBorrowNode = pBorrowNode -> m_pNext ;

		free ( pBorrowNode -> m_pPrev ) ;
	}

	free ( pClientNode ) ;
	free ( pBookNode ) ;
	free ( pBorrowNode ) ;
}