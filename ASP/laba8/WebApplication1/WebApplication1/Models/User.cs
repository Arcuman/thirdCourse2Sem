using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace WebApplication1.Models
{
    public class User
    {
        /// <summary>
        /// User Id
        /// </summary>
        /// <example>1</example>
        public int Id { get; set; }

        /// <summary>
        /// Last Name
        /// </summary>
        /// <example>Borisov</example>
        [Required]
        public string LastName { get; set; }

        /// <summary>
        /// First Name
        /// </summary>
        /// <example>Anton</example>
        public string FirstName { get; set; }

        /// <summary>
        /// User e-mail
        /// </summary>
        /// <example>anton.b@nyblecraft.com</example>
        public string Email { get; set; }

        /// <summary>
        /// Password
        /// </summary>
        /// <example>password</example>
        public string Password { get; set; }

        /// <summary>
        /// active/passive
        /// </summary>
        /// <example>Active</example>
        public string Status { get; set; }

        /// <summary>
        /// admin/user
        /// </summary>
        /// <example>customer</example>
        public string Role { get; set; }
    }
}
