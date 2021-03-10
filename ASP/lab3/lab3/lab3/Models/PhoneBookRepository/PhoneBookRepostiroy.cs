using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;

namespace lab3.Models.PhoneBookRepository
{
    public class PhoneBookRepostiroy
    {
        public List<PhoneNote> getAll()
        {
            using (StreamReader r = new StreamReader("D:\\bstu\\thirdCourse2Sem\\ASP\\lab3\\lab3\\lab3\\App_Data\\PhoneBook.json"))
            {
                string json = r.ReadToEnd();
                List<PhoneNote> items = JsonConvert.DeserializeObject<List<PhoneNote>>(json);
                return items;
            }
        }

    }
}