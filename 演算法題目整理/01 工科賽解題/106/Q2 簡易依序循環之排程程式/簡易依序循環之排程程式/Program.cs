using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 簡易依序循環之排程程式
{
    class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                Console.Write("請輸入行程processes數量(MAX 5): ");
                var count = Console.ReadLine().toInt();
                if (count > 5)
                    continue;

                Console.WriteLine();
                Console.WriteLine("請輸入每個行程的執行時間burst_time...");
                var pList = new List<int>();
                for (int i = 1; i <= count; i++)
                {
                    Console.Write($"P{i}: ");
                    var input = Console.ReadLine().toInt();
                    pList.Add(input);
                }

                Console.WriteLine();
                Console.Write("請輸入時間配額time_quantum: ");
                var mini = Console.ReadLine().toInt();
                var timeQuantumStr = "";
                int[] time = new int[count];
                int times = 0;
                int index = 0;
                List<int> remove = new List<int>();
                string str = "";
                while (pList.Count(x => x > 0) > 0)
                {
                    if (pList[index] <= 0)
                    {
                        index = (index + 1) % count;
                        continue;
                    }
                    str += (times * mini).ToString().PadLeft(2, '0') + ":" + "P" + (index + 1).ToString() + "    ";
                    pList[index] -= mini;
                    if (pList[index] <= 0)
                    {
                        remove.Add(index);
                    }

                    for (int i = 0; i < count; i++)
                    {
                        if (i == index || remove.Any(x => x == i))
                        {
                            continue;
                        }
                        time[i] += mini;
                    }
                    times += 1;
                    index = (index + 1) % count;
                }
                Console.WriteLine("各行程processes執行順序為...");
                Console.WriteLine(str);
                Console.WriteLine();
                for (int i = 0; i < count; i++)
                {
                    Console.Write($"P{i + 1}等待時間：{time[i]}    ");
                }
                Console.WriteLine();
                Console.WriteLine();
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
