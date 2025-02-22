# 📝 Linux Syslog Yönetim Sistemi

Bu C programı, Linux sistem günlüklerini (syslog) çift yönlü bağlı liste veri yapısında yöneten bir uygulamadır.

## 🎯 Proje Amacı
Sistem günlüklerini etkili bir şekilde yönetmek, filtrelemek ve öncelik seviyelerine göre sıralamak için geliştirilmiştir.

## 🛠️ Kullanılan Teknolojiler
* C Programlama Dili
* Çift Yönlü Bağlı Liste
* Dinamik Bellek Yönetimi
* Zaman İşlemleri (time.h)

## ⚙️ Çalışma Prensibi
Program, her günlük kaydı için aşağıdaki bilgileri saklar:
* ⏰ Zaman Damgası
* 🏷️ Öncelik Seviyesi
* 📋 Birim Bilgisi
* 💬 Mesaj
* 🖥️ Sunucu Adı

## 📋 Temel Özellikler
* Yeni günlük kaydı ekleme
* Öncelik seviyesine göre filtreleme
* Otomatik bellek yönetimi
* Çift yönlü gezinme imkanı

## 🖥️ Örnek Çıktı
```
Öncelik 1 günlükleri:
Zaman Damgası: Sat Feb 22 21:12:28 2025
Birim: çekirdek
Mesaj: Sistem başlatıldı
Sunucu Adı: sunucu1
Öncelik: 1

Öncelik 3 günlükleri:
Zaman Damgası: Sat Feb 22 21:12:33 2025
Birim: kimlik doğrulama
Mesaj: Kullanıcı giriş denemesi başarısız
Sunucu Adı: sunucu1
Öncelik: 3
```

## ⚠️ Hata Yönetimi
* Bellek tahsis hatalarına karşı kontroller
* NULL pointer kontrolleri

## 📜 Lisans
Bu proje eğitim amaçlı geliştirilmiştir.

## 🚀 İyi çalışmalar! 😊
