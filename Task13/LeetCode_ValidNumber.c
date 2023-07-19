#include <stdbool.h>

bool isNumber(char* s) {
    int i = 0;
    int signCounter = 0, dotCounter = 0, expCounter = 0;

    while (s[i] != '\0') {
        if ((s[i] < '0' || s[i] > '9') && (s[i] != 'e' && s[i] != 'E' && s[i] != '+' && s[i] != '.' && s[i] != '-')) {
            return false;
        }

        if (s[i] == '+' || s[i] == '-') {
            if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }
            if(s[i+1] == 'E' || s[i+1] == 'e'){
                return false;
            }
            if(i==0 && s[i+1] == '\0'){
                return false;
            }
        }

        if (s[i] == '.') {
            if (dotCounter > 0 || expCounter > 0) {
                return false;
            }
            if ((i == 0 || (s[i - 1] < '0' || s[i - 1] > '9')) && (s[i + 1] < '0' || s[i + 1] > '9')) {
                return false; // No digit before or after the dot
            }
            dotCounter++;
        }

        if (s[i] == 'e' || s[i] == 'E') {
            if (expCounter > 0) {
                return false;
            }
            expCounter++;
            if (i == 0 || s[i + 1] == '\0') {
                return false;
            }
            if (s[i + 1] == '+' || s[i + 1] == '-') {
                i++; // Skip the sign after 'e' or 'E'
                if (s[i + 1] == '\0') {
                    return false;
                }
            }
        }

        i++;
    }

    return true;
}
