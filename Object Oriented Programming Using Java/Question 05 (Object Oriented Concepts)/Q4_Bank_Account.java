/*Create a class named Q4_Bank_Account with data memebers accountNo, userName, email, accountType and accountBalance, 
Also create methods getAccountDetails() and displayAccountDetails(). */

import java.util.Scanner;

public class Q4_Bank_Account {
    int accountNo;
    String userName;
    String email;
    String accountType;
    double accountBalance;

    public void getAccountDetails() {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter Account Number: ");
        this.accountNo = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter User Name: ");
        this.userName = sc.nextLine();

        System.out.print("Enter Email: ");
        this.email = sc.nextLine();

        System.out.print("Enter Account Type: ");
        this.accountType = sc.nextLine();

        System.out.print("Enter Account Balance: ");
        this.accountBalance = sc.nextDouble();

        sc.close();
    }

    public void displayAccountDetails() {
        System.out.println("Account Number: " + accountNo);
        System.out.println("User Name: " + userName);
        System.out.println("Email: " + email);
        System.out.println("Account Type: " + accountType);
        System.out.println("Account Balance: $" + accountBalance);
    }

    // Main method to test the class
    public static void main(String[] args) {
        Q4_Bank_Account account = new Q4_Bank_Account();
        
        account.getAccountDetails();
        
        account.displayAccountDetails();
    }
}
