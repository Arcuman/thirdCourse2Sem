using System;
using System.Data;
using System.Windows;
using System.Data.SqlClient;

namespace Lab2
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        string connStr = @"Data Source=DESKTOP-991U2T1\SQLEXPRESS;Initial Catalog=Store;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False";
        DataTable Products = new DataTable();
        DataTable Order = new DataTable();
        DataTable OrderItems = new DataTable();
        DataTable Customer = new DataTable();

        private void addProduct_Click(object sender, RoutedEventArgs e)
        {
            string Name = textBoxProductName.Text;
            int Price = Convert.ToInt32(textBoxPrice.Text);
            int Quantity = Convert.ToInt32(textBoxQuantity.Text);

            if (Name.Length == 0)
            {
                MessageBox.Show("Проверьте данные");
            }
            else
            {
                DB db = new DB();
                db.openConnection(connStr);
                db.add_Product(Name, Price, Quantity);
                MessageBox.Show("Выполнено !!!");
                db.closeConnection();
            }
        }

        private void dropProduct_Click(object sender, RoutedEventArgs e)
        {
            int id = Convert.ToInt32(textBoxId.Text);

                DB db = new DB();
                db.openConnection(connStr);
                db.drop_Product(id);
                MessageBox.Show("Выполнено !!!");
                db.closeConnection();
        }

        private void changeProduct_Click(object sender, RoutedEventArgs e)
        {
            string Name = textBoxProductName.Text;
            int Price = Convert.ToInt32(textBoxPrice.Text);
            int Quantity = Convert.ToInt32(textBoxQuantity.Text);
            int id = Convert.ToInt32(textBoxId.Text);

            if (Name.Length == 0)
            {
                MessageBox.Show("Проверьте данные");
            }
            else
            {
                DB db = new DB();
                db.openConnection(connStr);
                db.change_Product(id, Name, Price, Quantity);
                MessageBox.Show("Выполнено !!!");
                db.closeConnection();
            }
        }

        private void allProducts_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string sqlExpression = "GetProducts";

                using (SqlConnection connection = new SqlConnection(connStr))
                {
                    connection.Open();
                    SqlDataAdapter command = new SqlDataAdapter(sqlExpression, connection);
                    Products.Clear();
                    command.Fill(Products);
                    usersGrid.ItemsSource = Products.DefaultView;
                    MessageBox.Show("Выполнено !!!");
                    connection.Close();
                }
            }
            catch
            {
                MessageBox.Show("Ошибка запроса");
            }
        }
        //--------------------------------------------------------------------------------------------------------------------

        private void addCustomer_Click(object sender, RoutedEventArgs e)
        {
            string Fname = textBoxCFName.Text;
            string Lname = textBoxCLName.Text;
            string Email = textBoxEmail.Text;
            string Address = textBoxAddress.Text;
            string City = textBoxCity.Text;

            if (Fname.Length == 0 || Lname.Length == 0)
            {
                MessageBox.Show("Проверьте данные");
            }
            else
            {
                DB db = new DB();
                db.openConnection(connStr);
                db.add_Customer(Fname, Lname, Email, Address, City);
                MessageBox.Show("Выполнено !!!");
                db.closeConnection();
            }
        }

        private void dropCustomer_Click(object sender, RoutedEventArgs e)
        {
            int id = Convert.ToInt32(textBoxId1.Text);

            DB db = new DB();
            db.openConnection(connStr);
            db.drop_Customer(id);
            MessageBox.Show("Выполнено !!!");
            db.closeConnection();
        }

        private void changeCustomer_Click(object sender, RoutedEventArgs e)
        {
            int id = Convert.ToInt32(textBoxId1.Text);
            string Fname = textBoxCFName.Text;
            string Lname = textBoxCLName.Text;
            string Email = textBoxEmail.Text;
            string Address = textBoxAddress.Text;
            string City = textBoxCity.Text;


            if (Fname.Length == 0 || Lname.Length == 0)
            {
                MessageBox.Show("Проверьте данные");
            }
            else
            {
                DB db = new DB();
                db.openConnection(connStr);
                db.change_Customer(id, Fname, Lname, Email, Address, City);
                MessageBox.Show("Выполнено !!!");
                db.closeConnection();
            }
        }
        private void allCustomers_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string sqlExpression = "GetCustomers";

                using (SqlConnection connection = new SqlConnection(connStr))
                {
                    connection.Open();
                    SqlDataAdapter command = new SqlDataAdapter(sqlExpression, connection);
                    Customer.Clear();
                    command.Fill(Customer);
                    CustomerGrid.ItemsSource = Customer.DefaultView;
                    MessageBox.Show("Выполнено !!!");
                    connection.Close();
                }
            }
            catch
            {
                MessageBox.Show("Ошибка запроса");
            }
        }
        //--------------------------------------------------------------------------------------------------------------------

        private void addOrder_Click(object sender, RoutedEventArgs e)
        {
            string ProductIds = textProductIds.Text;
            string Quantity = textQuantity.Text;
            string[] ProductArr = ProductIds.Split(' ');
            string[] Quantities = ProductIds.Split(' ');
            string RequiredData = textBoxRequiredDate.Text;
            int CumId = Convert.ToInt32(textBoxCumId.Text);
            DB db = new DB();
            db.openConnection(connStr);
            MessageBox.Show(db.add_Order(CumId, RequiredData, ProductArr, Quantities).ToString());
            db.closeConnection();
        }

        private void dropOrder_Click(object sender, RoutedEventArgs e)
        {
            int id = Convert.ToInt32(textBoxId2.Text);

            DB db = new DB();
            db.openConnection(connStr);
            db.drop_Order(id);
            MessageBox.Show("Выполнено !!!");
            db.closeConnection();
        }

        private void changeOrder_Click(object sender, RoutedEventArgs e)
        {
            string OrderDate = textBoxOrderDate.Text;
            string RequiredDate = textBoxRequiredDate.Text;
            string ShippedDate = textShippedDate.Text;
            int Status = Convert.ToInt32(textBoxStatus.Text);
            int CumId = Convert.ToInt32(textBoxCumId.Text);
            int id = Convert.ToInt32(textBoxId2.Text);

            if (OrderDate.Length == 0 || RequiredDate.Length == 0)
            {
                MessageBox.Show("Проверьте данные");
            }
            else
            {
                DB db = new DB();
                db.openConnection(connStr);
                db.change_Order(id, Status, ShippedDate);
                MessageBox.Show("Выполнено !!!");
                db.closeConnection();
            }
        }
        private void allOrders_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string sqlExpression = "GetOrders";

                using (SqlConnection connection = new SqlConnection(connStr))
                {
                    connection.Open();
                    SqlDataAdapter command = new SqlDataAdapter(sqlExpression, connection);
                    Order.Clear();
                    command.Fill(Order);
                    OrderGrid.ItemsSource = Order.DefaultView;
                    MessageBox.Show("Выполнено !!!");
                    connection.Close();
                }
            }
            catch
            {
                MessageBox.Show("Ошибка запроса");
            }
        }
        private void allOrderItems_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string sqlExpression = "GetOrderItems";

                using (SqlConnection connection = new SqlConnection(connStr))
                {
                    connection.Open();
                    SqlDataAdapter command = new SqlDataAdapter(sqlExpression, connection);
                    OrderItems.Clear();
                    command.Fill(OrderItems);
                    OrderItemsGrid.ItemsSource = OrderItems.DefaultView;
                    MessageBox.Show("Выполнено !!!");
                    connection.Close();
                }
            }
            catch
            {
                MessageBox.Show("Ошибка запроса");
            }
        }
    }
}
