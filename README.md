# API-Gateway-Priority-Scheduler
# RFC 9213 Uyumlu Modüler API Gateway İstek Zamanlayıcısı

Bu proje, gelen API isteklerini FIFO (İlk Giren İlk Çıkar) mantığına göre değil, RFC 9213 (Extensible HTTP Priorities) standardına uygun olarak aciliyet (urgency) sırasına göre işleyen bir zamanlayıcı simülasyonudur.

## Kullanılan Teknolojiler ve Veri Yapıları
* **Dil:** C (Modüler Mimari - Header/Source ayrımı)
* **Algoritma:** Min-Heap (O(log N) karmaşıklığı ile en acil isteği çekme)
* **Bellek Yönetimi:** Dinamik bellek tahsisi (malloc, realloc, free) ile sıfır sızıntı (zero leak) prensibi.

## Proje Modülleri
1. **`main.c`:** Ana uygulama ve istek simülasyonu katmanı.
2. **`priority_queue.h / .c`:** Min-Heap algoritması, kuyruk yönetimi ve bellek tahsisi modülü.
3. **`rfc9213.h / .c`:** HTTP öncelik stringlerini (örn: "u=0, i") parse eden modül.

## Nasıl Derlenir ve Çalıştırılır?
Projeyi terminal üzerinden derlemek için GCC derleyicisi gereklidir:

\`\`\`bash
gcc main.c priority_queue.c rfc9213.c -o gateway_scheduler
./gateway_scheduler
\`\`\`
