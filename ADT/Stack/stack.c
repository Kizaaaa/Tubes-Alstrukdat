#include <stdio.h>
#include "stack.h"

Addresss newNode(Entry x, DATETIME d)
{
    Addresss p = (Addresss)malloc(sizeof(Nodes));
    TEXTS(INFOS(p)) = x;
    WAKTUS(INFOS(p)) = d;
    NEXTS(p) = NULL;
    return p;
}

boolean isEmptyS(Stack s)
{
    return ADDR_TOP(s) == NULL;
}

int lengthS(Stack s)
{
    int ans = 0;
    while (ADDR_TOP(s) != NULL)
    {
        ans++;
        ADDR_TOP(s) = NEXTS(ADDR_TOP(s));
    }
    return ans;
}

void CreateStack(Stack *s)
{
    ADDR_TOP(*s) = NULL;
}

void push(Stack *s, Entry x, DATETIME d)
{
    if (isEmptyS(*s))
    {
        Addresss p = newNode(x,d);
        ADDR_TOP(*s) = p;
    }
    else
    {
        Addresss p = newNode(x,d);
        NEXTS(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, Eltypes *x)
{
    *x = TOP(*s);
    if (NEXTS(ADDR_TOP(*s)) == NULL)
    {
        Addresss p = ADDR_TOP(*s);
        free(p);
        ADDR_TOP(*s) = NULL;
    }
    else
    {
        Addresss p = ADDR_TOP(*s);
        ADDR_TOP(*s) = NEXTS(ADDR_TOP(*s));
        free(p);
    }
}

// int main(){
//     Stack s;
//     CreateStack(&s);
//     push(&s,3);
//     push(&s,4);
//     DisplayStack(s); printf("\n");
//     int x;
//     pop(&s,&x);
//     DisplayStack(s); printf("%d\n",x);
//     pop(&s,&x);
//     DisplayStack(s); printf("%d\n",x);
//     return 0;
// }