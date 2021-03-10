using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1.models
{
    class Customer
    {
        public Customer(string firstName, string lastName, string email, string addres, string city)
        {
            FirstName = firstName;
            LastName = lastName;
            Email = email;
            Addres = addres;
            City = city;
        }
        public Customer(int customer_id, string firstName, string lastName, string email, string addres, string city)
        {
            CustomID = customer_id;
            FirstName = firstName;
            LastName = lastName;
            Email = email;
            Addres = addres;
            City = city;
        }

        public int CustomID { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Email { get; set; }
        public string Addres { get; set; }
        public string City { get; set; }

        public override string ToString()
        {
            return FirstName + " " + LastName  + " " + Email + " " + Addres + " " + City;
        }
    }
}
