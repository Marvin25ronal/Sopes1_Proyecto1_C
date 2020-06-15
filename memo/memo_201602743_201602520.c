#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>
#include <linux/hugetlb.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>


static int modArchivo(struct seq_file *archivo, void *v)
{
    struct sysinfo inf;
    si_meminfo(&inf);
    long total_memoria = (inf.totalram * 4);
    long memoria_libre = (inf.freeram * 4);

    long memoria_utilizada = total_memoria - memoria_libre; 

    seq_printf(archivo," __________________________________________\n");
    seq_printf(archivo,"/                                          \\\n");
    seq_printf(archivo,"|  Lab. Sistemas operativos 1              |\n");
    seq_printf(archivo,"|  Vacas Junio 2020                        |\n");
    seq_printf(archivo,"|  Fernando Pensamiento Calderon           |\n");
    seq_printf(archivo,"|  201602743                               |\n");
    seq_printf(archivo,"|  Marvin Ronaldo Martinez Marroquin       |\n");
    seq_printf(archivo,"|  20162520                                |\n");
    seq_printf(archivo,"|  Proyecto 1 Modulo de Ram                |\n");
    seq_printf(archivo,"\\                                          /\n");
    seq_printf(archivo," ------------------------------------------\n");
    seq_printf(archivo,"\\                             .       .\n");
    seq_printf(archivo," \\                           / `.   .' \" \n");
    seq_printf(archivo,"  \\                  .---.  <    > <    >  .---.\n");
    seq_printf(archivo,"   \\                 |    \\  \\ - ~ ~ - /  /    |\n");
    seq_printf(archivo,"         _____          ..-~             ~-..-~\n");
    seq_printf(archivo,"        |     |   \\~~~\\.'                    `./~~~/\n");
    seq_printf(archivo,"       ---------   \\__/                        \\__/\n");
    seq_printf(archivo,"      .'  O    \\     /               /       \\  \" \n");
    seq_printf(archivo,"     (_____,    `._.'               |         }  \\/~~~/\n");
    seq_printf(archivo,"      `----.          /       }     |        /    \\__/\n");
    seq_printf(archivo,"            `-.      |       /      |       /      `. ,~~|\n");
    seq_printf(archivo,"                ~-.__|      /_ - ~ ^|      /- _      `..-'   \n");
    seq_printf(archivo,"                     |     /        |     /     ~-.     `-. _  _  _\n");
    seq_printf(archivo,"                     |_____|        |_____|         ~ - . _ _ _ _ _>\n");
    seq_printf(archivo,"                                                                      \n");

    seq_printf(archivo, "  Sistema Operativo: Ubuntu 18.04\n");
    seq_printf(archivo, "  Memoria Total     : \t %8lu KB - %8lu MB\n", total_memoria, total_memoria / 1024);
    seq_printf(archivo, "  Memoria Libre     : \t %8lu KB - %8lu MB \n", memoria_libre, memoria_libre / 1024);
    seq_printf(archivo, "  Memoria Utilizada : \t %8lu KB - %8lu MB \n", memoria_utilizada, memoria_utilizada / 1024);
    
    seq_printf(archivo, "  Memoria en uso: \t %i %%\n", (memoria_utilizada * 100) / total_memoria);
    return 0;
}

static int abriendo(struct inode *inode, struct file *file)
{
    return single_open(file, modArchivo, NULL);
}

static struct file_operations operaciones =
{
        .open = abriendo,
        .read = seq_read
};

static int iniciando(void)
{
    proc_create("memo_201602743_201602520", 0, NULL, &operaciones);

    printk(KERN_INFO "Carnet: 2016-02743_2016-02520\n");

    return 0;
}

static void terminando(void)
{
    remove_proc_entry("memo_201602743_201602520", NULL);

    printk(KERN_INFO "Curso: Sistemas Operativos 1\n");
}

MODULE_LICENSE("GPL");
module_init(iniciando);
module_exit(terminando);
