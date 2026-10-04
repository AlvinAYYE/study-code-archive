using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 最長子序列
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("Input: ");
                var inputList = Console.ReadLine().Split(' ').Select(x => x.toInt()).ToList();
                lcs3(inputList);
                var maxLength = allResult.Max(x => x.Count());
                var result = allResult.Where(x => x.Count() == maxLength).ToList().OrderBy(x => x.Sum()).First();

                Console.WriteLine("Output: ");
                Console.WriteLine(string.Join(" ", result));
                Console.WriteLine("");
                allResult.Clear();
            }
        }

        public static void lcs(List<int> inputList)
        {
            for (int i = 0; i < inputList.Count; i++)
            {
                for (int j = 0; j < allResult.Count; j++)
                {
                    var data = allResult[j];
                    if (data[data.Count - 1] < inputList[i])
                    {
                        var newData = new List<int>(allResult[j]);
                        newData.Add(inputList[i]);
                        allResult.Add(newData);
                    }
                }
                allResult.Add(new List<int>() { inputList[i] });
            }
        }

        public static List<List<int>> allResult = new List<List<int>>();

        public static void lcs2(List<int> inputList)
        {
            for (int i = 0; i < inputList.Count; i++)
            {
                for (int j = 0; j < allResult.Count; j++)
                {
                    var data = allResult[j];
                    if (data[data.Count - 1] < inputList[i])
                    {
                        var newList = new List<int>(allResult[j]);
                        newList.Add(inputList[i]);
                        allResult.Add(newList);
                    }
                }

                allResult.Add(new List<int>() { inputList[i] });
            }
        }

        public static void lcs3(List<int> inputList)
        {
            for (int i = 0; i < inputList.Count; i++)
            {
                for (int j = 0; j < allResult.Count; j++)
                {
                    var data = allResult[j];
                    if(data[data.Count - 1] < inputList[i])
                    {
                        var newList = new List<int>(data);
                        newList.Add(inputList[i]);
                        allResult.Add(newList);
                    }
                }

                allResult.Add(new List<int>() { inputList[i] });
            }
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
