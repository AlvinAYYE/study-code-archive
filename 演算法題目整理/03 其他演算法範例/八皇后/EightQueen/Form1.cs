using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace EightQueen
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        class Queen
        {
            public int x = 0;
            public int y = 0;
            public Queen(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
        }
        List<List<Queen>> maybe = new List<List<Queen>>();
        private void Form1_Load(object sender, EventArgs e)
        {
            LoadMap();
            for (int i = 1; i <= 8; i++)
            {
                PutQueen(new Queen(i, 1), new List<Queen>());
            }
            for (int i = 0; i < maybe[13].Count; i++)
            {
                panel1.Controls.Find("tb" + maybe[0][i].y + maybe[0][i].x, false).First().Text = "Q";
            }
        }
        void LoadMap()
        {
            for (int i = 1; i <= 8; i++)
            {
                for (int j = 1; j <= 8; j++)
                {
                    TextBox tb = new TextBox();
                    tb.Multiline = true;
                    tb.Size = new Size(50,50);
                    tb.Location = new Point(50 * j, 50 * i);
                    tb.Name = "tb" + i.ToString() + j.ToString();
                    panel1.Controls.Add(tb);
                }
            }
        }
        private void PutQueen(Queen queen, List<Queen> NowQueen)
        {
            if (NowQueen.Where(x => x.x == queen.x || x.y == queen.y || Math.Abs(queen.x - x.x) == Math.Abs(queen.y - x.y)).Count() == 0)
            {
                var now2 = new List<Queen>(NowQueen);
                now2.Add(queen);
                if (now2.Count == 8)
                    maybe.Add(now2);
                else if(queen.y <= 8)
                    for (int i = 1; i <= 8; i++)
                        PutQueen(new Queen(i, queen.y + 1), now2);
            }
        }
    }
}
