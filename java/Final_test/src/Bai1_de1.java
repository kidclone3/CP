import java.util.Scanner;

public class Bai1_de1 {
	
	public static int[][] inputMatrix(Scanner reader){
		int n = reader.nextInt();
		int[][] a = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = reader.nextInt();
			}
		}
		return a;
	}

	public static boolean isUpperTriangle(int[][] arr) {
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j < i && arr[i][j] != 0) return false;
			}
		}
		return true;
	}
	

	public static int maxElements(int[] a) {
		int mx = a[0];
		for(int it : a) {
			mx = Math.max(mx, it);
		}
		return mx;
	}
	public static int[] findRows(int[][] arr) {
		int n = arr.length;
		int mn = (int) 1e9;
		int c = 0;
		for(int[] it : arr) {
			int tmp = maxElements(it);
			if (tmp < mn) {
				mn = tmp;
				c = 1;
			}
			else if (tmp == mn) {
				c++;
			}
		}
		int[] ans = new int[c];
		for(int i = 0, j = 0; i < n; ++i) {
			int tmp = maxElements(arr[i]);
			if (tmp == mn) {
				ans[j++] = i;
			}
		}
		return ans;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] arr = inputMatrix(sc);
//		System.out.println(isUpperTriangle(arr));
		int[] ans = findRows(arr);
		for(int it : ans) {
			System.out.print(it + " ");
		}
	}
}
