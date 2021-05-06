using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using lab4.Data;
using lab4.Models;

namespace lab4.Controllers
{
    public class DictController : Controller
    {
        private DBContext db = new DBContext();

        // GET: Dict
        public ActionResult Index()
        {
            return View(db.PhoneNotes.ToList());
        }

        // GET: Dict/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            PhoneNote phoneNote = db.PhoneNotes.Find(id);
            if (phoneNote == null)
            {
                return HttpNotFound();
            }
            return View(phoneNote);
        }

        // GET: Dict/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Dict/Create
        // Чтобы защититься от атак чрезмерной передачи данных, включите определенные свойства, для которых следует установить привязку. Дополнительные 
        // сведения см. в разделе https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "Id,Name,PhoneNumber")] PhoneNote phoneNote)
        {
            if (ModelState.IsValid)
            {
                db.PhoneNotes.Add(phoneNote);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(phoneNote);
        }

        // GET: Dict/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            PhoneNote phoneNote = db.PhoneNotes.Find(id);
            if (phoneNote == null)
            {
                return HttpNotFound();
            }
            return View(phoneNote);
        }

        // POST: Dict/Edit/5
        // Чтобы защититься от атак чрезмерной передачи данных, включите определенные свойства, для которых следует установить привязку. Дополнительные 
        // сведения см. в разделе https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "Id,Name,PhoneNumber")] PhoneNote phoneNote)
        {
            if (ModelState.IsValid)
            {
                db.Entry(phoneNote).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(phoneNote);
        }

        // GET: Dict/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            PhoneNote phoneNote = db.PhoneNotes.Find(id);
            if (phoneNote == null)
            {
                return HttpNotFound();
            }
            return View(phoneNote);
        }

        // POST: Dict/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            PhoneNote phoneNote = db.PhoneNotes.Find(id);
            db.PhoneNotes.Remove(phoneNote);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
