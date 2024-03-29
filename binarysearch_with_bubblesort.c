#include<stdio.h>
#include<stdlib.h>
void bubblesort ( int *arr , int count ) ;
int binarysearch ( int *arr , int min , int max , int target ) ;
int main () {
	int count = 0 ;
	int target ;
	int i ;
	int num ;
	int *arr = ( int* ) malloc ( sizeof ( int ) ) ;
	while ( scanf ( "%d" , &num ) != EOF ) {
		arr[count++] = num ;
		arr = realloc ( arr , count*sizeof ( int ) ) ;
	}
	target = arr[count-1] ;
	count-- ;
	bubblesort ( arr , count ) ;
	printf ( "After BubbleSort: ") ;
	for ( i = 0 ; i < count ; i++ ) {
		printf ( "%d " , arr[i] ) ;
	}
	binarysearch ( arr , 0 , count , target ) ;
}

void bubblesort ( int *arr , int count ) {
	int i , j ;
	int tmp ;
	for ( i = 0 ; i < count - 1 ; i++ ) {
		for ( j = 0 ; j < count - 1 ; j++ ) {
			if ( arr[j] > arr[j+1] ) {
				tmp = arr[j] ;
				arr[j] = arr[j+1] ;
				arr[j+1] = tmp ;	
			}
		}
	}
}

int binarysearch ( int *arr , int min , int max , int target ) {
	int mid = ( min + max ) / 2 ;
	if ( max >= min ) {
		if ( target == arr[mid] ) {
			printf ( "\ntarget at: %d\n" , mid + 1 ) ;
			return 0 ;
		}
		else if ( target > arr[mid] ) {
			return binarysearch ( arr , mid + 1 , max , target ) ;
		}
		else {
			return binarysearch ( arr , min , mid - 1 , target ) ;
		}
	}
	
}
