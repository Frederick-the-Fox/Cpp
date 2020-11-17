#include<iostream>
#include<queue>

using namespace std;

queue <int> q;

int start, target;
int step[10001];
int used[10001];

int bfs();
int canmoveto(int u, int dire);
int moveto(int u, int dire);
void init();

int main() {
    int num;

    cin >> start >> target;
    init();
    num = bfs();
    cout << num << endl;
}

int bfs(){
    int u, v, i;

    while(!q.empty()){
        u = q.front();
        q.pop();
        for (i = 0; i < 3; i++){
            if (canmoveto(u, i)){
                v = moveto(u, i);
                if (v == target){
                    return(step[u] + 1);
                }
                used[v] = 1;
                step[v] = step[u] + 1;
            }
        }
    }
}

int canmoveto(int u, int dire){
    int v;
    v = moveto(u, dire);
    if (v <= target && used[v] == 0){
        return (1);
    }
    else return (0);
}


int moveto(int u, int dire){
    int v;
    v = u+1;
    if (dire == 1){
        v = u * 2;
    }
    else if(dire == 2){
         v= u * u;
    }
    return u;
}

void init(){
}