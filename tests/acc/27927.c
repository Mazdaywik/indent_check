int strdiff(char *a, char *b) {
    int bit_count = 0;

    while (*a != '\0' && *b != '\0') {
        int xor_result = *a ^ *b;

        for (int i = 0; i < 8; i++) {
            if (xor_result & (1 << i)) {
                return bit_count + i;
            }
        }

        bit_count += 8;
        a++;
        b++;
    }

    while (*a != '\0') {
        int xor_result = *a ^ 0;

        for (int i = 0; i < 8; i++) {
            if (xor_result & (1 << i)) {
                return bit_count + i;
            }
        }

        bit_count += 8;
        a++;
    }

    while (*b != '\0') {
        int xor_result = 0 ^ *b;

        for (int i = 0; i < 8; i++) {
            if (xor_result & (1 << i)) {
                return bit_count + i;
            }
        }

        bit_count += 8;
        b++;
    }

    return -1;
}