using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace lab5a.Controllers
{
    public class MResearchController : Controller
    {
        //ERROR
        public string MXX()
        {
            return "MXX";
        }

        [HttpGet]
        public string M01()
        {
            return "GET:M01";
        }

        [HttpGet]
        public string M02()
        {
            return "GET:M02";
        }

        [HttpGet]
        public string M03()
        {
            return "GET:M03";
        }


    }
}