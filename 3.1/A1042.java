import java.util.Arrays;
import java.util.Scanner;

public class A1042 {	//在pat中要用 Main


    public static void main(String[] args) {
        String[] startArray = new String[55];
        String[] end = new String[55];
        int[] order = new int[55];

        for (int i = 1; i <= 13; i++){
            startArray[i] = "S" + i;
        }
        for (int i = 1; i <= 13; i++){
            startArray[i + 13] = "H" + i;
        }
        for (int i = 1; i <= 13; i++){
            startArray[i + 26] = "C" + i;
        }
        for (int i = 1; i <= 13; i++){
            startArray[i + 39] = "D" + i;
        }
        startArray[53] = "J1";
        startArray[54] = "J2";


        Scanner in = new Scanner(System.in);
        int K;
        K = in.nextInt();
        for (int i = 1; i <= 54; i++){
            order[i] = in.nextInt();
        }
        for (int i = 0; i < K; i++){
            for (int j = 1; j <= 54; j++){
                end[order[j]] = startArray[j];
            }
            for (int j = 1; j <= 54; j++){
                startArray[j] = end[j];
            }
        }
        for (int i = 1; i <= 53; i++){
            System.out.print(end[i]+" ");
        }
        System.out.println(end[54]);

    }

}
