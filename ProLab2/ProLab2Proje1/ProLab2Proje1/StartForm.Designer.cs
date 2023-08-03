namespace ProLab2Proje1
{
    partial class StartForm
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
            this.problem1 = new System.Windows.Forms.Button();
            this.problem2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // problem1
            // 
            this.problem1.Location = new System.Drawing.Point(288, 101);
            this.problem1.Name = "Problem1";
            this.problem1.Size = new System.Drawing.Size(221, 55);
            this.problem1.TabIndex = 0;
            this.problem1.Text = "Problem 1";
            this.problem1.UseVisualStyleBackColor = true;
            this.problem1.Click += new System.EventHandler(this.Problem1_Click);
            // 
            // problem2
            // 
            this.problem2.Location = new System.Drawing.Point(288, 205);
            this.problem2.Name = "Problem2";
            this.problem2.Size = new System.Drawing.Size(221, 50);
            this.problem2.TabIndex = 1;
            this.problem2.Text = "Problem 2";
            this.problem2.UseVisualStyleBackColor = true;
            this.problem2.Click += new System.EventHandler(this.Problem2_Click);
            // 
            // StartForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.problem2);
            this.Controls.Add(this.problem1);
            this.Name = "StartForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Start Menu";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.StartForm_FormClosed);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button problem1;
        private System.Windows.Forms.Button problem2;
    }
}