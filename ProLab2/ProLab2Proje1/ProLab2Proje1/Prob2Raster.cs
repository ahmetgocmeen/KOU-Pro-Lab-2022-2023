using Microsoft.VisualBasic;
using System.Text.RegularExpressions;

namespace ProLab2Proje1
{
    public class Prob2Raster : Raster
    {
        Maze maze;
        public Prob2Raster(ProblemForm form) : base(form)
        {
        }
        public Prob2Raster() { }
        public override void Createraster()
        {
            edge = Convert.ToInt32(Interaction.InputBox("Karesel Alanın Kenar Uzunluğunu Giriniz:", "Kenar Uzunluğu", "", 20, 20));
            if (edge % 2 != 1)
            {
                edge -= 1;
            }
            raster = new int[edge, edge];
            problemForm.nodeSize = (int)(600 / edge);
            problemForm.centerpoints = new Point[edge, edge];
            for (int i = 0; i < edge; i++)
            {
                for (int j = 0; j < edge; j++)
                {
                    problemForm.centerpoints[i, j] = new Point(1 + j * problemForm.nodeSize + problemForm.nodeSize / 2, 1 + i * problemForm.nodeSize + problemForm.nodeSize / 2);
                }
            }
            problemForm.startPos = new Node(1, 1);
            problemForm.destinationPos = new Node(edge - 2, edge - 2);
            problemForm.level = 0;
            FillRaster();
            maze = new Maze(edge/2);
            for (int i = 0; i < edge; i++)
            {
                for (int j = 0; j < edge; j++)
                {
                    if (Regex.IsMatch(maze.mazestr.Substring(i * edge + j, 1), "[+-|]"))
                        raster[i, j] = problemForm.IMPDMT;
                }
            }
            problemForm.Invalidate();
        }
    }
}