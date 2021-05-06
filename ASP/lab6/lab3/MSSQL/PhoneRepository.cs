using PhoneDictionary;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MSSQL
{
    public sealed class PhoneRepository : IRepository<PhoneNote>
    {
        PhoneDictionaryContext db = new PhoneDictionaryContext();
        public PhoneNote Create(PhoneNote item)
        {
            db.PhoneNotes.Add(item);
            db.SaveChanges();
            return item;
        }

        public PhoneNote Delete(int id)
        {
            PhoneNote phoneNote = db.PhoneNotes.Find(id);
            db.PhoneNotes.Remove(phoneNote);
            db.SaveChanges();
            return phoneNote;
        }

        public PhoneNote Edit(PhoneNote item)
        {
            db.Entry(item).State = EntityState.Modified;
            db.SaveChanges();
            return item;
        }

        public PhoneNote Find(int id)
        {
            PhoneNote phoneNote = db.PhoneNotes.Find(id);
            return phoneNote;
        }

        public IEnumerable<PhoneNote> List()
        {
            return db.PhoneNotes.ToList();
        }
    }
}
