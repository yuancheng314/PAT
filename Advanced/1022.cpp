#include<iostream>
#include<map>
#include<set>
using namespace std;
/*在使用getline()时，要注意是否会接收到预期之外的字符*/
map< string ,set<int> > Title,Author,Key_word,Publisher,Published_year;

void query(map<string ,set<int> > &type,string word)
{   if(type.find(word)!=type.end()) //找到了
    {   for(auto it=type[word].begin();it!=type[word].end();it++)
        {   printf("%07d\n",*it); }
    }
    else cout<<"Not Found"<<endl;

}

int main()
{   int N,M,id;
    string title,author,key_word,publisher,published_year;
    scanf("%d",&N);
    for(int i=0;i<N;i++) /*读入书本信息*/
    {   scanf("%d\n",&id);
        getline(cin,title);
        Title[title].insert(id);
        getline(cin,author);
        Author[author].insert(id);
        char c;
        while(cin>>key_word)
        {   Key_word[key_word].insert(id);
            if((c=getchar())=='\n')
                break;
        }
        getline(cin,publisher);
        Publisher[publisher].insert(id);
        getline(cin,published_year);
        Published_year[published_year].insert(id);
    }
        
    scanf("%d",&M);
    string word;
    int cate;
    while(M--) /*查询书本信息*/
    {   scanf("%d: ",&cate); //这里必须有空格，或者下一行用getchar吸收空格     
        getline(cin,word);
        cout<< cate<<": "<<word<<endl;
        switch(cate)
        { case 1: { query(Title,word); break;}
          case 2: { query(Author,word); break;}
          case 3: { query(Key_word,word); break;}
          case 4: { query(Publisher,word); break;}
          case 5: { query(Published_year,word); break;}
        }
    }

    return 0;
}