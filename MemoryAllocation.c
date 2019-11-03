#include<stdio.h>

int main()
{
	int choice;
	int memory[10]={0},i,m,n,j,file[10]={0},first[10]={0},left[10]={0};
	int fragment[20],b[20],p[20],nb,np,temp,lowest=9999;
	static int barray[20],parray[20];
	 int fragments[10], blocks[10], files[10];
      int  number_of_blocks, number_of_files, top = 0;
      static int block_arr[10], file_arr[10];
	do
	{
      printf("ENTER THE MENU :\n 1. FIRST FIT\n 2. BEST FIT\n 3. WORST FIT\n ENTER THE CHOICE : ");
      scanf("%d",&choice);
      switch(choice)
      {
		  case 1:
        printf("Enter the no of memories :");
        scanf("%d",&n);
        printf("Enter the memory size :\n");
        for(i=0;i<n;i++)
                scanf("%d",&memory[i]);
        
        printf("Enter the no of files :");
        scanf("%d",&m);
        printf("Enter the file size :\n");
        for(j=0;j<m;j++)
                scanf("%d",&file[j]);
                
        for(j=0;j<m;j++)
         {
                for(i=0;i<n;i++)
                {
                        if(memory[i]>=file[j])
                        {
                                first[i] = file[j];
                                left[i] = memory[i] - file[j];
                                
                                break;
                        }
                }
        }
        
        printf("First Fit is :\n");
        printf("Memory size \t\t Files \t\t Fragmentation\n");
        for(i=0;i<n;i++)
			printf("%d \t\t %d \t\t %d\n",memory[i],first[i],left[i]);
			
			
			break;
			
			case 2:
				
	printf("\n\t\t\tMemory Management Scheme - Best Fit");
	printf("\nEnter the number of blocks:");
	scanf("%d",&nb);
	printf("Enter the number of processes:");
	scanf("%d",&np);
	
	printf("\nEnter the size of the blocks:-\n");
	for(i=1;i<=nb;i++)
    {
		printf("Block no.%d:",i);
        scanf("%d",&b[i]);
    }
	
	printf("\nEnter the size of the processes :-\n");
	for(i=1;i<=np;i++)
    {
        printf("Process no.%d:",i);
        scanf("%d",&p[i]);
    }
	
	for(i=1;i<=np;i++)
	{
		for(j=1;j<=nb;j++)
		{
			if(barray[j]!=1)
			{
				temp=b[j]-p[i];
				if(temp>=0)
					if(lowest>temp)
					{
						parray[i]=j;
						lowest=temp;
					}
			}
		}
		
		fragment[i]=lowest;
		barray[parray[i]]=1;
		lowest=10000;
	}
	
	printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
	for(i=1;i<=np && parray[i]!=0;i++)
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,p[i],parray[i],b[parray[i]],fragment[i]);

		break;
		
		case 3:
      printf("\nEnter the Total Number of Blocks:\t");
      scanf("%d",&number_of_blocks);
      printf("Enter the Total Number of Files:\t");
      scanf("%d",&number_of_files);
      printf("\nEnter the Size of the Blocks:\n");
      for(m = 0; m < number_of_blocks; m++) 
      {
            printf("Block No.[%d]:\t", m + 1);
            scanf("%d", &blocks[m]);
      }
      printf("Enter the Size of the Files:\n");
      for(m = 0; m < number_of_files; m++) 
      {
            printf("File No.[%d]:\t", m + 1);
            scanf("%d", &files[m]);
      }
      for(m = 0; m < number_of_files; m++)
      {
            for(n = 0; n < number_of_blocks; n++)
            {
                  if(block_arr[n] != 1)
                  {
                        temp = blocks[n] - files[m];
                        if(temp >= 0)
                        {
                              if(top < temp)
                              {
                                    file_arr[m] = n;
                                    top = temp;
                              }
                        } 
                  }
                  fragments[m] = top;
                  block_arr[file_arr[m]] = 1;
                  top = 0;
            }   
      }
      printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment");
      for(m = 0; m < number_of_files; m++)
      {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n", m, files[m], file_arr[m], blocks[file_arr[m]], fragments[m]);
      }
      break;
}
}while(choice!=4);
return 0;
	}