unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j))
{   if (nel == 1){return 0;}
	if (less(1, 0) == 1){return 0;}
	unsigned long left = 0;
	for (unsigned long i = 1; i <nel-1;i++)
		
		{
		if (left == 0){
			if(less(i+1, i) == 1){return i;}
		}
		else{
			if(less(i, i+1)==1){left=0;}
			else{left=1;}
			}}
	return nel-1;

}