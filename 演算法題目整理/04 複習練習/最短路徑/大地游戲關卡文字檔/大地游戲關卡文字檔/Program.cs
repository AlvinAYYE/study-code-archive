using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 大地游戲關卡文字檔
{
    class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                Console.Write("Input file name: ");
                var fileName = Console.ReadLine();
                Console.WriteLine($"Your file name is {fileName}");
                var streamReader = new StreamReader(fileName);
                Console.WriteLine("File text content is: ");
                var dataText = streamReader.ReadToEnd();
                Console.WriteLine(dataText);

                // process data
                var dataList = dataText.Split('\n').ToList();
                var count = dataList.First().toInt();
                for (int i = 1; i <= count; i++)
                {
                    var dataLine = dataList[i].Split(' ').ToList();
                    for (int j = 1; j <= dataLine.Count; j++)
                    {
                        var value = dataLine[j - 1].toDouble();
                        if(value != 0)
                        {
                            allRoute.Add(new Route
                            {
                                start = i,
                                end = j,
                                value = value
                            });
                        }
                    }
                }
                var start = dataList.Last().Split(' ').ToList().First().toInt();
                end = dataList.Last().Split(' ').ToList().Last().toInt();

                getRoute(allRoute.Where(x=>x.start == start).ToList(), new List<Route>());

                var minRoute = resultRoute.OrderBy(x => x.Sum(z => z.value)).First();
                var routeList = new List<int>();

                minRoute.ForEach(x =>
                {
                    routeList.Add(x.start);
                    routeList.Distinct();
                });
                routeList.Add(minRoute.Last().end);

                var routeString = string.Join("->", routeList);
                var values = minRoute.Sum(x => x.value);
                Console.WriteLine($"The fast route is: [{start} -> {end}]: {routeString} (route value: {values})");
            }
        }

        public static int end = 0;
        public static List<Route> allRoute = new List<Route>();
        public static List<List<Route>> resultRoute = new List<List<Route>>();

        public static void getRoute(List<Route> currentRoute, List<Route> beforeRoute)
        {
            currentRoute.ForEach(x =>
            {
                var list = beforeRoute.ToList();
                list.Add(x);
                if(x.end == end)
                {
                    resultRoute.Add(list);
                } else
                {
                    var newList = allRoute.Where(z => z.start == x.end && !beforeRoute.Contains(z)).ToList();
                    getRoute(newList, list);
                }
            });
        }
    }

    class Route
    {
        public int start;
        public int end;
        public double value;
    }

    static class Extension
    {
        public static int toInt(this string str)
        {
            return Convert.ToInt32(str);
        }

        public static double toDouble(this string str)
        {
            return Convert.ToDouble(str);
        }
    }
}
