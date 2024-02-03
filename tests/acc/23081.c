void left(unsigned long now,
          int (*compare)(unsigned long i, unsigned long j),
          void (*swap)(unsigned long i, unsigned long j), unsigned long start){
    if (now < start) return;
    if(compare(now-1, now) == 1)
        swap(now-1, now);
    left(now-1, compare, swap, start);
}
void right(unsigned long now,
           int (*compare)(unsigned long i, unsigned long j),
           void (*swap)(unsigned long i, unsigned long j), unsigned long end){
    if (now > end) return;
    if(compare(now-1, now) == 1)
        swap(now-1, now);
    right(now + 1, compare, swap, end);
}

void bubblesort2(unsigned long nel, unsigned long start, unsigned long end,
                 int (*compare)(unsigned long i, unsigned long j),
                 void (*swap)(unsigned long i, unsigned long j), unsigned long len)
{
    if(nel == 0) return;
    nel%2 == 0 ?  left(end, compare, swap, start++): right(start, compare, swap, end--);
    bubblesort2(nel - 1, start, end, compare, swap, len);
}

void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j))
{
    bubblesort2(nel, 1, nel - 1, compare, swap, nel);
}