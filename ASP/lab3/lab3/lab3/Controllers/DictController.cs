using lab3.Models;
using lab3.Models.PhoneBookRepository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace lab3.Controllers
{
    public class DictController : Controller
    {
        PhoneBookRepostiroy db = new PhoneBookRepostiroy();
        public ActionResult Index()
        {
            IEnumerable<PhoneNote> phoneBook = db.getAll();
            ViewBag.PhoneBook = phoneBook;
            return View();
        }

        [HttpGet]
        public ActionResult Add(int id)
        {
            ViewBag.PhoneId = id;
            return View();
        }

        [HttpPost]
        public string AddSave()
        {
            return "Спасибо";
        }

        [HttpGet]
        public ActionResult Update(int id)
        {
            ViewBag.PhoneId = id;
            return View();
        }

        [HttpPut]
        public string UpdateSave()
        {
            return "Спасибо";
        }
    }
}
