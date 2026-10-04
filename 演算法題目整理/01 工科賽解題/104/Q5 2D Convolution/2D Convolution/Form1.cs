using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2D_Convolution
{

    public partial class Form1 : Form
    {
        private TextBox[,] input, kernel, output;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 1; i <= 5; i++)
            {
                for (int j = 1; j <= 5; j++)
                {
                    output[i, j].Text = getResult(i,j).ToString();
                }
            }

            double mse = 0, mae = 0;
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    mse += Math.Pow(Convert.ToInt32(input[i, j].Text) - Convert.ToInt32(output[i, j].Text), 2);
                    mae += Math.Abs(Convert.ToInt32(input[i, j].Text) - Convert.ToInt32(output[i, j].Text));
                }
            }
            mse /= 49;
            mae /= 49;
            var psnr = 10 * Math.Log10(255 * 255 / mse);
            textBox1.Text = mse.ToString();
            textBox2.Text = mae.ToString();
            textBox3.Text = psnr.ToString();
        }

        private int getResult(int x, int y)
        {
            var result = 0;
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    var dx = Math.Abs(i - 1);
                    var dy = Math.Abs(j - 1);
                    result += Convert.ToInt32(kernel[dx, dy].Text) * Convert.ToInt32(input[x + i, y + j].Text);
                }
            }


            return result;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            initView();
        }

        private void initView()
        {
            input = new TextBox[7,7];
            kernel = new TextBox[3, 3];
            output = new TextBox[7, 7];

            // input layout
            var center = 3;
            var temp = 0;
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    var isCenter = Math.Abs(center - j) < 2 && Math.Abs(center - i) < 2;
                    var text = isCenter ? ++temp : 0;
                    var backgroundColor = isCenter ? Color.LightPink : Color.White;
                    var foregroundColor = isCenter ? Color.Red : Color.Black;

                    TextBox txt = new TextBox()
                    {
                        Width = flowLayoutPanelInput.Width / 8,
                        Height = flowLayoutPanelInput.Height / 8,
                        TextAlign = HorizontalAlignment.Center,
                        Multiline = true,
                        ForeColor = foregroundColor,
                        BackColor = backgroundColor,
                        Margin = new Padding(2),
                        Text = text.ToString()
                    };

                    input[i, j] = txt;
                    flowLayoutPanelInput.Controls.Add(txt);
                }
            }

            // ouput layout
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    var isCenter = Math.Abs(center - j) < 2 && Math.Abs(center - i) < 2;
                    var backgroundColor = isCenter ? Color.LightPink : Color.White;
                    var foregroundColor = isCenter ? Color.Red : Color.Black;

                    TextBox txt = new TextBox()
                    {
                        Width = flowLayoutPanelOutput.Width / 8,
                        Height = flowLayoutPanelOutput.Height / 8,
                        TextAlign = HorizontalAlignment.Center,
                        Multiline = true,
                        ForeColor = foregroundColor,
                        BackColor = backgroundColor,
                        Margin = new Padding(2),
                        Text = "0"
                    };

                    output[i, j] = txt;
                    flowLayoutPanelOutput.Controls.Add(txt);
                }
            }

            // kernel layout
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    var isCenter = j == 1 && 1 == i;
                    var backgroundColor = isCenter ? Color.LightPink : Color.White;
                    var foregroundColor = isCenter ? Color.Red : Color.Black;
                    var text = ((i - 1) * (1 == j ? 2 : 1));

                    TextBox txt = new TextBox()
                    {
                        Width = flowLayoutPanelKernel.Width / 4,
                        Height = flowLayoutPanelKernel.Height / 4,
                        TextAlign = HorizontalAlignment.Center,
                        Multiline = true,
                        ForeColor = foregroundColor,
                        BackColor = backgroundColor,
                        Margin = new Padding(2),
                        Text = text.ToString()
                    };

                    kernel[i, j] = txt;
                    flowLayoutPanelKernel.Controls.Add(txt);
                }
            }
        }
    }
}
