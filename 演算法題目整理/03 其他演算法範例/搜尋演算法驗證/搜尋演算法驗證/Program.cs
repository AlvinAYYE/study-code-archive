using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace 搜尋演算法驗證
{
    class Program
    {
        /*
         * 搜尋演算法時間驗證 
         * 時間比較(由小到大)： 
         *      線性搜尋
         * 注意事項
         * 1. 底下有兩種陣列，可選擇一種來驗證，或是想寫自己的演算法也可。
         */
        static void Main(string[] args)
        {
            Random ra = new Random(Guid.NewGuid().GetHashCode());
            List<int> ans = new List<int>();

            // 隨機排序之陣列
            int[] test = Enumerable.Range(1, 100000).OrderBy(x => ra.Next(0, 100000)).ToArray();

            // 反轉排序之陣列
            //int[] test = Enumerable.Range(1, 100000).Reverse().ToArray();

            // 搜尋目標(第一個)
            //int target = test[0];
            // 搜尋目標(隨機)
            //int target = test[ra.Next(0, test.Length)];
            // 搜尋目標(中間)
            int target = test[test.Length / 2];
            // 搜尋目標(最後一個)
            //int target = test[test.Length - 1];

            List<string> sort_name = new List<string>();
            List<long> times = new List<long>();
            Stopwatch sw = new Stopwatch(); 

            sort_name.Add("線性搜尋");
            sw.Start();
            ans.Add(LineSearch(test.ToArray(), target));
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("二分搜尋");
            sw.Start();
            ans.Add(BinarySearch(test.ToArray(), target));
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("插值搜尋");
            sw.Start();
            ans.Add(InterpolationSearch(test.ToArray(), target));
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            for (int i = 0; i < sort_name.Count; i++)
            {
                Console.WriteLine(sort_name[i] + "法搜尋時間:" + times[i].ToString());
            }
            Console.ReadKey();
        }

        // 線性搜尋
        static int LineSearch(int[] test, int target)
        {
            for (int i = 0; i < test.Length; i++)
            {
                if (test[i] == target)
                    return i;
            }
            return -1;
        }

        // 二分搜尋
        // test需要事先排序
        static int BinarySearch(int[] test, int target)
        {
            test = test.OrderBy(x => x).ToArray();
            int start = 0;
            int end = test.Length - 1;
            int mid;
            while (start <= end)
            {
                mid = (start + end) / 2;
                if (test[mid] < target)
                    start = mid + 1;
                else if (test[mid] > target)
                    end = mid - 1;
                else
                    return mid;
            }
            return -1;
        }

        // 插值搜尋
        // test需要事先排序
        static int InterpolationSearch(int[] test, int target)
        {
            test = test.OrderBy(x => x).ToArray();
            int left = 0;
            int right = test.Length - 1;
            int m = 0;
            while (left <= right)
            {
                m = (int)Math.Floor((double)(right - left) * (double)(target - test[left]) / (double)(test[right] - test[left])) + left;
                if (m < left || m > right)
                    break;
                if (target < test[m])
                    right = m - 1;
                else if (target > test[m])
                    left = m + 1;
                else
                    return m;
            }
            return -1;
        }
    }
}
