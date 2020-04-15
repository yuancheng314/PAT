#include<iostream>
#include<stack>
#include<cstring>
#include<vector>

using namespace std;

int maxn=35,N;
vector<int> pre,in,post;

void getpostorder(int root , int inbegin, int inend)
{
    if(inbegin>inend)   return;
    int cur=inbegin;
    while(cur<=inend && in[cur]!=pre[root])     cur++;
    getpostorder(root+1,inbegin,cur-1); //左递归
    getpostorder(root+(cur-inbegin)+1,cur+1,inend);  //右递归
    post.push_back(pre[root]);
}

int main()
{   cin>>N;
    char s[5];
    stack<int> st;
    int elem,key=0;

    //入栈结果为前序，，出栈结果为中序
    for(int i=0;i<2*N;i++)
    {   scanf("%s",s);
        if(strcmp(s,"Push")==0) //操作为入栈
        {
            scanf("%d",&elem);
            pre.push_back(elem);
            st.push(elem);
        }
        else //操作为出栈
        {
            in.push_back(st.top());
            st.pop();
           
        }
    }

    getpostorder(0,0,N-1);

    cout<<post[0];
    for(int i=1;i<N;i++)
        cout<<" "<<post[i];
    return 0;
}