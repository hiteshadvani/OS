import java.util.*;
import java.lang.*;
class FCFS
{
	public static void main(String args[])
	{
		int sum, i, att, awt;
		sum = 0;	att = 0;	awt = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Number of Processes: ");
		int p = sc.nextInt();
		int b[] = new int[p];
		String n[] = new String[p];
		System.out.println("Enter Process Name & Their Burst Time:");
		for(i = 0; i < p; i++)
		{
			n[i] = sc.next();
			b[i] = sc.nextInt();
		}
		System.out.println("Process\tWT\tTAT");
		for(i = 0; i < p; i++)
		{
			System.out.print(n[i]+"\t"+sum+"\t");
			awt = awt + sum;
			sum = sum + b[i];
			att = att + sum;
			System.out.println(sum);
		}
		System.out.println("Average Waiting Time = "+(awt / p));
		System.out.println("Average Turn Around Time = "+(att / p));
	}
}
