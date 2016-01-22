#include "mstack.h"
#include <stdlib.h>
#include <stdio.h>
#include "fatal.h"

struct Node {
    ElementType Element;
    PtrToNode Next;
};

main() {
    Stack S;

    S = CreateStack();
    printf("push stack 13\n");
    Push(13, S);
    printf("push stack 25\n");
    Push(25, S);
    printf("%d\n", Top(S));
    Pop(S);
    printf("%d\n", Top(S));
    Pop(S);
    printf("is empty %d\n", IsEmpty(S));
    return 0;
}

int IsEmpty( Stack S ) {
    return S->Next == NULL;   
}

Stack CreateStack( void ) {
    Stack S;

    S = malloc( sizeof( struct Node ) );
    if ( S == NULL )
        FatalError(" Out of space!!!");
    S->Next == NULL;
    MakeEmpty( S );
    return S;
}

void MakeEmpty( Stack S ) {
    if ( S == NULL )
        Error(" Must use CreateStack first!");
    else {
        while ( !IsEmpty( S ) )
            Pop( S );
    }
}

ElementType Top( Stack S ) {
    if ( !IsEmpty( S ) )
        return S->Next->Element;
    Error( "Empty Stack ");
    return 0;
}

void Pop( Stack S ) {
    PtrToNode FirstCell;

    if ( IsEmpty( S ) )
        Error("Empty Stack");
    else {
        //先把栈顶元素保存起来
        FirstCell = S->Next;
        //栈的头指针指向第二个元素
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

void Push( ElementType X, Stack S ) {
   PtrToNode TempCell; 

    TempCell = malloc( sizeof( struct Node ) );
    if ( TempCell == NULL )
        FatalError("Out of space!!!");
    else {
        TempCell->Element = X;
        TempCell->Next = S->Next;
        S->Next = TempCell;
    }
}
