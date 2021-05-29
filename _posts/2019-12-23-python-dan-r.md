---
layout: post
title:  "PYTHON DAN R BERSAMA"
date:   2019-12-23 09:36:59 +0700
author: "Akhmal R"
categories: indonesian article
---
# PENGGUNAAN BAHASA R DAN PYTHON SECARA BERSAMAAN

## Prakata

Bahasa R dan Python seringkali digunakan dalam proses yang berkaitan dengan _data science_ dan sudah banyak pula yang membandingkan R dan Python dari segi kegunaan hingga _job opportunity_. Pertanyaan yang timbul dari perbandingan antara dua bahasa yang masing-masing memiliki karakter yang berbeda adalah &quot;Bisakah keduanya dipakai bersamaan? Bagaimana jika dipakai bersamaan? Apakah lebih baik?&quot; dan pertanyaan lain yang menjurus ke &quot;R vs Python against the world&quot;.

Topik ini menarik untuk dibahas karena selama ini dan yang telah diketahui sebelumnya, R dan Python menjadi 2 hal yang harus dipilih untuk pekerjaan menyangkut data science dkk. dan hal ini tidak sepenuhnya salah, namun pada artikel ini, pilihan bertambah satu karena R dan Python bisa dipakai bersamaan.

Artikel ini bertujuan untuk membahas tujuan dari pemakaian masing-masing R dan Python dalam satu sistem pengolahan data dan bagaimana hal tersebut dapat dilakukan.

## Sekilas tentang Python dan R

Python dikembangkan oleh Guido van Rossum dan rilis pertama kali tahun 1991 sebagai bahasa _scripting,_ high-level dan bersifat **umum**. Pembuat dari Python menekankan aspek _readability_ pada desain bahasa Python dan memopulerkan _whitespace_ sebagai pengganti dari _bracket_ ({}).

Python pada dasarnya adalah bahasa pemrograman umum, Python dibuat tidak spesifik untuk statistika atau pengolahan data sebagai contoh Python dapat dimanfaatkan untuk pengembangan _game_, pengolahan data atau machine learning (semakin populer karena ini), pengembangan aplikasi web sampai dengan pengembangan aplikasi berbasis _mobile_ (Android).

R adalah bahasa _scripting_ sama seperti Python dan R juga menyediakan _environment_ sendiri untuk pengembangan program dengan R. R yang diciptakan oleh Ross Ihaka dan Robert Gentleman dikhususkan untuk keperluan statistika atau masalah yang berhubungan dengan pengolahan data, hal itu menjadi salah satu hal yang membedakan R dengan bahasa lain khususnya Python.

R banyak digunakan pada masalah yang berkaitan dengan statistika dan data, seperti data mining, data analysis, data visualization dsb. R memiliki komunitas pemakai dan pengembang yang lumayan besar dan bisa memuat banyak paket dan library, sama seperti Python.

Python menjadi pilihan untuk data science karena banyaknya library scientific yang dapat diakses, bersifat umum dan _readable_ sehingga menawarkan kemudahan untuk tahap produksi (misal, deep learning). R sudah melabeli diri sebagai bahasa yang bersifat khusus dalam hal penggunaan, yaitu statistika yang menyebabkan R pilihan yang baik untuk data science dan menawarkan hasil analisis yang baik pada fokus penggunaan (statistika).

## Kelebihan Python dan R

| **R** | **Python** |
| --- | --- |
| Lebih baik untuk analisis data | Kegunaan lebih beragam |
| Sangat statistikis | Produksi |
| visualisasi data yang lebih rapi | _Code readability_ |

Tabel 1: Kelebihan R dan Python

R berfokus kepada komputasi yang membantu tahapan penyelesaian masalah dalam statistika, berdasarkan tujuan itu, R menjadi bahasa yang sangat baik dipakai untuk menganalisis data melalui pendekatan statistika seperti mencari rataan, median, modus atau interkuartil. R dikembangkan untuk para statistikawan, jadi karakter atau sintaks bahasa R sangat statistikis, mulai dari penggunaan fungsi dan library yang dapat dipahami oleh statistikawan, bahkan yang tidak pernah belajar _coding_ sebelumnya. Paket dan library yang dimiliki oleh R lebih lengkap daripada library milik Python dalam hal analisis data dan visualisasi data, dalam hal visualisasi data, R unggul dibanding Python karena lebih lengkapnya library visualisasi data di R.

Python lebih fleksibel dibandingkan R karena Python bahasa _general-purpose_ yang bisa dipakai bahkan untuk bidang di luar pengolahan data. Python dengan library yang ada, dapat mengolah data sekaligus menghasilkan produk hasil pengolahan data tersebut (misal, model ML), juga kode Python mudah dibaca dan dipelajari.

Kelebihan yang ada di atas menurut saya dapat bersinergi dengan baik untuk membuat suatu sistem yang menerapkan analisis data, namun tetap memperhatikan tujuan awal pengembangan sistem

## Caranya?

Ada beberapa cara yang mungkin dilakukan untuk menggunakan R dan Python secara bersamaan tergantung tujuan yang sedang ingin diraih, ada 2 jenis pemakaian, yaitu Python yang diakses di R dan sebaliknya.

Paket-paket yang dapat mengakses Python di R adalah sebagai berikut:

- rJython
- rPython
- SnakeCharmR
- PythonInR
- reticulate

Paket-paket yang dapat mengakses R di Python adalah sebagai berikut:

- PypeR
- pyRserve
- rpy2

Cara-cara di atas tidak akan saya bahas satu persatu, namun metode pemakaian rpy2 akan saya bahas di bagian bonus.

## Kesimpulan

Kesimpulan yang dapat diambil dari pembahasan di atas:

- Python dan R dapat bersinergi dengan masing-masing kelebihan mereka
- Sinergi antara Python dan R dapat terasa dengan adanya paket dan library di atas

## Bonus

Pada bagian bonus, saya akan menjelaskan langkah-langkah pemakaian rpy2 untuk Linux dengan Python 3.7 yang sudah terpasang.

### Pastikan R sudah terpasang

Pasang R agar tahu apakah R sudah terpasang atau belum dengan command Linux Fedora:

{% highlight bash %}
# Fedora
$ sudo dnf install R

# Ubuntu
$ sudo apt-get install R

# sesuaikan dengan package manager yang anda pakai

{% endhighlight %}

### Pasang rpy2 dengan pip

{% highlight bash %}
$ python -m pip install rpy2
# atau
$ pip install rpy2
{% endhighlight %}

### Gunakan rpy2 untuk berbagai keperluan dengan Import

{% highlight python %}
import math, datetime
import rpy2.robjects.lib.ggplot2 as ggplot2
import rpy2.robjects as ro
from rpy2.robjects.packages import importr
base = importr('base')

mtcars = data(datasets).fetch('mtcars')['mtcars']
{% endhighlight %}

{% highlight python %}
rnorm = stats.rnorm
dataf_rnorm = robjects.DataFrame({'value': rnorm(300, mean=0) + rnorm(100, mean=3),
                                  'other_value': rnorm(300, mean=0) + rnorm(100, mean=3),
                                  'mean': IntVector([0, ]*300 + [3, ] * 100)})
{% endhighlight %}

{% highlight python %}
# plotting
gp = ggplot2.ggplot(mtcars)

pp = gp + \
     ggplot2.aes_string(x='wt', y='mpg') + \
     ggplot2.geom_point()

pp.plot()

# online at: https://rpy2.github.io/doc/latest/html/graphics.html#plot
{% endhighlight %}

### Gunakan rpy2 untuk berbagai keperluan dengan load_ext

{% highlight python %}
# activate R magic
%load_ext rpy2.ipython
{% endhighlight %}

lalu untuk tiap line (jupyter notebook) yang berbahasa R, ditambahkan `%%R`

{% highlight python %}
%%R
plot(cars)
{% endhighlight %}

Terima kasih sudah mampir, akhir kata Salam. (Akhmal R)
