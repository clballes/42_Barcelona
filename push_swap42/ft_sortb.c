void    findmax(t_push_list **stack, t_push_list **stack_b)
{
    t_push_list *temp;
    int    len;
    int i;  

    temp = *stack_b;
    len = 20;
    i = 0;
    while(temp)
    {
        while (temp->index > temp->next->index && i )
            temp = temp->next;
    }
}