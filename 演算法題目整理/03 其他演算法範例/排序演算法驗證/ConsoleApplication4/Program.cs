using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.IO;
using System.Net;
using System.Net.Mail;
using Microsoft.JScript;
using Microsoft.JScript.Vsa;
using System.Text.RegularExpressions;
using System.Diagnostics;

namespace ConsoleApplication4
{
    class Program
    {
        /*
         * 排序演算法時間驗證 
         * 1000次平均時間比較(由小到大)： 
         *      計數排序(0.13ms) -> 快速排序(1.30ms) -> 希爾排序(1.92ms) -> 
         *      梳排序(1.99ms) -> 堆積排序(3.09ms) -> 合併排序(10.81ms) -> 
         *      插入排序(86.60ms) -> 選擇排序(113.41ms) -> 侏儒排序(196.00ms) -> 
         *      雞尾酒排序(215.03ms) ~= 奇偶排序(221.24ms) -> 泡沫排序(286.78ms) -> 
         *      臭皮匠排序(620000ms)
         * 注意事項
         * 1. 臭皮匠排序十分花時間，大約有62億個Tick，大約十分鐘多，因此我未做千次平均
         * 2. 底下有兩種陣列，可選擇一種來驗證，或是想寫自己的演算法也可。
         * 3. 演算法正確驗證可用 CheckCorrect() 函式。
         * 4. 雞尾酒排序與奇偶排序為相近速度，我測了三次1000次的，一次雞尾酒，二次奇偶，所以定義為相近速度。
         */
        static void Main(string[] args)
        {
            Random ra = new Random(Guid.NewGuid().GetHashCode());

            // 隨機排序之陣列
            int[] test = Enumerable.Range(1, 10000).OrderBy(x => ra.Next(0, 10000)).ToArray();

            // 反轉排序之陣列
            //int[] test = Enumerable.Range(1, 10000).Reverse().ToArray();

            List<string> sort_name = new List<string>();
            List<long> times = new List<long>();
            Stopwatch sw = new Stopwatch();

            sort_name.Add("泡沫");
            sw.Start();
            BubbleSort(test.ToArray());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("侏儒");
            sw.Start();
            StupidSort(test.ToArray());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("雞尾酒");
            sw.Start();
            CocktailSort(test.ToArray());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("奇偶");
            sw.Start();
            OddEvenSort(test.ToArray());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("梳");
            sw.Start();
            CombSort(test.ToArray());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("快速");
            sw.Start();
            QuickSort(test.ToArray(), 0, test.Length - 1);
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            //sort_name.Add("臭皮匠");
            //sw.Start();
            //StoogeSort(test.ToArray(), 0, test.Length - 1);
            //sw.Stop();
            //times.Add(sw.ElapsedTicks);
            //sw.Reset();

            sort_name.Add("選擇");
            sw.Start();
            SelectionSort(test.ToArray());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("插入");
            sw.Start();
            InsertSort(test.ToArray());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("希爾");
            sw.Start();
            ShellSort(test.ToArray());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("合併");
            sw.Start();
            CombineSort(test.ToList());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("計數");
            sw.Start();
            CountSort(test.ToArray());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            sort_name.Add("堆積");
            sw.Start();
            HeapSort(test.ToArray());
            sw.Stop();
            times.Add(sw.ElapsedTicks);
            sw.Reset();

            for (int i = 0; i < sort_name.Count; i++)
            {
                Console.WriteLine(sort_name[i] + "排序法排序時間:" + times[i].ToString());
            }

            int test_times = 1000;
            // 測試平均

            // 泡沫平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                BubbleSort(test.ToArray());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 奇偶平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                OddEvenSort(test.ToArray());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 雞尾酒平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                CocktailSort(test.ToArray());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 侏儒平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                StupidSort(test.ToArray());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 選擇平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                SelectionSort(test.ToArray());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 插入平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                InsertSort(test.ToArray());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 合併平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                CombineSort(test.ToList());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 梳平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                CombSort(test.ToArray());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 希爾平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                ShellSort(test.ToArray());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 快速平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                QuickSort(test.ToArray(), 0, test.Length - 1);
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 計數平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                CountSort(test.ToArray());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            // 堆積平均
            times = new List<long>();
            for (int i = 0; i < test_times; i++)
            {
                sw.Start();
                HeapSort(test.ToArray());
                sw.Stop();
                times.Add(sw.ElapsedTicks);
                sw.Reset();
            }
            Console.WriteLine(times.Average());

            Console.ReadKey();
        }

        // 測試正確
        static public bool CheckCorrect(int[] test)
        {
            for (int i = 0; i < test.Length; i++)
            {
                if (test[i] != i + 1)
                    return false;
            }
            return true;
        }

        // 泡沫排序
        static public int[] BubbleSort(int[] test)
        {
            for (int i = 0; i < test.Length; i++)
            {
                for (int j = i + 1; j < test.Length; j++)
                {
                    if (test[i] > test[j])
                    {
                        int temp = test[i];
                        test[i] = test[j];
                        test[j] = temp;
                    }
                }
            }
            return test;
        }

        // 侏儒排序
        static public int[] StupidSort(int[] test)
        {
            int pos = 0;
            while (pos < test.Length)
            {
                if (pos == 0 || test[pos] >= test[pos - 1])
                    pos++;
                else
                {
                    int temp = test[pos];
                    test[pos] = test[pos - 1];
                    test[pos - 1] = temp;
                    pos--;
                }
            }
            return test;
        }

        // 雞尾酒排序
        static public int[] CocktailSort(int[] test)
        {
            int list_length = test.Length;
            int bottom = 0;
            int top = list_length - 1;
            bool swapped = true;
            while (swapped)
            {
                swapped = false;
                for (int i = bottom; i < top; i++)
                {
                    if (test[i] > test[i + 1])
                    {
                        int temp = test[i];
                        test[i] = test[i + 1];
                        test[i + 1] = temp;
                        swapped = true;
                    }
                }
                top -= 1;
                for (int i = top; i > bottom; i--)
                {
                    if (test[i] < test[i - 1])
                    {
                        int temp = test[i];
                        test[i] = test[i - 1];
                        test[i - 1] = temp;
                        swapped = true;
                    }
                }
                bottom += 1;
            }
            return test;
        }

        // 奇偶排序
        static public int[] OddEvenSort(int[] test)
        {
            bool sorted = false;
            while (!sorted)
            {
                sorted = true;
                for (int i = 0; i < 2; i++)
                {
                    for (int j = i; j < test.Length - 1; j += 2)
                    {
                        if (test[j] > test[j + 1])
                        {
                            int temp = test[j];
                            test[j] = test[j + 1];
                            test[j + 1] = temp;
                            sorted = false;
                        }
                    }
                }
            }
            return test;
        }

        // 梳排序
        static public int[] CombSort(int[] test)
        {
            int gap = test.Length;
            bool swapped = true;
            while (gap > 1 || swapped)
            {
                if (gap > 1)
                    gap = (int)(gap * 0.8);
                swapped = false;
                int i = 0;
                while (i + gap < test.Length)
                {
                    if (test[i].CompareTo(test[i + gap]) > 0)
                    {
                        int temp = test[i];
                        test[i] = test[i + gap];
                        test[i + gap] = temp;
                        swapped = true;
                    }
                    i++;
                }
            }
            return test;
        }

        // 快速排序
        static public void QuickSort(int[] test, int head, int tail)
        {
            if (head >= tail || test == null || test.Length <= 1)
                return;
            int i = head, j = tail, pivot = test[(head + tail) / 2];
            while (i <= j)
            {
                while (test[i] < pivot)
                    ++i;
                while (test[j] > pivot)
                    --j;
                if (i < j)
                {
                    int temp = test[i];
                    test[i] = test[j];
                    test[j] = temp;
                    ++i;
                    --j;
                }
                else if (i == j)
                    ++i;
            }
            QuickSort(test, head, j);
            QuickSort(test, i, tail);
        }

        // 臭皮匠排序
        static public int[] StoogeSort(int[] test, int i, int j)
        {
            if (test[j] < test[i])
            {
                int temp = test[j];
                test[j] = test[i];
                test[i] = temp;
            }
            if (j - i + 1 >= 3)
            {
                int t = (j - i + 1) / 3;
                StoogeSort(test, i, j - t);
                StoogeSort(test, i + t, j);
                StoogeSort(test, i, j - t);
            }
            return test;
        }

        // 選擇排序
        static public int[] SelectionSort(int[] test)
        {
            int len = test.Length;
            for (int i = 0; i < len - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < len; j++)
                {
                    if (test[j] < test[min])
                        min = j;
                }
                int temp = test[min];
                test[min] = test[i];
                test[i] = temp;
            }
            return test;
        }

        // 插入排序
        static public void InsertSort(int[] test)
        {
            for (int i = 1; i < test.Length; i++)
            {
                int temp = test[i];
                for (int j = i - 1; j >= 0; j--)
                {
                    if (test[j] > temp)
                    {
                        test[j + 1] = test[j];
                        test[j] = temp;
                    }
                    else
                        break;
                }
            }
        }

        // 希爾排序
        static public void ShellSort(int[] test)
        {
            int length = test.Length;
            int temp;
            for (int step = length / 2; step >= 1; step /= 2)
            {
                for (int i = step; i < length; i++)
                {
                    temp = test[i];
                    int j = i - step;
                    while (j >= 0 && test[j] > temp)
                    {
                        test[j + step] = test[j];
                        j -= step;
                    }
                    test[j + step] = temp;
                }
            }
        }

        // 合併排序
        static public List<int> CombineSort(List<int> lst)
        {
            if (lst.Count <= 1)
                return lst;
            int mid = lst.Count / 2;
            List<int> left = new List<int>();
            List<int> right = new List<int>();
            for (int i = 0; i < mid; i++)
            {
                left.Add(lst[i]);
            }
            for (int j = mid; j < lst.Count; j++)
                right.Add(lst[j]);
            left = CombineSort(left);
            right = CombineSort(right);
            return CombineSort_Merge(left, right);
        }
        static List<int> CombineSort_Merge(List<int> left, List<int> right)
        {
            List<int> temp = new List<int>();
            while (left.Count > 0 && right.Count > 0)
            {
                if(left[0] <= right[0])
                {
                    temp.Add(left[0]);
                    left.RemoveAt(0);
                }
                else
                {
                    temp.Add(right[0]);
                    right.RemoveAt(0);
                }
            }
            if(left.Count > 0)
                for (int i = 0; i < left.Count; i++)
                {
                    temp.Add(left[i]);
                }
            if(right.Count > 0)
                for (int i = 0; i < right.Count; i++)
                {
                    temp.Add(right[i]);
                }
            return temp;
        }

        // 計數排序
        static public int[] CountSort(int[] test)
        {
            int[] b = new int[test.Length];
            int max = test[0], min = test[0];
            foreach (var item in test)
            {
                if (item > max)
                    max = item;
                if (item < min)
                    min = item;
            }
            int k = max - min + 1;
            int[] c = new int[k];
            for (int i = 0; i < test.Length; i++)
            {
                c[test[i] - min] += 1;
            }
            for (int i = 1; i < c.Length; i++)
            {
                c[i] = c[i] + c[i - 1];
            }
            for (int i = test.Length - 1; i >= 0; i--)
            {
                b[--c[test[i] - min]] = test[i];
            }
            return b;
        }

        // 堆積排序
        static public int[] HeapSort(int[] test)
        {
            int len = test.Length - 1;
            int beginIndex = (test.Length >> 1) - 1;
            for (int i = beginIndex; i >= 0; i--)
            {
                maxHeapify(i, len, test);
            }
            for (int i = len; i > 0; i--)
            {
                int temp = test[0];
                test[0] = test[i];
                test[i] = temp;
                maxHeapify(0, i - 1, test);
            }
            return test;
        }
        static void maxHeapify(int index, int len, int[] test)
        {
            int li = (index << 1) + 1;
            int ri = li + 1;
            int cMax = li;
            if (li > len) return;
            if (ri <= len && test[ri] > test[li])
                cMax = ri;
            if(test[cMax] > test[index])
            {
                int temp = test[cMax];
                test[cMax] = test[index];
                test[index] = temp;
                maxHeapify(cMax, len, test);
            }
        }
    }
}
