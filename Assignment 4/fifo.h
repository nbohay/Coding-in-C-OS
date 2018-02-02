int array[20],rmpage[15],pageframe,pgsize;

void *fifo()
{
	int i,p=0,q=0,count=0,flag=0,num;
	for(int z=0;z<pageframe;z++)	//initiates all the array to -1 values
	{
		array[z]=-1;
	}
	for(i=0;i<pgsize;i++)	//goes through all the pages
	{
		flag=0;		//sets flag to 0
		num=rmpage[i];	//gets the number of the page
		for(int j=0;j<pageframe;j++)	//goes through each frame
		{
			if(num==array[j])	//if the values are the same between the random and the frame set a flag
			{
				flag=1;
				break;
			}
		}
		if(flag==0)	//if no flag has been set than check the frames
		{
			if(p<pageframe)
			{	
				array[p]=num;	//set the frame to the random value
				p++;		//move onto the next frame
				count++;	//set the counter fault to add 1
			}
			else{
				p=0;}
			
		}
		printf("\n Page [%d]: \t",i);			
		for(int l=0;l<pageframe;l++)	//prints the array frames
		{
			printf("%d\t",array[l]);
		}
	}
printf("\nPage Faults=%d\n",count);	//prints the number of page faults

}

