using System;
using System.Collections.Generic;

namespace Lab6.Models
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
