# Sistemas operativos 1 Practica 1
## Parte 1, agregando modulos.

En esta practica se realizaron 2 modulos. 

### Modulo de memoria

En el modulo de memoria se crea un archivo llamado memo_201602743_201602520 el cual se encuentra en la carpeta /proc
cada vez que se abre el archivo este llama un metodo el cual gracias a la estructura si_meminfo obtiene datos de la memeoria. 

### Modulo de CPU 

En el modulo de memoria se crea un archivo llamado memo_201602743_201602520 el cual se encuentra en la carpeta /proc
cada vez que se are el archivo este llama un metodo el cual gracias a la estructura task_struct obtiene un proceso el cual se puede subir hasta llegar al primer proceso. 


## Explicacion del codigo
El codigo sera explicado mas a detalle en los archivos .md que estan en la carpeta de cada modulo. 

## Acciones para agregar, quitar modulos y obtener mensajes de modulos. 

#### Comando para compilar un modulo 
```r
make all 
```
Este comando se realiza despues de que se escribe el codigo necesario para el modulo. 

#### Comando para ingresar el modulo

```r
sudo insmod archivo.ko  
```

#### Comando para retirar el modulo 

```r
sudo rmmod archivo  
```

#### Comando para obtener mensajes
```r
dmesg 
```

#### Comandos para acceder a los archivos creados por los modulos
```r
cd /proc
cat arcchivo
```

#### Comando para listar los modulos activos.
```r
sudo lsmod 
```

#### Comando para limpiar el directorio
```r
make clean 
```
