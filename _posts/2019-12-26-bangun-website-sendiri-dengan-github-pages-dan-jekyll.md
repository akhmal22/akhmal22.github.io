---
layout: post
title:  "BANGUN WEBSITE SENDIRI DENGAN GITHUB PAGES DAN JEKYLL"
date:   2019-12-26 22:23:59 +0700
categories: indonesian article
---
# BANGUN WEBSITE SENDIRI DENGAN GITHUB PAGES DAN JEKYLL

## Prakata

Ingin bangun website sendiri? Ingin punya website untuk dokumentasikan proyek kamu? Ingin blogging tapi dengan cara baru? Kamu datang di artikel yang tepat. Artikel ini akan membahas Github Pages, Jekyll dan cara membuat website sendiri dengan 2 teknologi mutakhir tersebut. Jadi, mari kita mulai pembahasan ini dengan pertanyaan apa itu Github Pages dan Apa itu Jekyll.

## Apa itu Github Pages?

Github Pages merupakan salah satu fitur terbaru dari Github yang memungkinkan pengguna Github membuat semacam situs (website) secara gratis dengan menjalankan trio maut git cli (add, commit, push) pada repositori (repo) khusus. Github Pages hanya situs statis yang menampilkan hasil render HTML saja (frontend)  dan tidak menyimpan atau menampilkan (operasi CRUD) seperti website pada umumnya (ada backend dan frontend).

Github Pages bertujuan untuk berbagai kebutuhan yang dapat ditangani dengan website statis seperti company profile atau self profile, dokumentasi proyek milik pribadi atau komunitas sampai berbagi ilmu dengan artikel anda.

## Apa itu Jekyll?

Jekyll merupakan generator situs statis yang ditujukan untuk pembuatan situs pribadi, proyek atau organisasi. Jekyll hanya me-render file yang ada pada repo Github anda menjadi content yang menyerupai blog. Jekyll dapat dipakai untuk membuat Github Pages anda lebih cantik dan lebih gampang untuk diubahsuai, terlepas dari Github Pages, Jekyll juga bisa dioperasikan dengan engine web server seperti Apache atau Nginx.

## Caranya?

Kebutuhan Software

Untuk guide ini, saya akan menggunakan Git CLI sebagai Git Client. Anda memerlukan beberapa software untuk bisa melakukan tahapan yang dibutuhkan, yaitu:

| **Software** | **Fungsi** |
| --- | --- |
| Git GUI/CLI | Menjalankan operasi git dari repo lokal |
| Ruby | Kebutuhan/dependensi untuk Jekyll |
| Gem | Package manager Ruby |
| Bundler | Gem dependencies manager Ruby untuk repo |

Tabel 1: Kebutuhan Software

Sebenarnya, Jekyll juga mempunyai beberapa dependensi yang harus dipenuhi, namun saya sebut hanya 4 kebutuhan software karena tabel di atas hanya untuk keperluan instalasi dan Jekyll beserta dependensinya akan bisa diatur oleh Bundler. Biasanya (jika anda pakai Linux) Git CLI dan Ruby sudah terinstall, jika belum ada, install dengan command (saya pakai Fedora)

{% highlight bash%}
# install Git CLI
$ sudo dnf install git

# install Ruby
$ sudo dnf install ruby ruby-devel
# beberapa distro memakai ruby-dev, sesuaikan dengan distro anda

# tiga command di atas bisa dijadikan 1
$ sudo dnf install git ruby ruby-devel

# install bundler
$ gem install bundle
{% endhighlight %}

Pembuatan Repo Github Baru

Setelah semua yang di atas terinstall, buat repo baru dari Git (repo lokal) dan dari website Github langsung. Pembuatan repo pada situs Github dapat dilakukan dengan klik menu tanda tambah &#39;+&#39; dan &#39;new repository&#39; lalu:

1. Isi nama repo dengan &quot;&lt;username&gt;.github.io&quot; dengan &lt;username&gt; adalah username dari akun Github anda
2. Tuliskan deskripsi (opsional)
3. Repo diatur ke mode publik
4. Inisiasi README (opsional)
5. Jangan sertakan .gitignore
6. License dibiarkan none juga tidak masalah
7. Repo Github anda siap dibuat.

![alt text](https://raw.githubusercontent.com/akhmal22/akhmal22.github.io/master/images/new-repo.png)

<sub>Gambar 1: Cara membuat repo baru di Github</sub>

![alt text](https://raw.githubusercontent.com/akhmal22/akhmal22.github.io/master/images/make-new-repo.png)

<sub>Gambar 2: Cara membuat repo khusus Github Pages</sub>

Giliran pengaturan dari Git CLI, karena repo Git anda yang di Github sudah diatur langsung di situs Github, anda hanya tinggal clone repo Github anda ke repo lokal dan tes situs anda

{% highlight bash %}
# clone git repo yang ada di github anda
$ git clone https://github.com/<username>/<username>.github.io

# pindah direktori ke direktori yang di clone
$ cd <username>.github.io

# buat dan masukkan kata “Hello, World!” pada index.html
$ echo "Hello, World" >> index.html

# tambahkan semua file yang ada di direktori tersebut
$ git add .

# commit perubahan yang anda lakukan
$ git commit -m “tulis perubahan yg anda lakukan disini”

# push commit yang telah dibuat ke repo remote
$ git push -u origin master

# jika ada masalah kredensial, bisa coba ini dan lakukan command di atas sekali lagi
$ git config --global user.name “<username>”
$ git config --global user.email “<email>”
{% endhighlight %}

Setelah command-command di atas dilakukan tanpa error, anda bisa cek situs anda dengan mengunjungi https://&lt;username&gt;.github.io.

Setting Jekyll pada Repo Lokal

Jika anda sudah memenuhi kebutuhan software diatas, maka anda bisa melanjutkan tahapan ke instalasi Jekyll dan mengatur Jekyll agar bisa bekerja dengan baik, tahapan selanjutnya adalah sebagai berikut.

{% highlight bash%}
# instalasi jekyll
$ gem install jekyll

# inisiasi Gemfile
$ bundle init

# tambahkan Jekyll ke Gemfile
$ bundle add jekyll -v “<versi Jekyll>”
# lihat https://pages.github.com/versions/ untuk mengisi <versi Jekyll>

# generate file Jekyll yang akan jadi komponen dari Github Pages
$ bundle exec jekyll new .

# jalankan situs anda di komputer anda
$ bundle exec jekyll serve
{% endhighlight %}

Jika anda sudah masuk ke tahap ini, anda sudah menambahkan Jekyll ke dalam Github Pages anda dan biasakan trio maut jika ada perubahan.

{% highlight bash %}
$ git add .

$ git commit -m “tulis perubahan yg anda lakukan disini”

$ git push -u origin master
{% endhighlight %}

Perubahan yang sudah disimpan akan perlu beberapa waktu untuk diterapkan, untuk itu bersabar. Cek website pribadi anda dengan mengunjungi https://&lt;username&gt;.github.io dan lihat penampilan dari website anda, lebih menarik bukan?

Saya kira artikel ini berakhir disini, mungkin akan di-update jika dirasa kurang. Terima kasih sudah mampir, akhir kata, Salam (Akhmal R)
