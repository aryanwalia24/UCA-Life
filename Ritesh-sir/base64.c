#include <stdio.h>
char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+/";

void encode(int n, char arr[100])
{
    char rev[100];
    int idx = 0;
    while (n != 0)
    {
        char c = chars[n % 64];
        rev[idx++] = c;
        n /= 64;
    }

    for (int i = 0; i < idx; i++)
    {
        arr[i] = rev[idx - i - 1];
    }
    arr[idx] = '\0';
}

int getVal(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return (int)c - 97; // or just do c-'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return (int)c - 64 + 26; // c - 'A' + 26;
    }
    else if (c >= '0' && c <= '9')
    {
        return (int)c - 48 + 52; // c - '0' + 52
    }
    else if (c == '/') // xtra chars
        return 62;
    else if (c == '+')
        return 63;
    else
        return -1; // invalid
}

int decode(char arr[100])
{
    int res = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        int num = getVal(arr[i]);
        res = res * 64 + num;
    }
    return res;
}

int main()
{
    int n = 64;
    // 63 = '/'
    // 64 = 'ba'
    // 65 = 'bb'
    // 128 = 'ca'
    char encoded[100];

    encode(n, encoded);
    int dec = decode(encoded);
    printf("Number  : %d", n);
    printf("\nEncoded : %s", encoded);
    printf("\nDecoded : %d", dec);
    return 0;
}