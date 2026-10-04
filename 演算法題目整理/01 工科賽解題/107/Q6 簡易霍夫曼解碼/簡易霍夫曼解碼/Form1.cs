using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 簡易霍夫曼解碼
{
    public partial class Form1 : Form
    {
        private Dictionary<string, string> dictionary = new Dictionary<string, string>();

        public Form1()
        {
            InitializeComponent();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var randomF1 = new List<string>();
            var random = new Random(Guid.NewGuid().GetHashCode());
            var alphaList = new List<string> { "A","B","C","D","E"};
            while(string.Join("",randomF1).Length > 50 || string.Join("", randomF1).Length < 26)
            {
                var key = alphaList[random.Next(0, 5)];
                var value = dictionary[key];
                randomF1.Add(value);
            }

            randomF1.Reverse();
            txtF1.Text = string.Join("", randomF1);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dictionary.Add("A","10");
            dictionary.Add("B", "01");
            dictionary.Add("C", "11");
            dictionary.Add("D", "001");
            dictionary.Add("E", "000");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var random = new Random(Guid.NewGuid().GetHashCode());
            var randomF2 = "";
            while (randomF2.Length < random.Next(26,51))
            {
                randomF2 += (random.Next(0,2)).ToString();
            }
            txtF2.Text = randomF2;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            txtCheck1.Text = "";
            txtCheck2.Text = "";
            txtDecode1.Text = "";
            txtDecode2.Text = "";

            var result = new List<string>();
            var result1 = new List<string>();
            var f1 = txtF1.Text;
            var f2 = txtF2.Text;

            while (f1.Length >= 0)
            {
                if (f1.Count() < 2)
                {
                    txtCheck1.Text = "不合理";
                    break;
                }

                var sub = f1.Substring(0, 2);
                if (dictionary.ContainsValue(sub))
                {
                    result.Add(dictionary.First(x => x.Value == sub).Key);
                    f1 = f1.Remove(0, sub.Length);
                    continue;
                }

                if(f1.Length > 2)
                {
                    var subLong = f1.Substring(0, 3);
                    if (dictionary.ContainsValue(subLong))
                    {
                        result.Add(dictionary.First(x => x.Value == subLong).Key);
                        f1 = f1.Remove(0, subLong.Length);
                        continue;
                    }
                }

                txtCheck1.Text = "不合理";
                break;
            }

            while (f2.Length > 0)
            {
                if (f2.Count() < 2)
                {
                    txtCheck2.Text = "不合理";
                    break;
                }

                var sub = f2.Substring(0, 2);
                if (dictionary.ContainsValue(sub))
                {
                    result1.Add(dictionary.First(x => x.Value == sub).Key);
                    f2 = f2.Remove(0, sub.Length);
                    continue;
                }

                var subLong = f2.Substring(0, 3);
                if (dictionary.ContainsValue(subLong))
                {
                    result1.Add(dictionary.First(x => x.Value == subLong).Key);
                    f2 = f2.Remove(0, subLong.Length);
                    continue;
                }

                txtCheck2.Text = "不合理";
                break;
            }

            if (txtCheck1.Text.Length == 0)
            {
                txtDecode1.Text = string.Join("", result);
            }

            if (txtCheck2.Text.Length == 0)
            {
                txtDecode2.Text = string.Join("", result1);
            }
        }
    }
}
