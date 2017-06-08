using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace testGraphics
{
    public partial class Form1 : Form
    {
        Point po = new Point(100, 100);
        int Length = 50;
        Point curPos;
        bool isMouseDown = false;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen p =new Pen(Color.Red);
            Brush b = new SolidBrush (Color.Green);
         
            e.Graphics.DrawRectangle(p, po.X, po.Y, Length, Length);
            e.Graphics.FillRectangle(b, po.X+1, po.Y+1, Length-1, Length-1);
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if(e.Button==System.Windows.Forms.MouseButtons.Left)
                if (e.X > po.X && e.X < po.X + Length && e.Y > po.Y && e.Y < po.Y + Length)
                {
                    isMouseDown = true;
                    curPos.X = e.X;
                    curPos.Y = e.Y;
                }
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (isMouseDown)
            {
                Graphics g = this.CreateGraphics();
                g.Clear(this.BackColor);
                po.X += e.X - curPos.X;
                po.Y += e.Y - curPos.Y;
                curPos.X = e.X;
                curPos.Y = e.Y;
                Pen p = new Pen(Color.Red);
                Brush b = new SolidBrush(Color.Green);
                g.DrawRectangle(p, po.X, po.Y, Length, Length);
                g.FillRectangle(b, po.X + 1, po.Y + 1, Length - 1, Length - 1);
            }
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            isMouseDown = false;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics g = button1.CreateGraphics();
            g.DrawLine(new Pen(Color.Red), 0, 0, button1.Width, button1.Height);
        }
    }
}
