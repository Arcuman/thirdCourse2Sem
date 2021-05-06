using System.Web.Mvc;

namespace Lab6.Controllers
{
    public class ErrorController : Controller
    {
        [ActionName("404")]
        public ActionResult Error404()
        {
            return View();
        }

    }
}