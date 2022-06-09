import java.util.Scanner;
public class Main{
    public static double findMedianSortedArrays(int A[], int B[]) {
        int n = A.length, m = B.length;
        if(n>m)return findMedianSortedArrays(B,A);
        int left = 0, right = n;
        while (left <= right) {
            int partitionA = (left + right)/2;
            int partitionB = (n + m + 1)/2 - partitionA;      // partitionA + partitionB = (n+m+1)/2
            //if partitionA is 0 then take INT_MIN for maxLeftA (nothing is left in the left of partition)
            double maxLeftA = Integer.MIN_VALUE;
            if(partitionA > 0){
                maxLeftA = A[partitionA-1];
            }
                
            //if partitionA is n then take INT_MAX for minRightA (nothing is left in the right of partition)
            double minRightA = Integer.MAX_VALUE;
            if(partitionA < n){
                minRightA = A[partitionA];
            }
                
            //Similarly for maxLeftB and minrightB
            double maxLeftB = Integer.MIN_VALUE;
            if(partitionB > 0){
                maxLeftB = B[partitionB-1];
            }
                    
            double minRightB = Integer.MAX_VALUE;
            if(partitionB < m){
                minRightB = B[partitionB];
            }
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {     // check weather it's a perfect partition or not
                if ((n+m) % 2 == 0) {                                // if the sorted merged array is of even length
                    return (Math.max(maxLeftA, maxLeftB) + Math.min(minRightA, minRightB))/2.0;
                } 
                else {
                    return Math.max(maxLeftA, maxLeftB);
                }
            } 
            else if (maxLeftA > minRightB) {                          //move left side.
                right = partitionA - 1;
            }
            else {                                                   // move right side
                left = partitionA + 1;
            }
        }
        return 0.0;    // we can't find the median if input is invalid i.e., arrays are not sorted
    }
        
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int A[]=new int[]{1,2,6,8};
        int B[]=new int[]{5,7,10};
        double median = findMedianSortedArrays(A,B);
        System.out.println(median);  
    }
}