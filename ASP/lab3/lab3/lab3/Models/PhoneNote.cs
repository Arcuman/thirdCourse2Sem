using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace lab3.Models
{
    public class PhoneNote
    {
        // ID записи
        public int Id { get; set; }
        // ФИО 
        [StringLength(50, MinimumLength = 3, ErrorMessage = "Длина имени должна быть больше 3 и меньше 50")]
        public string Name { get; set; }
        // Телефон
        [RegularExpression(@"^\+\d{8}$", ErrorMessage = "Неверный формат телефона")]
        public string PhoneNumber { get; set; }
    }
}