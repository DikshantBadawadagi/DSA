import java.util.Scanner; 
public class First{
    public static void main(String [] args){
        System.out.println("Enter a number: ");
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        System.out.println(num);
        String name=  "Dikshant";
        String diki = name.toUpperCase();
        hello(diki);

    }
    private static void hello(String name){
        if(name.equals("DIKSHANT")){
            System.out.println("This guy is awesome");
        }
        System.out.print("Hello " + name);
    }
}