#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct namect
{
    char* fname;
    char* lname;
    int letters;
};
 
void getinfo(struct namect* pst)
{
    int SLEN = 255;
 
    char temp[SLEN];
    printf("Please enter your first name:\n");
    scanf("%s", temp);
 
    pst->fname = (char*)malloc(strlen(temp)+1);
 
    strcpy(pst->fname, temp);
 
    printf("Please enter your last name:\n");
    scanf("%s", temp);
    pst->lname=(char*)malloc(strlen(temp)+1);
    strcpy(pst->lname, temp);
 
}
 
 
int main()
{
 
    struct namect names;
    struct namect* pst;
 
    pst = &names;
 
    getinfo(pst);
 
    printf("Name is: %s %s \n", pst->fname, pst->lname);
    return 0;
}