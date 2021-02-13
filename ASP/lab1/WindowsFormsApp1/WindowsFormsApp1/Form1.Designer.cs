
namespace WindowsFormsApp1
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
            this.valueOne = new System.Windows.Forms.TextBox();
            this.valueTwo = new System.Windows.Forms.TextBox();
            this.result = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // valueOne
            // 
            this.valueOne.Location = new System.Drawing.Point(120, 63);
            this.valueOne.Name = "valueOne";
            this.valueOne.Size = new System.Drawing.Size(100, 22);
            this.valueOne.TabIndex = 0;
            // 
            // valueTwo
            // 
            this.valueTwo.Location = new System.Drawing.Point(274, 63);
            this.valueTwo.Name = "valueTwo";
            this.valueTwo.Size = new System.Drawing.Size(100, 22);
            this.valueTwo.TabIndex = 1;
            // 
            // result
            // 
            this.result.AutoSize = true;
            this.result.Location = new System.Drawing.Point(221, 124);
            this.result.Name = "result";
            this.result.Size = new System.Drawing.Size(43, 17);
            this.result.TabIndex = 2;
            this.result.Text = "result";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(224, 171);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 3;
            this.button1.Text = "Click";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.result);
            this.Controls.Add(this.valueTwo);
            this.Controls.Add(this.valueOne);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox valueOne;
        private System.Windows.Forms.TextBox valueTwo;
        private System.Windows.Forms.Label result;
        private System.Windows.Forms.Button button1;
    }
}

