using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WcfServiceLibrary
{
    public interface IRepository<T> : IDisposable where T : class
    {
        IEnumerable<T> GetAllPhones();
        T Get(int ID);
        T Add(T item);
        bool Remove(string id);
        T Update(T item);
    }
}
