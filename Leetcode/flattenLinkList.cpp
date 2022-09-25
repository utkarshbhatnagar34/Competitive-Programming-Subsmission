#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};


/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   Node *fake = new Node(-1);
   priority_queue<pair<int,Node*>,vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;
   
   Node *cur = root;
   while(cur != NULL){
       pq.push({cur->data,cur});
       cur = cur->next;
   }
  
   cur = fake;
   Node *p1 = NULL, *bottom = NULL;
   
   while(pq.size()) {
       p1 = pq.top().second; pq.pop();
       
       cur->next= p1;
       
       p1 = p1->bottom;
       if(p1) pq.push({p1->data, p1});
       
       cur = cur->next;
       cur->next = NULL;
       cur->bottom = NULL;
   }
   
   while(fake != NULL) {
       cout<< fake->data <<endl;
       fake = fake->next;
   }
   return fake->next;
}

int main() {
  Node *head = new Node(-1);
  Node *cur = head;

  for(int i=1; i <= 5; i++) {
    cur->next = new Node(i);
    cur = cur->next;
  }
  cur = head;
  while(cur != NULL) {
    for(int i=1;i<=3;i++){
      cur->bottom = new 
    }
    cur = cur->next;
  }
  
   
}