using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 二元搜尋樹的前序表示
{
    class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                Console.WriteLine("Input:");
                var tree = new Tree();
                Console.ReadLine().Split(' ').Select(x => x.toInt()).ToList().ForEach(x => tree.insert(x));

                Console.WriteLine();

                Console.WriteLine("Output:");
                Console.WriteLine(tree.getResult(tree.root));
                Console.WriteLine();
            }
        }
    }

    class Node
    {
        public int item;
        public Node left;
        public Node right;
    }

    class Tree
    {
        public Node root;
        string path = "";

        public void insert(int value)
        {
            var node = new Node();
            node.item = value;
            if (root == null)
            {
                root = node;
                return;
            }

            var current = root;
            Node parent;

            while (true)
            {
                parent = current;
                if (current.item < value)
                {
                    current = current.right;
                    if(current == null)
                    {
                        parent.right = node;
                        return;
                    }
                } else
                {
                    current = current.left;
                    if (current == null)
                    {
                        parent.left = node;
                        return;
                    }
                }
            }
        }

        public string getResult(Node root)
        {
            if(root != null) {
                path += root.item + " ";
                getResult(root.left);
                getResult(root.right);
            }

            return path;
        }
    }

    static class Extension
    {
        public static int toInt(this string str)
        {
            return int.Parse(str);
        }
    }
}
