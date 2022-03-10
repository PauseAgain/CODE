#include<stdio.h>
int Median3( int A[ ], int left, int right );
void QSort( int A[ ], int left, int right );
void Quicksort( int A[ ], int N );
void InsertionSort (int *A, int N);
void Swap( int *p,int *q);
int p;
int cho=0; 
int main()
{
	int A[10]={49,38,65,97,76,13,27,50,2,8};
	int N=10;
	scanf("%d",&p);
	Quicksort(A,N);	
	return 0;
}

void Swap( int *p,int *q)
{
	int tmp;
	tmp=*p;
	*p=*q;
	*q=tmp;
}
int Median3( int A[ ], int left, int right ) 
{ 
    int  Center = ( left + right ) / 2; 
    if ( A[left] > A[Center] ) 
        Swap( &A[left], &A[Center] ); 
    if ( A[left] > A[right] ) 
        Swap( &A[left], &A[right] ); 
    if ( A[Center] > A[right] ) 
        Swap( &A[Center], &A[right] ); 
    /* Invariant: A[ left ] <= A[ Center ] <= A[ right ] */ 
    Swap( &A[Center], &A[right-1] ); /* Hide pivot */ 
    /* only need to sort A[ left + 1 ] �� A[ right �C 2 ] */
    return  A[right-1];  /* Return pivot */ 
}
void  QSort( int A[ ], int left, int right ) 
{   int  i,j; 
    int  Pivot; 
    if ( left+3<= right ) 
	{  /* if the sequence is not too short */
        if(cho==0)
        {
        	Pivot=A[p];	cho=1;
        	Swap(&A[p],&A[right]);
        	i=left-1;     j=right;  /* why not set left+1 and right-2? */
        	for(;;) 
			{ 
	 			while(A[++i]<Pivot){}  /* scan from left ����һ�����ڵ���pivot��*/
	 			while(A[--j]>Pivot){}  /* scan from right ����һ��С�ڵ���pivot��*/
	 			if (i<j) 
	    			Swap(&A[i],&A[j]);  /* adjust partition */
	 			else     break;  /* partition done */
        	} 
        	Swap( &A[i], &A[right] ); /* restore pivot */ 
        	printf("QSort(%d,%d):",left,right);
	    	for(j=0;j<10;j++)
				printf("%d,",A[j]);
			printf("\n");
        	QSort( A, left, i-1 );      /* recursively sort left part */
        	QSort( A, i+1, right );     /* recursively sort right part */
		}
		else
		{
			Pivot = Median3( A, left, right );  /* select pivot */ 
        	i=left;     j=right-1;  /* why not set left+1 and right-2? */
        	for(;;) 
			{ 
	 			while(A[++i]<Pivot){}  /* scan from left ����һ�����ڵ���pivot��*/
	 			while(A[--j]>Pivot){}  /* scan from right ����һ��С�ڵ���pivot��*/
	 			if (i<j) 
	    			Swap(&A[i],&A[j]);  /* adjust partition */
	 			else     break;  /* partition done */
        	} 
        	Swap( &A[i], &A[right-1] ); /* restore pivot */ 
        	printf("QSort(%d,%d):",left,right);
	    	for(j=0;j<10;j++)
				printf("%d,",A[j]);
			printf("\n");
        	QSort( A, left, i-1 );      /* recursively sort left part */
        	QSort( A, i+1, right );     /* recursively sort right part */
		}   
    }  /* end if - the sequence is long */
    else /* do an insertion sort on the short subarray */ 
    {
		InsertionSort(A+left,right-left+1);
		printf("insert(%d,%d):",left,right-left+1);
	  	for(j=0;j<10;j++)
			printf("%d,",A[j]);
	  	printf("\n");	
	}
}
void InsertionSort (int *A, int N) 
{ 
      int  j, P; 
      int  Tmp; 
      for ( P = 1; P < N; P++ ) 
	  { 
		Tmp = A[ P ]; 
		for ( j = P; j > 0 && A[j-1] > Tmp; j-- ) 
	    A[j] = A[j-1]; 
		A[j] = Tmp;
      }    
}
void  Quicksort( int A[ ], int N ) 
{ 
	QSort( A, 0, N-1 ); 
	/* A: 	the array 	*/
	/* 0: 	left index 	*/
	/* N �C 1: right index	*/
}

