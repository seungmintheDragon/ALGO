import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static int[] parents;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] ws = new int[n + 1];
        parents = new int[n + 1];
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        int ans = 0;

        for(int i = 1; i <= n; i ++) {
            ws[i] = Integer.parseInt(br.readLine());
            parents[i] = i;
            pq.add(new Edge(0, i, ws[i]));
        }

        for(int i = 1; i <=n; i ++) {
            //String[] line = br.readLine().split(" ");
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= n; j ++) {
                if(i < j) {
                    //pq.add(new Edge(i, j, Integer.parseInt(line[j - 1])));
                    pq.add(new Edge(i, j, Integer.parseInt(st.nextToken())));
                } else st.nextToken();
            }
        }

        while (!pq.isEmpty()) {
            Edge edge = pq.poll();

            if(findParent(edge.v1) == findParent(edge.v2)) {
                continue;
            }

            union(edge.v1, edge.v2);
            ans += edge.w;
        }
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    static int findParent(int v) {
        if(parents[v] == v) {
            return v;
        }
        return findParent(parents[v]);
    }

    static void union(int v1, int v2) {
        int p1 = findParent(v1);
        int p2 = findParent(v2);
        if(p1 > p2) parents[p1] = p2;
        else parents[p2] = p1;
    }

    static class Edge implements Comparable<Edge> {
        public Edge(int v1, int v2, int w) {
            this.v1 = v1;
            this.v2 = v2;
            this.w = w;
        }

        int v1;
        int v2;
        int w;

        @Override
        public int compareTo(Edge o) {
            return this.w - o.w;
        }
    }
}
