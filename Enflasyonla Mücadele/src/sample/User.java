package sample;

import java.util.Scanner;


public class User {
    private String name;
    private String surname;
    private Order[] orders= new Order[100];
    private String password;


    public User(String name, String surname, String password) {
        this.name= name;
        this.surname=surname;
        this.password=password;
    }


    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }



    public String getName() {
        return name;
    }

    public String getsurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setName(String name) {
        this.name = name;
    }
    public void createOrder(){
        int i=0;
        while(orders[i]!=null) i++;
        orders[i]= new Order();
    }
    public void addProduct(Product product,int orderNumber){
        int i=0;
        while(orders[orderNumber].getProducts()[i]!=null || orders[orderNumber].getProducts().length!=i) i++;
        if(orders[orderNumber].getProducts().length==i){
        }
        else orders[orderNumber].getProducts()[i]=product;
    }
    public boolean signIn(String ID,String password){
        if(this.getName().equals(ID) && this.getPassword().equals(password)){
            return true;
        } else {
            return false;
        }
        }
    
}
