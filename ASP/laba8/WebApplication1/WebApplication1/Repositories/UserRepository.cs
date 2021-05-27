using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using WebApplication1.Context;
using WebApplication1.Models;

namespace WebApplication1.Repositories
{
    public class UserRepository : IUserRepository
    {
        private readonly UserDBContext context;

        public UserRepository(UserDBContext context)
        {
            this.context = context;
        }

        public async Task<IEnumerable<User>> GetAll()
        {
            return await context.Users.ToListAsync();
        }

        public async Task<User> Get(int id)
        {
            return await context.Users.FindAsync(id);
        }

        public User Create(User phonebook)
        {
            return context.Users.Add(phonebook).Entity;
        }

        public User Update(User phonebook)
        {
            return context.Users.Update(phonebook).Entity;
        }

        public User Delete(int id)
        {
            User phonebook = context.Users.Find(id);
            if (phonebook != null)
            {
                return context.Users.Remove(phonebook).Entity;
            }

            return phonebook;
        }

        public async Task SaveChanges()
        {
            await context.SaveChangesAsync();
        }
    }
}
