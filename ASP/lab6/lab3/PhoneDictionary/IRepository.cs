using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PhoneDictionary
{
    public interface IRepository<T> where T : class
    {
        IEnumerable<T> List();
        T Find(int ID);
        T Create(T item);
        T Delete(int item);
        T Edit(T item);
    }
}
