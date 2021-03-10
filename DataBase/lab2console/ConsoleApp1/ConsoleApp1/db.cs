using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;
using ConsoleApp1.models;

namespace ConsoleApp1
{
    class DB
    {
        SqlConnection conn;
        public void openConnection(string connStr)
        {
            conn = new SqlConnection(connStr);
            conn.Open();
        }

        public void closeConnection()
        {
            conn.Close();
        }

        public void add_Product(Product product)
        {
            SqlCommand command = new SqlCommand("AddProduct", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            command.Parameters.Add("name", sqlDbType: SqlDbType.NVarChar).Value = product.Name;
            command.Parameters.Add("price", sqlDbType: SqlDbType.Decimal).Value = product.Price;
            command.Parameters.Add("count", sqlDbType: SqlDbType.NVarChar).Value = product.Quantity;
            command.ExecuteNonQuery();
        }

        public void drop_Product(Product product)
        {
            SqlCommand command = new SqlCommand("DeleteProduct", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            command.Parameters.Add("product_id", sqlDbType: SqlDbType.NVarChar).Value = product.ProductId;
            command.ExecuteNonQuery();
        }

        public void change_Product(Product product)
        {
            SqlCommand command = new SqlCommand("UpdateProduct", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            command.Parameters.Add("product_id", sqlDbType: SqlDbType.Int).Value = product.ProductId;
            command.Parameters.Add("name", sqlDbType: SqlDbType.NVarChar).Value = product.Name;
            command.Parameters.Add("price", sqlDbType: SqlDbType.Decimal).Value = product.Price;
            command.Parameters.Add("quantity", sqlDbType: SqlDbType.Int).Value = product.Quantity;
            command.ExecuteNonQuery();
        }

        // ----------------------------------------------------------------------------

        public void add_Customer(Customer customer)
        {
            using (
            SqlCommand command = new SqlCommand("AddCustomer", conn))
            {
                command.CommandType = CommandType.StoredProcedure;
                command.Parameters.Add("@first_name", sqlDbType: SqlDbType.NVarChar).Value = customer.FirstName;
                command.Parameters.Add("@last_name", sqlDbType: SqlDbType.NVarChar).Value = customer.LastName;
                command.Parameters.Add("@email", sqlDbType: SqlDbType.NVarChar).Value = customer.Email;
                command.Parameters.Add("@address", sqlDbType: SqlDbType.NVarChar).Value = customer.Addres;
                command.Parameters.Add("@city", sqlDbType: SqlDbType.NVarChar).Value = customer.City;
                command.ExecuteNonQuery();
            }
        }

        public void drop_Customer(Customer customer)
        {
            SqlCommand command = new SqlCommand("DeleteCustomerById", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            command.Parameters.Add("@customer_id", sqlDbType: SqlDbType.NVarChar).Value = customer.CustomID;
            command.ExecuteNonQuery();
        }

        public List<Customer> get_Customers()
        {
            List<Customer> customers = new List<Customer>();
            using (SqlCommand command = new SqlCommand("GetCustomers", conn))
            {
                command.CommandType = CommandType.StoredProcedure;
                var reader = command.ExecuteReader();
                if (reader.HasRows)
                {
                    while (reader.Read()) // построчно считываем данные
                    {
                        var customer = new Customer(Convert.ToInt32(reader["customer_id"]), (string)reader["first_name"], (string)reader["last_name"],
                            (string)reader["email"], (string)reader["address"], (string)reader["city"]);
                        customers.Add(customer);
                    }
                }
                reader.Close();

            }
            return customers;
        }

        public List<Product> get_Products()
        {
            List<Product> customers = new List<Product>();
            using (SqlCommand command = new SqlCommand("GetProducts", conn))
            {
                command.CommandType = CommandType.StoredProcedure;
                var reader = command.ExecuteReader();
                if (reader.HasRows)
                {
                    while (reader.Read()) // построчно считываем данные
                    {
                        var customer = new Product(Convert.ToInt32(reader["product_id"]), (string)reader["product_name"], Convert.ToInt32(reader["price"]),
                            Convert.ToInt32(reader["quantity"]));
                        customers.Add(customer);
                    }
                }
                reader.Close();

            }
            return customers;
        }

        public void change_Customer(Customer customer)
        {
            using (
            SqlCommand command = new SqlCommand("UpdateCustomer", conn))
            {
                command.CommandType = CommandType.StoredProcedure;
                command.Parameters.Add("@customer_id", sqlDbType: SqlDbType.Int).Value = customer.CustomID;
                command.Parameters.Add("@first_name", sqlDbType: SqlDbType.NVarChar).Value = customer.FirstName;
                command.Parameters.Add("@last_name", sqlDbType: SqlDbType.NVarChar).Value = customer.LastName;
                command.Parameters.Add("@email", sqlDbType: SqlDbType.NVarChar).Value = customer.Email;
                command.Parameters.Add("@address", sqlDbType: SqlDbType.NVarChar).Value = customer.Addres;
                command.Parameters.Add("@city", sqlDbType: SqlDbType.NVarChar).Value = customer.City;
                command.ExecuteNonQuery();
            }
        }

        public int getOrdersSum(DateTime start, DateTime end)
        {
            var sql = $"select SUM(total_price) from orders where order_date >= '{start}' and order_date < '{end}'";
            using (SqlCommand command = new SqlCommand(sql, conn))
            {
                var reader = command.ExecuteScalar();
                return Convert.ToInt32(reader);
            }
        }

        // ----------------------------------------------------------------------------
        public int add_Order(OrderItem[] products, Order order)
        {
            
            SqlCommand command = new SqlCommand("AddOrder", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            SqlParameter outputIdParam = new SqlParameter("@order_id", SqlDbType.Int)
            {
                Direction = ParameterDirection.Output
            };
            command.Parameters.Add(outputIdParam);
            command.Parameters.Add("@order_date", sqlDbType: SqlDbType.Date).Value = DateTime.Now.ToLocalTime();
            command.Parameters.Add("@required_date", sqlDbType: SqlDbType.Date).Value = order.RequiredDate;
            command.Parameters.Add("@customer_id", sqlDbType: SqlDbType.NVarChar).Value = order.CustomId;
            command.ExecuteNonQuery();

            for (int i = 0; i < products.Length; i++)
            {
                command = new SqlCommand("AddOrderItem", conn)
                {
                    CommandType = CommandType.StoredProcedure
                };
                command.Parameters.Add("@order_id", sqlDbType: SqlDbType.Int).Value = (int)outputIdParam.Value;
                command.Parameters.Add("@product_id", sqlDbType: SqlDbType.Int).Value = products[i].ProductId;
                command.Parameters.Add("@quantity", sqlDbType: SqlDbType.Int).Value = products[i].Quantity;
                command.ExecuteNonQuery();
            }
            return (int)outputIdParam.Value;
        }

    }
}
