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
    public partial class Sream : Form
    {
        public string index;
        public Dictionary<string, string> id_game = new Dictionary<string, string>();
        private static string DB = "Provider = Microsoft.Jet.OLEDB.4.0; Data Source = Sreamdb.mdb";
        private OleDbConnection connection = new OleDbConnection(DB);
                

        public Sream()
        {
            InitializeComponent();
            OpenDB();
        }

        void OpenDB()
        {
            OleDbConnection connection = new OleDbConnection(DB);
            
            connection.Open();

            string query = "SELECT id, GameName, Price FROM Store ORDER BY id";

            OleDbCommand command = new OleDbCommand(query, connection);

            OleDbDataReader reader = command.ExecuteReader();

            listBox1.Items.Clear();
            id_game.Clear();

            while(reader.Read())
            {
                id_game.Add(reader[0].ToString(), reader[1].ToString());
                listBox1.Items.Add(reader[1].ToString());
            }

            WriteDescription("Outer Wilds");

            reader.Close();
        }

        void WriteDescription (string index)
        {
            connection.Open();

            string query = "SELECT GameName, Price, Description, Image FROM Store WHERE GameName = '" + index + "'";

            OleDbCommand command = new OleDbCommand(query, connection);

            OleDbDataReader reader = command.ExecuteReader();

            reader.Read();
            label1.Text = reader[0].ToString();

            label3.Text = reader[1].ToString() + "$";

            label2.Text = reader[2].ToString();

            pictureBox1.ImageLocation = reader[3].ToString();

            connection.Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Store_Click(object sender, EventArgs e)
        {
            OpenDB();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Profile_sender.ProfilesDB();
            Profile_sender.ActivateLib();
            listBox1.Items.Clear();

            if (Profile_sender.active_login != null)
            {
                foreach (var el in id_game)
                {
                    for (int i = 0; i < Profile_sender.active_lib.Length; i++)
                    {
                        if (el.Key == Profile_sender.active_lib[i])
                        {
                            listBox1.Items.Add(el.Value);
                        }
                    }
                }
            }
            else 
            {
                OpenDB();
                MessageBox.Show("Login first", "This will not work"); 
            }
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void flowLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void обновитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenDB();
        }

        private void label1_Click(object sender, EventArgs e)
        {
            
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (Profile_sender.active_num == null)
            {
                MessageBox.Show("Login first", "This will not work");
            }
            else 
            {
                if (Sender.send_index.Length == 1)
                {
                    MessageBox.Show("Cart is Empty!");
                }
                else
                {
                    Cart cart = new Cart();
                    cart.Show();
                } 
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(index == null) { index = "Outer Wilds"; }
            
            Sender.send_index[Sender.length] = index;
            button3.Text = "Cart (" + ++Sender.length + ")"; 
            Sender.Resize_Arr();
        }

        private void системаToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged_1(object sender, EventArgs e)
        {
            index = listBox1.SelectedItem.ToString();
            
            WriteDescription(index);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            listBox1.Sorted = true;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Sream_FormClosing(object sender, FormClosingEventArgs e)
        {
            connection.Close();
        }

        private void label4_Click(object sender, EventArgs e)
        {
            login log = new login();
            log.Show();
        }

        private void statToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string val = "";

            connection.Open();
           
            string query = "SELECT GameName, Sold FROM Store ORDER BY id";
            OleDbCommand command = new OleDbCommand(query, connection);

            OleDbDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                val += reader[0].ToString() + " " + reader[1].ToString() + "\n";
            }    

            MessageBox.Show(val, "Number of copies sold");
            
        }

        private void закрытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            About about = new About();
            about.Show();
        }

        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Help.ShowHelp(null, "Help.chm");
        }

        private void splitContainer1_Panel2_EnabledChanged(object sender, EventArgs e)
        {

        }

        private void Sream_Activated(object sender, EventArgs e)
        {
            if (Profile_sender.active_login == null) { }
            else
            {
                label4.Text = Profile_sender.active_login;
            }
            button3.Text = "Cart (" + Sender.length.ToString() + ")";
        }

        private void button3_Enter(object sender, EventArgs e)
        {
            button3.Text = "Cart (" + Sender.length.ToString() + ")";
        }
    }
}
