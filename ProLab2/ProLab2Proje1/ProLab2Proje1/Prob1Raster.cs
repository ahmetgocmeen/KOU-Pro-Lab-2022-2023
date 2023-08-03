namespace ProLab2Proje1
{
    public class Prob1Raster : Raster
    {
        public URL url = new();
        Random rnd = new Random();
        public Prob1Raster(ProblemForm form) : base(form)
        {
        }
        public override void Createraster()
        {
            if (i % 2 == 0)
            {
                edge = (int)Math.Sqrt(url.matris1.Length);
            }
            else
            {
                edge = (int)Math.Sqrt(url.matris2.Length);
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
            problemForm.startPos = new Node(0, 0);
            problemForm.destinationPos = new Node(edge - 1, edge - 1);
            problemForm.level = 0;
            FillRaster();
            if (i % 2 == 0)
            {
                raster = (int[,])url.Return1().Clone();
            }
            else
            {
                raster = (int[,])url.Return2().Clone();
            }
            i++;
            for (int i = 0; i < edge; i++)
            {
                for (int j = 0; j < edge; j++)
                {
                    if (raster[i, j] == 2)
                    {
                        if (rnd.Next(1, 5) == 1)
                            raster[i, j] = problemForm.EMPTY;
                        else
                            raster[i, j] = problemForm.IMPDMT2;
                    }
                    else if (raster[i, j] == 3)
                    {
                        if (rnd.Next(1, 5) == 1)
                        {
                            if (!(i > 0 && j > 0 && raster[i + 1, j] == 3 &&
                                raster[i - 1, j] == 3 && raster[i, j + 1] == 3 &&
                                raster[i, j + 1] == 3))
                                raster[i, j] = problemForm.EMPTY;
                        }
                        else
                            raster[i, j] = problemForm.IMPDMT3;
                    }
                }
            }
            raster[problemForm.destinationPos.row, problemForm.destinationPos.col] = problemForm.DESTINATION;
            raster[problemForm.startPos.row, problemForm.startPos.col] = problemForm.START;
            problemForm.Invalidate();
        }
    }
}