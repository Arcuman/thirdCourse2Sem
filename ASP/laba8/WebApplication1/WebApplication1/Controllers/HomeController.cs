using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using Swashbuckle.AspNetCore.Annotations;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using WebApplication1.Models;
using WebApplication1.Repositories;

namespace WebApplication1.Controllers
{
    [Produces("application/json")]
    [Route("api/Lera")]
    [ApiController]
    public class userController : Controller
    {
        private IUserRepository repository;

        public userController(IUserRepository repository)
        {
            this.repository = repository;
        }

        /// <summary>
        /// Get All Users
        /// </summary>
        /// <returns>User list</returns>
        [HttpGet]
        public async Task<IEnumerable<User>> GetAll()
        {
            return await repository.GetAll();
        }

        /// <summary>
        /// Get User by Id
        /// </summary>
        /// <param name="id">User Id</param>
        /// <response code="200">User is found</response>
        /// <response code="404">User is not found</response>
        /// <returns>User</returns>
        [HttpGet("{id}")]
        public async Task<User> Get(int id)
        {
            return await repository.Get(id);
        }

        /// <summary>
        /// Add User
        /// </summary>
        /// <param name="user"></param>
        /// <response code="200">User is added</response>
        /// <response code="400">User is added</response>
        /// <returns>User</returns>
        [HttpPost]
        public async Task<User> Add(User user)
        {
            var addedUser = repository.Create(user);
            if (addedUser == null)
            {
                Response.StatusCode = StatusCodes.Status400BadRequest;
            }

            await repository.SaveChanges();
            return addedUser;
        }

        /// <summary>
        /// Update User by Id
        /// </summary>
        /// <response code="200">User is updated</response>
        /// <response code="400">User is not updated</response>
        /// <param name="user"></param>
        /// <returns>User</returns>
        [HttpPut]
        public async Task<User> Update(User user)
        {
            var updateduser = repository.Update(user);
            if (updateduser == null)
            {
                Response.StatusCode = StatusCodes.Status400BadRequest;
            }

            await repository.SaveChanges();
            return updateduser;
        }

        /// <summary>
        /// Delete User by Id
        /// </summary>
        /// <response code="200">User is deleted</response>
        /// <response code="404">User is not found</response>
        /// <param name="id">User Id</param>
        /// <returns>User</returns>
        [HttpDelete("{id}")]
        public async Task<User> Delete(int id)
        {
            var deleteduser = repository.Delete(id);
            if (deleteduser == null)
            {
                Response.StatusCode = StatusCodes.Status404NotFound;
            }

            await repository.SaveChanges();
            return deleteduser;
        }
    }
}
