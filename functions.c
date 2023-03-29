// inside the switch statement that handles conversion specifiers
case 'd':
case 'i': {
    int num;
    if (length_modifier == LENGTH_MODIFIER_L) {
        num = va_arg(args, long);
    }
    else if (length_modifier == LENGTH_MODIFIER_H) {
        num = (short) va_arg(args, int);
    }
    else {
        num = va_arg(args, int);
    }
    int negative = num < 0;
    if (negative) {
        num = -num;
    }
    char num_buffer[20];
    int num_pos = 0;
    do {
        num_buffer[num_pos] = num % 10 + '0';
        num_pos++;
        num /= 10;
    } while (num != 0);
    if (negative) {
        num_buffer[num_pos] = '-';
        num_pos++;
    }
    if (precision != -1) {
        int num_zeros = precision - num_pos;
        if (num_zeros > 0) {
            char zeros_buffer[20];
            memset(zeros_buffer, '0', num_zeros);
            for (int i = 0; i < num_zeros; i++) {
                buffer[buffer_pos] = zeros_buffer[i];
                buffer_pos++;
            }
            num_written += num_zeros;
        }
    }
    for (int i = num_pos - 1; i >= 0; i--) {
        buffer[buffer_pos] = num_buffer[i];
        buffer_pos++;
    }
    num_written += num_pos;
    format++;
    break;
}

case 'u': {
    unsigned int num;
    if (length_modifier == LENGTH_MODIFIER_L) {
        num = va_arg(args, unsigned long);
    }
    else if (length_modifier == LENGTH_MODIFIER_H) {
        num = (unsigned short) va_arg(args, unsigned int);
    }
    else {
        num = va_arg(args, unsigned int);
    }
    char num_buffer[20];
    int num_pos = 0;
    do {
        num_buffer[num_pos] = num % 10 + '0';
        num_pos++;
        num /= 10;
    } while (num != 0);
    if (precision != -1) {
        int num_zeros = precision - num_pos;
        if (num_zeros > 0) {
            char zeros_buffer[20];
            memset(zeros_buffer, '0', num_zeros);
            for (int i = 0; i < num_zeros; i++) {
                buffer[buffer_pos] = zeros_buffer[i];
                buffer_pos++;
            }
            num_written += num_zeros;
        }
    }
    for (int i = num_pos - 1; i >= 0; i--) {
        buffer[buffer_pos] = num_buffer[i];
        buffer_pos++;
    }
    num_written += num_pos;
    format++;
    break;
}

case 'o': {
    unsigned int num;
    if (length_modifier == LENGTH_MODIFIER_L) {
        num = va_arg(args, unsigned long);
    }
    else if (length_modifier == LENGTH_MODIFIER_H) {
        num = (unsigned short) va_arg(args, unsigned int);
    }
    else {
        num = va_arg(args, unsigned int);
    }
    char num_buffer[20];
    int num_pos = 0;
    do {
        num_buffer[num_pos] = num % 8 + '0';
        num_pos++;
        num /= 8;
    } while (num != 0);
    if (precision != -1) {
