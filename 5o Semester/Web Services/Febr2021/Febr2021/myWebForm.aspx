<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="myWebForm.aspx.cs" Inherits="Febr2021.myWebForm" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    
    <form id="form1" runat="server">
        <div>

            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>

            <br />
            <br />
            <asp:Button runat="server" Text="SQRT" OnClick="Unnamed1_Click"></asp:Button>
            <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
            <br />
            <br />
            <asp:Button runat="server" Text="Ceil" OnClick="Unnamed2_Click"></asp:Button>
            <asp:Label ID="Label2" runat="server" Text=""></asp:Label>


        </div>
    </form>
</body>
</html>
