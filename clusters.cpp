/*
    Rui Santos: 2020225542 
    Tomás Dias: 2020215701
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> g; // adjacency list of the graph
vector<vector<int>> g1; // values that a bank owes to another
vector<int> ids, low; // ids and low values for each node
stack<int> st; // stack used in the algorithm
vector<bool> on_stack; // flag to check if a node is on the stack
vector<vector<int>> sccs; // strongly connected components

int id_counter = 0; // global counter for ids

bool debug = false;


vector<int> saldos;


void calculaSaldos(int s){
    saldos = vector<int>(s);
    for(int i = 0; i<s; i++){
        for(int j = 0; j<s; j++){
            saldos[i]-=g1[i][j];
            saldos[j]+=g1[i][j];
        }
    }
    if(debug){
        cout << "banks values: " << endl;
        for(int j = 0; j<s; j++){
            cout << saldos[j] << " ";
        }
        cout << endl;
    }
}


void dfs(int u){
    ids[u] = low[u] = ++id_counter;
    st.push(u);
    on_stack[u] = true;

    for(int v : g[u]){
        if(ids[v] == 0){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(on_stack[v]){
            low[u] = min(low[u], ids[v]);
        }
    }

    if(ids[u] == low[u]){
        vector<int> scc;
        int v;
        do{
            v = st.top();
            st.pop();
            on_stack[v] = false;
            scc.push_back(v);
        } while(v != u);

        sccs.push_back(scc);
    }
}

void tarjan(int n){
    ids = vector<int> (n,0);
    low = vector<int> (n,0);
    on_stack = vector<bool> (n,false);

    for(int i = 0; i < n; i++){
        if(ids[i] == 0){
            dfs(i);
        }
    }
}

int main(){
    int size;
    while(cin >> size){
        sccs.clear();
        g1.clear();
        g.clear();
        ids.clear();
        low.clear();
        on_stack.clear();
        saldos.clear();
        int conta = 0;
        int a, to, b;
        g = vector<vector<int>> (size);
        g1 = vector<vector<int>> (size,vector<int>(size));
        while(conta<size){
            cin >> a;
            g[a-1] = vector<int>{};
            while(true){
                int deve, aQuem;
                cin >> deve;
                if(deve == 0) break;
                else{
                    cin >> aQuem;
                    g[a-1].push_back(aQuem-1);
                    g1[a-1][aQuem-1] = deve;
                }
            }
            conta++;
        }
        if(debug){
            cout << "g's list of adjency: " << endl;
            for(int i = 0; i < size; i++){
                cout << i + 1 << ": ";
                for(int j = 0; j < g[i].size(); j++){
                    cout << g[i][j] + 1 << " ";
                }
                cout << endl;
            }
        }
        tarjan(size);
        calculaSaldos(size);
        if(debug){
            cout << "Connected components" << endl;
            for(auto& scc : sccs){
                for(int v : scc){
                    cout << v + 1 << " ";
                }
                cout << endl;
            }
        }

        int out = 0;
        int maxsize = 0;
        for(auto& scc : sccs){
            int s = scc.size();
            if(s > 1){
                if(s > maxsize){
                    out = 0;
                    maxsize = s;
                    for(int v : scc){
                        out += saldos[v];
                    }
                }
            }
        }
        if(debug) cout << "result: " << endl;
        if(maxsize>1) cout << out << endl;
        else cout << "No cluster" << endl;
    }
}
