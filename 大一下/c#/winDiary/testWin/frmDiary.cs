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
    public partial class frmDiary : Form
    {
        public string FileName
        {
            get;
            set;
        }
        public frmDiary()
        {
            InitializeComponent();
        }
        public RichTextBox RichDiary
        {
            get { return richTextBox1; }
            set { richTextBox1 = value; }
        }

        private void richTextBox1_SelectionChanged(object sender, EventArgs e)
        {
            frmMain fm = this.MdiParent as frmMain;
            fm.RowLine.Text = richTextBox1.GetLineFromCharIndex(richTextBox1.SelectionStart)+1 +"行 ";
            fm.RowLine.Text += richTextBox1.SelectionStart - richTextBox1.GetFirstCharIndexOfCurrentLine() + 1 + "列";
        }


    }
}
