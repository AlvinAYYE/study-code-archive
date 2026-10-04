using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 資料分群
{
    public partial class Form1 : Form
    {
        private List<Data> dataList = new List<Data>();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var n = txtN.Text;

            if (n.isEmpty())
            {
                MessageBox.Show("N's content can't empty.", this.Text);
                return;
            }

            if(!n.isNumber())
            {
                MessageBox.Show("Please input a correct number for N", this.Text);
                return;
            }

            dataList.Clear();
            txtTop.Text = "";
            txtMath.Text = "";
            txtGroup.Text = "";

            var random = new Random(Guid.NewGuid().GetHashCode());
            for (int i = 1; i <= n.toInt(); i++)
            {
                txtTop.Text += String.Format("{0,-4}",i.ToString());
                
                var math = random.Next(0, 101);
                var english = random.Next(0, 101);
                
                txtMath.Text += string.Format("{0,-4}", math);
                txtEnglish.Text += string.Format("{0,-4}", english);

                dataList.Add(new Data
                {
                    math = math,
                    english = english
                });
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var q = txtQ.Text;

            if (q.isEmpty())
            {
                MessageBox.Show("Q's content can't empty.", this.Text);
                return;
            }

            if (!q.isNumber())
            {
                MessageBox.Show("Please input a correct number for Q", this.Text);
                return;
            }

            var random = new Random(Guid.NewGuid().GetHashCode());
            var index1 = random.Next(0, dataList.Count);
            var index2 = random.Next(0, dataList.Count);
            while(index1 == index2)
            {
                index2 = random.Next(0, dataList.Count);
            }




        }

        class Data
        {
            public int math;
            public int english;
            public int group;
        }
    }

    static class Extension
    {
        public static bool isEmpty(this string str)
        {
            return string.IsNullOrEmpty(str);
        }

        public static int toInt(this string str)
        {
            return Convert.ToInt32(str);
        }

        public static bool isNumber(this string str)
        {
            return int.TryParse(str, out _);
        }
    }
}
