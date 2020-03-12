bool Insert( List L, ElementType X )
{   if (L->Last==MAXSIZE-1) /*满了*/
    {   return false;   } 
    
    for(int i=0;i<=L->Last;i++)
    {   if(X==L->Data[i])   /*找到了*/
        {   return false;   }

        if(X>L->Data[i])    /*这个位置的数已经比X大了*/
        {   for(int j=L->Last;j>=i;j--)/*移位*/
            {   L->Data[j+1]=L->Data[j];    }   
            L->Data[i]=X;/*插入X*/
            L->Last++;
            return true;
        }
    }
    
    L->Data[++L->Last]=X; /*X比L中的元素都小，插在最后*/
    return true;


}