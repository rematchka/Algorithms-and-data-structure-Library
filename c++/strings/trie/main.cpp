//
//  main.cpp
//  Trie_problems
//
//  Created by MacBook Pro on 6/17/19.
//  Copyright © 2019 MacBook Pro. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;






struct node
{
    
    node* child[26];
    int words;
    node()
    {
        words = 0;
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
    
};


class trie
{
    
    node* n;
    
public:
    
    trie()
    {
        n = new node();
        
        
        
    }
    
    trie(string& s)
    {
        n = new node();
        int pos=-1;
        
        pos = s.find('_');
        int i=0;
        string temp;
        while(pos!=string::npos)
        {
            temp = s.substr(i,pos-i);
            add_word(temp);
            i=pos+1;
            pos = s.find_first_of('_',i);
        }
        temp = s.substr(i);
        add_word(temp);
    }
    
//    void add_word(string& s,node** v =NULL,int i = 0)
//    {
//        if(v==NULL) v = &n;
//        int len = (int)s.length();
//        if(i==len)
//        {
//            (*v)->words++;
//        }
//        else
//        {
//            int k = s[i]-'a';
//            if(((*v)->child[k])==NULL)
//            {
//                (*v)->child[k] = new node();
//
//            }
//
//            add_word(s,&((*v)->child[k]),i+1);
//
//        }
//    }
    
    
    
    void add_word(string& s)
    {
        node* v = n;
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            int k=s[i]-'a';
            if(v->child[k]==NULL)
            {
                v->child[k]=new node();
               
            }
             v= v->child[k];
        }
        v->words=(v->words+1);
    }
//    int count_words(string & s,node**  v=NULL,int i=0)
//    {
//        if(v==NULL) v=&n;
//        int m = i;
//        int len = s.length();
//
//        if(i==len)
//        {
//
//            return (*v)->words;
//        }
//
//        int k=s[0]-'a';
//
//
//        if((*v)->child[k]==NULL)
//        {
//            return 0;
//        }
//        else
//        {
//            return count_words(s,&((*v)->child[k]),m+1);
//        }
//    }
   
    
    int count_words(string & s)
    {
        node* v = n;
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            int k=s[i]-'a';
            if(v->child[k]==NULL)
            {
                return 0;
              
            }
            else
            {
                
                v= v->child[k];
            }
        }
        return v->words;
    }
    void destroy(node* v)
    {
        for(int i=0;i<26;i++)
        {
            if(v->child[i]!=NULL)
            {
                destroy(v->child[i]);
            }
        }
        delete v;
    }
    
    ~trie()
    {
        destroy(n);
    }
    
    
};





vector<int> solve(string A, vector<string> &B) {
    
    
    int len = B.size();
    vector<int> sorted_reviews(len);
    vector<int> scores(len);
    
    vector<string> good_words;
    
    
    int pos=-1;

    pos = A.find('_');
    int i=0;
    while(pos!=string::npos)
    {
        good_words.push_back(A.substr(i,pos-i));
        i=pos+1;
        pos = A.find_first_of('_',i);
    }
    good_words.push_back(A.substr(i));
    
   
    
    for(int i=0;i<len;i++)
    {
        sorted_reviews[i]=i;
        
        trie t(B[i]);
        
        
        for(int j=0;j<good_words.size();j++)
        {
            scores[i]+=t.count_words(good_words[j]);
        }
        
        
        
    }
    
   
    
    sort(sorted_reviews.begin(),sorted_reviews.end(),[scores](int a,int b){return scores[a]>scores[b];});
    
    return sorted_reviews;
    
}






int main(int argc, const char * argv[]) {

    
    vector<string>v;
    string S = "cool_ice_wifi";
    

    
    
    v.push_back("water_is_cool");
    v.push_back("cold_ice_drink");
    v.push_back("cool_wifi_speed");
    
    vector<int> sol=solve(S, v);
    for(auto s:sol)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    
    
    
    
    return 0;
}
