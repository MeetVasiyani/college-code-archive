/* WAP to create Account class, which is representing a bank account where we can deposit and withdraw money. if we want 
to withdraw money which exceed our bank balance? We will not be allowed, create InSuf cientFundException to handle 
above situation and display proper error message. */

import java.util.Scanner;

class InsufficientFundsException extends Exception {
    public InsufficientFundsException(String message) {
        super(message);
    }
}

class Account {
    private double balance;

    public Account(double initialBalance) {
        this.balance = initialBalance;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited ₹" + amount + ". New balance: ₹" + balance);
        } else {
            System.err.println("Invalid deposit amount. Please enter a positive value.");
        }
    }

    public void withdraw(double amount) throws InsufficientFundsException {
        if (amount > 0) {
            if (amount > balance) {
                throw new InsufficientFundsException("Insufficient funds. Available balance: ₹" + balance);
            } else {
                balance -= amount;
                System.out.println("Withdrew ₹" + amount + ". New balance: ₹" + balance);
            }
        } else {
            System.err.println("Invalid withdrawal amount. Please enter a positive value.");
        }
    }

    public double getBalance() {
        return balance;
    }
}

public class Q3_Exception_Handeling_Bank_Account {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double initialBalance = 0;

        System.out.print("Enter initial balance: ₹");
        initialBalance = scanner.nextDouble();

        Account account = new Account(initialBalance);

        while (true) {
            System.out.println("\nChoose an option:");
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Check balance");
            System.out.println("4. Exit");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter amount to deposit: ₹");
                    double depositAmount = scanner.nextDouble();
                    account.deposit(depositAmount);
                    break;
                case 2:
                    System.out.print("Enter amount to withdraw: ₹");
                    double withdrawAmount = scanner.nextDouble();
                    try {
                        account.withdraw(withdrawAmount);
                    } catch (InsufficientFundsException e) {
                        System.err.println(e.getMessage());
                    }
                    break;
                case 3:
                    System.out.println("Current balance: ₹" + account.getBalance());
                    break;
                case 4:
                    System.out.println("Exiting program...");
                    scanner.close();
                    return;
                default:
                    System.err.println("Invalid choice. Please try again.");
            }
        }
    }
}
