/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0 ; (s1[i] != '\0') || (s2[i] != '\0'); i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

/*void main()
{
    char *str1 = "testestts";
    char *str2 = "texsdsqd";
    int result = my_strcmp(str1, str2);
    printf("%d\n", result);
    }*/
