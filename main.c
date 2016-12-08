#include "Library_Service.h"


int main ()
{
	int iInput = 0 ;
	int iNum = 0 ;
	int iMenu = 0 ;
	bool bKeep = true ;
	
	pClientHead = ( Client * ) malloc ( sizeof ( Client ) ) ;
	pClientTail = ( Client * ) malloc ( sizeof ( Client ) ) ;
	pBookHead = ( Book * ) malloc ( sizeof ( Book ) ) ;
	pBookTail = ( Book * ) malloc ( sizeof ( Book ) ) ;
	pBorrowHead = ( Borrow * ) malloc ( sizeof ( Borrow ) ) ;
	pBorrowTail = ( Borrow * ) malloc ( sizeof ( Borrow ) ) ;
//	pUser = NULL ;

	FILE * fClient = fopen ( "Client.txt" , "r+" ) ;
	FILE * fBook = fopen ( "Book.txt" , "r+" ) ;
	FILE * fBorrow = fopen ( "Borrow.txt" , "r+" ) ;
	
	
	if ( NULL == fClient )
	{
		fClient = fopen ( "Client.txt" , "w+" ) ;
	}
	if ( NULL == fBook )
	{
		fBook = fopen ( "Book.txt" , "w+" ) ;
	}
	if ( NULL == fBorrow )
	{
		fBorrow = fopen ( "Borrow.txt" , "w+" ) ;
	}


	pClientHead -> m_pPrev = NULL ;
	pClientHead -> m_pNext = pClientTail ;
	pClientTail -> m_pPrev = pClientHead ;
	pClientTail -> m_pNext = NULL ;

	pBookHead -> m_pPrev = NULL ;
	pBookHead -> m_pNext = pBookTail ;
	pBookTail -> m_pPrev = pBookHead ;
	pBookTail -> m_pNext = NULL ;

	pBorrowHead -> m_pPrev = NULL ;
	pBorrowHead -> m_pNext = pBorrowTail ;
	pBorrowTail -> m_pPrev = pBorrowHead ;
	pBorrowTail -> m_pNext = NULL ;


	File_Load ( fClient , 1  ) ;
	fclose ( fClient ) ;
	File_Load ( fBook , 2 ) ;
	fclose ( fBook ) ;
	File_Load ( fBorrow , 3 ) ;
	fclose ( fBorrow ) ;

	ServiceMenu_Print () ;


	while ( bKeep )
	{
		printf ( "������ ����� �Է��ϼ��� : " ) ;


		scanf ( "%d" , & iInput ) ;

		fflush ( stdin ) ;


		if ( 0 == iMenu )
		{
			switch ( iInput )
			{
				case 1 :
					Register_Member () ;
					ServiceMenu_Print () ;

					break ;


				case 2 :
					Login_Member () ;

					if ( NULL == pUser )
						ServiceMenu_Print () ;
					else if ( pClientHead == pUser )
					{
						ServiceAdmin_Print () ;
						iMenu = 1 ;
					}
					else
					{
						ServiceUser_Print () ;
						iMenu = 2 ;
					}

					break ;

					
				case 3 :
					bKeep = false ;

					break ;
			}
		}
		else if ( 1 == iMenu )
		{
			switch ( iInput )
			{
				
			}
		}
		else
		{

		}


//		switch ( iInput )
//		{
//			case 1 :
//				Register_Member () ;
//				ServiceMenu_Print () ;
//
//				break ;
//			case 2 :
//				Login_Member () ;
//
//
//				if ( NULL == pUser )
//					ServiceMenu_Print () ;
//				else if ( pClientHead == pUser )
//					ServiceAdmin_Print () ;
//				else
//					ServiceUser_Print () ;
//
//				break ;
//			case 3 :
////				Menu_Print () ;
//				printf ( "============================\n" ) ;
//				printf ( "������ ����� �Է��ϼ��� : %d\n" , iInput ) ;
//				printf ( "============================\n" ) ;
////				Search_Member () ;
//				break ;
//			case 4 :
////				Menu_Print () ;
//				printf ( "============================\n" ) ;
//				printf ( "������ ����� �Է��ϼ��� : %d\n" , iInput ) ;
//				printf ( "============================\n" ) ;
//				Modify_Member () ;
//				break ;
//			case 5 :
////				Menu_Print () ;
//				printf ( "============================\n" ) ;
//				printf ( "������ ����� �Է��ϼ��� : %d\n" , iInput ) ;
//				printf ( "============================\n" ) ;
////				Delete_Member () ;
//				break ;
//			case 6 :
//			default :
//				break ;
//		}
	}


	fClient = fopen ( "Client.txt" , "w+" ) ;
	fBook = fopen ( "Book.txt" , "w+" ) ;
	fBorrow = fopen ( "Borrow.txt" , "w+" ) ;


	File_Save ( fClient , 1 ) ;
	File_Save ( fBook , 2 ) ;
	File_Save ( fBorrow , 3 ) ;


	fclose ( fClient ) ;
	fclose ( fBook ) ;
	fclose ( fBorrow ) ;

	All_free ( pClientHead ) ;
	All_free ( pBookHead ) ;
	All_free ( pBorrowHead ) ;
}

