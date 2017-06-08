namespace testWin
{
    partial class frmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.文件ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.miNew = new System.Windows.Forms.ToolStripMenuItem();
            this.miOPen = new System.Windows.Forms.ToolStripMenuItem();
            this.miSave = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
            this.退出eXitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.编辑EditToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.设置SetToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.miBgColor = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.tsbNewfile = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.tbSearch = new System.Windows.Forms.ToolStripTextBox();
            this.btnQuery = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.复制CopyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.粘贴PasteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.剪切CutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripSeparator();
            this.重做RedoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.撤销UndoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.miFont = new System.Windows.Forms.ToolStripMenuItem();
            this.lblRowLine = new System.Windows.Forms.ToolStripStatusLabel();
            this.miClose = new System.Windows.Forms.ToolStripMenuItem();
            this.miCloseAll = new System.Windows.Forms.ToolStripMenuItem();
            this.hToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.vToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.cToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.文件ToolStripMenuItem,
            this.编辑EditToolStripMenuItem,
            this.设置SetToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(633, 25);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 文件ToolStripMenuItem
            // 
            this.文件ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miNew,
            this.miOPen,
            this.miSave,
            this.miClose,
            this.miCloseAll,
            this.toolStripMenuItem1,
            this.退出eXitToolStripMenuItem});
            this.文件ToolStripMenuItem.Name = "文件ToolStripMenuItem";
            this.文件ToolStripMenuItem.Size = new System.Drawing.Size(71, 21);
            this.文件ToolStripMenuItem.Text = "文件(&File)";
            // 
            // miNew
            // 
            this.miNew.Name = "miNew";
            this.miNew.Size = new System.Drawing.Size(182, 22);
            this.miNew.Text = "新建日记(&New)";
            this.miNew.Click += new System.EventHandler(this.miNew_Click);
            // 
            // miOPen
            // 
            this.miOPen.Name = "miOPen";
            this.miOPen.Size = new System.Drawing.Size(182, 22);
            this.miOPen.Text = "打开日记(&Open)";
            this.miOPen.Click += new System.EventHandler(this.miOPen_Click);
            // 
            // miSave
            // 
            this.miSave.Name = "miSave";
            this.miSave.Size = new System.Drawing.Size(182, 22);
            this.miSave.Text = "保存日记(&Save)";
            this.miSave.Click += new System.EventHandler(this.miSave_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(179, 6);
            // 
            // 退出eXitToolStripMenuItem
            // 
            this.退出eXitToolStripMenuItem.Name = "退出eXitToolStripMenuItem";
            this.退出eXitToolStripMenuItem.Size = new System.Drawing.Size(182, 22);
            this.退出eXitToolStripMenuItem.Text = "退出(e&Xit)";
            // 
            // 编辑EditToolStripMenuItem
            // 
            this.编辑EditToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.复制CopyToolStripMenuItem,
            this.粘贴PasteToolStripMenuItem,
            this.剪切CutToolStripMenuItem,
            this.toolStripMenuItem2,
            this.重做RedoToolStripMenuItem,
            this.撤销UndoToolStripMenuItem});
            this.编辑EditToolStripMenuItem.Name = "编辑EditToolStripMenuItem";
            this.编辑EditToolStripMenuItem.Size = new System.Drawing.Size(74, 21);
            this.编辑EditToolStripMenuItem.Text = "编辑(&Edit)";
            // 
            // 设置SetToolStripMenuItem
            // 
            this.设置SetToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miBgColor,
            this.miFont,
            this.hToolStripMenuItem,
            this.vToolStripMenuItem,
            this.cToolStripMenuItem});
            this.设置SetToolStripMenuItem.Name = "设置SetToolStripMenuItem";
            this.设置SetToolStripMenuItem.Size = new System.Drawing.Size(70, 21);
            this.设置SetToolStripMenuItem.Text = "设置(&Set)";
            // 
            // miBgColor
            // 
            this.miBgColor.Name = "miBgColor";
            this.miBgColor.Size = new System.Drawing.Size(152, 22);
            this.miBgColor.Text = "背景色";
            this.miBgColor.Click += new System.EventHandler(this.miBgColor_Click);
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbNewfile,
            this.toolStripButton2,
            this.tbSearch,
            this.btnQuery,
            this.toolStripButton1});
            this.toolStrip1.Location = new System.Drawing.Point(0, 25);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(633, 25);
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // tsbNewfile
            // 
            this.tsbNewfile.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbNewfile.Image = ((System.Drawing.Image)(resources.GetObject("tsbNewfile.Image")));
            this.tsbNewfile.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbNewfile.Name = "tsbNewfile";
            this.tsbNewfile.Size = new System.Drawing.Size(23, 22);
            this.tsbNewfile.Text = "toolStripButton1";
            this.tsbNewfile.Click += new System.EventHandler(this.miNew_Click);
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton2.Text = "toolStripButton2";
            // 
            // tbSearch
            // 
            this.tbSearch.Name = "tbSearch";
            this.tbSearch.Size = new System.Drawing.Size(100, 25);
            // 
            // btnQuery
            // 
            this.btnQuery.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnQuery.Image = ((System.Drawing.Image)(resources.GetObject("btnQuery.Image")));
            this.btnQuery.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnQuery.Name = "btnQuery";
            this.btnQuery.Size = new System.Drawing.Size(23, 22);
            this.btnQuery.Click += new System.EventHandler(this.btnQuery_Click);
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton1.Text = "toolStripButton1";
            this.toolStripButton1.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1,
            this.lblRowLine});
            this.statusStrip1.Location = new System.Drawing.Point(0, 460);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(633, 22);
            this.statusStrip1.TabIndex = 2;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(187, 17);
            this.toolStripStatusLabel1.Text = "Copyright by fangxj 2015-2018";
            // 
            // 复制CopyToolStripMenuItem
            // 
            this.复制CopyToolStripMenuItem.Name = "复制CopyToolStripMenuItem";
            this.复制CopyToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.复制CopyToolStripMenuItem.Text = "复制(&Copy)";
            // 
            // 粘贴PasteToolStripMenuItem
            // 
            this.粘贴PasteToolStripMenuItem.Name = "粘贴PasteToolStripMenuItem";
            this.粘贴PasteToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.粘贴PasteToolStripMenuItem.Text = "粘贴(&Paste)";
            // 
            // 剪切CutToolStripMenuItem
            // 
            this.剪切CutToolStripMenuItem.Name = "剪切CutToolStripMenuItem";
            this.剪切CutToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.剪切CutToolStripMenuItem.Text = "剪切(Cu&t)";
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(149, 6);
            // 
            // 重做RedoToolStripMenuItem
            // 
            this.重做RedoToolStripMenuItem.Name = "重做RedoToolStripMenuItem";
            this.重做RedoToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.重做RedoToolStripMenuItem.Text = "重做(&Redo)";
            this.重做RedoToolStripMenuItem.Click += new System.EventHandler(this.重做RedoToolStripMenuItem_Click);
            // 
            // 撤销UndoToolStripMenuItem
            // 
            this.撤销UndoToolStripMenuItem.Name = "撤销UndoToolStripMenuItem";
            this.撤销UndoToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.撤销UndoToolStripMenuItem.Text = "撤销(&Undo)";
            // 
            // miFont
            // 
            this.miFont.Name = "miFont";
            this.miFont.Size = new System.Drawing.Size(152, 22);
            this.miFont.Text = "字体";
            this.miFont.Click += new System.EventHandler(this.miFont_Click);
            // 
            // lblRowLine
            // 
            this.lblRowLine.Name = "lblRowLine";
            this.lblRowLine.Size = new System.Drawing.Size(0, 17);
            // 
            // miClose
            // 
            this.miClose.Name = "miClose";
            this.miClose.Size = new System.Drawing.Size(182, 22);
            this.miClose.Text = "关闭日记(&Close)";
            this.miClose.Click += new System.EventHandler(this.miClose_Click);
            // 
            // miCloseAll
            // 
            this.miCloseAll.Name = "miCloseAll";
            this.miCloseAll.Size = new System.Drawing.Size(182, 22);
            this.miCloseAll.Text = "关闭所有(Close &All)";
            this.miCloseAll.Click += new System.EventHandler(this.miCloseAll_Click);
            // 
            // hToolStripMenuItem
            // 
            this.hToolStripMenuItem.Name = "hToolStripMenuItem";
            this.hToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.hToolStripMenuItem.Text = "H";
            this.hToolStripMenuItem.Click += new System.EventHandler(this.hToolStripMenuItem_Click);
            // 
            // vToolStripMenuItem
            // 
            this.vToolStripMenuItem.Name = "vToolStripMenuItem";
            this.vToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.vToolStripMenuItem.Text = "V";
            // 
            // cToolStripMenuItem
            // 
            this.cToolStripMenuItem.Name = "cToolStripMenuItem";
            this.cToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.cToolStripMenuItem.Text = "C";
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(633, 482);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "frmMain";
            this.Text = "我的日记本";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmMain_FormClosing);
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 文件ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem miNew;
        private System.Windows.Forms.ToolStripMenuItem miOPen;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 退出eXitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 编辑EditToolStripMenuItem;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton tsbNewfile;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.ToolStripMenuItem 设置SetToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem miBgColor;
        private System.Windows.Forms.ToolStripTextBox tbSearch;
        private System.Windows.Forms.ToolStripButton btnQuery;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripMenuItem miSave;
        private System.Windows.Forms.ToolStripMenuItem 复制CopyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 粘贴PasteToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 剪切CutToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem 重做RedoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 撤销UndoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem miFont;
        private System.Windows.Forms.ToolStripStatusLabel lblRowLine;
        private System.Windows.Forms.ToolStripMenuItem miClose;
        private System.Windows.Forms.ToolStripMenuItem miCloseAll;
        private System.Windows.Forms.ToolStripMenuItem hToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem vToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem cToolStripMenuItem;
    }
}