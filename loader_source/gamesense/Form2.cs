using System;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace gamesense
{
    public partial class Form2 : Form
    {
        string HWID;
        // Vars
        string dll_link = "https://github.com/maj0r1koff/wasovski/raw/main/loader/wasovski.dll"; // Нажмите "Loader setup" для подробностей
        string hwid_link = "https://raw.githubusercontent.com/maj0r1koff/wasovski/main/loader/banned_hwid.txt"; // Нажмите "Loader setup" для подробностей (Ссылка на файл с хвидами)
        string dll_name = "wasovski_git"; // Название файла (dll) которое качаеться без .dll
        int time_to_wait = 45000; // Сколько ждать времени перед инжектом (в милисекундах) (дефолт - 30 секунд)

        // SETUP VAR
        bool setted_up = false; // Измените на true если вы закончили настройку loader'a
        // SETUP VAR

        public const int WM_NCLBUTTONDOWN = 0xA1;
        public const int HT_CAPTION = 0x2;
        [System.Runtime.InteropServices.DllImport("user32.dll")]
        public static extern int SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);
        [System.Runtime.InteropServices.DllImport("user32.dll")]
        public static extern bool ReleaseCapture();
        public Form2()
        {
            InitializeComponent();
            
        }

        private async void load_Click(object sender, EventArgs e)
        {
            // Основа замка по hwidу была взята с GitHub SimpleLoader

            WebClient wb = new WebClient();
            string access_list = wb.DownloadString(hwid_link);
            if (access_list.Contains(HWID))
            {
                MessageBox.Show("Banned HWID", "wasovski");
                
            }
            else
            {
                this.Hide();
                string mainpath = "C:\\" + dll_name + ".dll";
                wb.DownloadFile(dll_link, mainpath);

                Process.Start("steam://rungameid/730");
                await Task.Delay(time_to_wait);
                Process csgo = Process.GetProcessesByName("csgo").FirstOrDefault();
                Process[] csgo_array = Process.GetProcessesByName("csgo");
                if (csgo_array.Length != 0)
                {
                    // Инжект
                    injector.BasicInject.Inject(mainpath, "csgo");
                    Console.Read();
                    MessageBox.Show("Injected", "wasovski", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    csgo.WaitForExit();
                    // Delete cheat
                    if (File.Exists(mainpath))
                    {
                        File.Delete(mainpath);
                    }
                    await Task.Delay(10000);
                    Application.Exit();

                }
                Clipboard.SetText(HWID);
                MessageBox.Show("Copied HWID", "wasovski");
            }
        }

        private void exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            timer1.Start();
            HWID = System.Security.Principal.WindowsIdentity.GetCurrent().User.Value;
            ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls12 | SecurityProtocolType.Tls11 | SecurityProtocolType.Tls;
        }

        private void setup_Click(object sender, EventArgs e)
        {
            this.Hide();
            var form3 = new Form3();
            form3.Closed += (s, args) => this.Close();
            form3.Show();
        }

        private void Form2_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                ReleaseCapture();
                SendMessage(Handle, WM_NCLBUTTONDOWN, HT_CAPTION, 0);
            }
        }

        private void load_MouseDown(object sender, MouseEventArgs e)
        {
            load.ForeColor = Color.FromArgb(146, 189, 68);
        }

        private void load_MouseUp(object sender, MouseEventArgs e)
        {
            load.ForeColor = SystemColors.ControlLight;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Process[] ida64 = Process.GetProcessesByName("ida64");
            Process[] ida32 = Process.GetProcessesByName("ida32");
            Process[] ollydbg = Process.GetProcessesByName("ollydbg");
            Process[] ollydbg64 = Process.GetProcessesByName("ollydbg64");
            Process[] loaddll = Process.GetProcessesByName("loaddll");
            Process[] httpdebugger = Process.GetProcessesByName("httpdebugger");
            Process[] windowrenamer = Process.GetProcessesByName("windowrenamer");
            Process[] processhacker = Process.GetProcessesByName("processhacker");
            Process[] processhacker2 = Process.GetProcessesByName("Process Hacker");
            Process[] processhacker3 = Process.GetProcessesByName("ProcessHacker");
            Process[] HxD = Process.GetProcessesByName("HxD");
            Process[] parsecd = Process.GetProcessesByName("parsecd");
            Process[] ida = Process.GetProcessesByName("ida");
            Process[] dnSpy = Process.GetProcessesByName("dnSpy");
            if (ida64.Length != 0 || ida32.Length != 0 || ollydbg.Length != 0 || ollydbg64.Length != 0 || loaddll.Length != 0 || httpdebugger.Length != 0 || windowrenamer.Length != 0 || processhacker.Length != 0 || processhacker2.Length != 0 || processhacker3.Length != 0 || HxD.Length != 0 || ida.Length != 0 || parsecd.Length != 0 || dnSpy.Length != 0)
            {
                Application.Exit();
            }

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(HWID);
            MessageBox.Show("Copied HWID", "wasovski");
        }
    }
}
