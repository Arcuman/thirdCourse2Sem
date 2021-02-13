using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;

namespace Lab2
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

        public void add_Product(string Name, int Price, int Quantity)
        {
            SqlCommand command = new SqlCommand("AddProduct", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            command.Parameters.Add("name", sqlDbType: SqlDbType.NVarChar).Value = Name;
            command.Parameters.Add("price", sqlDbType: SqlDbType.Decimal).Value = Price;
            command.Parameters.Add("count", sqlDbType: SqlDbType.NVarChar).Value = Quantity;
            command.ExecuteNonQuery();
        }

        public void drop_Product(int id)
        {
            SqlCommand command = new SqlCommand("DeleteProduct", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            command.Parameters.Add("product_id", sqlDbType: SqlDbType.NVarChar).Value = id;
            command.ExecuteNonQuery();
        }

        public void change_Product(int id, string Name, int Price, int Quantity)
        {
            SqlCommand command = new SqlCommand("UpdateProduct", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            command.Parameters.Add("product_id", sqlDbType: SqlDbType.Int).Value = id;
            command.Parameters.Add("name", sqlDbType: SqlDbType.NVarChar).Value = Name;
            command.Parameters.Add("price", sqlDbType: SqlDbType.Decimal).Value = Price;
            command.Parameters.Add("quantity", sqlDbType: SqlDbType.Int).Value = Quantity;
            command.ExecuteNonQuery();
        }

        // ----------------------------------------------------------------------------

        public void add_Customer(string Fname, string Lname, string Email, string Address, string City)
        {
            SqlCommand command = new SqlCommand("AddCustomer", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            command.Parameters.Add("@first_name", sqlDbType: SqlDbType.NVarChar).Value = Fname;
            command.Parameters.Add("@last_name", sqlDbType: SqlDbType.NVarChar).Value = Lname;
            command.Parameters.Add("@email", sqlDbType: SqlDbType.NVarChar).Value = Email;
            command.Parameters.Add("@address", sqlDbType: SqlDbType.NVarChar).Value = Address;
            command.Parameters.Add("@city", sqlDbType: SqlDbType.NVarChar).Value = City;
            command.ExecuteNonQuery();
        }

        public void drop_Customer(int id)
        {
            SqlCommand command = new SqlCommand("DeleteCustomerById", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            command.Parameters.Add("@customer_id", sqlDbType: SqlDbType.NVarChar).Value = id;
            command.ExecuteNonQuery();
        }

        public void change_Customer(int id,string Fname, string Lname, string Email, string Address, string City)
        {
            SqlCommand command = new SqlCommand("UpdateCustomer", conn)
            {
                CommandType = CommandType.StoredProcedure
            };
            command.Parameters.Add("@customer_id", sqlDbType: SqlDbType.Int).Value = id;
            command.Parameters.Add("@first_name", sqlDbType: SqlDbType.NVarChar).Value = Fname;
            command.Parameters.Add("@last_name", sqlDbType: SqlDbType.NVarChar).Value = Lname;
            command.Parameters.Add("@email", sqlDbType: SqlDbType.NVarChar).Value = Email;
            command.Parameters.Add("@address", sqlDbType: SqlDbType.NVarChar).Value = Address;
            command.Parameters.Add("@city", sqlDbType: SqlDbType.NVarChar).Value = City;
            command.ExecuteNonQuery();
        }

        // ----------------------------------------------------------------------------

        public int add_Order(int CumId, string RequiredDate, string[] ProductIds, string[] Quantities)
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
            command.Parameters.Add("@required_date", sqlDbType: SqlDbType.Date).Value = DateTime.Parse(RequiredDate);
            command.Parameters.Add("@customer_id", sqlDbType: SqlDbType.NVarChar).Value = CumId;
            command.ExecuteNonQuery();

            
            for (int i =0; i < ProductIds.Length;i++)
            {
                command = new SqlCommand("AddOrderItem", conn)
                {
                    CommandType = CommandType.StoredProcedure
                };
                command.Parameters.Add("@order_id", sqlDbType: SqlDbType.Int).Value = (int)outputIdParam.Value;
                command.Parameters.Add("@product_id", sqlDbType: SqlDbType.Int).Value = Convert.ToInt32(ProductIds[i]);
                command.Parameters.Add("@quantity", sqlDbType: SqlDbType.Int).Value = Convert.ToInt32(Quantities[i]);
                command.ExecuteNonQuery();
            }
            return (int)outputIdParam.Value;
        }

            public void drop_Order(int id)
        {
            string sql = "delete from Order where Id=" + id;
            SqlCommand command = new SqlCommand(sql, conn);
            command.ExecuteNonQuery();
        }

        public void change_Order(int id, int Status, string ShippedDate)
        {
            
        }
    }
}
