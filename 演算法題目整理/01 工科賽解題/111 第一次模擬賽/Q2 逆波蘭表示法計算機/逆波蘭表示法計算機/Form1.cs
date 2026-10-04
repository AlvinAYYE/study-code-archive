using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 逆波蘭表示法計算機
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var input = txtInput.Text.Split(' ').ToList();
            var temp = new List<string>();
            var result = "";
            for (int i = 0; i < input.Count; i++)
            {
                var c = input[i].ToString();

                if (input.Count == 1)
                {
                    result = c;
                } else if (input.Count == 2)
                {
                    result = "表示式錯誤";
                    break;
                } 

                if(c == "*" || c == "/" || c == "+" || c == "-")
                {
                    var r = 0.0;
                    if(c == "*")
                    {
                        r = temp[temp.Count - 2].toDouble() * temp[temp.Count - 1].toDouble();
                    } else if(c == "/")
                    {
                        r = temp[temp.Count - 2].toDouble() / temp[temp.Count - 1].toDouble();
                    } else if(c == "+")
                    {
                        r = temp[temp.Count - 2].toDouble() + temp[temp.Count - 1].toDouble();
                    } else if(c == "-")
                    {
                        r = temp[temp.Count - 2].toDouble() - temp[temp.Count - 1].toDouble();
                    }

                    input.Insert(input.IndexOf(temp[temp.Count - 2]), r.ToString());
                    input.Remove(temp[temp.Count - 2]);
                    input.Remove(temp[temp.Count - 1]);
                    input.Remove(c);
                    
                    i = -1;
                    temp.Clear();
                } else
                {
                    temp.Add(c);
                }
            }

            txtOutput.Text = result.ToString();
        }
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
