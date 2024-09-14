#include <stdio.h>     
#include <windows.h> 
#include <stdlib.h>  
#include <conio.h>
FILE *dosyaptr;
void kisiekle();
void guncelle(char Ad[60]);
void sil(char name[60]);
void arama();
void kisiarama(char i[60]);
int num(char numara[12]);
int gonder;
int islemdevam();
void listele();
char cevap,isim[30];
struct kisi{
	char ad[60];
	char numara[12];	
	char soyad[60];
	char cinsiyet[6];
	char tc[12];
	char eposta[60];
	char baba[60];
	char adres[60];
	
	
	
}data;


int main(){
	
	int islem;
	system("color 6f");
	system("cls");
	printf("\n\n\t\t\t\tMENU\n");
	printf("\t\t\t __________________________________\n");
	printf("\t\t\t |	                 	  |\n");
	printf("\t\t\t |	kisi ekle     [1]	  |\n");
    printf("\t\t\t |	kisi listele  [2]	  |\n");
    printf("\t\t\t |	kisi guncelle [3]	  |\n");
    printf("\t\t\t |	kisi sil      [4]	  |\n");
    printf("\t\t\t |	kisi bul      [5]	  |\n");
	printf("\t\t\t |________________________________|\n\n");
	printf("\t\t\t islem girin:");
	scanf("%d",&islem);
	

	if( islem==1 || islem==2 || islem==3 || islem==4 || islem==5 ){
		switch(islem){
			case 1: kisiekle(); break;
			case 2: listele();  break;
			case 3:
				{ do{printf("\n\t\t\tguncellenecek isim giriniz :");
					_flushall();
					gets(isim);
				guncelle(isim);
				for(;;){
						printf("\n");
						printf("\nmenuye don	[M]");
						printf("\nguncellemeye devam et	[G]");
						printf("\ncikis yap	[E]");
						cevap = _getche(); printf("\n"); system("cls");
						if(cevap== 'M' || cevap== 'm'){
						main(); break;
						}else if(cevap == 'g'|| cevap == 'G')
						{	
						 islem = 3; break;
						}
						else if(cevap == 'e' || cevap == 'E')
						{
							exit(1); break;	
						}
						else 
						{printf("\n yanlis tercih girdiniz !.....\n"); 
						}
					}
					}while (islem =3); break;
				}
			case 4:	{
				do{
				printf("\n\t\t\tsilinecek isim giriniz: ");
				_flushall();
				scanf("%s",&isim);
				sil(isim);
				for(;;)
				{printf("\n\tmenuye donmek icin				 [M]");
				printf("\n\tsilme islemine devam etmek icin  [S]");
				printf("\n\tcikis yapmak icin				 [E]");
				cevap= _getche(); printf("\n"); system("cls");
				if(cevap == 'M' || cevap=='m')
				{
					main(); break;
				}
				else if(cevap=='S' || cevap=='s')
				{
					islem= 4; break;
				}
				else if(cevap== 'E' || cevap == 'e' )
				{
					exit(1); break;
				}
				else
				{ 
				printf("\n\t yanlis tercih girdiniz !.... \n");
				}	
					
				}
			
				}while(islem=4); break;
			}
			case 5: arama(); break;
		}
	}
	else
		printf("\n\t\t lutfen belirtilen sayilari giriniz!...."); Sleep(1000); main();
	
	return 0;	}
/* kisi ekleme islemi buradan devam eder*/
void kisiekle(){
	dosyaptr= fopen("rehber.txt","a");
	
	if(dosyaptr==NULL){		printf(" Boyle bir dosya bulunmadý!..");			
	}else
	{
		system("cls");
		printf("yeni kayit \n\n");
		printf("\tad: ");
		scanf("%s", &data.ad);
		fprintf(dosyaptr, "%s ", data.ad);
		printf("\tsoyad: ");
		scanf("%s", & data.soyad);
		fprintf(dosyaptr, "%s ", data.soyad);
		
		do{
	    	printf("\tnumara: ");
			scanf("%s", &data.numara);
			gonder = num(data.numara);
		}while(gonder == 0);
		fprintf(dosyaptr, "%s ", data.numara);	
		
		do{
	    	printf("\ttc: ");
			scanf("%s", &data.tc);
			gonder = num(data.tc);
		}while(gonder == 0);
		fprintf(dosyaptr, "%s  ", data.tc);	
		
		printf("\tcinsiyet: ");
		scanf("%s", &data.cinsiyet);
		fprintf(dosyaptr, "%s ", data.cinsiyet);
		printf("\tbaba: ");
		scanf("%s", &data.baba);
		fprintf(dosyaptr, "%s ", data.baba);
		printf("\teposta: ");
		scanf("%s", &data.eposta);
		fprintf(dosyaptr, "%s ", data.eposta);
		printf("\tadres: ");
		scanf("%s", &data.adres);
		fprintf(dosyaptr, "%s\t  \n", data.adres);											
		fclose(dosyaptr);
		printf("kisi eklendi.\n\n");		
	} islemdevam(); 
}
/*listeleme islemi buradan devam eder*/
void listele(){
	
	dosyaptr= fopen("rehber.txt","r");
	int secim;
	
	if(dosyaptr==NULL){
		while(1){
			printf("\n\t\tKisi bulunmamaktadir....");
			printf("kisi eklemek icin [E]:");
			secim = _getche(); system("cls");
			if(secim== 'e' || secim == 'E'){
				kisiekle();
			}else{
				printf("\tyanlis deger girdiniz");
			}
		}
	}else{
		system("cls");
		printf("\n\t _________________________________\n");
		printf("\t_____________REHBER________________\n\n");
		while(fscanf(dosyaptr, "%s%s%s%s%s%s%s%s", &data.ad, &data.soyad, &data.numara, &data.tc, &data.cinsiyet, &data.baba, &data.eposta, &data.adres) != EOF){
			printf("ad:\t%s\nsoyad:	%s\nnumara: %s\ntc:	%s\ncinsiyet:%s\nbaba:	%s\neposta: %s\nadres:	%s\n\n", data.ad, data.soyad, data.numara, data.tc, data.cinsiyet, data.baba, data.eposta, data.adres);
		}
		fclose(dosyaptr);
		islemdevam();
	}
	
}
/*guncelleme islemi buradan devam eder*/
void guncelle(char Ad[60]){
	FILE *dosyaptr , *yeni ;
	int k=0;
	system("cls");
	
dosyaptr = fopen("rehber.txt","r");
	yeni = fopen("rehber1.txt","w");
	
	if(dosyaptr== NULL){
		printf("herhangi bir kisi kayitli degildir.");
	}else{
		rewind(dosyaptr);
		rewind(yeni);
		while(!feof(dosyaptr))
		{
		fscanf(dosyaptr, "%s %s %s %s %s %s %s %s ", &data.ad, &data.soyad, &data.numara, &data.tc, &data.cinsiyet, &data.baba, &data.eposta, &data.adres);
		if(strcmp(data.ad,Ad) == 0)
		{
			k = 1;
		printf("yeni guncelleme \n\n");
		printf("\tad: ");
		scanf("%s", &data.ad);
		fprintf(dosyaptr, "%s ", data.ad);
		printf("\tsoyad: ");
		scanf("%s", & data.soyad);
		fprintf(dosyaptr, "%s ", data.soyad);
		
		do{
	    	printf("\tnumara: ");
			scanf("%s", &data.numara);
			gonder = num(data.numara);
		}while(gonder == 0);
		fprintf(dosyaptr, "%s ", data.numara);	
		
		do{
	    	printf("\ttc: ");
			scanf("%s", &data.tc);
			gonder = num(data.tc);
		}while(gonder == 0);
		fprintf(dosyaptr, "%s  ", data.tc);	
		
		printf("\tcinsiyet: ");
		scanf("%s", &data.cinsiyet);
		fprintf(dosyaptr, "%s ", data.cinsiyet);
		printf("\tbaba: ");
		scanf("%s", &data.baba);
		fprintf(dosyaptr, "%s ", data.baba);
		printf("\teposta: ");
		scanf("%s", &data.eposta);
		fprintf(dosyaptr, "%s ", data.eposta);
		printf("\tadres: ");
		scanf("%s", &data.adres);
		fprintf(dosyaptr, "%s\t  \n", data.adres);	
		printf("\n [Kisi Guncellendi !... ]  \n\n");
		fprintf(yeni, "%s %s %s %s %s %s %s %s\t \n", data.ad, data.soyad, data.numara, data.tc, data.cinsiyet, data.baba, data.eposta, data.adres);
		
			
		}else
		{
		fprintf(yeni, "%s %s %s %s %s %s %s %s\t \n", data.ad, data.soyad, data.numara, data.tc, data.cinsiyet, data.baba, data.eposta, data.adres);

		}
		}
		_fcloseall();
		remove("rehber.txt");
		rename("rehber1.txt","rehber.txt");
		if(k==0){
		printf("\n\t kisi rehberde kayitli degildir."); 	Sleep(500);
		}
	}
	
}
/*silme islemi buradan gerçekleþir*/
void sil(char name[60])
{
	system("cls");
	FILE *dosyaptr, *yeni;
	dosyaptr = fopen("rehber.txt", "r");
	yeni = fopen("rehber1.txt", "w");
	if (dosyaptr == NULL)
	{
		printf("rehberinizde kayitli kimse yoktur!...");
	}
	else
	{	int a = 0;
		rewind(dosyaptr);
		rewind(yeni);
		printf("\n devam etmek istiyormusunuz [E]-[H]\n");
		cevap = _getch(); 
		if (cevap == 'E' || cevap == 'e')
		{
			while (!feof(dosyaptr))
			{
				fscanf(dosyaptr, "%s %s %s %s %s %s %s %s ", &data.ad, &data.soyad, &data.numara, &data.tc, &data.cinsiyet, &data.baba, &data.eposta, &data.adres);
				if (!strcmp(data.ad, name))
				{
					printf("\nSilinen Kisi Bilgileri\n");
					printf("<_______________________>\n");
					printf("Ad:\t%s\nSoyad:  %s\nCepTel: %s\nEvTel:  %s\nIsTel:  %s\nDogumT: %s\ne-posta:%s\nadres: %s\n", data.ad, data.soyad, data.numara, data.tc, data.cinsiyet, data.baba, data.eposta,data.adres);
					printf("\n\tKisi Silindi !..."); Sleep(500);
					a = 1;
				}
				else
					fprintf(yeni, "%s %s %s %s %s %s %s %s\t  \n", data.ad, data.soyad, data.numara, data.tc, data.cinsiyet, data.baba, data.eposta,data.adres);				
				
			}
			_fcloseall();
				remove("rehber.txt");
				rename("rehber1.txt","rehber.txt");
				if(a==0){
					printf("\n\tbu kisi kayitli degildir!...");
				}
		}
		else if(cevap == 'H' || cevap == 'h')
		{
			printf("\n\tsecim iptal ettiniz menuye donuluyor.."); Sleep(1000); main();
		}
		else
		{
		printf("\n\tyanlis harf girdiniz menuye dönülüyor!......"); Sleep(1000); main();
		}
	}
}
void arama()
{
	char name[60];
	dosyaptr=fopen("rehber.txt","r");
	if(dosyaptr==NULL)
	{
		printf("dosya bulunamadi"); Sleep(1000);
	}else
	{system("cls");
	printf("Aranan kisinin adini giriniz:");
				_flushall();
				gets(name); printf("\n"); 
				kisiarama(name);
	}
	islemdevam();
}
void kisiarama(char i[60])
{
	rewind(dosyaptr);
	int f=0;
	while(fscanf(dosyaptr, "%s",data.ad)!=EOF)
	{
		fscanf(dosyaptr, "%s", &data.soyad);		 
		fscanf(dosyaptr, "%s", &data.numara);		
		fscanf(dosyaptr, "%s", &data.tc);
		fscanf(dosyaptr, "%s", &data.cinsiyet);	
		fscanf(dosyaptr, "%s", &data.baba);	
		fscanf(dosyaptr, "%s", &data.eposta);
		fscanf(dosyaptr, "%s", &data.adres);
		
		if(!strcmp(data.ad,i))
		{
			printf("arana kisi...\n\n");
			printf("ad:\t%s\nsoyad:  %s\nnumara: %s\ntc: %s\ncinsiyet: %s\nbaba: %s\neposta: %s\nadres: %s\n\n", data.ad, data.soyad, data.numara, data.tc, data.cinsiyet, data.baba, data.eposta, data.adres);
			f=1;
		}
		
	
	}
		if(f=0){
			printf("\n\tboyle bir kisi yoktur");
		}
	
	
}


int num(char numara[12]){
	
			int dogru=0,yanlis=1;
		if( numara[10]==NULL || numara[9]==NULL || numara[8]==NULL || numara[7]==NULL || numara[6]==NULL || numara[5]==NULL || numara[4]==NULL || numara[3]==NULL || numara[2]==NULL || numara[1]==NULL || numara[0]==NULL)
{  printf("\t\t 11 haneli numara giriniz\n");  Sleep(1000); return dogru;
	}

		return yanlis;
}

int islemdevam(){

while(1){

	printf("\n\n\t\t\t  ______________________________\n");
	printf("\t\t\t |    	   		      	|\n");
	printf("\t\t\t |     Menuye don    [m]	|\n");
	printf("\t\t\t |     kisi ekle     [e]	|\n");	
    printf("\t\t\t |     kisi listele  [l]	| \n");
    printf("\t\t\t |     kisi bul      [b]	|\n");
	printf("\t\t\t |     cikis         [c]	|\n");
	printf("\t\t\t |    	   		      	|\n");
	printf("\t\t\t |______________________________|\n\n");
	printf("\t\t\t islem girin:");
	cevap = _getche(); system("cls");
	if(cevap=='m' || cevap=='M'){
		main();     break;
	}else if(cevap== 'e' || cevap=='E'){
		kisiekle();    break;
	}else if(cevap== 'l' || cevap=='L'){
		listele();   break;
	}else if(cevap== 'B' || cevap=='b'){
	    arama(); break;
	}else if(cevap== 'c' || cevap== 'C'){
		exit(1);  break;
	}else
		printf("\n\tyanlis deger girdiniz:");
	}



return 0;	
}
