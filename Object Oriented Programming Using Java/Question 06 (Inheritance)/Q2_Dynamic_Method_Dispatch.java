/* Declare a class called book having author_name as private data member. Extend book class to have two sub classes called 
book_publication & paper_publication. Each of these classes have private member called title. Write a complete program to 
show usage of dynamic method dispatch (dynamic polymorphism) to display book or paper publications of given author.Use 
command line arguments for inputting data. */
import java.util.Scanner;

class Book {
    private String authorName;

    public Book(String authorName) {
        this.authorName = authorName;
    }

    public String getAuthorName() {
        return authorName;
    }

    public void display() {
        System.out.println("Book Author: " + authorName);
    }
}

class BookPublication extends Book {
    private String title;

    public BookPublication(String authorName, String title) {
        super(authorName);
        this.title = title;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Book Title: " + title);
    }
}

class PaperPublication extends Book {
    private String title;

    public PaperPublication(String authorName, String title) {
        super(authorName);
        this.title = title;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Paper Title: " + title);
    }
}

public class Q2_Dynamic_Method_Dispatch {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter author name: ");
        String authorName = scanner.nextLine();

        System.out.print("Enter publication type (book or paper): ");
        String publicationType = scanner.nextLine();

        System.out.print("Enter publication title: ");
        String title = scanner.nextLine();

        scanner.close();

        Book publication;

        if (publicationType.equalsIgnoreCase("book")) {
            publication = new BookPublication(authorName, title);
        } else if (publicationType.equalsIgnoreCase("paper")) {
            publication = new PaperPublication(authorName, title);
        } else {
            System.out.println("Invalid publication type.");
            return;
        }

        publication.display();
    }
}


