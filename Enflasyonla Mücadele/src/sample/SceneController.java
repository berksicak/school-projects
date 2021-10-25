package sample;
import java.io.IOException;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class SceneController {
        private Stage stage;
        private Scene scene;
        private Parent root;
        @FXML
        TextField kullaniciadi;
        @FXML
        PasswordField sifre;
        @FXML
        Label hatalabel;
        @FXML
        TextField isim;
        @FXML
        TextField soyisim;
        @FXML
        PasswordField sifrek;
        @FXML
        PasswordField sifrek1;
        @FXML
        TextField kullaniciadi1;
        @FXML
        Label hatalabelk;
        @FXML
        Label hatalabel1;
        @FXML
        Button buton;


        public void switchTogiris(ActionEvent event) throws IOException {

            root = FXMLLoader.load(getClass().getResource("giris.fxml"));
            stage = (Stage)((Node)event.getSource()).getScene().getWindow();
            scene = new Scene(root);
            stage.setScene(scene);
            stage.show();

        }

        public void switchTokayit(ActionEvent event) throws IOException {
            Parent root = FXMLLoader.load(getClass().getResource("kayit.fxml"));
            stage = (Stage)((Node)event.getSource()).getScene().getWindow();
            scene = new Scene(root);
            stage.setScene(scene);
            stage.show();
        }
        public void switchToicecek(ActionEvent event) throws IOException {
            String username=kullaniciadi.getText();
            String password=sifre.getText();
            User kullanici=new User("ahmethan","babahmet","kiymaci");
            if (kullanici.signIn(username,password)){
            root = FXMLLoader.load(getClass().getResource("icecek.fxml"));
            stage = (Stage)((Node)event.getSource()).getScene().getWindow();
            scene = new Scene(root);
            stage.setScene(scene);
            stage.show();
            }else{
                hatalabel.setText("Hatalı Kullanıcı Adı Veya Şifre Lütfen Tekrar Deneyin!");
            }
        }
        public void kayit(ActionEvent event) throws IOException{
            String username=kullaniciadi1.getText();
            String isim=this.isim.getText();
            String soyisim=this.soyisim.getText();
            String sifrek=this.sifrek.getText();
            String sifrek1=this.sifrek1.getText();
            if(!(sifrek.equals(sifrek1))){
                hatalabelk.setText("Şifreler Eşleşmiyor");
            }else{
                hatalabelk.setText("Başarıyla kayıt oldun helalllllllkeeee");
                hatalabelk.setTextFill(Color.GREEN);
                buton.setText("İlerle");
                buton.setOnAction(new EventHandler<ActionEvent>() {
                    public void handle(ActionEvent e) {
                        FXMLLoader loader = new FXMLLoader(getClass().getResource("giris.fxml"));
                        try {
                            root = loader.load();
                        } catch (IOException ioException) {
                            ioException.printStackTrace();
                        }
                        stage = (Stage)((Node)event.getSource()).getScene().getWindow();
                        scene = new Scene(root);
                        stage.setScene(scene);
                        stage.show();
                    }
                });

            }
        }


        /*public void switchTotgida(ActionEvent event) throws IOException {
            root = FXMLLoader.load(getClass().getResource("tgida.fxml"));
            stage = (Stage)((Node)event.getSource()).getScene().getWindow();
            scene = new Scene(root);
            stage.setScene(scene);
            stage.show();
        }
        public void switchTotemizlik(ActionEvent event) throws IOException {
            root = FXMLLoader.load(getClass().getResource("temizlik.fxml"));
            stage = (Stage)((Node)event.getSource()).getScene().getWindow();
            scene = new Scene(root);
            stage.setScene(scene);
            stage.show();
        }*/
}
