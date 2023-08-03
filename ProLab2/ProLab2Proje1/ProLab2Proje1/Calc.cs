namespace ProLab2Proje1
{
    public class Calc
    {
        readonly ProblemForm problemForm;
        readonly Raster rstr;
        String message = "";
        int pathcounter = 0;
        public Calc(ProblemForm form, Raster rstr)
        {
            this.problemForm = form;
            this.rstr = rstr;
        }
        public String CalcPathAndTime()
        {
            problemForm.watch.Stop();
            Node curNode = (Node)problemForm.closedList[0];
            rstr.raster[curNode.row, curNode.col] = problemForm.PATH;
            while (!(curNode.row == problemForm.startPos.row && curNode.col == problemForm.startPos.col))
            {
                pathcounter++;
                curNode = curNode.prev;
                rstr.raster[curNode.row, curNode.col] = problemForm.PATH;
            }
            message = String.Format("Sonuca Giden Yoldaki Kare Sayısı: {0},\n Hedefe ulaşmak için geçen süre {1}sn", pathcounter, problemForm.watch.ElapsedMilliseconds/1000);
            rstr.raster[problemForm.startPos.row, problemForm.startPos.col] = problemForm.START;
            rstr.raster[problemForm.destinationPos.row, problemForm.destinationPos.col] = problemForm.DESTINATION;
            problemForm.watch.Reset();
            return message;
        }
    }
}