using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace testGraphics
{
    public partial class Form2 : Form
    {
        Bitmap bmp;
        Point cp,txtPoint;
        bool isMoouseDown = false;
        string style = "P",input="";
        TextBox tb;
        string saveFileName = @"d:\aa.jpg";
        public Form2()
        {
            InitializeComponent();
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer |
                    ControlStyles.ResizeRedraw |
                    ControlStyles.AllPaintingInWmPaint, true);
            tb = new TextBox();
            tb.BorderStyle = BorderStyle.FixedSingle;
            tb.Width = 100;
            tb.Height = 20;
            tb.KeyPress += tb_KeyPress;
            this.Controls.Add(tb);
            tb.Hide();
        }

        private void miOpen_Click(object sender, EventArgs e)
        {
            OpenFileDialog fd = new OpenFileDialog();
            
            if (fd.ShowDialog()==System.Windows.Forms.DialogResult.OK)
            {
              
                Image img = Image.FromFile(fd.FileName);
                bmp = new Bitmap(img.Width,img.Height);
                Graphics g = Graphics.FromImage(bmp);
                g.DrawImage(img, 0, 0);
                img.Dispose();
                saveFileName = fd.FileName;
                pictureBox1.BackColor = Color.Gray;
            }
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawImage(bmp,0,0);
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == System.Windows.Forms.MouseButtons.Left && e.X < bmp.Width && e.Y < bmp.Height)
            {
                cp.X = e.X;
                cp.Y = e.Y;
                isMoouseDown = true;
                if (style == "S")
                {
                    
                    tb.Left = e.X+panel1.Width;
                    tb.Top = e.Y+menuStrip1.Height;
                    txtPoint.X = e.X;
                    txtPoint.Y = e.Y;
                    tb.BringToFront();
                    tb.Show();
                    tb.Focus();
                    
                }
            }
        }
        private void tb_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == '\r')
            {
                input = tb.Text;
                tb.Hide();
                //pictureBox1.CreateGraphics().DrawString(input, new Font("宋体", 10), new SolidBrush(Color.Red), new PointF(txtPoint.X, txtPoint.Y));

                Graphics g = Graphics.FromImage(bmp);
                g.DrawString(input, new Font("宋体", 10), new SolidBrush(Color.Red), new PointF(txtPoint.X, txtPoint.Y));


                tb.Text = "";
                isMoouseDown = false;

            }
        }
        private void tb_KeyDown(object sender,KeyEventArgs e)
        {
            
        }
        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if (isMoouseDown)
            {
                isMoouseDown = false;
                Graphics gbmp = Graphics.FromImage(bmp);
                gbmp.DrawLine(new Pen(Color.Black), cp, new Point(e.X, e.Y));
                Graphics g = pictureBox1.CreateGraphics();
                g.DrawImage(bmp, 0, 0);
            }
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (isMoouseDown && e.X < bmp.Width && e.Y < bmp.Height)
            {
                Graphics g = pictureBox1.CreateGraphics();
                Graphics g2 = Graphics.FromImage(bmp);
                
                switch (style)
                {
                    case "P":
                        {
                            g.DrawLine(new Pen(Color.Black), cp, new Point(e.X, e.Y));
                            g2.DrawLine(new Pen(Color.Black), cp, new Point(e.X, e.Y));
                            cp.X = e.X;
                            cp.Y = e.Y;
                            break;
                        }
                    case "L":
                        {
                            g.DrawImage(bmp, 0, 0);
                            g.DrawLine(new Pen(Color.Black), cp, new Point(e.X, e.Y));
                            break;
                        }
                }
                
            }
        }

        private void Form2_Resize(object sender, EventArgs e)
        {
           
        }

        private void miSave_Click(object sender, EventArgs e)
        {
            
            bmp.Save(saveFileName, System.Drawing.Imaging.ImageFormat.Jpeg);
            
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics g = Graphics.FromImage(bmp);
            g.FillRectangle(new SolidBrush(Color.White), 0, 0, bmp.Width, bmp.Height);
        }

        private void miScreen_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form3 f3 = new Form3(this);
            f3.Show();
        }
        public void setPic(Bitmap bmp2, Point p1, Point p2)
        {
            bmp = new Bitmap(p2.X-p1.X,p2.Y-p1.Y);
            pictureBox1.BackColor = Color.Gray;
            Graphics g= Graphics.FromImage(bmp);
            g.DrawImage(bmp2, new Rectangle( 0,0, p2.X - p1.X, p2.Y - p1.Y),p1.X,p1.Y,p2.X-p1.X,p2.Y-p1.Y,GraphicsUnit.Pixel);
  
        }
        private void style_Click(object sender, EventArgs e)
        {
            style = (sender as RadioButton).Text;
            tb.Hide();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Form2_KeyDown(object sender, KeyEventArgs e)
        {

        }
    }
}
