#include <iostream>

size_t strlen(const char* str) {
    const char* p = str;
    while (*p) {
        p++;
    }
    return p - str;
}

int strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

char* strstr(const char* str1, const char* str2) {
    while (*str1) {
        const char* p1 = str1;
        const char* p2 = str2;
        while (*p1 && *p2 && (*p1 == *p2)) {
            p1++;
            p2++;
        }
        if (!*p2) {
            return (char*)str1;
        }
        str1++;
    }
    return nullptr;
}
char* strchr(const char* str, int c) {
    while (*str && *str != c) {
        str++;
    }
    if (*str == c) {
        return (char*)str;
    }
    return nullptr;
}

int strncmp(const char* str1, const char* str2, size_t n) {
    while (n > 0 && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
        n--;
    }
    if (n == 0) {
        return 0;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

char* strcat(char* dest, const char* src) {
    char* p = dest;
    while (*p) {
        p++;
    }
    while (*src) {
        *p++ = *src++;
    }
    *p = '\0';
    return dest;
}

char* strcpy(char* dest, const char* src) {
    char* p = dest;
    while (*src) {
        *p++ = *src++;
    }
    *p = '\0';
    return dest;
}
