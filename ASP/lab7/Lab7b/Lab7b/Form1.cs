using System;
using System.Linq;
using System.Windows.Forms;
using Lab7b.PhoneDictService; //ДЛЯ asmx
//using Lab7b.ServiceReference1; //для WCF

namespace Lab7b
{
    public partial class Form1 : Form
    {
       private PhoneDictServiceSoapClient Service { get; set; }//ДЛЯ asmx
        // private IService1 Service { get; set; } //для WCF
        public Form1()
        {
            InitializeComponent();
            Service = new PhoneDictServiceSoapClient();  //ДЛЯ asmx
            // Service = new Service1Client();  //для WCF
            LoadPhoneList();
        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            if (PhonesGrid.SelectedRows.Count != 0)
            {
                if (PhonesGrid.SelectedRows != null && PhonesGrid.SelectedRows[0] != null &&
                    PhonesGrid.SelectedRows[0].Cells[1].Value != null && PhonesGrid.SelectedRows[0].Cells[2].Value != null)
                {
                    int phone_number;
                    if (Int32.TryParse(PhonesGrid.SelectedRows[0].Cells[2].Value.ToString(), out phone_number))
                    {
                        Service.AddDict(new Phone
                        {
                            Name = PhonesGrid.SelectedRows[0].Cells[1].Value.ToString(),
                            Phone_Number = phone_number
                        });
                        LoadPhoneList();
                    }
                    else
                    {
                        MessageBox.Show("В номере телефона доступны только цифры");
                    }
                }
            }
        }

        private void UpdateButton_Click(object sender, EventArgs e)
        {
            if (PhonesGrid.SelectedRows.Count != 0)
            {
                if (PhonesGrid.SelectedRows != null && PhonesGrid.SelectedRows[0] != null &&
                    PhonesGrid.SelectedRows[0].Cells[1].Value != null && PhonesGrid.SelectedRows[0].Cells[2].Value != null)
                {
                    int phone_number;
                    if (Int32.TryParse(PhonesGrid.SelectedRows[0].Cells[2].Value.ToString(), out phone_number))
                    {
                        Service.UpdDict(new Phone
                        {
                            Id = int.Parse(PhonesGrid.SelectedRows[0].Cells[0].Value.ToString()),
                            Name = PhonesGrid.SelectedRows[0].Cells[1].Value.ToString(),
                            Phone_Number = phone_number
                        });
                        LoadPhoneList();
                    }
                    else
                    {
                        MessageBox.Show("В номере телефона доступны только цифры");
                    }
                }
            }
        }


        private void DeleteButton_Click(object sender, EventArgs e)
        {
            if (PhonesGrid.SelectedRows.Count != 0)
            {
                if (PhonesGrid.SelectedRows != null && PhonesGrid.SelectedRows[0] != null &&
                    PhonesGrid.SelectedRows[0].Cells[1].Value != null && PhonesGrid.SelectedRows[0].Cells[2].Value != null)
                {
                    int phone_number;
                    if (Int32.TryParse(PhonesGrid.SelectedRows[0].Cells[2].Value.ToString(), out phone_number))
                    {
                        Service.DelDict(new Phone
                        {
                            Id = int.Parse(PhonesGrid.SelectedRows[0].Cells[0].Value.ToString()),
                            Name = PhonesGrid.SelectedRows[0].Cells[1].Value.ToString(),
                            Phone_Number = Int32.Parse(PhonesGrid.SelectedRows[0].Cells[2].Value.ToString())
                        });
                        LoadPhoneList();
                    }
                    else
                    {
                        MessageBox.Show("В номере телефона доступны только цифры");
                    }
                }
            }
        }


        private void LoadPhoneList()
        {
            PhonesGrid.Rows.Clear();
            PhonesGrid.Columns.Clear();
            PhonesGrid.Columns.Add("Id", "Id");
            PhonesGrid.Columns.Add("Name", "Name");
            PhonesGrid.Columns.Add("Phone_Number", "Phone_Number");
            int rowNumber;
            foreach (var phone in Service.GetDict().ToList())
            {
                rowNumber = PhonesGrid.Rows.Add();
                PhonesGrid.Rows[rowNumber].Cells["Id"].Value = phone.Id;
                PhonesGrid.Rows[rowNumber].Cells[0].ReadOnly = true;
                PhonesGrid.Rows[rowNumber].Cells["Name"].Value = phone.Name;
                PhonesGrid.Rows[rowNumber].Cells["Phone_Number"].Value = phone.Phone_Number;
            }
        }
    }
}