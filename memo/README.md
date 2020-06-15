# Modulo de memoria(memo)
Este modulo muestra datos de la memoria y el porcentaje de memoria utilizado. 

## .h importados 

```r
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>
#include <linux/hugetlb.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
```

## Estructuras importantes. 
sysinfo: estructura la cual contiene datos importantes de la memoria.

Una vez obtenido esto solo falta realizar algunos calclos y mostrar los datos. 

## Datos importantes de la estructura sysinfo
```r
totalram: indica la cantidad total de ram
freeram:  indica la cantidad libre de ram
```
