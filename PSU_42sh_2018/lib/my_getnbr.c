/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_getnbr.c
*/

int last_i(int sign_alias, int result_alias)
{
    if ((sign_alias % 2) == 1)
        result_alias = -result_alias;
    if (result_alias < -2147483638 || result_alias > 2147483638)
        return (0);
    return (result_alias);
}

int my_getnbr(char *str)
{
    long long result = 0;
    int result_int;
    int sign = 0;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign++;
        i++;
    }
    while (str[i] > 47 && str[i] < 58) {
        result = result * 10;
        result +=  (str[i] - '0');
        i++;
    }
    result_int = last_i(sign, result);
    return (result_int);
}
