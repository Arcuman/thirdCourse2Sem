using System;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using Microsoft.SqlServer.Server;

public partial class StoredProcedures
{
    [Microsoft.SqlServer.Server.SqlProcedure]
    public static void SumOrderDate (SqlDateTime StartDate, SqlDateTime EndDate)
    {
        using (SqlConnection con = new SqlConnection("context connection = true"))
        using (SqlCommand cmd = new SqlCommand("select SUM(total_price) from [orders]" +
                                "where [order_date] between @StartDate and @EndDate;", con))
        {
            cmd.Parameters.AddWithValue("@StartDate", StartDate);
            cmd.Parameters.AddWithValue("@EndDate", EndDate);
            con.Open();

            SqlContext.Pipe.ExecuteAndSend(cmd);
        }
    }
}
