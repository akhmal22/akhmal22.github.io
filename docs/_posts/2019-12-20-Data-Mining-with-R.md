# Fruit and Vegetables Availability

https://www.ers.usda.gov/data-products/food-availability-per-capita-data-system/food-availability-per-capita-data-system/#Food%20Availability

All data in Pounds

## Activate R


```python
# activate R magic
%load_ext rpy2.ipython
```


```r
%%R
x <- 42
print(x)
```


    [1] 42



## import csv


```r
%%R
fruitveg = 'https://gist.githubusercontent.com/akhmal22/f398b2c192a50e8acec9c9dd31a96ee3/raw/5c8ab16d36332ddd2ec3ef06925f13b27d3300f4/fruitveg.csv'
datafv = read.csv(fruitveg)
```


```r
%%R
head(datafv,10)
```


       year freshf canf freezef driedf juicef otherf totalProcf totalf freshv  canv
    1  1970  100.6 26.2     3.9   10.0   96.7    0.7      137.4  238.0  154.4 100.7
    2  1971  100.8 26.5     4.0   10.0  100.5    0.6      141.6  242.4  148.1 107.8
    3  1972   94.4 24.2     4.0    7.2  101.7    0.7      137.7  232.0  151.4 104.6
    4  1973   96.7 24.5     4.1   10.2  100.0    0.6      139.3  236.0  148.1  98.3
    5  1974   96.1 24.0     3.3    9.7  101.8    1.0      139.8  235.8  146.2  99.1
    6  1975  101.3 23.5     3.0   10.3  113.9    0.4      151.2  252.5  149.1  97.9
    7  1976  101.9 23.4     3.4   13.5  115.5    0.3      156.2  258.1  148.4 103.6
    8  1977   99.6 24.4     3.3    9.9  131.2    0.6      169.4  268.9  148.8 101.7
    9  1978  103.6 24.1     3.7    8.6  119.4    0.8      156.6  260.3  143.9  96.7
    10 1979   99.9 25.0     3.1   10.1  112.5    0.6      151.3  251.2  149.0 100.6
       freezev driedv chips legume totalProcv totalv totalfv
    1     43.7   13.2  17.4    7.0      181.9  336.3   574.3
    2     45.3   13.8  17.2    7.4      191.5  339.5   581.9
    3     45.3   13.3  16.7    6.6      186.4  337.8   569.8
    4     50.6   14.2  16.3    8.0      187.4  335.5   571.5
    5     51.0   16.1  15.7    6.2      188.1  334.3   570.1
    6     52.6   16.7  15.5    7.2      189.8  338.9   591.4
    7     57.5   17.1  15.8    6.8      200.7  349.1   607.2
    8     59.0   12.7  16.2    7.0      196.7  345.5   614.5
    9     58.9   13.4  16.5    5.7      191.2  335.1   595.4
    10    55.4   13.1  16.7    6.7      192.6  341.6   592.8



## remove null


```r
%%R
datafv <- na.omit(datafv) # Remove NA
```


```r
%%R
head(datafv)
```


      year freshf canf freezef driedf juicef otherf totalProcf totalf freshv  canv
    1 1970  100.6 26.2     3.9   10.0   96.7    0.7      137.4  238.0  154.4 100.7
    2 1971  100.8 26.5     4.0   10.0  100.5    0.6      141.6  242.4  148.1 107.8
    3 1972   94.4 24.2     4.0    7.2  101.7    0.7      137.7  232.0  151.4 104.6
    4 1973   96.7 24.5     4.1   10.2  100.0    0.6      139.3  236.0  148.1  98.3
    5 1974   96.1 24.0     3.3    9.7  101.8    1.0      139.8  235.8  146.2  99.1
    6 1975  101.3 23.5     3.0   10.3  113.9    0.4      151.2  252.5  149.1  97.9
      freezev driedv chips legume totalProcv totalv totalfv
    1    43.7   13.2  17.4    7.0      181.9  336.3   574.3
    2    45.3   13.8  17.2    7.4      191.5  339.5   581.9
    3    45.3   13.3  16.7    6.6      186.4  337.8   569.8
    4    50.6   14.2  16.3    8.0      187.4  335.5   571.5
    5    51.0   16.1  15.7    6.2      188.1  334.3   570.1
    6    52.6   16.7  15.5    7.2      189.8  338.9   591.4



## year column is not used, drop it


```r
%%R
datafv <- subset(datafv, select = -c(year))
```


```r
%%R
head(datafv)
```


      freshf canf freezef driedf juicef otherf totalProcf totalf freshv  canv
    1  100.6 26.2     3.9   10.0   96.7    0.7      137.4  238.0  154.4 100.7
    2  100.8 26.5     4.0   10.0  100.5    0.6      141.6  242.4  148.1 107.8
    3   94.4 24.2     4.0    7.2  101.7    0.7      137.7  232.0  151.4 104.6
    4   96.7 24.5     4.1   10.2  100.0    0.6      139.3  236.0  148.1  98.3
    5   96.1 24.0     3.3    9.7  101.8    1.0      139.8  235.8  146.2  99.1
    6  101.3 23.5     3.0   10.3  113.9    0.4      151.2  252.5  149.1  97.9
      freezev driedv chips legume totalProcv totalv totalfv
    1    43.7   13.2  17.4    7.0      181.9  336.3   574.3
    2    45.3   13.8  17.2    7.4      191.5  339.5   581.9
    3    45.3   13.3  16.7    6.6      186.4  337.8   569.8
    4    50.6   14.2  16.3    8.0      187.4  335.5   571.5
    5    51.0   16.1  15.7    6.2      188.1  334.3   570.1
    6    52.6   16.7  15.5    7.2      189.8  338.9   591.4




```python
# this method similar to pandas.Dataframe.describe()
%%R
summary(datafv)
```


         freshf           canf          freezef          driedf     
     Min.   : 94.4   Min.   :13.30   Min.   :3.000   Min.   : 7.20  
     1st Qu.:107.7   1st Qu.:16.55   1st Qu.:3.850   1st Qu.: 9.90  
     Median :123.3   Median :19.95   Median :4.300   Median :10.30  
     Mean   :119.2   Mean   :19.49   Mean   :4.267   Mean   :10.79  
     3rd Qu.:128.3   3rd Qu.:22.27   3rd Qu.:4.800   3rd Qu.:12.12  
     Max.   :142.7   Max.   :26.50   Max.   :5.600   Max.   :15.00  
         juicef          otherf         totalProcf        totalf     
     Min.   : 80.9   Min.   :0.2000   Min.   :109.7   Min.   :232.0  
     1st Qu.:100.5   1st Qu.:0.3000   1st Qu.:138.5   1st Qu.:254.5  
     Median :115.7   Median :0.5000   Median :151.4   Median :267.3  
     Mean   :111.1   Mean   :0.5292   Mean   :146.1   Mean   :265.4  
     3rd Qu.:120.4   3rd Qu.:0.7000   3rd Qu.:156.4   3rd Qu.:277.5  
     Max.   :136.4   Max.   :1.0000   Max.   :170.5   Max.   :300.0  
         freshv           canv           freezev          driedv     
     Min.   :143.9   Min.   : 81.90   Min.   :43.70   Min.   :10.50  
     1st Qu.:151.8   1st Qu.: 96.50   1st Qu.:58.73   1st Qu.:12.80  
     Median :185.1   Median :100.50   Median :68.80   Median :13.90  
     Mean   :176.3   Mean   : 99.96   Mean   :67.05   Mean   :14.10  
     3rd Qu.:194.2   3rd Qu.:103.85   3rd Qu.:75.95   3rd Qu.:15.32  
     Max.   :204.4   Max.   :112.40   Max.   :83.40   Max.   :17.70  
         chips           legume         totalProcv        totalv     
     Min.   :13.70   Min.   : 5.700   Min.   :181.9   Min.   :334.3  
     1st Qu.:16.18   1st Qu.: 6.700   1st Qu.:192.8   1st Qu.:344.5  
     Median :16.70   Median : 7.200   Median :202.0   Median :388.9  
     Mean   :16.79   Mean   : 7.365   Mean   :205.3   Mean   :381.5  
     3rd Qu.:17.52   3rd Qu.: 8.025   3rd Qu.:218.4   3rd Qu.:413.9  
     Max.   :20.00   Max.   :11.200   Max.   :232.0   Max.   :425.1  
        totalfv     
     Min.   :569.8  
     1st Qu.:612.7  
     Median :647.0  
     Mean   :646.9  
     3rd Qu.:686.2  
     Max.   :721.3  


