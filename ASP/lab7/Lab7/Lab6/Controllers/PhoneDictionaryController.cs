using System.Collections.Generic;
using System.Web.Http;
using Lab6.Models;

namespace Lab6.Controllers
{
    [Route("ts")]
    public class PhoneDictionaryController : ApiController
    {
        PhoneRepository phoneRepository;
        public PhoneDictionaryController()
        {
            phoneRepository = new PhoneRepository();
        }

        [HttpGet]
        public List<Phone> Get()
        {
            return (List<Phone>)phoneRepository.GetAllPhones();
        }

        [HttpPost]
        public Phone Post(Phone phone)
        {
            return phoneRepository.Add(phone);
        }

        [HttpPut]
        public Phone Put(Phone phone)
        {
            return phoneRepository.Update(phone);
        }

        [HttpDelete]
        public bool Delete(string id)
        {
            return phoneRepository.Remove(id);
        }

    }
}
