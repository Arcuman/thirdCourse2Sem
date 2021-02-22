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
            string connStr = @"Data Source=DESKTOP-6U8VG1H ;Initial Catalog=Store;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False";
            DB db = new DB();
            db.openConnection(connStr);
            //Customer customer = new Customer("Anton", "Borisov", "wef@mail.ru", "Belorusskaya 21", "Mogilev");
            //db.add_Customer(customer);
            var customers = db.get_Customers();
            foreach (var customer in customers)
                Console.WriteLine(customer);
            db.closeConnection();
            Console.WriteLine("End");
        }
    }
}
