using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 巴斯卡三角形
{
    class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                Console.WriteLine("Input:");
                var input = Console.ReadLine();
                Console.WriteLine();
                Console.WriteLine("Output:");
                Console.WriteLine(getResult(int.Parse(input)));
                Console.WriteLine();
            }
        }

        public static String getResult(int index)
        {
            var resultList = new List<List<ulong>>();
            resultList.Add(new List<ulong> { 1 });
            for (int i = 0; i < 99; i++)
            {
                var line = new List<ulong>();
                line.Add(1);

                for (int j = 1; j < resultList[i].Count(); j++)
                {
                    line.Add(resultList[i][j] + resultList[i][j - 1]);
                }

                line.Add(1);

                resultList.Add(line);
            }

            return string.Join(" ", resultList[index]);
        }
    }
}
