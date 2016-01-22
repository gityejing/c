    typedef int ElementType;

    #ifndef _List_H
    #define _List_H

    struct Node;
    typedef struct Node *PtrToNode;
    typedef PtrToNode List;
    typedef PtrToNode Position;

    List MakeEmpty( List L );
    int isEmpty( List L );
    int isLast( Position P, List L );
    Position Find( ElementType X, List L );
    void Delete( ElementType X, List L );
    Position findPrevious( ElementType X, List L );
    void Insert( ElementType X, List L, Position P );
//    void Insert2( ElementType X, List L );
    void DeleteList( List L );
    Position Header( List L );
    Position First( List L );
    Position Advance( Position P );
    ElementType Retrieve( Position P );
//    void MPrintList( List L );

    #endif
