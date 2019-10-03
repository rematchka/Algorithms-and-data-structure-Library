//
//  main.cpp
//  Tress
//
//  Created by MacBook Pro on 6/17/19.
//  Copyright © 2019 MacBook Pro. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//vector<int> inorderTraversal(TreeNode* A) {
//
//    vector<int> v;
//    if(A==NULL) return v;
//
//    TreeNode* node = A;
//
//    stack<TreeNode*> s;
//    s.push(node);
//
//    while(!(s.empty()))
//    {
//
//        node = s.top();
//        TreeNode* left = node->left;
//
//
//
//
//
//        if(left != NULL)
//        {
//            s.push(left);
//            node->left = NULL;
//        }
//        else
//        {
//
//            s.pop();
//            v.push_back(node->val);
//
//            if(node->right!=NULL)
//                s.push(node->right);
//        }
//
//    }
//
//    return v;
//}

vector<int> inorderTraversal(TreeNode* A) {
    
    vector<int> v;
    if(A==NULL) return v;
    
    TreeNode* node = A;
    
    stack<TreeNode*> s;
    s.push(node);
    
   while(!s.empty())
   {
       
       if(node == NULL)
       {
           if(!s.empty())
           {
               node = s.top();
               v.push_back(node->val);
               s.pop();
               node = node->right;
               
           }
       }
       else
       {
           s.push(node);
           node = node->left;
       }
   }

    
    return v;
}

//vector<int> postOrderTraversal(TreeNode* A)
//{
//    vector<int>v;
//
//    TreeNode* node = A;
//
//    stack<TreeNode*> s;
//
//    s.push(node);
//    while(!s.empty())
//    {
//        node = s.top();
//        if(!node->right && !node->left)
//        {
//            v.push_back(node->val);
//            s.pop();
//        }
//        else
//        {
//        if(node->right)
//        {
//            s.push(node->right);
//            node->right = NULL;
//        }
//        if(node->left)
//        {
//            s.push(node->left);
//            node->left = NULL;
//        }
//        }
//
//
//    }
//
//    return v;
//}



vector<int> postOrderTraversal(TreeNode* A)
{
    vector<int>v;
    
    TreeNode* node = A;
    
    stack<TreeNode*> s;
    
    s.push(node);
    while(!s.empty())
    {
        node = s.top();
        
        if(!node->left && !node->right)
        {
            v.push_back(node->val);
        }
        else if(!node->left){
            node = node->right;
            s.push(node);
        }
        else if(!node->right)
        {
            node = node->left;
            s.push(node);
        }
        else
        {
            
        }
            
    }
    
    return v;
}

int main(int argc, const char * argv[]) {
    
    TreeNode* f = new TreeNode(1);
    f->left = new TreeNode(2);
    f->right = new TreeNode(3);
    f->left->left = new TreeNode(4);
    f->left->right = new TreeNode(5);
    f->left->right->left = new TreeNode(7);
    f->right->right = new TreeNode(6);
    vector<int> v = postOrderTraversal(f);
    cout<<endl<<endl;
    
    for(int i =0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
        
        
    }
    cout<<endl;
}

