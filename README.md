# so-long
<img width="2178" alt="so_long2" src="https://github.com/yildizozcan/so-long/assets/129951908/eefab910-1539-4979-a738-e3983227e015">

So-long projesi, C dili ve mlx kütüphanesindeki grafiksel arayüzleri kullanarak 2D oyun yapma projesidir. Projeden kısaca bahsedelim.
Projeyi iki kısma ayırabiliriz. Parser ve mlx'i kullandığınız kısım.
Parser haritanın kontrollerini sağladığımız kısımdır. Bu kısmında dikkat edilmesi gereken temel şeyler(Projenin zorunlu kısımı hakkında):
1. Harita dikdörtgen şeklinde olmalıdır.
2. Harita da bir oyuncu olmalıdır.
3. Haritanın dört bir tarafı duvarlarla çevrili olmak zorundadır.
4. Player duvarlardan geçmemelidir.
5. Haritada bir exit en az bir de collectible olmak durumundadır.
6. Oyuncu exit'a ve var olan collectible'lara erişebilmeledir.
Mlx kısmında ise haritanızı pencereye taşıyıp klavye tuşları ile hareketleri kontrol etmenizi sağlayacak temel mlx kütüphanesindeki fonksiyonları kullanmalısınız.
