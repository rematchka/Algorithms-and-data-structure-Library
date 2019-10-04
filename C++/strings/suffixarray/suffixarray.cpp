//
//  main.cpp
//  SuffixArray
//
//  Created by MacBook Pro on 6/14/19.
//  Copyright © 2019 MacBook Pro. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef vector<int> vi;

class SuffixArray{
    
    vi rank;
    vi nextrank;
    vi temp;
    vi arr;
    bool flag;
    int len;
    string s;
    
    bool cmp(int i , int j)
    {

        if (rank[i]==rank[j])
            return nextrank[i]<nextrank[j];
        else
            return rank[i]<rank[j];
        

    }
    
public:
    SuffixArray(string s)
    {
        this->s=s;
        
        len = (int)s.length();
        if(len!=0)
        {
        rank.resize(len);
        nextrank.resize(len);
        arr.resize(len);
        temp.resize(len);
        flag = true;
        int i=0;
        for(;i<len-1;i++)
        {
            rank[i]=s[i]-'a';
            nextrank[i]=s[i+1]-'a';
            arr[i]=i;
        }
        rank[i]=s[i]-'a';
        nextrank[i]=-1;
        arr[i]=i;
        construct();
        }
        
    }
    
    //Multiple algorithms exist
    //O(nlogn*logn)
    void construct()
    {
        int i=1;
   
        
        while((i<<1)<=len)
        {
            sort(arr.begin(),arr.end(),bind(&SuffixArray::cmp,this, std::placeholders::_1,std::placeholders::_2));
                recompute_rank(i);
                if(rank[arr[len-1]] == len-1)
                {
                
                    break;
                }
            
            i = i<<1;
            
        }
        
 
        
    }
    
    
    
   void recompute_rank(int j)
    {
        int k =(1<<j);

        for(int i=0;i<len;i++)
        {
            temp[i] = rank[i];
        }
        
        int i=1;
        rank[arr[0]]=0;
        while(i<len)
        {
        if(temp[arr[i]]==temp[arr[i-1]] && nextrank[arr[i]]==nextrank[arr[i-1]])
        {
            rank[arr[i]]=rank[arr[i-1]];
        }
        else{
            rank[arr[i]]=rank[arr[i-1]]+1;
        }
            i++;
        }
        i=0;
        while(i<len)
        {
            int c = arr[i]+k;
            if(c>=len)
            {
                nextrank[arr[i]] = -1;
            }
            else
            {
                nextrank[arr[i]] = rank[c];
            }
            i++;
        }
    }
    
    
    void print_suffixes()
    {
        for(int i=0;i<len;i++)
        {
            string s1 = s.substr(arr[i]);
            cout<<s1<<endl;
        }
    }
    
    
    
    
};






int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s="banana";
    string s_r=s;
    reverse(s_r.begin(), s_r.end());
    SuffixArray arr(s);
    
    
    SuffixArray arr2(s_r);
                     
    arr.print_suffixes();
    arr2.print_suffixes();
    return 0;
}
