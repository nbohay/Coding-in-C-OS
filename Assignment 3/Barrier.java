//Nicholas Bohay
//Operating Systems
//4-12-2017
public class Barrier {//created the class Barrier
	
	boolean bool=true;
	int threads=0;
	int BlockedThreads=0;
	public Barrier(int threads){//instantiate the number of threads given in previous document
		this.threads=threads;
	}
	public synchronized void freeAll(){//frees all of the threads
		notifyAll();
	}
	
	public synchronized void waitForOthers(){// holds all the threads until they have all completed their task
		BlockedThreads++;
		if(BlockedThreads<threads){
			try {
				wait();
			} 
			catch (InterruptedException e) {}
		}
		else{							//frees the remaining part of the worker tasks
			notifyAll();		
			}
		
	}
}
