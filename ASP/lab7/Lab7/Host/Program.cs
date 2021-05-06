using System;
using System.ServiceModel;
using WcfServiceLibrary;

namespace Host
{
    class Program
    {
        static void Main(string[] args)
        {
            ServiceHost host = new ServiceHost(typeof(Service1));
            host.Open();
            Console.WriteLine("Host started");
            Console.ReadKey();
            host.Close();
        }
    }
}
