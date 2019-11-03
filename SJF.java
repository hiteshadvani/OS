import java.lang.*;
import java.util.*;

class SJF
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of programs : ");
		int num = sc.nextInt();
		String name[] = new String[num];
		int burst_time [] = new int [num];
		for(int i=0; i<num; i++)
		{
			System.out.println("Enter the program name and burst time : ");
			name[i] = sc.next();
			burst_time[i] = sc.nextInt();
		}
		int wait_time [] = new int [num];
		int turn_around_time [] = new int [num];
		int temp;
		String temp1;
		for(int i=0; i<num; i++)
		{
			for(int j=0; j<num-i-1; j++)
			{
				if(burst_time[j] > burst_time[j+1])
				{
					 temp = burst_time[j];
					 burst_time[j] = burst_time[j+1];
					 burst_time[j+1] = temp;
					 temp1 = name[j];
					 name[j] = name[j+1];
					 name[j+1] = temp1;
				}
			}
		}
		wait_time[0] = 0;
		turn_around_time[0] = burst_time[0];
		for(int i=1; i<num; i++)
		{
			wait_time[i]= turn_around_time[i-1];
			turn_around_time[i] = wait_time[i] + burst_time[i];
		}
		System.out.println("Program Name \tArrival Time \tBurst Time \tWait Time \tTurn Around Time ");
		for (int i=0; i<num; i++)
		{
			System.out.println(name[i]+" \t\t"+0+" \t\t"+burst_time[i]+" \t\t"+wait_time[i]+" \t\t"+turn_around_time[i]);
			
		}
		int atat = 0;
		int awt = 0;
		for (int i=0; i<num; i++)
		{
			atat = atat + turn_around_time[i];
			awt = awt + wait_time[i];
		}
		atat = atat/num;
		awt = awt/num;
		System.out.println("The Average Waiting Time is : "+awt);
		System.out.println("The Average Turn Around Time : "+atat);
	}
}
