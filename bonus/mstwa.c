/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-bsminishell1-killian.cassard
** File description:
** mstwa.c
*/

#include "n4s.h"
char *my_strdup(char const *src)
{
    char *copy = malloc(sizeof(char) * (strlen(src) + 1));
    int i = 0;

    while (src[i] != '\0'){
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}

int count_items(char const *src, char *sep)
{
    int count = 0;
    int i = 0;
    bool is_word = false;

    while (src[i] != '\0') {
        if (src[i] == sep[0] && !is_word){
            count++;
            is_word = true;
        }
        if (src[i] != sep[0])
            is_word = false;
        i++;
    }
    if (!is_word)
        return count + 1;
    return count;
}

char **mstwa(char *src, char *sep)
{
    char **arr = NULL;
    int len = count_items(src, sep);
    char *token = NULL;
    int pos = 0;

    arr = malloc(sizeof(char *) * (len + 1));
    token = strtok(src, sep);
    while (token != NULL){
        arr[pos] = my_strdup(token);
        token = strtok(NULL, sep);
        pos++;
    }
    arr[pos] = NULL;
    return arr;
}

void free_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}
