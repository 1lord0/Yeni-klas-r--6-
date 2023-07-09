#include <stdio.h>
#include <string.h>

struct BankaHesabi {
    char hesapAdi[50];
    double bakiye;
};

void hesapOlustur(struct BankaHesabi* hesap, const char* hesapAdi, double baslangicBakiye) {
    strcpy(hesap->hesapAdi, hesapAdi);
    hesap->bakiye = baslangicBakiye;
}

void hesapBilgisi(const struct BankaHesabi* hesap) {
    printf("Hesap Adi: %s\n", hesap->hesapAdi);
    printf("Bakiye: %.2f\n", hesap->bakiye);
}

void paraYatir(struct BankaHesabi* hesap, double miktar) {
    hesap->bakiye += miktar;
    printf("%.2f TL yatirildi.\n", miktar);
}

void paraCek(struct BankaHesabi* hesap, double miktar) {
    if (miktar <= hesap->bakiye) {
        hesap->bakiye -= miktar;
        printf("%.2f TL cekildi.\n", miktar);
    } else {
        printf("Yetersiz bakiye!\n");
    }
}

int main() {
    struct BankaHesabi hesap;

    printf("Hesap adinizi girin: ");
    fgets(hesap.hesapAdi, sizeof(hesap.hesapAdi), stdin);
    hesap.hesapAdi[strcspn(hesap.hesapAdi, "\n")] = '\0';

    hesapOlustur(&hesap, hesap.hesapAdi, 0);

    hesapBilgisi(&hesap);

    int secim;
    double miktar;

    do {
        printf("\nIslem secin:\n");
        printf("1. Para yatir\n");
        printf("2. Para cek\n");
        printf("3. Hesap bilgisi goster\n");
        printf("0. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Yatirmak istediginiz miktar: ");
                scanf("%lf", &miktar);
                paraYatir(&hesap, miktar);
                break;
            case 2:
                printf("Cekmek istediginiz miktar: ");
                scanf("%lf", &miktar);
                paraCek(&hesap, miktar);
                break;
            case 3:
                hesapBilgisi(&hesap);
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim!\n");
                break;
        }

    } while (secim != 0);

    return 0;
}

