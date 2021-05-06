using System.Runtime.Serialization;

namespace WcfServiceLibrary
{
    public class Phone
    {
        [DataMember]
        public int Id { get; set; }
        [DataMember]
        public string Name { get; set; }
        [DataMember]
        public int Phone_Number { get; set; }
    }
}
