import java.io.*;
import java.util.*;

public class QUES3 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        int[] divnum = NumberDiv(n);
        int[] divsum = SumDiv(n);

        for (int i = 1; i <= n; i++) {
            System.out.println(divnum[i] + " " + divsum[i]);
        }
    }

    public static int[] NumberDiv(int n) {
        int[] divnum = new int[100005];

        Arrays.fill(divnum, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                divnum[j]++;
            }
        }

        return divnum;
    }

    public static int[] SumDiv(int n) {
        int[] divsum = new int[100005];

        Arrays.fill(divsum, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                divsum[j] += i;
            }
        }

        return divsum;
    }
}