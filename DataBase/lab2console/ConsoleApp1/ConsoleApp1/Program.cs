using ConsoleApp1.models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {

        static void Main(string[] args)
        {
            string connStr = @"Data Source=DESKTOP-IMVVJS9\SQLEXPRESS;Initial Catalog=Store;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False";
            DB db = new DB();
            db.openConnection(connStr);
            Console.WriteLine("ADD CUSTOMER");
            Customer addCustomer = new Customer("Anton", "Borisov", "wef@mail.ru", "Belorusskaya 21", "Mogilev");
            db.add_Customer(addCustomer);
            Customer changeCUstomer = null;
            //get customers
            var customers = db.get_Customers();
            Console.WriteLine("GET CUSTOMERS");
            foreach (var customer in customers)
            {
                changeCUstomer = customer;
                Console.WriteLine(customer);
            }
            changeCUstomer.Email = "test@mail.co";
            Console.WriteLine("/////////////////////////////////");
            Console.WriteLine("CHANGE CUSTOMER");
            //get customers
            db.change_Customer(changeCUstomer);
            customers = db.get_Customers();
            Console.WriteLine("GET CUSTOMERS");
            foreach (var customer in customers)
            {
                Console.WriteLine(customer);
            }
            Console.WriteLine("ADD PRODUCT");
            Product addProduct = new Product("Table", 1000, 5);
            db.add_Product(addProduct);
            var products = db.get_Products();
            Console.WriteLine("GET PRODUCTS");
            Product addToOrderProduct = null;
            foreach (var product in products)
            {
                addToOrderProduct = product;
                Console.WriteLine(product);
            }

            OrderItem orderItem1 = new OrderItem(addToOrderProduct.ProductId,1);
            Order order = new Order(changeCUstomer.CustomID, DateTime.Now, DateTime.Now);
            db.add_Order(new OrderItem[] { orderItem1 }, order);
            Console.WriteLine(db.getOrdersSum(DateTime.Parse("2020-01-01"), DateTime.Parse("2022-01-01")));
            db.closeConnection();
            Console.WriteLine("End");
            Console.ReadKey();
        }
    }
}
