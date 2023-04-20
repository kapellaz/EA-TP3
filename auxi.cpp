#include <iostream>
#include <vector>


using namespace std;

vector<vector<int>> g;



int main(){
    int size;
    while(cin >> size){
        int conta = 0;
        int a, to, b;
        g = vector<vector<int>> (size,vector<int>(size));
        while(conta<size){
            int a;
            cin >> a;
            while(cin){
                int deve, aQuem;
                cin >> deve;
                if(deve == 0) break;
                else{
                    cin >> aQuem;
                    g[a-1][aQuem-1] = deve;
                }
            }
            conta++;
        }

    }
    /*
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }*/

}