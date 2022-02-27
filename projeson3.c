#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void ANA_MENU();
void FIRMA_GIRISI();
void MUSTERI_GIRISI();
void Otobus_Ekle();
void Sefer_Bilgisi();
void Koltuk_Bilgisi();
void Sefer_No();
void Kapasite();
void Otobus_No();
void bilgi();
char rando[]={"555555"};
char NUMARA[]={"55555555"};
int hasilat,kisi_basi_ucret;
FILE *file;
int sayi;
int apasite;
int Personel;
char Otobus_Modeli[10];
char baslangic_sehri[20],varis_sehri[20];
int kalkis_saat,sonuc,islem;
int main(){
	
	
 ANA_MENU();

return 0;
}

void ANA_MENU(){
    int x,i=0;
    tekrar:
    printf("ANA MENU\n1.FIRMA GIRISI\n2.MUSTERI GIRISI\n3.CIKIS\n\n");
    printf("Lutfen seciminizi yapiniz:");
    scanf("%d",&x);
    if (x<4){
	    if (x==1){
	        FIRMA_GIRISI();
	    }
        else if(x==2){
    	    MUSTERI_GIRISI();
	    }
	    else if(x==3){
		    printf("cikis yapiliyor");
		    exit(1);
        }
    }
     
    else{
        printf("\nGecersiz giris yaptiniz.\n");
	    goto tekrar;
    }

}

void FIRMA_GIRISI(){

	int x;
	tekrar:
	printf("\n1-Otobus Ekle\n2-Sefer Bilgisi Ekle\n3-Sefer/Koltuk Bilgisi\n4-Bir Ust Menuye Don\n");
    printf("Lutfen seciminizi yapiniz:");
    scanf("%d",&x);
    if (x<5){
    	if (x==1){
		    Otobus_Ekle();
	    }
        else if (x==2){
	        Sefer_Bilgisi();
	    }
	    else if (x==3){
		    Koltuk_Bilgisi();
	    }
	    else if (x==4){
		    ANA_MENU();
	    }
    }
    else
    {
        printf("Gecersiz giris tekrar deneyin\n");
	     goto tekrar;
    }
}
void Otobus_Ekle(){

  
   
	printf("\nOtobus_Modeli:");
	scanf("%s",Otobus_Modeli);
	 
	Otobus_No();
}

void Otobus_No(){

	srand(time(NULL));


	sayi=rand()%10+1;
    printf("Otobus No:%d\n",sayi);


    Kapasite();
}
void Kapasite(){

	printf("Kapasite:");
	tekrar:
	scanf("%d",&apasite);
	if (apasite>30){
		printf("Personel sayisi:3\n\n");
		Personel=3;
	}
    else if(apasite<30 && apasite>0){
        printf("Personel sayisi:2\n\n");
        Personel=2;
    
	}
	else{
		printf("Hatali islem girdiniz tekrar giriniz:");
		goto tekrar;
	}
    file=fopen("Otobus_Ekle.txt","a");
    fprintf(file,"Otobus_No:%d\tOtobus_Modeli:%s\tPersonel:%d\tKapasite:%d\t ",sayi,Otobus_Modeli,Personel,apasite);
    
    fclose(file);
	FIRMA_GIRISI();
}

void Sefer_Bilgisi(){
	int Otobus_No;


	printf("Otobus numarasini giriniz:");
	scanf("%d",&Otobus_No);
	
    
    int saat,varis_saat;
    geridon:
    printf("saati giriniz:");
    scanf("%d",&saat);
    kalkis_saat=saat*100+55;
        

        
    if(saat<24 && saat>=0){
        printf("kalkissaati:%d\n" ,kalkis_saat);
    }
    else{
        printf("Hatali deger girdiniz."); 
        goto geridon;
        }
    
    printf("varis saatini:");
    scanf("%d",&varis_saat);
    replay:
    
    sonuc=varis_saat*100;
    islem=sonuc-kalkis_saat-40;
    if(apasite>30 && Personel==3){
        printf("yolculuk suresi:%d",abs(islem));
    }
    else if(apasite<30 && Personel==2){
        if(islem>400){
            printf("hatali kullanim tekrar deneyiniz:");
            goto replay;  
        }
        else;
            printf("yolculuk suresi:%d",abs(islem));
    }
    

    Sefer_No();
  }

void Sefer_No(){
    char hex[] = {"0123456789ABCDEF"};  
    int i=0;
    srand(time(NULL));
    for( i; i<4;i++){
        rando[i+2]=hex[(rand()%16)];
    } 
    file=fopen("Otobus_Ekle.txt","a");
    fprintf(file,"%s\n ",rando);
    fclose(file);


        
    file=fopen("Sefer_No.txt","a");
    fprintf(file,"Sefer_No:%s\n",rando);
    fclose(file);
    printf("\nSefer numaraniz :%s\n",rando);

    printf("\nSeferin baslayacagi sehri giriniz:" );
    scanf("%s" ,baslangic_sehri);
    printf("\nSeferin bitecegi sehri giriniz:" );
    scanf("%s" ,varis_sehri);
    
    printf("\nBu yolculuk sonunda toplanmasi gereken hasilat degerini giriniz:");
    scanf("%d" ,&hasilat);

    kisi_basi_ucret = hasilat /apasite;

    printf("\nKisi basi odenmesi gereken ucret:%d" ,kisi_basi_ucret);
    file=fopen("Sefer_Bilgisi.txt","a");

    fprintf(file," %s\t %s\t %s\t %d\t %d\t %d\t %d \t%d\t%d\n",rando,baslangic_sehri,varis_sehri,hasilat,kisi_basi_ucret,islem,kalkis_saat,sonuc,sayi);
        
    fclose(file);
    FIRMA_GIRISI();
	}
void Koltuk_Bilgisi(){

	char Sefer_No[35];
    int secim;
    	printf("1-Bos koltuklar\n2-Sefer bilgisi\n");
	printf("Lutfen seciminizi yapiniz:");
	
	scanf("%d",&secim);

	if(secim==1){
	file=fopen("Sefer_No.txt","r");
    while(!feof(file)){
        printf("%c",fgetc(file));
    }
    fclose(file);
    printf("Sefer_No:");
    scanf("%s",Sefer_No);

		file=fopen("Otobus_Ekle.txt","r");
 

        while(!feof(file)){
            
        
            int i,j;
            fscanf(file,"%d %s %d %d %s",&sayi,&Otobus_Modeli,&Personel,&apasite,&rando);
            if(strcmp(rando,Sefer_No)==0){
            
            
                for(i=1;i<=(apasite/4);i++){
                    printf(" %2.d\t",i);
                    for(j=1;j<=4;j++){
                        printf(" [ ]");
                    }
                printf("\n");
                    }
                if((apasite%4)!=0)
                    printf("%2d\t",(apasite/4)+1);
                for(i=1;(i<=apasite%4);i++){
                    printf("[ ]");
                }
        }
        fclose(file);
        FIRMA_GIRISI();
        }
    }
	else if(secim==2){
	    bilgi();
	

    }
}
void bilgi(){
	    char Sefer_No[35];
	    file=fopen("Sefer_No.txt","r");
    while(!feof(file)){
        printf("%c",fgetc(file));
    }
    fclose(file);
    printf("Sefer_No:");
    scanf("%s",Sefer_No);
		file=fopen("Sefer_Bilgisi.txt","r");
        while(!feof(file)){

            fscanf(file,"%s %s %s %d %d %d %d %d %d ",&rando,&baslangic_sehri,&varis_sehri,&hasilat,&kisi_basi_ucret,&islem,&kalkis_saat,&sonuc,&sayi);
            if(strcmp(rando,Sefer_No)==0){
                printf("sefer no:%s\tbaslangic_sehri:%s\tvaris_sehri:%s\thasilat:%d\tkisi_basi_ucret:%d\tsure:%d\tkalkis_saat:%d\tvaris_saat:%d\totobus no:%d\n",rando,baslangic_sehri,varis_sehri,hasilat,kisi_basi_ucret,islem,kalkis_saat,sonuc,sayi);
            }
        }
        fclose(file);
    FIRMA_GIRISI();
	
	
}
void MUSTERI_GIRISI(){
	
	int tercih,koltuk_no,onay;
	char ad[20],soyad[20];
	char rez_no[25];


	printf("\n1-Seferleri Listele\n2-Sefer Rezervasyon Yap\n3-Bir ust Menuye Don\n4-Rezervasyon Goster\n");
	printf("Lutfen seciminizi yapiniz\n");
	scanf("%d",&tercih);
    do{
    	if(tercih==1){
            file=fopen("Sefer_Bilgisi.txt","r");
            while(!feof(file)){
                fscanf(file,"%s %s %s %d %d %d %d %d %d ",&rando,&baslangic_sehri,&varis_sehri,&hasilat,&kisi_basi_ucret,&islem,&kalkis_saat,&sonuc,&sayi);
                printf("sefer no:%s\tbaslangic_sehri:%s\tvaris_sehri:%s\thasilat:%d\tkisi_basi_ucret:%d\tsure:%d\tkalkis_saat:%d\tvaris_saat:%d\totobus no:%d\n",rando,baslangic_sehri,varis_sehri,hasilat,kisi_basi_ucret,islem,kalkis_saat,sonuc,sayi);
                
			}
			fclose(file);
            printf("\n");
            MUSTERI_GIRISI();
        }
        else if(tercih==2){
        	  char Sefer_No[35];
	        file=fopen("Sefer_No.txt","r");
            while(!feof(file)){
            printf("%c",fgetc(file));
            }
            fclose(file);
            printf("Sefer_No:");
            scanf("%s",Sefer_No);
		    file=fopen("Sefer_Bilgisi.txt","r");
            while(!feof(file)){

                fscanf(file,"%s %s %s %d %d %d %d %d %d ",&rando,&baslangic_sehri,&varis_sehri,&hasilat,&kisi_basi_ucret,&islem,&kalkis_saat,&sonuc,&sayi);
                if(strcmp(rando,Sefer_No)==0){
                    printf("sefer no:%s\tbaslangic_sehri:%s\tvaris_sehri:%s\thasilat:%d\tkisi_basi_ucret:%d\tsure:%d\tkalkis_saat:%d\tvaris_saat:%d\totobus no:%d\n",rando,baslangic_sehri,varis_sehri,hasilat,kisi_basi_ucret,islem,kalkis_saat,sonuc,sayi);
            }
        }
        fclose(file);
        printf("Ad:");scanf("%s",&ad);
        printf("soyad:");scanf("%s",&soyad);
        printf("koltuk no:");scanf("%d",&koltuk_no);
        printf("onayliyormusunuz?(evet='1'    hayir='2')");
        scanf("%d",&onay);
        if(onay==1){
            char number[] = {"0123456789ABCDEF"};  
            int i=0;
            srand(time(NULL));
            for( i; i<8;i++){
                NUMARA[i]=number[(rand()%16)];
            
            } 
            printf("rezervasyon numara:%s",NUMARA);
            file=fopen("kulanici.txt","a");
            fprintf(file,"name:%s\tsurname:%s\tno:%s\n",ad,soyad,NUMARA);
            fclose(file);
            
            MUSTERI_GIRISI();
		}
		else if(onay==2){
			printf("iptal edildi...");
			ANA_MENU();
		}

		}
        else if(tercih==3){
        	ANA_MENU();
        } 
        else if(tercih==4){
        	printf("rezervasyon numarasini giriniz:");scanf("%s",&rez_no);
        	file=fopen("kulanici.txt","r");
        	fscanf(file,"%s %s %s",&ad,&soyad,&NUMARA);
        	while(!feof(file)){
				if(strcmp(rez_no,NUMARA)==0){
                    printf("name:%s\tsurname:%s\trezervasyon numara:%s\t\n",ad,soyad,NUMARA);
                }
                
            }
            fclose(file);
           
		}
	}while(tercih!=5);
}



