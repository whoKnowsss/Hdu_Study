using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;

namespace RussianBlock
{
    public partial class Form1 : Form
    {
        Game game = new Game();
        int iPos = 0;
        ArrayList al = new ArrayList();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            game.Draw(e.Graphics,true);
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            Graphics g = this.CreateGraphics();
            if (e.KeyCode == Keys.Left)
                game.CurPointMove(1,g);
            if (e.KeyCode == Keys.Up)
                game.CurPointMove(2,g);
            if (e.KeyCode == Keys.Right)
                game.CurPointMove(3,g);
            if (e.KeyCode == Keys.Down)

                game.CurPointMove(4,g);
        }

        private void Form1_Click(object sender, EventArgs e)
        {
            al = game.FindPath();
            if(al.Count>0)
            timer1.Enabled = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (iPos < al.Count)
            {
                game.PointMove((Point)al[iPos], this.CreateGraphics());
                iPos++;
            }
            else
            {
                timer1.Enabled = false;
                game.ClearPath();
                iPos = 0;
            }
        }

        private void 开始ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            game = new Game();
            game.Draw(this.CreateGraphics(), true);
        }
    }
}
