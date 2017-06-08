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

namespace testStream
{
    public partial class Form1 : Form
    {
        string FileName = "";
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnOpen_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "文本文件(*.txt)|*.txt";
            if (ofd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                FileName = ofd.FileName;
                FileStream fs = new FileStream(ofd.FileName,FileMode.Open);
                StreamReader sr = new StreamReader(fs,Encoding.GetEncoding("gb2312"));
                txtContent.Text = sr.ReadToEnd();
                sr.Close();
                fs.Dispose();
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(FileName))
            {
                SaveFileDialog sfd = new SaveFileDialog();
                if (sfd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    FileName = sfd.FileName;
                    if (!FileName.ToLower().EndsWith(".txt"))
                        FileName += ".txt";
                }
            }
            FileStream fs = new FileStream(FileName, FileMode.OpenOrCreate);
            StreamWriter sw = new StreamWriter(fs,Encoding.GetEncoding("gb2312"));
            sw.WriteLine(txtContent.Text);
            sw.Close();
            fs.Dispose();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }
    }
}
