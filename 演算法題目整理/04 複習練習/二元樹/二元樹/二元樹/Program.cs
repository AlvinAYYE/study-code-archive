using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 二元樹
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("Input: ");
                var tree = new Tree();
                Console.ReadLine().Split(' ').Select(x => x.toInt()).ToList().ForEach(x=> tree.insert(x));

                Console.WriteLine("1) 前序");
                Console.WriteLine("2) 中序");
                Console.WriteLine("3) 後序");
                var mode = Console.ReadLine().toInt();

                Console.WriteLine("Output: ");
                if(mode == 1)
                {
                    tree.getPerviousPath(tree.root);
                    Console.WriteLine(tree.perviousPath);
                } else if(mode == 2)
                {
                    tree.getMiddlePath(tree.root);
                    Console.WriteLine(tree.middlePath);
                } else if(mode == 3)
                {
                    tree.getAfterPath(tree.root);
                    Console.WriteLine(tree.afterPath);
                }

                Console.WriteLine();
            }
        }
    }

    class Node
    {
        public Node left;
        public Node right;
        public int value;
    }

    class Tree
    {
        public Node root;
        public string perviousPath = "";
        public string middlePath = "";
        public string afterPath = "";

        public void insert(int value)
        {
            var node = new Node();
            node.value = value;
            if(root == null)
            {
                root = node;
                return;
            }

            var currentNode = root;
            Node parent;
            while(true)
            {
                parent = currentNode;
                if(value < currentNode.value)
                {
                    currentNode = parent.left;
                    if(currentNode == null)
                    {
                        parent.left = node;
                        return;
                    }
                } else
                {
                    currentNode = parent.right;
                    if (currentNode == null)
                    {
                        parent.right = node;
                        return;
                    }
                }
            }
        }

        public void getPerviousPath(Node root)
        {
            if(root != null)
            {
                perviousPath += root.value + " ";
                getPerviousPath(root.left);
                getPerviousPath(root.right);
            }
        }

        public void getMiddlePath(Node root)
        {
            if (root != null)
            {
                getMiddlePath(root.left);
                middlePath += root.value + " ";
                getMiddlePath(root.right);
            }
        }

        public void getAfterPath(Node root)
        {
            if (root != null)
            {
                getAfterPath(root.left);
                getAfterPath(root.right);
                afterPath += root.value + " ";
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
