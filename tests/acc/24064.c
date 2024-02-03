unsigned long closest_fib(unsigned long step) {
	unsigned long a = 0, b = 1, c = 1, dop;
	if (step == 1) {
		return 0;
	}
	while (c < step) {
		dop = a;
		a = b;
		b = b + dop;
		if ((a + b) >= step) {
			return b;
		}
		c = a + b;
	}
	return c;
}

void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
	int loc, i, j;
	unsigned long d = closest_fib(nel);
	while (d >= 1) {
		for (i = d; i < nel; i++) {
			loc = i;
			while (loc >= d && (compare(loc - d, loc) > 0)) {
					swap(loc, loc - d);
					loc -= d;
			}
		}
		d = closest_fib(d);
	}
}