package veritabani;

public class Product {
    private String name;
    private String type;
    private double price;
    private int ID;

    public Product(String name, String type, double price, int ID) {
        this.name = name;
        this.type = type;
        this.price = price;
        this.ID = ID;
    }

    public int getID() {
		return ID;
	}

	public void setID(int iD) {
		ID = iD;
	}

	public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }
}
