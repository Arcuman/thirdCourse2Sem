using LAB_11.Contexts;
using LAB_11.Models;
using System;
using System.Linq;

namespace LAB_11
{
    class Program
    {
        static void Main(string[] args)
        {
            var context = new AppDbContext();
            var clients = context.Clients;

            Console.WriteLine("ALL");

            foreach (var client in clients)
            {
                Console.WriteLine($"Id: {client.Id} | Client_Name: {client.Client_Name} | Phone_Number: {client.Phone_Number}");
            }

            var newClient = new Client
            {
                Client_Name = "Example",
                Phone_Number = "+777"
            };
            clients.Add(newClient);
            context.SaveChanges();
            Console.WriteLine(newClient.Id);
            Console.WriteLine("AFTER INSERT");

            foreach (var client in clients)
            {
                Console.WriteLine($"Id: {client.Id} | Client_Name: {client.Client_Name} | Phone_Number: {client.Phone_Number}");
            }

            var deletedClient = clients.First(c => c.Client_Name.Equals("Example"));
            clients.Remove(deletedClient);
            context.SaveChanges();

            Console.WriteLine("AFTER DELETE");
            foreach (var client in clients)
            {
                Console.WriteLine($"Id: {client.Id} | Client_Name: {client.Client_Name} | Phone_Number: {client.Phone_Number}");
            }
        }
    }
}
