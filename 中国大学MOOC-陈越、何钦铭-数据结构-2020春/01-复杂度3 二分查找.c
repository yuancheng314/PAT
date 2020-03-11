Position BinarySearch( List L, ElementType X )
{   int low=1,high=L->Last;
    int mid = (high+low)/2;
    while(low<=high)
    {   if(L->Data[mid]==X)
        {  return mid; }
        else if(L->Data[mid]>X)
        {   high=mid-1;
            mid=(high+low)/2;
        }
        else if(L->Data[mid]<X)
        {   low=mid+1;
            mid=(high+low)/2;
        }
    }

    return NotFound;


}
