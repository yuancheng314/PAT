#include<iostream>
#include<cstring>
using namespace std;

struct Bignum{  int d[1020],len=0; };
Bignum change(char* s){
    Bignum res;
    res.len=strlen(s);
    for(int i=0;i<res.len;i++){
        res.d[i]=s[res.len-1-i]-'0'; //逆着赋值
    }
    return res;
}
void printBignum(Bignum a){
    for(int i=a.len-1;i>=0;i--)
        printf("%d",a.d[i]);
}

bool isPalin(Bignum a){
    int j=a.len-1;
    for(int i=0;i<a.len/2;i++)
        if(a.d[i]!=a.d[j--])
            return false;
    return true;
}

Bignum add(Bignum a,Bignum b){
    Bignum c;
    int carry=0;
    for(int i=0;i<a.len || i<b.len ;i++){
        int temp=a.d[i]+b.d[i]+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0)    c.d[c.len++]=carry;
    return c;
}
Bignum reverse(Bignum a){
    Bignum b;
    for(int i=a.len-1;i>=0;i--){
        b.d[b.len++]=a.d[i];
    }
    return b;
}
int main(){

    char s[1005];
    scanf("%s",s);
    Bignum a=change(s),b;
    for(int i=1;i<=10;i++){
         if(isPalin(a)){
            printBignum(a);
            printf(" is a palindromic number.");
            return 0;
        }
        b=reverse(a);
        printBignum(a);
        printf(" + ");
        printBignum(b);
        printf(" = ");
        a=add(a,b);
        printBignum(a);
        printf("\n");
       
    }
    printf("Not found in 10 iterations.");
    return 0;
}