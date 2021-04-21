using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.UI;

namespace lab5b.Controllers
{
    public class CHResearchController : Controller
    {
        // GET: CHResearch
        public ActionResult Index()
        {
            return View();
        }
        static int x = 9;
        [OutputCache(Duration = 5, Location = OutputCacheLocation.ServerAndClient), HttpGet]
        public ActionResult AD()
        {
            x++;
            string t = DateTime.Now.ToLongTimeString();
            return Content($"GET:/AD:{t} \n {x}");
        }

        [OutputCache(Duration = 7, VaryByParam = "x;y"), HttpPost]
        public ActionResult AP(string x, string y)
        {
            string t = DateTime.Now.ToLongTimeString();
            return Content($"POST:/AP:{t}:{x}:{y}");
        }
    }
}