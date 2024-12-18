# Directory Projesi

Bu proje, C dilinde basit bir telefon rehberi uygulamasıdır. Kullanıcıların kişi bilgilerini ekleyebileceği, arayabileceği ve listeleyebileceği bir yapı sunar.

## Özellikler

- **Kişi Ekleme:** Kullanıcılar, isim, soyisim ve telefon numarası bilgilerini kaydedebilir.
- **Kişi Arama:** Kaydedilmiş kişiler arasında isme göre arama yapabilir.
- **Kişi Listeleme:** Tüm kayıtlı kişilerin bilgilerini görüntüleyebilir.

## Kodun Teknik Detayları

### Kütüphaneler

Kodda aşağıdaki kütüphaneler kullanılmıştır:
- `<iostream>`: Kullanıcı ile iletişim için giriş/çıkış işlemleri.
- `<fstream>`: Dosya işlemleri (okuma ve yazma).
- `<string>`: Metin işlemleri.
- `<cstdlib>`: Genel yardımcı işlevler.

### Fonksiyonlar

- `void kisiEkle()`: 
  Kullanıcıdan isim, soyisim ve telefon numarası alarak `rehber.txt` dosyasına kaydeder.
  
- `void kisiAra()`: 
  Kullanıcıdan aramak istediği ismi alır ve `rehber.txt` dosyasındaki eşleşen kayıtları bulur.
  
- `void kisileriListele()`: 
  `rehber.txt` dosyasındaki tüm kayıtları ekrana yazdırır.

### Dosya İşlemleri

Proje, kişi bilgilerini saklamak için `rehber.txt` adlı bir dosya kullanır. Bu dosya, ekleme ve okuma modlarında açılarak kişi bilgileri üzerinde işlem yapılır.
