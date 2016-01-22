#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include "fatal.h"
void MPrintList( List L );
void Insert2( ElementType X, List L );
struct Node {
    ElementType Element;
    Position    Next;
};

main() {
    List L = malloc( sizeof( struct Node ));
    //MAppend( 2, header );
    //MAppend( 4, header );
    int i;
    for ( i = 0; i < 50; i += 2)
        Insert2(i, L);
    Insert( 2, L, L );
    Insert( 4, L, L );
    Insert2( 6, L );
    MPrintList( L );
    printf("is empty %d\n", IsEmpty(L));

    Position pre = FindPrevious( 6, L );
    printf("preNode value: %d\n", pre->Element);
    return 0;
}


List MakeEmpty( List L ) {
    if ( L != NULL )
        DeleteList( L );
    L = malloc( sizeof (struct Node ) );
    if ( L == NULL )
        FatalError( "Out of memory!!!" );
    L->Next = NULL;
    return L;
}

int IsEmpty( List L ) {
    return L->Next == NULL;
}

int IsLast( Position P, List L ) {
    return P->Next == NULL;
}

Position Find( ElementType X, List L ) {
    Position P;

    P = L->Next;
    while ( P != NULL && P->Element != X)
        P = P->Next;

    return P;
}

void Delete( ElementType X, List L ) {
   Position P, TempCell ;

   P = FindPrevious( X, L );

   if ( !IsLast( P, L ) ) {
        TempCell = P->Next;
        P->Next = TempCell->Next;
        free( TempCell );
   }
}

//查找指定值的前一个元素
Position FindPrevious( ElementType X, List L ) {
    Position P;

    P = L;
    while ( P != NULL && P->Next->Element != X )
        P = P->Next;

    return P;
}

isLast( Position P, List L ) {
    return P->Next == NULL;
}

void Insert( ElementType X, List L, Position P ) {
   // Position TempCell; 

   // TempCell = malloc( sizeof( struct Node ) );

   // if ( TempCell == NULL )
   //     FatalError( "Out of space!!!" );
   // else {

   // TempCell->Element = X;
   // TempCell->Next = P->Next;
   // P->Next = TempCell;
   // }
    Position P1, TempCell;

    P1 = L;
    TempCell = malloc( sizeof( struct Node ) );
    if ( TempCell == NULL )
        FatalError( "Out of space!!!" );
    else {
        while ( P1 != NULL && P1->Next != NULL )
            P1 = P1->Next;

        TempCell->Element = X;
        P1->Next = TempCell;
    }
}

void Insert2( ElementType X, List L ) {
    Position P, TempCell;

    P = L;
    TempCell = malloc( sizeof( struct Node ) );
    if ( TempCell == NULL )
        FatalError( "Out of space!!!" );
    else {
        while ( P != NULL && P->Next != NULL )
            P = P->Next;

        TempCell->Element = X;
        P->Next = TempCell;
    }
}

void MPrintList( List L ) {
    Position P;
    int pos = 1;

    P = L->Next;
    printf("lists: \n");
    while ( P != NULL ) {
        if ( pos % 9 == 0  )
            printf("\n");
        printf("%3d->%3d ", pos++, P->Element);
        P = P->Next;
    }
    printf("\n");

}

void DeleteList( List L ) {
    Position P, Tmp;

    P = L->Next;
    L->Next = NULL;
    while ( P != NULL ) {
        Tmp = P->Next;
        free( P );
        P = Tmp;
    }
}

Position Header( List L ) {
    return L;
}

Position First( List L ) {
    return L->Next;
}

Position Advance( Position P ) {
    return P->Next;
}

ElementType Retrieve( Position P ) {
    return P->Element;
}
