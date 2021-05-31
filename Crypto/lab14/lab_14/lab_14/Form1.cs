using System;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace lab_14
{
    public partial class Form1 : Form
    {
        string srcFilename = "", destFilename = "", filename = "", matrixFilename = "";

        public Form1()
        {
            InitializeComponent();
        }

        private void chooseFileForHide_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
                srcFilename = openFileDialog.FileName;
            else return;
            fileForHide.Text = srcFilename;
        }

        private void extract_Click(object sender, EventArgs e)
        {
            FileStream readStream;
            try
            {
                readStream = new FileStream(filename, FileMode.Open);
            }
            catch (IOException)
            {
                MessageBox.Show("Opening file error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            string result = LSB.ExtractText(new Bitmap(readStream));
            readStream.Close();
            extractedMessage.Text = result;
            filename = "";
        }

        private void chooseFileForMatrix_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
                matrixFilename = openFileDialog.FileName;
            else return;
            fileForMatrix.Text = filename;
            FileStream readStream;
            try
            {
                readStream = new FileStream(matrixFilename, FileMode.Open);
            }
            catch (IOException)
            {
                MessageBox.Show("Opening file error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            pictureBox.Image = LSB.CreateMatrix(new Bitmap(readStream));
            readStream.Close();
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                destFilename = saveFileDialog.FileName;
            }
            else return;
            FileStream writeStream;
            try
            {
                writeStream = new FileStream(destFilename, FileMode.Create);
            }
            catch (IOException)
            {
                MessageBox.Show("Opening file error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            pictureBox.Image.Save(writeStream, System.Drawing.Imaging.ImageFormat.Bmp);
            writeStream.Close();
            matrixFilename = ""; destFilename = "";
        }

        private void chooseFileForExtract_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
                filename = openFileDialog.FileName;
            else return;
            fileForExtract.Text = filename;
        }

        private void hide_Click(object sender, EventArgs e)
        {
            FileStream readStream;
            try
            {
                readStream = new FileStream(srcFilename, FileMode.Open);
            }
            catch (IOException)
            {
                MessageBox.Show("Opening file error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            Bitmap result =  LSB.HideText(hiddenMessage.Text, new Bitmap(readStream));
            readStream.Close();

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                destFilename = saveFileDialog.FileName;
            }
            else return;
            FileStream writeStream;
            try
            {
                writeStream = new FileStream(destFilename, FileMode.Create); 
            }
            catch (IOException)
            {
                MessageBox.Show("Opening file error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            result.Save(writeStream, System.Drawing.Imaging.ImageFormat.Bmp);
            writeStream.Close();
            srcFilename = ""; destFilename = "";
        }
    }
}
