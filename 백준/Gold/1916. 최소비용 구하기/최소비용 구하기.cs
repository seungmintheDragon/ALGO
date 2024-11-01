using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace Baekjoon
{
    class Program
    {
        public class MyCompare : IComparer<List<int>>
        {
            public int Compare(List<int> x, List<int> y)
            {
                if(x[0] == y[0]) return x[1] - y[1];
                return x[0] - y[0];
            }
        }
        
        static int N;
        static int M;
        static int S;
        static int E;
        static int[] dist = new int[1001];
        static List<List<int>>[] nodes = new List<List<int>>[1001];        
        
        public static void Dijkstra()
        {
            SortedSet<List<int>> pq = new SortedSet<List<int>>(new MyCompare());
            dist[S] = 0;
            pq.Add(new List<int>() {0, S});
            while(pq.Count != 0)
            {
                List<int> costcur = pq.First();
                pq.Remove(costcur);
                int cost = costcur[0];
                int cur = costcur[1];
                if(dist[cur] < cost) continue;
                
                for(int i = 0; i < nodes[cur].Count; i ++)
                {
                    int next = nodes[cur][i][0];
                    int nc = cost + nodes[cur][i][1];
                    if(dist[next] > nc)
                    {
                        dist[next] = nc;
                        pq.Add(new List<int>() {nc, next});
                    }
                }
            }
        }
        
        
        static void Main(String[] args)
        {
            int[] input;
            N = int.Parse(Console.ReadLine());
            M = int.Parse(Console.ReadLine());
            for(int i = 0; i <= N; i ++) 
            {    
                 nodes[i] = new List<List<int>>();
                 dist[i] = (int)1e9;
            }
            for(int i = 0; i < M; i ++) {
                input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                nodes[input[0]].Add(new List<int>{input[1], input[2]});
            }
            input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            S = input[0]; E = input[1];
            Dijkstra();
            Console.WriteLine(dist[E]);
            
        }
    }
}