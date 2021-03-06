#include<bits/stdc++.h>
using namespace std;
void printTheCycle();


int isRes[100];
bool bg = false;

int node, edge,k, mainNode,m;
vector<int> V[100];
int color[100];
int cycle[100];
int resource, process;



void killAndRecovery(int m)
{
    // find resource and
   // cout<<"Enter kill process\n";
    if(isRes[cycle[m]])
        resource = cycle[m];
    else
        process = cycle[m];

    if(isRes[cycle[k-1]])
        resource = cycle[k-1];//
    else
        process = cycle[k-1];

    //cout<<"Resource: "<<resource;
    //cout<<",process: "<<process<<"\n";
    cout<<"process "<<process<<" is killed\n";

    V[resource].clear();

    for(int i = m; i < k; i++)
        if(cycle[i] != process)
            cout<<cycle[i]<<" ";
    cout<<"\n";

}

void printTheCycle(int m)
{
    //cout<<"Enter PrintCycle\n";
    for(int i = m; i < k; i++)
        cout<<cycle[i]<<" ";
    cout<<"\n";

    killAndRecovery(m);
    return;
}



void DFS(int u)
{
    //cout<<"Enter dfs\n";
    //cout<<"u = "<<u<<"\n";

    color[u] = 1;
    cycle[k++] = u;
    for(int i = 0; i < V[u].size(); i++)
    {
        int v = V[u][i];
        //cout<<"v = "<<v<<"\n";
        //cout<<"main node = "<<mainNode<<"\n";
        if(v == mainNode)
        {
            cout<<"A cycle detected\n";
            printTheCycle(m);
            m = k;
            bg = true;
        }
        else if(color[v] == 0)
        {
            if(bg)
            {
                bg = false;
                mainNode = v;
            }
            DFS(v);
        }
    }
}


int main()
{
    cout<<"Enter node and edge number:";
    cin>>node>>edge;


    cout<<"Start->end->1(if resource)-> else 0\n";
    int u, v, r1, r2;
    for(int i = 1; i <= edge; i++)
    {
        cin>>u>>v>>r1>>r2;
        V[u].push_back(v);
        isRes[u] = r1;
        isRes[v] = r2;

    }



    for(int i = 1; i <= node; i++)
    {

        if(color[i] == 0)
        {
            m = 0;
            k = 0;
            mainNode = i;
            DFS(mainNode);
        }
    }

    return 0;

}

/*
13 13
1 2 1 0
2 3 0 1
4 3 0 1
5 3 0 1
6 5 1 0
7 3 7 1
7 8 0 1
9 8 0 1
8 10 1 0
10 11 0 1
11 12 1 0
12 13 0 1
13 7 1 0




1 2 0 1
2 3 1 0
3 1 0 0
2 4 1 0
4 5 0 1
5 6 1 0
6 7 0 1
7 4 1 0
*/

//
