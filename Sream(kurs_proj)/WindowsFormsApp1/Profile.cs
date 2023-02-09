using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.OleDb;
using System.Windows.Forms;

namespace WindowsFormsApp1
{

    static class Profile_sender
    {
        public static string active_num, active_login;
        public static string[] active_lib;

        public static Dictionary<string, string> Log_Lib = new Dictionary<string, string>();
        public static Dictionary<string, string> Log_Pass = new Dictionary<string, string>();
        private static string DB = "Provider = Microsoft.Jet.OLEDB.4.0; Data Source = Sreamdb.mdb";
        private static OleDbConnection connection = new OleDbConnection(DB);
        
        public static void ProfilesDB()
        {
            Log_Lib.Clear();
            Log_Pass.Clear();
            OleDbConnection connection = new OleDbConnection(DB);

            connection.Open();

            string query = "SELECT Login, Pass, Lib FROM Profiles ORDER BY id";

            OleDbCommand command = new OleDbCommand(query, connection);

            OleDbDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                Log_Lib.Add(reader[0].ToString(), reader[2].ToString());
                Log_Pass.Add(reader[0].ToString(), reader[1].ToString());
            }

            reader.Close();
        }

        public static void ActivateLib()
        {
            foreach (var el in Log_Lib)
            {
                if (el.Key == active_login)
                {
                    active_lib = el.Value.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                }
            }
        }

    }
}
