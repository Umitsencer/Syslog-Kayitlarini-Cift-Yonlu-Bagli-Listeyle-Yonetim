#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Günlük (log) kaydı için yapı
struct SyslogKaydi {
    int oncelik;           // Öncelik seviyesi
    time_t zamanDamgasi;   // Zaman damgası
    char birim[32];        // Birim (facility) bilgisi
    char mesaj[1024];      // Günlük mesajı
    char sunucuAdi[256];   // Sunucu adı
};

// Çift yönlü bağlı liste düğümü
struct Dugum {
    struct SyslogKaydi veri;
    struct Dugum* sonraki;
    struct Dugum* onceki;
};

// Bağlı liste yapısı
struct BagliListe {
    struct Dugum* bas;
    struct Dugum* son;
    int boyut;
};

// Bağlı liste başlatma
struct BagliListe* listeOlustur() {
    struct BagliListe* liste = (struct BagliListe*)malloc(sizeof(struct BagliListe));
    liste->bas = NULL;
    liste->son = NULL;
    liste->boyut = 0;
    return liste;
}

// Yeni günlük kaydı ekleme (başa ekleme)
void gunlukEkle(struct BagliListe* liste, struct SyslogKaydi kayit) {
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeniDugum->veri = kayit;
    
    if (liste->bas == NULL) {
        yeniDugum->sonraki = NULL;
        yeniDugum->onceki = NULL;
        liste->bas = yeniDugum;
        liste->son = yeniDugum;
    } else {
        yeniDugum->sonraki = liste->bas;
        yeniDugum->onceki = NULL;
        liste->bas->onceki = yeniDugum;
        liste->bas = yeniDugum;
    }
    liste->boyut++;
}

// Belirli bir öncelik seviyesine göre günlük kayıtlarını listeleme
void onceligeGoreListele(struct BagliListe* liste, int oncelik) {
    struct Dugum* gecici = liste->bas;
    while (gecici != NULL) {
        if (gecici->veri.oncelik == oncelik) {
            printf("Zaman Damgası: %s", ctime(&gecici->veri.zamanDamgasi));  // Zaman damgası
            printf("Birim: %s\n", gecici->veri.birim);
            printf("Mesaj: %s\n", gecici->veri.mesaj);
            printf("Sunucu Adı: %s\n", gecici->veri.sunucuAdi);
            printf("Öncelik: %d\n\n", gecici->veri.oncelik);
        }
        gecici = gecici->sonraki;
    }
}

// Belleği temizleme
void listeyiTemizle(struct BagliListe* liste) {
    struct Dugum* gecici = liste->bas;
    while (gecici != NULL) {
        struct Dugum* silinecek = gecici;
        gecici = gecici->sonraki;
        free(silinecek);
    }
    free(liste);
}

// Test için örnek kullanım
int main() {
    struct BagliListe* syslogListesi = listeOlustur();
    
    // Örnek günlük kayıtları oluşturma
    struct SyslogKaydi kayit1 = {
        .oncelik = 1,
        .zamanDamgasi = time(NULL),
        .birim = "çekirdek",
        .mesaj = "Sistem başlatıldı",
        .sunucuAdi = "sunucu1"
    };
    
    struct SyslogKaydi kayit2 = {
        .oncelik = 3,
        .zamanDamgasi = time(NULL) + 5, // 5 saniye fark
        .birim = "kimlik doğrulama",
        .mesaj = "Kullanıcı giriş denemesi başarısız",
        .sunucuAdi = "sunucu1"
    };
    
    // Günlük kayıtlarını listeye ekleme
    gunlukEkle(syslogListesi, kayit1);
    gunlukEkle(syslogListesi, kayit2);
    
    // Öncelik seviyesine göre listeleme
    printf("Öncelik 1 günlükleri:\n");
    onceligeGoreListele(syslogListesi, 1);
    
    printf("Öncelik 3 günlükleri:\n");
    onceligeGoreListele(syslogListesi, 3);
    
    // Belleği temizleme
    listeyiTemizle(syslogListesi);
    
    return 0;
}
