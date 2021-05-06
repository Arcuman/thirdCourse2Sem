using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace lab3.Controllers
{
    public class ErrorController : Controller
    {
        // GET: Error
        public ActionResult Error()
        {
            Response.StatusCode = 404;
            ViewBag.url = Request.Url.ToString().Split(';')[1];
            ViewBag.method = Request.HttpMethod;
            return View();
        }
    }
}