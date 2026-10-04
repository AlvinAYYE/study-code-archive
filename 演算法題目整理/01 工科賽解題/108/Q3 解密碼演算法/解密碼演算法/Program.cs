using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 解密碼演算法
{
    class Program
    {
        static void Main(string[] args)
        {
            // 068afa4e 07871c0c 005af200 00160ecc 000553e6
            while (true)
            {
                Console.WriteLine("Input: ");
                var inputArray = Console.ReadLine().Split(' ').Select(x=>Convert.ToInt32(x, 16)).ToList();
                var h0 = 0xabcd;
                var h1 = 0xcdef;
                var h2 = 0x2266;
                var h3 = 0xceed;
                var h4 = 0xaccd;
                var hArr = new int[] { h0, h1, h2, h3, h4 };

                foreach(int i in inputArray)
                {
                    Console.Write(i + " ");
                }
                inputArray = inputArray.Select((x, index) => {
                     return inputArray[index] - hArr[index];
                }).ToList();
                Console.WriteLine("");
                foreach (int i in inputArray)
                {
                    Console.Write(i + " ");
                }
                hArr.Reverse();

                var word = new int[5];
                for (int i = 0; i < 5; i++)
                {
                    var temp = inputArray[0]; // a = temp
                    inputArray[0] = inputArray[1]; // b = a
                    inputArray[1] = inputArray[2]; // c = b
                    inputArray[2] = inputArray[3]; // d = c
                    inputArray[3] = inputArray[4]; // e = d
                    inputArray[4] = hArr[i];

                    var f = inputArray[1] + inputArray[2];
                    var k = 0x5a82;
                    var result = temp - 4 * inputArray[0] - k - inputArray[4] - f;
                    word[i] = Convert.ToInt32((char)result + ' ');
                }
                word = word.Reverse().ToArray();
                Console.WriteLine("Output: ");
                var resultStr = string.Join("", word.ToList().Select(x => (char)x));
                Console.WriteLine(resultStr);

                Console.WriteLine();
            }
        }
    }
}
