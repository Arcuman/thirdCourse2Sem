using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1.models
{
    class Product
    {
        public Product(string name, int price, int quantity)
        {
            Name = name;
            Price = price;
            Quantity = quantity;
        }
        public Product(int product_id, string name, int price, int quantity)
        {
            ProductId = product_id;
            Name = name;
            Price = price;
            Quantity = quantity;
        }

        public int ProductId { get; set; }

        public string Name { get; set; } 

        public int Price { get; set; }

        public int Quantity { get; set; }

        public override string ToString()
        {
            return ProductId + " " + Name + " " + Price + " " + Quantity;
        }
    }
}
