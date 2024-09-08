using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Febr2021
{
    public partial class myWebForm : System.Web.UI.Page
    {
        myService mS = new myService();
        protected void Page_Load(object sender, EventArgs e)
        {
           
        }


        protected void Unnamed1_Click(object sender, EventArgs e)
        {
            //To value apo to textBox einai string to metatrepoume se double afou h sunarthsh thelei double
            double value = Convert.ToDouble(TextBox1.Text);
            //To apotelesma prepei na graftei se morfi string afou to text pairnei times string ara to double to kanoume string
            Label1.Text = Convert.ToString(mS.getSQRT(value));
        }

        protected void Unnamed2_Click(object sender, EventArgs e)
        {
            double value = Convert.ToDouble(TextBox1.Text);
            Label2.Text = Convert.ToString(mS.getCeil(value));
        }
    }
}