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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace LibrarySystem
{
    using ID = UInt64;
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
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
        extern static bool AdminLogin(ID id, string name, string password);
        private void AdminLoginButton_Click(object sender, RoutedEventArgs e)
        {
            if (0 == AdminIDTextBox.Text.Length)
            {
                MessageBox.Show("请输入编号!");
                return;
            }
            ID id = Convert.ToUInt64(AdminIDTextBox.Text);
            string name=AdminNameTextBox.Text;
            string password=AdminPasswordBox.Password;
            if (0 == name.Length)
            {
                MessageBox.Show("请输入用户名!");
                return;
            }
            if (0 == password.Length)
            {
                MessageBox.Show("请输入密码!");
                return;
            }
            if (AdminLogin(id,name,password))
            {
                MessageBox.Show("Succeed!");
            }
            else
            {
                MessageBox.Show("密码错误!");
            }
        }
        [DllImport("IO.dll")]
        extern static bool RootLogin(string password);
        private void RootLoginButton_Click(object sender, RoutedEventArgs e)
        {
            if (RootLogin(RootPasswordBox.Password))
            {
                RootWindow rootWindow = new RootWindow(RootPasswordBox.Password);
                rootWindow.Show();
                this.Close();
            }
            else
            {
                MessageBox.Show("密码错误!");
            }
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            //MessageBox.Show("谢谢使用!");
        }
    }
}
