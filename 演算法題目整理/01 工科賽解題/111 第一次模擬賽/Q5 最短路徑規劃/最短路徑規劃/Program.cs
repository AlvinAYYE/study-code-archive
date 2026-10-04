using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 最短路徑規劃
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("請輸入節點檔案名稱: ");
            var fileName = Console.ReadLine();
            var stream = new StreamReader(fileName);
            var data = stream.ReadToEnd();
            Console.WriteLine("你輸入的文字檔内容為: ");
            Console.WriteLine(data);

            // solve data
            var dataList = data.Split('\n').ToList();
            var nodeCount = dataList.First().toInt();

            for (int i = 1; i < dataList.Count; i++)
            {
                var numList = dataList[i].Split(' ').Select(x => x.toInt()).ToList();
                routeList.Add(new Route
                {
                    start = numList[0],
                    end = numList[1],
                    value = numList[2]
                });
            }

            Console.Write("請輸入起始節點: ");
            var start = Console.ReadLine().toInt();

            Console.Write("請輸入終點節點: ");
            end = Console.ReadLine().toInt();

            Console.WriteLine($"從節點{start}至節點{end}的最短路徑為: ");

            for (int i = 0; i < 20; i++)
            {
                Console.Write("-");
            }
            Console.Write("\n");

            // cal result
            getRoute(routeList.Where(x => x.start == start).ToList(), new List<Route>());

            var sortRoute = allRoute.OrderBy(z => z.Sum(x=>x.value)).First();
            var sortValue = sortRoute.Sum(x => x.value);
            var routeString = "";
            sortRoute.ForEach(x =>
            {
                routeString += $"V{x.start} --{x.value}-->";
            });
            routeString += $"V{sortRoute.Last().end}";
            Console.WriteLine(routeString);
            Console.WriteLine($"路徑長度： {sortValue}");
            Console.ReadKey();
        }

        public static List<Route> routeList = new List<Route>();
        public static List<List<Route>> allRoute = new List<List<Route>>();
        public static int end;

        public static void getRoute(List<Route> current, List<Route> before)
        {
            current.ForEach(x =>
            {
                var list = before.ToList();
                list.Add(x);
                if (x.end == end)
                {
                    allRoute.Add(list);
                } else
                {
                    var newList = routeList.Where(z => z.start == x.end && !before.Contains(z)).ToList();
                    getRoute(newList, list);
                }
            });
        }
    }

    class Route
    {
        public int start;
        public int end;
        public int value;
    }


    static class Extension
    {
        public static int toInt(this string str)
        {
            return Convert.ToInt32(str);
        }
    }
}
