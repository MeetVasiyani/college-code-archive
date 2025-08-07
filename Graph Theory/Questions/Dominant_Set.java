package Questions;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Dominant_Set {

    public static void findSubsets(int [] arr,int index,List<Integer> subset,List<List<Integer>> result){
        if(index == arr.length){
            result.add(new ArrayList<>(subset));
            return;
        }

        subset.add(arr[index]);
        findSubsets(arr, index+1, subset, result);

        subset.remove(subset.size()-1);

        findSubsets(arr, index+1, subset, result);
    }

    public static List<List<Integer>> subset_Helper(int [] arr){
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();
        findSubsets(arr, 0, subset, result);
        return result;
    }

    public static boolean isDominating(int[][] edges,List<Integer> subset,int n,int e){
        if(subset.isEmpty()){
            return false;
        }
        HashSet<Integer> set = new HashSet<>();
        for(int node: subset){
            set.add(node);
            for(int i = 0; i < e; i++){
                if(edges[i][0] == node){
                    set.add(edges[i][1]);
                }
                if(edges[i][1] == node){
                    set.add(edges[i][0]);
                }
            }
        }
        return n == set.size();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<List<Integer>> result = new ArrayList<>();

        System.out.println("Enter number of nodes");
        int n = sc.nextInt();
        System.out.println("Enter number of edges");
        int e = sc.nextInt();
        int [][] edges = new int[e][2];

        int [] arr = new int[n];

        for (int i = 0; i < e; i++) {
            System.out.println("Enter starting node of edge "+(i+1));
            edges[i][0] = sc.nextInt();
            System.out.println("Enter ending node of edge "+(i+1));
            edges[i][1] = sc.nextInt();
        }

        System.out.print("Edges : {");
        for (int i = 0; i < e; i++) {
            System.out.print("{"+edges[i][0]+","+edges[i][1]+"}");
        }
        System.out.print("}");

        for(int i = 0; i < n; i++){
            arr[i] = i+1;
        }

        List<List<Integer>> subsets = subset_Helper(arr);

        for(List<Integer> subset : subsets){
            if(isDominating(edges,subset,n,e)){
                result.add(subset);
            }
        }

        System.out.println("\nDominating sets:");
        for (List<Integer> subset : result) {
            System.out.println(subset);
        }
    }
}
