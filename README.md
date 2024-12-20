![desain diagram](https://github.com/user-attachments/assets/bfd46aa1-ad3b-4090-88e6-c9d90c129611)

Pada program ini menggunakan library ESP32Servo.h untuk mengaktifkan servo, WiFi.h digunakan untuk menyambungkan wifi pada ESP32, UnniversalTelegrambot.h digunakan untuk mengintegrasi antara ESP32 dan bot telegram. program menghubungkan ESP32 ke jaringan wifi dengan menggunakan WiFi.begin(ssid, password) memulai koneksi ke jaringan WiFi dengan SSID dan password yang diberikan. Inisialisasi pin pada program menggunakan pinMode untuk mengetahui sebagai apa input atau output, dan juga untuk menginisialisasi servo ke posisi awal yaitu 90 derajat. Sistem juga menginisialisasi pin sensor api sebagai input dan pin buzzer serta relay sebagai output, memastikan mereka dalam keadaan tidak aktif awalnya. Servo motor diatur ke posisi tengah, dan koneksi ke Telegram diuji dengan mengirim pesan "Bot is connected".
Dalam loop utama, sistem secara kontinu membaca nilai dari sensor api. Jika api terdeteksi di sisi kanan (sensor 1 dan 2 aktif), buzzer dan relay diaktifkan, servo bergerak ke kanan, dan notifikasi dikirim ke Telegram. Jika api terdeteksi di sisi kiri (sensor 4 dan 5 aktif), buzzer dan relay juga diaktifkan, servo bergerak ke kiri, dan notifikasi dikirim ke Telegram. Jika tidak ada api yang terdeteksi, buzzer dan relay dinonaktifkan, dan servo kembali ke posisi tengah. Dengan jeda waktu 500 milidetik antara pembacaan sensor, sistem memberikan waktu yang cukup untuk servo bergerak dan memastikan pembacaan sensor tidak terlalu sering. Program ini secara efektif mengintegrasikan pemantauan, respons otomatis, dan notifikasi real-time untuk mendeteksi dan menanggapi kebakaran.

V.	Hasil
Saat terdeteksi api, ESP32 akan menyalakan buzzer sebagai tanda peringatan bahwa ada api yang terdeteksi. Selanjutnya, ESP32 akan mengaktifkan relay yang berfungsi untuk menyalakan pompa air. Selain itu, ESP32 akan mengirimkan pesan deteksi api melalui Telegram Bot untuk memberitahukan pengguna. Servo kemudian akan bergerak menuju lokasi yang terdeteksi api, baik ke kanan maupun ke kiri, sesuai dengan posisi sensor yang aktif.

Terdapat dua kondisi saat terdeteksi api. Kondisi pertama adalah ketika api terdeteksi oleh dua sensor di sisi kanan, maka servo akan bergerak ke kanan. Kondisi kedua adalah ketika api terdeteksi oleh dua sensor di sisi kiri, maka servo akan bergerak ke kiri. Dengan demikian, sistem ini tidak hanya memberikan peringatan dan respons otomatis, tetapi juga secara dinamis mengarahkan alat pemadam kebakaran ke lokasi api berdasarkan posisi sensor yang aktif.

●	Saat api terdeteksi di 2 sensor kanan

![kanan](https://github.com/user-attachments/assets/d5e9576e-5676-41bf-b806-0df3fcff2abf)

 
Sensor api akan mendeteksi jika api berada pada jangkauan, jika sensor data 1 dan 2 aktif maka esp memberitahukan pada buzzer ada api terdeteksi untuk memberikan peringatan suara, sehingga orang disekitar dapat segera mengetahui bahwa terjadi kebakaran. Serta akan menyalakan relay untuk mengaktifkan pompa air dan servo akan merubah arah menjadi 135 derajat. Selain itu, untuk memberikan peringatan jarak jauh, sistem akan mengirimkan pesan melalui Telegram Bot yang menampilkan pesan peringatan dan informasi tentang lokasi api yang terdeteksi. Namun, pesan notifikasi hanya akan dikirimkan jika ada perubahan kondisi dari tidak ada api menjadi terdeteksi api, atau sebaliknya, sehingga sistem tidak terus-menerus mengirimkan pesan notifikasi berulang.

 ![kanan1](https://github.com/user-attachments/assets/6cd2a86b-6bf6-4158-a0c2-8ab17574f5c8)

●	Saat api terdeteksi di 2 sensor kiri

![kiri](https://github.com/user-attachments/assets/3eb6911a-aaa9-498b-87e2-5e55f629dd9a)


Jika sensor api 4 dan 5 mendeteksi adanya api di sebelah kiri, ESP32 akan memberikan peringatan suara dengan mengaktifkan buzzer sehingga orang di sekitar dapat segera mengetahui bahwa terjadi kebakaran. Selain itu, ESP32 akan menyalakan relay untuk mengaktifkan pompa air dan menggerakkan servo ke arah 45 derajat. Untuk memberikan peringatan jarak jauh, sistem akan mengirimkan pesan melalui Telegram Bot yang menampilkan pesan peringatan dan informasi tentang lokasi api yang terdeteksi. Namun, pesan notifikasi hanya akan dikirimkan jika ada perubahan kondisi dari tidak ada api menjadi terdeteksi api, atau sebaliknya, sehingga sistem tidak terus-menerus mengirimkan pesan notifikasi berulang.

![kiri1](https://github.com/user-attachments/assets/1b38dcaa-01fa-4e41-8291-d18ee71b3d41)


●	Notifikasi Telegram bot

![tele](https://github.com/user-attachments/assets/8425d560-723a-4023-b085-d1104c27293d)

  
Sistem akan mengirimkan pesan melalui Telegram Bot yang menampilkan pesan peringatan dan informasi tentang lokasi api yang terdeteksi. Namun, pesan notifikasi hanya akan dikirimkan jika ada perubahan kondisi dari tidak ada api menjadi terdeteksi api, atau sebaliknya, sehingga sistem tidak terus-menerus mengirimkan pesan notifikasi berulang.



Video Demo

https://github.com/user-attachments/assets/e73762f7-02e7-480f-97e1-e1edfa362912




