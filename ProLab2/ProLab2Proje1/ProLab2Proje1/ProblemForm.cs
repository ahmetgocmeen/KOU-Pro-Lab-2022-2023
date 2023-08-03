using ProLab2Proje1.Properties;
using System.Diagnostics;
using System.Drawing.Drawing2D;

namespace ProLab2Proje1
{
    public partial class ProblemForm : Form
    {
        public int nodeSize;
        public List<Node> openList = new();
        public List<Node> closedList = new();
        public Node startPos;
        public Node destinationPos;
        public Point[,] centerpoints;
        public bool isRunning;
        public bool found;
        public bool endOfSearch;
        public bool animation;
        public int level;
        public Stopwatch watch = new();
        public int EMPTY = 0;
        public int IMPDMT = 1;
        public int IMPDMT2 = 2;
        public int IMPDMT3 = 3;
        public int ROBOT = 4;
        public int CLOSED = 5;
        public int PATH = 6;
        public int START = 7;
        public int DESTINATION = 8;
        public Calc calc;
        public Raster rstr;
        Greedy greedy;
        StartForm startForm;
        readonly Impediment impediment = new();

        public Node StartPos { get; internal set; }

        public ProblemForm()
        {
            InitializeComponent();
            rstr = new Prob2Raster(this);
            rstr.Createraster();
        }
        public ProblemForm(int a)
        {
            InitializeComponent();
            MazeButton.Text = "URL Değiştir";
            rstr = new Prob1Raster(this);
            rstr.Createraster();
        }
        private void ProblemForm_Paint(object sender, PaintEventArgs e)
        {
            Brush brush = new SolidBrush(Color.Gray);
            Graphics g = e.Graphics;
            g.FillRectangle(brush, new Rectangle(0, 0, rstr.edge * nodeSize + 1, rstr.edge * nodeSize + 1));
            brush.Dispose();
            for (int i = 0; i < rstr.edge; i++)
            {
                for (int j = 0; j < rstr.edge; j++)
                {
                    if (rstr.raster[i, j] == EMPTY)
                        brush = new SolidBrush(Color.White);
                    else if (rstr.raster[i, j] == IMPDMT)
                        g.FillPolygon(impediment.GetTexture(0), CalcCornerPoints(i, j));
                    else if (rstr.raster[i, j] == IMPDMT2)
                        g.FillPolygon(impediment.GetTexture(1), CalcCornerPoints(i, j));
                    else if (rstr.raster[i, j] == IMPDMT3)
                        g.FillPolygon(impediment.GetTexture(2), CalcCornerPoints(i, j));
                    else if (rstr.raster[i, j] == START)
                        brush = new SolidBrush(Color.Green);
                    else if (rstr.raster[i, j] == DESTINATION)
                        brush = new SolidBrush(Color.Red);
                    else if (rstr.raster[i, j] == ROBOT)
                        brush = new SolidBrush(Color.Blue);
                    else if (rstr.raster[i, j] == CLOSED)
                        brush = new SolidBrush(Color.Tomato);
                    else if (rstr.raster[i, j] == PATH)
                        brush = new SolidBrush(Color.SpringGreen);
                    if (rstr.raster[i, j] != IMPDMT && rstr.raster[i, j] != IMPDMT2 && rstr.raster[i, j] != IMPDMT3)
                        g.FillPolygon(brush, CalcCornerPoints(i, j));
                    brush.Dispose();
                }
            }
        }
        private void MazeButton_Click(object sender, EventArgs e)
        {
            RunAnimationButton.Enabled = true;
            RunButton.Enabled = true;
            animation = false;
            isRunning = false;
            rstr.Createraster();
        }
        private void ClearButton_Click(object sender, EventArgs e)
        {
            RunAnimationButton.Enabled = true;
            RunButton.Enabled = true;
            animation = false;
            isRunning = false;
            rstr.FillRaster();
            Invalidate();
        }
        private void RunButton_Click(object sender, EventArgs e)
        {
            if (isRunning) return;
            RunAnimationButton.Enabled = false;
            isRunning = true;
            watch.Start();
            ProblemSolver();
        }
        private void RunAnimationButton_Click(object sender, EventArgs e)
        {
            if (isRunning) return;
            RunButton.Enabled = false;
            timer.Stop();
            timer.Start();
            watch.Start();
            animation = true;
            isRunning = true;
        }
        private void Timer_Tick(object sender, EventArgs e)
        {
            if (animation)
            {
                ProblemSolver();
                Invalidate();
                if (endOfSearch)
                {
                    animation = false;
                    timer.Stop();
                }
            }
        }
        private void ProblemSolver()
        {
            greedy = new Greedy(this, rstr);
            greedy.Solver();
            if (found)
            {
                calc = new Calc(this, rstr);
                string text = calc.CalcPathAndTime();
                message.Text = text;
                endOfSearch = true;
                Invalidate();
            }
        }
        private void ProblemForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
        private void StartMenu_Click(object sender, EventArgs e)
        {
            this.Hide();
            startForm = new StartForm();
            startForm.Show();
        }
        private Point[] CalcCornerPoints(int i, int j)
        {
            Point[] cornerPoints = {
                new Point(1 + j*nodeSize, 1 + i*nodeSize),
                new Point((j+1)*nodeSize, 1 + i*nodeSize),
                new Point((j+1)*nodeSize, (i+1)*nodeSize),
                new Point(1 + j*nodeSize, (i+1)*nodeSize)
            };
            return cornerPoints;
        }
    }
}