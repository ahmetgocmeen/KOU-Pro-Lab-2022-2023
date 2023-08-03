namespace ProLab2Proje1
{
    public class Node
    {
        public int row;
        public int col;
        public Node prev;
        public double h;
        public int level;
        public Node(int row, int col)
        {
            this.row = row;
            this.col = col;
        }
    }
}
