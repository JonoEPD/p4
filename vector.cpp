#ifndef _VECTOR_CPP_
#define _VECTOR_CPP_

#include "vector.h"

/* Weiss quicksort (pg 286) */
template <typename Object>
void vector<Object>::quicksort(vector<Object> & a, int left, int right )
{
  if(left + 10 <= right )
    {
      int center = (left + right) / 2;
      if(a[center] < a[left])
	swap(a[left],a[center]);
      if(a[right] < a[left])
	swap(a[left],a[right]);
      if(a[right] < a[center])
	swap(a[center],a[right]);
      
      swap(a[center],a[right-1]);
      Object pivot = a[right-1];

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
template <typename Object>
void vector<Object>::insertionSort(vector<Object> &a, int left, int right)
{
  int j;

  for(int p = left; p <= right; p++)
    {
      Object tmp = a[p];
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
