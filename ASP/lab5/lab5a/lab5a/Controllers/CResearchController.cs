using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace lab5a.Controllers
{
    public class CResearchController : Controller
    {
        [AcceptVerbs(HttpVerbs.Get | HttpVerbs.Post)]
        public string C01()
        {
            string body;
            using (StreamReader reader = new StreamReader(Request.InputStream))
            {
                body = reader.ReadToEnd();
            }
            return (Request.HttpMethod == "POST" ? $"body: {body}; " : "") + $"header: {Request.Headers.ToString()}; " + $"method: {Request.HttpMethod}; " + $"uri: {Request.Url.AbsoluteUri}; " + $"params: {Request.QueryString["param"]}; ";
        }

        [AcceptVerbs(HttpVerbs.Get | HttpVerbs.Post)]
        public string C02()
        {
            string body;

            using (StreamReader reader = new StreamReader(Request.InputStream))
            {
                body = reader.ReadToEnd();
            }
            return $"body: {body};" + $"header: {Request.Headers.ToString()};" + $"status: {HttpContext.Response.StatusCode.ToString()}";
        }
    }
}