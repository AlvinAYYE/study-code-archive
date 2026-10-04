using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 計算次方及餘數
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var a = txtA.Text;
            var b = txtB.Text;
            var c = txtC.Text;

            if(string.IsNullOrEmpty(a) || string.IsNullOrEmpty(b) || string.IsNullOrEmpty(c))
            {
                MessageBox.Show("A or B or C content can't empty.", this.Text);
                return; 
            }
            BigInteger result = BigInteger.Pow(BigInteger.Parse(a), b.toInt()) % BigInteger.Parse(c);
            txtResult.Text = result.ToString();
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
