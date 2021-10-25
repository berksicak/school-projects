package veritabani;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;



public class Main {
	public static void main(String[] args) throws SQLException {
		// TODO Auto-generated method stub
		ExportItem("Gotur");
		//InsertItem(5,"kola",7.5,"Gotur","Icecek");
	}
	public static void InsertItem(int urunId,String urunAd,double urunFiyat,String tableName,String urunType) throws SQLException {
		Connection connect=null;
		DbHelper db=new DbHelper();
		PreparedStatement statement=null;
		try {
			connect=db.getConnection();
			String sql="insert into "+tableName
					+" values (?,?,?,?)";
			statement=connect.prepareStatement(sql);
			statement.setInt(1, urunId);
			statement.setString(2, urunAd);
			statement.setDouble(3, urunFiyat);
			statement.setString(4,urunType);
			statement.executeUpdate();
		}
		catch(SQLException e) {
			db.ShowError(e);
		}
		finally {
			statement.close();
			connect.close();
		}
	}
	public static Product[] ExportItem(String tableName) {
		Connection connect=null;
		DbHelper db=new DbHelper();
		Product[] a1=new Product[50];
		int i=0;
		try {
			String sql="select * from "+tableName;
			connect=db.getConnection();
			Statement st=connect.createStatement();
			ResultSet rs=st.executeQuery(sql);
			while(rs.next()) {
				a1[i]=new Product(rs.getString("urunAd"),rs.getString("urunType"),Double.parseDouble(rs.getString("urunFiyat")),Integer.parseInt(rs.getString("urunId")));
				System.out.println(a1[i].getID());
				System.out.println(a1[i].getName());
				System.out.println(a1[i].getPrice());
				System.out.println(a1[i].getType());
				i++;
			}
			st.close();
		}
		catch(SQLException e) {
			db.ShowError(e);
		}
		return a1;
	}
}
