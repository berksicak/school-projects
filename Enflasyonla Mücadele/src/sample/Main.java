package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

import java.awt.*;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Image simge=new Image("simge.png");
        primaryStage.getIcons().add(simge);
        Parent root = FXMLLoader.load(getClass().getResource("giris.fxml"));
        primaryStage.setTitle("Enflasyonla Mücadele");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
