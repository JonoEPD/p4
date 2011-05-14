#ifndef _VECTOR_CPP_
#define _VECTOR_CPP_

#include "vector.h"

/* Weiss quicksort (pg 286) */
template <typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right )
{
  if(left + 10 <= right )
    {
      Comparable pivot = median3(a, left, right );

      int i = left, j = right - 1;
      for( ;; )
	{
	  while(a[++i] < pivot ) { }
	  while(pivot < a[--j] ) { }
	  if(i < j)
	    swap( a[i], a[j] );
	  else
	    break;
	}
      
      swap( a[i], a[ right - 1] ); //Restore pivot
      
      quicksort( a, left, i - 1 ); //Sort small elements
      quicksort( a, i + 1, right ); //Sort large elements
    }
  else
    insertionSort( a, left, right );
}

/* Weiss insertionSort * (pg 282) */
template <typename Comparable>
void insertionSort(vector<Comparable> a, int left, int right)
{
  int j;

  for(int p = left; p <= right; p++)
    {
      Comparable tmp = a[p];
      for( j = p; j > 0 && tmp < a[ j - 1]; j--)
	a[ j ] = a[ j-1 ];
      a[ j ] = tmp;
    }
}

template <class Object>
const vector<Object> & vector<Object>::operator=( const vector<Object> & rhs )
{
    if( this != &rhs )
    {
        delete [ ] objects;
        currentSize = rhs.size( );
        objects = new Object[ currentSize ];
        for( int k = 0; k < currentSize; k++ )
            objects[ k ] = rhs.objects[ k ];
    }
    return *this;
}

template <class Object>
void vector<Object>::resize( int newSize )
{
    Object *oldArray = objects;
    int numToCopy = newSize < currentSize ? newSize : currentSize;

    objects = new Object[ newSize ];
    currentSize = newSize;

    for( int k = 0; k < numToCopy; k++ )
        objects[ k ] = oldArray[ k ];

    delete [ ] oldArray;
}

#endif
