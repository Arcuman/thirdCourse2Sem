using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1.models
{
    class Order
    {

        public Order(int orderId, int customId, int orderStatus, DateTime orderDate, DateTime requiredDate, DateTime shippedDate, int totalPrice)
        {
            OrderId = orderId;
            CustomId = customId;
            OrderStatus = orderStatus;
            OrderDate = orderDate;
            RequiredDate = requiredDate;
            ShippedDate = shippedDate;
            TotalPrice = totalPrice;
        }

        public Order(int customId, DateTime orderDate, DateTime requiredDate)
        {
            CustomId = customId;
            OrderDate = orderDate;
            RequiredDate = requiredDate;
        }

        public int OrderId { get; set; }
        public int CustomId { get; set; }
        public int OrderStatus { get; set; }
        public DateTime OrderDate { get; set; }
        public DateTime RequiredDate { get; set; }
        public DateTime ShippedDate { get; set; }
        public int TotalPrice { get; set; }

        public List<OrderItem> Products { get; set; } 
    }
}
