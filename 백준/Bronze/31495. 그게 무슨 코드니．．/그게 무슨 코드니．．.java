import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        String a = in.nextLine();
        long len = a.length();

        if(a.charAt(0) == '"' && a.charAt((int)(len - 1)) == '"')
        {
            if(len <= 2)
                System.out.println("CE");
            
            else
            {
                for(int i = 1 ; i < len - 1 ; i++)
                    System.out.print(a.charAt(i));
            }
        }

        else
            System.out.println("CE");
    }
}