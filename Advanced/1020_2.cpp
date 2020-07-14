#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> post,in;
map<int, int> level;
void pre(int root,int start,int end,int index){
    if(start>end)
        return;
    int i = start;
    while(i<end && in[i]!=post[root])
        ++i;
    level[index] = post[root];
    pre(root-1-end+i, start,i-1 ,2*index+1);
    //左子树在后序中的根结点为root – (end – i + 1)，即为当前根结点-(右子树的个数+1)
    pre(root-1, i+1, end,2*index+2);
}

int main(){
    int N;
    cin >> N;
    post.resize(N), in.resize(N);
    for (int i = 0; i < N;++i)
        scanf("%d", &post[i]);
    for (int i = 0; i < N;++i)
        scanf("%d", &in[i]);

    pre(N - 1, 0, N - 1, 0);

    auto it = level.begin();
    printf("%d", it->second);
    for (it++; it != level.end();++it)
        printf(" %d", it->second);
    return 0;
}
