using System;
using System.Collections.Generic;
using System.Linq;

namespace 最小路徑程式
{
    // [[7,8,9],[1,2,3],[4,5,6]]
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.Write("請輸入一個二維陣列： ");
                var strArray = Console.ReadLine();
                var dataList = strArrayToList(strArray);
                Console.WriteLine("數字地圖：");
                dataList.ForEach(x =>
                {
                    Console.WriteLine($"        [{string.Join(", ", x)}]");
                });

                var allRoads = getAllRoads2(dataList);
                Console.WriteLine("所有路徑：");
                allRoads.ForEach(x =>
                {
                    Console.WriteLine($"        [{string.Join(", ", x)}]");
                });

                var minRoad = allRoads.OrderBy(x => x.Sum()).First();
                Console.WriteLine($"最短路徑：  [{string.Join(", ", minRoad)}]");
                Console.WriteLine($"最小路徑和：  {minRoad.Sum()}");
                Console.WriteLine();
            }
        }

        private static List<List<int>> getAllRoads(List<List<int>> roads)
        {
            var result = new List<List<int>>();
            var xCount = roads.First().Count();
            var yCount = roads.Count();


            var yHeight = 0;
            var xWidth = 0;
            while (yHeight < yCount)
            {
                var temp = new List<int>();
                var y = 0;
                var x = 0;

                for (y = 0; y < yCount - yHeight; y++)
                {
                    temp.Add(roads[y][x]);
                }

                y -= 1;

                for (x = 1; x < xCount - xWidth; x++)
                {
                    temp.Add(roads[y][x]);
                }

                x -= 1;

                for (int i = y + 1; i < yCount; i++)
                {
                    temp.Add(roads[i][x]);
                }

                for (int i = x + 1; i < xCount; i++)
                {
                    temp.Add(roads[yCount - 1][i]);
                }

                result.Add(temp);

                if (xWidth == xCount || yHeight == 0)
                {
                    xWidth = 0;
                    yHeight++;
                    continue;
                }

                xWidth += 1;
            }

            return result;
        }

        private static List<List<int>> getAllRoads2(List<List<int>> roads)
        {
            var result = new List<List<int>>();
            var xCount = roads.First().Count();
            var yCount = roads.Count();

            for (int i = yCount - 1; i >= 0; i--)
            {
                var temp = new List<int>();
                for (int z = 0; z < i; z++)
                {
                    temp.Add(roads[z][0]);
                }

                for (int j = 0; j < xCount; j++)
                {
                    for (int k = 1; k < xCount - j; k++)
                    {
                        temp.Add(roads[i][k]);
                    }

                    for (int x = i; x < yCount; x++)
                    {
                        temp.Add(roads[x][j]);
                    }

                    for (int l = j; l < xCount; l++)
                    {
                        temp.Add(roads[yCount - 1][j]);
                    }

                    result.Add(temp);
                }
            }

            return result;
        }

        private static List<List<int>> strArrayToList(string strArray)
        {
            strArray = strArray.TrimStart('[').TrimEnd(']');
            var dataList = strArray.Split(']');
            var result = new List<List<int>>();
            for (int i = 0; i < dataList.Count(); i++)
            {
                var str = dataList[i];
                if (i != 0)
                {
                    str = str.Replace(",[", "");
                }

                result.Add(str.Split(',').Select(x => x.toInt()).ToList());
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
