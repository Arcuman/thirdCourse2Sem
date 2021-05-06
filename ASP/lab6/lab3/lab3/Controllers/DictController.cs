using PhoneDictionary;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;

namespace lab3.Controllers
{
    public class DictController : Controller
    {
        IRepository<PhoneNote> db;

        public DictController(IRepository<PhoneNote> rep)
        {
            db = rep;
        }

        // GET: Dict
        public ActionResult Index()
        {
            return View(db.List());
        }

        // GET: Dict/Create
        public ActionResult Add()
        {
            return View();
        }

        // POST: Dict/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        public ActionResult Add([Bind(Include = "Id,Name,PhoneNumber")] PhoneNote phonebookRecord)
        {
                db.Create(phonebookRecord);
                return RedirectToAction("Index");
        }

        // GET: Dict/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            PhoneNote phonebookRecord = db.Find(id.Value);
            if (phonebookRecord == null)
            {
                return HttpNotFound();
            }
            return View(phonebookRecord);
        }

        // POST: Dict/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        public ActionResult Edit([Bind(Include = "Id,Name,PhoneNumber")] PhoneNote phonebookRecord)
        {
                db.Edit(phonebookRecord);
                return RedirectToAction("Index");
        }

        // GET: Dict/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            PhoneNote phonebookRecord = db.Find(id.Value);
            if (phonebookRecord == null)
            {
                return HttpNotFound();
            }
            return View(phonebookRecord);
        }

        // POST: Dict/Delete/5
        [HttpPost, ActionName("Delete")]
        public ActionResult DeleteConfirmed(int id)
        {
            db.Delete(id);
            return RedirectToAction("Index");
        }
    }
}
