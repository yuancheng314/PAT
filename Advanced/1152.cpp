#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool isPrime(int x){
    if(x<=1)    return false;
    if(x==2)    return true;
    int ceil=sqrt(x);
    for(int i=2;i<=ceil;i++){
        if(x%i==0)
            return false;    
    }
    return true;
}
int chage(char* s,int from ,int K){
    int res=0;
    for(int i=0;i<K;i++)   res=10*res+s[from+i]-'0';
    return res;
}
int main(){
    int L,K,cur;
    char s[1005];
    scanf("%d %d",&L,&K);
    scanf("%s",s);
    for(int from=0;from<=L-K;from++){
        cur=chage(s,from,K);
        if(isPrime(cur)){
            printf("%0*d\n",K,cur);
          	// cout << setfill('0')<<setw(K)<<cur<<"\n";
            /*前导0的处理是这道题的一个坑点，
              std::setw ：需要填充多少个字符,默认填充的字符为' '空格
              std::setfill：设置std::setw将填充什么样的字符，如:std::setfill('*')
              std::setbase(n)：将输出数据转换为n进制
              std::setprecision()：控制输出流显示浮点数的数字个数，C++默认的流输出数值有效位是6。
            */
            return 0;
        }
    }
    printf("404");
    return 0;
}