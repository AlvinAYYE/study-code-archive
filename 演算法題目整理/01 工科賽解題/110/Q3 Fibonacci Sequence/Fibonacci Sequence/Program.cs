using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fibonacci_Sequence
{
    class Program
    {
        static void Main(string[] args)
        {
            var dataList = getFibonacci();
            var index = 1;
            dataList.RemoveAt(0);
            dataList.ForEach(x =>
            {
                Console.WriteLine($"{index} {x}");
                index++;
            });

            while (true)
            {
                Console.Write("請從費式數列(Fibonacci Sequence)中選擇第1個數字:");
                var first = Console.ReadLine().toInt();
                Console.Write($"您選擇第 {first} 費式數列(Fibonacci Sequence):");
                ulong firstFib = dataList[first - 1];
                Console.WriteLine(firstFib);

                Console.Write("請從費式數列(Fibonacci Sequence)中選擇第2個數字:");
                var second = Console.ReadLine().toInt();
                Console.Write($"您選擇第 {second} 費式數列(Fibonacci Sequence):");
                ulong secondFib = dataList[second - 1];
                Console.WriteLine(secondFib);

                ulong result = firstFib + secondFib;
                Console.Write($"兩個費式數列(Fibonacci Sequence) 相加結果為: {result}");
                Console.WriteLine();
            }
        }

        private static List<ulong> getFibonacci()
        {
            var result = new List<ulong>();
            result.Add(0);
            result.Add(1);
            for (int i = 1; i < 92; i++)
            {
                result.Add(result[i - 1] + result[i]);
            }

            return result;
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
