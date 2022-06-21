#include <bits/stdc++.h>
using namespace std;

//trie for string a to z
struct Node{
  Node *link[27];
  bool isTerminal=false;

  bool containsKey(char ch){
    return link[ch-'a']!=NULL;
  }
  void putKey(char ch,Node *node){
    link[ch-'a'] =node;
  }
};

class Trie{
  public:
  Node *root;
  Trie(){
    root=new Node();
  }

  void insert(string s){
    Node *node=root;
    for(char ch:s){
      if(!node->containsKey(ch)){
        node->putKey(ch,new Node());
      }
      node=node->link[ch-'a'];
    }
    node->isTerminal=true;
  }

  bool search(string s){
    Node *node=root;
    for(char ch:s){
      if(node->containsKey(ch)){
        node=node->link[ch-'a'];
      }
      else return false;
    }
    return node->isTerminal;
  }

};

int main(){
  Trie f;
  cout<<"Enter";
}