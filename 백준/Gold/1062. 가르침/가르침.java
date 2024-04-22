import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{

    static int k;
    static int n;
    static String[] words;
    static boolean[] alpha = new boolean[26];
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        words = new String[n];

        for(int i = 0; i < n; i ++) {
            words[i] = br.readLine();
        }



        alpha['a' - 'a'] = true;
        alpha['n' - 'a'] = true;
        alpha['t' - 'a'] = true;
        alpha['i' - 'a'] = true;
        alpha['c' - 'a'] = true;


        if (k < 5) {
            System.out.println(ans);
        }
        else {
            DFS(0, 0);
            System.out.println(ans);
        }


    }

    static void DFS(int cnt, int cur) {
        if(cnt + 5 == k) {
            countAlpha();

        }

        for(int i = cur; i < 26; i ++) {
            if(alpha[i]) {
                continue;
            }
            //System.out.println(i + "현재 위치");
            alpha[i] = true;
            DFS(cnt + 1, i + 1);
            alpha[i] = false;
        }
    }

    static void countAlpha() {
        int cnt = 0;
        for(int i = 0; i < n; i ++) {
            boolean flag = true;
            char[] word = words[i].toCharArray();
            for(char c : word) {
                if(!alpha[c - 'a']) {
                    flag = false;
                    break;
                }
            }

            if(flag) cnt ++;

        }

        ans = Math.max(ans, cnt);
    }

}