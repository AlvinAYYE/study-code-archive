using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 印出二元搜尋樹兩節點路徑
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("1. 請輸入二元搜尋樹資料：");
                var count = Console.ReadLine().toInt();
                var tree = new Tree();
                Console.ReadLine().Split(',').Select(x=>x.toInt()).ToList().ForEach(x=> tree.insert(x));
                Console.WriteLine("2. 輸入欲走訪兩節點：");
                var twoPoint = Console.ReadLine().Split(',').Select(x => x.toInt()).ToList();
                Console.WriteLine("走訪路徑為：");
                
                Console.WriteLine(tree.getPath(twoPoint.First(), twoPoint.Last()));

                Console.WriteLine();
            }
        }

        class Node
        {
            public int value;
            public Node right;
            public Node left;
        }

        class Tree
        {
            public Node root;

            public void insert(int value)
            {
                var node = new Node();
                node.value = value;
                if (root == null)
                {
                    root = node;
                    return;
                }

                var current = root;
                Node parent;
                while(true)
                {
                    parent = current;
                    if(current.value > value)
                    {
                        current = parent.left;
                        if(current == null)
                        {
                            parent.left = node;
                            return;
                        }
                    } else
                    {
                        current = parent.right;
                        if (current == null)
                        {
                            parent.right = node;
                            return;
                        }
                    }
                }
            }

            public string getPath(int start, int end)
            {
                var temp = new List<int>();
                var current = root;
                while (!temp.Contains(start))
                {
                    temp.Add(current.value);
                    if(start < current.value)
                    {
                        current = current.left;
                    } else
                    {
                        current = current.right;
                    }
                }

                // 如果尋找的兩點都在相同子樹的話
                if(temp.Contains(start) && temp.Contains(end))
                {
                    var result = "";
                    if (temp.IndexOf(start) > temp.IndexOf(end))
                        temp.Reverse();

                    for (int i = temp.IndexOf(start); i <= temp.IndexOf(end); i++)
                    {
                        result += temp[i] + ",";
                    }

                    return result.TrimEnd(',');
                }

                temp.Reverse();
                var current2 = root;
                while(current2 != null)
                {
                    if(end < current2.value)
                    {
                        current2 = current2.left;
       
                    } else
                    {
                        current2 = current2.right;
                    }

                    if (current2 != null)
                    {
                        temp.Add(current2.value);

                        if (current2.value == end)
                            break;
                    }
                }

                if (temp.Contains(start) && temp.Contains(end))
                {
                    var result = "";
                    if (temp.IndexOf(start) > temp.IndexOf(end))
                        temp.Reverse();

                    for (int i = temp.IndexOf(start); i <= temp.IndexOf(end); i++)
                    {
                        result += temp[i] + ",";
                    }

                    result = result.TrimEnd(',');
                    var tempList = result.Split(',').ToList();
                    var saveList = result.Split(',').ToList();
                    tempList.ForEach(x =>
                    {
                        if(saveList.Count(z=>z.ToString() == x) > 1)
                        {
                            saveList.Remove(root.value.ToString());
                            saveList.Remove(x);
                        }
                    });
                    return string.Join(",", saveList);
                }


                return "";
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
