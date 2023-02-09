using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.OleDb;
using System.Windows.Forms;

namespace WindowsFormsApp1
{

    public static class Sender
    {
        public static string [] send_index = new string [1];
        public static int length = 0;

        public static void Resize_Arr()
        {
            length = send_index.Length;

            Array.Resize(ref send_index, length+1);

        }
    }
}
