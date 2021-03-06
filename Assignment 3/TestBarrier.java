//Nicholas Bohay
//Homework 3 Operating Systems
//4-12-2017

import java.io.*;

/**
 * A testing harness for the Barrier class.
 *
 * Proper output is that we should see is that all threads 
 * output an 'A' before reaching the barrier and then a 'B'
 * after proceeding through the barrier. Therefore, output
 * should appear as a series of 'A's followed by an equal count
 * of 'B's. (There should not be an intermingling of 'A's and 'B's.
 */

public class TestBarrier  
{
	public static final int THREAD_COUNT = 5;

        public static void main(String args[]) throws java.io.IOException {
			System.out.println("Proper output is that we should see is that all threads");
	 		System.out.println("output an 'A' before reaching the barrier and then a 'B'");
	 		System.out.println("after proceeding through the barrier. Therefore, output");
	 		System.out.println("should appear as a series of 'A's followed by an equal count");
	 		System.out.println("of 'B's. (There should not be an intermingling of 'A's and 'B's.");
			System.out.println("\n\nPress Enter to begin the test:");
			(new BufferedReader(new InputStreamReader(System.in))).read();

			// initialize the barrier to the number of threads
			// waiting upon the barrier
	        Barrier barrier = new Barrier(THREAD_COUNT);

	        Thread[] workers = new Thread[THREAD_COUNT];
	        for (int i = 0; i < workers.length; i++) { 
	        	workers[i] = new Thread(new Worker(barrier));
	        	workers[i].start();
	        }
	        try {
	        	for (int i = 0; i < workers.length; i++)
	        		workers[i].join();
	        }
	        catch (InterruptedException ie) { }
       
	        System.out.println("\n\nPress Enter to begin the freeAll() test:");
	        (new BufferedReader(new InputStreamReader(System.in))).read();
	
	        barrier = new Barrier(THREAD_COUNT + 1);
	        workers = new Thread[THREAD_COUNT];
	        for (int i = 0; i < workers.length; i++) {
	        	workers[i] = new Thread(new Worker(barrier));
	        	workers[i].start();
	        }

	        try {
	        	Thread.sleep(1000);
	        }
	        catch (InterruptedException ie) { }
	        	barrier.freeAll();

        	}
}


/**
 * A worker using the Barrier
 */
class Worker implements Runnable 
{
	private Barrier partA;

	public Worker(Barrier partA) {
		this.partA = partA;
	}

	/**
	 * Each thread will do some work for awhile, and then
	 * invoke waitForOthers(). A thread may proceed when all
	 * other threads have arrived at the barrier.
	 */
	public void run() {
		System.out.println("A");
		
		partA.waitForOthers();

		System.out.println("B");
	}
}

