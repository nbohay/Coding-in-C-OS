//Nicholas Bohay
//3-23-2017
//Homework 2 Coded in Java

import java.util.Scanner; 							//needed for scanner tool

public class Threads {
	public static void main(String[] args){			//main thread
		int n;
		Scanner reader =new Scanner(System.in);		// asks user for input and saves the number
		System.out.println("Enter a number: ");
		n= reader.nextInt();
		reader.close(); 							//closes the scanner
		
		Runnable q= new otput(n);					//creates the runnable and sends number from scanner to next thread
		Thread t=new Thread(q);						//creates the thread
		try {										//checks to see if main thread has finished so next thread can go
	        t.join();
	    } 
		catch (InterruptedException e) {
	        e.printStackTrace();
	    }
		t.start();									//must initiate thread to run after completed main thread
	}
}
class otput implements Runnable{					
	int a;
	public otput(int n){							//gets number from scanner
		a=n;
	}
	public int[] primenumbers(int a){				
		int[] array=new int[a+1];					//creates array of numbers with size of number given added 1-all are valued at 0
		for (int i=2; i<=Math.sqrt(a); i++){		//code for finding prime numbers in the array with Sieve of Eratosthenes					
			for(int k=i*i; k<=a; k+=i){				//if multiples of value tag as a 1
				array[k]=1;
			}
		}
	return array;
	}	

	public void run(){	
		int[] Prime=primenumbers(a);				//calls for array with prime numbers
		System.out.println("The prime numbers lower or equal to "+a+ " are: ");
		for (int i=2; i<Prime.length; i++){			//iterate through entire array skips 0,1
			if(Prime[i]!=1){						//finds the value not flagged as 1 and prints them
				System.out.print(i+ "\n");
			}
		}
	}
}