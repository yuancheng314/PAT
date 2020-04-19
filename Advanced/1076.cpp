#include<iostream>
#include<queue>
#include<vector>
#include<cstring> //因为要使用memset函数
using namespace std;

struct Node {  int id,layer;  };

vector<Node> Adj[1010];
bool inq[1010]={false} ; //用于判断顶点是否已经被加入队列
/*PAT使用全局变量一般可以减少对于调用函数时应传入哪些参数的思考
然而这道题，如果inq使用了全局变量，一定记得在每次调用BFS前重新
填充inq,当然也可以将inq设置为BFS的域内函数从而不适用全局变量
*/
int N,L;

int BFS(Node node)
{   int numForward=0,cur_id;
    queue<Node> q;
    q.push(node);
    inq[node.id]=true;//标记node已入队

    Node cur_node,next_node;
    while(!q.empty())
    {   cur_node=q.front();//取出队首节点
        q.pop();    //队首节点出队
        cur_id=cur_node.id;
        for(int i=0;i<Adj[cur_id].size();i++)
        {   next_node=Adj[cur_id][i];
            next_node.layer=cur_node.layer+1; //next的层号等于当前节点层号加１
            if(inq[next_node.id]==false && next_node.layer<=L)
            {   //将nex_node入队
                q.push(next_node);
                inq[next_node.id]=true;
                numForward++;
            }
        }
    }
    return numForward;
}

int main()
{   int num_query,numFollow,follow_id;
    Node user;
    cin>>N>>L;

    for(int i=1;i<=N;i++)
    {   user.id=i;
        scanf("%d",&numFollow);
        for(int j=0;j<numFollow;j++)
        {
            scanf("%d",&follow_id);
            Adj[follow_id].push_back(user);
            /*注意不是Adj[user].push_back(Node(id,0))*/
        }
    }
    cin>>num_query;
    int id_query;
    for(int i=0;i<num_query;i++)
    {   memset(inq,false,sizeof(inq));
        scanf("%d",&id_query);
        Node query_node={id_query,0};
        printf("%d\n",BFS(query_node));
    }
    return 0;
}