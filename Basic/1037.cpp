#include<iostream>
#include<cstring>
using namespace std;

int main()
{   int Pg,Ps,Pk,Ag,As,Ak,P,A;
    scanf("%d.%d.%d %d.%d.%d",&Pg,&Ps,&Pk,&Ag,&As,&Ak);
    P=(Pg*17+Ps)*29+Pk;
    A=(Ag*17+As)*29+Ak;
    if(P>A)
    {   cout<<"-"<<(P-A)/29/17<<"."<<(P-A)/29%17<<"."<<(P-A)%29;    }
    else cout<<(A-P)/29/17<<"."<<(A-P)/29%17<<"."<<(A-P)%29;

    return 0;
}
