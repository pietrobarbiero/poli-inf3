#include <pthread.h>
#include <string.h>
#include <stdio.h>

#define N 10
#define M 4

struct ts {
	int tid;
	char s[N];
};

void *print(void *arg){
	int tid;
	char s[M];
	struct ts *p_ts; //puntatore alla struttura
	
	p_ts = (struct ts *) arg;
	tid = p_ts->tid;
	strcpy(s, p_ts->s);
	fprintf(stdout, "%s%d\n", s, tid);
	return (void*) 0;
};

int main(){
	int i;
	pthread_t t[M];
	struct ts v[M];
	
	for(i=0; i<M; i++){
		v[i].tid = i;
		strcpy(v[i].s, "ciao: ");
		pthread_create(&t[i], NULL, print, (void *) &v[i]);
	}
	//sleep(2);
	fprintf(stdout, "creante\n");
	
	return 0;
}
