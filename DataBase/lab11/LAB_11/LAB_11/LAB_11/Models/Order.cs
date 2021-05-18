using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_11.Models
{
    public class Order
    {
        public int Id { get; set; }
        public DateTime Order_Date { get; set; }
        public DateTime Provision_Date { get; set; }
        public int ClientId { get; set; }
        public int ProductId { get; set; }

        public virtual Client Client { get; set; }
        public virtual Product Product { get; set; }
    }
}
