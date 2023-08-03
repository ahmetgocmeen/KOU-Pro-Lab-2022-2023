using System.Diagnostics;
using System.Globalization;
using System.Xml.Linq;

namespace ProLab2Proje1
{
    public class Greedy
    {
        readonly ProblemForm problemForm;
        readonly Raster rstr;
        public Greedy(ProblemForm form, Raster rstr)
        {
            this.problemForm = form;
            this.rstr = rstr;
        }
        public void Solver()
        {
            if (problemForm.openList.Count == 0)
            {
                problemForm.endOfSearch = true;
                rstr.raster[problemForm.startPos.row, problemForm.startPos.col] = problemForm.ROBOT;
                problemForm.RunAnimationButton.Enabled = false;
                problemForm.Invalidate();
                return;
            }
            Node current;
            problemForm.openList.Sort((x, y) =>
            {
                int consequence = x.h.CompareTo(y.h);
                if (consequence == 0)
                    consequence = x.level.CompareTo(y.level);
                return consequence;
            });
            current = problemForm.openList[0];
            problemForm.openList.RemoveAt(0);
            problemForm.closedList.Insert(0, current);
            rstr.raster[current.row, current.col] = problemForm.CLOSED;
            List<Node> neighbors = FindNeighbors(current);
            for (int i = 0; i < neighbors.Count; i++)
            {
                double diffxlength = Math.Abs(problemForm.centerpoints[problemForm.destinationPos.row,   problemForm.destinationPos.col].X - problemForm.centerpoints[neighbors[i].row,neighbors[i].col].X);
                double diffylength = Math.Abs(problemForm.centerpoints[problemForm.destinationPos.row, problemForm.destinationPos.col].Y  - problemForm.centerpoints[neighbors[i].row,   neighbors[i].col].Y);
                neighbors[i].h = diffxlength + diffylength;
                if (neighbors[i].h == 0)
                {
                    problemForm.closedList.Add(current);
                    problemForm.found = true;
                    problemForm.endOfSearch = true;
                    return;
                }
                else
                {
                    int index = -1;
                    for (int j = 0; j < problemForm.closedList.Count; j++)
                    {
                        if (problemForm.closedList[j].row == neighbors[i].row && problemForm.closedList[j].col == neighbors[i].col)
                        {
                            index = j;
                            break;
                        }
                    }
                    if (index == -1)
                    {
                        problemForm.openList.Add(neighbors[i]);
                        rstr.raster[neighbors[i].row, neighbors[i].col] = problemForm.ROBOT;
                    }
                }
            }
            if (!problemForm.animation)
                Solver();
        }
        public List<Node> FindNeighbors(Node curr)
        {
            List<Node> neighborsList = new();
            int row = curr.row;
            int col = curr.col;
            Node node;
            if (row > 0 && rstr.raster[row - 1, col] != problemForm.IMPDMT && rstr.raster[row - 1, col] != problemForm.IMPDMT2 && rstr.raster[row - 1, col] != problemForm.IMPDMT3)
            {
                node = new Node(row - 1, col) { prev = curr, level = ++problemForm.level };
                neighborsList.Add(node);
            }
            if (col < rstr.edge - 1 && rstr.raster[row, col + 1] != problemForm.IMPDMT && rstr.raster[row, col + 1] != problemForm.IMPDMT2 && rstr.raster[row, col + 1] != problemForm.IMPDMT3)
            {
                node = new Node(row, col + 1) { prev = curr, level = ++problemForm.level };
                neighborsList.Add(node);
            }
            if (row < rstr.edge - 1 && rstr.raster[row + 1, col] != problemForm.IMPDMT && rstr.raster[row + 1, col] != problemForm.IMPDMT2 && rstr.raster[row + 1, col] != problemForm.IMPDMT3)
            {
                node = new Node(row + 1, col) { prev = curr, level = ++problemForm.level };
                neighborsList.Add(node);
            }
            if (col > 0 && rstr.raster[row, col - 1] != problemForm.IMPDMT && rstr.raster[row, col - 1] != problemForm.IMPDMT2 && rstr.raster[row, col - 1] != problemForm.IMPDMT3)
            {
                node = new Node(row, col - 1) {prev = curr, level = ++problemForm.level };
                neighborsList.Add(node);
            }
            return neighborsList;
        }
    }
}