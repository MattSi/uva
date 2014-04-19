#include <stdio.h>


int dfs(int *pw){
	int wl, dl, wr, dr;
	int r1 = 1, r2 = 1;
	scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
	if(wl!=0 &&  wr!=0){
		*pw = wl + wr;
		return (wl * dl == wr * dr);
	}
	if(wl == 0)
		r1 = dfs(&wl);
	
	if(wr == 0)
		r2 = dfs(&wr);
	
	*pw = wl + wr;
	return ((wl * dl == wr * dr) && r1 && r2);
}


int main(int argc, char* argv[]){
	int mobiles, w, bal;
#ifndef ONLINE_JUDGE
	freopen("./tests/839.in", "r", stdin);
#endif
	scanf("%d", &mobiles);
	while(mobiles-- > 0){
		bal = dfs(&w);
		if(bal)
			printf("YES\n");
		else
			printf("NO\n");
		if(mobiles)printf("\n");
	}
	return 0;
}
