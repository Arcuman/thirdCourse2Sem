using System;
using System.Web;

namespace BAA_Lab1
{
    public class IISHandler3 : IHttpHandler
    {
        /// <summary>
        /// Вам потребуется настроить этот обработчик в файле Web.config вашего 
        /// веб-сайта и зарегистрировать его с помощью IIS, чтобы затем воспользоваться им.
        /// см. на этой странице: https://go.microsoft.com/?linkid=8101007
        /// </summary>
        #region Члены IHttpHandler

        public bool IsReusable
        {
            // Верните значение false в том случае, если ваш управляемый обработчик не может быть повторно использован для другого запроса.
            // Обычно значение false соответствует случаю, когда некоторые данные о состоянии сохранены по запросу.
            get { return true; }
        }

        public void ProcessRequest(HttpContext context)
        {
            var parmA = context.Request.Form.Get("ParmA");
            var parmB = context.Request.Form.Get("ParmB");
            var res = context.Response;
            res.ContentType = "text/plain";
            res.Write("PUT-HTTP-BAA: ParmA= " + parmA + ", ParmB= " + parmB);

        }

        #endregion
    }
}
