using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_11.Models
{
    public class Client
    {
        public int Id { get; set; }
        public string Client_Name { get; set; }
        public string Phone_Number { get; set; }

        public virtual ICollection<Order> Orders { get; set; }
    }
}
