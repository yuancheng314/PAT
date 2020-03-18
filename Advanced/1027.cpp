#include<iostream>
using namespace std;

int main()
{   int R,G,B;
    char change[14]={"0123456789ABC"};
    cin>>R>>G>>B;
    cout<<"#"<<change[R/13]<<change[R%13]<<change[G/13]<<change[G%13]<<change[B/13]<<change[B%13];
    
    return 0;
} 