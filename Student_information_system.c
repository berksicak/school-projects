#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
typedef struct TEACHER{
	int id;
	char name[20];
	char surname[15];
	char unvan[20];
}teacher;
typedef struct LESSON{
	int code;
	char name[20];
	int credit;
	int quota;
	int tcode;//öðretmen id
}lesson;
typedef struct STUDENT{
	int number;
	char name[20];
	char surname[15];
	int num_of_les;//maks 10 ders alabilir.
	int sum_of_credit;//maks 25 kredilik ders alabilir.
}student;
void addteacher(){
	FILE *fp1;
	int i=0;
	fp1=fopen("ogretim_uyeleri.txt","r+");
	teacher t1,t2;
	t2.id=0;
	printf("girmek istediginiz egitim gorevlisini id ad soyad unvan seklinde giriniz.");
	scanf("%d %s %s %s",&t1.id,t1.name,t1.surname,t1.unvan);
	fscanf(fp1,"%d %s %s %s\n",&t2.id,t2.name,t2.surname,t2.unvan);
	while(!feof(fp1) && t1.id!=t2.id){	
	fscanf(fp1,"%d %s %s %s\n",&t2.id,t2.name,t2.surname,t2.unvan);
	}
	if(t2.id==t1.id){
		printf("Girdiginiz numara alinmistir,baska numara ile tekrar deneyiniz.");
	}
	else{
	fprintf(fp1,"%d %s %s %s\n",t1.id,t1.name,t1.surname,t1.unvan);
}
	
	fclose(fp1);
}
void addlesson(){
	FILE *fp2;
	fp2=fopen("dersler.txt","r+");
	lesson ls1,ls2;
	ls2.code=0;
	printf("girmek istediginiz dersi kod isim kredi kontenjan ogretmenkodu seklinde giriniz.");
	scanf("%d %s %d %d %d",&ls1.code,ls1.name,&ls1.credit,&ls1.quota,&ls1.tcode);
	while(!feof(fp2) && ls1.code!=ls2.code){	
	fscanf(fp2,"%d %s %d %d %d\n",&ls2.code,ls2.name,&ls2.credit,&ls2.quota,&ls2.tcode);
	}
	if(ls2.code==ls1.code){
		printf("Girdiginiz numara alinmistir,baska numara ile tekrar deneyiniz.");
	}
	else {
	fprintf(fp2,"%d %s %d %d %d\n",ls1.code,ls1.name,ls1.credit,ls1.quota,ls1.tcode);
}
	fclose(fp2);
}
void addstudent(){
	FILE *fp4;
	fp4=fopen("Öðrenciler.txt","r+");
	student st1,st2;
	st1.num_of_les=0;
	st1.sum_of_credit=0;
	st2.number=0;
	printf("OGRENCI EKLEME\nnumara ad soyad seklinde giriniz.(Numara en kucuk 1 olabilir.)");
	scanf("%d %s %s",&st1.number,st1.name,st1.surname);
	while(!feof(fp4) && st1.number!=st2.number){	
	fscanf(fp4,"%d %s %s %d %d\n",&st2.number,st2.name,st2.surname,&st2.num_of_les,&st2.sum_of_credit);
	}
	 if(st2.number==st1.number){
		printf("Girdiginiz numara alinmistir,baska numara ile tekrar deneyiniz.");
	}
	else{
		fprintf(fp4,"%d %s %s %d %d\n",st1.number,st1.name,st1.surname,st1.num_of_les,st1.sum_of_credit);
	}
	fclose(fp4);
}
void course_enroll(){
	FILE *fp2, *fp3, *fp4;
	fp2=fopen("dersler.txt","r");
	fp3=fopen("ÖðrenciDersKayýt.txt","a");
	fp4=fopen("Öðrenciler.txt","r");
	lesson ls;
	int pick,x,i=0,n=0,*codes;
	student st,*arr;
	arr=(student*)calloc(1,sizeof(student));
	codes=(int*)calloc(25,sizeof(int));
	printf("ogrenci numarasini giriniz."); scanf("%d",&x);
	fscanf(fp4,"%d %s %s %d %d\n",&st.number,st.name,st.surname,&st.num_of_les,&st.sum_of_credit);
	while(!feof(fp4) && st.number!=x){
		fscanf(fp4,"%d %s %s %d %d\n",&st.number,st.name,st.surname,&st.num_of_les,&st.sum_of_credit);
	}

	if(st.number==x){
		printf("Ogrenci numarasi:%d AD:%s SOYAD:%s aldigi ders sayisi:%d toplam kredisi:%d\n",st.number,st.name,st.surname,st.num_of_les,st.sum_of_credit);
	while(!feof(fp2)){
		fscanf(fp2,"%d %s %d %d %d\n",&ls.code,ls.name,&ls.credit,&ls.quota,&ls.tcode);
		codes[i]=ls.code;
		i++;
		printf("Ders kodu:%d\nDers Adi:%s\nDers kotasi:%d\nOgretmen kodu:%d\n",ls.code,ls.name,ls.quota,ls.tcode);
	}
	printf("sectiginiz dersin kodunu giriniz.");
	scanf("%d",&pick);
	while(codes[n]!=pick && n<i){
		n++;
	}
	if(codes[n]!=pick) printf("yanlis giris yaptiniz ders mevcut degildir.");
	else {
		rewind(fp2);
		while(!feof(fp2) && ls.code!=pick){
		fscanf(fp2,"%d %s %d %d %d\n",&ls.code,ls.name,&ls.credit,&ls.quota,&ls.tcode);	
}
		if(st.sum_of_credit+ls.credit<=25 && st.num_of_les+1<=10){
		char *instime;
		instime=(char*)malloc(30*sizeof(char));
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		sprintf(instime, "%d-%02d-%02d/%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		fprintf(fp3,"%d %d %s\n",pick,st.number,instime);
		free(instime);
	rewind(fp4);
	i=0;
	while(!feof(fp4)){
		fscanf(fp4,"%d %s %s %d %d\n",&(arr+i)->number,(arr+i)->name,(arr+i)->surname,&(arr+i)->num_of_les,&(arr+i)->sum_of_credit);
		if((arr+i)->number==st.number){
			(arr+i)->num_of_les++;
			(arr+i)->sum_of_credit=(arr+i)->sum_of_credit+ls.credit;
		}
		arr=(student*)realloc(arr,(i+2)*sizeof(student));
		i++;
	}
	fclose(fp4);
	fp4=fopen("Öðrenciler.txt","w");
	for(n=0;n<i;n++){
		fprintf(fp4,"%d %s %s %d %d\n",(arr+n)->number,(arr+n)->name,(arr+n)->surname,(arr+n)->num_of_les,(arr+n)->sum_of_credit);
	}
	printf("\nDers basariyla eklendi ve ogrenci bilgileri guncellendi.\n");
}
else printf("kredi asimi ya da ders sayisi fazlaligindan ders eklenilemedi.");
}
}
else printf("ogrenci bulunamadi.");
	free(codes);
	free(arr);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
}
void show_lessons(){
	FILE *fp2;
	fp2=fopen("dersler.txt","r");
	lesson ls;
	while(!feof(fp2)){
		fscanf(fp2,"%d %s %d %d %d\n",&ls.code,ls.name,&ls.credit,&ls.quota,&ls.tcode);
		printf("Ders kodu:%d\nDers Adi:%s\nDers kredisi:%d\nDers kotasi:%d\nOgretmen kodu:%d\n",ls.code,ls.name,ls.credit,ls.quota,ls.tcode);
	}
	fclose(fp2);
}
void show_teachers(){
	FILE *fp1;
	fp1=fopen("ogretim_uyeleri.txt","r");
	teacher t1;
	printf("\n\t\t\tOGRETMENLER\n");
	while(!feof(fp1)){
		fscanf(fp1,"%d %s %s %s\n",&t1.id,t1.name,t1.surname,t1.unvan);
		printf("ID:%d\nAD:%s\nSOYAD:%s\nUNVAN:%s\n",t1.id,t1.name,t1.surname,t1.unvan);
	}
	fclose(fp1);
}
void delete_student(){
	FILE *fp4;
	int pick,i=0,n;
	student st,*arr,temp;
	arr=(student*)malloc(sizeof(student));
	arr->number=0;
	fp4=fopen("Öðrenciler.txt","r");
	printf("Silmek istediginiz ogrencinin numrasini giriniz:"); scanf("%d",&pick);
	while(!feof(fp4) && pick!=st.number){	
	fscanf(fp4,"%d %s %s %d %d",&st.number,st.name,st.surname,&st.num_of_les,&st.sum_of_credit);
	}
	if(pick==st.number){
		rewind(fp4);
		while(!feof(fp4)){
			fscanf(fp4,"%d %s %s %d %d\n",&(arr+i)->number,(arr+i)->name,(arr+i)->surname,&(arr+i)->num_of_les,&(arr+i)->sum_of_credit);
			if(pick==(arr+i)->number){
			i--;
	}
			arr=(student*)realloc(arr,(i+2)*sizeof(student));
			i++;
	}
	fclose(fp4);
	fp4=fopen("Öðrenciler.txt","w");
	for(n=0;n<i;n++){
	fprintf(fp4,"%d %s %s %d %d\n",(arr+n)->number,(arr+n)->name,(arr+n)->surname,(arr+n)->num_of_les,(arr+n)->sum_of_credit);
	}
	fclose(fp4);
}
	else {
	printf("bu numarada ogrenci yoktur.");
	fclose(fp4);
	free(arr);
}
}
void delete_lesson(){
	FILE *fp;
	int pick,i=0,c=0,x=0;
	fp=fopen("dersler.txt","r");
	lesson ls,*arr;
	ls.code=0;
	arr=(lesson*)malloc(sizeof(lesson));
	arr->code=0;
	show_lessons();
	printf("silmek istediginiz dersin kodunu giriniz:");
	scanf("%d",&pick);
	while(!feof(fp) && pick!=ls.code){
		fscanf(fp,"%d %s %d %d %d\n",&ls.code,ls.name,&ls.credit,&ls.quota,&ls.tcode);
	}
	if(pick==ls.code){
		rewind(fp);
		while(!feof(fp)){
			fscanf(fp,"%d %s %d %d %d\n",&(arr+i)->code,(arr+i)->name,&(arr+i)->credit,&(arr+i)->quota,&(arr+i)->tcode);
			if(pick==(arr+i)->code){
				i--;
}
			arr=(lesson*)realloc(arr,(i+2)*sizeof(lesson));
			i++;
	}
	fclose(fp);
	fp=fopen("dersler.txt","w");
	for(c=0;c<i;c++){
		fprintf(fp,"%d %s %d %d %d\n",(arr+c)->code,(arr+c)->name,(arr+c)->credit,(arr+c)->quota,(arr+c)->tcode);
	}
		printf("%d kodunda ki ders silinmistir.",pick);
}
		else if(pick!=ls.code){
			printf("ders bulunamadi.");
		}
		fclose(fp);
		free(arr);
}
void delete_teacher(){
	FILE *fp;
	int pick,i=0,c=0,x=0;
	fp=fopen("ogretim_uyeleri.txt","r");
	teacher tc,*arr;
	tc.id=0;
	arr=(teacher*)malloc(sizeof(teacher));
	arr->id=0;
	show_teachers();
	printf("silmek istediginiz ogretmenin id'sini giriniz:");
	scanf("%d",&pick);
	while(!feof(fp) && pick!=tc.id){
		fscanf(fp,"%d %s %s %s\n",&tc.id,tc.name,tc.surname,tc.unvan);
	}
	if(pick==tc.id){
		rewind(fp);
		while(!feof(fp)){
			fscanf(fp,"%d %s %s %s\n",&(arr+i)->id,(arr+i)->name,(arr+i)->surname,(arr+i)->unvan);
			if(pick==(arr+i)->id){
				i--;
}
			arr=(teacher*)realloc(arr,(i+2)*sizeof(teacher));
			i++;
	}
	fclose(fp);
	fp=fopen("ogretim_uyeleri.txt","w");
	for(c=0;c<i;c++){
		fprintf(fp,"%d %s %s %s\n",(arr+c)->id,(arr+c)->name,(arr+c)->surname,(arr+c)->unvan);
	}
		printf("%d id'sinde ki ogretmen silinmistir.",pick);
}
		else if(pick!=tc.id){
			printf("Ogretmen bulunamadi.");
		}
		fclose(fp);
		free(arr);
}
void show_lessons_with_tid(){
	FILE *fp2;
	fp2=fopen("dersler.txt","r");
	lesson ls;
	int pick;
	printf("\nDerslerini ogrenmek istediginiz ogretmenin id'sini giriniz:"); scanf("%d",&pick);
	while(!feof(fp2)){
		fscanf(fp2,"%d %s %d %d %d\n",&ls.code,ls.name,&ls.credit,&ls.quota,&ls.tcode);
		if(pick==ls.tcode){
		printf("Ders kodu:%d\nDers Adi:%s\nDers kredisi:%d\nDers kotasi:%d\nOgretmen kodu:%d\n",ls.code,ls.name,ls.credit,ls.quota,ls.tcode);
}
	}
	fclose(fp2);
}
void show_students_with_lcode(){
	FILE *fp,*fp1;
	student st;
	fp=fopen("Öðrenciler.txt","r");
	fp1=fopen("ÖðrenciDersKayýt.txt","r");
	int pick,lscode,stnum;
	char time[50];
	printf("\nOgrencileri gormek istediginiz dersin kodunu giriniz."); scanf("%d",&pick);
	printf("\n\t\t\tDersi alan ogrenciler\n");
	while(!feof(fp1)){
		fscanf(fp1,"%d %d %s\n",&lscode,&stnum,time);
		rewind(fp);
		if(lscode==pick){
			while(!feof(fp)){
				fscanf(fp,"%d %s %s %d %d\n",&st.number,st.name,st.surname,&st.num_of_les,&st.sum_of_credit);
				if(st.number==stnum){
				printf("\nNumara: %d\nIsim: %s\nSoyisim: %s\nToplam Ders Sayisi: %d\nToplam Kredi Sayisi: %d\n",st.number,st.name,st.surname,st.num_of_les,st.sum_of_credit);
}
}
		}
	}
	fclose(fp);
	fclose(fp1);
	printf("menuye donmek icin herhangi bir tusa basin.");
	getch();
}
void show_lessons_with_stnum(){
	FILE *fp,*fp1;
	student st;
	fp=fopen("Öðrenciler.txt","r");
	fp1=fopen("ÖðrenciDersKayýt.txt","r");
	char time[50];
	int pick;
	printf("\nDerslerini gormek istediginiz ogrencinin numarasini giriniz."); scanf("%d",&pick);
	
	
	
	fclose(fp);
	fclose(fp1);
	printf("menuye donmek icin herhangi bir tusa basin.");
	getch();
}
void student_update(){
	FILE *fp;
	fp=fopen("Öðrenciler.txt","r");
	student st,*arr,tmp;
	arr=(student*)malloc(sizeof(student));
	int pick,i=0,pick1,c=0,true=0,temp;
	printf("\nguncelleme yapacaginiz ogrencinin numarasini giriniz."); scanf("%d",&pick);
	printf("\nguncellemek istediginizi seciniz\nNumara: 0\nIsim: 1\nSoyisim: 2\nToplam ders sayisi: 3\nToplam kredi: 4"); scanf("%d",&pick1);
	while(!feof(fp)){
		fscanf(fp,"%d %s %s %d %d\n",&(arr+i)->number,(arr+i)->name,(arr+i)->surname,&(arr+i)->num_of_les,&(arr+i)->sum_of_credit);
		if((arr+i)->number==pick){
			memcpy(&tmp,arr+i,sizeof(student));
			true=1;
		}
		arr=(student*)realloc((arr),(i+2)*sizeof(student));
		i++;
	}
	if(true==1){
	switch(pick1){
		case 0:
			printf("yeni numara giriniz"); scanf("%d",&tmp.number);
			break;
		case 1:
			printf("yeni ad giriniz."); scanf("%s",tmp.name);
			break;
		case 2:
			printf("yeni soyad giriniz."); scanf("%s",tmp.surname);
			break;
		case 3:
			temp=tmp.num_of_les;
			printf("yeni toplam ders sayisini giriniz."); scanf("%d",&tmp.num_of_les);
			if(tmp.num_of_les>10){
				tmp.num_of_les=temp;
				printf("fazla giris yapildi maksimum 10 ders alabilirsiniz, degisiklik yapilmadi.");
			}
			break;
		case 4:
			temp=tmp.sum_of_credit;
			printf("yeni toplam kredi sayisini giriniz."); scanf("%d",&tmp.sum_of_credit);
			if(tmp.sum_of_credit>10){
				tmp.sum_of_credit=temp;
				printf("fazla giris yapildi maksimum 25 kredi alabilirsiniz, degisiklik yapilmadi.");
			}
			break;
	}
	fclose(fp);
	fp=fopen("Öðrenciler.txt","w");
	while(c<i){
		if((arr+c)->number!=pick){
			fprintf(fp,"%d %s %s %d %d\n",(arr+c)->number,(arr+c)->name,(arr+c)->surname,(arr+c)->num_of_les,(arr+c)->sum_of_credit);
			c++;
}
		else{
			fprintf(fp,"%d %s %s %d %d\n",tmp.number,tmp.name,tmp.surname,tmp.num_of_les,tmp.sum_of_credit);
			c++;
	}
}
}
	else printf("giris yaptiginiz numara yanlis.");
	free(arr);
	fclose(fp);
}
void teacher_update(){
	FILE *fp;
	teacher tc,*arr,tmp;
	arr=(teacher*)malloc(sizeof(teacher));
	fp=fopen("ogretim_uyeleri.txt","r");
	int pick,i=0,pick1,c=0,true=0,temp;
	printf("\nguncelleme yapacaginiz ogretim uyesinin numarasini giriniz: "); scanf("%d",&pick);
	printf("\nguncellemek istediginizi seciniz\nID: 0\nIsim: 1\nSoyisim: 2\nUnvan: 3\n "); scanf("%d",&pick1);
	while(!feof(fp)){
		fscanf(fp,"%d %s %s %s\n",&(arr+i)->id,(arr+i)->name,(arr+i)->surname,(arr+i)->unvan);
		if((arr+i)->id==pick){
			memcpy(&tmp,arr+i,sizeof(teacher));
			true=1;
		}
		arr=(teacher*)realloc((arr),(i+2)*sizeof(teacher));
		i++;
	}
	if(true==1){
	switch(pick1){
		case 0:
			printf("yeni id giriniz"); scanf("%d",&tmp.id);
			break;
		case 1:
			printf("yeni ad giriniz."); scanf("%s",tmp.name);
			break;
		case 2:
			printf("yeni soyad giriniz."); scanf("%s",tmp.surname);
			break;
		case 3:
			printf("yeni unvan giriniz."); scanf("%s",tmp.unvan);
			break;
	}
	fclose(fp);
	fp=fopen("ogretim_uyeleri.txt","w");
	while(c<i){
		if((arr+c)->id!=pick){
			fprintf(fp,"%d %s %s %s\n",(arr+c)->id,(arr+c)->name,(arr+c)->surname,(arr+c)->unvan);
			c++;
}
		else{
			fprintf(fp,"%d %s %s %s\n",tmp.id,tmp.name,tmp.surname,tmp.unvan);
			c++;
	}
}
}
	else printf("giris yaptiginiz numara yanlis.");
	free(arr);
	fclose(fp);
}
void lesson_update(){
	FILE *fp;
	fp=fopen("dersler.txt","r");
	lesson ls,*arr,tmp;
	arr=(lesson*)malloc(sizeof(lesson));
	int pick,i=0,pick1,c=0,true=0,temp;
	printf("\nguncelleme yapacaginiz dersin kodunu giriniz."); scanf("%d",&pick);
	printf("\nguncellemek istediginizi seciniz\nKod: 0\nIsim: 1\nKredi: 2\nKota: 3\nOgretmen kodu: 4"); scanf("%d",&pick1);
	while(!feof(fp)){
		fscanf(fp,"%d %s %d %d %d\n",&(arr+i)->code,(arr+i)->name,&(arr+i)->credit,&(arr+i)->quota,&(arr+i)->tcode);
		if((arr+i)->code==pick){
			memcpy(&tmp,arr+i,sizeof(lesson));
			true=1;
		}
		arr=(lesson*)realloc((arr),(i+2)*sizeof(lesson));
		i++;
	}
	if(true==1){
	switch(pick1){
		case 0:
			printf("yeni kod giriniz"); scanf("%d",&tmp.code);
			break;
		case 1:
			printf("yeni ad giriniz."); scanf("%s",tmp.name);
			break;
		case 2:
			printf("yeni kredi giriniz."); scanf("%d",&tmp.credit);
			break;
		case 3:
			printf("yeni ders kotasini giriniz."); scanf("%d",&tmp.quota);
			break;
		case 4:
			printf("yeni ogretmen kodunu giriniz."); scanf("%d",&tmp.tcode);
			break;
	}
	fclose(fp);
	fp=fopen("dersler.txt","w");
	while(c<i){
		if((arr+c)->code!=pick){
			fprintf(fp,"%d %s %d %d %d\n",(arr+c)->code,(arr+c)->name,(arr+c)->credit,(arr+c)->quota,(arr+c)->tcode);
			c++;
}
		else{
			fprintf(fp,"%d %s %d %d %d\n",tmp.code,tmp.name,tmp.credit,tmp.quota,tmp.tcode);
			c++;
	}
}
}
	else printf("giris yaptiginiz numara yanlis.");
	free(arr);
	fclose(fp);
}
void class_list(){
	FILE *fp,*fp1,*fp2,*fp3;
	int pick,tcode,stcode,*courses,i=0,a,b,c=0;
	char *time;
	courses=(int*)malloc(5*sizeof(int));
	time=(char*)malloc(50*sizeof(char));
	lesson ls;
	student st;
	fp=fopen("DERSKODU_SINIFLISTESI.txt","w");
	fp1=fopen("ÖðrenciDersKayýt.txt","r");
	fp2=fopen("dersler.txt","r");
	fp3=fopen("Öðrenciler.txt","r");
	printf("ogretim uye id giriniz:"); scanf("%d",&pick);
	while(!feof(fp2)){
		fscanf(fp2,"%d %s %d %d %d\n",&ls.code,ls.name,&ls.credit,&ls.quota,&ls.tcode);
		if(ls.tcode==pick){
			courses[i]=ls.tcode;
			i++;
		}
	}
	while(c<i){
		fprintf(fp,"\t\t\t%d kodlu dersin sýnýf listesi\n",courses[c]);
		while(!feof(fp1)){
			fscanf(fp1,"%d %d %s\n",&a,&b,time);
			if(a==courses[c]){
				while(!feof(fp3)){
					fscanf(fp3,"%d %s %s %d %d\n",&st.number,st.name,st.surname,&st.num_of_les,&st.sum_of_credit);
					fprintf(fp,"\nOgrenci numarasi: %d\t Ad soyad: %s %s\tDers sayisi: %d\ttoplam kredisi: %d\n",st.number,st.name,st.surname,st.num_of_les,st.sum_of_credit);
				}
			}
		}
		rewind(fp1);
		c++;
	}
	fclose(fp3);
	fclose(fp);	
	fclose(fp1);
	fclose(fp2);
	free(time);
	free(courses);
}
int main() {
	int giris=1;
	while(giris!=0){
		printf("\t\t\t DERS KAYIT SISTEMI\n");
		printf("ogretmen eklemek icin: 1\nders eklemek icin: 2\nogrenci eklemek icin: 3\nders kaydi icin:4\ndersleri gormek icin: 5\nogretim uyelerini gormek icin: 6\nogrenci silmek icin: 7\nders silmek icin: 8\nOgretmen silmek icin: 9\nBir ogretmenin derslerini gormek icin: 10\nDerse gore ogrencileri gormek icin: 11\nOgrenci guncellemek icin: 12\nOgretim uyesi guncellemek icin: 13\nDers guncellemesi icin: 14\nSinif listeleri icin: 15\ncikis icin: 0 \n");
		scanf("%d",&giris);
		switch(giris){
			case 0: 
				return 0;
			case 1:
				addteacher();
				break;
			case 2:
				addlesson();
				break;
			case 3:
				addstudent();
				break;
			case 4:
				course_enroll();
				break;
			case 5:
				show_lessons();
				break;
			case 6:
				show_teachers();
				break;
			case 7:
				delete_student();
				break;
			case 8:
				delete_lesson();
				break;
			case 9:
				delete_teacher();
				break;
			case 10:
				show_lessons_with_tid();
				break;
			case 11:
				show_students_with_lcode();
				break;
			case 12:
				student_update();
				break;
			case 13:
				teacher_update();
				break;
			case 14:
				lesson_update();
				break;
			case 15:
				class_list();
				break;
		}
	}
	return 0;
}
