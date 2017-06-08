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
    public partial class Form3 : Form
    {
        Bitmap bmp;
        bool isMouseDown = false;
        Point cp,ep;
        Form2 F2;
        Label lbl;
        public Form3()
        {
            InitializeComponent();
        }
        public Form3(Form2 f2)
        {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer | ControlStyles.AllPaintingInWmPaint | ControlStyles.UserPaint, true);
            F2 = f2;
            lbl = new Label();
            lbl.BorderStyle = BorderStyle.FixedSingle;
            lbl.Width = 60;
            lbl.Height = 20;
            lbl.Text = "截取屏幕";
            lbl.Click+=lblClick;
            this.Controls.Add(lbl);
            lbl.Hide();
        }
        private void lblClick(object sender, EventArgs e)
        {
            this.Close();
            F2.setPic(bmp, cp,ep);
            F2.Show();
            
        }
        private void Form3_Click(object sender, EventArgs e)
        {
            
        }

        private void Form3_Load(object sender, EventArgs e)
        {
           

        }

        private void Form3_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawImage(bmp, 0, 0);
            e.Graphics.DrawRectangle(new Pen(Color.Green), cp.X, cp.Y, ep.X - cp.X, ep.Y - cp.Y);
        }

        private void Form3_Activated(object sender, EventArgs e)
        {
            bmp = new Bitmap(Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height);
            Graphics g = Graphics.FromImage(bmp);
            g.CopyFromScreen(0, 0, 0, 0, new Size(bmp.Width, bmp.Height));
        }

        private void Form3_DoubleClick(object sender, EventArgs e)
        {
            
        }

        private void Form3_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == System.Windows.Forms.MouseButtons.Left)
            {
                lbl.Hide();
                isMouseDown = true;
                cp.X = e.X;
                cp.Y = e.Y;
            }
            
        }

        private void Form3_MouseUp(object sender, MouseEventArgs e)
        {
            if (isMouseDown)
            {
                isMouseDown = false;
                ep.X = e.X;
                ep.Y = e.Y;
                lbl.Left = e.X;
                lbl.Top = e.Y;
                lbl.Show();
            }
        }

        private void Form3_MouseMove(object sender, MouseEventArgs e)
        {
            if(isMouseDown)
            {
                Graphics g = this.CreateGraphics();
                this.Refresh();
                g.DrawRectangle(new Pen(Color.Green), cp.X, cp.Y, e.X-cp.X, e.Y-cp.Y);

            }
        }
    }
}
