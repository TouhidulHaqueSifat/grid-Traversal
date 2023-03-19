#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int maze[N][N];
/*
5 8
########
#.A#...#
#.##.#B#
#......#
########

x  y
-  -
0  1
0  -1
-1  0
1   0

direction array
dx={0,0,-1,1}
dy={1,-1,0,0}
for(int i=0;i<4;i++)
    new_dx=x+d[i]
    new_dy=y+d[i]

we have to check :
1)is the cell within the maze
2)is the cell is wall
3) is the cell is visited
*/
int visited[N][N],level[N][N];

//DIRECTION ARRAY
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n,m;

bool is_inside(pair<int,int>coord){
  int x=coord.first;
  int y=coord.second;

  if(x>=0 && x<n && y>=0 && y<m)
        return true;
  return false;

}
bool is_safe(pair<int , int>coord)
{
    int x=coord.first;
    int y=coord.second;
    if(maze[x][y]==-1)
        return false;
    return true;
}

void bfs(pair<int,int>source)
{
    queue<pair<int,int>>q;
    visited[source.first][source.second]=1;
    level[source.first][source.second]=0;
    q.push(source);

    while(!q.empty()){
        pair<int ,int>head=q.front();
        q.pop();
        int x=head.first;
        int y=head.second;
        for(int i=0;i<4;i++){
          int new_X=x+dx[i];
          int new_Y=y+dy[i];
          pair<int,int>adj_node={new_X,new_Y};

          if(is_inside(adj_node) && is_safe(adj_node) && visited[new_X][new_Y]==0 )
          {
              visited[new_X][new_Y]=1;
              level[new_X][new_Y]=level[x][y]+1;
              q.push(adj_node);
          }

        }
    }

}
int main()
{

    cin>>n>>m;
    pair<int , int>src,dst;
    for(int i=0; i<n; i++)
    {
        string input;
        cin>>input;
        for(int j=0; j<m; j++)
        {
            if(input[j]=='#')
            {
                maze[i][j]=-1;
            }
            else if(input[j]=='A'){
                src={i,j};
            }
            else if(input[j]=='B'){
                dst={i,j};
            }
        }

    }
    bfs(src);
    if(visited[dst.first][dst.second]==0)
    {
        cout<<"NO";
    }
    else{
        cout<<"YES"<<"\n";
        cout<<level[dst.first][dst.second];
    }

    return 0;
}
