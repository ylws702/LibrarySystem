using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace LibrarySystem
{
    using ID = UInt64;
    /// <summary>
    /// RootWindow.xaml 的交互逻辑
    /// </summary>
    public partial class RootWindow : Window
    {
        public RootWindow()
        {
            InitializeComponent();
        }
        protected override void OnKeyDown(KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                TraversalRequest request = new TraversalRequest(FocusNavigationDirection.Next);
                if (Keyboard.FocusedElement is UIElement elementWithFocus)
                {
                    elementWithFocus.MoveFocus(request);
                }
                e.Handled = true;
            }
            base.OnKeyDown(e);
        }
        [DllImport("IO.dll")]
        extern static bool RootLogin(string password);
        public RootWindow(string password)
        {
            InitializeComponent();
            if (RootLogin(password))
            {
                MessageBox.Show("系统管理员，欢迎使用图书管理系统!");
            }
            else
            {
                MessageBox.Show("出现错误!");
            }
        }
        [DllImport("IO.dll")]
        extern static bool ChangeRootPassword(string oldpw, string newpw);
        private void ChangePasswordButton_Click(object sender, RoutedEventArgs e)
        {
            if (0 == OldPasswordBox.Password.Length)
            {
                MessageBox.Show("请输入原密码！");
                return;
            }
            if (0 == NewPasswordBox.Password.Length)
            {
                MessageBox.Show("请输入新密码！");
                return;
            }
            if (0 == NewPasswordBox2.Password.Length)
            {
                MessageBox.Show("请输入密码确认！");
                return;
            }
            if (NewPasswordBox.Password != NewPasswordBox2.Password)
            {
                MessageBox.Show("新密码与密码确认不一致！");
                return;
            }
            string oldpw = OldPasswordBox.Password;
            string newpw = NewPasswordBox.Password;
            if (ChangeRootPassword(oldpw, newpw))
            {
                MessageBox.Show("修改成功！");
                OldPasswordBox.Clear();
                NewPasswordBox.Clear();
                NewPasswordBox2.Clear();
            }
            else
            {
                MessageBox.Show("修改失败！");
            }
        }
        
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            MessageBox.Show("谢谢使用！");
            MainWindow mainWindow = new MainWindow();
            mainWindow.Show();
        }

        [DllImport("IO.dll")]
        extern static ID AddAdmin(string name, string password);
        private void AddAdminButton_Click(object sender, RoutedEventArgs e)
        {
            string name = NewAdminTextBox.Text;
            string password = NewAdminPasswordBox.Password;
            if (0 == name.Length)
            {
                MessageBox.Show("请输入用户名！");
                return;
            }
            if (0 == password.Length)
            {
                MessageBox.Show("请输入用户名！");
                return;
            }
            ID id=AddAdmin(name, password);
            if (0==id)
            {
                MessageBox.Show("修改失败！");
            }
            else
            {
                StringBuilder msg=new StringBuilder();
                msg.AppendLine("成功保存修改!");
                msg.AppendLine("已成功添加管理员:");
                msg.AppendLine(name);
                msg.AppendLine();
                msg.AppendLine("ID:");
                msg.AppendLine(id.ToString());
                MessageBox.Show(msg.ToString(), "添加管理员");
                NewAdminTextBox.Clear();
                NewAdminPasswordBox.Clear();
            }
        }
    }
}
