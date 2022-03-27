#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int N, Q;
vector<unordered_set<int>> adj;
vector<int> ind;

void input() {
   adj.resize(N + 1);
   ind.resize(N + 1);
   for (int i = 0; i < N-1; i++) {
      int a, b;cin>>a>>b;
      adj[a].insert(b);
      adj[b].insert(a);
      ind[a]++; ind[b]++;
   }
}

void calculateCost() {
   queue<int> q;
   vector<int> in=ind;
   vector<int> visited(N+1);
   for (int i = 1; i <= N; i++) {
      if (in[i] == 1) q.push(i);
   }

   ll cost = 0;

   while (q.size()) {
      int node = q.front();
      q.pop();
      visited[node]=1;
      for (auto i : adj[node]) {
        if(visited[i]==0){
            cost += in[node] * 1ll * in[i];
            //cout<<node<<" "<<i<<endl;
            in[node]--;in[i]--;
            if(in[i]==1) q.push(i);
        }
      }
   }
   cout << cost << endl;
}
int main()
{
   SPEED;
   int T; cin >> T;
   while (T--) {
      adj.clear(); ind.clear();
      cin >> N >> Q;
      input();
      calculateCost();

      //answering query
      vector<unordered_set<int>> adjcpy=adj;
      vector<int> indcpy=ind;
      while(Q--){
        int a,b,c,d;cin>>a>>b>>c>>d;
       // cout<<a<<" "<<b<<" "<<c<<" "<<d<< endl;
        adj[a].erase(b);
        adj[b].erase(a);
        ind[a]--;ind[b]--;

        adj[c].insert(d);
        adj[d].insert(c);
        ind[c]++;ind[d]++;

        // for(int i=1;i<=N;i++){
        //   cout<<i<<" ->";
        //   for(auto child:adj[i])
        //     cout<<child<<" ";
        //     cout<<endl;
        // }
        calculateCost();
        adj=adjcpy;
        ind=indcpy;
      }
   }
   return 0;
}