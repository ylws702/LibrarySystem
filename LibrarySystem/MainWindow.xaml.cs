﻿using System;
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
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Login(object sender, RoutedEventArgs e)
        {

        }
        [DllImport("IO.dll")]
        extern static bool RootLogin(String password);
        private void RootLoginButton_Click(object sender, RoutedEventArgs e)
        {
            if (RootLogin(RootPasswordBox.Password))
            {
                MessageBox.Show("Succeed!");
            }
            else
            {
                MessageBox.Show("failed!");
            }
        }
    }
}
