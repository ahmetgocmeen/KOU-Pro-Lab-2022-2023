using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ProLab2Proje1
{
    public abstract class Raster
    {
        Random rnd = new Random();
        public int[,] raster;
        public int edge;
        int pnt;
        public ProblemForm problemForm;
        public static int i = 0;
        public Raster(ProblemForm form)
        {
            this.problemForm = form;
        }
        public Raster() { }
        public abstract void Createraster();
        public void FillRaster()
        {
            if (problemForm.endOfSearch || problemForm.isRunning)
            {
                for (int i = 0; i < edge; i++)
                {
                    for (int j = 0; j < edge; j++)
                    {
                        if (raster[i, j] == problemForm.START)
                            problemForm.startPos = new Node(i, j);
                        if (raster[i, j] == problemForm.DESTINATION)
                            problemForm.destinationPos = new Node(i, j);
                        if (raster[i, j] == problemForm.ROBOT || raster[i, j] == problemForm.CLOSED || raster[i, j] == problemForm.PATH)
                            raster[i, j] = problemForm.EMPTY;
                    }
                }
            }
            else
            {
                for (int i = 0; i < edge; i++)
                {
                    for (int j = 0; j < edge; j++)
                    {
                        raster[i, j] = problemForm.EMPTY;
                    }
                }
                if (problemForm.rstr.GetType() == typeof(Prob1Raster))
                {
                    problemForm.startPos = new Node(0, 0);
                    problemForm.destinationPos = new Node(edge - 1, edge - 1);
                }
                else
                {
                    problemForm.startPos = new Node(1, 1);
                    problemForm.destinationPos = new Node(edge - 2, edge - 2);
                }
            }
            problemForm.found = false;
            problemForm.endOfSearch = false;
            problemForm.openList.Clear();
            problemForm.closedList.Clear();
            problemForm.openList.Add(problemForm.startPos);
            problemForm.startPos.h = -1;
            if (!problemForm.isRunning)
            {
                raster[problemForm.destinationPos.row, problemForm.destinationPos.col] = problemForm.DESTINATION;
                raster[problemForm.startPos.row, problemForm.startPos.col] = problemForm.START;
            }
        }
    }
}