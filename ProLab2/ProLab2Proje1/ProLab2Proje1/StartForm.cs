using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProLab2Proje1
{
    public partial class StartForm : Form
    {
        ProblemForm problemForm;
        public StartForm()
        {
            InitializeComponent();
        }

        private void Problem1_Click(object sender, EventArgs e)
        {
            problemForm = new ProblemForm(1);
            problemForm.Show();
            this.Hide();
        }

        private void Problem2_Click(object sender, EventArgs e)
        {
            problemForm = new ProblemForm();
            problemForm.Show();
            this.Hide();
        }

        private void StartForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

    }
}
