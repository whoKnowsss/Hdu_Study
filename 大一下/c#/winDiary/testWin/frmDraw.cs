using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace testWin
{
    public partial class frmDraw : Form
    {
        Point p = new Point(50, 50);
        Point pos;
        const int L = 30;
        bool isDown = false;
        public frmDraw()
        {
            InitializeComponent();
        }

        private void frmDraw_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.DrawRectangle(new Pen(Color.Red), p.X, p.Y, L, L);
            g.FillRectangle(new SolidBrush(Color.Green), p.X+1, p.Y+1, L-1, L-1);
        }

        private void frmDraw_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.X > p.X && e.X < p.X + L && e.Y > p.Y && e.Y < p.Y + L)
            {
                isDown = true;
                pos.X = e.X;
                pos.Y = e.Y;
            }
        }

        private void frmDraw_MouseUp(object sender, MouseEventArgs e)
        {
            isDown = false;
        }

        private void frmDraw_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDown)
            {
                Graphics g = this.CreateGraphics();
                g.FillRectangle(new SolidBrush(this.BackColor), p.X, p.Y, L+1, L+1);
                p.X = p.X+e.X-pos.X;
                p.Y = p.Y + e.Y - pos.Y;
                g.DrawRectangle(new Pen(Color.Red), p.X, p.Y, L, L);
                g.FillRectangle(new SolidBrush(Color.Green), p.X+ 1, p.Y+1, L-1, L-1);
                pos.X = e.X;
                pos.Y = e.Y;
            }
        }
    }
}
