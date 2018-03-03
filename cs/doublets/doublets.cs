using System;
using System.Collections.Generic;

class Doublets
{
    ISet<string> dict = new HashSet<string>();
    IDictionary<string, int> wordToIdx = new Dictionary<string, int>();
    IDictionary<int, string> idxToWord = new Dictionary<int, string>();
    List<int>[] graph;

    private void Solve()
    {
        ReadDict();
        IndexDict();
        ConstructGraph();
        ProcessQueries();
    }

    void ReadDict()
    {
        while (true)
        {
            var s = Console.ReadLine();
            if ("".Equals(s))
            {
                break;
            }
            dict.Add(s);
        }
    }

    void IndexDict()
    {
        int i = 0;
        foreach (var w in dict)
        {
            wordToIdx[w] = i;
            idxToWord[i] = w;
            i++;
        }
    }

    void ConstructGraph()
    {
        var patternToWords = new Dictionary<string, IList<int>>();
        foreach (var w in dict)
        {
            int idx = wordToIdx[w];
            GetOrInsert(patternToWords, w, () => new List<int>()).Add(idx);
            for (int i = 0; i < w.Length; i++)
            {
                var pattern = w.Substring(0, i) + '*' + w.Substring(i + 1); // Replace one char
                GetOrInsert(patternToWords, pattern, () => new List<int>()).Add(idx);
            }
        }
        var edges = new HashSet<Tuple<int, int>>();
        foreach (var oneDiffWords in patternToWords.Values)
        {
            foreach (var w1 in oneDiffWords)
            {
                foreach (var w2 in oneDiffWords)
                {
                    if (w1 != w2)
                    {
                        edges.Add(new Tuple<int, int>(Math.Min(w1, w2), Math.Max(w1, w2)));
                    }
                }
            }
        }
        graph = new List<int>[dict.Count];
        for (int i = 0; i < dict.Count; i++)
        {
            graph[i] = new List<int>();
        }
        foreach (var edge in edges)
        {
            graph[edge.Item1].Add(edge.Item2);
            graph[edge.Item2].Add(edge.Item1);
        }
    }

    void ProcessQueries()
    {
        bool first = true;
        while (true)
        {
            var inp = Console.ReadLine();
            if (inp == null)
            {
                return;
            }
            if (!first)
            {
                Console.WriteLine();
            }
            first = false;
            var args = inp.Split(' ');
            var w1 = args[0];
            var w2 = args[1];
            var ans = Bfs(w1, w2);
            if (ans == null)
            {
                Console.WriteLine("No solution.");
            }
            else
            {
                foreach (var w in ans)
                {
                    Console.WriteLine(idxToWord[w]);
                }
            }
        }
    }

    IEnumerable<int> Bfs(string w1, string w2)
    {
        int fr = wordToIdx[w1];
        int to = wordToIdx[w2];
        var visited = new bool[dict.Count];
        var pre = new int[dict.Count];
        var q = new Queue<int>();
        q.Enqueue(fr);
        visited[fr] = true;
        while (q.Count != 0 && !visited[to])
        {
            int t = q.Dequeue();
            foreach (var neighbour in graph[t])
            {
                if (!visited[neighbour])
                {
                    q.Enqueue(neighbour);
                    pre[neighbour] = t;
                    visited[neighbour] = true;
                }
            }
        }
        if (!visited[to])
        {
            return null;
        }
        else
        {
            var ans = new LinkedList<int>();
            int v = to;
            while (v != fr)
            {
                ans.AddFirst(v);
                v = pre[v];
            }
            ans.AddFirst(fr);
            return ans;
        }

    }

    static V GetOrInsert<K, V>(IDictionary<K, V> d, K key, Func<V> def)
    {
        if (!d.ContainsKey(key))
        {
            V v = def();
            d[key] = v;
            return v;
        }
        return d[key];
    }

    static void Main(String[] args)
    {
        new Doublets().Solve();
    }
}