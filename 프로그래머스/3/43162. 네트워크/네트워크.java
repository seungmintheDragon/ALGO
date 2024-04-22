import java.util.Queue;
import java.util.LinkedList;

class Solution {
    boolean[] check;
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        check = new boolean[n];
              
        for(int i = 0; i < computers.length; i ++) {
            if(!check[i]) {
                DFS(i, computers);
                answer ++;
            }
        }
        
        return answer;
    }
    
    void DFS(int current, int[][] computers) {
        check[current] = true;
        for(int i =0; i < computers.length; i ++) {
            if(i != current && !check[i] && computers[current][i] == 1) {
                DFS(i, computers);
            }
        }
    }
}