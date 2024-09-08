using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace Febr2021
{
    /// <summary>
    /// Summary description for myService
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class myService : System.Web.Services.WebService
    {

        [WebMethod]
        public double getSQRT(double number)
        {
            return Math.Sqrt(number);
        }


        public double getCeil(double number)
        {
            return Math.Ceiling(number);

        }


    }
}
