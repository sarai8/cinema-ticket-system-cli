# 🎬 Sinema Yönetim Sistemi

Bu proje, C++ programlama dili kullanılarak geliştirilmiş konsol tabanlı bir **Sinema Yönetim Sistemi** uygulamasıdır. Sistem; film, salon, seans ve bilet işlemlerini yönetmek amacıyla hazırlanmıştır.

## 📌 Proje Hakkında

Projede nesne yönelimli programlama (OOP) prensipleri kullanılmıştır. Admin ve müşteri işlemleri ayrı yapılar halinde tasarlanmış, sinema sistemi içerisindeki tüm yönetim işlemleri merkezi bir yapı üzerinden kontrol edilmiştir.

Uygulama sayesinde:

* Film ekleme, silme ve güncelleme
* Salon yönetimi
* Seans işlemleri
* Bilet satış işlemleri
* Dosyaya veri kaydetme ve dosyadan veri okuma
* Salon karşılaştırma ve sıralama işlemleri

kolayca gerçekleştirilebilmektedir.

---

# 🛠 Kullanılan Teknolojiler

* **C++**
* Nesne Yönelimli Programlama (OOP)
* Dinamik Bellek Yönetimi
* Dosya İşlemleri (File I/O)
* Makefile

---

# 📂 Proje Yapısı

```bash
sinemaProjesi/
│
├── include/
│   ├── admin.h
│   ├── bilet.h
│   ├── film.h
│   ├── kullanici.h
│   ├── musteri.h
│   ├── sinemaSalonu.h
│   ├── sinemaSistemi.h
│   └── test.h
│
├── src/
│   ├── admin.cpp
│   ├── bilet.cpp
│   ├── film.cpp
│   ├── kullanici.cpp
│   ├── main.cpp
│   ├── musteri.cpp
│   ├── sinemaSalonu.cpp
│   ├── sinemaSistemi.cpp
│   └── test.cpp
│
├── biletler.txt
├── salonlar.txt
├── Makefile
└── sinema.exe
```

---

# ⚙️ Kurulum ve Çalıştırma

## Linux / MacOS

Terminal üzerinden proje klasörüne giderek aşağıdaki komutları çalıştırın:

```bash
make
./sinema
```

## Windows (MinGW)

```bash
g++ -Iinclude src/*.cpp -o sinema.exe
sinema.exe
```

---

# 👨‍💻 Sistem Özellikleri

## 🎞 Film İşlemleri

* Film ekleme
* Film silme
* Film güncelleme
* Film listeleme
* Yaş sınırı belirleme
* Seans tanımlama

## 🏢 Salon İşlemleri

* Salon ekleme
* Salon silme
* Salon güncelleme
* Salon listeleme
* Kapasite karşılaştırma
* En büyük salonu bulma
* Salon sıralama

## 🎟 Bilet İşlemleri

* Bilet satışı
* Bilet kaydetme
* Bilet listeleme
* Dosyaya yazma / okuma

## 👤 Kullanıcı Yapısı

Sistemde iki farklı kullanıcı tipi bulunmaktadır:

### Admin

Admin kullanıcıları:

* Film yönetebilir
* Salon yönetebilir
* Seans işlemleri yapabilir

### Müşteri

Müşteriler:

* Film görüntüleyebilir
* Bilet satın alabilir

---

# 💾 Dosya İşlemleri

Projede kalıcı veri saklamak amacıyla `.txt` dosyaları kullanılmaktadır.

Kullanılan dosyalar:

| Dosya          | Açıklama                 |
| -------------- | ------------------------ |
| `salonlar.txt` | Salon bilgilerini saklar |
| `biletler.txt` | Satılan biletleri saklar |

#

---

# 📸 Örnek Menü

```text
------ Film Islemleri ------
1- Film Ekle
2- Film Guncelle
3- Film Sil
4- Filmleri Listele
5- Geri Don
```

---

#
