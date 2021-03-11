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
        private string path;
        private string json;
        private List<PhoneNote> phoneNoteList;

        public PhoneBookRepostiroy()
        {
            path = AppDomain.CurrentDomain.BaseDirectory + @"\App_Data\PhoneBook.json";
            json = File.ReadAllText(path);
            phoneNoteList = JsonConvert.DeserializeObject<List<PhoneNote>>(json) ?? new List<PhoneNote>();
        }

        public PhoneNote Create(PhoneNote phonebookRecord)
        {
            phoneNoteList.Sort((r1, r2) => r1.Id - r2.Id);
            var lastRecord = phoneNoteList.FindLast(r => true);
            if (lastRecord != null)
                phonebookRecord.Id = lastRecord.Id + 1;
            phoneNoteList.Add(phonebookRecord);
            File.WriteAllText(path, JsonConvert.SerializeObject(phoneNoteList));
            return phonebookRecord;
        }
        public PhoneNote Delete(int id)
        {
            var phonebookRecord = phoneNoteList.Find(r => r.Id == id);
            phoneNoteList.Remove(phonebookRecord);
            File.WriteAllText(path, JsonConvert.SerializeObject(phoneNoteList));
            return phonebookRecord;
        }
        public PhoneNote Edit(PhoneNote phonebookRecord)
        {
            var index = phoneNoteList.FindIndex(r => r.Id == phonebookRecord.Id);
            phoneNoteList[index] = phonebookRecord;
            File.WriteAllText(path, JsonConvert.SerializeObject(phoneNoteList));
            return phonebookRecord;
        }

        public PhoneNote Find(int id)
        {
            return phoneNoteList.Find(r => r.Id == id);
        }

        public IEnumerable<PhoneNote> List()
        {
            return phoneNoteList;
        }
    }
}