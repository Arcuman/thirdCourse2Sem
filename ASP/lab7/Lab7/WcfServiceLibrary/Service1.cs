using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace WcfServiceLibrary
{
    // ПРИМЕЧАНИЕ. Команду "Переименовать" в меню "Рефакторинг" можно использовать для одновременного изменения имени класса "Service1" в коде и файле конфигурации.
    public class Service1 : IService1
    {
        private PhoneRepository phoneRepository;

        public Service1()
        {
            phoneRepository = new PhoneRepository();
        }

        public List<Phone> GetDict()
        {
            return (List<Phone>)phoneRepository.GetAllPhones();
        }

        public void AddDict(Phone phone)
        {
            phoneRepository.Add(phone);
        }

        public void UpdDict(Phone phone)
        {
            phoneRepository.Update(phone);
        }

        public bool DelDict(Phone person)
        {
            return phoneRepository.Remove(person.Id.ToString());
        }
    }
}

