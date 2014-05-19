#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define C 32
#define V 1024

char candidates[C][32];
int voting[V][C];
int voting_index[V];
int vote_count[C];

int doVote(int votes, int people){
	int i, validtikit, m;
	memset(voting_index, 0, sizeof(voting_index));
	
	/* ���û��ѡƱ�����൱�����к�ѡ��ѡƱ��ͬ */
	if(votes == 0){
		for(i=1; i<=people; i++)
			vote_count[i] = 1;
		return -1;
	}

	while(1){
		/* ͳ��ѡƱ */
		memset(vote_count, 0, sizeof(vote_count));
		for(i=0; i<votes; i++){
			vote_count [ 
				voting[i][voting_index[i]]
			] += 1;
		}
		/* �ҳ����ֵ�� �����ѡƱ���룬��ֱ��ʤ�� */
		for(i=0; i<C; i++)
			if(vote_count[i] * 2 > votes)
				return i; /* ���ص�i����ѡ��*/
		
		/* �����к�ѡ�˵�Ʊ����ͬ�����˳�*/
		validtikit = 0;
		for(i=0; i<C; i++){
			if(vote_count[i] > 0){
				validtikit = vote_count[i];
				break;
			}
		}
		for(i=0; i<C; i++){
			if(vote_count[i] > 0 && vote_count[i] != validtikit){
				validtikit = -1;
				break;
			}
		}
		if(validtikit != -1){
			/* ��Щ��ѡ�˵�Ʊ����ͬ�� ����-1, ��������������������Ч�ĺ�ѡ��Ʊ����ͬ*/
			return -1;
		}

		/* �ҳ���ѡ�˻�õ�����ѡƱ*/
		m = 1000000;
		for(i=0; i<C; i++){
			if(vote_count[i] > 0 && vote_count[i] < m)
				m = vote_count[i];
		}

		/* ��̭����ѡƱ�ĺ�ѡ��*/
		for(i=0; i<C; i++){
			if(vote_count[i] == m)
				vote_count[i] = -1;
		}

		/* �޸�ѡƱ���*/
		for(i=0; i<votes; i++){

			while(1){
				if(vote_count[
					voting[i][voting_index[i]]
				] == -1){
					voting_index[i] ++;
				}
				else 
					break;
			}
			
		}
	}
}

int main(int argc, char* argv[])
{
    int cases, person;
    int i, j, votes, winner;
    size_t len;
    char buff[1024];
    char *tmp;
#ifndef ONLINE_JUDGE
    freopen("./tests/10142.in", "r", stdin);
#endif
    scanf("%d\n", &cases);
    while(cases--){
        scanf("%d\n", &person);
        for(i=0; i<person; i++){
            fgets(candidates[i], 32, stdin);
            len = strlen(candidates[i]);
            if(candidates[i][len-1] == '\n')
                candidates[i][len-1] = '\0';
        }
        /* read voting from std input stream */
        votes = 0;
		memset(voting, 0, sizeof(voting));
        while(fgets(buff, 1024, stdin)){
            len = strlen(buff);
            if(buff[len-1] == '\n')
                buff[len-1] = '\0';
            if(buff[0] == '\0')
                break;
            for(j=0, tmp = buff; j<person; j++, tmp = strchr(tmp, ' ')+1){
                sscanf(tmp, "%d", &voting[votes][j]);
            }
            votes++;
        }
		winner = doVote(votes, person);
		if(winner >= 0)
			printf("%s\n", candidates[winner-1]);
		else{ 
			for(i=1; i<C; i++){
				if(vote_count[i] > 0)
					printf("%s\n", candidates[i-1]);
			}
		}
		if(cases>0)
			printf("\n");
    }
    return 0;
}

