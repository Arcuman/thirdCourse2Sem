using System;
using System.Web.Mvc;

namespace Lab6.Controllers
{
    public class DictController : Controller
    {
        [HttpGet]
        public ContentResult Index()
        {
            return Content(
                System.IO.File.ReadAllText(@"D:\bstu\thirdCourse2Sem\ASP\lab7\Lab7\Lab6\Views\Dict\index.html"),"text/html");
        }
    }
}