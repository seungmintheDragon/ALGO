using System;
using System.Collections;
using System.Linq;
using System.Collections.Generic;

namespace BackJoon 
{
    class Program
    {
        private static int gcd(int a, int b)
        {
            return b != 0 ? gcd(b, a % b) : a;
        }
        
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] num = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[] LtoR = new int[n];
            int[] RtoL = new int[n];
            LtoR[0] = num[0];
            RtoL[n - 1] = num[n - 1];
            
            for(int i = 1; i <= n - 1; i ++)
            {
                int val = LtoR[i - 1];
                LtoR[i] = gcd(Math.Max(val, num[i]), Math.Min(val, num[i]));
            }
            
            for(int i = n - 2; i >= 0; i --)
            {
                int val = RtoL[i + 1];
                RtoL[i] = gcd(Math.Max(val, num[i]), Math.Min(val, num[i])); 
            }
            
            int result = -1;
	        int except = -1;

	        for (int i = 0; i < n; i++)
            {
		        if (i == 0)
                {
			        result = Math.Max(result, RtoL[1]);
                    except = num[i];
		        }
		        else if (i == n - 1)
                {
			        if (result < LtoR[n-2])
                    {
				        result = LtoR[n-2];
				        except = num[i];
			        }
		        }
		        else
                {
			        if (result < gcd(LtoR[i - 1], RtoL[i + 1]))
                    {
				        result = gcd(LtoR[i - 1], RtoL[i + 1]);
				        except = num[i];
			        }
		        }
	        }

	        if (except % result == 0)
            {
		        Console.WriteLine(-1);
	        }
	        else
            {
		        Console.WriteLine(result + " " + except);
	        }
        }
    }
}