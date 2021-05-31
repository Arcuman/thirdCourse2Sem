namespace lab_14
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.chooseFileForHide = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.hide = new System.Windows.Forms.Button();
            this.fileForHide = new System.Windows.Forms.Label();
            this.hiddenMessage = new System.Windows.Forms.RichTextBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.label3 = new System.Windows.Forms.Label();
            this.extractedMessage = new System.Windows.Forms.RichTextBox();
            this.extract = new System.Windows.Forms.Button();
            this.fileForExtract = new System.Windows.Forms.Label();
            this.chooseFileForExtract = new System.Windows.Forms.Button();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.fileForMatrix = new System.Windows.Forms.Label();
            this.chooseFileForMatrix = new System.Windows.Forms.Button();
            this.pictureBox = new System.Windows.Forms.PictureBox();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // openFileDialog
            // 
            this.openFileDialog.Filter = "Images (*.bmp)|*.bmp|All files (*.*)|*.*";
            // 
            // chooseFileForHide
            // 
            this.chooseFileForHide.Location = new System.Drawing.Point(9, 286);
            this.chooseFileForHide.Name = "chooseFileForHide";
            this.chooseFileForHide.Size = new System.Drawing.Size(100, 29);
            this.chooseFileForHide.TabIndex = 0;
            this.chooseFileForHide.Text = "Choose file";
            this.chooseFileForHide.UseVisualStyleBackColor = true;
            this.chooseFileForHide.Click += new System.EventHandler(this.chooseFileForHide_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(103, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Enter message";
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Location = new System.Drawing.Point(12, 12);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(599, 410);
            this.tabControl1.TabIndex = 2;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.hide);
            this.tabPage1.Controls.Add(this.fileForHide);
            this.tabPage1.Controls.Add(this.hiddenMessage);
            this.tabPage1.Controls.Add(this.chooseFileForHide);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(591, 381);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Hide";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // hide
            // 
            this.hide.Location = new System.Drawing.Point(9, 321);
            this.hide.Name = "hide";
            this.hide.Size = new System.Drawing.Size(570, 45);
            this.hide.TabIndex = 4;
            this.hide.Text = "Hide message";
            this.hide.UseVisualStyleBackColor = true;
            this.hide.Click += new System.EventHandler(this.hide_Click);
            // 
            // fileForHide
            // 
            this.fileForHide.AutoSize = true;
            this.fileForHide.Location = new System.Drawing.Point(115, 292);
            this.fileForHide.Name = "fileForHide";
            this.fileForHide.Size = new System.Drawing.Size(0, 17);
            this.fileForHide.TabIndex = 3;
            // 
            // hiddenMessage
            // 
            this.hiddenMessage.Location = new System.Drawing.Point(9, 32);
            this.hiddenMessage.Name = "hiddenMessage";
            this.hiddenMessage.Size = new System.Drawing.Size(573, 242);
            this.hiddenMessage.TabIndex = 2;
            this.hiddenMessage.Text = "";
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.label3);
            this.tabPage2.Controls.Add(this.extractedMessage);
            this.tabPage2.Controls.Add(this.extract);
            this.tabPage2.Controls.Add(this.fileForExtract);
            this.tabPage2.Controls.Add(this.chooseFileForExtract);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(591, 381);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Extract";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 109);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(128, 17);
            this.label3.TabIndex = 4;
            this.label3.Text = "Extracted message";
            // 
            // extractedMessage
            // 
            this.extractedMessage.Location = new System.Drawing.Point(7, 129);
            this.extractedMessage.Name = "extractedMessage";
            this.extractedMessage.ReadOnly = true;
            this.extractedMessage.Size = new System.Drawing.Size(573, 242);
            this.extractedMessage.TabIndex = 3;
            this.extractedMessage.Text = "";
            // 
            // extract
            // 
            this.extract.Location = new System.Drawing.Point(7, 61);
            this.extract.Name = "extract";
            this.extract.Size = new System.Drawing.Size(570, 45);
            this.extract.TabIndex = 2;
            this.extract.Text = "Extract message";
            this.extract.UseVisualStyleBackColor = true;
            this.extract.Click += new System.EventHandler(this.extract_Click);
            // 
            // fileForExtract
            // 
            this.fileForExtract.AutoSize = true;
            this.fileForExtract.Location = new System.Drawing.Point(115, 23);
            this.fileForExtract.Name = "fileForExtract";
            this.fileForExtract.Size = new System.Drawing.Size(0, 17);
            this.fileForExtract.TabIndex = 1;
            // 
            // chooseFileForExtract
            // 
            this.chooseFileForExtract.Location = new System.Drawing.Point(9, 17);
            this.chooseFileForExtract.Name = "chooseFileForExtract";
            this.chooseFileForExtract.Size = new System.Drawing.Size(100, 29);
            this.chooseFileForExtract.TabIndex = 0;
            this.chooseFileForExtract.Text = "Choose file";
            this.chooseFileForExtract.UseVisualStyleBackColor = true;
            this.chooseFileForExtract.Click += new System.EventHandler(this.chooseFileForExtract_Click);
            // 
            // saveFileDialog
            // 
            this.saveFileDialog.Filter = "Images (*.bmp)|*.bmp|All files (*.*)|*.*";
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.pictureBox);
            this.tabPage3.Controls.Add(this.fileForMatrix);
            this.tabPage3.Controls.Add(this.chooseFileForMatrix);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(591, 381);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Matrix";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // fileForMatrix
            // 
            this.fileForMatrix.AutoSize = true;
            this.fileForMatrix.Location = new System.Drawing.Point(112, 23);
            this.fileForMatrix.Name = "fileForMatrix";
            this.fileForMatrix.Size = new System.Drawing.Size(0, 17);
            this.fileForMatrix.TabIndex = 3;
            // 
            // chooseFileForMatrix
            // 
            this.chooseFileForMatrix.Location = new System.Drawing.Point(6, 17);
            this.chooseFileForMatrix.Name = "chooseFileForMatrix";
            this.chooseFileForMatrix.Size = new System.Drawing.Size(100, 29);
            this.chooseFileForMatrix.TabIndex = 2;
            this.chooseFileForMatrix.Text = "Choose file";
            this.chooseFileForMatrix.UseVisualStyleBackColor = true;
            this.chooseFileForMatrix.Click += new System.EventHandler(this.chooseFileForMatrix_Click);
            // 
            // pictureBox
            // 
            this.pictureBox.Location = new System.Drawing.Point(6, 52);
            this.pictureBox.Name = "pictureBox";
            this.pictureBox.Size = new System.Drawing.Size(579, 323);
            this.pictureBox.TabIndex = 4;
            this.pictureBox.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(623, 435);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "LSB";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.Button chooseFileForHide;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Button hide;
        private System.Windows.Forms.Label fileForHide;
        private System.Windows.Forms.RichTextBox hiddenMessage;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.Button extract;
        private System.Windows.Forms.Label fileForExtract;
        private System.Windows.Forms.Button chooseFileForExtract;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.RichTextBox extractedMessage;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Label fileForMatrix;
        private System.Windows.Forms.Button chooseFileForMatrix;
        private System.Windows.Forms.PictureBox pictureBox;
    }
}

