#include "Library_Service.h"
#define TIME_T_SECOND_30DAY		2592000		;

int iClientCount = 0 ;
int iBookCount = 0 ;
int iBorrowCount = 0 ;
int iBookNum = 0 ;
Client * pUser = NULL ;				// Login. NULL is noOne, ClientHead is admin. Other people, that people login.


/*
 * Load File and add to LinkedList
 */
void File_Load ( FILE * fFile , int iFileCheck )
{
	Client * pClientNode = NULL ;
	Client * pClientSort = NULL ;
	Book * pBookNode = NULL ;
	Book * pBookSort = NULL ;
	Borrow * pBorrowNode = NULL ;
	int i = 0 ;
	int iStartIndex = 0 ;
	int iTemp = 0 ;
	char cTemp [ 150 ] ;
	char cInfo [ 50 ] ;


	if ( 1 == iFileCheck )
	{
		while ( ( NULL != fFile ) && ( fgets ( cTemp , 149 , fFile ) ) )
		{
			pClientNode = ( Client * ) malloc ( sizeof ( Client ) ) ;							// pNode -> m_pNext = pNew
			Copy_Nto0 ( cTemp , cInfo , 0 , 0 , 8 ) ;
			pClientNode -> m_iStudentNum = atoi ( cInfo ) ;

			i = 11 ;
			iStartIndex = 11 ;
			iTemp = 0 ;
			

			while ( '\n' != cTemp [ i ] )
			{
				++ i ;


				if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 0 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					//Copy_Nto0 ( cTemp , pClientNode -> m_cPassword , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pClientNode -> m_cPassword = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cInfo ) + 1 ) ) ;
					strncpy ( pClientNode -> m_cPassword , cInfo , strlen ( cInfo ) ) ;
					pClientNode -> m_cPassword [ strlen ( cInfo ) ] = '\0' ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 1 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					//Copy_Nto0 ( cTemp , pClientNode -> m_cName , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pClientNode -> m_cName = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cInfo ) + 1 ) ) ;
					strncpy ( pClientNode -> m_cName , cInfo , strlen ( cInfo ) ) ;
					pClientNode -> m_cName [ strlen ( cInfo ) ] = '\0' ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 2 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					//Copy_Nto0 ( cTemp , pClientNode -> m_cAddress , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pClientNode -> m_cAddress = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cInfo ) + 1 ) ) ;
					strncpy ( pClientNode -> m_cAddress , cInfo , strlen ( cInfo ) ) ;
					pClientNode -> m_cAddress [ strlen ( cInfo ) ] = '\0' ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( '\n' == cTemp [ i ] ) && ( 3 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					//Copy_Nto0 ( cTemp , pClientNode -> m_cNumber , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex ) ;
					pClientNode -> m_cNumber = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cInfo ) + 1 ) ) ;
					strncpy ( pClientNode -> m_cNumber , cInfo , strlen ( cInfo ) ) ;
					pClientNode -> m_cNumber [ strlen ( cInfo ) ] = '\0' ;
//					iStartIndex = i + 1 ;
//					++ iTemp ;
//					++ i ;
				}
			}


			pClientSort = Sort_StudentNum_Find_Member ( pClientNode ) ;

			pClientSort -> m_pNext -> m_pPrev = pClientNode ;
			pClientNode -> m_pNext = pClientSort -> m_pNext ;
			pClientSort -> m_pNext = pClientNode ;
			pClientNode -> m_pPrev = pClientSort ;


//			pClientTail -> m_pPrev -> m_pNext -> m_pNext = pClientTail ;											// pNew -> m_pNext = pTail
//			pClientTail -> m_pPrev -> m_pNext -> m_pPrev = pClientTail -> m_pPrev ;									// pNew -> m_pPrev = pNode
//			pClientTail -> m_pPrev = pClientTail -> m_pPrev -> m_pNext ;											// pTail -> m_pPrev = pNew

			
			++ iClientCount ;
		}
	}
	else if ( 2 == iFileCheck )
	{
		while ( ( NULL != fFile ) && ( fgets ( cTemp , 149 , fFile ) ) )
		{
			pBookNode = ( Book * ) malloc ( sizeof ( Book ) ) ;							// pNode -> m_pNext = pNew
			Copy_Nto0 ( cTemp , cInfo , 0 , 0 , 7 ) ;
			pBookNode -> m_iBookNum = atoi ( cInfo ) ;


			if ( pBookNode -> m_iBookNum > iBookNum )
				iBookNum = pBookNode -> m_iBookNum ;

			i = 10 ;
			iStartIndex = 10 ;
			iTemp = 0 ;
			

			while ( '\n' != cTemp [ i ] )
			{
				++ i ;


				if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 0 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					//Copy_Nto0 ( cTemp , pBookNode -> m_cName , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBookNode -> m_cName = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cInfo ) + 1 ) ) ;
					strncpy ( pBookNode -> m_cName , cInfo , strlen ( cInfo ) ) ;
					pBookNode -> m_cName [ strlen ( cInfo ) ] = '\0' ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 1 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					//Copy_Nto0 ( cTemp , pBookNode -> m_cPublisher , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBookNode -> m_cPublisher = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cInfo ) + 1 ) ) ;
					strncpy ( pBookNode -> m_cPublisher , cInfo , strlen ( cInfo ) ) ;
					pBookNode -> m_cPublisher [ strlen ( cInfo ) ] = '\0' ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 2 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					//Copy_Nto0 ( cTemp , pBookNode -> m_cAuthor , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBookNode -> m_cAuthor = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cInfo ) + 1 ) ) ;
					strncpy ( pBookNode -> m_cAuthor , cInfo , strlen ( cInfo ) ) ;
					pBookNode -> m_cAuthor [ strlen ( cInfo ) ] = '\0' ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 3 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBookNode -> m_cISBN = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cInfo ) + 1 ) ) ;
					strncpy ( pBookNode -> m_cISBN , cInfo , strlen ( cInfo ) ) ;
					pBookNode -> m_cISBN [ strlen ( cInfo ) ] = '\0' ;
					//pBookNode -> m_lISBN = atol ( cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 4 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					//Copy_Nto0 ( cTemp , pBookNode -> m_cHoldingInstitution , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex - 2 ) ;
					pBookNode -> m_cHoldingInstitution = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cInfo ) + 1 ) ) ;
					strncpy ( pBookNode -> m_cHoldingInstitution , cInfo , strlen ( cInfo ) ) ;
					pBookNode -> m_cHoldingInstitution [ strlen ( cInfo ) ] = '\0' ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( '\n' == cTemp [ i ] ) && ( 5 == iTemp ) )
				{
//					cTemp [ i - 1 ] = '\0' ;
					pBookNode -> m_cBorrow = cTemp [ i - 1 ] ;
//					Copy_Nto0 ( cTemp , pClientTail -> m_cNumber , iStartIndex , 0 , i - iStartIndex ) ;
//					iStartIndex = i + 1 ;
//					++ iTemp ;
//					++ i ;
				}
			}


			pBookSort = Sort_ISBN_Find_Book ( pBookNode ) ;

			pBookSort -> m_pNext -> m_pPrev = pBookNode ;
			pBookNode -> m_pNext = pBookSort -> m_pNext ;
			pBookSort -> m_pNext = pBookNode ;
			pBookNode -> m_pPrev = pBookSort ;

//			pBookTail -> m_pPrev -> m_pNext -> m_pNext = pBookTail ;											// pNew -> m_pNext = pTail
//			pBookTail -> m_pPrev -> m_pNext -> m_pPrev = pBookTail -> m_pPrev ;									// pNew -> m_pPrev = pNode
//			pBookTail -> m_pPrev = pBookTail -> m_pPrev -> m_pNext ;											// pTail -> m_pPrev = pNew
			
			++ iBookCount ;
		}
	}
	else
	{
		while ( ( NULL != fFile ) && ( fgets ( cTemp , 149 , fFile ) ) )
		{
			pBorrowNode = ( Borrow * ) malloc ( sizeof ( Borrow ) ) ;
//			pBorrowTail -> m_pPrev -> m_pNext = ( Borrow * ) malloc ( sizeof ( Borrow ) ) ;							// pNode -> m_pNext = pNew

			
			pBorrowNode -> m_pNext = pBorrowTail ;											// pNew -> m_pNext = pTail
			pBorrowNode -> m_pPrev = pBorrowTail -> m_pPrev ;								// pNew -> m_pPrev = pNode
			pBorrowNode -> m_pPrev -> m_pNext = pBorrowNode ;								// pNode -> m_pNext = pNew
			pBorrowTail -> m_pPrev = pBorrowNode ;											// pTail -> m_pPrev = pNew


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
					pBorrowTail -> m_pPrev -> m_tBorrowDate = atol ( cInfo ) ;
					iStartIndex = i + 1 ;
					++ iTemp ;
					++ i ;
				}
				else if ( ( '\n' == cTemp [ i ] ) && ( 2 == iTemp ) )
//				else if ( ( ' ' == cTemp [ i - 2 ] ) && ( '|' == cTemp [ i - 1  ] ) && ( ' ' == cTemp [ i ] ) && ( 2 == iTemp ) )
				{
				//																													type is time_t. Find it!!!!!!!!!!!!!!!!!!!!!
//					cTemp [ i - 1 ] = '\0' ;
					Copy_Nto0 ( cTemp , cInfo , iStartIndex , 0 , i - iStartIndex ) ;
					pBorrowTail -> m_pPrev -> m_tReturnDate = atol ( cInfo ) ;
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
				fprintf ( fFile , "%d | %s | %s | %s | %s | %s | %c\n" , pBookNode -> m_iBookNum , pBookNode -> m_cName , pBookNode -> m_cPublisher ,
																			pBookNode -> m_cAuthor , pBookNode -> m_cISBN , pBookNode -> m_cHoldingInstitution ,
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
				fprintf ( fFile , "%d | " , pBorrowNode -> m_iStudentNum ) ;
				fprintf ( fFile , "%d | " , pBorrowNode -> m_iBookNum ) ;
				fprintf ( fFile , "%ld | " , pBorrowNode -> m_tBorrowDate ) ;
				fprintf ( fFile , "%ld\n" , pBorrowNode -> m_tReturnDate ) ;
//				fprintf ( fFile , "%d | %d | %ld | %ld\n" , pBorrowNode -> m_iStudentNum , pBorrowNode -> m_iBookNum ,
//															pBorrowNode -> m_tBorrowDate , pBorrowNode -> m_tReturnDate ) ;
				//fprintf ( fFile , "%d | %d | %s | %s\n" , pNode -> m_iStudentNum , pNode -> m_cPassword ,
				//											 pNode -> m_cName , pNode -> m_cAddress , pNode -> m_cNumber ) ;
				// time_t. Check it!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				pBorrowNode = pBorrowNode -> m_pNext ;
			}
		}
	}
	else
	{
		pBorrowNode = pBorrowTail -> m_pPrev ;

		fprintf ( fFile , "%d | " , pBorrowNode -> m_iStudentNum ) ;
		fprintf ( fFile , "%d | " , pBorrowNode -> m_iBookNum ) ;
		fprintf ( fFile , "%ld | " , pBorrowNode -> m_tBorrowDate ) ;
		fprintf ( fFile , "%ld\n" , pBorrowNode -> m_tReturnDate ) ;
//		fprintf ( fFile , "%d | %d | %ld | %ld\n" , pBorrowNode -> m_iStudentNum , pBorrowNode -> m_iBookNum ,
//													pBorrowNode -> m_tBorrowDate , pBorrowNode -> m_tReturnDate ) ;
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
	char cTemp [ 50 ] ;


	printf ( "학번, 비밀번호, 이름, 주소 , 전화번호를 입력.\n" ) ;
	printf ( "학번 : " ) ;
	scanf ( "%d" , & pNode -> m_iStudentNum ) ;
	fflush ( stdin ) ;
	
	printf ( "비밀번호 : " ) ;
//	scanf ( "%s" , pNode -> m_cPassword ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;
	
	pNode -> m_cPassword = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cTemp ) + 1 ) ) ;
	strncpy ( pNode -> m_cPassword , cTemp , strlen ( cTemp ) ) ;
	pNode -> m_cPassword [ strlen ( cTemp ) ] = '\0' ;

	printf ( "이름 : " ) ;
//	scanf ( "%s" , pNode -> m_cName ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;
	
	pNode -> m_cName = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cTemp ) + 1 ) ) ;
	strncpy ( pNode -> m_cName , cTemp , strlen ( cTemp ) ) ;
	pNode -> m_cName [ strlen ( cTemp ) ] = '\0' ;

	printf ( "주소 : " ) ;
//	scanf ( "%s" , pNode -> m_cAddress ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;
	
	pNode -> m_cAddress = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cTemp ) + 1 ) ) ;
	strncpy ( pNode -> m_cAddress , cTemp , strlen ( cTemp ) ) ;
	pNode -> m_cAddress [ strlen ( cTemp ) ] = '\0' ;

	printf ( "전화번호 : " ) ;
//	scanf ( "%s" , pNode -> m_cNumber ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;
	
	pNode -> m_cNumber = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cTemp ) + 1 ) ) ;
	strncpy ( pNode -> m_cNumber , cTemp , strlen ( cTemp ) ) ;
	pNode -> m_cNumber [ strlen ( cTemp ) ] = '\0' ;


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
		File_Save ( fClient , 1 ) ;
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
	char cTemp [ 50 ] ;

	printf ( "도서명, 출판사, 저자명, ISBN , 소장처 입력.\n" ) ;
	printf ( "도서명 : " ) ;
//	scanf ( "%s" , cTemp ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;
	
	pNode -> m_cName = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cTemp ) + 1 ) ) ;
	strncpy ( pNode -> m_cName , cTemp , strlen ( cTemp ) ) ;
	pNode -> m_cName [ strlen ( cTemp ) ] = '\0' ;

	printf ( "출판사 : " ) ;
//	scanf ( "%s" , cTemp ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;

	pNode -> m_cPublisher = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cTemp ) + 1 ) ) ;
	strncpy ( pNode -> m_cPublisher , cTemp , strlen ( cTemp ) ) ;
	pNode -> m_cPublisher [ strlen ( cTemp ) ] = '\0' ;

	printf ( "저자명 : " ) ;
//	scanf ( "%s" , cTemp ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;

	pNode -> m_cAuthor = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cTemp ) + 1 ) ) ;
	strncpy ( pNode -> m_cAuthor , cTemp , strlen ( cTemp ) ) ;
	pNode -> m_cAuthor [ strlen ( cTemp ) ] = '\0' ;

	printf ( "ISBN : " ) ;
//	scanf ( "%s" , cTemp ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;

	pNode -> m_cISBN = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cTemp ) + 1 ) ) ;
	strncpy ( pNode -> m_cISBN , cTemp , strlen ( cTemp ) ) ;
	pNode -> m_cISBN [ strlen ( cTemp ) ] = '\0' ;

	printf ( "소장처 : " ) ;
//	scanf ( "%s" , cTemp ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;

	pNode -> m_cHoldingInstitution = ( char * ) malloc ( sizeof ( char ) * ( strlen ( cTemp ) + 1 ) ) ;
	strncpy ( pNode -> m_cHoldingInstitution , cTemp , strlen ( cTemp ) ) ;
	pNode -> m_cHoldingInstitution [ strlen ( cTemp ) ] = '\0' ;


	pSort = Sort_ISBN_Find_Book ( pNode ) ;
	
	
	if ( NULL == pSort )
	{
		free ( pNode ) ;
		
		printf ( "Same Student Number. Register failed.\n" ) ;
	}
	if ( NULL != pSort )									// Why?
	{
//		Remove_Line_Escape_Sequence ( pNode ) ;

		pNode -> m_cBorrow = 'Y' ;
		pNode -> m_iBookNum = iBookNum + 1 ;
		++ iBookNum ;
		pSort -> m_pNext -> m_pPrev = pNode ;
		pNode -> m_pNext = pSort -> m_pNext ;
		pSort -> m_pNext = pNode ;
		pNode -> m_pPrev = pSort ;

		++ iBookCount ;


		fBook = fopen ( "Book.txt" , "a" ) ;
		File_Save ( fBook , 2 ) ;
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
	Book * pSort = pBookHead ;
	char cSortISBN [ 14 ] ;
	char cNodeISBN [ 14 ] ;
	char cTemp [ 8 ] ;
	int iSortISBN = 0 ;
	int iNodeISBN = 0 ;
//	long lSortISBN = 0 ;
//	long lNodeISBN = pNode -> m_lISBN ;

	strcpy ( cNodeISBN , pNode -> m_cISBN ) ;


	while ( pSort -> m_pNext != pBookTail )
	{
		pSort = pSort -> m_pNext ;
		strcpy ( cSortISBN , pSort -> m_cISBN ) ;

		strncpy ( cTemp , cSortISBN , 7 ) ;
		cTemp [ 7 ] = '\0' ;
		iSortISBN = atoi ( cTemp ) ;
		strncpy ( cTemp , cNodeISBN , 7 ) ;
		cTemp [ 7 ] = '\0' ;
		iNodeISBN = atoi ( cTemp ) ;
		//lSortISBN = pSort -> m_lISBN ;

		
/*		if ( lNodeISBN == lSortISBN )
		{
			pSort = NULL ;

			break ;
		} */
		if ( iSortISBN > iNodeISBN )			// SortISBN is 20160805111 , NodeNumber is 20160805112
		{
			pSort = pSort -> m_pPrev ;

			break ;
		}
		else if ( iSortISBN == iNodeISBN )
		{
			Copy_Nto0 ( cSortISBN , cTemp , 7 , 0 , 7 ) ;
			iSortISBN = atoi ( cTemp ) ;
			Copy_Nto0 ( cNodeISBN , cTemp , 7 , 0 , 7 ) ;
			iNodeISBN = atoi ( cTemp ) ;

			if ( iSortISBN > iNodeISBN )
			{
				pSort = pSort -> m_pPrev ;

				break ;
			}
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
	
	fflush ( stdin ) ;


	if ( 2 == iMenu )
		iMenu = 3 ;


	pNode = Search_Book ( iMenu , true ) ;
	
	
	if ( NULL != pNode )
	{
		Print_Book_Information ( pNode ) ;
		pNode = Search_Book ( 5 , true ) ;
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

	printf ( "Input Menu : " ) ;

	scanf ( "%d" , & iMenu ) ;

	if ( 2 == iMenu )
		iMenu = 3 ;
	
	fflush ( stdin ) ;


	pBookNode = Search_Book ( iMenu , true ) ;
	
	
	if ( NULL != pBookNode )
	{
		Print_Book_Information ( pBookNode ) ;

		pClientNode = pClientHead ;
		pBookNode = pBookHead ;

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
		while ( pBookNode -> m_pNext != pBookTail )
		{
			pBookNode = pBookNode -> m_pNext ;

	
			if ( pBookNode -> m_iBookNum == iTempBookNum )
				break ;
		}


		if ( pClientNode -> m_iStudentNum != iStudentNum )
		{
			printf ( "Client doesn't exist.\n" ) ;
		}
		else if ( pBookNode -> m_iBookNum != iTempBookNum )
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
			File_Save ( fBorrow , 0 ) ;
			fclose ( fBorrow ) ;


//			free ( pBorrowNode ) ;
		}
	}
}


/*
 * Set returning date.
 * If returning date is Sunday, set it Monday. + 1 day.
 */
time_t Set_Return_Date ( time_t tTime )
{
	char cTemp [ 40 ] ;


	tTime += TIME_T_SECOND_30DAY ;
	//strncpy ( cTemp , ctime ( tTime ) , 26 ) ;
	strcpy ( cTemp , ctime ( & tTime ) ) ;
	
	
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
	int ** irgBookNum = NULL ;
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


		while ( i != iStudentBorrow )
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
					pBookNode = pBookNode -> m_pNext ;


					if ( pBorrowNode -> m_iBookNum == pBookNode -> m_iBookNum )
						break ;
				}


				Print_Borrow_Information ( pBorrowNode , pBookNode ) ;
				irgBookNum [ i ] = pBorrowNode -> m_iBookNum ;
				++i ;
			}
		}


		printf ( "Input returning book number : " ) ;
		scanf ( "%d" , & iTemp ) ;
		fflush ( stdin ) ;

		i = 0 ;


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
	char cName [ 20 ] ;
	int iTempStudentNum ;
	Client * pNode = pClientHead ;


	while ( 4 != iMenu )
	{
		pNode = pClientHead ;


		printf ( "1. Name Search\t" ) ;
		printf ( "2. Student Number Search\n" ) ;
		printf ( "3. All Search\t" ) ;
		printf ( "4. Previous Menu\n\n" ) ;
		printf ( "Input Menu : " ) ;


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


			if ( pClientTail != pNode -> m_pNext )
				Print_User ( pNode ) ;
			else
				printf ( "There's no user name %s\n" , cName ) ;
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
		else if ( 4 != iMenu )
		{
			printf ( "Wrong menu. Try again.\n" ) ;
		}
	}
}


/*
 * Search Specific Book.
 * Name, ISBN, Publisher, Author, BookNumber
 */
Book * Search_Book ( int iMenu , bool bReturn )
{
	char cName [ 25 ] ;
	char cISBN [ 14 ] ;
	//long lISBN = 0 ;
	char cPublisher [ 25 ] ;
	char cAuthor [ 15 ] ;
	int iBookNum = 0 ;
	Book * pNode = pBookHead ;


	while ( 6 != iMenu )
	{
		pNode = pBookHead ;

		if ( ! bReturn )
		{
			printf ( "1. Name\t" ) ;
			printf ( "2. Publisher\n" ) ;
			printf ( "3. ISBN\t" ) ;
			printf ( "4. Author\n" ) ;
			printf ( "5. All Search\t" ) ;
			printf ( "6. Previous Menu\n\n" ) ;
			printf ( "Input Menu : " ) ;


			scanf ( "%d" , & iMenu ) ;
			fflush ( stdin ) ;
		}


		if ( 1 == iMenu )	// Name
		{
			printf ( "Input Book Name : " ) ;

			gets ( cName ) ;
			fflush ( stdin ) ;


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
		
		else if ( 2 == iMenu ) // Publisher
		{
			printf ( "Input Publisher : " ) ;

			gets ( cPublisher ) ;
			fflush ( stdin ) ;

			//scanf ( "%s" , cPublisher ) ;


			while ( pNode -> m_pNext != pBookTail )
			{
				pNode = pNode -> m_pNext ;


				if ( ! strcmp ( cPublisher , pNode -> m_cPublisher ) )
				{
					break ;

				}
			}
		}
		else if ( 3 == iMenu ) // ISBN
		{
			printf ( "Input ISBN : " ) ;
			//scanf ( "%ld" , & lISBN ) ;
			scanf ( "%s" , cISBN ) ;
			fflush ( stdin ) ;


			while ( pNode -> m_pNext != pBookTail )
			{
				pNode = pNode -> m_pNext ;


				if ( ! strcmp ( cISBN , pNode -> m_cISBN ) )
				{
					break ;
				}
			}
		}
		else if ( 4 == iMenu ) // Author
		{
			printf ( "Input Author : " ) ;

			gets ( cAuthor ) ;
			fflush ( stdin ) ;

			//scanf ( "%s" , cAuthor ) ;


			while ( pNode -> m_pNext != pBookTail )
			{
				pNode = pNode -> m_pNext ;


				if ( ! strcmp ( cAuthor , pNode -> m_cAuthor ) )
				{
					break ;
				}
			}
		}
		else if ( 5 == iMenu )	// BookNumber
		{
			printf ( "Input BookNumber : " ) ;

			scanf ( "%d" , & iBookNum ) ;
			fflush ( stdin ) ;

			//scanf ( "%s" , cAuthor ) ;


			while ( pNode -> m_pNext != pBookTail )
			{
				pNode = pNode -> m_pNext ;


				if ( iBookNum == pNode -> m_iBookNum )
				{
					break ;
				}
			}
		}
		/*else if ( 5 == iMenu )
		{
			while ( pBookTail != pNode -> m_pNext )
			{
				pNode = pNode -> m_pNext ;

				Print_Book_Information ( pNode ) ;
			}
		
			pNode = pBookHead ;
		}*/
		else if ( 6 == iMenu )
		{
			break ;
		}
		else
		{
			printf ( "Wrong menu. Try again.\n" ) ;
		}

		/*else
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
		}*/

		if ( pNode -> m_pNext == pBookTail )
			pNode = NULL ;
		else if ( ! bReturn )
			Print_Book_Information ( pNode ) ;
		else
			return pNode ;
	}
	//if ( ! iMenu )
	//{
	//	printf ( "1. Name\t" ) ;
	//	printf ( "2. ISBN\n" ) ;
	//	printf ( "3. Publisher\t" ) ;
	//	printf ( "4. Author\n" ) ;

	//	scanf ( "%d" , & iMenu ) ;

	//	//도서명 ISBN 출판사 저자명 도서번호
	//}
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
	char cTemp [ 50 ] ;
	FILE * fClient = NULL ;


	printf ( "Modify information except student number, and name.\n" ) ;
	printf ( "Password : " ) ;
//	scanf ( "%s" , pUser -> m_cPassword ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;
	
	strncpy ( pUser -> m_cPassword , cTemp , strlen ( cTemp ) ) ;
	pUser -> m_cPassword [ strlen ( cTemp ) ] = '\0' ;

	printf ( "Address : " ) ;
//	scanf ( "%s" , pUser -> m_cAddress ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;
	
	strncpy ( pUser -> m_cAddress , cTemp , strlen ( cTemp ) ) ;
	pUser -> m_cAddress [ strlen ( cTemp ) ] = '\0' ;

	printf ( "Phone Number : " ) ;
//	scanf ( "%s" , pUser -> m_cNumber ) ;
	gets ( cTemp ) ;
	fflush ( stdin ) ;
	
	strncpy ( pUser -> m_cNumber , cTemp , strlen ( cTemp ) ) ;
	pUser -> m_cNumber [ strlen ( cTemp ) ] = '\0' ;


	fClient = fopen ( "Client.txt" , "w+" ) ;
	File_Save ( fClient , 1 ) ;
	fclose ( fClient ) ;


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

		free ( pUser -> m_cAddress ) ;
		free ( pUser -> m_cName ) ;
		free ( pUser -> m_cNumber ) ;
		free ( pUser -> m_cPassword ) ;

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
		printf ( "\nStudent Number : %d\n" , pNode -> m_iStudentNum ) ;
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
		printf ( "ISBN : %s\n" , pNode -> m_cISBN ) ;
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


	while ( pClientTail != ( pClientNode -> m_pNext ) )
	//while ( pClientTail != pClientNode )
	{
		pClientNode = pClientNode -> m_pNext ;

		free ( pClientNode -> m_cAddress ) ;
		free ( pClientNode -> m_cName ) ;
		free ( pClientNode -> m_cNumber ) ;
		free ( pClientNode -> m_cPassword ) ;

		free ( pClientNode -> m_pPrev ) ;
	}
	while ( pBookTail != ( pBookNode -> m_pNext ) )
	//while ( pBookTail != pBookNode )
	{
		pBookNode = pBookNode -> m_pNext ;

		free ( pBookNode -> m_cAuthor ) ;
		free ( pBookNode -> m_cHoldingInstitution ) ;
		free ( pBookNode -> m_cName ) ;
		free ( pBookNode -> m_cPublisher ) ;

		free ( pBookNode -> m_pPrev ) ;
	}
	while ( pBorrowTail != ( pBorrowNode -> m_pNext ) )
	{
		pBorrowNode = pBorrowNode -> m_pNext ;

		free ( pBorrowNode -> m_pPrev ) ;
	}

	free ( pClientNode -> m_pNext ) ;
	free ( pClientNode ) ;
	free ( pBookNode -> m_pNext ) ;
	free ( pBookNode ) ;
	free ( pBorrowNode -> m_pNext ) ;
//	free ( pBorrowNode ) ;
}