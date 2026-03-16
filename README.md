# Push Swap

*This project has been created as part of the 42 curriculum by ybalkan, iuslu*

## Description
**Push Swap**, veri setlerini sınırlı bir dizi işlem ve iki yığın (A ve B) kullanarak mümkün olan en az hamleyle sıralamayı amaçlayan bir algoritma projesidir. Proje, karmaşıklık yönetimi ve algoritma optimizasyonu üzerine odaklanır.

Bu implementasyonda, yüksek performans ve minimum işlem sayısı hedefleyen optimize edilmiş bir yapı kullanılmıştır. Proje, modüler bir mimariye sahip olup (parsing, ops, algo, utils) geniş ölçekli sayı dizilerini etkili bir şekilde sıralayabilmektedir. Ayrıca performans analizi için `--bench` bayrağı içermektedir.

## Instructions
Projenin derlenmesi ve çalıştırılması için aşağıdaki adımları takip edebilirsiniz:

### Derleme
Proje dizininde `Makefile` dosyasını kullanarak derleme yapabilirsiniz:
```bash
make
```

### Kullanım
Programı bir sayı dizisi ile çalıştırın:
```bash
./push_swap 3 2 5 1 4
```

Hız testi ve işlem sayısını görmek için `--bench` bayrağını kullanabilirsiniz:
```bash
./push_swap --bench 500
```

### Temizlik
Nesne dosyalarını ve ikili dosyayı temizlemek için:
```bash
make clean
make fclean
```

## Resources
Bu projenin geliştirilme sürecinde aşağıdaki kaynaklardan yararlanılmıştır:
- **42 Subject**: Proje gereksinimleri ve kısıtlamaları.
- **Algoritma Teknikleri**: Yığın tabanlı sıralama algoritmaları ve optimizasyon stratejileri üzerine makaleler.

### AI Kullanımı
Bu projede Yapay Zeka (Antigravity), aşağıdaki görevlerde yardımcı bir araç olarak kullanılmıştır:
- **Kod Refaktörü**: Kodun modüler hale getirilmesi ve 42 Norm kurallarına (Norminette) uygunluğunun sağlanması.
- **Hata Ayıklama**: Derleme hatalarının çözülmesi ve uç durumların (edge cases) tespiti.
- **Dokümantasyon**: Mevcut README dosyasının ve teknik açıklamaların yapılandırılması.
- **Performans Analizi**: Yazılan algoritmaların verimlilik kontrolleri ve optimizasyon önerileri.