using Lab6.Models;
using System.Collections.Generic;
using System.Web.Services;

namespace Lab6.Services
{
    /// <summary>
    /// Сводное описание для PhoneDictService
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // Чтобы разрешить вызывать веб-службу из скрипта с помощью ASP.NET AJAX, раскомментируйте следующую строку. 
    //[System.Web.Script.Services.ScriptService]
    public class PhoneDictService : System.Web.Services.WebService
    {

        private PhoneRepository phoneRepository;

        public PhoneDictService()
        {
            phoneRepository = new PhoneRepository();
        }

        [WebMethod]
        public string HelloWorld()
        {
            return "Привет всем!";
        }

        [WebMethod]
        public List<Phone> GetDict()
        {
            return (List<Phone>)phoneRepository.GetAllPhones();
        }

        [WebMethod]
        public void AddDict(Phone phone)
        {
            phoneRepository.Add(phone);
        }

        [WebMethod]
        public void UpdDict(Phone phone)
        {
            phoneRepository.Update(phone);
        }

        [WebMethod]
        public bool DelDict(Phone phone)
        {
            return phoneRepository.Remove(phone.Id.ToString());
        }
    }
}
