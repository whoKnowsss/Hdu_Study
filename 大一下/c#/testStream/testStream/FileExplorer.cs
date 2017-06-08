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
using System.Diagnostics;

namespace testStream
{
    public partial class FileExplorer : Form
    {
        public FileExplorer()
        {
            InitializeComponent();
        }

        private void FileExplorer_Load(object sender, EventArgs e)
        {
            foreach (DriveInfo di in DriveInfo.GetDrives())
            {
                if (di.IsReady)
                    comboBox1.Items.Add(di.VolumeLabel + "(" + di.Name + ")");
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            treeView1.Nodes.Clear();
            listView1.Items.Clear();
            string drive = comboBox1.Text.Substring(comboBox1.Text.LastIndexOf("(") + 1, 3);
            foreach (string p in Directory.GetFileSystemEntries(drive))
            {
                if (Directory.Exists(p))//文件夹
                {
                    string dn = p.Substring(p.LastIndexOf("\\") + 1);
                    treeView1.Nodes.Add(p,dn);
                }
                else//文件
                {
                    
                    listView1.Items.Add(p,Path.GetFileNameWithoutExtension(p),1);
                }
            
            }
        }

        private void treeView1_DoubleClick(object sender, EventArgs e)
        {

            if (treeView1.SelectedNode != null)
            {
                listView1.Items.Clear();
                treeView1.SelectedNode.Nodes.Clear();
                string dir = treeView1.SelectedNode.Name;
                foreach (string p in Directory.GetFileSystemEntries(dir))
                {
                    if (Directory.Exists(p))//文件夹
                    {
                        string dn = p.Substring(p.LastIndexOf("\\") + 1);
                        treeView1.SelectedNode.Nodes.Add(p, dn);
                    }
                    else//文件
                    {

                        listView1.Items.Add(p, Path.GetFileNameWithoutExtension(p), 1);
                    }

                }
                treeView1.SelectedNode.Expand();
            }
        }

        private void 新建文件ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 f1 = new Form1();
            f1.Show();
        }

        private void 运行文件ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(listView1.SelectedItems[0]!=null)
            {
                string fn = listView1.SelectedItems[0].Name;
               
                Process.Start(fn);
            }
             
        }

        private void 复制文件ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }
    }
}
