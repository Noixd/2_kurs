using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb;

namespace WindowsFormsApp1
{
    public partial class login : Form
    {
        private static string DB = "Provider = Microsoft.Jet.OLEDB.4.0; Data Source = Sreamdb.mdb";
        private OleDbConnection connection = new OleDbConnection(DB);
                
        public login()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool authorization = false;
            Profile_sender.ProfilesDB();

            foreach (var element in Profile_sender.Log_Pass)
            {
                if (textBox1.Text == Profile_sender.active_login && textBox2.Text == Profile_sender.active_num)
                {
                    MessageBox.Show("You already login!", "Hey?");
                    Close();
                    break;
                }

                if (textBox1.Text == element.Key && textBox2.Text == element.Value)
                {
                    authorization = true;
                    break;
                }
                else
                {
                    authorization = false;
                }
            }

            if (authorization)
            {
                Profile_sender.active_login = textBox1.Text;
                Profile_sender.active_num = textBox2.Text;

                MessageBox.Show("Hello, " + textBox1.Text + "!", "Success!");

                Profile_sender.ActivateLib();

                Sream.ActiveForm.Activate();
                Close();
            }
            else
            {
                MessageBox.Show("Check Out!", "Incorrect!");
            }
            
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            connection.Open();
            string query = "INSERT INTO Profiles (Login, Pass) VALUES (@text1, @text2)";

            OleDbCommand command = new OleDbCommand(query, connection);

            command.Parameters.Add("@text1", OleDbType.VarChar).Value = textBox1.Text;
            command.Parameters.Add("@text2", OleDbType.VarChar).Value = textBox2.Text;

            command.ExecuteNonQuery();

            Profile_sender.active_login = textBox1.Text;
            Profile_sender.active_num = textBox2.Text;
            MessageBox.Show("Welcome, " + textBox1.Text + "!", "Success!");
            connection.Close();
            Close();
            Sream.ActiveForm.Activate();
        }

        private void login_Load(object sender, EventArgs e)
        {

        }
    }
}
