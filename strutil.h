#ifndef __STRUTIL__
#define __STRUTIL__

int len(char *);
int cmp(char *, char *);
void sort(char **, int);
int sorted(char **, int);
char *cpy(char *);
void cpyt(char *, char *);
char **split(char *, char);
char *sbstr(char *, int s, int e);

#endif

