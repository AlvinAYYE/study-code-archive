using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 找零錢
{
    class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                Console.WriteLine("Input:");
                var moneyType = Console.ReadLine().Split(' ').Select(x => x.toInt()).ToList();
                var count = Console.ReadLine().toInt();
                var money = new List<int>();
                for (int i = 0; i < count; i++)
                {
                    money.Add(Console.ReadLine().toInt());
                }
                var result = new List<String>();
                money.ForEach(x =>
                {
                    result.Add(changeCoin(moneyType.ToArray(), x));
                });

                Console.WriteLine();
                Console.WriteLine("Output:");
                result.ForEach(x =>
                {
                    Console.WriteLine(x);
                });
                
                Console.WriteLine();
            }
        }

        public static string changeCoin(int[] moneyType, int amount)
        {
            int typeCount = moneyType.Length;
            var resultList = new List<string>();
            var dp = Enumerable.Range(0, amount + 1).Select(x=>x = int.MaxValue).ToList();
            int[] lastBestCoinKindIndexes = new int[amount + 1];

            dp[0] = 0;

            for (int i = moneyType[0]; i <= amount; ++i)
            {
                int min =  int.MaxValue - 1;

                for (int c = 0; c < typeCount; ++c)
                {
                    int type = moneyType[c];

                    if (i < type)
                    {
                        break;
                    }

                    int remainAmount = i - type;

                    if (min > dp[remainAmount])
                    {
                        min = dp[remainAmount];
                        lastBestCoinKindIndexes[i] = c;
                    }
                }

                dp[i] = min + 1;
            }

            for (int a = 0; a <= amount; ++a)
            {
                int minCount = dp[a];

                if (minCount == int.MaxValue)
                {
                    continue;
                }

                int[] coinKindsCounts = new int[typeCount];

                int n = a;

                while (n > 0)
                {
                    int lastBestCoinKindIndex = lastBestCoinKindIndexes[n];
                    int lastBestCoinKind = moneyType[lastBestCoinKindIndex];

                    ++coinKindsCounts[lastBestCoinKindIndex];
                    n -= lastBestCoinKind;
                }

                resultList.Add(string.Join(" ", coinKindsCounts));
            }
            return resultList.Last();
        }
    }

    static class Extensions
    {
        public static int toInt(this object obj)
        {
            return Convert.ToInt32(obj);
        }
    }
}
