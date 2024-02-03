// Рекурсивная функция бинарного поиска
unsigned long binsearch_recursive(unsigned long nel, int (*compare)(unsigned long i), unsigned long low, unsigned long high) {
    // Проверяем, что нижняя граница не превышает верхнюю
    if (low <= high) {
        // Вычисляем индекс середины последовательности
        unsigned long mid = low + (high - low) / 2;

        // Вызываем функцию сравнения для определения отношения mid-го элемента к искомому числу
        int cmp = compare(mid);

        // Если совпадение найдено, возвращаем индекс mid
        if (cmp == 0) {
            return mid;
        }
        // Если mid-й элемент меньше искомого числа, рекурсивно вызываем функцию для правой половины
        else if (cmp < 0) {
            return binsearch_recursive(nel, compare, mid + 1, high);
        }
        // Если mid-й элемент больше искомого числа, рекурсивно вызываем функцию для левой половины
        else {
            return binsearch_recursive(nel, compare, low, mid - 1);
        }
    }

    // Если элемент не найден, возвращаем nel (количество элементов в последовательности)
    return nel;
}

// Обертка для вызова рекурсивной функции с начальными значениями индексов
unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    return binsearch_recursive(nel, compare, 0, nel - 1);
}
