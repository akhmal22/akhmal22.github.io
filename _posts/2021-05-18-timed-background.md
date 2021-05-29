---
layout: post
title:  "TIMED BACKGROUND"
date:   2021-05-18 11:12:59 +0700
author: "Akhmal R"
categories: indonesian article
---

# Membuat Wallpaper yang mengikuti pergerakan matahari

## Prakata

Pernah kepikiran kalau wallpaper kita bisa berubah sendiri? Saya yakin pasti pernah, tapi pernah kepikiran matahari wallpaper kita bisa bergerak sendiri? Harusnya pernah kalau anda pake si M dari toko A. Tapi jika kita males beli produk dari toko A tersebut apakah matahari di wallpaper kita bisa bergerak sendiri? Bisa lah! Lanjutan dari artikel ini akan membahas (semoga bisa dimengerti) cara supaya matahari di laptop/PC anda bisa gerak sendiri.

## Beneran bisa? Emang ada fitur seperti itu?

Iya sejujurnya setau saya tidak ada fitur bawaan seperti itu di laptop/PC selain dari toko A, di Windows setau saya tidak ada (kalaupun ada, tidak dibahas disini) tapi di OS Linux, bisa dibikin timed background itu dan kita akan bahas.

## Timed Background? Apa itu?

Timed background (istilah bikinan saya sih ini ckck) itu istilah yang merujuk pada suatu file yang dipakai untuk background desktop yang berubah mengikuti waktu setempat, sejauh ini sejalan kan dengan judul yang mau matahari di laptop/PC kita gerak sendiri. Timed background terdiri dari beberapa gambar yang bergantian mengisi wallpaper anda sesuai waktu di tempat anda.

## Gak bahas Windows? Berarti cuma untuk Linux?

Iya artikel ini ditujukan untuk pengguna Linux dengan Desktop Environment (DE) GNOME. Untuk DE lainnya saya belum pernah coba tetapi jika DE yang sedikit-banyak memakai komponen GNOME untuk struktur DE mereka (seperti Budgie atau Cinnamon) kemungkinan sih bisa.

## Untuk Linux apa ya?

Saya bilang semua Linux dengan DE GNOME bisa dengan cara ini karena ini fitur dari GNOME, tapi saya akan praktikan dengan Fedora.

## Yaudah kasih tau caranya!

Iya yaudah langsung dikasih caranya, biar gak pusing, kita bikin daftar cara-caranya dulu ya.
1. Boot ke Linux pada komputer anda dan pastikan DE yang dipakai adalah GNOME (Budgie/Cinnamon kemungkinan bisa, tapi artikel ini hanya berfokus pada GNOME).
2. Cari foto/video yang menunjukkan pergerakan matahari pada suatu tempat (keyword hint: sky timelapse) lalu download.
3. Pilih 4 gambar yang menunjukkan waktu fajar, siang, senja dan malam dari foto/video yang di-download.
4. Beri sufiks pada 4 gambar sesuai waktu yang ditunjukkan gambar dan buat timed background.
5. Buat direktori untuk menampung gambar-gambar dan timed background yang sudah dibuat.
6. Aplikasikan timed background.

Seperti biasa, cek dulu kelengkapan prasyarat untuk praktik. Ceklisnya sebenarnya cuma OS Linux dengan DE GNOME yang sudah terinstall, kalau belum, silakan install terlebih dulu. Jika OS yang disebut sudah terinstall, cari video dengan gambar pemandangan langit dengan mataharinya (sky timelapse) yang menunjukkan sedang terbit, siang dan tenggelam, bisa juga kumpulan foto yang memenuhi syarat tersebut (misalnya gambar Mojave).

Setelah mendapat foto/video yang dimaksud, pilih gambar-gambar (jika anda dapat video, potong video menjadi 4 gambar) yang menunjukkan waktu fajar, tengah hari, senja dan malam hari lalu beri sufiks keempat waktu tersebut pada gambar yang sesuai -dawn untuk gambar fajar, -day untuk gambar tengah hari, -dusk untuk gambar senja dan -night untuk gambar malam hari, nama gambar disarankan menggunakan nama file timed background (misalnya timed background bernama "Bristol.xml") ditambah sufiks yang sesuai (misalkan gambar senja, disarankan bernama "Bristol-dusk.jpg"). Jika anda mendapat 4 gambar dengan sufiks yang telah disebut, maka kita bisa membuat timed background yang telah disebutkan di awal artikel dengan membuat file .xml dan salin kode di bawah.

{% highlight xml %}
<background>
<starttime>
  <year>2020</year>
  <month>10</month>
  <day>20</day>
  <hour>07</hour>
  <minute>00</minute>
  <second>00</second>
</starttime>
<!-- This animation will start at 7 AM. -->

<!-- We start with dawn at 7 AM. It will remain up for 2 hours. -->
<static>
<duration>7200.0</duration>
<file>/home/akhmalr/timedBackground/Bristol-dawn.jpg</file>
</static>

<!-- Dawn ended and starts to transition to day at 9 AM. The transition lasts for 2 hours, ending at 11 AM. -->
<transition type="overlay">
<duration>7200.0</duration>
<from>/home/akhmalr/timedBackground/Bristol-dawn.jpg</from>
<to>/home/akhmalr/timedBackground/Bristol-day.jpg</to>
</transition>

<!-- It's 11 AM, we're showing the day image in full force now, for 4 hours ending at 3 PM. -->
<static>
<duration>14400.0</duration>
<file>/home/akhmalr/timedBackground/Bristol-day.jpg</file>
</static>

<!-- It's 3 PM, and we're starting to transition to dusk. Transition completes at 7 PM. -->
<transition type="overlay">
<duration>14400.0</duration>
<from>/home/akhmalr/timedBackground/Bristol-day.jpg</from>
<to>/home/akhmalr/timedBackground/Bristol-dusk.jpg</to>
</transition>

<!-- It's 7 PM, we're showing the dusk for 2 hours ending at 9 PM. -->
<static>
<duration>7200.0</duration>
<file>/home/akhmalr/timedBackground/Bristol-dusk.jpg</file>
</static>

<!-- It's 9 PM, and we're starting to transition to night. Transition completes at 11 PM. -->
<transition type="overlay">
<duration>7200.0</duration>
<from>/home/akhmalr/timedBackground/Bristol-dusk.jpg</from>
<to>/home/akhmalr/timedBackground/Bristol-night.jpg</to>
</transition>

<!-- It's 11 PM, we're showing the night till 5 AM. -->
<static>
<duration>21600.0</duration>
<file>/home/akhmalr/timedBackground/Bristol-night.jpg</file>
</static>

<!-- It's 5 AM, and we're starting to transition to dawn. Transition completes at 7 AM. -->
<transition type="overlay">
<duration>7200.0</duration>
<from>/home/akhmalr/timedBackground/Bristol-night.jpg</from>
<to>/home/akhmalr/timedBackground/Bristol-dawn.jpg</to>
</transition>

</background>
{% endhighlight %}

Kode diatas berguna untuk mengganti wallpaper secara berkala berdasarkan waktu perkiraan 4 waktu tersebut mulai dan berakhir, kode tersebut dapat diubah tergantung kebutuhan tertentu anda (misalkan, path menuju gambar atau durasi penggantian dapat diubah sesuai keinginan).

![directory](https://raw.githubusercontent.com/akhmal22/akhmal22.github.io/master/images/direktori-timed-background.png)
<sub>Gambar 1: file-file dalam direktori timed background</sub>

Setelah 5 file tersebut siap, buat direktori dan masukkan 5 file tersebut ke direktori yang telah dibuat agar tidak tercecer di root/home directory anda. Sekian adalah pembuatan timed background, sampai saat ini, timed background sudah bisa diaplikasikan.

![directory](https://raw.githubusercontent.com/akhmal22/akhmal22.github.io/master/images/tweaks.png)
<sub>Gambar 2: aplikasikan timed background dengan GNOME Tweaks</sub>

Pengaplikasian timed background dapat dilakukan dengan GNOME Tweaks, oleh karena itu jika anda belum menginstall (GNOME Tweaks bukan aplikasi bawaan) anda harus menginstall GNOME Tweaks terlebih dulu, jika sudah, anda dapat langsung mengaplikasikan timed background dengan beralih ke seksi Appearance lalu pada file selector image, pilih file .xml yang telah dibuat sebelumnya dan selesai, timed background sudah teraplikasikan pada laptop/PC anda.

Sampai disini dulu artikel pertama saya di tahun 2021 semoga bukan menjadi satu-satunya di tahun ini, akhir kata, Salam (Akhmal R)
