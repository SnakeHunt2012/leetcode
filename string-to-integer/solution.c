#define INT_MIN -2147483648
#define INT_MAX 2147483647

int myAtoi(char* str) {
    int i, length = strlen(str), state = 0, sign = 1, digit_flag = 0;
    unsigned long long integer = 0;

    for (i = 0; i < length; ++i) {
        switch (state) {
        case 0:
            if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r')
                state = 0;
            else if (str[i] == '+' || str[i] == '-')
                state = 1;
            else if (str[i] >= '0' && str[i] <= '9')
                state = 2;
            else
                state = 4;
            break;
        case 1:
            if (str[i] >= '0' && str[i] <= '9')
                state = 2;
            else
                state = 4;
            break;
        case 2:
            if (str[i] >= '0' && str[i] <= '9')
                state = 2;
            else
                state = 3;
            break;
        case 3:
            break;
        case 4:
            return 0;
        }
    }
    
    if (state != 2 && state != 3)
        return 0;

    for (i = 0; i < length; ++i) {
        if (!digit_flag && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'))
            continue;
    
        if (digit_flag && (str[i] < '0' || str[i] > '9'))
            return sign * (int) integer;
    
        if (str[i] == '+') {
            sign = 1;
            digit_flag = 1;
            continue;
        }
        if (str[i] == '-') {
            sign = -1;
            digit_flag = 1;
            continue;
        }
    
        digit_flag = 1;
        integer *= 10;
        integer += str[i] - '0';
    
        if (sign == 1 && integer > 2147483647)
            return INT_MAX;
        if (sign == -1 && integer > 2147483648)
            return INT_MIN;
    }
    return sign * (int) integer;
}
