using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 最長遞增子序列
{
    //0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
    class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                Console.WriteLine("Input: ");
                var input = Console.ReadLine().Split(' ').Select(x=>x.toInt()).ToList();

                Console.WriteLine();
                Console.WriteLine("Output:");
                Console.WriteLine(result(input));


                Console.WriteLine();
            }
        }   

        private static string result(List<int> arr)
        {
            var result = new List<string>();
            var maxlen = 1;
            var maxidx = 0;
            for (int i = 0; i < arr.Count; i++)
            {
                for (int j = 0; j < result.Count; j++)
                {
                    var data = result[j].Split(' ').Where(x=>x != "").Select(x => x.toInt()).ToList();
                    if(data[data.Count - 1] < arr[i])
                    {
                        result.Add(result[j]  + arr[i] + " ");
                    }

                    if(maxlen == data.Count && data[data.Count - 1] < arr[i])
                    {
                        maxlen = data.Count() + 1;
                        maxidx = j;
                    }
                }
                result.Add(arr[i] + " ");
            }


            var maxsum = int.MaxValue;
            result.Where(x=>x.TrimEnd().Split(' ').ToList().Count == maxlen).ToList().ForEach(x =>
              {
                  var sum = x.TrimEnd().Split(' ').Select(z => z.toInt()).Sum();
                  if(maxsum > sum)
                  {
                      maxsum = sum;
                      maxidx = result.IndexOf(x);
                  }
              });

            return result[maxidx];
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
