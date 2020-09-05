import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	// NAA.
	// - primitive typeshould be stored on stack
	// - e.g., int
	public static int loopStack(int size) {
		int[] xs;
		xs = new int[size];

		for (int i=0; i < size; i++) {
			System.out.println("add i: " + i);
			xs[i] = i;
		}
		return size;
	}

	// NAA.
	// - non primitive type should be stored on heap
	// - e.g., Integer
	public static int loopHeap(int size) {
		ArrayList<Integer> xs = new ArrayList<Integer>();

		for (int i=0; i < size; i++) {
			System.out.println("add i: " + i);
			xs.add(Integer.valueOf(i));
		}
		return size;
	}

	public static int loopHeap2(int size) {
		ArrayList<IntHolder> xs = new ArrayList<IntHolder>();

		for (int i=0; i < size; i++) {
			System.out.println("add i: " + i);
			xs.add(new IntHolder(i));
		}
		return size;
	}
	
	public static void main(String args[]) {
		System.out.println("*** loopStack(5)");
		int xs1 = loopStack(5);

		System.out.println("");
		System.out.println("*** loopHeap(5)");
		int xs2 = loopHeap(5);

		System.out.println("");
		System.out.println("*** loopHeap2(5)");
		int xs3 = loopHeap2(5);

		// run until enter int
		Scanner console = new Scanner(System.in);
		System.out.println("Enter any int to stop.");
		console.nextInt();
	}
}
