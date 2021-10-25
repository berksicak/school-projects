package sample;

public class Product {
    private String name;
    private String type;
    private double price;

    public Product(String name, String type, double price, Market market) {
        this.name = name;
        this.type = type;
        this.price = price;
        this.market = market;
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

    public Market getMarket() {
        return market;
    }

    public void setMarket(Market market) {
        this.market = market;
    }
    private Market market;
}
