bool isValid(char * s){
    int length = strlen(s);
    
    if (length == 0) return true;
    if (length % 2 == 1) return false;
    
    char stack[length / 2];
    int stack_top = -1;

    for (int i = 0; i < length; ++i) {
        switch (s[i]) {
        case '(':
            if (stack_top >= length / 2 - 1) return false;
            else stack[++stack_top] = '(';
            break;
        case '[':
            if (stack_top >= length / 2 - 1) return false;
            else stack[++stack_top] = '[';
            break;
        case '{':
            if (stack_top >= length / 2 - 1) return false;
            else stack[++stack_top] = '{';
            break;
        case ')':
            if (stack_top >= 0 && stack[stack_top] == '(') --stack_top;
            else return false;
            break;
        case ']':
            if (stack_top >= 0 && stack[stack_top] == '[') --stack_top;
            else return false;
            break;
        case '}':
            if (stack_top >= 0 && stack[stack_top] == '{') --stack_top;
            else return false;
            break;
        }
    }
    
    if (stack_top == -1) return true;
    else return false;
}
