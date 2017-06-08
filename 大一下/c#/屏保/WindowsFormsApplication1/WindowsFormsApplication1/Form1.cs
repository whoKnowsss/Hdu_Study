using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class 屏保 : Form
    {
        public 屏保()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
            int x = 10;
            int y = 10;
        private void timer1_Tick(object sender, EventArgs e)
        {
           
            this.label1.Left += x;
            this.label1.Top += y;
            if (this.label1.Top < 0 || this.label1.Top + this.label1.Height > this.Height) y= -y;
            if (this.label1.Left < 0 || this.label1.Left + this.label1.Width > this.Width) x = -x;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            Application.Exit();
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            Application.Exit();
        }

        private void Form1_MouseMove(object sender, EventArgs e)
        {
            Application.Exit();
        }

       
    }
}
