using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProLab2Proje1
{
    public class Maze
    {

        private Random rnd;
        private NodeState[,] Nodes;
        public String mazestr = "";
        private int edge;
        public Maze(int edge)
        {
            this.edge = edge;
            Nodes = new NodeState[edge,edge];
            for (int x = 0; x < edge; x++)
            {
                for (int y = 0; y < edge; y++)
                {
                    Nodes[x, y] = NodeState.Initial;
                }
            }
            rnd = new Random();
            VisitNode(rnd.Next(edge), rnd.Next(edge));
            MakeString();
        }
        public NodeState this[int x, int y]
        {
            get{
                return Nodes[x, y]; 
            }
            set {
                Nodes[x, y] = value;
            }
        }
        public IEnumerable<RemoveWallAction> GetNeighbours(Point p)
        {
            if (p.X > 0) 
                yield return new RemoveWallAction { Neighbour = new Point(p.X - 1, p.Y), Wall = NodeState.Left };
            if (p.Y > 0) 
                yield return new RemoveWallAction { Neighbour = new Point(p.X, p.Y - 1), Wall = NodeState.Top };
            if (p.X < edge - 1) 
                yield return new RemoveWallAction { Neighbour = new Point(p.X + 1, p.Y), Wall = NodeState.Right };
            if (p.Y < edge - 1) 
                yield return new RemoveWallAction { Neighbour = new Point(p.X, p.Y + 1), Wall = NodeState.Bottom };
        }

        public void VisitNode(int x, int y)
        {
            this[x, y] |= NodeState.Visited;
            foreach (var p in GetNeighbours(new Point(x, y)).Shuffle(rnd).Where(z => !(this[z.Neighbour.X, z.Neighbour.Y].HasFlag(NodeState.Visited))))
            {
                this[x, y] -= p.Wall;
                this[p.Neighbour.X, p.Neighbour.Y] -= p.Wall.OppositeWall();
                VisitNode(p.Neighbour.X, p.Neighbour.Y);
            }
        }
        public void MakeString()
        {
            var firstLine = string.Empty;
            for (var y = 0; y < edge; y++)
            {
                var sbTop = new StringBuilder();
                var sbMid = new StringBuilder();
                for (var x = 0; x < edge; x++)
                {
                    sbTop.Append(this[x, y].HasFlag(NodeState.Top) ? "+-" : "+ ");
                    sbMid.Append(this[x, y].HasFlag(NodeState.Left) ? "| " : "  ");
                }
                if (firstLine == string.Empty)
                    firstLine = sbTop.ToString();
                mazestr = mazestr + sbTop + "+";
                mazestr = mazestr + sbMid + "|";
            }
            mazestr = mazestr + firstLine + "+";
        }
    }
    [Flags]
    public enum NodeState
    {
        Top = 1,
        Right = 2,
        Bottom = 4,
        Left = 8,
        Visited = 128,
        Initial = Top | Right | Bottom | Left,
    }
    public struct RemoveWallAction
    {
        public Point Neighbour;
        public NodeState Wall;
    }
}
