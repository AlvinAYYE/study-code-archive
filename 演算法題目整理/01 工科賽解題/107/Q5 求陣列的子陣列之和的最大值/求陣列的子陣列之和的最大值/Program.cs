using System;
using System.Collections.Generic;
using System.Linq;

namespace 求陣列的子陣列之和的最大值
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("Input: ");
                var count = Console.ReadLine().toInt();
                var numList = Console.ReadLine().Split(' ').Select(x => x.toInt()).ToList();
                Console.WriteLine();

                Console.WriteLine("Output: ");
                var resultList = getResult(numList);
                var maxList = resultList.OrderByDescending(x => x.Sum()).First();
                
                Console.WriteLine(maxList.Sum());
                Console.WriteLine($"{numList.IndexOf(maxList.First())} {numList.IndexOf(maxList.Last())}");

                Console.WriteLine();
            }
        }

        public static List<List<int>> getResult(List<int> numList)
        {
            List<List<int>> resultList = new List<List<int>>();
            var count = 2;
            while (count <= numList.Count)
            {
                for (int i = 0; i < numList.Count; i++)
                {
                    var temp = new List<int>();

                    for (int j = i; j < i + count; j++)
                    {
                        if(i + count > numList.Count)
                        {
                            continue;
                        }
                        temp.Add(numList[j]);
                    }

                    resultList.Add(temp);
                }

                count++;
            }

            return resultList;
        }
    }

    static class Extension
    {
        public static int toInt(this string str)
        {
            return Convert.ToInt32(str);
        }
    }
}
