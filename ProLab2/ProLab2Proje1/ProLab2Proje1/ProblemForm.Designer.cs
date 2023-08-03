namespace ProLab2Proje1
{
    partial class ProblemForm
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
            components = new System.ComponentModel.Container();
            message = new Label();
            MazeButton = new Button();
            ToolTip = new ToolTip(components);
            ClearButton = new Button();
            RunButton = new Button();
            RunAnimationButton = new Button();
            timer = new System.Windows.Forms.Timer(components);
            startMenu = new Button();
            SuspendLayout();
            // 
            // message
            // 
            message.AutoSize = true;
            message.Font = new Font("Microsoft Sans Serif", 12F, FontStyle.Regular, GraphicsUnit.Point);
            message.ForeColor = Color.Red;
            message.Location = new Point(3, 618);
            message.Margin = new Padding(4, 0, 4, 0);
            message.MinimumSize = new Size(584, 19);
            message.Name = "message";
            message.Size = new Size(584, 20);
            message.TabIndex = 20;
            message.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // MazeButton
            // 
            MazeButton.Font = new Font("Arial", 9.75F, FontStyle.Bold, GraphicsUnit.Point);
            MazeButton.Location = new Point(637, 194);
            MazeButton.Margin = new Padding(4);
            MazeButton.Name = "MazeButton";
            MazeButton.Size = new Size(196, 32);
            MazeButton.TabIndex = 6;
            MazeButton.Text = "Labirent Değiştir";
            MazeButton.UseVisualStyleBackColor = true;
            MazeButton.Click += MazeButton_Click;
            // 
            // ClearButton
            // 
            ClearButton.Font = new Font("Arial", 9.75F, FontStyle.Bold, GraphicsUnit.Point);
            ClearButton.Location = new Point(637, 314);
            ClearButton.Margin = new Padding(4);
            ClearButton.Name = "ClearButton";
            ClearButton.Size = new Size(196, 32);
            ClearButton.TabIndex = 7;
            ClearButton.Text = "Temizle";
            ClearButton.UseVisualStyleBackColor = true;
            ClearButton.Click += ClearButton_Click;
            // 
            // RunButton
            // 
            RunButton.Font = new Font("Arial", 9.75F, FontStyle.Bold, GraphicsUnit.Point);
            RunButton.Location = new Point(637, 234);
            RunButton.Margin = new Padding(4);
            RunButton.Name = "RunButton";
            RunButton.Size = new Size(196, 32);
            RunButton.TabIndex = 8;
            RunButton.Text = "Sonuç Göster";
            RunButton.UseVisualStyleBackColor = true;
            RunButton.Click += RunButton_Click;
            // 
            // RunAnimationButton
            // 
            RunAnimationButton.Font = new Font("Arial", 9.75F, FontStyle.Bold, GraphicsUnit.Point);
            RunAnimationButton.Location = new Point(637, 274);
            RunAnimationButton.Margin = new Padding(4);
            RunAnimationButton.Name = "RunAnimationButton";
            RunAnimationButton.Size = new Size(196, 32);
            RunAnimationButton.TabIndex = 10;
            RunAnimationButton.Text = "Çalıştır";
            RunAnimationButton.UseVisualStyleBackColor = true;
            RunAnimationButton.Click += RunAnimationButton_Click;
            // 
            // timer
            // 
            timer.Interval = 50;
            timer.Tick += Timer_Tick;
            // 
            // startMenu
            // 
            startMenu.Font = new Font("Arial", 9.75F, FontStyle.Bold, GraphicsUnit.Point);
            startMenu.Location = new Point(637, 352);
            startMenu.Margin = new Padding(3, 2, 3, 2);
            startMenu.Name = "startMenu";
            startMenu.Size = new Size(196, 32);
            startMenu.TabIndex = 21;
            startMenu.Text = "Ana Menü";
            startMenu.UseVisualStyleBackColor = true;
            startMenu.Click += StartMenu_Click;
            // 
            // ProblemForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(846, 661);
            Controls.Add(startMenu);
            Controls.Add(message);
            Controls.Add(RunAnimationButton);
            Controls.Add(RunButton);
            Controls.Add(ClearButton);
            Controls.Add(MazeButton);
            DoubleBuffered = true;
            FormBorderStyle = FormBorderStyle.Fixed3D;
            Margin = new Padding(4);
            MaximizeBox = false;
            Name = "ProblemForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Problem Solver";
            FormClosed += ProblemForm_FormClosed;
            Paint += ProblemForm_Paint;
            ResumeLayout(false);
            PerformLayout();
        }
        #endregion
        public System.Windows.Forms.Button MazeButton;
        public System.Windows.Forms.ToolTip ToolTip;
        public System.Windows.Forms.Button ClearButton;
        public System.Windows.Forms.Button RunButton;
        public System.Windows.Forms.Button RunAnimationButton;
        public System.Windows.Forms.Label Message;
        public System.Windows.Forms.Timer timer;
        private System.Windows.Forms.Button startMenu;
        private Label message;
    }
}

