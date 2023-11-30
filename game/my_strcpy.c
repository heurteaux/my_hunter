/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** task01
*/

char *my_strcpy(char *dest, char const *src)
{
    int n = 0;

    while (src[n] != '\0') {
        dest[n] = src[n];
        n++;
    }
    dest[n] = '\0';
    return dest;
}

/*void main(void)
{
    char str_base[] = "zeazeaeuhujaijeijijeza";
    char str_dest[] = "AAAAAAAAAAAAAAAAAAAAAA";
    //read_str(str_dest);
    char *str_dest_new = my_strcpy(str_dest, str_base);
    //read_str(str_base);
    //read_str(str_dest);
    printf("%s\n", str_dest_new);
    }*/
