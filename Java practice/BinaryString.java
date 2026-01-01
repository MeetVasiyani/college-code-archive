import java.util.*;
class Main {
    public static void main(String[] args) {
        String bin = "101.110";
        String [] parts = bin.split("\\.");
        int intPart = Integer.parseInt(parts[0],2);
        double fracpart = 0.0;

        if(parts.length > 1){
            fracpart = Integer.parseInt(parts[1], 2)/Math.pow(2,parts[1].length());
        }

        System.out.println(intPart+fracpart);
    }
}