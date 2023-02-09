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
    public partial class Cart : Form
    {
        private static string DB = "Provider = Microsoft.Jet.OLEDB.4.0; Data Source = Sreamdb.mdb";
        private OleDbConnection connection = new OleDbConnection(DB);
        public int index { get; set; }
        public Cart()
        {
            InitializeComponent();
            OpenDB();
            
        }

        void OpenDB()
        {
            OleDbConnection connection = new OleDbConnection(DB);

            connection.Open();

            listBox1.Items.Clear();

            for (int i = 0; i < Sender.send_index.Length; i++)
            {
                if (Sender.send_index[i] != null)
                {
                    string query = "SELECT GameName, Price FROM Store WHERE GameName = '" + Sender.send_index[i] + "'";

                    OleDbCommand command = new OleDbCommand(query, connection);

                    OleDbDataReader reader = command.ExecuteReader();

                    reader.Read();

                    listBox1.Items.Add(reader[0].ToString() + " \t" + reader[1].ToString());

                    reader.Close();
                }
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int sold_prev;
            bool correct = false;
            string inp = "", outp;

            foreach (var element in Profile_sender.Log_Pass)
            {
                
                if (textBox1.Text == element.Key && textBox2.Text == element.Value)
                {

                    correct = true;
                    break;
                }
                else
                {
                    correct = false;
                }

            }
            if (correct) {
                MessageBox.Show("Thank you for your purchase! \nHave a good game!");

                connection.Open();

                for (int i = 0; i < Sender.length; i++)
                {
                    if (Sender.send_index[i] != null)
                    {
                        string query_in = "UPDATE Store SET Sold = @text WHERE GameName = '" + Sender.send_index[i] + "'";
                        string query_out = "SELECT Sold FROM Store WHERE GameName = '" + Sender.send_index[i] + "'";
                        string query = "SELECT id FROM Store WHERE GameName = '" + Sender.send_index[i] + "'";

                        OleDbCommand command = new OleDbCommand(query_out, connection);
                        OleDbCommand command2 = new OleDbCommand(query_in, connection);
                        OleDbCommand command_inp = new OleDbCommand(query, connection);

                        OleDbDataReader reader = command_inp.ExecuteReader();

                        sold_prev = int.Parse(command.ExecuteScalar().ToString());

                        sold_prev++;

                        command2.Parameters.Add("@text", OleDbType.VarChar).Value = sold_prev;

                        command2.ExecuteNonQuery();

                        while (reader.Read())
                        {
                            inp += " " + reader[0];
                        }
                        reader.Close();
                        
                    }
                    else continue;
                }
                string query_lib_out = "SELECT Lib FROM Profiles WHERE Login = '" + Profile_sender.active_login + "'";
                string query_lib_in = "UPDATE Profiles SET Lib = @text WHERE Login = '"+ Profile_sender.active_login + "'";

                OleDbCommand command3 = new OleDbCommand(query_lib_out, connection);

                outp = command3.ExecuteScalar().ToString();

                OleDbCommand command4 = new OleDbCommand(query_lib_in, connection);

                outp += inp;

                command4.Parameters.Add("@text", OleDbType.VarChar).Value = outp;

                command4.ExecuteNonQuery();
                connection.Close();

                Array.Resize(ref Sender.send_index, 1);
                Sender.send_index[0] = null;
                Sender.length = 0;
                listBox1.Items.Clear();
                Close(); 
            }
            else
            {
                MessageBox.Show("Check Out!", "Incorrect!");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex == -1)
            {
                MessageBox.Show("Choose first", "Hey!");
            }
            else
            {
                Sender.send_index[listBox1.SelectedIndex] = "";
                listBox1.Items.Remove(listBox1.SelectedItem);
                Array.Resize(ref Sender.send_index, Sender.send_index.Length - 1);
            }
            
            
            if (listBox1.Items.Count == 0)
            {
                MessageBox.Show("Cart is Empty!");
                
                Sream.ActiveForm.Activate();
                Close();
            }
            
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Cart_Load(object sender, EventArgs e)
        {
            if (Profile_sender.active_login != null)
            {
                textBox1.Text = Profile_sender.active_login;
                textBox2.Text = Profile_sender.active_num;
            }
        }
    }
}
