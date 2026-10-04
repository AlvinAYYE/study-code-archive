using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 凸形直綫環繞系統
{
    public partial class Form1 : Form
    {
        private List<Rectangle> rectangles = new List<Rectangle>();

        public Form1()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var graphic = pictureBox1.CreateGraphics();
            var pen = new Pen(Color.Black, 2);
            pen.DashPattern = new float[] { 7,2 };
            graphic.Clear(SystemColors.Control);
            var random = new Random(Guid.NewGuid().GetHashCode());
            var count = random.Next(3, 5);
            rectangles.Clear();
            for (int i = 0; i < count; i++)
            {
                var x = random.Next(20,81);
                var y = random.Next(20, 81);
                var height = random.Next(40,201);
                var width = random.Next(40, 201);

                var rectangle = new Rectangle(x,y, width, height);
                rectangles.Add(rectangle);
                graphic.DrawRectangle(pen, rectangle);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var bitmap = new Bitmap(pictureBox2.Width, pictureBox2.Height);
            var graphic = Graphics.FromImage(bitmap);
            var pen = new Pen(Color.Black, 2);
            pen.DashPattern = new float[] { 7, 2 };
            rectangles.ForEach(rectangle =>
            {
                graphic.DrawRectangle(pen, rectangle);
            });

            graphic.Save();
            var redPen = new Pen(Color.Red, 4);
            var maxX = rectangles.Max(x => x.X);
            var maxY = rectangles.Max(x => x.Y);
            var minX = rectangles.Min(x => x.Y);
            graphic.DrawLine(redPen, maxX, maxY, minX, maxY);

            graphic.Save();
            pictureBox2.Image = bitmap;
        }
    }
}
