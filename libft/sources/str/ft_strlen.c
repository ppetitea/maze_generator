int     ft_strlen(char *string)
{
    int    length;

    if (string == 0)
        return (0);
    length = 0;
    while (string[length] != '\0')
        length++;
    return (length);
}