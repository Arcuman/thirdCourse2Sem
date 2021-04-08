using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace lab5b.Controllers
{
    [RoutePrefix("it")]
    public class MResearchController : Controller
    {
        // GET: MResearch
        public ActionResult Index()
        {
            return Content("GET:MResearch/Index");
        }

        [Route("{n:int}/{str}")]
        [HttpGet]
        public ActionResult M01B(int n, string str)
        {
            return Content($"GET:M01B/{n}/{str}");
        }

        [Route("{b:bool}/{letters:alpha}")]
        [AcceptVerbs("get", "post")]
        public ActionResult M02(bool b, string letters)
        {
            return Content($"{Request.HttpMethod}:M02/{b}/{letters}");
        }

        [Route("{f:float}/{str:length(2, 5)}")]
        [AcceptVerbs("get", "delete")]
        public ActionResult M03(float f, string str)
        {
            return Content($"{Request.HttpMethod}:M03/{f}/{str}");
        }

        [Route("{letters:length(3, 4)}/{n:range(100, 200)}")]
        [HttpPut]
        public ActionResult M04(string letters, int n)
        {
            return Content($"PUT:M04/{letters}/{n}");
        }

        [Route("{mail:regex(^\\w+@\\w+\\.\\w+$)}")]
        [HttpPost]
        public ActionResult M05(string mail)
        {
            return Content($"POST:M05/{mail}");
        }

    }
}