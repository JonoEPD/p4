        #ifndef _QUADRATIC_PROBING_H_
        #define _QUADRATIC_PROBING_H_

        #include "vector.h"

        // QuadraticProbing Hash table class
        //
        // CONSTRUCTION: an initialization for ITEM_NOT_FOUND
        //               and an approximate initial size or default of 101
        //
        // ******************PUBLIC OPERATIONS*********************
        // void insert( x )       --> Insert x
        // void remove( x )       --> Remove x
        // Hashable find( x )     --> Return item that matches x
        // void makeEmpty( )      --> Remove all items
        // int hash( String str, int tableSize )
        //                        --> Static method to hash strings

        template <class HashedObj>
        class QuadraticHashTable
        {
          public:
            explicit QuadraticHashTable( int size = 101 );
            QuadraticHashTable( const QuadraticHashTable & rhs )
              : array( rhs.array),
                currentSize( rhs.currentSize ) { }

            const HashedObj & find( const HashedObj & x ) const;

            void makeEmpty( );
            void insert( const HashedObj & x );

            const QuadraticHashTable & operator=( const QuadraticHashTable & rhs );

            enum EntryType { ACTIVE, EMPTY, DELETED };
          
            struct HashEntry
            {
                HashedObj element;
                EntryType info;

	      HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )                  : element( e ), info( i ) { }
            };

            vector<HashEntry> array;
            int currentSize;
            bool isPrime( int n ) const;
            int nextPrime( int n ) const;
            int findPos( const char *, int birthYear ) const;
	    int findObject( const char *, int birthYear ) const;
            int hash( const char *, int birthYear, int tableSize ) const;
            void rehash( );
        };

        #include "QuadraticProbing.cpp"
        #endif
