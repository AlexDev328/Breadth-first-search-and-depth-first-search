#include <iostream>
#include <queue>
using namespace std;

#define MAX 20

int m[MAX][MAX], used[MAX];

int  n, a, b;

int dfs(int v)
{
    used[v] = 1;
    cout<<"Посещена вершина: "<<v+1<<endl;
    for (int i = 0; i <= n; i++)
        if (m[v][i] && !used[i]) dfs(i);
    return 0;
}

int bfs(int v)
{
    int lvl=1;
    used[v] = 1;
    queue<int> q;
    q.push(v);
    cout<<"посещена вершина "<<q.back()+1<<endl;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (m[k][i] && !used[i])
            {
                int u = i;
                if (!used[u])
                {
                    used[u] = lvl;
                    q.push(u);
                    cout<<"посещена вершина "<<q.back()+1<<endl;
                }
            }
        }
        lvl++;
    }
    return 0;
}



int main(void)

{
    // обнуляем переменные
    for (int j = 0; j < MAX; ++j) {
        for (int k = 0; k < MAX; ++k)
            m[j][k]=0;
        used[j]=0;
    }

    // читаем входные данные

    cin >> n;

    // составляем матрицу смежности
    for (int l = 0; l < n; ++l) {
        cin>>a>>b;
        a--;
        b--;

        m[a][b] = m[b][a] = 1;
    }
    //выводим матрицу смежности
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;

    }

    // запускаем поиск в глубину с вершины 1
    cout<<"DFS"<<endl;
    dfs(0);

    for (int i = 0; i < n; ++i)
        used[i]=0;
    // запускаем поиск в ширину с вершины 1
    cout<<"BFS"<<endl;
    bfs(0);

    return 0;
}
