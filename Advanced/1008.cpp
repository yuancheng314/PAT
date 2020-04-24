#include<iostream>
using namespace std;
const int stop=5,up=6,down=4;
int main()
{   int N,sum=0,from=0,to;
    cin>>N;
    sum+=N*stop;
    for(int i=0;i<N;i++)
    {   scanf("%d",&to);
        sum+= to-from>0 ? (to-from)*up : (to-from)*down*-1;
        from=to;
    }
    cout<<sum;
    return 0;
}
