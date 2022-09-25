#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

sktruct Node {
	int data;
	Node *next;
};
// struct Node* reverse(struct Node *head, int k) {
	
// }
// struct Node*  ReverseKNodes(struct Node *head, int k) {
// 	return reverse(head, k);
// }
struct Node*  ReverseKNodes(struct Node *head, int k) {
	if (head == NULL) return NULL;

	Node *cur = head, *prev = NULL, *next = head;
	int i = 0;
	while (cur && i < k) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		i++;
	}

	if (next != NULL) {
		head->next = ReverseKNodes(next, k);
	}
	return prev;
}

void printLink(Node *head) {
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
int main()
{
	SPEED;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
   
	//create linklist
	Node *head = new Node();
	Node *cur = new Node();
	cur->data = v[0];
	head->next = cur;
	Node *prev = cur;
	for (int i = 1; i < n; i++) {
		cur = new Node();
		cur->data = v[i];
		prev->next = cur;
		prev = cur;
	}
	printLink(head->next);
    cur=ReverseKNodes(head->next,3);
    printLink(cur);
	return 0;
}