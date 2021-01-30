import java.util.Scanner;

public class SoinsuBunkai {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);

        System.out.print("input a data ...");
        int data = scanner.nextInt();

        System.out.print(data + " =  1 ");
        for(int i = 2;i <= data;){
            if(data % i == 0){
                System.out.print(" * " + i);
                data /= i;
            }else{
                i++;
            }
        }
    }
}