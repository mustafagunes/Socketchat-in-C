#### C ve socket kullanılarak yerel ağ üzerinden çalıştırılabilen basit bir mesajlaşma uygulaması.

# Başlayalım
### Platformlar

* MacOS
* Windows
* Linux Distroları

### Basit Kurulum
Aşağıdaki komutları terminal ekranınıza sırası ile yazınız ve çalıştırınız :

```shell
git clone https://github.com/mustafagunes/Socketchat-in-C.git
cd Socketchat-in-C
```

Bu aşamaları yaptıktan sonra uygulamamızı çalıştırabiliriz.
```shell
./server 9898
```

Yukarıdaki komut ile server'ı çalıştırdık. Şimdi istemcimizi çalıştırmak için 2. terminal ekranımıza aşağıdaki komutları yazıyoruz.
```shell
./client 127.0.0.1 9898
```

## Evet başarı ile çalıştırdın !
