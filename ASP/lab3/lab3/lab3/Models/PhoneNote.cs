using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace lab3.Models
{
    public class PhoneNote
    {
        // ID записи
        public int Id { get; set; }
        // ФИО 
        public string Name { get; set; }
        // Телефон
        public string PhoneNumber { get; set; }
    }
}