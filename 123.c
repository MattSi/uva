#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ROW 256
#define COL 2048
#define IGNOREROW 64
#define IGNORECOL 128

char sentences[ROW][COL];
char ignore[IGNOREROW][IGNORECOL];
char words[256*100][IGNORECOL];
int  sennum=0, wordnum=0, ignorenum=0;

int strcomp(const void *arg1, const void *arg2){
	char *a = (char*)arg1;
	char *b = (char*)arg2;
	return strcmp(a,b);
}

void insertwords(char sentence[], int len){
	int i;
	char *p1, *p2;
	for(i=0; i<len; i++) sentence[i] = tolower(sentence[i]);
	strcpy(sentences[sennum++], sentence);
	p1 = sentence;
	while((p2 = strchr(p1, ' ')) != NULL){
		*p2 = '\0';
		if(!bsearch(p1, ignore, ignorenum, sizeof(ignore[0]), strcomp))
			strcpy(words[wordnum++], p1);
		p1 = p2+1;
	}
	if(*p1 && !bsearch(p1, ignore, ignorenum, sizeof(ignore[0]),strcomp))
		strcpy(words[wordnum++], p1);
}

int bfullword(char sentence[], char p[], char word[], int wordlen){
	char *tmp = sentence;
	if(p == sentence){
		if(*(p+wordlen) == ' ' || *(p+wordlen) == '\0')
			return 1;
	}else{
		if(*(tmp+(p-sentence-1)) == ' ' && (*(p+wordlen)== ' ' || *(p+wordlen) == '\0')    ){
			return 1;
		}
	}
	return 0;
}
void print(char word[], int len){
	int i,j;
	char *p, *s;
	for(i=0; i<sennum; i++){
		s = sentences[i];
		while((p = strstr(s, word)) != NULL){
			if(!bfullword(sentences[i], p, word, len)){
				s = p+len;
				continue;
			}
			s = sentences[i];
			while(s!=p)
				putchar(*s++);
			for(j=0; j<len; j++)
				putchar(toupper(*(p+j)));
			p = p + len;
			printf("%s\n", p);
			s = p;    
		}
	}
}

int main(int argc, char* argv[]){
	char sentence[COL],word[COL],ch;
	char *p, *p2;
	int len, i=0, j=0;
#ifndef ONLINE_JUDGE
	FILE *fp;
	fp = freopen("./tests/123.in", "r", stdin);
	fp = freopen("./tests/123.out","w", stdout);
#endif

	while(fgets(word, COL, stdin) != NULL){
		len = strlen(word);
		if(word[len-1] == '\n'){word[len-1]='\0';len--;}
		if(!strcmp(word, "::"))break;
		for(i=0; i<len; i++)word[i] = tolower(word[i]);
		strcpy(ignore[ignorenum++], word);
	}
	qsort(ignore, ignorenum, sizeof(ignore[0]), strcomp);
	while(fgets(sentence, COL, stdin) != NULL){
		len = strlen(sentence);
		if(sentence[len-1] == '\n'){
			sentence[len-1] = '\0';
			len--;
		}
		insertwords(sentence, len);
	}
	qsort(words, wordnum, sizeof(words[0]), strcomp);
	p = p2 = words[0]; i = 0;
	print(p, strlen(p));
	while(i<wordnum){
		if(!strcmp(p,p2)) p2 = words[++i];        
		else{
			print(p2, strlen(p2));
			p = p2;
		}
	}
	return 0;
}
