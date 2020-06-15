# Modulo CPU
Este modulo lista los procesos que estan corriendo en nuestro sistema operativo linux. 

## .h importados 

```r
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/seq_file.h>
#include <linux/proc_fs.h>
#include <linux/mm.h>
```

## Estructuras importantes. 
task_struct: structura la cual contiene un proceso, con la variable current se obtiene el proceso actual y de una forma iterativa se puede llegar hasta el primer proceso de la siguiente forma. 

```r
 struct task_struct *root = current;
    while (root->pid != 1)
    {
        root = root->parent;
    }
```
Una vez obtenido esto solo falta hacer de una forma recursiva que se imprima el proceso y se muestren los procesos hijos. 

## Datos importantes de la estructura task_struct

pid: el id del proceso. 
comm: el nombre del proceso.
state: el estado del proceso(se obtiene de forma numerica pero se puede obtener que significa cada numero)
children: los procesos hijos que tiene el proceso.

