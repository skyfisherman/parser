# include <stdio.h>

char s[10000];
int t = 0;

_Bool intag;

inline _Bool isblank(char c)
{
	return (c > 0 && c <= ' ');
}

int main()
{
	char c;
	while ((c = getchar())!= EOF ) {
		if (isblank(c)) {
			if (!intag) continue;
			if(t && isblank(s[t-1] )) continue;
			c = ' ';
		}

		if ( c == '<' ) {
			intag = 1;
			if (t) {
				s[t] = 0;
				putchar('~'); 
				puts(s);
				t = 0;
			}
		} else
		if ( c == '>' ) {
			intag = 0;
			if (t) {
				while(t && s[t-1]==' ') t--;
				s[t] = 0;
				putchar('#');
				puts(s);
				t = 0;
			}
		} else
			s[t++] = c;
	}
	puts("");
}
