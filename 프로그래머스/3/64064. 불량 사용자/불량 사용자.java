import java.util.Arrays;
import java.util.HashSet;

class Solution {
    static boolean[] isSame;
    static int ans = 0;
    static String[] sameString;
    static HashSet<String> stringSet = new HashSet<>();
    
    public int solution(String[] user_id, String[] banned_id) {

        
        int b_len = (int) banned_id.length;
        int u_len = (int) user_id.length;
        
        sameString = new String[b_len];
        
        
        isSame = new boolean[b_len];

        DFS(0, 0, u_len, b_len, user_id, banned_id);
        return stringSet.size();
    }
    
    
    static boolean compareString(String a, String b) {
        if(a.length() != b.length()) {
            return false;
        }
        
        char[] ac = a.toCharArray();
        char[] bc = b.toCharArray();
        
        boolean check = true;
        for(int i = 0; i < ac.length; i ++) {
            if (bc[i] == '*') {
                continue;
            }
            if(ac[i] != bc[i]) {
                check = false;
                break;
            }
        }
        
        return check;
        
    }
    
    static void DFS(int cur, int cnt_ban, int u_len ,int b_len ,String[] user_id, String[] banned_id) {
        if(cnt_ban == b_len) {
            //System.out.println(Arrays.toString(sameString));
            stringSet.add(Arrays.toString(sameString));
            ans ++;
            return;
        }
        //System.out.println(Arrays.toString(sameString));
        if(cur == u_len) {
            
            return;
        }
        for(int j = 0; j < b_len; j ++) {
            if(!isSame[j] && compareString(user_id[cur], banned_id[j])) {
                isSame[j] = true;
                sameString[cnt_ban] = user_id[cur];
                DFS(cur + 1, cnt_ban + 1, u_len, b_len, user_id, banned_id);
                isSame[j] = false;
                sameString[cnt_ban] = "";
            }
        }
        DFS(cur + 1, cnt_ban, u_len, b_len, user_id, banned_id);
    }

    
    
}