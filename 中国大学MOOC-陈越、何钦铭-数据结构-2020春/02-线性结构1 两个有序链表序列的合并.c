List Merge( List L1, List L2 )
{   
    List L;
    PtrToNode p, p1=L1->Next,p2=L2->Next;
    L=(List)malloc(sizeof(List));
    p=L;

    while(p1 && p2)
    {   if(p1->Data > p2->Data)
        {   p->Next=p2;
            p=p->Next;
            p2=p2->Next;      
        }
        else
        {   p->Next=p1;
            p=p->Next;
            p1=p1->Next;
        }
    }

    p->Next = p1 ? p1 : p2;
    L1->Next=NULL;
    L2->Next=NULL;
    return L;

}