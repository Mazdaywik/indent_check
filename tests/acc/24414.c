unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    unsigned long low = 0;
    unsigned long high = nel;
    
    while (low < high) {
        unsigned long mid = low + (high - low) / 2;
        int cmp = compare(mid);

        if (cmp == 0) {
            // Найденное число равно искомому
            return mid;
        } else if (cmp < 0) {
            // Искомое число больше, смещаем нижнюю границу
            low = mid + 1;
        } else {
            // Искомое число меньше, смещаем верхнюю границу
            high = mid;
        }
    }

    // Элемент не найден
    return nel;
}