int array[20],rmpage[15],pageframe,pgsize;

void *lru()
{
	int temp[10],i,q=0,flag,count=0,num,frame,p;
	//initiates the pageframes to negative 1  and a 0 in each temp array	
	for(int z=0;z<pageframe;z++)	
	{
		temp[z]=0;
		array[z]=-1;
	}
	for(i=0;i<pgsize;i++)	//goes through each page 
	{
		flag=0;		//sets flag to 0
		num=rmpage[i];	//creates an int num that has the number of the current page random
		for(int j=0;j<pageframe;j++)	//goes through the pageframes to check if the random nummber and the frame is the same value, if so flag it		
		{
			if(num==array[j])
			{
				flag=1;
				break;
			}
		}
		if((flag==0)&&(q<pageframe))	//if the flag is zero and q is less thatn the number of pageframes then fault, and add the random number to the array
		{
			count++;
			array[q]=num;
			q++;
			if(q==pageframe)	//if the last value
			{
				count++;	//add fault which is count	
				for(int j=0;j<pageframe;j++)	//go through the frames 	
				{		
					frame=array[j];		//get value of the frame currently	
					for(int k=0;k>0;k--)	//goes back 
					{
						if(frame!=rmpage[k])	//checks if the values are the same, if not add to temp and go back frames to check
							temp[j]++;
						else
							break;
					}			
					if(temp[j]>0) //if there is a number in temp set it to zero but input number into array
					{
						temp[j]=0;
						p=j;
					}
				}
				array[p]=num;
			}
		}
		printf("\n Page [%d]: \t",i);			
		for(int l=0;l<pageframe;l++)	//prints the pageframes and the 
		{
			printf("%d\t",array[l]);
		}
	}
	printf("\nPage faults=%d\n",count);	//prints the amount of pagefaults in lru
}
