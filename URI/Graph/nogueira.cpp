#include<bits/stdc++.h>
#define MAX 100
using namespace std;
using ii = pair<int,int>;

vector<string> grid(MAX);
int dx [] = {1,0,-1,0};
int dy [] = {0,1,0,-1};
bool visited[MAX][MAX][MAX];

typedef struct {
    int dist = 0;
    pair<int,int> a = ii(-1,-1),b = ii(-1,-1),c = ii(-1,-1);//posição
    pair<int,int> stA = ii(-1,-1),stB = ii (-1,-1),stC = ii (-1,-1);//status
}STATE;

int solve(int N){
    bool flag = false;
    int x,y,movs = -1;
    queue<STATE> to_visit;
    STATE init_state;

    //Inicialização
    memset(visited,false,sizeof(visited));
    init_state.dist = 0; init_state.stA = ii(-1,-1); init_state.stB = ii(-1,-1); init_state.stC = ii(-1,-1);

    for(int i = 0;i < N;i++){
        for(int j = 0;j  < N;j++){
            if(grid[i][j] == 'A') init_state.a = ii(i,j);
            if(grid[i][j] == 'B') init_state.b = ii(i,j);
            if(grid[i][j] == 'C') init_state.c = ii(i,j);
        }
    }

    //BFS
    to_visit.push(init_state);
    
    while(!to_visit.empty() && !flag){
        STATE current_state = to_visit.front();
        to_visit.pop();

        for(int i = 0;i < 4;i++){
                STATE next_state;
                
                //Obstáculos
                x = current_state.a.first + dx[i], y = current_state.a.second + dy[i];
                if(x >= 0 && y >= 0 && x < N && y < N && grid[x][y] != '#') next_state.a = ii(x,y);
                else next_state.a = ii(current_state.a.first,current_state.a.second);

                x = current_state.b.first + dx[i], y = current_state.b.second + dy[i];
                if(x >= 0 && y >= 0 && x < N && y < N && grid[x][y] != '#') next_state.b = ii(x,y);
                else next_state.b = ii(current_state.b.first,current_state.b.second);

                x = current_state.c.first + dx[i], y = current_state.c.second + dy[i];
                if(x >= 0 && y >= 0 && x < N && y < N && grid[x][y] != '#') next_state.c = ii(x,y);
                else next_state.c = ii(current_state.c.first,current_state.c.second);

                //Robôs
                if(next_state.a == next_state.b){
                    if(current_state.a == next_state.a){
                        next_state.b = current_state.b;
                        if(next_state.b == next_state.c) next_state.c = current_state.c;
                    }else{
                        next_state.a = current_state.a;
                        if(next_state.a == next_state.c) next_state.c = current_state.c;
                    }
                }
                if(next_state.a == next_state.c){
                    if(current_state.a == next_state.a){
                        next_state.c = current_state.c;
                        if(next_state.c == next_state.b) next_state.b = current_state.b;
                    }else{
                        next_state.a = current_state.a;
                        if(next_state.a == next_state.b) next_state.b = current_state.b;
                    }
                }
                if(next_state.b == next_state.c){
                    if(current_state.b == next_state.b){
                            next_state.c = current_state.c;
                            if(next_state.c == next_state.a) next_state.a = current_state.a;
                    }else{
                        next_state.b = current_state.b;
                        if(next_state.b == next_state.a) next_state.a = current_state.a;
                    }
                }

                if(visited[next_state.a.first*N+next_state.a.second][next_state.b.first*N+next_state.b.second][next_state.c.first*N+next_state.c.second]) continue;

                //Célula alvo
                if(next_state.stA == ii(-1,-1) && grid[next_state.a.first][next_state.a.second] == 'X'){
                    if(next_state.a != next_state.stB && next_state.a != next_state.stC) next_state.stA = next_state.a;
                }
                if(next_state.stB == ii(-1,-1) && grid[next_state.b.first][next_state.b.second] == 'X'){
                    if(next_state.b != next_state.stA && next_state.b != next_state.stC) next_state.stB = next_state.b;
}
                if(next_state.stC == ii(-1,-1) && grid[next_state.c.first][next_state.c.second] == 'X'){
                    if(next_state.c != next_state.stA && next_state.c != next_state.stB) next_state.stC = next_state.c;
                }

                visited[next_state.a.first*N+next_state.a.second][next_state.b.first*N+next_state.b.second][next_state.c.first*N+next_state.c.second] = true;
                next_state.dist = current_state.dist + 1;

                //Terminou
                if(next_state.stA != ii(-1,-1) && next_state.stB != ii(-1,-1) &&  next_state.stC != ii(-1,-1)){
                    flag = true;
                    movs = next_state.dist;
                    break;
                }
                to_visit.push(next_state);
        }
    }

    return movs;
}

int main(){
    ios::sync_with_stdio(false);
    int t,n;

    cin >> t;
    for(int ct = 1;ct <= t;ct++){
        cin >> n;
        for(int i = 0;i < n;i++) cin >> grid[i];

        int ans = solve(n);
        if(ans != -1) cout << "Case " << ct << ": " << ans << endl;
        else cout << "Case " << ct << ": " << "trapped" << endl;
    }

    return 0;
}