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

void printTabs(struct seq_file *m, int cont);
void readTreeProcess(struct seq_file *m, struct task_struct *s, int cont);

char get_State(struct task_struct *s)
{

    /* if (task_list->state == TASK_RUNNING) {			    
			    return 'Ejecutando';
			}else if (task_list->state == TASK_INTERRUPTIBLE) {
                return 'Interrumpible';			    
			}else if (task_list->state == TASK_UNINTERRUPTIBLE) {			    
                return 'Ininterrumpible';			    
			}else if (task_list->state == __TASK_STOPPED) {			    
                return 'Detenido';			    
			}else if (task_list->state == __TASK_TRACED) {			    
                return 'Rastreado';			    
			}else if (task_list->exit_state == EXIT_DEAD) {			    
                return 'Muriendo';			    
			}else if (task_list->exit_state == EXIT_ZOMBIE) {			    
                return 'Zombie';			    
			}else if (task_list->state == TASK_DEAD) {
                return 'Muerto';			    
			}else if (task_list->state == TASK_NOLOAD) {			    
                return 'Sin Cargar ';			    
			}else if (task_list->state == TASK_WAKEKILL) {			    
                return 'No interactivo';			    
			}else if (task_list->state == TASK_WAKING) {			    
                return 'Despierto ';			    
			}else{
                return 'Desconocido';				
			}*/

    if (s->state == TASK_RUNNING)
    {
        return 'R';
    }
    else if (s->state == TASK_STOPPED)
    {
        return 'S';
    }
    else if (s->state == TASK_INTERRUPTIBLE)
    {
        return 'I';
    }
    else if (s->state == TASK_UNINTERRUPTIBLE)
    {
        return 'U';
    }
    else if (s->state == EXIT_ZOMBIE)
    {
        return 'Z';
    }
    else
    {
        return 'O';
    }
}

static int hello_proc_show(struct seq_file *m, void *v)
{
    struct task_struct *root = current;

    seq_printf(m, " __________________________________________\n");
    seq_printf(m, "/                                          \\\n");
    seq_printf(m, "|  Lab. Sistemas operativos 1              |\n");
    seq_printf(m, "|  Vacas Junio 2020                        |\n");
    seq_printf(m, "|  Fernando Pensamiento Calderon           |\n");
    seq_printf(m, "|  201602743                               |\n");
    seq_printf(m, "|  Marvin Ronaldo Martinez Marroquin       |\n");
    seq_printf(m, "|  20162520                                |\n");
    seq_printf(m, "|  Proyecto 1 Modulo de Procesos           |\n");
    seq_printf(m, "\\                                          /\n");
    seq_printf(m, " ------------------------------------------\n");
    seq_printf(m, "   \\\n");
    seq_printf(m, "    \\\n");
    seq_printf(m, "        .--.\n");
    seq_printf(m, "       |o_o |\n");
    seq_printf(m, "       |:_/ |\n");
    seq_printf(m, "      //   \\ \\\n");
    seq_printf(m, "     (|     | )\n");
    seq_printf(m, "    /'\\_   _/`\\\n");
    seq_printf(m, "    \\___)=(___/\n");
    seq_printf(m, "\n");

    while (root->pid != 1)
    {
        root = root->parent;
    }
    seq_printf(m, "[\n");
    readTreeProcess(m, root, 1);
    seq_printf(m, "]\n");

    seq_printf(m, "\n");
    seq_printf(m, "\n");
    seq_printf(m, "\n");

    seq_printf(m, " __________________________________________\n");
    seq_printf(m, "/                                          \\\n");
    seq_printf(m, "|  TIPOS DE ESTADOS                        |\n");
    seq_printf(m, "|  R = TASK_RUNNING                        |\n");
    seq_printf(m, "|  S = TASK_STOPPED                        |\n");
    seq_printf(m, "|  I = TASK_INTERRUPTIBLE                  |\n");
    seq_printf(m, "|  U = TASK_UNINTERRUPTIBLE                |\n");
    seq_printf(m, "|  Z = EXIT_ZOMBIE                         |\n");
    seq_printf(m, "|  O = OTHE_CASE                           |\n");
    seq_printf(m, "\\                                          /\n");
    seq_printf(m, " ------------------------------------------\n");
    seq_printf(m, "    \\\n");
    seq_printf(m, "     \\\n");
    seq_printf(m, "                                   .::!!!!!!!:.\n");
    seq_printf(m, "  .!!!!!:.                        .:!!!!!!!!!!!!\n");
    seq_printf(m, "  ~~~~!!!!!!.                 .:!!!!!!!!!UWWW$$$ \n");
    seq_printf(m, "      :$$NWX!!:           .:!!!!!!XUWW$$$$$$$$$P \n");
    seq_printf(m, "      $$$$$##WX!:      .<!!!!UW$$$$\"  $$$$$$$$# \n");
    seq_printf(m, "      $$$$$  $$$UX   :!!UW$$$$$$$$$   4$$$$$* \n");
    seq_printf(m, "      ^$$$B  $$$$\\     $$$$$$$$$$$$   d$$R\" \n");
    seq_printf(m, "        \"*$bd$$$$      '*$$$$$$$$$$$o+#\" \n");
    seq_printf(m, "             \"\"\"\"          \"\"\"\"\"\"\" \n");

    return 0;
}

void printTabs(struct seq_file *m, int cont)
{
    while (cont != 0)
    {
        seq_printf(m, "\t");
        cont = cont - 1;
    }
}

void readTreeProcess(struct seq_file *m, struct task_struct *s, int cont)
{
    struct list_head *list;
    struct task_struct *task;
    int t = 0;
    int nhijos = 0;

    printTabs(m, cont);
    seq_printf(m, "{\n");

    //PID
    printTabs(m, cont);
    seq_printf(m, "\"pid\":");
    seq_printf(m, "%d", s->pid);
    seq_printf(m, ",\n");
    //Nombre
    printTabs(m, cont);
    seq_printf(m, "\"name\":");
    seq_printf(m, "\"%s\"", s->comm);
    seq_printf(m, ",\n");
    //Estado
    printTabs(m, cont);
    seq_printf(m, "\"state\":");
    seq_printf(m, "\"%c\"", get_State(s));
    seq_printf(m, ",\n");
    //Children

    printTabs(m, cont);
    seq_printf(m, "\"children\":");
    seq_printf(m, "[");

    list_for_each(list, &s->children)
    {
        if (t++ != 0)
        {
            printTabs(m, cont);
            seq_printf(m, ",\n");
        }
        else
        {
            seq_printf(m, "\n");
        }
        task = list_entry(list, struct task_struct, sibling);
        readTreeProcess(m, task, cont + 1);
        nhijos = nhijos + 1;
    }
    if (nhijos != 0)
    {
        printTabs(m, cont);
    }
    seq_printf(m, "]\n");
    printTabs(m, cont);
    seq_printf(m, "}\n");
}

static int hello_proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, hello_proc_show, NULL);
}

static const struct file_operations hello_proc_fops = {
    .owner = THIS_MODULE,
    .open = hello_proc_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};

static int __init hello_proc_init(void)
{
    printk(KERN_INFO "Carnet: 2016-02743_2016-02520\n");
    proc_create("CPU_201602743_201602520", 0, NULL, &hello_proc_fops); // CREAR EL ARCHIVO DEL PROC
    return 0;
}

static void __exit hello_proc_exit(void)
{
    printk(KERN_INFO "Sistemas Operativos 1\n");
    remove_proc_entry("CPU_201602743_201602520", NULL);
}

MODULE_LICENSE("GPL");
module_init(hello_proc_init);
module_exit(hello_proc_exit);
