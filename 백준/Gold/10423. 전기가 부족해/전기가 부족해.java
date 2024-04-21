import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static ArrayList<edge>[] arr;
    public static int[] elect;
    public static PriorityQueue<edge> pq;
    static class edge implements Comparable<edge>{
        int next;
        int w;

        public edge(int next, int w) {
            this.next = next;
            this.w = w;
        }

        @Override
        public int compareTo(edge o) {
            return this.w - o.w;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        arr = new ArrayList[n + 1];
        for(int i = 0; i <= n; i++) arr[i] = new ArrayList<edge>();

        elect = new int[k];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < k; i ++) {
            elect[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < m; i ++) {
            st = new StringTokenizer(br.readLine());
            int e1 = Integer.parseInt(st.nextToken());
            int e2 = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            //System.out.printf("e1: %d e2: %d w: %d", e1, e2, weight);
            arr[e1].add(new edge(e2, weight));
            arr[e2].add(new edge(e1, weight));
        }

        boolean[] isVisit = new boolean[n + 1];
        pq = new PriorityQueue<>();
        for(int i = 0; i < k; i ++) {
            isVisit[elect[i]] = true;
            for (edge e:arr[elect[i]]) {
                pq.add(e);
            }
        }
        int ans = 0;
        while (!pq.isEmpty()) {
            edge e = pq.poll();
            if(!isVisit[e.next]) {
                isVisit[e.next] = true;
                ans += e.w;
                for (edge nextE:arr[e.next]) {
                    if(!isVisit[nextE.next]) {
                        pq.add(nextE);
                    }
                }
            }
        }

        bw.write(ans + "");
        bw.flush();
        bw.close();

    }
}
