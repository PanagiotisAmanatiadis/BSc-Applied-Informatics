using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace Febr2022
{
    /// <summary>
    /// Summary description for myWebService
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class myWebService : System.Web.Services.WebService
    {

        [WebMethod]
        public string getString(string str1,string str2,string str3)
        {
            return str1.Replace(str2, str3);
        }
    }
}
