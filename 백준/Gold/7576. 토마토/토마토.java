import java.io.BufferedReader;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
public class Main {
    static int n;
    static int m;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        int tomato = 0;
        //System.out.println(m +" " + n);
        Queue<pair> q = new LinkedList<pair>();
        for(int i = 0; i < n; i ++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j ++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                //System.out.print(arr[i][j] + " ");
                if(arr[i][j] == 1) q.offer(new pair(i, j));
                if(arr[i][j] == 0) tomato ++;
            }
            //System.out.println();
        }

        int day = -1;
        int[] dx = {0, -1, 0, 1};
        int[] dy = {-1, 0, 1, 0};
        //System.out.println("-----------------------------------");
        if(tomato == 0 && q.size() > 0) {
            System.out.println("0");
        } else if(tomato == 0) {
            System.out.println("-1");
        } else {
            
            while(!q.isEmpty()) {
                day ++;
                int qsize = (int) q.size();
                //System.out.println("-----------------------------------");
                for(int dd = 0; dd < qsize; dd ++) {
                    pair cur = q.poll();
                    //System.out.println(cur.x + " " +cur.y);
                    int x = cur.x;
                    int y = cur.y;
                    for(int i = 0; i < 4; i ++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(inRange(nx, ny)) {
                            arr[nx][ny] = 1;
                            tomato --;
                            q.offer(new pair(nx,ny));
    
                        }
                    }
                }
            }
    
            if(tomato == 0) {
                System.out.println(day + "");
            } else{
                System.out.println("-1");
            }
        }


    }

    static boolean inRange(int x, int y) {
        return 0 <= x && x < n && 0<=y && y< m && arr[x][y] == 0;
    }

    static class pair{
        int x;
        int y;

        public pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
