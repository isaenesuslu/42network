# 🔄 Push_Swap: Çalışma Mantığı ve İşlem Sırası

Programın terminale `./push_swap 3 1 2` yazdığın andan itibaren hangi dosyaların hangi sırayla çalıştığını aşağıda görebilirsin. Bu, projenin "yaşam döngüsü"dür.

---

### 🚠 0. Başlangıç (Giriş Kapısı)
*   **Dosya:** `srcs/main/main.c`
*   **İşlem:** Program buradan başlar. İlk yaptığı iş, kaç tane sayı geldiğine bakmaktır. Eğer sayı gelmediyse programı sessizce kapatır.

---

### 🕵️ 1. Kontrol ve Temizlik (Parsing)
Program sayıları hemen listeye eklemez, önce "gerçekten doğru mu?" diye bakar.
*   **Sırasıyla:**
    1.  `srcs/parsing/parser.c`: Gelen argümanları yakalar. Eğer `"3 1 2"` gibi tırnak içinde geldiyse `split.c` devreye girer.
    2.  `srcs/parsing/validator.c`: Her bir kelimenin sadece rakamlardan oluştuğuna, aynı sayının tekrar etmediğine ve sayıların `int` sınırında (max 2147483647) olduğuna bakar.
    3.  **Hata varsa:** `srcs/utils/error_utils.c` üzerinden `Error\n` yazdırır ve çıkar.

---

### 🧱 2. Bellek Kurulumu (Initialization)
Artık elimizde temiz rakamlar var. Şimdi bunları bilgisayarın hafızasında kutulara (Linked List) koyma vakti.
*   **Dosya:** `srcs/main/init.c` -> `srcs/utils/list_utils.c`
*   **İşlem:** Sayıları tek tek alır, her biri için bir `t_node` oluşturur ve A yığınına (Stack A) sırayla bağlar.

---

### 🧠 3. Strateji Seçimi (Decision Point)
Her şey kuruldu. Şimdi "nasıl sıralayacağız?" kararı verilir.
*   **Dosya:** `srcs/main/main.c` (İçindeki if-else yapısı)
*   **İşlem:**
    -   Sayılar zaten sıralı mı? Evet ise -> Bitiş'e git.
    -   Sayı adedi <= 5 mi? Evet ise -> `srcs/algo/sort_tiny.c`'yi çağır.
    -   Sayı adedi > 5 mi? Evet ise -> `srcs/algo/turk_algo.c`'yi (Büyük algoritma) başlat.

---

### 🎲 4. Uygulama (Sorting & Ops)
Algoritma çalışırken sürekli olarak A ve B arasında sayı çevirir.
*   **Dosyalar:** `srcs/algo/` (Kafa) <-> `srcs/ops/` (Kollar)
*   **Mantık:**
    -   `turk_algo.c` hesap yapar: "Şu sayıyı atarsam daha ucuz olur" (`cost.c`).
    -   Karar verince `ops/push.c` veya `ops/rotate.c` gibi dosyaları çağırarak kutuların yerini değiştirir.

---

### 🧹 5. Temizlik ve Kapanış (Exit)
İşlem bitti, sayılar sıralandı. Şimdi emanet aldığın belleği geri vermen lazım.
*   **Dosya:** `srcs/main/exit.c` -> `srcs/utils/error_utils.c`
*   **İşlem:** `free_stack` fonksiyonu tüm bağlı listeyi (`malloc` ile açılan her kutuyu) tek tek siler. Programı güvenle kapatır.

---

### 💡 Özet Geçersek:
1.  **Main** başlar -> **Parser** kontrol eder -> **Init** kutuları oluşturur.
2.  **Main** karar verir -> **Algo** strateji belirler -> **Ops** kutuları hareket ettirir.
3.  **Exit** her şeyi temizler ve program durur.

Bu sırayı anladıysan, her dosyanın neden var olduğunu ve birbirlerine nasıl bağlı olduklarını daha iyi görebilirsin.
