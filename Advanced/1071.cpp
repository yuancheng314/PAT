#include<iostream>
#include<map>
#include<cctype>
using namespace std;

int main()
{
    string text,word,res;
    map<string,int> count;
    getline(cin,text);
    int len=text.length();
    for(int i=0;i<len;i++)
    {   if(isalnum(text[i]))
        {   word+=tolower(text[i]);   
        }
        
        if( !isalnum(text[i]) || i==len-1 )
        {   if( word.length()!=0 )
                count[word]++;
            word="";    //单词中的内容清空
        }
    }

    int max=0;
    for(auto it=count.begin();it!=count.end();it++)
    {   if(it->second>max)
        {   max=it->second;
            res=it->first;
        }
    
    }
    cout<<res<<" "<<max;

    return 0;
}