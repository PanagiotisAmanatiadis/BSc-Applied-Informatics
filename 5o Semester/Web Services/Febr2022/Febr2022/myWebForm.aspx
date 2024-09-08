<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="myWebForm.aspx.cs" Inherits="Febr2022.myWebForm" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>

            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
            <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
            <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
            <br />

            <asp:Button ID="Button1" runat="server" Text="Button" OnClick="Button1_Click" />


        </div>
    </form>
</body>
</html>
