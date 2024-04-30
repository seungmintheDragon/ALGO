#include <string>
#include <vector>

using namespace std;

#define INF 2000001 

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> minTaxi(n + 1, vector<int>(n+1, INF));
    
    for(int i = 0; i < fares.size(); i ++) {
        minTaxi[fares[i][0]][fares[i][1]] = fares[i][2];
        minTaxi[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int i = 0; i <= n; i ++) {
        minTaxi[i][i] = 0;
    }
    
    for(int k = 1; k <= n; k ++) {
        for(int i = 1; i <=n; i ++) {
            for(int j = 1; j <=n; j ++) {
                if(minTaxi[i][j] > minTaxi[i][k] + minTaxi[k][j]) {
                    minTaxi[i][j] = minTaxi[i][k] + minTaxi[k][j];
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i ++) {
        if(answer > minTaxi[s][i] + minTaxi[i][a] + minTaxi[i][b]){
            answer = minTaxi[s][i] + minTaxi[i][a] + minTaxi[i][b];
        }
    }
    
    
    return answer;
}