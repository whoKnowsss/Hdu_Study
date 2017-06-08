namespace testWin
{
    partial class frmDraw
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
            this.SuspendLayout();
            // 
            // frmDraw
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(483, 390);
            this.Name = "frmDraw";
            this.Text = "frmDraw";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.frmDraw_Paint);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.frmDraw_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.frmDraw_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.frmDraw_MouseUp);
            this.ResumeLayout(false);

        }

        #endregion
    }
}