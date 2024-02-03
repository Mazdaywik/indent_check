int maxarray(void *base, unsigned long nel, unsigned long width, 
        int (*compare)(void *a, void *b)) 
{ 
    int maxx = 0;
    
    for (int i = 0; i < nel; i++) {
	if (compare((char*)base + (i)*width, (char*)base + (maxx)*width) > 0) {
		maxx = i;
	}
    }
    return maxx;
}