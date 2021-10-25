package veritabani;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;;
public class DbHelper {
	static String username="root";
	static String password="";
	static String dbUrl="jdbc:mysql://localhost:3306/urunler_database";
	
	public Connection getConnection() throws SQLException {
		return(Connection)DriverManager.getConnection(dbUrl,username,password);
	}
	public void ShowError(SQLException ex) {
		System.out.println("Error: "+ex.getMessage());
		System.out.println("Error Code: "+ex.getErrorCode());
	}
}
