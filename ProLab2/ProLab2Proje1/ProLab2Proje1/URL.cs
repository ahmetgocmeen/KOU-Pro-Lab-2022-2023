using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace ProLab2Proje1
{
    public class URL
    {
        public WebClient wc = new WebClient();
        public string theTextFile;
        public string[] newText;
        public int[,] matris1 = new int[20, 20];
        public int[,] matris2 = new int[10, 10];
        public URL()
        {
            TextTo2DArray();
        }
        public void TextTo2DArray()
        {
            int i = 0;
            theTextFile = wc.DownloadString("http://bilgisayar.kocaeli.edu.tr/prolab2/url1.txt");
            newText = theTextFile.Split(new Char[] { '\n' });
            foreach (string author in newText)
            {
                var intArray = author.Select(c => c - '0').ToArray();
                for (int a = 0; a < intArray.Length; a++)
                    matris1[i, a] = intArray[a];
                i++;
            }
            i = 0;
            theTextFile = wc.DownloadString("http://bilgisayar.kocaeli.edu.tr/prolab2/url2.txt");
            newText = theTextFile.Split(new Char[] { '\n' });
            foreach (string author in newText)
            {
                var intArray = author.Select(c => c - '0').ToArray();
                for (int a = 0; a < intArray.Length; a++)
                    matris2[i, a] = intArray[a];
                i++;
            }
        }
        public int[,] Return1()
        {
            return matris1;
        }

        public int[,] Return2()
        {
            return matris2;
        }
    }
}
