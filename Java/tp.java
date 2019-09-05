import java.util.Scanner;
import java.util.Random;

class Animal 
{
    public void mymethod()
    {
        System.out.println("Animal");
    }
    class cat{
    public void mymethod()
    {
        System.out.println("Cat");
    }
}
}


public class tp
{
    public static void main(String... args)
    {
        cat c = new cat();
        Animal a = new Animal();
        c.mymethod();
        a.mymethod();
    }
}