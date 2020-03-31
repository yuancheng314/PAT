#include<iostream>
#include<stack>
using namespace std;
int a[1010];

int main()
{   int M,N,K;
    cin>>M>>N>>K;
    stack<int> s;
 
    for(int i=0;i<K;i++)
    {   while(!s.empty())   {   s.pop();    }
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);
        int current=1; //current 指向出栈序列中的待出栈元素
        for(int i=1;i<=N;i++)
        {   s.push(i);
            if(s.size()>M)  {  break; }
            while(!s.empty()&&s.top()==a[current]) 
            //栈非空且栈顶元素与出栈序列当前位置的元素相同
            {   s.pop();
                current++;
            }
        }
        if(s.empty()) //最终结果为栈空
            cout<<"YES\n";
        else    cout<<"NO\n";
    }

    return 0;
}