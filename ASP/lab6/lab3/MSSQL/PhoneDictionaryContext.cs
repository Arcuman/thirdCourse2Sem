using PhoneDictionary;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MSSQL
{
    class PhoneDictionaryContext : DbContext
    {
        public PhoneDictionaryContext() : base("name=PhoneDictionaryEntities")
        {
        }

        public virtual DbSet<PhoneNote> PhoneNotes { get; set; }
    }
}
