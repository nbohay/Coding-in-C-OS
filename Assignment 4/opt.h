int array[20],rmpage[15],pageframe,pgsize;

void *opt()
{
	int temp[10],i,flag,num,frame,p,q=0,count=0;
	//initiates the pageframes to negative 1  and a 0 in each temp array	
	for(int z=0;z<pageframe;z++)
	{
		temp[z]=0;
		array[z]=-1;
	}
	//goes through each page 
	for(i=0;i<pgsize;i++)
	{
		flag=0;	//sets flag to 0
		num=rmpage[i];	//creates an int num that has the number of the current randomized number of page frames
		for(int j=0;j<pageframe;j++)		//goes through the pageframes to check if the num and the pageframe have the same value		
		{
			if(num==array[j]){		//if they do, the flag is set to 1
				flag=1;
				break;
			}
		}
		if((flag==0)&&(q<pageframe))	//if the flag is 0 and there the int q is less than the amount of pageframe continue
		{	
			count++;		//adds a value for the fault
			array[q]=num;		//the number in the array is now the same number as the pageframe
			q++;			//adds value to int q for continue through pageframes
			if(q==pageframe)	//if the value of q is the same as the pagefault
			{
				count++;			//count is increased as a fault
				for(int j=0;j<pageframe;j++)		//goes through the frames	
				{		
					frame=array[j];			//gets the value of the current frame
					for(int k=i;k<pgsize;k++)	
					{
						if(frame!=rmpage[k])	//checks if the current frame is not the next page
							temp[j]++;	//adds the value to temp array 
						else
							break;
					}
					if(temp[j]>0)			//if there is a value in temp array then add it to the pageframe
					{
						temp[j]=0;
						p=j;
					}
				}
				array[p]=num;
			}
		}
		printf("\n Page [%d]: \t",i);			
		for(int l=0;l<pageframe;l++)	//prints the array
		{
			printf("%d\t",array[l]);
		}
	}
	printf("\nPage Faults=%d\n",count);	//prints the amount of pagefaults in the opt function
}

	
	
