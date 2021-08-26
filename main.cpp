#include "queue.hpp"
#include "node.hpp"

#include <cstdio>
#include <cstdlib>
#include <ctime>

void FIFO(queue &);
void Round_Robin(queue &);
void priority(queue &);
void SJF(queue &);

int main()
{

    int opc;
    int num_procesos, tiempo, prioridad;
    system("color 0E");

    do
    {
        system("cls");
        printf("PLANIFICACION DE PROCESOS \n");
        printf("----------------------------------------\n");
        printf("1. FIFO\n");
        printf("2. SJF\n");
        printf("3. ROUND - ROBIN\n");
        printf("4. PRIORIDAD \n");
        printf("5. Salir\n\n");

        printf("Opcion: ");
        scanf("%i", &opc);

        switch (opc)
        {

        case 1:
            {

            printf("\n FIFO \n\n");
            printf("Introduce el numero de procesos: \n");
            scanf("%i", &num_procesos);
            queue p1(num_procesos);

            for (int i = 0; i < num_procesos; i++)
            {
                printf("introduce el tiempo del proceso [%i]: ", i + 1);
                scanf("%i", &tiempo);
                p1.enqueue(tiempo, 'A' + i, NULL);
            }

            FIFO(p1);

            printf("\n");
            system("pause");
            break;

            }
        case 2:
            {

            printf("\n SJF \n\n");
            printf("Introduce el numero de procesos: \n");
            scanf("%i", &num_procesos);
            queue p2(num_procesos);

            for (int i = 0; i < num_procesos; i++)
            {
                printf("introduce el tiempo del proceso [%i]: ", i + 1);
                scanf("%i", &tiempo);
                p2.enqueue(tiempo, 'A' + i, NULL);
            }

            SJF(p2);

            printf("\n");
            system("pause");
            break;

            }

        case 3:
            {

            printf("\n ROUND ROBIN \n\n");
            printf("introduce el numro de procesos: \n");
            scanf("%i", &num_procesos);
            queue p3(num_procesos);

            for (int i = 0; i < num_procesos; i++)
            {
                printf("introduce el tiempo del proceso [%i]: ", i + 1);
                scanf("%i", &tiempo);
                p3.enqueue(tiempo, 'A' + i, NULL);
            }

            Round_Robin(p3);

            printf("\n");
            system("pause");
            break;

            }

        case 4:
            {

            printf("\n PRIORIDAD \n\n");
            printf("introduce el numro de procesos: \n");
            scanf("%i", &num_procesos);
            queue p4(num_procesos);

            for (int i = 0; i < num_procesos; i++)
            {
                printf("introduce el tiempo del proceso [%i]: ", i + 1);
                scanf("%i", &tiempo);
                printf("introduce la prioridad del proceso [%i]: ", i + 1);
                scanf("%i", &prioridad);
                p4.enqueue(tiempo, 'A' + i, prioridad);
            }

            priority(p4);

            printf("\n");
            system("pause");
            break;

            }
        }
    }while (opc != 5);

    return 0;
}

void FIFO(queue &process)
{
    node *p_front = NULL;
    int t_return = 0;

    while (!process.empty())
    {

        p_front = process.front();
        t_return += p_front->data();

        printf("\nTiempo de retorno del proceso %c: %i", p_front->name(), t_return);

        process.dequeue();
    }
}

void Round_Robin(queue &process)
{

    node *p_front = NULL;
    node *p_aux = NULL;

    int size = process.size();
    int t_return = 0;
    int quantum = 0;

    do
    {

        quantum += process.front()->data();

        process.enqueue(process.front()->data(), process.front()->name(), NULL);

        process.dequeue();

    } while (process.front()->name() != 'A');

    quantum /= size;

    printf("****%i****", quantum);

    while (!process.empty())
    {

        if ((process.front()->data()) > quantum)
        {

            p_front = process.front();

            p_front->set_data(process.front()->data() - quantum);
            t_return += quantum;
            process.enqueue(p_front->data(), p_front->name(), NULL);
            process.dequeue();

            p_front = NULL;
        }

        if ((process.front()->data()) <= quantum)
        {

            t_return += process.front()->data();
            printf("\nTiempo de retorno del proceso %c: %i", process.front()->name(), t_return);
            process.dequeue();
        }
    }
}

void priority(queue &process)
{

    const int len = process.size();

    node **nodesArray = new node *[len];

    for (int k = 0; k < len; k++)
    {
        nodesArray[k] = process.dequeue_save();
        printf("%c ", nodesArray[k]->name());
        printf("%i ", nodesArray[k]->data());
        printf("%i ", nodesArray[k]->priority());

        printf("\n");
    }

    printf("\n\n");

    for (int k = 0; k < len; k++)
    {
        printf("%i ", nodesArray[k]->data());
    }

    int i;
    int j = 0;

    while (j <= len - 2)
    {

        i = 0;

        while (i <= (len - 2) - j)
        {

            if (nodesArray[i]->priority() < nodesArray[i + 1]->priority())
            {

                node *aux;
                aux = nodesArray[i];
                nodesArray[i] = nodesArray[i + 1];
                nodesArray[i + 1] = aux;
            }
            i++;
        }
        j++;
    }

    printf("\n\n");

    for (int k = 0; k < len; k++)
    {
        printf("%i ", nodesArray[k]->data());
    }

    printf("\n\n");

    for (int k = 0; k < len; k++)
    {
        process.enqueue(nodesArray[k]->data(), nodesArray[k]->name(), nodesArray[k]->priority());
    }

    for (int k = 0; k < len; k++)
    {
        printf("%d ", process.dequeue());
    }

    delete[] nodesArray;
}

void SJF(queue &process)
{
    node *p_front = NULL;
    int t_return = 0;
    int t_prom = 0;
    int t_promfinal = 0;
    const int len = process.size();

    node **nodesArray = new node *[len];

    for (int k = 0; k < len; k++)
    {
        nodesArray[k] = process.dequeue_save();
    }

    printf("\n\n");

    int i;
    int j = 0;

    while (j <= len - 2)
    {

        i = 0;

        while (i <= (len - 2) - j)
        {

            if (nodesArray[i]->data() > nodesArray[i + 1]->data())
            {

                node *aux;
                aux = nodesArray[i];
                nodesArray[i] = nodesArray[i + 1];
                nodesArray[i + 1] = aux;
            }
            i++;
        }
        j++;
    }

    /*for(int k = 0; k < len; k++){
        printf("\nproceso %c, tiempo %i \n", nodesArray[k]->name() ,nodesArray[k] -> data());
    }*/

    for (int k = 0; k < len; k++)
    {
        process.enqueue(nodesArray[k]->data(), nodesArray[k]->name(), nodesArray[k]->priority());
    }

    while (!process.empty())
    {

        p_front = process.front();
        t_return += p_front->data();
        t_prom += t_return;

        printf("\nTiempo de retorno del proceso %c: %i", p_front->name(), t_return);

        process.dequeue();
    }

    t_promfinal = t_prom / len;

    printf("\nTiempo de retorno promedio:  %i", t_promfinal);

    delete[] nodesArray;
}
