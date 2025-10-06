#include "strutil.h"
#include <stdlib.h>

int len(char *s) {
	char *p = s;
	while (*p++);
	return p - s - 1;
}

int cmp(char *s, char *p) {
	char *sc = s;
	char *pc = p;
	while (*sc && *pc && *pc++ == *sc++);
	return *--sc - *--pc;
}

char *cpy(char *s) {
	int l = len(s);
	char *p = malloc(sizeof(char) * (l + 1));
	while (*p++ = *s++);
	return p - l - 1;
}

void cpyt(char *src, char *dst) {
	char *c = src;
	char *d = dst;
	while (*d++ = *c++);
}

char *sbstr(char *s, int se, int e) {
	char *p = malloc(sizeof(char) * (e - se + 2));
	for (int i = se; i <= e; i++) {
		p[i - se] = s[i];
	}
	p[e - se + 1] = '\0';
	return p;
}

char **split(char *s, char sp) {
	int l = 0;
	int i = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == sp) l++;
	}
	char **r = malloc(sizeof(char *) * (l + 2));
	l = 0;
	i = 0;
	while (s[i]) {
		int se = i;
		while (s[i] && s[i++] != sp);
		i--;
		if (i - se) {
			r[l] = malloc(sizeof(char) * (i - se + 2));
			for (int j = se; j < i; j++) {
				r[l][j - se] = s[j];
			}
			r[l][i - se] = '\0';
			l++;
		}
		i++;
	}
	r[l] = NULL;
	return r;
}

static void swap(char **arr, int l, int r) {
	char *p = arr[l];
	arr[l] = arr[r];
	arr[r] = p;
}

static int pvt(char **arr, int l, int r) {
	int ipvt = r;
	int s = l;
	for (int i = l; i < r; i++) {
		if (cmp(arr[i], arr[ipvt]) < 0) {
			swap(arr, s, i);
			s++;
		} 
	}
	swap(arr, s, ipvt);
	return s;
}

static void ssort(char **arr, int s, int e) {
	if (s < e) {
		int ipvt = pvt(arr, s, e);
		ssort(arr, s, ipvt - 1);
		ssort(arr, ipvt + 1, e);
	}
}

void sort(char **arr, int l) {
	ssort(arr, 0, l - 1);
}

int sorted(char **arr, int l) {
	for (int i = 0; i < l - 1; i++) {
		if (cmp(arr[i], arr[i + 1]) > 0) return 0;
	}
	return 1;
}
