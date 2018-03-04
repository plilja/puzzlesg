using System;
using System.Collections.Generic;
using System.Linq;

class Reduction
{
    static void Main(String[] _)
    {
        int t = int.Parse(Console.ReadLine());
        for (int i = 1; i <= t; i++)
        {
            var args = Console.ReadLine().Split(' ');
            int N = int.Parse(args[0]);
            int M = int.Parse(args[1]);
            int L = int.Parse(args[2]);
            List<Tuple<string, int, int>> agencies = new List<Tuple<string, int, int>>();
            for (int j = 0; j < L; j++)
            {
                var agency = Console.ReadLine();
                var idx = agency.IndexOf(':');
                var name = agency.Substring(0, idx);
                var tmp = agency.Substring(idx + 1).Split(',');
                int A = int.Parse(tmp[0]);
                int B = int.Parse(tmp[1]);
                agencies.Add(new Tuple<string, int, int>(name, A, B));
            }
            List<Tuple<int, string>> prices = CalcPrices(N, M, agencies);
            prices.Sort();
            Console.WriteLine(String.Format("Case {0}", i));
            foreach (var price in prices)
            {
                Console.WriteLine("{0} {1}", price.Item2, price.Item1);
            }
        }
    }

    static List<Tuple<int, string>> CalcPrices(int N, int M, List<Tuple<string, int, int>> agencies)
    {
        return agencies
            .Select(agency => new Tuple<int, string>(CalcPrice(N, M, agency.Item2, agency.Item3), agency.Item1))
            .ToList();
    }

    static int CalcPrice(int N, int M, int A, int B)
    {
        int half = N / 2;
        if (half < M || (N - half) * A < B)
        {
            return (N - M) * A;
        }
        else
        {
            return B + CalcPrice(half, M, A, B);
        }
    }
}