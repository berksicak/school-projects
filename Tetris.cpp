#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int main(){
	int gelen,matris[50][50],i,j,n,m,kontrol,silme[50],puan=0,k,eskipuan=0,sum[50];
	srand(time(NULL));
	printf("					  	TETRIS");
	printf("\nharita kac satir ve kac sutundan olussun?");
	scanf("%d%d",&n,&m);
	int koor,dondurme,sekil;
	char tekrar='1';
	while(tekrar=='1'){
		puan=0;
		for(i=0;i<n+3;i++){
		for(j=0;j<m;j++){
		 matris[i][j]=0;
}
	}//harita yazdirma
		printf("  ");
	for(i=0;i<m;i++){
	if(i<=9) printf(" %d ",i);
	else if(i>9) printf(" %d",i);
}
	for(i=3;i<n+3;i++){
		if(i-2<=9)printf("\n%d ",i-2);
		else printf("\n%d",i-2);
		for(j=0;j<m;j++){
		 printf("[%d]",matris[i][j]);
}
	}
	char c='d';
	while(c=='d'){
	printf("cikmak icin ESC  devam etmek icin d tusuna basiniz\n");
	c=getch();
	if(c==27) break;
	gelen=rand()%5;	
	sekil=gelen;
	puan=puan+10;
	switch(sekil){
		case 0: 
		printf(" Gelen sekil:[1] Baslangic sutunu kac olsun?");
		scanf("%d",&koor);
		for(i=0;i<n+3;i++){
			if(matris[i][koor]==0){
			 matris[i][koor]=1;
			matris[i-1][koor]=0;		
		}
		}
		break;
		case 1:
			printf("\ngelen sekil:[1]\n            [1]");
			printf("\ndondurmek isterseniz 1'e istemiyorsaniz 0'a basin\n");
			scanf("%d",&dondurme);
			if(dondurme==1){
				printf("yeni sekil: [1][1]");
				printf("baslangic sutunu kac olsun?");
				scanf("%d",&koor);
				for(i=0;i<n+3;i++){
					if(matris[i][koor]==0 && matris[i][koor+1]==0){
						matris[i][koor]=1;
						matris[i][koor+1]=1;
						matris[i-1][koor]=0;
						matris[i-1][koor+1]=0;
					}
				}
			}
			if(dondurme==0){
			printf("baslangic sutunu kac olsun?");
			scanf("%d",&koor);
			for(i=0;i<n+3;i++){
				if(i==0){
					if(matris[i][koor]==0 && matris[i+1][koor]==0){
						matris[i][koor]=1;
						matris[i+1][koor]=1;
						i=2;
					}
				}
				if(i!=0){
				if(matris[i][koor]==0 && matris[i+1][koor]==0){
					matris[i][koor]=1;
					matris[i+1][koor]=1;
					matris[i-2][koor]=0;
					matris[i-1][koor]=0;
			}
				}
				}
			}
			break;
			case 2:
				printf("\ngelen sekil:[1][1]\n            [1][1]");
				printf("\nbaslangic sutunu kac olsun?");
				scanf("%d",&koor);
				for(i=0;i<n+3;i++){
					if(i==0){
					if(matris[i][koor]==0 && matris[i][koor+1]==0 && matris[i+1][koor]==0 && matris[i+1][koor+1]==0){
						matris[i][koor]=1;
						matris[i][koor+1]=1;
						matris[i+1][koor]=1;
						matris[i+1][koor]=1;
					}
					i=2;
					}				
					else if(i>0){ 
					if(matris[i][koor]==0 && matris[i][koor+1]==0){
						matris[i][koor]=1;
						matris[i][koor+1]=1;
						matris[i-2][koor]=0;
						matris[i-2][koor+1]=0;
					}
				}
				}
				break;				
			case 3:
				printf("\ngelen sekil:[1]\n            [1]\n            [1]");
				printf("sekili dondurmek istiyorsaniz 1 istemiyorsaniz 0 a basin\n");
				scanf("%d",&dondurme);
				if(dondurme==1){
					printf("yeni sekil:[1][1][1]\n baslangic sutununu giriniz");
					scanf("%d",&koor);
					for(i=0;i<n+3;i++){
						if(matris[i][koor]==0 && matris[i][koor+1]==0 && matris[i][koor+2]==0){
							matris[i][koor]=1;
							matris[i][koor+1]=1;
							matris[i][koor+2]=1;
							matris[i-1][koor]=0;
							matris[i-1][koor+1]=0;
							matris[i-1][koor+2]=0;
						}
					}
				}
				else if(dondurme==0){
					printf("baslangic sutununu giriniz.");
					scanf("%d",&koor);
					for(i=0;i<n+3;i++){
						if(i==0){
							if(matris[i][koor]==0 && matris[i][koor+1]==0 && matris[i][koor+2]==0){
								matris[i][koor]=1;
								matris[i+1][koor]=1;
								matris[i+2][koor]=1;
							}
						}
						i=3;
					 if(i!=0){
					 	for(i=0;i<n+3;i++){
						if(matris[i][koor]==0){
							matris[i][koor]=1;
							matris[i-3][koor]=0;
					}
						}
					}
					}
				}
				break;
				case 4: 
				//z sekli 
				printf("\ngelen sekil:      [1][1]\n               [1][1]");
				printf("dondurmek istiyorsaniz 1 istemiyorsaniz 0 girin.\n");
				scanf("%d",&dondurme);
				if(dondurme==0){
					printf("baslangic sutununu giriniz.(sekilin en solundan baslayacaktir.)");
					scanf("%d",&koor);
					for(i=0;i<n+3;i++){
						if(i==0){
						if(matris[i][koor+1]==0 && matris[i][koor+2]==0 && matris[i][koor]==0 && matris[i+1][koor]==0 && matris[i+1][koor+1]==0){
						matris[i][koor+1]=1;
						matris[i][koor+2]=1;
						matris[i+1][koor]=1;
						matris[i+1][koor+1]=1;
						i=2;
						}
					}
						if(i>0){
							if(matris[i][koor]==0 && matris[i][koor+1]==0 && matris[i-1][koor+2]==0){
								matris[i][koor]=1;
								matris[i][koor+1]=1;
								matris[i-1][koor+2]=1;
								matris[i-2][koor+2]=0;
								matris[i-2][koor+1]=0;
								matris[i-1][koor]=0;
							}
						}
					}	
				}
				if(dondurme==1){
					printf("\nyeni sekil: [1]\n            [1][1]\n               [1]\n");
					printf("baslangic sutununu giriniz.");
					scanf("%d",&koor);
					for(i=0;i<n+3;i++){
						if(i==0){
							if(matris[i][koor]==0 && matris[i+1][koor]==0 && matris[i+1][koor+1]==0 && matris[i+2][koor+1]==0){
								matris[i][koor]=1;
								matris[i+1][koor]=1;
								matris[i+1][koor+1]=1;
								matris[i+2][koor+1]=1;
								i=2;
							}
						}
						if(i>0){
							if(matris[i][koor]==0 && matris[i+1][koor+1]==0){
								matris[i+1][koor+1]=1;
								matris[i][koor]=1;
								matris[i-1][koor+1]=0;
								matris[i-2][koor]=0;
							}
						}
					}
				}
				break;
				case 5:
					printf("\ngelen sekil:[1]\n            [1]\n            [1][1]\n");
						printf("1 kere dondurmek istiyorsaniz 1'e 2 kere istiyorsaniz 2'ye\n 3 kere istiyorsaniz 3'e  istemiyorsaniz 0'a basin\n");
						scanf("%d",&dondurme);
						if(dondurme==0){
							printf("baslangic sutunu kac olsun?");
							scanf("%d",&koor);
							for(i=0;i<n+3;i++){
								if(i==0){
								if(matris[i][koor]==0 && matris[i][koor+1]==0 && matris[i+1][koor]==0 && matris[i+1][koor+1]==0 && matris[i+2][koor]==0 && matris[i+2][koor+1]==0){
								matris[i][koor]=1;
								matris[i+1][koor]=1;
								matris[i+2][koor]=1;
								matris[i+2][koor+1]=1;	
								i=3;
								}
							}
							if(matris[i][koor]==0 && matris[i][koor+1]==0){
								matris[i][koor]=1;
								matris[i][koor+1]=1;
								matris[i-3][koor]=0;
								matris[i-1][koor+1]=0;
							}
							}
						}
						if(dondurme==1){
							printf("\nyenisekil:[1][1][1]\n          [1]\n");
							printf("baslangic sutununu giriniz.");
							scanf("%d",&koor);
							for(i=0;i<n+3;i++){
								if(i==0){
									if(matris[i][koor]==0 && matris[i][koor+1]==0 && matris[i][koor+2]==0 && matris[i+1][koor]==0){
									matris[i][koor]=1;
									matris[i][koor+1]=1;
									matris[i][koor+2]=1;
									matris[i+1][koor]=1;
									i=2;
									}
								}
								if(i>0){
									if(matris[i][koor]==0 && matris[i-1][koor+1]==0 && matris[i-1][koor+2]==0){
										matris[i][koor]=1;
										matris[i-1][koor+1]=1;
										matris[i-1][koor+2]=1;
										matris[i-2][koor]=0;
										matris[i-2][koor+1]=0;
										matris[i-2][koor+2]=0;
									}
								}
							}
						}
						if(dondurme==2){
							printf("yeni sekil:[1][1][1]\n           [1]");
							printf("\nbaslangic sutununu giriniz.");
							scanf("%d",&koor);
							for(i=0;i<n+3;i++){
								if(i==0){
									if(matris[i][koor]==0 && matris[i][koor+1]==0 && matris[i][koor+2]==0 && matris[i+1][koor==0]){
										matris[i][koor]=1;
										matris[i][koor+1]=1;
										matris[i][koor+2]=1;
										matris[i+1][koor]=1;
										i=3;
									}
								}
								if(i>0){
									if(matris[i][koor]==0 && matris[i-1][koor+1]==0 && matris[i-1][koor+2]==0){
										matris[i][koor]=1;
										matris[i-1][koor+1]=1;
										matris[i-1][koor+2]=1;
										matris[i-2][koor]=0;
										matris[i-2][koor+1]=0;
										matris[i-2][koor+2]=0;
									}
								}
							}
						}
						if(dondurme==3){
							printf("yeni sekil:[1][1]\n              [1]\n              [1]");
							printf("\n baslangic sutununu giriniz.");
							scanf("%d",&koor);
							for(i=0;i<n+3;i++){
								if(i==0){
									if(matris[i][koor]==0 && matris[i][koor+1]==0 && matris[i+1][koor+1]==0 && matris[i+2][koor+1]==0){
										matris[i][koor]=1;
										matris[i][koor+1]=1;
										matris[i+1][koor+1]=1;
										matris[i+2][koor+1]=1;
										i=1;
									}
								}
								if(i>0){
									if(matris[i][koor]==0 && matris[i+2][koor+1]==0){
										matris[i-1][koor]=0;
										matris[i-1][koor+1]=0;
										matris[i][koor]=1;
										matris[i+2][koor+1]=1;
									}
								}
							}
						}
						break;	
					}
					for(i=3;i<n+3;i++){
		for(j=0;j<m;j++){
			sum[i]=sum[i]+matris[i][j];
		}
		if(sum[i]==m){
			puan=puan+100;
			for(j=0;j<m;j++){
				matris[i][j]=0;
			}
			k=i;
			while(sum[k-1]!=0){
				for(j=0;j<m;j++){
				matris[k][j]=matris[k-1][j];
			    }
			    k=k-1;
			}
			for(j=0;j<m;j++){
				matris[k][j]=0;
			}
		}
		sum[i+1]=0;
    	}
					kontrol=1;
					i=0;
					while(kontrol==1 && i<m){
					if(matris[2][i]!=0){
					c=27;
				}
					i++;	
					}
					printf("ANLIK PUANINIZ:%d\n",puan);
		printf("  ");
	for(i=0;i<m;i++){
	if(i<=9) printf(" %d ",i);
	else if(i>9) printf(" %d",i);
}
	for(i=3;i<n+3;i++){
		if(i-2<=9)printf("\n%d ",i-2);
		else printf("\n%d",i-2);
		for(j=0;j<m;j++){
		 printf("[%d]",matris[i][j]);
}
	}
}
	printf("\n					  	OYUN BITTI\n");
	printf("					  	PUANININZ:%d\n",puan);
	if(eskipuan!=0) printf("					  	ESKI OYUNDAKI PUANINIZ:%d\n",eskipuan);
	eskipuan=puan;
	puan=0;
	printf("tekrar oynamak istiyorsaniz 1 istemiyorsaniz 0 girin\n");
	tekrar=getch();
	
}
	return 0;

}
		
