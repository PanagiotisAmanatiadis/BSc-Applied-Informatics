﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Febr2022
{
    public partial class myWebForm : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            myWebService mS =new myWebService();

            Label1.Text = mS.getString(TextBox1.Text, TextBox2.Text, TextBox3.Text);
        }
    }
}