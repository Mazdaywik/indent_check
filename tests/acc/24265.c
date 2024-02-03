int strdiff(char *a, char *b) {
    int tmp_ind = 0;
    while (*a != '\0' && *b != '\0') {
        if (*a != *b) {
            for (int bit = 0; bit < 8; bit++) {
                if ((1 << bit) & (*a ^ *b)) {
                    return tmp_ind + bit;
                }
            }
        }
        a++;
        b++;
        tmp_ind += 8;
    }
    if (*a == '\0' && *b == '\0') {
        return -1;
    } else {
        char c;
        if (*a == '\0') {
            c = *b;
        } else {
            c = *a;
        }
        for (int bit = 0; bit < 8; bit++) {
            if ((1 << bit) & c) {
                return tmp_ind + bit;
            }
        }
        return tmp_ind + 8;
    }
}