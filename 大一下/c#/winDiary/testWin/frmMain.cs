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


namespace testWin
{
    
    public partial class frmMain : Form
    {
        int pos = 0;
        public frmMain()
        {
            InitializeComponent();
        }

        public ToolStripStatusLabel RowLine
        {
            get { return lblRowLine; }
            set { lblRowLine = value; }
        }
        public StatusStrip statusStrip
        {
            get { return this.statusStrip1; }
            set { this.statusStrip1 = value; }
        }
        private void frmMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            
                Application.Exit();
        }

        private void miNew_Click(object sender, EventArgs e)
        {
            frmDiary fd = new frmDiary();
            fd.Text = DateTime.Now.ToLongDateString();
            fd.MdiParent = this;
            fd.Show();
        }

        private void miBgColor_Click(object sender, EventArgs e)
        {
            frmDiary currentForm = this.ActiveMdiChild as frmDiary;
            ColorDialog cd = new ColorDialog();
            if (cd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            { currentForm.RichDiary.BackColor = cd.Color; }
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            frmDraw fd = new frmDraw();
            fd.MdiParent = this;
            fd.Show();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {

        }

        private void miOPen_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "文本文件(*.txt)|*.txt|富文本文件(*.rtf)|*.rtf";
            if (ofd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                string fn = ofd.FileName;
                frmDiary fd = new frmDiary();
                fd.RichDiary.LoadFile(fn);
                fd.MdiParent = this;
                fd.Text = Path.GetFileNameWithoutExtension(fn);
                fd.FileName = fn;
                fd.Show();
                
            }
        }

        private void miSave_Click(object sender, EventArgs e)
        {
            if (this.ActiveMdiChild != null)
            {
                frmDiary fd = this.ActiveMdiChild as frmDiary;
                if (string.IsNullOrEmpty(fd.FileName))
                {
                    SaveFileDialog sfd = new SaveFileDialog();
                    sfd.Filter = "文本文件(*.txt)|*.txt|富文本文件(*.rtf)|*.rtf";
                    if (sfd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        string fn = sfd.FileName;
                        if (fn.ToLower().EndsWith("txt") || fn.ToLower().EndsWith("rtf"))
                        {
                            fd.RichDiary.SaveFile(fn);
                            fd.FileName = fn;
                        }
                        else
                        {
                            MessageBox.Show("请填写正确的后缀名！");
                        }
                    }
                }
                else
                    fd.RichDiary.SaveFile(fd.FileName);
            }
        }

        private void miFont_Click(object sender, EventArgs e)
        {
            if (this.ActiveMdiChild != null)
            {
                frmDiary fd = this.ActiveMdiChild as frmDiary;
                FontDialog font = new FontDialog();
                font.ShowColor = true;
                if (font.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    fd.RichDiary.SelectionFont = font.Font;
                    fd.RichDiary.SelectionColor = font.Color;
                }
            }
        }

        private void btnQuery_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(tbSearch.Text))
            {
                if (this.ActiveMdiChild != null)
                {
                    frmDiary fd = this.ActiveMdiChild as frmDiary;
                     pos = fd.RichDiary.Text.IndexOf(tbSearch.Text, pos);
                     if (pos >= 0)
                     {
                         fd.RichDiary.SelectionStart = pos;
                         fd.RichDiary.SelectionLength = tbSearch.Text.Length;
                         pos += tbSearch.Text.Length + 1;

                     }
                     else
                         pos = 0;
                }
            }
        }

        private void 重做RedoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.ActiveMdiChild != null)
            {
                frmDiary fd = this.ActiveMdiChild as frmDiary;
                fd.RichDiary.Cut();
            }
        }

        private void miClose_Click(object sender, EventArgs e)
        {
            if (this.ActiveMdiChild != null)
            {
                this.ActiveMdiChild.Close();
            }
        }

        private void miCloseAll_Click(object sender, EventArgs e)
        {
            foreach (Form f in this.MdiChildren)
                f.Close();
        }

        private void hToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.TileHorizontal);
        }

       
    }
}
