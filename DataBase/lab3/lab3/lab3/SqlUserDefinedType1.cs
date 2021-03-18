using System;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Text.RegularExpressions;
using Microsoft.SqlServer.Server;
using System.IO;


[Serializable]
[SqlUserDefinedType(Format.UserDefined,
    MaxByteSize = -1)]
public struct CustomAddress : INullable, IBinarySerialize
{
    private string _address;

    public SqlString Address
    {
        get { return new SqlString(_address); }
        set
        {
            if (value == null)
            {
                _address = string.Empty;
                return;
            }

            string str = (string)value;

            if (Regex.IsMatch(str, @"^[A-Za-z0-9]+(?:\s[A-Za-z0-9'_-]+)+$"))
            {
                _address = str;
            }
            else
            {
                throw new ArgumentException("Address is not valid.");
            }
        }
    }

    public override string ToString()
    {
        return _address;
    }

    public bool IsNull
    {
        get { return string.IsNullOrEmpty(_address); }
    }

    public static CustomAddress Null
    {
        get
        {
            CustomAddress n = new CustomAddress();
            n._address = string.Empty;
            return n;
        }
    }

    public static CustomAddress Parse(SqlString s)
    {
        if (s.IsNull)
            return CustomAddress.Null;

        CustomAddress n = new CustomAddress();
        n.Address = s;

        return n;
    }

    public void Read(BinaryReader r)
    {
        _address = r.ReadString();
    }

    public void Write(BinaryWriter w)
    {
        w.Write(_address);
    }
}