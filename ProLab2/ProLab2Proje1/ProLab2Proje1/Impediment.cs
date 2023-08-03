using ProLab2Proje1.Properties;
using System.Drawing.Drawing2D;

namespace ProLab2Proje1
{
    class Impediment
    {
        public Image[] image = new Bitmap[3];
        public TextureBrush[] tBrush = new TextureBrush[3];
        public Impediment()
        {
            SetTextureBrush(); 
        }
        public void SetTextureBrush()
        {
            image[0] = new Bitmap(Resources.wall1);
            image[1] = new Bitmap(Resources.tyrewall);
            image[2] = new Bitmap(Resources.gravetrap);
            tBrush[0] = new TextureBrush(image[0]);
            tBrush[1] = new TextureBrush(image[1]);
            tBrush[2] = new TextureBrush(image[2]);
            tBrush[0].Transform = new Matrix(
               75.0f / 640.0f,
               0.0f,
               0.0f,
               75.0f / 480.0f,
               0.0f,
               0.0f);
            tBrush[1].Transform = new Matrix(
               75.0f / 640.0f,
               0.0f,
               0.0f,
               75.0f / 480.0f,
               0.0f,
               0.0f);
            tBrush[2].Transform = new Matrix(
               75.0f / 640.0f,
               0.0f,
               0.0f,
               75.0f / 480.0f,
               0.0f,
               0.0f);
        }
        public TextureBrush GetTexture(int index)
        {
            return tBrush[index];
        }
    }
}
