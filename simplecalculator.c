#include <stdio.h>
#include <string.h>

void substracktion(int Array1[],int Array2[]){

    int len1 = sizeof(Array1)/sizeof(int);
    int len2 = sizeof(Array2)/sizeof(int);

    // Çıkarma İşlemi İçin Bir İnt Bir Array Oluşturuyorum
    int subsofarrays[len1];

    // Çıkarma İşlemini Gerçekleştiriyorum
    for(int i = len1-1 ; i>=0 ; i--){
        int a = Array1[i] - Array2[i];
        if(a<0){
            Array1[i-1] = Array1[i-1]-1 ;
            a += 10;
            subsofarrays[i] = a;
        }else{
            subsofarrays[i] = a;
        }
    }

    // Çıkarma İşleminin Sonucunun Çıktısını Veriyorum
    printf("\nCikarma Isleminin Sonucu: \n");
    for(int i =0; i<len1; i++){
        printf("%d ",subsofarrays[i]);
    }

}

void sumsofarrays(int Array1[],int Array2[]){

    int len1 = sizeof(Array1)/sizeof(int);
    int len2 = sizeof(Array2)/sizeof(int);

    // Toplama İşleminin Sonucu İçin Toplam Dizisini Oluşturuyorum
    int sumofarrays[len1+1];

    //Toplama İşlemindeki Eldeler İçin Bir Değişken Oluşturuyorum
    int elde = 0;

    // Toplama İşlemini Gerçekleştiriyorum
    int p = len1;
    for(int i = len1-1; i>=0 ; i--){
        int a = Array1[i] + Array2[i];
        if(a>=10){
            if(elde > 0){
                elde--;
                a=a+1;
                a = a%10;
                sumofarrays[p] = a;
                elde++;
            }else{
                a = a%10;
                sumofarrays[p] = a;
                elde++;
            }
        }else if(a<10){
            if(elde>0){
                elde--;
                a++;
                if(a>=10){
                    elde++;
                    a = a%10;
                }
                sumofarrays[p] = a;
            }else{
                sumofarrays[p] = a;
            }
        }
        p--;
    }
    sumofarrays[p] = elde;

    // Toplama İşleminin Sonucunun Çıktısını Veriyorum
    printf("\nToplama Isleminin Sonucu: \n");
    for(int i =0; i<len1+1; i++){
        printf("%d ",sumofarrays[i]);
    }

}

void multiply(int Array1[],int Array2[]){

    int len1 = sizeof(Array1)/sizeof(int);
    int len2 = sizeof(Array2)/sizeof(int);

    // Çarpma İşleminin Sonucu İçin Array Oluşturuyorum
    int multipofarrays[len1+len2];
    int lenmultip = len1+len2;
    for(int i = len1+len2-1 ; i>=0;i--){
        multipofarrays[i] = 0;
    }

    // Çarpma İşlemini Gerçekleştiriyorum
    int counter1 = lenmultip-1;
    int counter2 = lenmultip-2;
    int total ;
    int carryofmultip = 0;

    for(int i = len1-1 ; i>=len1-len2 ; i--){
        for(int j = len1-1 ; j>=0 ; j--){
            total = Array1[j]*Array2[i] + multipofarrays[counter1] + carryofmultip;
            carryofmultip = 0;
            if(total>=10){
                multipofarrays[counter1] = total%10;
                carryofmultip = (total/10)%10;
            }else{
                multipofarrays[counter1] = total;
                carryofmultip = 0;
            }
            total = 0;
            counter1--;
        }
        multipofarrays[counter1] =  carryofmultip;
        carryofmultip = 0;
        counter1 = counter2;
        counter2--;
    }

    // Çarpma İşleminin Sonucunun Çıktısını Veriyorum
    printf("\nCarpma Isleminin Sonucu: \n");
    for(int i =0; i<len1+len2; i++){
        printf("%d ",multipofarrays[i]);
    }

}

int main(){

    char sayi1[255];
    char sayi2[255];

    // 1.Sayı Alındı
    printf("1.Sayiyi Giriniz : ");
    gets(sayi1);
    // 2.Sayı Alındı
    printf("2.Sayiyi Giriniz : ");
    gets(sayi2);

    // Girilen Sayıların Uzunlukları Bulundu
    int len1 = strlen(sayi1);
    int len2 = strlen(sayi2);

    // Char Olarak Aldığımız Dizileri İşlem Yapabilmek İçin İnt Dizisine Çeviriyorum
    int Array1[len1];
    for (int i = len1 - 1; i >= 0; i--) {
        int temp = sayi1[i] - '0'; // - '0' İşlemi ile Char olan değişkeni İnt'e Çevirdim
        Array1[i] = temp;
    }

    // len1 in Boyutu len2'den Büyük Olduğu İçin 2.Sayının Toplama İşlemi İçin Boş Olan Basamaklarını 0 İle Dolduruyorum
    int Array2[len1];
    int counter = len2 - 1;
    for (int i = len1 - 1; i >= 0; i--) {
        if (counter >= 0) { //Eğer 2. sayımızın boyutunu aşmadıysak char'ı int'e çevir
            int temp = sayi2[counter] - '0'; //Ascii kodunu kullanarak char'ı int değişkene çevirdim
            counter--;
            Array2[i] = temp;
        } else { //Else durumuna düşüyorsa 2. sayımızın basamaklarını doldurduk demektir. Kalan basamakları 0 ile doldurdum.
            Array2[i] = 0;
        }
    }

    printf("Girdiginiz Sayilarla Yapmak Istediginiz Islemler \n Toplama Islemi Icin : 'A' \n Cikarma Islemi Icin : 'B'\n Carpma Islemi Icin : 'C'\n Islem Turu :  ");
    char operation;
    scanf("%c",&operation);

    switch (operation) {
        case 'A':
            sumsofarrays(Array1,Array2);
            break;
        case 'B':
            substracktion(Array1,Array2);
            break;
        case 'C':
            multiply(Array1,Array2);
            break;
        default:
            printf("Istenilen Harflerden Birini Girmediniz");
    }

    return 0 ;

}
