import java.util.Scanner;

public class ageOfPet {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Do you own a cat or dog?");
        String animal = sc.nextLine();
        
        if(animal.equals("cat") || animal.equals("Cat")) {
            System.out.println("Please provide your cats name and age in human years: ");
            String name = sc.nextLine();
            int catYears = sc.nextInt();

            System.out.printf("Your cat %s is %d years old in cat years.\n", name, catYears * 5);
        } else if(animal.equals("dog") || animal.equals("Dog")) {
            System.out.println("Please provide your dogs name and age in human years: ");
            String name = sc.nextLine();
            int dogYears = sc.nextInt();

            System.out.printf("Your dog %s is %d years old in dog years.\n", name, dogYears * 7);
        }
    }
}