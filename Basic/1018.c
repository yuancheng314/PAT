#include<stdio.h>

char maxpro(int byC,int byJ,int byB)
{   if(byB>=byC && byB>=byJ) { return 'B';}   
    if(byC>=byJ && byC>=byB) { return 'C';}
    return 'J';
    
    

}
int main()
{
    int N,BbyC=0,BbyJ=0,BbyB=0,draw=0;
    int AbyC=0,AbyJ=0,AbyB=0,Awin=0,Bwin=0;
    char player1,player2;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {   scanf(" %c %c",&player1,&player2);
        if(player1=='C')
        {   if(player2=='C') {  draw++; }
            else if(player2=='J') { AbyC++;  }
            else if(player2=='B') { BbyB++;  }
        }
        else if(player1=='J')
        {   if(player2=='C') {  BbyC++; }
            if(player2=='J') {  draw++; }
            if(player2=='B') {  AbyJ++;}
        }
        else if(player1=='B')
        {   if(player2=='C') {  AbyB++; }
            if(player2=='J') {  BbyJ++; }
            if(player2=='B') {  draw++; }
        }
    }
    Awin=AbyC+AbyJ+AbyB;
    Bwin=BbyC+BbyJ+BbyB;
    printf("%d %d %d\n",Awin,draw,Bwin);
    printf("%d %d %d\n",Bwin,draw,Awin);
    printf("%c %c",maxpro(AbyC,AbyJ,AbyB),maxpro(BbyC,BbyJ,BbyB));
    return 0;
}